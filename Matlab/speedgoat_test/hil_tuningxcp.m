function xcp = hil_tuningxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'hil_tuning';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.001;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'hil_tuning_B.Constant3';
    
xcp.signals(2).symbol =  'hil_tuning_B.ASCIIDecode_o1';
    
xcp.signals(3).symbol =  'hil_tuning_B.ASCIIDecode_o2';
    
xcp.signals(4).symbol =  'hil_tuning_B.ASCIIDecode_o3';
    
xcp.signals(5).symbol =  'hil_tuning_B.ASCIIDecode_o4';
    
xcp.signals(6).symbol =  'hil_tuning_B.ASCIIDecode_o5';
    
xcp.signals(7).symbol =  'hil_tuning_B.ASCIIDecode_o6';
    
xcp.signals(8).symbol =  'hil_tuning_B.ASCIIDecode_o7';
    
xcp.signals(9).symbol =  'hil_tuning_B.ASCIIDecode_o8';
    
xcp.signals(10).symbol =  'hil_tuning_B.ASCIIDecode_o9';
    
xcp.signals(11).symbol =  'hil_tuning_B.ASCIIDecode_o10';
    
xcp.signals(12).symbol =  'hil_tuning_B.ASCIIDecode_o11';
    
xcp.signals(13).symbol =  'hil_tuning_B.ASCIIDecode_o12';
    
xcp.signals(14).symbol =  'hil_tuning_B.ASCIIEncode2';
    
xcp.signals(15).symbol =  'hil_tuning_B.UDPReceive_o1';
    
xcp.signals(16).symbol =  'hil_tuning_B.UDPReceive_o2';
    
xcp.signals(17).symbol =  'hil_tuning_B.Clock';
    
xcp.signals(18).symbol =  'hil_tuning_B.Output';
    
xcp.signals(19).symbol =  'hil_tuning_B.LookUpTable1';
    
xcp.signals(20).symbol =  'hil_tuning_B.MathFunction';
    
xcp.signals(21).symbol =  'hil_tuning_B.Sum';
    
xcp.signals(22).symbol =  'hil_tuning_B.Clock_c';
    
xcp.signals(23).symbol =  'hil_tuning_B.Output_a';
    
xcp.signals(24).symbol =  'hil_tuning_B.LookUpTable1_k';
    
xcp.signals(25).symbol =  'hil_tuning_B.MathFunction_p';
    
xcp.signals(26).symbol =  'hil_tuning_B.Sum_k';
    
xcp.signals(27).symbol =  'hil_tuning_B.Clock_j';
    
xcp.signals(28).symbol =  'hil_tuning_B.Output_d';
    
xcp.signals(29).symbol =  'hil_tuning_B.LookUpTable1_j';
    
xcp.signals(30).symbol =  'hil_tuning_B.MathFunction_l';
    
xcp.signals(31).symbol =  'hil_tuning_B.Sum_ks';
    
xcp.signals(32).symbol =  'hil_tuning_B.Clock_h';
    
xcp.signals(33).symbol =  'hil_tuning_B.Output_i';
    
xcp.signals(34).symbol =  'hil_tuning_B.LookUpTable1_jw';
    
xcp.signals(35).symbol =  'hil_tuning_B.MathFunction_a';
    
xcp.signals(36).symbol =  'hil_tuning_B.Sum_m';
    
xcp.signals(37).symbol =  'hil_tuning_B.Clock_l';
    
xcp.signals(38).symbol =  'hil_tuning_B.Output_o';
    
xcp.signals(39).symbol =  'hil_tuning_B.LookUpTable1_i';
    
xcp.signals(40).symbol =  'hil_tuning_B.MathFunction_o';
    
xcp.signals(41).symbol =  'hil_tuning_B.Sum_g';
    
xcp.signals(42).symbol =  'hil_tuning_B.Clock_i';
    
xcp.signals(43).symbol =  'hil_tuning_B.Output_iv';
    
xcp.signals(44).symbol =  'hil_tuning_B.LookUpTable1_b';
    
xcp.signals(45).symbol =  'hil_tuning_B.MathFunction_e';
    
xcp.signals(46).symbol =  'hil_tuning_B.Sum_e';
    
xcp.signals(47).symbol =  'hil_tuning_B.Clock_f';
    
xcp.signals(48).symbol =  'hil_tuning_B.Output_k';
    
xcp.signals(49).symbol =  'hil_tuning_B.LookUpTable1_o';
    
xcp.signals(50).symbol =  'hil_tuning_B.MathFunction_f';
    
xcp.signals(51).symbol =  'hil_tuning_B.Sum_j';
    
xcp.signals(52).symbol =  'hil_tuning_B.Clock_p';
    
xcp.signals(53).symbol =  'hil_tuning_B.Output_h';
    
xcp.signals(54).symbol =  'hil_tuning_B.LookUpTable1_m';
    
xcp.signals(55).symbol =  'hil_tuning_B.MathFunction_d';
    
xcp.signals(56).symbol =  'hil_tuning_B.Sum_l';
    
xcp.signals(57).symbol =  'hil_tuning_B.Clock_fy';
    
xcp.signals(58).symbol =  'hil_tuning_B.Output_f';
    
xcp.signals(59).symbol =  'hil_tuning_B.LookUpTable1_jt';
    
xcp.signals(60).symbol =  'hil_tuning_B.MathFunction_h';
    
xcp.signals(61).symbol =  'hil_tuning_B.Sum_b';
    
xcp.signals(62).symbol =  'hil_tuning_B.Clock_io';
    
xcp.signals(63).symbol =  'hil_tuning_B.Output_i5';
    
xcp.signals(64).symbol =  'hil_tuning_B.LookUpTable1_f';
    
xcp.signals(65).symbol =  'hil_tuning_B.MathFunction_b';
    
xcp.signals(66).symbol =  'hil_tuning_B.Sum_kw';
    
xcp.signals(67).symbol =  'hil_tuning_B.Clock_l0';
    
xcp.signals(68).symbol =  'hil_tuning_B.Output_o4';
    
xcp.signals(69).symbol =  'hil_tuning_B.LookUpTable1_fg';
    
xcp.signals(70).symbol =  'hil_tuning_B.MathFunction_n';
    
xcp.signals(71).symbol =  'hil_tuning_B.Sum_p';
    
xcp.signals(72).symbol =  'hil_tuning_B.Clock_n';
    
xcp.signals(73).symbol =  'hil_tuning_B.Output_p';
    
xcp.signals(74).symbol =  'hil_tuning_B.LookUpTable1_p';
    
xcp.signals(75).symbol =  'hil_tuning_B.MathFunction_i';
    
xcp.signals(76).symbol =  'hil_tuning_B.Sum_eg';
    
xcp.signals(77).symbol =  'hil_tuning_B.DataTypeConversion';
    
xcp.signals(78).symbol =  'hil_tuning_B.Gain';
    
xcp.signals(79).symbol =  'hil_tuning_B.Add';
    
xcp.signals(80).symbol =  'hil_tuning_B.DataTypeConversion_e';
    
xcp.signals(81).symbol =  'hil_tuning_B.Gain_m';
    
xcp.signals(82).symbol =  'hil_tuning_B.Add_a';
    
xcp.signals(83).symbol =  'hil_tuning_B.DataTypeConversion_g';
    
xcp.signals(84).symbol =  'hil_tuning_B.Gain_g';
    
xcp.signals(85).symbol =  'hil_tuning_B.Add_f';
    
xcp.signals(86).symbol =  'hil_tuning_B.DataTypeConversion_j';
    
xcp.signals(87).symbol =  'hil_tuning_B.Gain_f';
    
xcp.signals(88).symbol =  'hil_tuning_B.Add_c';
    
xcp.signals(89).symbol =  'hil_tuning_B.DataTypeConversion_b';
    
xcp.signals(90).symbol =  'hil_tuning_B.Gain_eb';
    
xcp.signals(91).symbol =  'hil_tuning_B.Add_j';
    
xcp.signals(92).symbol =  'hil_tuning_B.DataTypeConversion_l';
    
xcp.signals(93).symbol =  'hil_tuning_B.Gain_d';
    
xcp.signals(94).symbol =  'hil_tuning_B.Add_ca';
    
xcp.signals(95).symbol =  'hil_tuning_B.DataTypeConversion_o';
    
xcp.signals(96).symbol =  'hil_tuning_B.Gain_k';
    
xcp.signals(97).symbol =  'hil_tuning_B.Add_h';
    
xcp.signals(98).symbol =  'hil_tuning_B.DataTypeConversion_k';
    
xcp.signals(99).symbol =  'hil_tuning_B.Gain_e';
    
xcp.signals(100).symbol =  'hil_tuning_B.Add_d';
    
xcp.signals(101).symbol =  'hil_tuning_B.DataTypeConversion_ji';
    
xcp.signals(102).symbol =  'hil_tuning_B.Gain_c';
    
xcp.signals(103).symbol =  'hil_tuning_B.Add_o';
    
xcp.signals(104).symbol =  'hil_tuning_B.DataTypeConversion_a';
    
xcp.signals(105).symbol =  'hil_tuning_B.Gain_fl';
    
xcp.signals(106).symbol =  'hil_tuning_B.Add_g';
    
xcp.signals(107).symbol =  'hil_tuning_B.DataTypeConversion_n';
    
xcp.signals(108).symbol =  'hil_tuning_B.Gain_my';
    
xcp.signals(109).symbol =  'hil_tuning_B.Add_cb';
    
xcp.signals(110).symbol =  'hil_tuning_B.DataTypeConversion_i';
    
xcp.signals(111).symbol =  'hil_tuning_B.Gain_j';
    
xcp.signals(112).symbol =  'hil_tuning_B.Add_k';
         
xcp.parameters(1).symbol = 'hil_tuning_P.Constant3_Value';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&hil_tuning_P.Constant3_Value';     
         
xcp.parameters(2).symbol = 'hil_tuning_P.abduction_tune_Value';
xcp.parameters(2).size   =  1;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&hil_tuning_P.abduction_tune_Value';     
         
xcp.parameters(3).symbol = 'hil_tuning_P.ankle_tune_Value';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&hil_tuning_P.ankle_tune_Value';     
         
xcp.parameters(4).symbol = 'hil_tuning_P.ankle_twist_tune_Value';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&hil_tuning_P.ankle_twist_tune_Value';     
         
xcp.parameters(5).symbol = 'hil_tuning_P.hip_tune_Value';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&hil_tuning_P.hip_tune_Value';     
         
xcp.parameters(6).symbol = 'hil_tuning_P.knee_tune_Value';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&hil_tuning_P.knee_tune_Value';     
         
xcp.parameters(7).symbol = 'hil_tuning_P.rotation_tune_Value';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&hil_tuning_P.rotation_tune_Value';     
         
xcp.parameters(8).symbol = 'hil_tuning_P.ASCIIDecode_P1';
xcp.parameters(8).size   =  35;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&hil_tuning_P.ASCIIDecode_P1[0]';     
         
xcp.parameters(9).symbol = 'hil_tuning_P.ASCIIDecode_P2';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&hil_tuning_P.ASCIIDecode_P2';     
         
xcp.parameters(10).symbol = 'hil_tuning_P.ASCIIDecode_P3';
xcp.parameters(10).size   =  12;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&hil_tuning_P.ASCIIDecode_P3[0]';     
         
xcp.parameters(11).symbol = 'hil_tuning_P.ASCIIEncode2_P1';
xcp.parameters(11).size   =  35;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&hil_tuning_P.ASCIIEncode2_P1[0]';     
         
xcp.parameters(12).symbol = 'hil_tuning_P.ASCIIEncode2_P2';
xcp.parameters(12).size   =  1;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&hil_tuning_P.ASCIIEncode2_P2';     
         
xcp.parameters(13).symbol = 'hil_tuning_P.ASCIIEncode2_P3';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&hil_tuning_P.ASCIIEncode2_P3';     
         
xcp.parameters(14).symbol = 'hil_tuning_P.ASCIIEncode2_P4';
xcp.parameters(14).size   =  12;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&hil_tuning_P.ASCIIEncode2_P4[0]';     
         
xcp.parameters(15).symbol = 'hil_tuning_P.UDPConfigure_P1';
xcp.parameters(15).size   =  4;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&hil_tuning_P.UDPConfigure_P1[0]';     
         
xcp.parameters(16).symbol = 'hil_tuning_P.UDPConfigure_P2';
xcp.parameters(16).size   =  4;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&hil_tuning_P.UDPConfigure_P2[0]';     
         
xcp.parameters(17).symbol = 'hil_tuning_P.UDPConfigure_P3';
xcp.parameters(17).size   =  4;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&hil_tuning_P.UDPConfigure_P3[0]';     
         
xcp.parameters(18).symbol = 'hil_tuning_P.UDPConfigure_P5';
xcp.parameters(18).size   =  1;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&hil_tuning_P.UDPConfigure_P5';     
         
xcp.parameters(19).symbol = 'hil_tuning_P.UDPConfigure_P8';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&hil_tuning_P.UDPConfigure_P8';     
         
xcp.parameters(20).symbol = 'hil_tuning_P.UDPConfigure_P9';
xcp.parameters(20).size   =  1;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&hil_tuning_P.UDPConfigure_P9';     
         
xcp.parameters(21).symbol = 'hil_tuning_P.UDPConfigure_P10';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&hil_tuning_P.UDPConfigure_P10';     
         
xcp.parameters(22).symbol = 'hil_tuning_P.UDPConfigure_P11';
xcp.parameters(22).size   =  1;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&hil_tuning_P.UDPConfigure_P11';     
         
xcp.parameters(23).symbol = 'hil_tuning_P.UDPConfigure_P12';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'real_T'; 
xcp.parameters(24).baseaddr = '&hil_tuning_P.UDPConfigure_P12';     
         
xcp.parameters(24).symbol = 'hil_tuning_P.UDPReceive_P1';
xcp.parameters(24).size   =  11;       
xcp.parameters(24).dtname = 'real_T'; 
xcp.parameters(25).baseaddr = '&hil_tuning_P.UDPReceive_P1[0]';     
         
xcp.parameters(25).symbol = 'hil_tuning_P.UDPReceive_P2';
xcp.parameters(25).size   =  1;       
xcp.parameters(25).dtname = 'real_T'; 
xcp.parameters(26).baseaddr = '&hil_tuning_P.UDPReceive_P2';     
         
xcp.parameters(26).symbol = 'hil_tuning_P.UDPReceive_P3';
xcp.parameters(26).size   =  1;       
xcp.parameters(26).dtname = 'real_T'; 
xcp.parameters(27).baseaddr = '&hil_tuning_P.UDPReceive_P3';     
         
xcp.parameters(27).symbol = 'hil_tuning_P.UDPReceive_P4';
xcp.parameters(27).size   =  1;       
xcp.parameters(27).dtname = 'real_T'; 
xcp.parameters(28).baseaddr = '&hil_tuning_P.UDPReceive_P4';     
         
xcp.parameters(28).symbol = 'hil_tuning_P.UDPReceive_P5';
xcp.parameters(28).size   =  13;       
xcp.parameters(28).dtname = 'real_T'; 
xcp.parameters(29).baseaddr = '&hil_tuning_P.UDPReceive_P5[0]';     
         
xcp.parameters(29).symbol = 'hil_tuning_P.UDPReceive_P6';
xcp.parameters(29).size   =  1;       
xcp.parameters(29).dtname = 'real_T'; 
xcp.parameters(30).baseaddr = '&hil_tuning_P.UDPReceive_P6';     
         
xcp.parameters(30).symbol = 'hil_tuning_P.UDPReceive_P7';
xcp.parameters(30).size   =  1;       
xcp.parameters(30).dtname = 'real_T'; 
xcp.parameters(31).baseaddr = '&hil_tuning_P.UDPReceive_P7';     
         
xcp.parameters(31).symbol = 'hil_tuning_P.UDPReceive_P9';
xcp.parameters(31).size   =  1;       
xcp.parameters(31).dtname = 'real_T'; 
xcp.parameters(32).baseaddr = '&hil_tuning_P.UDPReceive_P9';     
         
xcp.parameters(32).symbol = 'hil_tuning_P.UDPSend_P1';
xcp.parameters(32).size   =  11;       
xcp.parameters(32).dtname = 'real_T'; 
xcp.parameters(33).baseaddr = '&hil_tuning_P.UDPSend_P1[0]';     
         
xcp.parameters(33).symbol = 'hil_tuning_P.UDPSend_P2';
xcp.parameters(33).size   =  1;       
xcp.parameters(33).dtname = 'real_T'; 
xcp.parameters(34).baseaddr = '&hil_tuning_P.UDPSend_P2';     
         
xcp.parameters(34).symbol = 'hil_tuning_P.UDPSend_P3';
xcp.parameters(34).size   =  13;       
xcp.parameters(34).dtname = 'real_T'; 
xcp.parameters(35).baseaddr = '&hil_tuning_P.UDPSend_P3[0]';     
         
xcp.parameters(35).symbol = 'hil_tuning_P.UDPSend_P4';
xcp.parameters(35).size   =  1;       
xcp.parameters(35).dtname = 'real_T'; 
xcp.parameters(36).baseaddr = '&hil_tuning_P.UDPSend_P4';     
         
xcp.parameters(36).symbol = 'hil_tuning_P.UDPSend_P5';
xcp.parameters(36).size   =  1;       
xcp.parameters(36).dtname = 'real_T'; 
xcp.parameters(37).baseaddr = '&hil_tuning_P.UDPSend_P5';     
         
xcp.parameters(37).symbol = 'hil_tuning_P.UDPSend_P6';
xcp.parameters(37).size   =  1;       
xcp.parameters(37).dtname = 'real_T'; 
xcp.parameters(38).baseaddr = '&hil_tuning_P.UDPSend_P6';     
         
xcp.parameters(38).symbol = 'hil_tuning_P.Constant_Value';
xcp.parameters(38).size   =  1;       
xcp.parameters(38).dtname = 'real_T'; 
xcp.parameters(39).baseaddr = '&hil_tuning_P.Constant_Value';     
         
xcp.parameters(39).symbol = 'hil_tuning_P.LookUpTable1_bp01Data';
xcp.parameters(39).size   =  40;       
xcp.parameters(39).dtname = 'real_T'; 
xcp.parameters(40).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data[0]';     
         
xcp.parameters(40).symbol = 'hil_tuning_P.Constant_Value_k';
xcp.parameters(40).size   =  1;       
xcp.parameters(40).dtname = 'real_T'; 
xcp.parameters(41).baseaddr = '&hil_tuning_P.Constant_Value_k';     
         
xcp.parameters(41).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_n';
xcp.parameters(41).size   =  40;       
xcp.parameters(41).dtname = 'real_T'; 
xcp.parameters(42).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_n[0]';     
         
xcp.parameters(42).symbol = 'hil_tuning_P.Constant_Value_p';
xcp.parameters(42).size   =  1;       
xcp.parameters(42).dtname = 'real_T'; 
xcp.parameters(43).baseaddr = '&hil_tuning_P.Constant_Value_p';     
         
xcp.parameters(43).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_d';
xcp.parameters(43).size   =  40;       
xcp.parameters(43).dtname = 'real_T'; 
xcp.parameters(44).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_d[0]';     
         
xcp.parameters(44).symbol = 'hil_tuning_P.Constant_Value_g';
xcp.parameters(44).size   =  1;       
xcp.parameters(44).dtname = 'real_T'; 
xcp.parameters(45).baseaddr = '&hil_tuning_P.Constant_Value_g';     
         
xcp.parameters(45).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_l';
xcp.parameters(45).size   =  40;       
xcp.parameters(45).dtname = 'real_T'; 
xcp.parameters(46).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_l[0]';     
         
xcp.parameters(46).symbol = 'hil_tuning_P.Constant_Value_h';
xcp.parameters(46).size   =  1;       
xcp.parameters(46).dtname = 'real_T'; 
xcp.parameters(47).baseaddr = '&hil_tuning_P.Constant_Value_h';     
         
xcp.parameters(47).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_g';
xcp.parameters(47).size   =  40;       
xcp.parameters(47).dtname = 'real_T'; 
xcp.parameters(48).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_g[0]';     
         
xcp.parameters(48).symbol = 'hil_tuning_P.Constant_Value_gs';
xcp.parameters(48).size   =  1;       
xcp.parameters(48).dtname = 'real_T'; 
xcp.parameters(49).baseaddr = '&hil_tuning_P.Constant_Value_gs';     
         
xcp.parameters(49).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_gm';
xcp.parameters(49).size   =  40;       
xcp.parameters(49).dtname = 'real_T'; 
xcp.parameters(50).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_gm[0]';     
         
xcp.parameters(50).symbol = 'hil_tuning_P.Constant_Value_gsv';
xcp.parameters(50).size   =  1;       
xcp.parameters(50).dtname = 'real_T'; 
xcp.parameters(51).baseaddr = '&hil_tuning_P.Constant_Value_gsv';     
         
xcp.parameters(51).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_nh';
xcp.parameters(51).size   =  40;       
xcp.parameters(51).dtname = 'real_T'; 
xcp.parameters(52).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_nh[0]';     
         
xcp.parameters(52).symbol = 'hil_tuning_P.Constant_Value_a';
xcp.parameters(52).size   =  1;       
xcp.parameters(52).dtname = 'real_T'; 
xcp.parameters(53).baseaddr = '&hil_tuning_P.Constant_Value_a';     
         
xcp.parameters(53).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_e';
xcp.parameters(53).size   =  40;       
xcp.parameters(53).dtname = 'real_T'; 
xcp.parameters(54).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_e[0]';     
         
xcp.parameters(54).symbol = 'hil_tuning_P.Constant_Value_f';
xcp.parameters(54).size   =  1;       
xcp.parameters(54).dtname = 'real_T'; 
xcp.parameters(55).baseaddr = '&hil_tuning_P.Constant_Value_f';     
         
xcp.parameters(55).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_b';
xcp.parameters(55).size   =  40;       
xcp.parameters(55).dtname = 'real_T'; 
xcp.parameters(56).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_b[0]';     
         
xcp.parameters(56).symbol = 'hil_tuning_P.Constant_Value_kd';
xcp.parameters(56).size   =  1;       
xcp.parameters(56).dtname = 'real_T'; 
xcp.parameters(57).baseaddr = '&hil_tuning_P.Constant_Value_kd';     
         
xcp.parameters(57).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_k';
xcp.parameters(57).size   =  40;       
xcp.parameters(57).dtname = 'real_T'; 
xcp.parameters(58).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_k[0]';     
         
xcp.parameters(58).symbol = 'hil_tuning_P.Constant_Value_m';
xcp.parameters(58).size   =  1;       
xcp.parameters(58).dtname = 'real_T'; 
xcp.parameters(59).baseaddr = '&hil_tuning_P.Constant_Value_m';     
         
xcp.parameters(59).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_h';
xcp.parameters(59).size   =  40;       
xcp.parameters(59).dtname = 'real_T'; 
xcp.parameters(60).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_h[0]';     
         
xcp.parameters(60).symbol = 'hil_tuning_P.Constant_Value_gd';
xcp.parameters(60).size   =  1;       
xcp.parameters(60).dtname = 'real_T'; 
xcp.parameters(61).baseaddr = '&hil_tuning_P.Constant_Value_gd';     
         
xcp.parameters(61).symbol = 'hil_tuning_P.LookUpTable1_bp01Data_p';
xcp.parameters(61).size   =  40;       
xcp.parameters(61).dtname = 'real_T'; 
xcp.parameters(62).baseaddr = '&hil_tuning_P.LookUpTable1_bp01Data_p[0]';     
         
xcp.parameters(62).symbol = 'hil_tuning_P.Constant_Value_b';
xcp.parameters(62).size   =  1;       
xcp.parameters(62).dtname = 'real_T'; 
xcp.parameters(63).baseaddr = '&hil_tuning_P.Constant_Value_b';     
         
xcp.parameters(63).symbol = 'hil_tuning_P.Gain_Gain';
xcp.parameters(63).size   =  1;       
xcp.parameters(63).dtname = 'real_T'; 
xcp.parameters(64).baseaddr = '&hil_tuning_P.Gain_Gain';     
         
xcp.parameters(64).symbol = 'hil_tuning_P.Constant_Value_pf';
xcp.parameters(64).size   =  1;       
xcp.parameters(64).dtname = 'real_T'; 
xcp.parameters(65).baseaddr = '&hil_tuning_P.Constant_Value_pf';     
         
xcp.parameters(65).symbol = 'hil_tuning_P.Constant1_Value';
xcp.parameters(65).size   =  1;       
xcp.parameters(65).dtname = 'real_T'; 
xcp.parameters(66).baseaddr = '&hil_tuning_P.Constant1_Value';     
         
xcp.parameters(66).symbol = 'hil_tuning_P.Gain_Gain_f';
xcp.parameters(66).size   =  1;       
xcp.parameters(66).dtname = 'real_T'; 
xcp.parameters(67).baseaddr = '&hil_tuning_P.Gain_Gain_f';     
         
xcp.parameters(67).symbol = 'hil_tuning_P.Constant_Value_i';
xcp.parameters(67).size   =  1;       
xcp.parameters(67).dtname = 'real_T'; 
xcp.parameters(68).baseaddr = '&hil_tuning_P.Constant_Value_i';     
         
xcp.parameters(68).symbol = 'hil_tuning_P.Gain_Gain_g';
xcp.parameters(68).size   =  1;       
xcp.parameters(68).dtname = 'real_T'; 
xcp.parameters(69).baseaddr = '&hil_tuning_P.Gain_Gain_g';     
         
xcp.parameters(69).symbol = 'hil_tuning_P.Constant_Value_e';
xcp.parameters(69).size   =  1;       
xcp.parameters(69).dtname = 'real_T'; 
xcp.parameters(70).baseaddr = '&hil_tuning_P.Constant_Value_e';     
         
xcp.parameters(70).symbol = 'hil_tuning_P.Constant1_Value_e';
xcp.parameters(70).size   =  1;       
xcp.parameters(70).dtname = 'real_T'; 
xcp.parameters(71).baseaddr = '&hil_tuning_P.Constant1_Value_e';     
         
xcp.parameters(71).symbol = 'hil_tuning_P.Gain_Gain_k';
xcp.parameters(71).size   =  1;       
xcp.parameters(71).dtname = 'real_T'; 
xcp.parameters(72).baseaddr = '&hil_tuning_P.Gain_Gain_k';     
         
xcp.parameters(72).symbol = 'hil_tuning_P.Constant_Value_iy';
xcp.parameters(72).size   =  1;       
xcp.parameters(72).dtname = 'real_T'; 
xcp.parameters(73).baseaddr = '&hil_tuning_P.Constant_Value_iy';     
         
xcp.parameters(73).symbol = 'hil_tuning_P.Gain_Gain_au';
xcp.parameters(73).size   =  1;       
xcp.parameters(73).dtname = 'real_T'; 
xcp.parameters(74).baseaddr = '&hil_tuning_P.Gain_Gain_au';     
         
xcp.parameters(74).symbol = 'hil_tuning_P.Constant_Value_mw';
xcp.parameters(74).size   =  1;       
xcp.parameters(74).dtname = 'real_T'; 
xcp.parameters(75).baseaddr = '&hil_tuning_P.Constant_Value_mw';     
         
xcp.parameters(75).symbol = 'hil_tuning_P.Constant1_Value_a';
xcp.parameters(75).size   =  1;       
xcp.parameters(75).dtname = 'real_T'; 
xcp.parameters(76).baseaddr = '&hil_tuning_P.Constant1_Value_a';     
         
xcp.parameters(76).symbol = 'hil_tuning_P.Gain_Gain_jv';
xcp.parameters(76).size   =  1;       
xcp.parameters(76).dtname = 'real_T'; 
xcp.parameters(77).baseaddr = '&hil_tuning_P.Gain_Gain_jv';     
         
xcp.parameters(77).symbol = 'hil_tuning_P.Constant_Value_pr';
xcp.parameters(77).size   =  1;       
xcp.parameters(77).dtname = 'real_T'; 
xcp.parameters(78).baseaddr = '&hil_tuning_P.Constant_Value_pr';     
         
xcp.parameters(78).symbol = 'hil_tuning_P.Constant1_Value_gr';
xcp.parameters(78).size   =  1;       
xcp.parameters(78).dtname = 'real_T'; 
xcp.parameters(79).baseaddr = '&hil_tuning_P.Constant1_Value_gr';     
         
xcp.parameters(79).symbol = 'hil_tuning_P.Gain_Gain_j0';
xcp.parameters(79).size   =  1;       
xcp.parameters(79).dtname = 'real_T'; 
xcp.parameters(80).baseaddr = '&hil_tuning_P.Gain_Gain_j0';     
         
xcp.parameters(80).symbol = 'hil_tuning_P.Constant_Value_pk';
xcp.parameters(80).size   =  1;       
xcp.parameters(80).dtname = 'real_T'; 
xcp.parameters(81).baseaddr = '&hil_tuning_P.Constant_Value_pk';     
         
xcp.parameters(81).symbol = 'hil_tuning_P.Constant1_Value_g';
xcp.parameters(81).size   =  1;       
xcp.parameters(81).dtname = 'real_T'; 
xcp.parameters(82).baseaddr = '&hil_tuning_P.Constant1_Value_g';     
         
xcp.parameters(82).symbol = 'hil_tuning_P.Gain_Gain_kd';
xcp.parameters(82).size   =  1;       
xcp.parameters(82).dtname = 'real_T'; 
xcp.parameters(83).baseaddr = '&hil_tuning_P.Gain_Gain_kd';     
         
xcp.parameters(83).symbol = 'hil_tuning_P.Constant_Value_gdr';
xcp.parameters(83).size   =  1;       
xcp.parameters(83).dtname = 'real_T'; 
xcp.parameters(84).baseaddr = '&hil_tuning_P.Constant_Value_gdr';     
         
xcp.parameters(84).symbol = 'hil_tuning_P.Gain_Gain_n';
xcp.parameters(84).size   =  1;       
xcp.parameters(84).dtname = 'real_T'; 
xcp.parameters(85).baseaddr = '&hil_tuning_P.Gain_Gain_n';     
         
xcp.parameters(85).symbol = 'hil_tuning_P.Constant_Value_d';
xcp.parameters(85).size   =  1;       
xcp.parameters(85).dtname = 'real_T'; 
xcp.parameters(86).baseaddr = '&hil_tuning_P.Constant_Value_d';     
         
xcp.parameters(86).symbol = 'hil_tuning_P.Gain_Gain_d';
xcp.parameters(86).size   =  1;       
xcp.parameters(86).dtname = 'real_T'; 
xcp.parameters(87).baseaddr = '&hil_tuning_P.Gain_Gain_d';     
         
xcp.parameters(87).symbol = 'hil_tuning_P.Constant_Value_ij';
xcp.parameters(87).size   =  1;       
xcp.parameters(87).dtname = 'real_T'; 
xcp.parameters(88).baseaddr = '&hil_tuning_P.Constant_Value_ij';     
         
xcp.parameters(88).symbol = 'hil_tuning_P.Gain_Gain_a';
xcp.parameters(88).size   =  1;       
xcp.parameters(88).dtname = 'real_T'; 
xcp.parameters(89).baseaddr = '&hil_tuning_P.Gain_Gain_a';     
         
xcp.parameters(89).symbol = 'hil_tuning_P.Constant_Value_l';
xcp.parameters(89).size   =  1;       
xcp.parameters(89).dtname = 'real_T'; 
xcp.parameters(90).baseaddr = '&hil_tuning_P.Constant_Value_l';     
         
xcp.parameters(90).symbol = 'hil_tuning_P.Constant1_Value_k';
xcp.parameters(90).size   =  1;       
xcp.parameters(90).dtname = 'real_T'; 
xcp.parameters(91).baseaddr = '&hil_tuning_P.Constant1_Value_k';     
         
xcp.parameters(91).symbol = 'hil_tuning_P.Gain_Gain_j';
xcp.parameters(91).size   =  1;       
xcp.parameters(91).dtname = 'real_T'; 
xcp.parameters(92).baseaddr = '&hil_tuning_P.Gain_Gain_j';     
         
xcp.parameters(92).symbol = 'hil_tuning_P.left_abduction';
xcp.parameters(92).size   =  40;       
xcp.parameters(92).dtname = 'real_T'; 
xcp.parameters(93).baseaddr = '&hil_tuning_P.left_abduction[0]';     
         
xcp.parameters(93).symbol = 'hil_tuning_P.left_ankle';
xcp.parameters(93).size   =  40;       
xcp.parameters(93).dtname = 'real_T'; 
xcp.parameters(94).baseaddr = '&hil_tuning_P.left_ankle[0]';     
         
xcp.parameters(94).symbol = 'hil_tuning_P.left_hip';
xcp.parameters(94).size   =  40;       
xcp.parameters(94).dtname = 'real_T'; 
xcp.parameters(95).baseaddr = '&hil_tuning_P.left_hip[0]';     
         
xcp.parameters(95).symbol = 'hil_tuning_P.left_knee';
xcp.parameters(95).size   =  40;       
xcp.parameters(95).dtname = 'real_T'; 
xcp.parameters(96).baseaddr = '&hil_tuning_P.left_knee[0]';     
         
xcp.parameters(96).symbol = 'hil_tuning_P.left_knee_twist';
xcp.parameters(96).size   =  40;       
xcp.parameters(96).dtname = 'real_T'; 
xcp.parameters(97).baseaddr = '&hil_tuning_P.left_knee_twist[0]';     
         
xcp.parameters(97).symbol = 'hil_tuning_P.left_rotation';
xcp.parameters(97).size   =  40;       
xcp.parameters(97).dtname = 'real_T'; 
xcp.parameters(98).baseaddr = '&hil_tuning_P.left_rotation[0]';     
         
xcp.parameters(98).symbol = 'hil_tuning_P.right_abduction';
xcp.parameters(98).size   =  40;       
xcp.parameters(98).dtname = 'real_T'; 
xcp.parameters(99).baseaddr = '&hil_tuning_P.right_abduction[0]';     
         
xcp.parameters(99).symbol = 'hil_tuning_P.right_ankle';
xcp.parameters(99).size   =  40;       
xcp.parameters(99).dtname = 'real_T'; 
xcp.parameters(100).baseaddr = '&hil_tuning_P.right_ankle[0]';     
         
xcp.parameters(100).symbol = 'hil_tuning_P.right_hip';
xcp.parameters(100).size   =  40;       
xcp.parameters(100).dtname = 'real_T'; 
xcp.parameters(101).baseaddr = '&hil_tuning_P.right_hip[0]';     
         
xcp.parameters(101).symbol = 'hil_tuning_P.right_knee';
xcp.parameters(101).size   =  40;       
xcp.parameters(101).dtname = 'real_T'; 
xcp.parameters(102).baseaddr = '&hil_tuning_P.right_knee[0]';     
         
xcp.parameters(102).symbol = 'hil_tuning_P.right_knee_twist';
xcp.parameters(102).size   =  40;       
xcp.parameters(102).dtname = 'real_T'; 
xcp.parameters(103).baseaddr = '&hil_tuning_P.right_knee_twist[0]';     
         
xcp.parameters(103).symbol = 'hil_tuning_P.right_rotation';
xcp.parameters(103).size   =  40;       
xcp.parameters(103).dtname = 'real_T'; 
xcp.parameters(104).baseaddr = '&hil_tuning_P.right_rotation[0]';     

function n = getNumParameters
n = 103;

function n = getNumSignals
n = 112;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

