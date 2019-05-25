function pt=Robot_leg_2pt
pt = [];

  
pt(1).blockname = 'Robot/Left_Abduction_Motion/Constant';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'Robot_leg_2_P.Constant_Value';
pt(1).baseaddr   = '&Robot_leg_2_P.Constant_Value';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'Robot/Left_Abduction_Motion/Look-Up Table1';
pt(2).paramname = 'BreakpointsForDimension1';
pt(2).class     = 'vector';
pt(2).nrows     = 1;
pt(2).ncols     = 40;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data';
pt(2).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data[0]';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = 'Robot/Left_Ankle Motion/Constant';
pt(3).paramname = 'Value';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'Robot_leg_2_P.Constant_Value_d';
pt(3).baseaddr   = '&Robot_leg_2_P.Constant_Value_d';
pt(3).dtname     = 'real_T';



  
pt(4).blockname = 'Robot/Left_Ankle Motion/Look-Up Table1';
pt(4).paramname = 'BreakpointsForDimension1';
pt(4).class     = 'vector';
pt(4).nrows     = 1;
pt(4).ncols     = 40;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';
pt(4).isStruct  = false;
pt(4).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_k';
pt(4).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_k[0]';
pt(4).dtname     = 'real_T';



  
pt(5).blockname = 'Robot/Left_Ankle_Twist_Motion/Constant';
pt(5).paramname = 'Value';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';
pt(5).isStruct  = false;
pt(5).symbol     = 'Robot_leg_2_P.Constant_Value_j';
pt(5).baseaddr   = '&Robot_leg_2_P.Constant_Value_j';
pt(5).dtname     = 'real_T';



  
pt(6).blockname = 'Robot/Left_Ankle_Twist_Motion/Look-Up Table1';
pt(6).paramname = 'BreakpointsForDimension1';
pt(6).class     = 'vector';
pt(6).nrows     = 1;
pt(6).ncols     = 40;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';
pt(6).isStruct  = false;
pt(6).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_b';
pt(6).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_b[0]';
pt(6).dtname     = 'real_T';



  
pt(7).blockname = 'Robot/Left_Hip_Motion/Constant';
pt(7).paramname = 'Value';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';
pt(7).isStruct  = false;
pt(7).symbol     = 'Robot_leg_2_P.Constant_Value_a';
pt(7).baseaddr   = '&Robot_leg_2_P.Constant_Value_a';
pt(7).dtname     = 'real_T';



  
pt(8).blockname = 'Robot/Left_Hip_Motion/Look-Up Table1';
pt(8).paramname = 'BreakpointsForDimension1';
pt(8).class     = 'vector';
pt(8).nrows     = 1;
pt(8).ncols     = 40;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';
pt(8).isStruct  = false;
pt(8).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_l';
pt(8).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_l[0]';
pt(8).dtname     = 'real_T';



  
pt(9).blockname = 'Robot/Left_Knee_Motion/Constant';
pt(9).paramname = 'Value';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';
pt(9).isStruct  = false;
pt(9).symbol     = 'Robot_leg_2_P.Constant_Value_n';
pt(9).baseaddr   = '&Robot_leg_2_P.Constant_Value_n';
pt(9).dtname     = 'real_T';



  
pt(10).blockname = 'Robot/Left_Knee_Motion/Look-Up Table1';
pt(10).paramname = 'BreakpointsForDimension1';
pt(10).class     = 'vector';
pt(10).nrows     = 1;
pt(10).ncols     = 40;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';
pt(10).isStruct  = false;
pt(10).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_m';
pt(10).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_m[0]';
pt(10).dtname     = 'real_T';



  
pt(11).blockname = 'Robot/Left_Rotation_Motion/Constant';
pt(11).paramname = 'Value';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';
pt(11).isStruct  = false;
pt(11).symbol     = 'Robot_leg_2_P.Constant_Value_e';
pt(11).baseaddr   = '&Robot_leg_2_P.Constant_Value_e';
pt(11).dtname     = 'real_T';



  
pt(12).blockname = 'Robot/Left_Rotation_Motion/Look-Up Table1';
pt(12).paramname = 'BreakpointsForDimension1';
pt(12).class     = 'vector';
pt(12).nrows     = 1;
pt(12).ncols     = 40;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';
pt(12).isStruct  = false;
pt(12).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_c';
pt(12).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_c[0]';
pt(12).dtname     = 'real_T';



  
pt(13).blockname = 'Robot/Right_Abduction_Motion/Constant';
pt(13).paramname = 'Value';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';
pt(13).isStruct  = false;
pt(13).symbol     = 'Robot_leg_2_P.Constant_Value_k';
pt(13).baseaddr   = '&Robot_leg_2_P.Constant_Value_k';
pt(13).dtname     = 'real_T';



  
pt(14).blockname = 'Robot/Right_Abduction_Motion/Look-Up Table1';
pt(14).paramname = 'BreakpointsForDimension1';
pt(14).class     = 'vector';
pt(14).nrows     = 1;
pt(14).ncols     = 40;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';
pt(14).isStruct  = false;
pt(14).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_a';
pt(14).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_a[0]';
pt(14).dtname     = 'real_T';



  
pt(15).blockname = 'Robot/Right_Ankle_Motion/Constant';
pt(15).paramname = 'Value';
pt(15).class     = 'scalar';
pt(15).nrows     = 1;
pt(15).ncols     = 1;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';
pt(15).isStruct  = false;
pt(15).symbol     = 'Robot_leg_2_P.Constant_Value_h';
pt(15).baseaddr   = '&Robot_leg_2_P.Constant_Value_h';
pt(15).dtname     = 'real_T';



  
pt(16).blockname = 'Robot/Right_Ankle_Motion/Look-Up Table1';
pt(16).paramname = 'BreakpointsForDimension1';
pt(16).class     = 'vector';
pt(16).nrows     = 1;
pt(16).ncols     = 40;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';
pt(16).isStruct  = false;
pt(16).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_p';
pt(16).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_p[0]';
pt(16).dtname     = 'real_T';



  
pt(17).blockname = 'Robot/Right_Ankle_Twist_Motion/Constant';
pt(17).paramname = 'Value';
pt(17).class     = 'scalar';
pt(17).nrows     = 1;
pt(17).ncols     = 1;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';
pt(17).isStruct  = false;
pt(17).symbol     = 'Robot_leg_2_P.Constant_Value_g';
pt(17).baseaddr   = '&Robot_leg_2_P.Constant_Value_g';
pt(17).dtname     = 'real_T';



  
pt(18).blockname = 'Robot/Right_Ankle_Twist_Motion/Look-Up Table1';
pt(18).paramname = 'BreakpointsForDimension1';
pt(18).class     = 'vector';
pt(18).nrows     = 1;
pt(18).ncols     = 40;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';
pt(18).isStruct  = false;
pt(18).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_bj';
pt(18).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_bj[0]';
pt(18).dtname     = 'real_T';



  
pt(19).blockname = 'Robot/Right_Hip_Motion/Constant';
pt(19).paramname = 'Value';
pt(19).class     = 'scalar';
pt(19).nrows     = 1;
pt(19).ncols     = 1;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';
pt(19).isStruct  = false;
pt(19).symbol     = 'Robot_leg_2_P.Constant_Value_l';
pt(19).baseaddr   = '&Robot_leg_2_P.Constant_Value_l';
pt(19).dtname     = 'real_T';



  
pt(20).blockname = 'Robot/Right_Hip_Motion/Look-Up Table1';
pt(20).paramname = 'BreakpointsForDimension1';
pt(20).class     = 'vector';
pt(20).nrows     = 1;
pt(20).ncols     = 40;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';
pt(20).isStruct  = false;
pt(20).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_n';
pt(20).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_n[0]';
pt(20).dtname     = 'real_T';



  
pt(21).blockname = 'Robot/Right_Knee_Motion/Constant';
pt(21).paramname = 'Value';
pt(21).class     = 'scalar';
pt(21).nrows     = 1;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';
pt(21).isStruct  = false;
pt(21).symbol     = 'Robot_leg_2_P.Constant_Value_m';
pt(21).baseaddr   = '&Robot_leg_2_P.Constant_Value_m';
pt(21).dtname     = 'real_T';



  
pt(22).blockname = 'Robot/Right_Knee_Motion/Look-Up Table1';
pt(22).paramname = 'BreakpointsForDimension1';
pt(22).class     = 'vector';
pt(22).nrows     = 1;
pt(22).ncols     = 40;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';
pt(22).isStruct  = false;
pt(22).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_c2';
pt(22).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_c2[0]';
pt(22).dtname     = 'real_T';



  
pt(23).blockname = 'Robot/Right_Rotation_Motion/Constant';
pt(23).paramname = 'Value';
pt(23).class     = 'scalar';
pt(23).nrows     = 1;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';
pt(23).ndims     = '2';
pt(23).size      = '[]';
pt(23).isStruct  = false;
pt(23).symbol     = 'Robot_leg_2_P.Constant_Value_ln';
pt(23).baseaddr   = '&Robot_leg_2_P.Constant_Value_ln';
pt(23).dtname     = 'real_T';



  
pt(24).blockname = 'Robot/Right_Rotation_Motion/Look-Up Table1';
pt(24).paramname = 'BreakpointsForDimension1';
pt(24).class     = 'vector';
pt(24).nrows     = 1;
pt(24).ncols     = 40;
pt(24).subsource = 'SS_DOUBLE';
pt(24).ndims     = '2';
pt(24).size      = '[]';
pt(24).isStruct  = false;
pt(24).symbol     = 'Robot_leg_2_P.LookUpTable1_bp01Data_o';
pt(24).baseaddr   = '&Robot_leg_2_P.LookUpTable1_bp01Data_o[0]';
pt(24).dtname     = 'real_T';



  
pt(25).blockname = '';
pt(25).paramname = 'left_theta_1';
pt(25).class     = 'vector';
pt(25).nrows     = 1;
pt(25).ncols     = 40;
pt(25).subsource = 'SS_DOUBLE';
pt(25).ndims     = '2';
pt(25).size      = '[]';
pt(25).isStruct  = false;
pt(25).symbol     = 'Robot_leg_2_P.left_theta_1';
pt(25).baseaddr   = '&Robot_leg_2_P.left_theta_1[0]';
pt(25).dtname     = 'real_T';



  
pt(26).blockname = '';
pt(26).paramname = 'left_theta_2';
pt(26).class     = 'vector';
pt(26).nrows     = 1;
pt(26).ncols     = 40;
pt(26).subsource = 'SS_DOUBLE';
pt(26).ndims     = '2';
pt(26).size      = '[]';
pt(26).isStruct  = false;
pt(26).symbol     = 'Robot_leg_2_P.left_theta_2';
pt(26).baseaddr   = '&Robot_leg_2_P.left_theta_2[0]';
pt(26).dtname     = 'real_T';



  
pt(27).blockname = '';
pt(27).paramname = 'left_theta_3';
pt(27).class     = 'vector';
pt(27).nrows     = 1;
pt(27).ncols     = 40;
pt(27).subsource = 'SS_DOUBLE';
pt(27).ndims     = '2';
pt(27).size      = '[]';
pt(27).isStruct  = false;
pt(27).symbol     = 'Robot_leg_2_P.left_theta_3';
pt(27).baseaddr   = '&Robot_leg_2_P.left_theta_3[0]';
pt(27).dtname     = 'real_T';



  
pt(28).blockname = '';
pt(28).paramname = 'left_theta_4';
pt(28).class     = 'vector';
pt(28).nrows     = 1;
pt(28).ncols     = 40;
pt(28).subsource = 'SS_DOUBLE';
pt(28).ndims     = '2';
pt(28).size      = '[]';
pt(28).isStruct  = false;
pt(28).symbol     = 'Robot_leg_2_P.left_theta_4';
pt(28).baseaddr   = '&Robot_leg_2_P.left_theta_4[0]';
pt(28).dtname     = 'real_T';



  
pt(29).blockname = '';
pt(29).paramname = 'left_theta_5';
pt(29).class     = 'vector';
pt(29).nrows     = 1;
pt(29).ncols     = 40;
pt(29).subsource = 'SS_DOUBLE';
pt(29).ndims     = '2';
pt(29).size      = '[]';
pt(29).isStruct  = false;
pt(29).symbol     = 'Robot_leg_2_P.left_theta_5';
pt(29).baseaddr   = '&Robot_leg_2_P.left_theta_5[0]';
pt(29).dtname     = 'real_T';



  
pt(30).blockname = '';
pt(30).paramname = 'left_theta_6';
pt(30).class     = 'vector';
pt(30).nrows     = 1;
pt(30).ncols     = 40;
pt(30).subsource = 'SS_DOUBLE';
pt(30).ndims     = '2';
pt(30).size      = '[]';
pt(30).isStruct  = false;
pt(30).symbol     = 'Robot_leg_2_P.left_theta_6';
pt(30).baseaddr   = '&Robot_leg_2_P.left_theta_6[0]';
pt(30).dtname     = 'real_T';



  
pt(31).blockname = '';
pt(31).paramname = 'right_theta_1';
pt(31).class     = 'vector';
pt(31).nrows     = 1;
pt(31).ncols     = 40;
pt(31).subsource = 'SS_DOUBLE';
pt(31).ndims     = '2';
pt(31).size      = '[]';
pt(31).isStruct  = false;
pt(31).symbol     = 'Robot_leg_2_P.right_theta_1';
pt(31).baseaddr   = '&Robot_leg_2_P.right_theta_1[0]';
pt(31).dtname     = 'real_T';



  
pt(32).blockname = '';
pt(32).paramname = 'right_theta_2';
pt(32).class     = 'vector';
pt(32).nrows     = 1;
pt(32).ncols     = 40;
pt(32).subsource = 'SS_DOUBLE';
pt(32).ndims     = '2';
pt(32).size      = '[]';
pt(32).isStruct  = false;
pt(32).symbol     = 'Robot_leg_2_P.right_theta_2';
pt(32).baseaddr   = '&Robot_leg_2_P.right_theta_2[0]';
pt(32).dtname     = 'real_T';



  
pt(33).blockname = '';
pt(33).paramname = 'right_theta_3';
pt(33).class     = 'vector';
pt(33).nrows     = 1;
pt(33).ncols     = 40;
pt(33).subsource = 'SS_DOUBLE';
pt(33).ndims     = '2';
pt(33).size      = '[]';
pt(33).isStruct  = false;
pt(33).symbol     = 'Robot_leg_2_P.right_theta_3';
pt(33).baseaddr   = '&Robot_leg_2_P.right_theta_3[0]';
pt(33).dtname     = 'real_T';



  
pt(34).blockname = '';
pt(34).paramname = 'right_theta_4';
pt(34).class     = 'vector';
pt(34).nrows     = 1;
pt(34).ncols     = 40;
pt(34).subsource = 'SS_DOUBLE';
pt(34).ndims     = '2';
pt(34).size      = '[]';
pt(34).isStruct  = false;
pt(34).symbol     = 'Robot_leg_2_P.right_theta_4';
pt(34).baseaddr   = '&Robot_leg_2_P.right_theta_4[0]';
pt(34).dtname     = 'real_T';



  
pt(35).blockname = '';
pt(35).paramname = 'right_theta_5';
pt(35).class     = 'vector';
pt(35).nrows     = 1;
pt(35).ncols     = 40;
pt(35).subsource = 'SS_DOUBLE';
pt(35).ndims     = '2';
pt(35).size      = '[]';
pt(35).isStruct  = false;
pt(35).symbol     = 'Robot_leg_2_P.right_theta_5';
pt(35).baseaddr   = '&Robot_leg_2_P.right_theta_5[0]';
pt(35).dtname     = 'real_T';



  
pt(36).blockname = '';
pt(36).paramname = 'right_theta_6';
pt(36).class     = 'vector';
pt(36).nrows     = 1;
pt(36).ncols     = 40;
pt(36).subsource = 'SS_DOUBLE';
pt(36).ndims     = '2';
pt(36).size      = '[]';
pt(36).isStruct  = false;
pt(36).symbol     = 'Robot_leg_2_P.right_theta_6';
pt(36).baseaddr   = '&Robot_leg_2_P.right_theta_6[0]';
pt(36).dtname     = 'real_T';


function len = getlenPT
len = 36;

