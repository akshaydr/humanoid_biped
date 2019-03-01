function pt=hil_tuningpt
pt = [];

  
pt(1).blockname = 'Constant3';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'hil_tuning_P.Constant3_Value';
pt(1).baseaddr   = '&hil_tuning_P.Constant3_Value';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'abduction_tune';
pt(2).paramname = 'Value';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'hil_tuning_P.abduction_tune_Value';
pt(2).baseaddr   = '&hil_tuning_P.abduction_tune_Value';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = 'ankle_tune';
pt(3).paramname = 'Value';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'hil_tuning_P.ankle_tune_Value';
pt(3).baseaddr   = '&hil_tuning_P.ankle_tune_Value';
pt(3).dtname     = 'real_T';



  
pt(4).blockname = 'ankle_twist_tune';
pt(4).paramname = 'Value';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';
pt(4).isStruct  = false;
pt(4).symbol     = 'hil_tuning_P.ankle_twist_tune_Value';
pt(4).baseaddr   = '&hil_tuning_P.ankle_twist_tune_Value';
pt(4).dtname     = 'real_T';



  
pt(5).blockname = 'hip_tune';
pt(5).paramname = 'Value';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';
pt(5).isStruct  = false;
pt(5).symbol     = 'hil_tuning_P.hip_tune_Value';
pt(5).baseaddr   = '&hil_tuning_P.hip_tune_Value';
pt(5).dtname     = 'real_T';



  
pt(6).blockname = 'knee_tune';
pt(6).paramname = 'Value';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';
pt(6).isStruct  = false;
pt(6).symbol     = 'hil_tuning_P.knee_tune_Value';
pt(6).baseaddr   = '&hil_tuning_P.knee_tune_Value';
pt(6).dtname     = 'real_T';



  
pt(7).blockname = 'rotation_tune';
pt(7).paramname = 'Value';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';
pt(7).isStruct  = false;
pt(7).symbol     = 'hil_tuning_P.rotation_tune_Value';
pt(7).baseaddr   = '&hil_tuning_P.rotation_tune_Value';
pt(7).dtname     = 'real_T';



  
pt(8).blockname = 'ASCII Decode ';
pt(8).paramname = 'P1';
pt(8).class     = 'vector';
pt(8).nrows     = 1;
pt(8).ncols     = 35;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';
pt(8).isStruct  = false;
pt(8).symbol     = 'hil_tuning_P.ASCIIDecode_P1';
pt(8).baseaddr   = '&hil_tuning_P.ASCIIDecode_P1[0]';
pt(8).dtname     = 'real_T';



  
pt(9).blockname = 'ASCII Decode ';
pt(9).paramname = 'P2';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';
pt(9).isStruct  = false;
pt(9).symbol     = 'hil_tuning_P.ASCIIDecode_P2';
pt(9).baseaddr   = '&hil_tuning_P.ASCIIDecode_P2';
pt(9).dtname     = 'real_T';



  
pt(10).blockname = 'ASCII Decode ';
pt(10).paramname = 'P3';
pt(10).class     = 'vector';
pt(10).nrows     = 1;
pt(10).ncols     = 12;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';
pt(10).isStruct  = false;
pt(10).symbol     = 'hil_tuning_P.ASCIIDecode_P3';
pt(10).baseaddr   = '&hil_tuning_P.ASCIIDecode_P3[0]';
pt(10).dtname     = 'real_T';



  
pt(11).blockname = 'ASCII Encode 2';
pt(11).paramname = 'P1';
pt(11).class     = 'vector';
pt(11).nrows     = 1;
pt(11).ncols     = 35;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';
pt(11).isStruct  = false;
pt(11).symbol     = 'hil_tuning_P.ASCIIEncode2_P1';
pt(11).baseaddr   = '&hil_tuning_P.ASCIIEncode2_P1[0]';
pt(11).dtname     = 'real_T';



  
pt(12).blockname = 'ASCII Encode 2';
pt(12).paramname = 'P2';
pt(12).class     = 'scalar';
pt(12).nrows     = 1;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';
pt(12).isStruct  = false;
pt(12).symbol     = 'hil_tuning_P.ASCIIEncode2_P2';
pt(12).baseaddr   = '&hil_tuning_P.ASCIIEncode2_P2';
pt(12).dtname     = 'real_T';



  
pt(13).blockname = 'ASCII Encode 2';
pt(13).paramname = 'P3';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';
pt(13).isStruct  = false;
pt(13).symbol     = 'hil_tuning_P.ASCIIEncode2_P3';
pt(13).baseaddr   = '&hil_tuning_P.ASCIIEncode2_P3';
pt(13).dtname     = 'real_T';



  
pt(14).blockname = 'ASCII Encode 2';
pt(14).paramname = 'P4';
pt(14).class     = 'vector';
pt(14).nrows     = 1;
pt(14).ncols     = 12;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';
pt(14).isStruct  = false;
pt(14).symbol     = 'hil_tuning_P.ASCIIEncode2_P4';
pt(14).baseaddr   = '&hil_tuning_P.ASCIIEncode2_P4[0]';
pt(14).dtname     = 'real_T';



  
pt(15).blockname = 'UDP Configure';
pt(15).paramname = 'P1';
pt(15).class     = 'vector';
pt(15).nrows     = 1;
pt(15).ncols     = 4;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';
pt(15).isStruct  = false;
pt(15).symbol     = 'hil_tuning_P.UDPConfigure_P1';
pt(15).baseaddr   = '&hil_tuning_P.UDPConfigure_P1[0]';
pt(15).dtname     = 'real_T';



  
pt(16).blockname = 'UDP Configure';
pt(16).paramname = 'P2';
pt(16).class     = 'vector';
pt(16).nrows     = 1;
pt(16).ncols     = 4;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';
pt(16).isStruct  = false;
pt(16).symbol     = 'hil_tuning_P.UDPConfigure_P2';
pt(16).baseaddr   = '&hil_tuning_P.UDPConfigure_P2[0]';
pt(16).dtname     = 'real_T';



  
pt(17).blockname = 'UDP Configure';
pt(17).paramname = 'P3';
pt(17).class     = 'vector';
pt(17).nrows     = 1;
pt(17).ncols     = 4;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';
pt(17).isStruct  = false;
pt(17).symbol     = 'hil_tuning_P.UDPConfigure_P3';
pt(17).baseaddr   = '&hil_tuning_P.UDPConfigure_P3[0]';
pt(17).dtname     = 'real_T';



  
pt(18).blockname = 'UDP Configure';
pt(18).paramname = 'P5';
pt(18).class     = 'scalar';
pt(18).nrows     = 1;
pt(18).ncols     = 1;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';
pt(18).isStruct  = false;
pt(18).symbol     = 'hil_tuning_P.UDPConfigure_P5';
pt(18).baseaddr   = '&hil_tuning_P.UDPConfigure_P5';
pt(18).dtname     = 'real_T';



  
pt(19).blockname = 'UDP Configure';
pt(19).paramname = 'P8';
pt(19).class     = 'scalar';
pt(19).nrows     = 1;
pt(19).ncols     = 1;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';
pt(19).isStruct  = false;
pt(19).symbol     = 'hil_tuning_P.UDPConfigure_P8';
pt(19).baseaddr   = '&hil_tuning_P.UDPConfigure_P8';
pt(19).dtname     = 'real_T';



  
pt(20).blockname = 'UDP Configure';
pt(20).paramname = 'P9';
pt(20).class     = 'scalar';
pt(20).nrows     = 1;
pt(20).ncols     = 1;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';
pt(20).isStruct  = false;
pt(20).symbol     = 'hil_tuning_P.UDPConfigure_P9';
pt(20).baseaddr   = '&hil_tuning_P.UDPConfigure_P9';
pt(20).dtname     = 'real_T';



  
pt(21).blockname = 'UDP Configure';
pt(21).paramname = 'P10';
pt(21).class     = 'scalar';
pt(21).nrows     = 1;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';
pt(21).isStruct  = false;
pt(21).symbol     = 'hil_tuning_P.UDPConfigure_P10';
pt(21).baseaddr   = '&hil_tuning_P.UDPConfigure_P10';
pt(21).dtname     = 'real_T';



  
pt(22).blockname = 'UDP Configure';
pt(22).paramname = 'P11';
pt(22).class     = 'scalar';
pt(22).nrows     = 1;
pt(22).ncols     = 1;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';
pt(22).isStruct  = false;
pt(22).symbol     = 'hil_tuning_P.UDPConfigure_P11';
pt(22).baseaddr   = '&hil_tuning_P.UDPConfigure_P11';
pt(22).dtname     = 'real_T';



  
pt(23).blockname = 'UDP Configure';
pt(23).paramname = 'P12';
pt(23).class     = 'scalar';
pt(23).nrows     = 1;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';
pt(23).ndims     = '2';
pt(23).size      = '[]';
pt(23).isStruct  = false;
pt(23).symbol     = 'hil_tuning_P.UDPConfigure_P12';
pt(23).baseaddr   = '&hil_tuning_P.UDPConfigure_P12';
pt(23).dtname     = 'real_T';



  
pt(24).blockname = 'UDP Receive';
pt(24).paramname = 'P1';
pt(24).class     = 'vector';
pt(24).nrows     = 1;
pt(24).ncols     = 11;
pt(24).subsource = 'SS_DOUBLE';
pt(24).ndims     = '2';
pt(24).size      = '[]';
pt(24).isStruct  = false;
pt(24).symbol     = 'hil_tuning_P.UDPReceive_P1';
pt(24).baseaddr   = '&hil_tuning_P.UDPReceive_P1[0]';
pt(24).dtname     = 'real_T';



  
pt(25).blockname = 'UDP Receive';
pt(25).paramname = 'P2';
pt(25).class     = 'scalar';
pt(25).nrows     = 1;
pt(25).ncols     = 1;
pt(25).subsource = 'SS_DOUBLE';
pt(25).ndims     = '2';
pt(25).size      = '[]';
pt(25).isStruct  = false;
pt(25).symbol     = 'hil_tuning_P.UDPReceive_P2';
pt(25).baseaddr   = '&hil_tuning_P.UDPReceive_P2';
pt(25).dtname     = 'real_T';



  
pt(26).blockname = 'UDP Receive';
pt(26).paramname = 'P3';
pt(26).class     = 'scalar';
pt(26).nrows     = 1;
pt(26).ncols     = 1;
pt(26).subsource = 'SS_DOUBLE';
pt(26).ndims     = '2';
pt(26).size      = '[]';
pt(26).isStruct  = false;
pt(26).symbol     = 'hil_tuning_P.UDPReceive_P3';
pt(26).baseaddr   = '&hil_tuning_P.UDPReceive_P3';
pt(26).dtname     = 'real_T';



  
pt(27).blockname = 'UDP Receive';
pt(27).paramname = 'P4';
pt(27).class     = 'scalar';
pt(27).nrows     = 1;
pt(27).ncols     = 1;
pt(27).subsource = 'SS_DOUBLE';
pt(27).ndims     = '2';
pt(27).size      = '[]';
pt(27).isStruct  = false;
pt(27).symbol     = 'hil_tuning_P.UDPReceive_P4';
pt(27).baseaddr   = '&hil_tuning_P.UDPReceive_P4';
pt(27).dtname     = 'real_T';



  
pt(28).blockname = 'UDP Receive';
pt(28).paramname = 'P5';
pt(28).class     = 'vector';
pt(28).nrows     = 1;
pt(28).ncols     = 13;
pt(28).subsource = 'SS_DOUBLE';
pt(28).ndims     = '2';
pt(28).size      = '[]';
pt(28).isStruct  = false;
pt(28).symbol     = 'hil_tuning_P.UDPReceive_P5';
pt(28).baseaddr   = '&hil_tuning_P.UDPReceive_P5[0]';
pt(28).dtname     = 'real_T';



  
pt(29).blockname = 'UDP Receive';
pt(29).paramname = 'P6';
pt(29).class     = 'scalar';
pt(29).nrows     = 1;
pt(29).ncols     = 1;
pt(29).subsource = 'SS_DOUBLE';
pt(29).ndims     = '2';
pt(29).size      = '[]';
pt(29).isStruct  = false;
pt(29).symbol     = 'hil_tuning_P.UDPReceive_P6';
pt(29).baseaddr   = '&hil_tuning_P.UDPReceive_P6';
pt(29).dtname     = 'real_T';



  
pt(30).blockname = 'UDP Receive';
pt(30).paramname = 'P7';
pt(30).class     = 'scalar';
pt(30).nrows     = 1;
pt(30).ncols     = 1;
pt(30).subsource = 'SS_DOUBLE';
pt(30).ndims     = '2';
pt(30).size      = '[]';
pt(30).isStruct  = false;
pt(30).symbol     = 'hil_tuning_P.UDPReceive_P7';
pt(30).baseaddr   = '&hil_tuning_P.UDPReceive_P7';
pt(30).dtname     = 'real_T';



  
pt(31).blockname = 'UDP Receive';
pt(31).paramname = 'P9';
pt(31).class     = 'scalar';
pt(31).nrows     = 1;
pt(31).ncols     = 1;
pt(31).subsource = 'SS_DOUBLE';
pt(31).ndims     = '2';
pt(31).size      = '[]';
pt(31).isStruct  = false;
pt(31).symbol     = 'hil_tuning_P.UDPReceive_P9';
pt(31).baseaddr   = '&hil_tuning_P.UDPReceive_P9';
pt(31).dtname     = 'real_T';



  
pt(32).blockname = 'UDP Send';
pt(32).paramname = 'P1';
pt(32).class     = 'vector';
pt(32).nrows     = 1;
pt(32).ncols     = 11;
pt(32).subsource = 'SS_DOUBLE';
pt(32).ndims     = '2';
pt(32).size      = '[]';
pt(32).isStruct  = false;
pt(32).symbol     = 'hil_tuning_P.UDPSend_P1';
pt(32).baseaddr   = '&hil_tuning_P.UDPSend_P1[0]';
pt(32).dtname     = 'real_T';



  
pt(33).blockname = 'UDP Send';
pt(33).paramname = 'P2';
pt(33).class     = 'scalar';
pt(33).nrows     = 1;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';
pt(33).ndims     = '2';
pt(33).size      = '[]';
pt(33).isStruct  = false;
pt(33).symbol     = 'hil_tuning_P.UDPSend_P2';
pt(33).baseaddr   = '&hil_tuning_P.UDPSend_P2';
pt(33).dtname     = 'real_T';



  
pt(34).blockname = 'UDP Send';
pt(34).paramname = 'P3';
pt(34).class     = 'vector';
pt(34).nrows     = 1;
pt(34).ncols     = 13;
pt(34).subsource = 'SS_DOUBLE';
pt(34).ndims     = '2';
pt(34).size      = '[]';
pt(34).isStruct  = false;
pt(34).symbol     = 'hil_tuning_P.UDPSend_P3';
pt(34).baseaddr   = '&hil_tuning_P.UDPSend_P3[0]';
pt(34).dtname     = 'real_T';



  
pt(35).blockname = 'UDP Send';
pt(35).paramname = 'P4';
pt(35).class     = 'scalar';
pt(35).nrows     = 1;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';
pt(35).ndims     = '2';
pt(35).size      = '[]';
pt(35).isStruct  = false;
pt(35).symbol     = 'hil_tuning_P.UDPSend_P4';
pt(35).baseaddr   = '&hil_tuning_P.UDPSend_P4';
pt(35).dtname     = 'real_T';



  
pt(36).blockname = 'UDP Send';
pt(36).paramname = 'P5';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';
pt(36).ndims     = '2';
pt(36).size      = '[]';
pt(36).isStruct  = false;
pt(36).symbol     = 'hil_tuning_P.UDPSend_P5';
pt(36).baseaddr   = '&hil_tuning_P.UDPSend_P5';
pt(36).dtname     = 'real_T';



  
pt(37).blockname = 'UDP Send';
pt(37).paramname = 'P6';
pt(37).class     = 'scalar';
pt(37).nrows     = 1;
pt(37).ncols     = 1;
pt(37).subsource = 'SS_DOUBLE';
pt(37).ndims     = '2';
pt(37).size      = '[]';
pt(37).isStruct  = false;
pt(37).symbol     = 'hil_tuning_P.UDPSend_P6';
pt(37).baseaddr   = '&hil_tuning_P.UDPSend_P6';
pt(37).dtname     = 'real_T';



  
pt(38).blockname = 'Left Abduction1/Constant';
pt(38).paramname = 'Value';
pt(38).class     = 'scalar';
pt(38).nrows     = 1;
pt(38).ncols     = 1;
pt(38).subsource = 'SS_DOUBLE';
pt(38).ndims     = '2';
pt(38).size      = '[]';
pt(38).isStruct  = false;
pt(38).symbol     = 'hil_tuning_P.Constant_Value';
pt(38).baseaddr   = '&hil_tuning_P.Constant_Value';
pt(38).dtname     = 'real_T';



  
pt(39).blockname = 'Left Abduction1/Look-Up Table1';
pt(39).paramname = 'BreakpointsForDimension1';
pt(39).class     = 'vector';
pt(39).nrows     = 1;
pt(39).ncols     = 40;
pt(39).subsource = 'SS_DOUBLE';
pt(39).ndims     = '2';
pt(39).size      = '[]';
pt(39).isStruct  = false;
pt(39).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data';
pt(39).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data[0]';
pt(39).dtname     = 'real_T';



  
pt(40).blockname = 'Left Ankle Twist1/Constant';
pt(40).paramname = 'Value';
pt(40).class     = 'scalar';
pt(40).nrows     = 1;
pt(40).ncols     = 1;
pt(40).subsource = 'SS_DOUBLE';
pt(40).ndims     = '2';
pt(40).size      = '[]';
pt(40).isStruct  = false;
pt(40).symbol     = 'hil_tuning_P.Constant_Value_k';
pt(40).baseaddr   = '&hil_tuning_P.Constant_Value_k';
pt(40).dtname     = 'real_T';



  
pt(41).blockname = 'Left Ankle Twist1/Look-Up Table1';
pt(41).paramname = 'BreakpointsForDimension1';
pt(41).class     = 'vector';
pt(41).nrows     = 1;
pt(41).ncols     = 40;
pt(41).subsource = 'SS_DOUBLE';
pt(41).ndims     = '2';
pt(41).size      = '[]';
pt(41).isStruct  = false;
pt(41).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_n';
pt(41).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_n[0]';
pt(41).dtname     = 'real_T';



  
pt(42).blockname = 'Left Ankle1/Constant';
pt(42).paramname = 'Value';
pt(42).class     = 'scalar';
pt(42).nrows     = 1;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';
pt(42).ndims     = '2';
pt(42).size      = '[]';
pt(42).isStruct  = false;
pt(42).symbol     = 'hil_tuning_P.Constant_Value_p';
pt(42).baseaddr   = '&hil_tuning_P.Constant_Value_p';
pt(42).dtname     = 'real_T';



  
pt(43).blockname = 'Left Ankle1/Look-Up Table1';
pt(43).paramname = 'BreakpointsForDimension1';
pt(43).class     = 'vector';
pt(43).nrows     = 1;
pt(43).ncols     = 40;
pt(43).subsource = 'SS_DOUBLE';
pt(43).ndims     = '2';
pt(43).size      = '[]';
pt(43).isStruct  = false;
pt(43).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_d';
pt(43).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_d[0]';
pt(43).dtname     = 'real_T';



  
pt(44).blockname = 'Left Hip1/Constant';
pt(44).paramname = 'Value';
pt(44).class     = 'scalar';
pt(44).nrows     = 1;
pt(44).ncols     = 1;
pt(44).subsource = 'SS_DOUBLE';
pt(44).ndims     = '2';
pt(44).size      = '[]';
pt(44).isStruct  = false;
pt(44).symbol     = 'hil_tuning_P.Constant_Value_g';
pt(44).baseaddr   = '&hil_tuning_P.Constant_Value_g';
pt(44).dtname     = 'real_T';



  
pt(45).blockname = 'Left Hip1/Look-Up Table1';
pt(45).paramname = 'BreakpointsForDimension1';
pt(45).class     = 'vector';
pt(45).nrows     = 1;
pt(45).ncols     = 40;
pt(45).subsource = 'SS_DOUBLE';
pt(45).ndims     = '2';
pt(45).size      = '[]';
pt(45).isStruct  = false;
pt(45).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_l';
pt(45).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_l[0]';
pt(45).dtname     = 'real_T';



  
pt(46).blockname = 'Left Knee1/Constant';
pt(46).paramname = 'Value';
pt(46).class     = 'scalar';
pt(46).nrows     = 1;
pt(46).ncols     = 1;
pt(46).subsource = 'SS_DOUBLE';
pt(46).ndims     = '2';
pt(46).size      = '[]';
pt(46).isStruct  = false;
pt(46).symbol     = 'hil_tuning_P.Constant_Value_h';
pt(46).baseaddr   = '&hil_tuning_P.Constant_Value_h';
pt(46).dtname     = 'real_T';



  
pt(47).blockname = 'Left Knee1/Look-Up Table1';
pt(47).paramname = 'BreakpointsForDimension1';
pt(47).class     = 'vector';
pt(47).nrows     = 1;
pt(47).ncols     = 40;
pt(47).subsource = 'SS_DOUBLE';
pt(47).ndims     = '2';
pt(47).size      = '[]';
pt(47).isStruct  = false;
pt(47).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_g';
pt(47).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_g[0]';
pt(47).dtname     = 'real_T';



  
pt(48).blockname = 'Left Rotation1/Constant';
pt(48).paramname = 'Value';
pt(48).class     = 'scalar';
pt(48).nrows     = 1;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';
pt(48).ndims     = '2';
pt(48).size      = '[]';
pt(48).isStruct  = false;
pt(48).symbol     = 'hil_tuning_P.Constant_Value_gs';
pt(48).baseaddr   = '&hil_tuning_P.Constant_Value_gs';
pt(48).dtname     = 'real_T';



  
pt(49).blockname = 'Left Rotation1/Look-Up Table1';
pt(49).paramname = 'BreakpointsForDimension1';
pt(49).class     = 'vector';
pt(49).nrows     = 1;
pt(49).ncols     = 40;
pt(49).subsource = 'SS_DOUBLE';
pt(49).ndims     = '2';
pt(49).size      = '[]';
pt(49).isStruct  = false;
pt(49).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_gm';
pt(49).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_gm[0]';
pt(49).dtname     = 'real_T';



  
pt(50).blockname = 'Right Abduction1/Constant';
pt(50).paramname = 'Value';
pt(50).class     = 'scalar';
pt(50).nrows     = 1;
pt(50).ncols     = 1;
pt(50).subsource = 'SS_DOUBLE';
pt(50).ndims     = '2';
pt(50).size      = '[]';
pt(50).isStruct  = false;
pt(50).symbol     = 'hil_tuning_P.Constant_Value_gsv';
pt(50).baseaddr   = '&hil_tuning_P.Constant_Value_gsv';
pt(50).dtname     = 'real_T';



  
pt(51).blockname = 'Right Abduction1/Look-Up Table1';
pt(51).paramname = 'BreakpointsForDimension1';
pt(51).class     = 'vector';
pt(51).nrows     = 1;
pt(51).ncols     = 40;
pt(51).subsource = 'SS_DOUBLE';
pt(51).ndims     = '2';
pt(51).size      = '[]';
pt(51).isStruct  = false;
pt(51).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_nh';
pt(51).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_nh[0]';
pt(51).dtname     = 'real_T';



  
pt(52).blockname = 'Right Ankle Twist1/Constant';
pt(52).paramname = 'Value';
pt(52).class     = 'scalar';
pt(52).nrows     = 1;
pt(52).ncols     = 1;
pt(52).subsource = 'SS_DOUBLE';
pt(52).ndims     = '2';
pt(52).size      = '[]';
pt(52).isStruct  = false;
pt(52).symbol     = 'hil_tuning_P.Constant_Value_a';
pt(52).baseaddr   = '&hil_tuning_P.Constant_Value_a';
pt(52).dtname     = 'real_T';



  
pt(53).blockname = 'Right Ankle Twist1/Look-Up Table1';
pt(53).paramname = 'BreakpointsForDimension1';
pt(53).class     = 'vector';
pt(53).nrows     = 1;
pt(53).ncols     = 40;
pt(53).subsource = 'SS_DOUBLE';
pt(53).ndims     = '2';
pt(53).size      = '[]';
pt(53).isStruct  = false;
pt(53).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_e';
pt(53).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_e[0]';
pt(53).dtname     = 'real_T';



  
pt(54).blockname = 'Right Ankle1/Constant';
pt(54).paramname = 'Value';
pt(54).class     = 'scalar';
pt(54).nrows     = 1;
pt(54).ncols     = 1;
pt(54).subsource = 'SS_DOUBLE';
pt(54).ndims     = '2';
pt(54).size      = '[]';
pt(54).isStruct  = false;
pt(54).symbol     = 'hil_tuning_P.Constant_Value_f';
pt(54).baseaddr   = '&hil_tuning_P.Constant_Value_f';
pt(54).dtname     = 'real_T';



  
pt(55).blockname = 'Right Ankle1/Look-Up Table1';
pt(55).paramname = 'BreakpointsForDimension1';
pt(55).class     = 'vector';
pt(55).nrows     = 1;
pt(55).ncols     = 40;
pt(55).subsource = 'SS_DOUBLE';
pt(55).ndims     = '2';
pt(55).size      = '[]';
pt(55).isStruct  = false;
pt(55).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_b';
pt(55).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_b[0]';
pt(55).dtname     = 'real_T';



  
pt(56).blockname = 'Right Hip1/Constant';
pt(56).paramname = 'Value';
pt(56).class     = 'scalar';
pt(56).nrows     = 1;
pt(56).ncols     = 1;
pt(56).subsource = 'SS_DOUBLE';
pt(56).ndims     = '2';
pt(56).size      = '[]';
pt(56).isStruct  = false;
pt(56).symbol     = 'hil_tuning_P.Constant_Value_kd';
pt(56).baseaddr   = '&hil_tuning_P.Constant_Value_kd';
pt(56).dtname     = 'real_T';



  
pt(57).blockname = 'Right Hip1/Look-Up Table1';
pt(57).paramname = 'BreakpointsForDimension1';
pt(57).class     = 'vector';
pt(57).nrows     = 1;
pt(57).ncols     = 40;
pt(57).subsource = 'SS_DOUBLE';
pt(57).ndims     = '2';
pt(57).size      = '[]';
pt(57).isStruct  = false;
pt(57).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_k';
pt(57).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_k[0]';
pt(57).dtname     = 'real_T';



  
pt(58).blockname = 'Right Knee1/Constant';
pt(58).paramname = 'Value';
pt(58).class     = 'scalar';
pt(58).nrows     = 1;
pt(58).ncols     = 1;
pt(58).subsource = 'SS_DOUBLE';
pt(58).ndims     = '2';
pt(58).size      = '[]';
pt(58).isStruct  = false;
pt(58).symbol     = 'hil_tuning_P.Constant_Value_m';
pt(58).baseaddr   = '&hil_tuning_P.Constant_Value_m';
pt(58).dtname     = 'real_T';



  
pt(59).blockname = 'Right Knee1/Look-Up Table1';
pt(59).paramname = 'BreakpointsForDimension1';
pt(59).class     = 'vector';
pt(59).nrows     = 1;
pt(59).ncols     = 40;
pt(59).subsource = 'SS_DOUBLE';
pt(59).ndims     = '2';
pt(59).size      = '[]';
pt(59).isStruct  = false;
pt(59).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_h';
pt(59).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_h[0]';
pt(59).dtname     = 'real_T';



  
pt(60).blockname = 'Right Rotation1/Constant';
pt(60).paramname = 'Value';
pt(60).class     = 'scalar';
pt(60).nrows     = 1;
pt(60).ncols     = 1;
pt(60).subsource = 'SS_DOUBLE';
pt(60).ndims     = '2';
pt(60).size      = '[]';
pt(60).isStruct  = false;
pt(60).symbol     = 'hil_tuning_P.Constant_Value_gd';
pt(60).baseaddr   = '&hil_tuning_P.Constant_Value_gd';
pt(60).dtname     = 'real_T';



  
pt(61).blockname = 'Right Rotation1/Look-Up Table1';
pt(61).paramname = 'BreakpointsForDimension1';
pt(61).class     = 'vector';
pt(61).nrows     = 1;
pt(61).ncols     = 40;
pt(61).subsource = 'SS_DOUBLE';
pt(61).ndims     = '2';
pt(61).size      = '[]';
pt(61).isStruct  = false;
pt(61).symbol     = 'hil_tuning_P.LookUpTable1_bp01Data_p';
pt(61).baseaddr   = '&hil_tuning_P.LookUpTable1_bp01Data_p[0]';
pt(61).dtname     = 'real_T';



  
pt(62).blockname = 'Subsystem1/Constant';
pt(62).paramname = 'Value';
pt(62).class     = 'scalar';
pt(62).nrows     = 1;
pt(62).ncols     = 1;
pt(62).subsource = 'SS_DOUBLE';
pt(62).ndims     = '2';
pt(62).size      = '[]';
pt(62).isStruct  = false;
pt(62).symbol     = 'hil_tuning_P.Constant_Value_b';
pt(62).baseaddr   = '&hil_tuning_P.Constant_Value_b';
pt(62).dtname     = 'real_T';



  
pt(63).blockname = 'Subsystem1/Gain';
pt(63).paramname = 'Gain';
pt(63).class     = 'scalar';
pt(63).nrows     = 1;
pt(63).ncols     = 1;
pt(63).subsource = 'SS_DOUBLE';
pt(63).ndims     = '2';
pt(63).size      = '[]';
pt(63).isStruct  = false;
pt(63).symbol     = 'hil_tuning_P.Gain_Gain';
pt(63).baseaddr   = '&hil_tuning_P.Gain_Gain';
pt(63).dtname     = 'real_T';



  
pt(64).blockname = 'Subsystem10/Constant';
pt(64).paramname = 'Value';
pt(64).class     = 'scalar';
pt(64).nrows     = 1;
pt(64).ncols     = 1;
pt(64).subsource = 'SS_DOUBLE';
pt(64).ndims     = '2';
pt(64).size      = '[]';
pt(64).isStruct  = false;
pt(64).symbol     = 'hil_tuning_P.Constant_Value_pf';
pt(64).baseaddr   = '&hil_tuning_P.Constant_Value_pf';
pt(64).dtname     = 'real_T';



  
pt(65).blockname = 'Subsystem10/Constant1';
pt(65).paramname = 'Value';
pt(65).class     = 'scalar';
pt(65).nrows     = 1;
pt(65).ncols     = 1;
pt(65).subsource = 'SS_DOUBLE';
pt(65).ndims     = '2';
pt(65).size      = '[]';
pt(65).isStruct  = false;
pt(65).symbol     = 'hil_tuning_P.Constant1_Value';
pt(65).baseaddr   = '&hil_tuning_P.Constant1_Value';
pt(65).dtname     = 'real_T';



  
pt(66).blockname = 'Subsystem10/Gain';
pt(66).paramname = 'Gain';
pt(66).class     = 'scalar';
pt(66).nrows     = 1;
pt(66).ncols     = 1;
pt(66).subsource = 'SS_DOUBLE';
pt(66).ndims     = '2';
pt(66).size      = '[]';
pt(66).isStruct  = false;
pt(66).symbol     = 'hil_tuning_P.Gain_Gain_f';
pt(66).baseaddr   = '&hil_tuning_P.Gain_Gain_f';
pt(66).dtname     = 'real_T';



  
pt(67).blockname = 'Subsystem11/Constant';
pt(67).paramname = 'Value';
pt(67).class     = 'scalar';
pt(67).nrows     = 1;
pt(67).ncols     = 1;
pt(67).subsource = 'SS_DOUBLE';
pt(67).ndims     = '2';
pt(67).size      = '[]';
pt(67).isStruct  = false;
pt(67).symbol     = 'hil_tuning_P.Constant_Value_i';
pt(67).baseaddr   = '&hil_tuning_P.Constant_Value_i';
pt(67).dtname     = 'real_T';



  
pt(68).blockname = 'Subsystem11/Gain';
pt(68).paramname = 'Gain';
pt(68).class     = 'scalar';
pt(68).nrows     = 1;
pt(68).ncols     = 1;
pt(68).subsource = 'SS_DOUBLE';
pt(68).ndims     = '2';
pt(68).size      = '[]';
pt(68).isStruct  = false;
pt(68).symbol     = 'hil_tuning_P.Gain_Gain_g';
pt(68).baseaddr   = '&hil_tuning_P.Gain_Gain_g';
pt(68).dtname     = 'real_T';



  
pt(69).blockname = 'Subsystem12/Constant';
pt(69).paramname = 'Value';
pt(69).class     = 'scalar';
pt(69).nrows     = 1;
pt(69).ncols     = 1;
pt(69).subsource = 'SS_DOUBLE';
pt(69).ndims     = '2';
pt(69).size      = '[]';
pt(69).isStruct  = false;
pt(69).symbol     = 'hil_tuning_P.Constant_Value_e';
pt(69).baseaddr   = '&hil_tuning_P.Constant_Value_e';
pt(69).dtname     = 'real_T';



  
pt(70).blockname = 'Subsystem12/Constant1';
pt(70).paramname = 'Value';
pt(70).class     = 'scalar';
pt(70).nrows     = 1;
pt(70).ncols     = 1;
pt(70).subsource = 'SS_DOUBLE';
pt(70).ndims     = '2';
pt(70).size      = '[]';
pt(70).isStruct  = false;
pt(70).symbol     = 'hil_tuning_P.Constant1_Value_e';
pt(70).baseaddr   = '&hil_tuning_P.Constant1_Value_e';
pt(70).dtname     = 'real_T';



  
pt(71).blockname = 'Subsystem12/Gain';
pt(71).paramname = 'Gain';
pt(71).class     = 'scalar';
pt(71).nrows     = 1;
pt(71).ncols     = 1;
pt(71).subsource = 'SS_DOUBLE';
pt(71).ndims     = '2';
pt(71).size      = '[]';
pt(71).isStruct  = false;
pt(71).symbol     = 'hil_tuning_P.Gain_Gain_k';
pt(71).baseaddr   = '&hil_tuning_P.Gain_Gain_k';
pt(71).dtname     = 'real_T';



  
pt(72).blockname = 'Subsystem2/Constant';
pt(72).paramname = 'Value';
pt(72).class     = 'scalar';
pt(72).nrows     = 1;
pt(72).ncols     = 1;
pt(72).subsource = 'SS_DOUBLE';
pt(72).ndims     = '2';
pt(72).size      = '[]';
pt(72).isStruct  = false;
pt(72).symbol     = 'hil_tuning_P.Constant_Value_iy';
pt(72).baseaddr   = '&hil_tuning_P.Constant_Value_iy';
pt(72).dtname     = 'real_T';



  
pt(73).blockname = 'Subsystem2/Gain';
pt(73).paramname = 'Gain';
pt(73).class     = 'scalar';
pt(73).nrows     = 1;
pt(73).ncols     = 1;
pt(73).subsource = 'SS_DOUBLE';
pt(73).ndims     = '2';
pt(73).size      = '[]';
pt(73).isStruct  = false;
pt(73).symbol     = 'hil_tuning_P.Gain_Gain_au';
pt(73).baseaddr   = '&hil_tuning_P.Gain_Gain_au';
pt(73).dtname     = 'real_T';



  
pt(74).blockname = 'Subsystem3/Constant';
pt(74).paramname = 'Value';
pt(74).class     = 'scalar';
pt(74).nrows     = 1;
pt(74).ncols     = 1;
pt(74).subsource = 'SS_DOUBLE';
pt(74).ndims     = '2';
pt(74).size      = '[]';
pt(74).isStruct  = false;
pt(74).symbol     = 'hil_tuning_P.Constant_Value_mw';
pt(74).baseaddr   = '&hil_tuning_P.Constant_Value_mw';
pt(74).dtname     = 'real_T';



  
pt(75).blockname = 'Subsystem3/Constant1';
pt(75).paramname = 'Value';
pt(75).class     = 'scalar';
pt(75).nrows     = 1;
pt(75).ncols     = 1;
pt(75).subsource = 'SS_DOUBLE';
pt(75).ndims     = '2';
pt(75).size      = '[]';
pt(75).isStruct  = false;
pt(75).symbol     = 'hil_tuning_P.Constant1_Value_a';
pt(75).baseaddr   = '&hil_tuning_P.Constant1_Value_a';
pt(75).dtname     = 'real_T';



  
pt(76).blockname = 'Subsystem3/Gain';
pt(76).paramname = 'Gain';
pt(76).class     = 'scalar';
pt(76).nrows     = 1;
pt(76).ncols     = 1;
pt(76).subsource = 'SS_DOUBLE';
pt(76).ndims     = '2';
pt(76).size      = '[]';
pt(76).isStruct  = false;
pt(76).symbol     = 'hil_tuning_P.Gain_Gain_jv';
pt(76).baseaddr   = '&hil_tuning_P.Gain_Gain_jv';
pt(76).dtname     = 'real_T';



  
pt(77).blockname = 'Subsystem4/Constant';
pt(77).paramname = 'Value';
pt(77).class     = 'scalar';
pt(77).nrows     = 1;
pt(77).ncols     = 1;
pt(77).subsource = 'SS_DOUBLE';
pt(77).ndims     = '2';
pt(77).size      = '[]';
pt(77).isStruct  = false;
pt(77).symbol     = 'hil_tuning_P.Constant_Value_pr';
pt(77).baseaddr   = '&hil_tuning_P.Constant_Value_pr';
pt(77).dtname     = 'real_T';



  
pt(78).blockname = 'Subsystem4/Constant1';
pt(78).paramname = 'Value';
pt(78).class     = 'scalar';
pt(78).nrows     = 1;
pt(78).ncols     = 1;
pt(78).subsource = 'SS_DOUBLE';
pt(78).ndims     = '2';
pt(78).size      = '[]';
pt(78).isStruct  = false;
pt(78).symbol     = 'hil_tuning_P.Constant1_Value_gr';
pt(78).baseaddr   = '&hil_tuning_P.Constant1_Value_gr';
pt(78).dtname     = 'real_T';



  
pt(79).blockname = 'Subsystem4/Gain';
pt(79).paramname = 'Gain';
pt(79).class     = 'scalar';
pt(79).nrows     = 1;
pt(79).ncols     = 1;
pt(79).subsource = 'SS_DOUBLE';
pt(79).ndims     = '2';
pt(79).size      = '[]';
pt(79).isStruct  = false;
pt(79).symbol     = 'hil_tuning_P.Gain_Gain_j0';
pt(79).baseaddr   = '&hil_tuning_P.Gain_Gain_j0';
pt(79).dtname     = 'real_T';



  
pt(80).blockname = 'Subsystem5/Constant';
pt(80).paramname = 'Value';
pt(80).class     = 'scalar';
pt(80).nrows     = 1;
pt(80).ncols     = 1;
pt(80).subsource = 'SS_DOUBLE';
pt(80).ndims     = '2';
pt(80).size      = '[]';
pt(80).isStruct  = false;
pt(80).symbol     = 'hil_tuning_P.Constant_Value_pk';
pt(80).baseaddr   = '&hil_tuning_P.Constant_Value_pk';
pt(80).dtname     = 'real_T';



  
pt(81).blockname = 'Subsystem5/Constant1';
pt(81).paramname = 'Value';
pt(81).class     = 'scalar';
pt(81).nrows     = 1;
pt(81).ncols     = 1;
pt(81).subsource = 'SS_DOUBLE';
pt(81).ndims     = '2';
pt(81).size      = '[]';
pt(81).isStruct  = false;
pt(81).symbol     = 'hil_tuning_P.Constant1_Value_g';
pt(81).baseaddr   = '&hil_tuning_P.Constant1_Value_g';
pt(81).dtname     = 'real_T';



  
pt(82).blockname = 'Subsystem5/Gain';
pt(82).paramname = 'Gain';
pt(82).class     = 'scalar';
pt(82).nrows     = 1;
pt(82).ncols     = 1;
pt(82).subsource = 'SS_DOUBLE';
pt(82).ndims     = '2';
pt(82).size      = '[]';
pt(82).isStruct  = false;
pt(82).symbol     = 'hil_tuning_P.Gain_Gain_kd';
pt(82).baseaddr   = '&hil_tuning_P.Gain_Gain_kd';
pt(82).dtname     = 'real_T';



  
pt(83).blockname = 'Subsystem6/Constant';
pt(83).paramname = 'Value';
pt(83).class     = 'scalar';
pt(83).nrows     = 1;
pt(83).ncols     = 1;
pt(83).subsource = 'SS_DOUBLE';
pt(83).ndims     = '2';
pt(83).size      = '[]';
pt(83).isStruct  = false;
pt(83).symbol     = 'hil_tuning_P.Constant_Value_gdr';
pt(83).baseaddr   = '&hil_tuning_P.Constant_Value_gdr';
pt(83).dtname     = 'real_T';



  
pt(84).blockname = 'Subsystem6/Gain';
pt(84).paramname = 'Gain';
pt(84).class     = 'scalar';
pt(84).nrows     = 1;
pt(84).ncols     = 1;
pt(84).subsource = 'SS_DOUBLE';
pt(84).ndims     = '2';
pt(84).size      = '[]';
pt(84).isStruct  = false;
pt(84).symbol     = 'hil_tuning_P.Gain_Gain_n';
pt(84).baseaddr   = '&hil_tuning_P.Gain_Gain_n';
pt(84).dtname     = 'real_T';



  
pt(85).blockname = 'Subsystem7/Constant';
pt(85).paramname = 'Value';
pt(85).class     = 'scalar';
pt(85).nrows     = 1;
pt(85).ncols     = 1;
pt(85).subsource = 'SS_DOUBLE';
pt(85).ndims     = '2';
pt(85).size      = '[]';
pt(85).isStruct  = false;
pt(85).symbol     = 'hil_tuning_P.Constant_Value_d';
pt(85).baseaddr   = '&hil_tuning_P.Constant_Value_d';
pt(85).dtname     = 'real_T';



  
pt(86).blockname = 'Subsystem7/Gain';
pt(86).paramname = 'Gain';
pt(86).class     = 'scalar';
pt(86).nrows     = 1;
pt(86).ncols     = 1;
pt(86).subsource = 'SS_DOUBLE';
pt(86).ndims     = '2';
pt(86).size      = '[]';
pt(86).isStruct  = false;
pt(86).symbol     = 'hil_tuning_P.Gain_Gain_d';
pt(86).baseaddr   = '&hil_tuning_P.Gain_Gain_d';
pt(86).dtname     = 'real_T';



  
pt(87).blockname = 'Subsystem8/Constant';
pt(87).paramname = 'Value';
pt(87).class     = 'scalar';
pt(87).nrows     = 1;
pt(87).ncols     = 1;
pt(87).subsource = 'SS_DOUBLE';
pt(87).ndims     = '2';
pt(87).size      = '[]';
pt(87).isStruct  = false;
pt(87).symbol     = 'hil_tuning_P.Constant_Value_ij';
pt(87).baseaddr   = '&hil_tuning_P.Constant_Value_ij';
pt(87).dtname     = 'real_T';



  
pt(88).blockname = 'Subsystem8/Gain';
pt(88).paramname = 'Gain';
pt(88).class     = 'scalar';
pt(88).nrows     = 1;
pt(88).ncols     = 1;
pt(88).subsource = 'SS_DOUBLE';
pt(88).ndims     = '2';
pt(88).size      = '[]';
pt(88).isStruct  = false;
pt(88).symbol     = 'hil_tuning_P.Gain_Gain_a';
pt(88).baseaddr   = '&hil_tuning_P.Gain_Gain_a';
pt(88).dtname     = 'real_T';



  
pt(89).blockname = 'Subsystem9/Constant';
pt(89).paramname = 'Value';
pt(89).class     = 'scalar';
pt(89).nrows     = 1;
pt(89).ncols     = 1;
pt(89).subsource = 'SS_DOUBLE';
pt(89).ndims     = '2';
pt(89).size      = '[]';
pt(89).isStruct  = false;
pt(89).symbol     = 'hil_tuning_P.Constant_Value_l';
pt(89).baseaddr   = '&hil_tuning_P.Constant_Value_l';
pt(89).dtname     = 'real_T';



  
pt(90).blockname = 'Subsystem9/Constant1';
pt(90).paramname = 'Value';
pt(90).class     = 'scalar';
pt(90).nrows     = 1;
pt(90).ncols     = 1;
pt(90).subsource = 'SS_DOUBLE';
pt(90).ndims     = '2';
pt(90).size      = '[]';
pt(90).isStruct  = false;
pt(90).symbol     = 'hil_tuning_P.Constant1_Value_k';
pt(90).baseaddr   = '&hil_tuning_P.Constant1_Value_k';
pt(90).dtname     = 'real_T';



  
pt(91).blockname = 'Subsystem9/Gain';
pt(91).paramname = 'Gain';
pt(91).class     = 'scalar';
pt(91).nrows     = 1;
pt(91).ncols     = 1;
pt(91).subsource = 'SS_DOUBLE';
pt(91).ndims     = '2';
pt(91).size      = '[]';
pt(91).isStruct  = false;
pt(91).symbol     = 'hil_tuning_P.Gain_Gain_j';
pt(91).baseaddr   = '&hil_tuning_P.Gain_Gain_j';
pt(91).dtname     = 'real_T';



  
pt(92).blockname = '';
pt(92).paramname = 'left_abduction';
pt(92).class     = 'vector';
pt(92).nrows     = 1;
pt(92).ncols     = 40;
pt(92).subsource = 'SS_DOUBLE';
pt(92).ndims     = '2';
pt(92).size      = '[]';
pt(92).isStruct  = false;
pt(92).symbol     = 'hil_tuning_P.left_abduction';
pt(92).baseaddr   = '&hil_tuning_P.left_abduction[0]';
pt(92).dtname     = 'real_T';



  
pt(93).blockname = '';
pt(93).paramname = 'left_ankle';
pt(93).class     = 'vector';
pt(93).nrows     = 1;
pt(93).ncols     = 40;
pt(93).subsource = 'SS_DOUBLE';
pt(93).ndims     = '2';
pt(93).size      = '[]';
pt(93).isStruct  = false;
pt(93).symbol     = 'hil_tuning_P.left_ankle';
pt(93).baseaddr   = '&hil_tuning_P.left_ankle[0]';
pt(93).dtname     = 'real_T';



  
pt(94).blockname = '';
pt(94).paramname = 'left_hip';
pt(94).class     = 'vector';
pt(94).nrows     = 1;
pt(94).ncols     = 40;
pt(94).subsource = 'SS_DOUBLE';
pt(94).ndims     = '2';
pt(94).size      = '[]';
pt(94).isStruct  = false;
pt(94).symbol     = 'hil_tuning_P.left_hip';
pt(94).baseaddr   = '&hil_tuning_P.left_hip[0]';
pt(94).dtname     = 'real_T';



  
pt(95).blockname = '';
pt(95).paramname = 'left_knee';
pt(95).class     = 'vector';
pt(95).nrows     = 1;
pt(95).ncols     = 40;
pt(95).subsource = 'SS_DOUBLE';
pt(95).ndims     = '2';
pt(95).size      = '[]';
pt(95).isStruct  = false;
pt(95).symbol     = 'hil_tuning_P.left_knee';
pt(95).baseaddr   = '&hil_tuning_P.left_knee[0]';
pt(95).dtname     = 'real_T';



  
pt(96).blockname = '';
pt(96).paramname = 'left_knee_twist';
pt(96).class     = 'vector';
pt(96).nrows     = 1;
pt(96).ncols     = 40;
pt(96).subsource = 'SS_DOUBLE';
pt(96).ndims     = '2';
pt(96).size      = '[]';
pt(96).isStruct  = false;
pt(96).symbol     = 'hil_tuning_P.left_knee_twist';
pt(96).baseaddr   = '&hil_tuning_P.left_knee_twist[0]';
pt(96).dtname     = 'real_T';



  
pt(97).blockname = '';
pt(97).paramname = 'left_rotation';
pt(97).class     = 'vector';
pt(97).nrows     = 1;
pt(97).ncols     = 40;
pt(97).subsource = 'SS_DOUBLE';
pt(97).ndims     = '2';
pt(97).size      = '[]';
pt(97).isStruct  = false;
pt(97).symbol     = 'hil_tuning_P.left_rotation';
pt(97).baseaddr   = '&hil_tuning_P.left_rotation[0]';
pt(97).dtname     = 'real_T';



  
pt(98).blockname = '';
pt(98).paramname = 'right_abduction';
pt(98).class     = 'vector';
pt(98).nrows     = 1;
pt(98).ncols     = 40;
pt(98).subsource = 'SS_DOUBLE';
pt(98).ndims     = '2';
pt(98).size      = '[]';
pt(98).isStruct  = false;
pt(98).symbol     = 'hil_tuning_P.right_abduction';
pt(98).baseaddr   = '&hil_tuning_P.right_abduction[0]';
pt(98).dtname     = 'real_T';



  
pt(99).blockname = '';
pt(99).paramname = 'right_ankle';
pt(99).class     = 'vector';
pt(99).nrows     = 1;
pt(99).ncols     = 40;
pt(99).subsource = 'SS_DOUBLE';
pt(99).ndims     = '2';
pt(99).size      = '[]';
pt(99).isStruct  = false;
pt(99).symbol     = 'hil_tuning_P.right_ankle';
pt(99).baseaddr   = '&hil_tuning_P.right_ankle[0]';
pt(99).dtname     = 'real_T';



  
pt(100).blockname = '';
pt(100).paramname = 'right_hip';
pt(100).class     = 'vector';
pt(100).nrows     = 1;
pt(100).ncols     = 40;
pt(100).subsource = 'SS_DOUBLE';
pt(100).ndims     = '2';
pt(100).size      = '[]';
pt(100).isStruct  = false;
pt(100).symbol     = 'hil_tuning_P.right_hip';
pt(100).baseaddr   = '&hil_tuning_P.right_hip[0]';
pt(100).dtname     = 'real_T';



  
pt(101).blockname = '';
pt(101).paramname = 'right_knee';
pt(101).class     = 'vector';
pt(101).nrows     = 1;
pt(101).ncols     = 40;
pt(101).subsource = 'SS_DOUBLE';
pt(101).ndims     = '2';
pt(101).size      = '[]';
pt(101).isStruct  = false;
pt(101).symbol     = 'hil_tuning_P.right_knee';
pt(101).baseaddr   = '&hil_tuning_P.right_knee[0]';
pt(101).dtname     = 'real_T';



  
pt(102).blockname = '';
pt(102).paramname = 'right_knee_twist';
pt(102).class     = 'vector';
pt(102).nrows     = 1;
pt(102).ncols     = 40;
pt(102).subsource = 'SS_DOUBLE';
pt(102).ndims     = '2';
pt(102).size      = '[]';
pt(102).isStruct  = false;
pt(102).symbol     = 'hil_tuning_P.right_knee_twist';
pt(102).baseaddr   = '&hil_tuning_P.right_knee_twist[0]';
pt(102).dtname     = 'real_T';



  
pt(103).blockname = '';
pt(103).paramname = 'right_rotation';
pt(103).class     = 'vector';
pt(103).nrows     = 1;
pt(103).ncols     = 40;
pt(103).subsource = 'SS_DOUBLE';
pt(103).ndims     = '2';
pt(103).size      = '[]';
pt(103).isStruct  = false;
pt(103).symbol     = 'hil_tuning_P.right_rotation';
pt(103).baseaddr   = '&hil_tuning_P.right_rotation[0]';
pt(103).dtname     = 'real_T';


function len = getlenPT
len = 103;

