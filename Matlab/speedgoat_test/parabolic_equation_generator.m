%% Inputs
upper_leg_length = 13.5;
lower_leg_length = 17.8;
gaitPeriod = 1.0;
step_length = 10;
%time = (0:1:10);

%% Trajectory parameters
x_initial = 0;
x_mid = step_length/2;
x_final = step_length;
y_initial = 0;
y_peak = step_length/4;
y_final = 0;
x_graph_offset = -(x_final + 1);  %-(x_final + 1)
y_graph_offset = 0;
time = linspace(0,gaitPeriod, (x_final+1)*2)'; 

%% Parabolic Trajectory Generaion
syms a b c;
eqn1 = c == y_initial;
eqn2 = y_peak == ((x_mid^2)*a + (x_mid*b) + c);
eqn3 = y_final == ((x_final^2)*a + (x_final*b) + c);
[A,B] = equationsToMatrix([eqn1, eqn2, eqn3], [c, b, a]);
co_effs = linsolve(A,B);
x = (x_initial + x_graph_offset:1: x_initial + x_graph_offset + step_length);
y = ((co_effs(3)*((x-x_graph_offset).^2)) + (co_effs(2)*(x-x_graph_offset)) + co_effs(1));
y = double(y);

%% Inverse Kinematics Joint angle Calculation
x_offset = 0;
y_offset = lower_leg_length + upper_leg_length - 2;

t2_numerator = ((x-x_offset).^2 + (y-y_offset).^2 - upper_leg_length^2 - lower_leg_length^2);
t2_denominator = (2 * upper_leg_length * lower_leg_length);
t2 = acosd(t2_numerator./t2_denominator);

t1_numerator = lower_leg_length * sind(t2);
t1_denominator = upper_leg_length + (lower_leg_length * cosd(t2));
t1 = atand((y-y_offset)./(x-x_offset)) - atand(t1_numerator./t1_denominator);

%% Right Leg Parameters
%t3 = 0 - (t1 - t1);
%t1 = t1 - 90;
t2 = -t2;
t1 = -180 -t1;
right_t1 = t1 + smiData.RevoluteJoint(2).Rz.Pos + 270;
right_t1 = [linspace(right_t1(x_final + 1),right_t1(x_final + 1),x_final + 1) right_t1];

right_t2 = smiData.RevoluteJoint(1).Rz.Pos - t2;
right_t2 = [linspace(right_t2(x_final + 1),right_t2(x_final + 1),x_final + 1) right_t2];

right_t3 = right_t1 - right_t2 - smiData.RevoluteJoint(3).Rz.Pos;
%right_t3 = [right_t3 linspace(smiData.RevoluteJoint(3).Rz.Pos,smiData.RevoluteJoint(3).Rz.Pos,x_final + 1)];

left_t1 = t1 + smiData.RevoluteJoint(12).Rz.Pos + 270;
left_t1 = [left_t1 linspace(left_t1(1),left_t1(1),x_final + 1)];

left_t2 = smiData.RevoluteJoint(11).Rz.Pos - t2;
left_t2 = [left_t2 linspace(left_t2(1),left_t2(1),x_final + 1)];

left_t3 = left_t1 - left_t2 - smiData.RevoluteJoint(7).Rz.Pos;
%left_t3 = [left_t3 linspace(smiData.RevoluteJoint(7).Rz.Pos,smiData.RevoluteJoint(7).Rz.Pos,x_final + 1)];

%t1 = linspace(smiData.RevoluteJoint(3).Rz.Pos,smiData.RevoluteJoint(3).Rz.Pos,x_final + 1)';
%t2 = linspace(smiData.RevoluteJoint(2).Rz.Pos,smiData.RevoluteJoint(2).Rz.Pos,x_final + 1)';
%t3 = linspace(smiData.RevoluteJoint(4).Rz.Pos,smiData.RevoluteJoint(4).Rz.Pos,x_final + 1)';
right_t4 = linspace(smiData.RevoluteJoint(8).Rz.Pos,smiData.RevoluteJoint(8).Rz.Pos, (x_final+1)*2)';
right_t5 = linspace(smiData.RevoluteJoint(5).Rz.Pos,smiData.RevoluteJoint(5).Rz.Pos, (x_final+1)*2)';
right_t6 = linspace(smiData.RevoluteJoint(10).Rz.Pos,smiData.RevoluteJoint(10).Rz.Pos, (x_final+1)*2)';

left_t4 = linspace(smiData.RevoluteJoint(6).Rz.Pos,smiData.RevoluteJoint(6).Rz.Pos, (x_final+1)*2)';
left_t5 = linspace(smiData.RevoluteJoint(4).Rz.Pos,smiData.RevoluteJoint(4).Rz.Pos, (x_final+1)*2)';
left_t6 = linspace(smiData.RevoluteJoint(9).Rz.Pos,smiData.RevoluteJoint(9).Rz.Pos, (x_final+1)*2)';

%% Angle Conversion
right_theta_1 = degtorad(double(right_t1));
right_theta_2 = degtorad(double(right_t2));
right_theta_3 = degtorad(double(right_t3));
right_theta_4 = degtorad(double(right_t4));
right_theta_5 = degtorad(double(right_t5));
right_theta_6 = degtorad(double(right_t6));

right_theta_1 = flip(right_theta_1);
right_theta_2 = flip(right_theta_2);
right_theta_3 = flip(right_theta_3);

left_theta_1 = degtorad(double(left_t1));
left_theta_2 = degtorad(double(left_t2));
left_theta_3 = degtorad(double(left_t3));
left_theta_4 = degtorad(double(left_t4));
left_theta_5 = degtorad(double(left_t5));
left_theta_6 = degtorad(double(left_t6));

left_theta_1 = flip(left_theta_1);
left_theta_2 = flip(left_theta_2);
left_theta_3 = flip(left_theta_3);

%t1_length = length(t1);
%for i = 1:t1_length
%    if (t1(i) <= -90)
%        t1(i) = -180 -t1(i);
%    end
%end
%t2 = -t2;
%t1 = -180 -t1;

%% Graph Plot
hold on 
plot(time,left_theta_2,'LineWidth',3,'color',[0,0.5,1]);   %Blue
plot(time,right_theta_1,'LineWidth',3,'color',[1,0.5,0]);  %Orange
plot(time,right_theta_2,'LineWidth',3,'color',[0,0.5,0]);  %Green
plot(time,left_theta_1,'LineWidth',3,'color',[1,0.5,1]);  %Pink
hold off

%theta_1 = theta_1 - 1.2673;
%theta_2 = theta_2 - 0.726;