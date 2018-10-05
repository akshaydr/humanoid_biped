%% Initialize
clear;
run("robotParameters.m");
run("Robot_leg_2_DataFile.m");

%% Inputs
upper_leg_length = 13.5; %Upper Leg Length
lower_leg_length = 21.5; %Lower Leg Length
bend = 4;
step_length = 10; %Step Length
gait_period = 1.0; %Gait Period
samples = 20; %

simulation_time = linspace(0,10, samples*2);

%% Trajectory Parameters
h = 0; %Parabola Transformation
time = linspace(0,gait_period, samples*2);
time_first = linspace(0,gait_period, samples);
total_time = linspace(0,10, samples*2);
u1 = linspace(0, 10, samples*2);

%% Trajectory Generation
x = linspace(h, h+step_length, samples);
x_first = linspace(h, h, samples);
%y1 = trajectory_equation(step_length, samples);
y1 = trajectory_equation(0,0,  step_length/2,step_length/4,  step_length,0, h,samples);
y2 = trajectory_equation(0,0,  step_length/2,0,  step_length,0, h,samples);
y3 = trajectory_equation(0,0,  0.01,step_length/8,  0.02,step_length/4, h,samples);

%% Inverse Kinematics Generaion
%(x_trajectory, y_trajectory, link1, link2, x_link_position, y_link_position)
m = 0;
n = upper_leg_length + lower_leg_length - bend;
[right_hip_1, right_knee_1] = joint_angles(x, y1, upper_leg_length, lower_leg_length, m, n, samples);
[right_hip_2, right_knee_2] = joint_angles(x, y2, upper_leg_length, lower_leg_length, m, n, samples);
[right_hip_3, right_knee_3] = joint_angles(x_first, y3, upper_leg_length, lower_leg_length, m, n, samples);

[left_hip_1, left_knee_1] = joint_angles(x, y1, upper_leg_length, lower_leg_length, m, n, samples);
[left_hip_2, left_knee_2] = joint_angles(x, y2, upper_leg_length, lower_leg_length, m, n, samples);
[left_hip_3, left_knee_3] = joint_angles(x, y2, upper_leg_length, lower_leg_length, m, n, samples);

%% CoM shift angle calculation
xg = 10.72;
yg = 9.2;
t4 = atand(xg/(34.5 + yg));

%xg = 7.72;
%yg = 9.2;
%t4 = atand(xg/(34.5 + yg));
%% Right Leg joints
right_hip_1 = right_hip_1 + smiData.RevoluteJoint(2).Rz.Pos + 270;
right_hip_2 = right_hip_2 + smiData.RevoluteJoint(2).Rz.Pos + 270;
right_hip_3 = right_hip_3 + smiData.RevoluteJoint(2).Rz.Pos + 270;
right_hip_first = [right_hip_3 flip(right_hip_3)];
right_hip = [right_hip_2 flip(right_hip_1) ];
%right_hip = [flip(right_hip_1) right_hip_2];

right_knee_1 = smiData.RevoluteJoint(1).Rz.Pos - right_knee_1;
right_knee_2 = smiData.RevoluteJoint(1).Rz.Pos - right_knee_2;
right_knee_3 = smiData.RevoluteJoint(1).Rz.Pos - right_knee_3;
right_knee_first = [right_knee_3 flip(right_knee_3)];
right_knee = [right_knee_2 flip(right_knee_1) ];
%right_knee = [flip(right_knee_1) right_knee_2];

right_ankle = right_hip - right_knee + smiData.RevoluteJoint(3).Rz.Pos;

%right_hip = linspace(smiData.RevoluteJoint(2).Rz.Pos,smiData.RevoluteJoint(2).Rz.Pos, samples*2);
%right_knee = linspace(smiData.RevoluteJoint(1).Rz.Pos,smiData.RevoluteJoint(1).Rz.Pos, samples*2);
%right_ankle = linspace(smiData.RevoluteJoint(3).Rz.Pos,smiData.RevoluteJoint(3).Rz.Pos, samples*2);

right_knee_twist = linspace(smiData.RevoluteJoint(8).Rz.Pos,smiData.RevoluteJoint(8).Rz.Pos, samples*2);
right_abduction = linspace(smiData.RevoluteJoint(5).Rz.Pos,smiData.RevoluteJoint(5).Rz.Pos, samples*2);
right_t6 = linspace(smiData.RevoluteJoint(10).Rz.Pos,smiData.RevoluteJoint(10).Rz.Pos, samples*2);

right_theta_1 = deg2rad(right_hip);
right_theta_2 = deg2rad(right_knee);
right_theta_3 = deg2rad(right_ankle);
right_theta_4 = deg2rad(right_knee_twist);
right_theta_5 = deg2rad(right_abduction);
right_theta_6 = deg2rad(right_t6);

%% Left Leg joints
% hip = (left_hip_1) + 270;
% hip = (4000/360)* hip;
% hip = int32(hip + 2036)
hip_1 = left_hip_1 + 270;
hip_2 = left_hip_2 + 270;
hip_merge = [flip(hip_1) hip_2];
hip = (4000/360)* hip_merge;
hip = int32(hip + 2036);

left_hip_1 = left_hip_1 + smiData.RevoluteJoint(12).Rz.Pos + 270;
left_hip_2 = left_hip_2 + smiData.RevoluteJoint(12).Rz.Pos + 270;
left_hip_3 = left_hip_3 + smiData.RevoluteJoint(12).Rz.Pos + 270;
left_hip = [flip(left_hip_1) left_hip_2];
%left_hip = [left_hip_2 flip(left_hip_1)];
 
% kn = (left_knee_1) * -1;
% kn = (4000/360)* kn ;
% kn = int32(kn +2036)

knee_1 = left_knee_1 *-1;
knee_2 = left_knee_2 *-1;
knee_merge = [flip(knee_1) knee_2];
knee = (4000/360)* knee_merge;
knee = int32(knee + 2036);
left_knee_1 = smiData.RevoluteJoint(11).Rz.Pos - left_knee_1;
left_knee_2 = smiData.RevoluteJoint(11).Rz.Pos - left_knee_2;
left_knee_3 = smiData.RevoluteJoint(11).Rz.Pos - left_knee_3;
left_knee = [flip(left_knee_1) left_knee_2];
%left_knee = [left_knee_2 flip(left_knee_1)];

left_ankle = left_hip - left_knee + smiData.RevoluteJoint(7).Rz.Pos;
ankle = hip_merge - knee_merge;
ankle = (4000/360)*ankle;
ankle = int32(ankle + 2036);

disp("Hip_angle");
print_function(hip)

disp("Knee_angle");
print_function(knee)

disp("Ankle_angle");
print_function(ankle)

%left_hip = linspace(smiData.RevoluteJoint(12).Rz.Pos,smiData.RevoluteJoint(12).Rz.Pos, samples*2);
%left_knee = linspace(smiData.RevoluteJoint(11).Rz.Pos,smiData.RevoluteJoint(11).Rz.Pos, samples*2);
%left_ankle = linspace(smiData.RevoluteJoint(7).Rz.Pos,smiData.RevoluteJoint(7).Rz.Pos, samples*2);

left_knee_twist = linspace(smiData.RevoluteJoint(6).Rz.Pos,smiData.RevoluteJoint(6).Rz.Pos, samples*2);
left_abduction = linspace(smiData.RevoluteJoint(4).Rz.Pos,smiData.RevoluteJoint(4).Rz.Pos, samples*2);
left_t6 = linspace(smiData.RevoluteJoint(9).Rz.Pos,smiData.RevoluteJoint(9).Rz.Pos, samples*2);

left_theta_1 = deg2rad(left_hip);
left_theta_2 = deg2rad(left_knee);
left_theta_3 = deg2rad(left_ankle);
left_theta_4 = deg2rad(left_knee_twist);
left_theta_5 = deg2rad(left_abduction);
left_theta_6 = deg2rad(left_t6);

%% Graph Plot
hold on
% plot(x,hip,'LineWidth',3,'color',[1,0.5,0]);  %Orange
% plot(x,kn,'LineWidth',3,'color',[0,0.5,0]);  %Green
hold off

%% Joint angle generation Function
function [t1, t2] = joint_angles(x, y, l1, l2, m, n, samples)
t2_numerator = ((x-m).^2 + (y-n).^2 - l1^2 - l2^2);
t2_denominator = (2 * l1 * l2);
t2 = acosd(t2_numerator./t2_denominator);

t1_numerator = l2 * sind(t2);
t1_denominator = l1 + (l2 * cosd(t2));
t1 = atand((y-n)./(x-m)) - atand(t1_numerator./t1_denominator);
t1((2*m) + 1 : samples) = t1((2*m) + 1 : samples) + 180;

t2 = -t2;
t1 = -180 -t1;
end

%% Trajectory function
function y = trajectory_equation(xi,yi, xm,ym, xf,yf, h,samples)
syms a b c;
eqn1 = c == yi;
eqn2 = ym == ((xm^2)*a + (xm*b) + c);
eqn3 = yf == ((xf^2)*a + (xf*b) + c);
[A,B] = equationsToMatrix([eqn1, eqn2, eqn3], [c, b, a]);
co_effs = linsolve(A,B);
x = linspace(h, h+xf, samples);
y = double((co_effs(3)*((x-h).^2)) + (co_effs(2)*(x-h)) + co_effs(1));
end

function print_function(ankle)
fprintf('%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, \n', ankle(1), ankle(2), ankle(3), ankle(4), ankle(5), ankle(6), ankle(7), ankle(8), ankle(9), ankle(10), ankle(11), ankle(12), ankle(13), ankle(14), ankle(15), ankle(16), ankle(17), ankle(18), ankle(19), ankle(20), ankle(21), ankle(22), ankle(23), ankle(24), ankle(25), ankle(26), ankle(27), ankle(28), ankle(29), ankle(30), ankle(31), ankle(32), ankle(33), ankle(34), ankle(35), ankle(36), ankle(37), ankle(38), ankle(39), ankle(40));
end
