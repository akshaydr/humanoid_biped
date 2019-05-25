function xcp = Robot_leg_2xcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'Robot_leg_2';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.2;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'Robot_leg_2_B.Clock';
    
xcp.signals(2).symbol =  'Robot_leg_2_B.Output';
    
xcp.signals(3).symbol =  'Robot_leg_2_B.LookUpTable1';
    
xcp.signals(4).symbol =  'Robot_leg_2_B.MathFunction';
    
xcp.signals(5).symbol =  'Robot_leg_2_B.Sum';
    
xcp.signals(6).symbol =  'Robot_leg_2_B.Clock_b';
    
xcp.signals(7).symbol =  'Robot_leg_2_B.Output_e';
    
xcp.signals(8).symbol =  'Robot_leg_2_B.LookUpTable1_e';
    
xcp.signals(9).symbol =  'Robot_leg_2_B.MathFunction_f';
    
xcp.signals(10).symbol =  'Robot_leg_2_B.Sum_c';
    
xcp.signals(11).symbol =  'Robot_leg_2_B.Clock_m';
    
xcp.signals(12).symbol =  'Robot_leg_2_B.Output_n';
    
xcp.signals(13).symbol =  'Robot_leg_2_B.LookUpTable1_es';
    
xcp.signals(14).symbol =  'Robot_leg_2_B.MathFunction_e';
    
xcp.signals(15).symbol =  'Robot_leg_2_B.Sum_cu';
    
xcp.signals(16).symbol =  'Robot_leg_2_B.Clock_c';
    
xcp.signals(17).symbol =  'Robot_leg_2_B.Output_g';
    
xcp.signals(18).symbol =  'Robot_leg_2_B.LookUpTable1_c';
    
xcp.signals(19).symbol =  'Robot_leg_2_B.MathFunction_a';
    
xcp.signals(20).symbol =  'Robot_leg_2_B.Sum_e';
    
xcp.signals(21).symbol =  'Robot_leg_2_B.Clock_n';
    
xcp.signals(22).symbol =  'Robot_leg_2_B.Output_a';
    
xcp.signals(23).symbol =  'Robot_leg_2_B.LookUpTable1_n';
    
xcp.signals(24).symbol =  'Robot_leg_2_B.MathFunction_g';
    
xcp.signals(25).symbol =  'Robot_leg_2_B.Sum_h';
    
xcp.signals(26).symbol =  'Robot_leg_2_B.Clock_a';
    
xcp.signals(27).symbol =  'Robot_leg_2_B.Output_l';
    
xcp.signals(28).symbol =  'Robot_leg_2_B.LookUpTable1_i';
    
xcp.signals(29).symbol =  'Robot_leg_2_B.MathFunction_c';
    
xcp.signals(30).symbol =  'Robot_leg_2_B.Sum_j';
    
xcp.signals(31).symbol =  'Robot_leg_2_B.Clock_k';
    
xcp.signals(32).symbol =  'Robot_leg_2_B.Output_ez';
    
xcp.signals(33).symbol =  'Robot_leg_2_B.LookUpTable1_cp';
    
xcp.signals(34).symbol =  'Robot_leg_2_B.MathFunction_m';
    
xcp.signals(35).symbol =  'Robot_leg_2_B.Sum_ev';
    
xcp.signals(36).symbol =  'Robot_leg_2_B.Clock_f';
    
xcp.signals(37).symbol =  'Robot_leg_2_B.Output_p';
    
xcp.signals(38).symbol =  'Robot_leg_2_B.LookUpTable1_j';
    
xcp.signals(39).symbol =  'Robot_leg_2_B.MathFunction_i';
    
xcp.signals(40).symbol =  'Robot_leg_2_B.Sum_m';
    
xcp.signals(41).symbol =  'Robot_leg_2_B.Clock_h';
    
xcp.signals(42).symbol =  'Robot_leg_2_B.Output_i';
    
xcp.signals(43).symbol =  'Robot_leg_2_B.LookUpTable1_p';
    
xcp.signals(44).symbol =  'Robot_leg_2_B.MathFunction_er';
    
xcp.signals(45).symbol =  'Robot_leg_2_B.Sum_m0';
    
xcp.signals(46).symbol =  'Robot_leg_2_B.Clock_bc';
    
xcp.signals(47).symbol =  'Robot_leg_2_B.Output_c';
    
xcp.signals(48).symbol =  'Robot_leg_2_B.LookUpTable1_d';
    
xcp.signals(49).symbol =  'Robot_leg_2_B.MathFunction_p';
    
xcp.signals(50).symbol =  'Robot_leg_2_B.Sum_f';
    
xcp.signals(51).symbol =  'Robot_leg_2_B.Clock_hk';
    
xcp.signals(52).symbol =  'Robot_leg_2_B.Output_ck';
    
xcp.signals(53).symbol =  'Robot_leg_2_B.LookUpTable1_a';
    
xcp.signals(54).symbol =  'Robot_leg_2_B.MathFunction_ph';
    
xcp.signals(55).symbol =  'Robot_leg_2_B.Sum_a';
    
xcp.signals(56).symbol =  'Robot_leg_2_B.Clock_hb';
    
xcp.signals(57).symbol =  'Robot_leg_2_B.Output_cq';
    
xcp.signals(58).symbol =  'Robot_leg_2_B.LookUpTable1_g';
    
xcp.signals(59).symbol =  'Robot_leg_2_B.MathFunction_fl';
    
xcp.signals(60).symbol =  'Robot_leg_2_B.Sum_p';
    
xcp.signals(61).symbol =  'Robot_leg_2_B.INPUT_10_1_1';
    
xcp.signals(62).symbol =  'Robot_leg_2_B.INPUT_11_1_1';
    
xcp.signals(63).symbol =  'Robot_leg_2_B.INPUT_12_1_1';
    
xcp.signals(64).symbol =  'Robot_leg_2_B.INPUT_1_1_1';
    
xcp.signals(65).symbol =  'Robot_leg_2_B.INPUT_2_1_1';
    
xcp.signals(66).symbol =  'Robot_leg_2_B.INPUT_3_1_1';
    
xcp.signals(67).symbol =  'Robot_leg_2_B.INPUT_4_1_1';
    
xcp.signals(68).symbol =  'Robot_leg_2_B.INPUT_5_1_1';
    
xcp.signals(69).symbol =  'Robot_leg_2_B.INPUT_6_1_1';
    
xcp.signals(70).symbol =  'Robot_leg_2_B.INPUT_7_1_1';
    
xcp.signals(71).symbol =  'Robot_leg_2_B.INPUT_8_1_1';
    
xcp.signals(72).symbol =  'Robot_leg_2_B.INPUT_9_1_1';
         
xcp.parameters(1).symbol = 'Robot_leg_2_P.Constant_Value';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&Robot_leg_2_P.Constant_Value';     
         
xcp.parameters(2).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data';
xcp.parameters(2).size   =  40;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data[0]';     
         
xcp.parameters(3).symbol = 'Robot_leg_2_P.Constant_Value_d';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&Robot_leg_2_P.Constant_Value_d';     
         
xcp.parameters(4).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_k';
xcp.parameters(4).size   =  40;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_k[0]';     
         
xcp.parameters(5).symbol = 'Robot_leg_2_P.Constant_Value_j';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&Robot_leg_2_P.Constant_Value_j';     
         
xcp.parameters(6).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_b';
xcp.parameters(6).size   =  40;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_b[0]';     
         
xcp.parameters(7).symbol = 'Robot_leg_2_P.Constant_Value_a';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&Robot_leg_2_P.Constant_Value_a';     
         
xcp.parameters(8).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_l';
xcp.parameters(8).size   =  40;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_l[0]';     
         
xcp.parameters(9).symbol = 'Robot_leg_2_P.Constant_Value_n';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&Robot_leg_2_P.Constant_Value_n';     
         
xcp.parameters(10).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_m';
xcp.parameters(10).size   =  40;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_m[0]';     
         
xcp.parameters(11).symbol = 'Robot_leg_2_P.Constant_Value_e';
xcp.parameters(11).size   =  1;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&Robot_leg_2_P.Constant_Value_e';     
         
xcp.parameters(12).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_c';
xcp.parameters(12).size   =  40;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_c[0]';     
         
xcp.parameters(13).symbol = 'Robot_leg_2_P.Constant_Value_k';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&Robot_leg_2_P.Constant_Value_k';     
         
xcp.parameters(14).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_a';
xcp.parameters(14).size   =  40;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_a[0]';     
         
xcp.parameters(15).symbol = 'Robot_leg_2_P.Constant_Value_h';
xcp.parameters(15).size   =  1;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&Robot_leg_2_P.Constant_Value_h';     
         
xcp.parameters(16).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_p';
xcp.parameters(16).size   =  40;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_p[0]';     
         
xcp.parameters(17).symbol = 'Robot_leg_2_P.Constant_Value_g';
xcp.parameters(17).size   =  1;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&Robot_leg_2_P.Constant_Value_g';     
         
xcp.parameters(18).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_bj';
xcp.parameters(18).size   =  40;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_bj[0]';     
         
xcp.parameters(19).symbol = 'Robot_leg_2_P.Constant_Value_l';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&Robot_leg_2_P.Constant_Value_l';     
         
xcp.parameters(20).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_n';
xcp.parameters(20).size   =  40;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_n[0]';     
         
xcp.parameters(21).symbol = 'Robot_leg_2_P.Constant_Value_m';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&Robot_leg_2_P.Constant_Value_m';     
         
xcp.parameters(22).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_c2';
xcp.parameters(22).size   =  40;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_c2[0]';     
         
xcp.parameters(23).symbol = 'Robot_leg_2_P.Constant_Value_ln';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'real_T'; 
xcp.parameters(24).baseaddr = '&Robot_leg_2_P.Constant_Value_ln';     
         
xcp.parameters(24).symbol = 'Robot_leg_2_P.LookUpTable1_bp01Data_o';
xcp.parameters(24).size   =  40;       
xcp.parameters(24).dtname = 'real_T'; 
xcp.parameters(25).baseaddr = '&Robot_leg_2_P.LookUpTable1_bp01Data_o[0]';     
         
xcp.parameters(25).symbol = 'Robot_leg_2_P.left_theta_1';
xcp.parameters(25).size   =  40;       
xcp.parameters(25).dtname = 'real_T'; 
xcp.parameters(26).baseaddr = '&Robot_leg_2_P.left_theta_1[0]';     
         
xcp.parameters(26).symbol = 'Robot_leg_2_P.left_theta_2';
xcp.parameters(26).size   =  40;       
xcp.parameters(26).dtname = 'real_T'; 
xcp.parameters(27).baseaddr = '&Robot_leg_2_P.left_theta_2[0]';     
         
xcp.parameters(27).symbol = 'Robot_leg_2_P.left_theta_3';
xcp.parameters(27).size   =  40;       
xcp.parameters(27).dtname = 'real_T'; 
xcp.parameters(28).baseaddr = '&Robot_leg_2_P.left_theta_3[0]';     
         
xcp.parameters(28).symbol = 'Robot_leg_2_P.left_theta_4';
xcp.parameters(28).size   =  40;       
xcp.parameters(28).dtname = 'real_T'; 
xcp.parameters(29).baseaddr = '&Robot_leg_2_P.left_theta_4[0]';     
         
xcp.parameters(29).symbol = 'Robot_leg_2_P.left_theta_5';
xcp.parameters(29).size   =  40;       
xcp.parameters(29).dtname = 'real_T'; 
xcp.parameters(30).baseaddr = '&Robot_leg_2_P.left_theta_5[0]';     
         
xcp.parameters(30).symbol = 'Robot_leg_2_P.left_theta_6';
xcp.parameters(30).size   =  40;       
xcp.parameters(30).dtname = 'real_T'; 
xcp.parameters(31).baseaddr = '&Robot_leg_2_P.left_theta_6[0]';     
         
xcp.parameters(31).symbol = 'Robot_leg_2_P.right_theta_1';
xcp.parameters(31).size   =  40;       
xcp.parameters(31).dtname = 'real_T'; 
xcp.parameters(32).baseaddr = '&Robot_leg_2_P.right_theta_1[0]';     
         
xcp.parameters(32).symbol = 'Robot_leg_2_P.right_theta_2';
xcp.parameters(32).size   =  40;       
xcp.parameters(32).dtname = 'real_T'; 
xcp.parameters(33).baseaddr = '&Robot_leg_2_P.right_theta_2[0]';     
         
xcp.parameters(33).symbol = 'Robot_leg_2_P.right_theta_3';
xcp.parameters(33).size   =  40;       
xcp.parameters(33).dtname = 'real_T'; 
xcp.parameters(34).baseaddr = '&Robot_leg_2_P.right_theta_3[0]';     
         
xcp.parameters(34).symbol = 'Robot_leg_2_P.right_theta_4';
xcp.parameters(34).size   =  40;       
xcp.parameters(34).dtname = 'real_T'; 
xcp.parameters(35).baseaddr = '&Robot_leg_2_P.right_theta_4[0]';     
         
xcp.parameters(35).symbol = 'Robot_leg_2_P.right_theta_5';
xcp.parameters(35).size   =  40;       
xcp.parameters(35).dtname = 'real_T'; 
xcp.parameters(36).baseaddr = '&Robot_leg_2_P.right_theta_5[0]';     
         
xcp.parameters(36).symbol = 'Robot_leg_2_P.right_theta_6';
xcp.parameters(36).size   =  40;       
xcp.parameters(36).dtname = 'real_T'; 
xcp.parameters(37).baseaddr = '&Robot_leg_2_P.right_theta_6[0]';     

function n = getNumParameters
n = 36;

function n = getNumSignals
n = 72;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

