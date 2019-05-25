function xcp = Copy_of_Robot_leg_3_0xcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'Copy_of_Robot_leg_3_0';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.001;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_b';
    
xcp.signals(2).symbol =  'Copy_of_Robot_leg_3_0_B.Constant3';
    
xcp.signals(3).symbol =  'Copy_of_Robot_leg_3_0_B.PulseGenerator';
    
xcp.signals(4).symbol =  'Copy_of_Robot_leg_3_0_B.ASCIIEncode2';
    
xcp.signals(5).symbol =  'Copy_of_Robot_leg_3_0_B.Add';
    
xcp.signals(6).symbol =  'Copy_of_Robot_leg_3_0_B.TransportDelay';
    
xcp.signals(7).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN';
    
xcp.signals(8).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_lc';
    
xcp.signals(9).symbol =  'Copy_of_Robot_leg_3_0_B.Output_k';
    
xcp.signals(10).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_hv';
    
xcp.signals(11).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_b';
    
xcp.signals(12).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_er';
    
xcp.signals(13).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_b5';
    
xcp.signals(14).symbol =  'Copy_of_Robot_leg_3_0_B.Output_h2';
    
xcp.signals(15).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_l4';
    
xcp.signals(16).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_bl';
    
xcp.signals(17).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_eb';
    
xcp.signals(18).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_i';
    
xcp.signals(19).symbol =  'Copy_of_Robot_leg_3_0_B.Output_dc';
    
xcp.signals(20).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_pq';
    
xcp.signals(21).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_gl';
    
xcp.signals(22).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_o';
    
xcp.signals(23).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_d';
    
xcp.signals(24).symbol =  'Copy_of_Robot_leg_3_0_B.Output_n';
    
xcp.signals(25).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_pv';
    
xcp.signals(26).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_hx';
    
xcp.signals(27).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_d';
    
xcp.signals(28).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_h';
    
xcp.signals(29).symbol =  'Copy_of_Robot_leg_3_0_B.Output_i';
    
xcp.signals(30).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_m';
    
xcp.signals(31).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_cx';
    
xcp.signals(32).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_m';
    
xcp.signals(33).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_hr';
    
xcp.signals(34).symbol =  'Copy_of_Robot_leg_3_0_B.Output_e';
    
xcp.signals(35).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_du';
    
xcp.signals(36).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_l4';
    
xcp.signals(37).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_j';
    
xcp.signals(38).symbol =  'Copy_of_Robot_leg_3_0_B.Gain';
    
xcp.signals(39).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1';
    
xcp.signals(40).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2';
    
xcp.signals(41).symbol =  'Copy_of_Robot_leg_3_0_B.Gain3';
    
xcp.signals(42).symbol =  'Copy_of_Robot_leg_3_0_B.Gain4';
    
xcp.signals(43).symbol =  'Copy_of_Robot_leg_3_0_B.Gain5';
    
xcp.signals(44).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_f';
    
xcp.signals(45).symbol =  'Copy_of_Robot_leg_3_0_B.Output_b';
    
xcp.signals(46).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_b';
    
xcp.signals(47).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_j';
    
xcp.signals(48).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_a5';
    
xcp.signals(49).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_lw';
    
xcp.signals(50).symbol =  'Copy_of_Robot_leg_3_0_B.Output_nc';
    
xcp.signals(51).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_i';
    
xcp.signals(52).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_ar';
    
xcp.signals(53).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_n';
    
xcp.signals(54).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_ly';
    
xcp.signals(55).symbol =  'Copy_of_Robot_leg_3_0_B.Output_f3';
    
xcp.signals(56).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_iy';
    
xcp.signals(57).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_f';
    
xcp.signals(58).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_me';
    
xcp.signals(59).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_ao';
    
xcp.signals(60).symbol =  'Copy_of_Robot_leg_3_0_B.Output_kh';
    
xcp.signals(61).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_ba';
    
xcp.signals(62).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_k';
    
xcp.signals(63).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_ebu';
    
xcp.signals(64).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_c';
    
xcp.signals(65).symbol =  'Copy_of_Robot_leg_3_0_B.Output_fc';
    
xcp.signals(66).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_cs';
    
xcp.signals(67).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_m0';
    
xcp.signals(68).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_ez';
    
xcp.signals(69).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_o';
    
xcp.signals(70).symbol =  'Copy_of_Robot_leg_3_0_B.Output_l';
    
xcp.signals(71).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_mf';
    
xcp.signals(72).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_lq';
    
xcp.signals(73).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_b';
    
xcp.signals(74).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_e';
    
xcp.signals(75).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_g';
    
xcp.signals(76).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_f';
    
xcp.signals(77).symbol =  'Copy_of_Robot_leg_3_0_B.Gain3_a';
    
xcp.signals(78).symbol =  'Copy_of_Robot_leg_3_0_B.Gain4_o';
    
xcp.signals(79).symbol =  'Copy_of_Robot_leg_3_0_B.Gain5_n';
    
xcp.signals(80).symbol =  'Copy_of_Robot_leg_3_0_B.Add1';
    
xcp.signals(81).symbol =  'Copy_of_Robot_leg_3_0_B.Add2';
    
xcp.signals(82).symbol =  'Copy_of_Robot_leg_3_0_B.Add3';
    
xcp.signals(83).symbol =  'Copy_of_Robot_leg_3_0_B.Add4';
    
xcp.signals(84).symbol =  'Copy_of_Robot_leg_3_0_B.Add5';
    
xcp.signals(85).symbol =  'Copy_of_Robot_leg_3_0_B.Add6';
    
xcp.signals(86).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_e';
    
xcp.signals(87).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_o';
    
xcp.signals(88).symbol =  'Copy_of_Robot_leg_3_0_B.Add_g';
    
xcp.signals(89).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_p5';
    
xcp.signals(90).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_jh';
    
xcp.signals(91).symbol =  'Copy_of_Robot_leg_3_0_B.Add_l';
    
xcp.signals(92).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_g';
    
xcp.signals(93).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_h';
    
xcp.signals(94).symbol =  'Copy_of_Robot_leg_3_0_B.Add_j';
    
xcp.signals(95).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_c';
    
xcp.signals(96).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_k';
    
xcp.signals(97).symbol =  'Copy_of_Robot_leg_3_0_B.Add_n';
    
xcp.signals(98).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_dj';
    
xcp.signals(99).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_fj';
    
xcp.signals(100).symbol =  'Copy_of_Robot_leg_3_0_B.Add_i5';
    
xcp.signals(101).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_a4';
    
xcp.signals(102).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_i3';
    
xcp.signals(103).symbol =  'Copy_of_Robot_leg_3_0_B.Add_by';
    
xcp.signals(104).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_ec';
    
xcp.signals(105).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_b';
    
xcp.signals(106).symbol =  'Copy_of_Robot_leg_3_0_B.Add_aa';
    
xcp.signals(107).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_aq';
    
xcp.signals(108).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_gp';
    
xcp.signals(109).symbol =  'Copy_of_Robot_leg_3_0_B.Add_i';
    
xcp.signals(110).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_k';
    
xcp.signals(111).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_i';
    
xcp.signals(112).symbol =  'Copy_of_Robot_leg_3_0_B.Add_jr';
    
xcp.signals(113).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_d';
    
xcp.signals(114).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_gb';
    
xcp.signals(115).symbol =  'Copy_of_Robot_leg_3_0_B.Add_jp';
    
xcp.signals(116).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_j';
    
xcp.signals(117).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_jw';
    
xcp.signals(118).symbol =  'Copy_of_Robot_leg_3_0_B.Add_a';
    
xcp.signals(119).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_f';
    
xcp.signals(120).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_js';
    
xcp.signals(121).symbol =  'Copy_of_Robot_leg_3_0_B.Add_b';
    
xcp.signals(122).symbol =  'Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem.In1';
    
xcp.signals(123).symbol =  'Copy_of_Robot_leg_3_0_B.SwitchCaseActionSubsystem1.In1';
    
xcp.signals(124).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_10_1_1';
    
xcp.signals(125).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_10_1_2';
    
xcp.signals(126).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_10_1_3';
    
xcp.signals(127).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_11_1_1';
    
xcp.signals(128).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_11_1_2';
    
xcp.signals(129).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_11_1_3';
    
xcp.signals(130).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_12_1_1';
    
xcp.signals(131).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_12_1_2';
    
xcp.signals(132).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_12_1_3';
    
xcp.signals(133).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_13_1_1';
    
xcp.signals(134).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_13_1_2';
    
xcp.signals(135).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_13_1_3';
    
xcp.signals(136).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_14_1_1';
    
xcp.signals(137).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_14_1_2';
    
xcp.signals(138).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_14_1_3';
    
xcp.signals(139).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_15_1_1';
    
xcp.signals(140).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_15_1_2';
    
xcp.signals(141).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_15_1_3';
    
xcp.signals(142).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_16_1_1';
    
xcp.signals(143).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_16_1_2';
    
xcp.signals(144).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_16_1_3';
    
xcp.signals(145).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_17_1_1';
    
xcp.signals(146).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_17_1_2';
    
xcp.signals(147).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_17_1_3';
    
xcp.signals(148).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_18_1_1';
    
xcp.signals(149).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_18_1_2';
    
xcp.signals(150).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_18_1_3';
    
xcp.signals(151).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_19_1_1';
    
xcp.signals(152).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_19_1_2';
    
xcp.signals(153).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_19_1_3';
    
xcp.signals(154).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_1_1_1';
    
xcp.signals(155).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_20_1_1';
    
xcp.signals(156).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_20_1_2';
    
xcp.signals(157).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_20_1_3';
    
xcp.signals(158).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_21_1_1';
    
xcp.signals(159).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_21_1_2';
    
xcp.signals(160).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_21_1_3';
    
xcp.signals(161).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_22_1_1';
    
xcp.signals(162).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_22_1_2';
    
xcp.signals(163).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_22_1_3';
    
xcp.signals(164).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_23_1_1';
    
xcp.signals(165).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_24_1_1';
    
xcp.signals(166).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_25_1_1';
    
xcp.signals(167).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_26_1_1';
    
xcp.signals(168).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_27_1_1';
    
xcp.signals(169).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_28_1_1';
    
xcp.signals(170).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_29_1_1';
    
xcp.signals(171).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_29_1_2';
    
xcp.signals(172).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_29_1_3';
    
xcp.signals(173).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_2_1_1';
    
xcp.signals(174).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_30_1_1';
    
xcp.signals(175).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_30_1_2';
    
xcp.signals(176).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_30_1_3';
    
xcp.signals(177).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_31_1_1';
    
xcp.signals(178).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_31_1_2';
    
xcp.signals(179).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_31_1_3';
    
xcp.signals(180).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_32_1_1';
    
xcp.signals(181).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_32_1_2';
    
xcp.signals(182).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_32_1_3';
    
xcp.signals(183).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_33_1_1';
    
xcp.signals(184).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_33_1_2';
    
xcp.signals(185).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_33_1_3';
    
xcp.signals(186).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_34_1_1';
    
xcp.signals(187).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_34_1_2';
    
xcp.signals(188).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_34_1_3';
    
xcp.signals(189).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_35_1_1';
    
xcp.signals(190).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_35_1_2';
    
xcp.signals(191).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_35_1_3';
    
xcp.signals(192).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_36_1_1';
    
xcp.signals(193).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_36_1_2';
    
xcp.signals(194).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_36_1_3';
    
xcp.signals(195).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_37_1_1';
    
xcp.signals(196).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_37_1_2';
    
xcp.signals(197).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_37_1_3';
    
xcp.signals(198).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_38_1_1';
    
xcp.signals(199).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_38_1_2';
    
xcp.signals(200).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_38_1_3';
    
xcp.signals(201).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_39_1_1';
    
xcp.signals(202).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_39_1_2';
    
xcp.signals(203).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_39_1_3';
    
xcp.signals(204).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_3_1_1';
    
xcp.signals(205).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_40_1_1';
    
xcp.signals(206).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_40_1_2';
    
xcp.signals(207).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_40_1_3';
    
xcp.signals(208).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_41_1_1';
    
xcp.signals(209).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_41_1_2';
    
xcp.signals(210).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_41_1_3';
    
xcp.signals(211).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_42_1_1';
    
xcp.signals(212).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_42_1_2';
    
xcp.signals(213).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_42_1_3';
    
xcp.signals(214).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_43_1_1';
    
xcp.signals(215).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_43_1_2';
    
xcp.signals(216).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_43_1_3';
    
xcp.signals(217).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_44_1_1';
    
xcp.signals(218).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_44_1_2';
    
xcp.signals(219).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_44_1_3';
    
xcp.signals(220).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_4_1_1';
    
xcp.signals(221).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_5_1_1';
    
xcp.signals(222).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_6_1_1';
    
xcp.signals(223).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_7_1_1';
    
xcp.signals(224).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_7_1_2';
    
xcp.signals(225).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_7_1_3';
    
xcp.signals(226).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_8_1_1';
    
xcp.signals(227).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_8_1_2';
    
xcp.signals(228).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_8_1_3';
    
xcp.signals(229).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_9_1_1';
    
xcp.signals(230).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_9_1_2';
    
xcp.signals(231).symbol =  'Copy_of_Robot_leg_3_0_B.INPUT_9_1_3';
    
xcp.signals(232).symbol =  'Copy_of_Robot_leg_3_0_B.OUTPUT_1_0';
    
xcp.signals(233).symbol =  'Copy_of_Robot_leg_3_0_B.OUTPUT_1_1';
    
xcp.signals(234).symbol =  'Copy_of_Robot_leg_3_0_B.STATE_1';
    
xcp.signals(235).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_i';
    
xcp.signals(236).symbol =  'Copy_of_Robot_leg_3_0_B.NormalForce_i';
    
xcp.signals(237).symbol =  'Copy_of_Robot_leg_3_0_B.Add1_i';
    
xcp.signals(238).symbol =  'Copy_of_Robot_leg_3_0_B.SumofElements_l';
    
xcp.signals(239).symbol =  'Copy_of_Robot_leg_3_0_B.FrictionForce_k';
    
xcp.signals(240).symbol =  'Copy_of_Robot_leg_3_0_B.FSph';
    
xcp.signals(241).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_m';
    
xcp.signals(242).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_l';
    
xcp.signals(243).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a';
    
xcp.signals(244).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_l';
    
xcp.signals(245).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_g';
    
xcp.signals(246).symbol =  'Copy_of_Robot_leg_3_0_B.NormalForce';
    
xcp.signals(247).symbol =  'Copy_of_Robot_leg_3_0_B.Add1_f';
    
xcp.signals(248).symbol =  'Copy_of_Robot_leg_3_0_B.SumofElements';
    
xcp.signals(249).symbol =  'Copy_of_Robot_leg_3_0_B.FrictionForce';
    
xcp.signals(250).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_i';
    
xcp.signals(251).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_mf';
    
xcp.signals(252).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a0';
    
xcp.signals(253).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_n';
    
xcp.signals(254).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_eu';
    
xcp.signals(255).symbol =  'Copy_of_Robot_leg_3_0_B.Output_j';
    
xcp.signals(256).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_j';
    
xcp.signals(257).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_d';
    
xcp.signals(258).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_a';
    
xcp.signals(259).symbol =  'Copy_of_Robot_leg_3_0_B.Clock';
    
xcp.signals(260).symbol =  'Copy_of_Robot_leg_3_0_B.Output';
    
xcp.signals(261).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1';
    
xcp.signals(262).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction';
    
xcp.signals(263).symbol =  'Copy_of_Robot_leg_3_0_B.Sum';
    
xcp.signals(264).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_n0';
    
xcp.signals(265).symbol =  'Copy_of_Robot_leg_3_0_B.Output_o';
    
xcp.signals(266).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_jm';
    
xcp.signals(267).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_dn';
    
xcp.signals(268).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_f';
    
xcp.signals(269).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_n';
    
xcp.signals(270).symbol =  'Copy_of_Robot_leg_3_0_B.Output_f';
    
xcp.signals(271).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_p';
    
xcp.signals(272).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_p';
    
xcp.signals(273).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_i';
    
xcp.signals(274).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_e';
    
xcp.signals(275).symbol =  'Copy_of_Robot_leg_3_0_B.Output_d';
    
xcp.signals(276).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_h';
    
xcp.signals(277).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_m';
    
xcp.signals(278).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_c';
    
xcp.signals(279).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_euk';
    
xcp.signals(280).symbol =  'Copy_of_Robot_leg_3_0_B.Output_jd';
    
xcp.signals(281).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_e';
    
xcp.signals(282).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_a';
    
xcp.signals(283).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_fb';
    
xcp.signals(284).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_ny';
    
xcp.signals(285).symbol =  'Copy_of_Robot_leg_3_0_B.Output_h';
    
xcp.signals(286).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_d';
    
xcp.signals(287).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_dy';
    
xcp.signals(288).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_e';
    
xcp.signals(289).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_ev';
    
xcp.signals(290).symbol =  'Copy_of_Robot_leg_3_0_B.Output_hw';
    
xcp.signals(291).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_hj';
    
xcp.signals(292).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_pp';
    
xcp.signals(293).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_cc';
    
xcp.signals(294).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_p';
    
xcp.signals(295).symbol =  'Copy_of_Robot_leg_3_0_B.Output_p';
    
xcp.signals(296).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_dv';
    
xcp.signals(297).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_h';
    
xcp.signals(298).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_k';
    
xcp.signals(299).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_bo';
    
xcp.signals(300).symbol =  'Copy_of_Robot_leg_3_0_B.Output_fa';
    
xcp.signals(301).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_c';
    
xcp.signals(302).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_c';
    
xcp.signals(303).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_l';
    
xcp.signals(304).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_l';
    
xcp.signals(305).symbol =  'Copy_of_Robot_leg_3_0_B.Output_g';
    
xcp.signals(306).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_k';
    
xcp.signals(307).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_l';
    
xcp.signals(308).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_ff';
    
xcp.signals(309).symbol =  'Copy_of_Robot_leg_3_0_B.Clock_a';
    
xcp.signals(310).symbol =  'Copy_of_Robot_leg_3_0_B.Output_ds';
    
xcp.signals(311).symbol =  'Copy_of_Robot_leg_3_0_B.LookUpTable1_l';
    
xcp.signals(312).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_h5';
    
xcp.signals(313).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_p';
    
xcp.signals(314).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_f';
    
xcp.signals(315).symbol =  'Copy_of_Robot_leg_3_0_B.Abs1_k';
    
xcp.signals(316).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_a';
    
xcp.signals(317).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_p1';
    
xcp.signals(318).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_b';
    
xcp.signals(319).symbol =  'Copy_of_Robot_leg_3_0_B.LogicalOperator_n';
    
xcp.signals(320).symbol =  'Copy_of_Robot_leg_3_0_B.Product_d';
    
xcp.signals(321).symbol =  'Copy_of_Robot_leg_3_0_B.FSph';
    
xcp.signals(322).symbol =  'Copy_of_Robot_leg_3_0_B.SprForce_ny';
    
xcp.signals(323).symbol =  'Copy_of_Robot_leg_3_0_B.DampForce_b';
    
xcp.signals(324).symbol =  'Copy_of_Robot_leg_3_0_B.FSph';
    
xcp.signals(325).symbol =  'Copy_of_Robot_leg_3_0_B.FPla_j';
    
xcp.signals(326).symbol =  'Copy_of_Robot_leg_3_0_B.FSph';
    
xcp.signals(327).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_k';
    
xcp.signals(328).symbol =  'Copy_of_Robot_leg_3_0_B.Abs1_o2';
    
xcp.signals(329).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_p';
    
xcp.signals(330).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_m';
    
xcp.signals(331).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_n';
    
xcp.signals(332).symbol =  'Copy_of_Robot_leg_3_0_B.LogicalOperator_k';
    
xcp.signals(333).symbol =  'Copy_of_Robot_leg_3_0_B.Product_m';
    
xcp.signals(334).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_m';
    
xcp.signals(335).symbol =  'Copy_of_Robot_leg_3_0_B.SprForce_a';
    
xcp.signals(336).symbol =  'Copy_of_Robot_leg_3_0_B.DampForce_hs';
    
xcp.signals(337).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_m';
    
xcp.signals(338).symbol =  'Copy_of_Robot_leg_3_0_B.FPla_p';
    
xcp.signals(339).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_m';
    
xcp.signals(340).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_n';
    
xcp.signals(341).symbol =  'Copy_of_Robot_leg_3_0_B.Abs1_n';
    
xcp.signals(342).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_b';
    
xcp.signals(343).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_g';
    
xcp.signals(344).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_gi';
    
xcp.signals(345).symbol =  'Copy_of_Robot_leg_3_0_B.LogicalOperator_aj';
    
xcp.signals(346).symbol =  'Copy_of_Robot_leg_3_0_B.Product_e';
    
xcp.signals(347).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_l';
    
xcp.signals(348).symbol =  'Copy_of_Robot_leg_3_0_B.SprForce_e';
    
xcp.signals(349).symbol =  'Copy_of_Robot_leg_3_0_B.DampForce_f';
    
xcp.signals(350).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_l';
    
xcp.signals(351).symbol =  'Copy_of_Robot_leg_3_0_B.FPla_n';
    
xcp.signals(352).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_l';
    
xcp.signals(353).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_ff';
    
xcp.signals(354).symbol =  'Copy_of_Robot_leg_3_0_B.Abs1_b';
    
xcp.signals(355).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_bu';
    
xcp.signals(356).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_m5';
    
xcp.signals(357).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_c';
    
xcp.signals(358).symbol =  'Copy_of_Robot_leg_3_0_B.LogicalOperator_nt';
    
xcp.signals(359).symbol =  'Copy_of_Robot_leg_3_0_B.Product_j';
    
xcp.signals(360).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a';
    
xcp.signals(361).symbol =  'Copy_of_Robot_leg_3_0_B.SprForce_m';
    
xcp.signals(362).symbol =  'Copy_of_Robot_leg_3_0_B.DampForce_n';
    
xcp.signals(363).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a';
    
xcp.signals(364).symbol =  'Copy_of_Robot_leg_3_0_B.FPla_d';
    
xcp.signals(365).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a';
    
xcp.signals(366).symbol =  'Copy_of_Robot_leg_3_0_B.Abs';
    
xcp.signals(367).symbol =  'Copy_of_Robot_leg_3_0_B.Abs1';
    
xcp.signals(368).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion';
    
xcp.signals(369).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_c';
    
xcp.signals(370).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_f';
    
xcp.signals(371).symbol =  'Copy_of_Robot_leg_3_0_B.LogicalOperator';
    
xcp.signals(372).symbol =  'Copy_of_Robot_leg_3_0_B.Product';
    
xcp.signals(373).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_i';
    
xcp.signals(374).symbol =  'Copy_of_Robot_leg_3_0_B.SprForce_p';
    
xcp.signals(375).symbol =  'Copy_of_Robot_leg_3_0_B.DampForce_h';
    
xcp.signals(376).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_i';
    
xcp.signals(377).symbol =  'Copy_of_Robot_leg_3_0_B.FPla_h';
    
xcp.signals(378).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_i';
    
xcp.signals(379).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_g';
    
xcp.signals(380).symbol =  'Copy_of_Robot_leg_3_0_B.Abs1_o';
    
xcp.signals(381).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_m';
    
xcp.signals(382).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_f';
    
xcp.signals(383).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_gt';
    
xcp.signals(384).symbol =  'Copy_of_Robot_leg_3_0_B.LogicalOperator_a';
    
xcp.signals(385).symbol =  'Copy_of_Robot_leg_3_0_B.Product_g';
    
xcp.signals(386).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_mf';
    
xcp.signals(387).symbol =  'Copy_of_Robot_leg_3_0_B.SprForce_n';
    
xcp.signals(388).symbol =  'Copy_of_Robot_leg_3_0_B.DampForce_c';
    
xcp.signals(389).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_mf';
    
xcp.signals(390).symbol =  'Copy_of_Robot_leg_3_0_B.FPla_a';
    
xcp.signals(391).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_mf';
    
xcp.signals(392).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_e';
    
xcp.signals(393).symbol =  'Copy_of_Robot_leg_3_0_B.Abs1_d';
    
xcp.signals(394).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_mc';
    
xcp.signals(395).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_j';
    
xcp.signals(396).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_j';
    
xcp.signals(397).symbol =  'Copy_of_Robot_leg_3_0_B.LogicalOperator_l';
    
xcp.signals(398).symbol =  'Copy_of_Robot_leg_3_0_B.Product_k';
    
xcp.signals(399).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a0';
    
xcp.signals(400).symbol =  'Copy_of_Robot_leg_3_0_B.SprForce_j';
    
xcp.signals(401).symbol =  'Copy_of_Robot_leg_3_0_B.DampForce_j';
    
xcp.signals(402).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a0';
    
xcp.signals(403).symbol =  'Copy_of_Robot_leg_3_0_B.FPla_o';
    
xcp.signals(404).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a0';
    
xcp.signals(405).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_d';
    
xcp.signals(406).symbol =  'Copy_of_Robot_leg_3_0_B.Abs1_l';
    
xcp.signals(407).symbol =  'Copy_of_Robot_leg_3_0_B.DataTypeConversion_l';
    
xcp.signals(408).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_p';
    
xcp.signals(409).symbol =  'Copy_of_Robot_leg_3_0_B.Gain1_o';
    
xcp.signals(410).symbol =  'Copy_of_Robot_leg_3_0_B.LogicalOperator_e';
    
xcp.signals(411).symbol =  'Copy_of_Robot_leg_3_0_B.Product_f';
    
xcp.signals(412).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_n';
    
xcp.signals(413).symbol =  'Copy_of_Robot_leg_3_0_B.SprForce';
    
xcp.signals(414).symbol =  'Copy_of_Robot_leg_3_0_B.DampForce';
    
xcp.signals(415).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_n';
    
xcp.signals(416).symbol =  'Copy_of_Robot_leg_3_0_B.FPla';
    
xcp.signals(417).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_n';
    
xcp.signals(418).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_m';
    
xcp.signals(419).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_b';
    
xcp.signals(420).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_dq';
    
xcp.signals(421).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_hq';
    
xcp.signals(422).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_eg';
    
xcp.signals(423).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_em';
    
xcp.signals(424).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_n1';
    
xcp.signals(425).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_k';
    
xcp.signals(426).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_ky';
    
xcp.signals(427).symbol =  'Copy_of_Robot_leg_3_0_B.DeadZone_ko';
    
xcp.signals(428).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_l';
    
xcp.signals(429).symbol =  'Copy_of_Robot_leg_3_0_B.Product_g0';
    
xcp.signals(430).symbol =  'Copy_of_Robot_leg_3_0_B.Signvx_ax';
    
xcp.signals(431).symbol =  'Copy_of_Robot_leg_3_0_B.Signx_l2';
    
xcp.signals(432).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_l4';
    
xcp.signals(433).symbol =  'Copy_of_Robot_leg_3_0_B.Product_mw';
    
xcp.signals(434).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_oq';
    
xcp.signals(435).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_f';
    
xcp.signals(436).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_ax';
    
xcp.signals(437).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_ab';
    
xcp.signals(438).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_gg';
    
xcp.signals(439).symbol =  'Copy_of_Robot_leg_3_0_B.FSph';
    
xcp.signals(440).symbol =  'Copy_of_Robot_leg_3_0_B.FSph';
    
xcp.signals(441).symbol =  'Copy_of_Robot_leg_3_0_B.FSph';
    
xcp.signals(442).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_hg';
    
xcp.signals(443).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_e';
    
xcp.signals(444).symbol =  'Copy_of_Robot_leg_3_0_B.FSph';
    
xcp.signals(445).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_bw';
    
xcp.signals(446).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_at';
    
xcp.signals(447).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_mo';
    
xcp.signals(448).symbol =  'Copy_of_Robot_leg_3_0_B.Product6_a';
    
xcp.signals(449).symbol =  'Copy_of_Robot_leg_3_0_B.Product7_c';
    
xcp.signals(450).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_lx';
    
xcp.signals(451).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_oc';
    
xcp.signals(452).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_em';
    
xcp.signals(453).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_g';
    
xcp.signals(454).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_bz';
    
xcp.signals(455).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_nc';
    
xcp.signals(456).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_j';
    
xcp.signals(457).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_kv';
    
xcp.signals(458).symbol =  'Copy_of_Robot_leg_3_0_B.DeadZone_l';
    
xcp.signals(459).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_fs';
    
xcp.signals(460).symbol =  'Copy_of_Robot_leg_3_0_B.Product_gr';
    
xcp.signals(461).symbol =  'Copy_of_Robot_leg_3_0_B.Signvx_p';
    
xcp.signals(462).symbol =  'Copy_of_Robot_leg_3_0_B.Signx_j';
    
xcp.signals(463).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_la';
    
xcp.signals(464).symbol =  'Copy_of_Robot_leg_3_0_B.Product_jf';
    
xcp.signals(465).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_l';
    
xcp.signals(466).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_jh';
    
xcp.signals(467).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_ep';
    
xcp.signals(468).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_o';
    
xcp.signals(469).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_np';
    
xcp.signals(470).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_m';
    
xcp.signals(471).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_m';
    
xcp.signals(472).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_m';
    
xcp.signals(473).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_d1';
    
xcp.signals(474).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_o4';
    
xcp.signals(475).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_m';
    
xcp.signals(476).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_ab';
    
xcp.signals(477).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_j';
    
xcp.signals(478).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_is';
    
xcp.signals(479).symbol =  'Copy_of_Robot_leg_3_0_B.Product6_b';
    
xcp.signals(480).symbol =  'Copy_of_Robot_leg_3_0_B.Product7_j';
    
xcp.signals(481).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_jh';
    
xcp.signals(482).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_n';
    
xcp.signals(483).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_fu';
    
xcp.signals(484).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_ib';
    
xcp.signals(485).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_aw';
    
xcp.signals(486).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_p';
    
xcp.signals(487).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_a';
    
xcp.signals(488).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_b';
    
xcp.signals(489).symbol =  'Copy_of_Robot_leg_3_0_B.DeadZone_k';
    
xcp.signals(490).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_b';
    
xcp.signals(491).symbol =  'Copy_of_Robot_leg_3_0_B.Product_if';
    
xcp.signals(492).symbol =  'Copy_of_Robot_leg_3_0_B.Signvx_h';
    
xcp.signals(493).symbol =  'Copy_of_Robot_leg_3_0_B.Signx_e';
    
xcp.signals(494).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_j4';
    
xcp.signals(495).symbol =  'Copy_of_Robot_leg_3_0_B.Product_fd';
    
xcp.signals(496).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_ij';
    
xcp.signals(497).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_e';
    
xcp.signals(498).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_ma';
    
xcp.signals(499).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_ae';
    
xcp.signals(500).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_jh';
    
xcp.signals(501).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_l';
    
xcp.signals(502).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_l';
    
xcp.signals(503).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_l';
    
xcp.signals(504).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_ib';
    
xcp.signals(505).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_m';
    
xcp.signals(506).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_l';
    
xcp.signals(507).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_kn';
    
xcp.signals(508).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_iys';
    
xcp.signals(509).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_jn';
    
xcp.signals(510).symbol =  'Copy_of_Robot_leg_3_0_B.Product6_c';
    
xcp.signals(511).symbol =  'Copy_of_Robot_leg_3_0_B.Product7_bi';
    
xcp.signals(512).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_iw';
    
xcp.signals(513).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_dl';
    
xcp.signals(514).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_ar';
    
xcp.signals(515).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_d';
    
xcp.signals(516).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_iz';
    
xcp.signals(517).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_aq';
    
xcp.signals(518).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_i';
    
xcp.signals(519).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_g4';
    
xcp.signals(520).symbol =  'Copy_of_Robot_leg_3_0_B.DeadZone_ap';
    
xcp.signals(521).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_e';
    
xcp.signals(522).symbol =  'Copy_of_Robot_leg_3_0_B.Product_gy';
    
xcp.signals(523).symbol =  'Copy_of_Robot_leg_3_0_B.Signvx_l';
    
xcp.signals(524).symbol =  'Copy_of_Robot_leg_3_0_B.Signx_lq';
    
xcp.signals(525).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_eb0';
    
xcp.signals(526).symbol =  'Copy_of_Robot_leg_3_0_B.Product_a4';
    
xcp.signals(527).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_hn';
    
xcp.signals(528).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_k';
    
xcp.signals(529).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_k';
    
xcp.signals(530).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_ku';
    
xcp.signals(531).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_ae';
    
xcp.signals(532).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a';
    
xcp.signals(533).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a';
    
xcp.signals(534).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a';
    
xcp.signals(535).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_eu';
    
xcp.signals(536).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_km';
    
xcp.signals(537).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a';
    
xcp.signals(538).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_dh';
    
xcp.signals(539).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_k5';
    
xcp.signals(540).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_a';
    
xcp.signals(541).symbol =  'Copy_of_Robot_leg_3_0_B.Product6_p';
    
xcp.signals(542).symbol =  'Copy_of_Robot_leg_3_0_B.Product7_f';
    
xcp.signals(543).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_h';
    
xcp.signals(544).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_d';
    
xcp.signals(545).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_d';
    
xcp.signals(546).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_ld';
    
xcp.signals(547).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_jg';
    
xcp.signals(548).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_hs';
    
xcp.signals(549).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_h';
    
xcp.signals(550).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_e';
    
xcp.signals(551).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_i';
    
xcp.signals(552).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_d';
    
xcp.signals(553).symbol =  'Copy_of_Robot_leg_3_0_B.GAIN_p';
    
xcp.signals(554).symbol =  'Copy_of_Robot_leg_3_0_B.Compare';
    
xcp.signals(555).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_n';
    
xcp.signals(556).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_a';
    
xcp.signals(557).symbol =  'Copy_of_Robot_leg_3_0_B.DeadZone_e';
    
xcp.signals(558).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_k';
    
xcp.signals(559).symbol =  'Copy_of_Robot_leg_3_0_B.Product_br';
    
xcp.signals(560).symbol =  'Copy_of_Robot_leg_3_0_B.Signvx_e';
    
xcp.signals(561).symbol =  'Copy_of_Robot_leg_3_0_B.Signx_h';
    
xcp.signals(562).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_p0';
    
xcp.signals(563).symbol =  'Copy_of_Robot_leg_3_0_B.Product_np';
    
xcp.signals(564).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_cpr';
    
xcp.signals(565).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_i';
    
xcp.signals(566).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_gk';
    
xcp.signals(567).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_p4';
    
xcp.signals(568).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_k';
    
xcp.signals(569).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_i';
    
xcp.signals(570).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_i';
    
xcp.signals(571).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_i';
    
xcp.signals(572).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_jd';
    
xcp.signals(573).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_oi';
    
xcp.signals(574).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_i';
    
xcp.signals(575).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_l1';
    
xcp.signals(576).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_a';
    
xcp.signals(577).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_ij';
    
xcp.signals(578).symbol =  'Copy_of_Robot_leg_3_0_B.Product6_l';
    
xcp.signals(579).symbol =  'Copy_of_Robot_leg_3_0_B.Product7_b';
    
xcp.signals(580).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_c';
    
xcp.signals(581).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_k';
    
xcp.signals(582).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_ii';
    
xcp.signals(583).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_j2';
    
xcp.signals(584).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_kge';
    
xcp.signals(585).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_o';
    
xcp.signals(586).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_m';
    
xcp.signals(587).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_db';
    
xcp.signals(588).symbol =  'Copy_of_Robot_leg_3_0_B.DeadZone_a';
    
xcp.signals(589).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_m';
    
xcp.signals(590).symbol =  'Copy_of_Robot_leg_3_0_B.Product_jh';
    
xcp.signals(591).symbol =  'Copy_of_Robot_leg_3_0_B.Signvx_c';
    
xcp.signals(592).symbol =  'Copy_of_Robot_leg_3_0_B.Signx_o';
    
xcp.signals(593).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_pm';
    
xcp.signals(594).symbol =  'Copy_of_Robot_leg_3_0_B.Product_o';
    
xcp.signals(595).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_k';
    
xcp.signals(596).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_h';
    
xcp.signals(597).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_n';
    
xcp.signals(598).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_ew';
    
xcp.signals(599).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_n';
    
xcp.signals(600).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_mf';
    
xcp.signals(601).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_mf';
    
xcp.signals(602).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_mf';
    
xcp.signals(603).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_ph';
    
xcp.signals(604).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_o';
    
xcp.signals(605).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_mf';
    
xcp.signals(606).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_gs';
    
xcp.signals(607).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_d';
    
xcp.signals(608).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_m';
    
xcp.signals(609).symbol =  'Copy_of_Robot_leg_3_0_B.Product6_d';
    
xcp.signals(610).symbol =  'Copy_of_Robot_leg_3_0_B.Product7_p';
    
xcp.signals(611).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_js';
    
xcp.signals(612).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_o';
    
xcp.signals(613).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_a';
    
xcp.signals(614).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_hxv';
    
xcp.signals(615).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_o3';
    
xcp.signals(616).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_l';
    
xcp.signals(617).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_g';
    
xcp.signals(618).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_i';
    
xcp.signals(619).symbol =  'Copy_of_Robot_leg_3_0_B.DeadZone_b';
    
xcp.signals(620).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_g';
    
xcp.signals(621).symbol =  'Copy_of_Robot_leg_3_0_B.Product_i';
    
xcp.signals(622).symbol =  'Copy_of_Robot_leg_3_0_B.Signvx_a';
    
xcp.signals(623).symbol =  'Copy_of_Robot_leg_3_0_B.Signx_l';
    
xcp.signals(624).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_lb';
    
xcp.signals(625).symbol =  'Copy_of_Robot_leg_3_0_B.Product_n';
    
xcp.signals(626).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_h';
    
xcp.signals(627).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_o';
    
xcp.signals(628).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_h';
    
xcp.signals(629).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_e';
    
xcp.signals(630).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_jd';
    
xcp.signals(631).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a0';
    
xcp.signals(632).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a0';
    
xcp.signals(633).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a0';
    
xcp.signals(634).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_cp';
    
xcp.signals(635).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_cp';
    
xcp.signals(636).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_a0';
    
xcp.signals(637).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_l';
    
xcp.signals(638).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_po';
    
xcp.signals(639).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_ha';
    
xcp.signals(640).symbol =  'Copy_of_Robot_leg_3_0_B.Product6_g';
    
xcp.signals(641).symbol =  'Copy_of_Robot_leg_3_0_B.Product7_a';
    
xcp.signals(642).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_j';
    
xcp.signals(643).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction1_g';
    
xcp.signals(644).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_cq';
    
xcp.signals(645).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_m';
    
xcp.signals(646).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_kg';
    
xcp.signals(647).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_b';
    
xcp.signals(648).symbol =  'Copy_of_Robot_leg_3_0_B.Compare_f';
    
xcp.signals(649).symbol =  'Copy_of_Robot_leg_3_0_B.Abs_c';
    
xcp.signals(650).symbol =  'Copy_of_Robot_leg_3_0_B.DeadZone';
    
xcp.signals(651).symbol =  'Copy_of_Robot_leg_3_0_B.Gain2_i';
    
xcp.signals(652).symbol =  'Copy_of_Robot_leg_3_0_B.Product_b';
    
xcp.signals(653).symbol =  'Copy_of_Robot_leg_3_0_B.Signvx';
    
xcp.signals(654).symbol =  'Copy_of_Robot_leg_3_0_B.Signx';
    
xcp.signals(655).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_ml';
    
xcp.signals(656).symbol =  'Copy_of_Robot_leg_3_0_B.Product_jb';
    
xcp.signals(657).symbol =  'Copy_of_Robot_leg_3_0_B.Product1';
    
xcp.signals(658).symbol =  'Copy_of_Robot_leg_3_0_B.Product2';
    
xcp.signals(659).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_m';
    
xcp.signals(660).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_b';
    
xcp.signals(661).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_h';
    
xcp.signals(662).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_n';
    
xcp.signals(663).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_n';
    
xcp.signals(664).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_n';
    
xcp.signals(665).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_b5';
    
xcp.signals(666).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_i';
    
xcp.signals(667).symbol =  'Copy_of_Robot_leg_3_0_B.FSph_n';
    
xcp.signals(668).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_g';
    
xcp.signals(669).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_k';
    
xcp.signals(670).symbol =  'Copy_of_Robot_leg_3_0_B.Product5';
    
xcp.signals(671).symbol =  'Copy_of_Robot_leg_3_0_B.Product6';
    
xcp.signals(672).symbol =  'Copy_of_Robot_leg_3_0_B.Product7';
    
xcp.signals(673).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_d';
    
xcp.signals(674).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction1';
    
xcp.signals(675).symbol =  'Copy_of_Robot_leg_3_0_B.Gain_mv';
    
xcp.signals(676).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_j';
    
xcp.signals(677).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_kn';
    
xcp.signals(678).symbol =  'Copy_of_Robot_leg_3_0_B.Product_ms';
    
xcp.signals(679).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_kj';
    
xcp.signals(680).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_i1';
    
xcp.signals(681).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_ny';
    
xcp.signals(682).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_d1';
    
xcp.signals(683).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_i3';
    
xcp.signals(684).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_iw';
    
xcp.signals(685).symbol =  'Copy_of_Robot_leg_3_0_B.Sum1_f';
    
xcp.signals(686).symbol =  'Copy_of_Robot_leg_3_0_B.Sum2_k';
    
xcp.signals(687).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_gn';
    
xcp.signals(688).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction1_aw';
    
xcp.signals(689).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_nd';
    
xcp.signals(690).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_m';
    
xcp.signals(691).symbol =  'Copy_of_Robot_leg_3_0_B.slipy_j';
    
xcp.signals(692).symbol =  'Copy_of_Robot_leg_3_0_B.slipx_p';
    
xcp.signals(693).symbol =  'Copy_of_Robot_leg_3_0_B.Sum3_dn';
    
xcp.signals(694).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_pg';
    
xcp.signals(695).symbol =  'Copy_of_Robot_leg_3_0_B.Sqrt_o';
    
xcp.signals(696).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_o';
    
xcp.signals(697).symbol =  'Copy_of_Robot_leg_3_0_B.Stiffness_Force_k0';
    
xcp.signals(698).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_l';
    
xcp.signals(699).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_d2';
    
xcp.signals(700).symbol =  'Copy_of_Robot_leg_3_0_B.Saturation_dc';
    
xcp.signals(701).symbol =  'Copy_of_Robot_leg_3_0_B.Sign_kv';
    
xcp.signals(702).symbol =  'Copy_of_Robot_leg_3_0_B.RESHAPE_l';
    
xcp.signals(703).symbol =  'Copy_of_Robot_leg_3_0_B.Product_n4';
    
xcp.signals(704).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_g';
    
xcp.signals(705).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_ox';
    
xcp.signals(706).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_in';
    
xcp.signals(707).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_fk';
    
xcp.signals(708).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_id';
    
xcp.signals(709).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_d0';
    
xcp.signals(710).symbol =  'Copy_of_Robot_leg_3_0_B.Sum1_o';
    
xcp.signals(711).symbol =  'Copy_of_Robot_leg_3_0_B.Sum2_j';
    
xcp.signals(712).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_ke';
    
xcp.signals(713).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction1_p';
    
xcp.signals(714).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_c3';
    
xcp.signals(715).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_bh';
    
xcp.signals(716).symbol =  'Copy_of_Robot_leg_3_0_B.slipy_n';
    
xcp.signals(717).symbol =  'Copy_of_Robot_leg_3_0_B.slipx_f';
    
xcp.signals(718).symbol =  'Copy_of_Robot_leg_3_0_B.Sum3_g';
    
xcp.signals(719).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_f';
    
xcp.signals(720).symbol =  'Copy_of_Robot_leg_3_0_B.Sqrt_d';
    
xcp.signals(721).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_i';
    
xcp.signals(722).symbol =  'Copy_of_Robot_leg_3_0_B.Stiffness_Force_kw';
    
xcp.signals(723).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_mh';
    
xcp.signals(724).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_g';
    
xcp.signals(725).symbol =  'Copy_of_Robot_leg_3_0_B.Saturation_el';
    
xcp.signals(726).symbol =  'Copy_of_Robot_leg_3_0_B.Sign_g';
    
xcp.signals(727).symbol =  'Copy_of_Robot_leg_3_0_B.RESHAPE_b';
    
xcp.signals(728).symbol =  'Copy_of_Robot_leg_3_0_B.Product_j2';
    
xcp.signals(729).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_f';
    
xcp.signals(730).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_hu';
    
xcp.signals(731).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_b';
    
xcp.signals(732).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_ad';
    
xcp.signals(733).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_gd';
    
xcp.signals(734).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_ec';
    
xcp.signals(735).symbol =  'Copy_of_Robot_leg_3_0_B.Sum1_cv';
    
xcp.signals(736).symbol =  'Copy_of_Robot_leg_3_0_B.Sum2_n';
    
xcp.signals(737).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_hr';
    
xcp.signals(738).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction1_a2';
    
xcp.signals(739).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_ao';
    
xcp.signals(740).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_a5';
    
xcp.signals(741).symbol =  'Copy_of_Robot_leg_3_0_B.slipy_o';
    
xcp.signals(742).symbol =  'Copy_of_Robot_leg_3_0_B.slipx_l';
    
xcp.signals(743).symbol =  'Copy_of_Robot_leg_3_0_B.Sum3_a';
    
xcp.signals(744).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_pt';
    
xcp.signals(745).symbol =  'Copy_of_Robot_leg_3_0_B.Sqrt_h';
    
xcp.signals(746).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_df';
    
xcp.signals(747).symbol =  'Copy_of_Robot_leg_3_0_B.Stiffness_Force_kv';
    
xcp.signals(748).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_m';
    
xcp.signals(749).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_a';
    
xcp.signals(750).symbol =  'Copy_of_Robot_leg_3_0_B.Saturation_d';
    
xcp.signals(751).symbol =  'Copy_of_Robot_leg_3_0_B.Sign_m';
    
xcp.signals(752).symbol =  'Copy_of_Robot_leg_3_0_B.RESHAPE_j1';
    
xcp.signals(753).symbol =  'Copy_of_Robot_leg_3_0_B.Product_pw';
    
xcp.signals(754).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_a';
    
xcp.signals(755).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_l';
    
xcp.signals(756).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_c';
    
xcp.signals(757).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_iy';
    
xcp.signals(758).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_g';
    
xcp.signals(759).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_ei';
    
xcp.signals(760).symbol =  'Copy_of_Robot_leg_3_0_B.Sum1_ck';
    
xcp.signals(761).symbol =  'Copy_of_Robot_leg_3_0_B.Sum2_g';
    
xcp.signals(762).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_pq';
    
xcp.signals(763).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction1_m';
    
xcp.signals(764).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_j';
    
xcp.signals(765).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_i';
    
xcp.signals(766).symbol =  'Copy_of_Robot_leg_3_0_B.slipy_h';
    
xcp.signals(767).symbol =  'Copy_of_Robot_leg_3_0_B.slipx_m';
    
xcp.signals(768).symbol =  'Copy_of_Robot_leg_3_0_B.Sum3_c';
    
xcp.signals(769).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_p';
    
xcp.signals(770).symbol =  'Copy_of_Robot_leg_3_0_B.Sqrt_l3';
    
xcp.signals(771).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_h';
    
xcp.signals(772).symbol =  'Copy_of_Robot_leg_3_0_B.Stiffness_Force_kg';
    
xcp.signals(773).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_d';
    
xcp.signals(774).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_cq';
    
xcp.signals(775).symbol =  'Copy_of_Robot_leg_3_0_B.Saturation_jq';
    
xcp.signals(776).symbol =  'Copy_of_Robot_leg_3_0_B.Sign_f';
    
xcp.signals(777).symbol =  'Copy_of_Robot_leg_3_0_B.RESHAPE_jw';
    
xcp.signals(778).symbol =  'Copy_of_Robot_leg_3_0_B.Product_bl';
    
xcp.signals(779).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_ik';
    
xcp.signals(780).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_b';
    
xcp.signals(781).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_d';
    
xcp.signals(782).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_cw';
    
xcp.signals(783).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_e';
    
xcp.signals(784).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_ph';
    
xcp.signals(785).symbol =  'Copy_of_Robot_leg_3_0_B.Sum1_c';
    
xcp.signals(786).symbol =  'Copy_of_Robot_leg_3_0_B.Sum2_h';
    
xcp.signals(787).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_c2';
    
xcp.signals(788).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction1_a';
    
xcp.signals(789).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_p';
    
xcp.signals(790).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_l';
    
xcp.signals(791).symbol =  'Copy_of_Robot_leg_3_0_B.slipy_c';
    
xcp.signals(792).symbol =  'Copy_of_Robot_leg_3_0_B.slipx_c';
    
xcp.signals(793).symbol =  'Copy_of_Robot_leg_3_0_B.Sum3_d';
    
xcp.signals(794).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_i';
    
xcp.signals(795).symbol =  'Copy_of_Robot_leg_3_0_B.Sqrt_m';
    
xcp.signals(796).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_k';
    
xcp.signals(797).symbol =  'Copy_of_Robot_leg_3_0_B.Stiffness_Force_k';
    
xcp.signals(798).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_e';
    
xcp.signals(799).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_cz';
    
xcp.signals(800).symbol =  'Copy_of_Robot_leg_3_0_B.Saturation_e';
    
xcp.signals(801).symbol =  'Copy_of_Robot_leg_3_0_B.Sign_b';
    
xcp.signals(802).symbol =  'Copy_of_Robot_leg_3_0_B.RESHAPE';
    
xcp.signals(803).symbol =  'Copy_of_Robot_leg_3_0_B.Product_nx';
    
xcp.signals(804).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_b';
    
xcp.signals(805).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_hx';
    
xcp.signals(806).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_hs';
    
xcp.signals(807).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_bz';
    
xcp.signals(808).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_i';
    
xcp.signals(809).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_mh';
    
xcp.signals(810).symbol =  'Copy_of_Robot_leg_3_0_B.Sum1_e';
    
xcp.signals(811).symbol =  'Copy_of_Robot_leg_3_0_B.Sum2_m';
    
xcp.signals(812).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_mw';
    
xcp.signals(813).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction1_j';
    
xcp.signals(814).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_f';
    
xcp.signals(815).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_ft';
    
xcp.signals(816).symbol =  'Copy_of_Robot_leg_3_0_B.slipy_a';
    
xcp.signals(817).symbol =  'Copy_of_Robot_leg_3_0_B.slipx_h';
    
xcp.signals(818).symbol =  'Copy_of_Robot_leg_3_0_B.Sum3_i';
    
xcp.signals(819).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_j1';
    
xcp.signals(820).symbol =  'Copy_of_Robot_leg_3_0_B.Sqrt_f';
    
xcp.signals(821).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_d';
    
xcp.signals(822).symbol =  'Copy_of_Robot_leg_3_0_B.Stiffness_Force_i';
    
xcp.signals(823).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_c';
    
xcp.signals(824).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_o';
    
xcp.signals(825).symbol =  'Copy_of_Robot_leg_3_0_B.Saturation_f';
    
xcp.signals(826).symbol =  'Copy_of_Robot_leg_3_0_B.Sign_l';
    
xcp.signals(827).symbol =  'Copy_of_Robot_leg_3_0_B.RESHAPE_f';
    
xcp.signals(828).symbol =  'Copy_of_Robot_leg_3_0_B.Product_bbt';
    
xcp.signals(829).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_h1';
    
xcp.signals(830).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_a';
    
xcp.signals(831).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_i';
    
xcp.signals(832).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_f';
    
xcp.signals(833).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_ju';
    
xcp.signals(834).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_g';
    
xcp.signals(835).symbol =  'Copy_of_Robot_leg_3_0_B.Sum1_j';
    
xcp.signals(836).symbol =  'Copy_of_Robot_leg_3_0_B.Sum2_e';
    
xcp.signals(837).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_o';
    
xcp.signals(838).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction1_n';
    
xcp.signals(839).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_e';
    
xcp.signals(840).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_p';
    
xcp.signals(841).symbol =  'Copy_of_Robot_leg_3_0_B.slipy_e';
    
xcp.signals(842).symbol =  'Copy_of_Robot_leg_3_0_B.slipx_k';
    
xcp.signals(843).symbol =  'Copy_of_Robot_leg_3_0_B.Sum3_p';
    
xcp.signals(844).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction_l';
    
xcp.signals(845).symbol =  'Copy_of_Robot_leg_3_0_B.Sqrt_l';
    
xcp.signals(846).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_Enable_b';
    
xcp.signals(847).symbol =  'Copy_of_Robot_leg_3_0_B.Stiffness_Force_m';
    
xcp.signals(848).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_p';
    
xcp.signals(849).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_nm';
    
xcp.signals(850).symbol =  'Copy_of_Robot_leg_3_0_B.Saturation_j';
    
xcp.signals(851).symbol =  'Copy_of_Robot_leg_3_0_B.Sign_k';
    
xcp.signals(852).symbol =  'Copy_of_Robot_leg_3_0_B.RESHAPE_p';
    
xcp.signals(853).symbol =  'Copy_of_Robot_leg_3_0_B.Product_eg';
    
xcp.signals(854).symbol =  'Copy_of_Robot_leg_3_0_B.Product1_c';
    
xcp.signals(855).symbol =  'Copy_of_Robot_leg_3_0_B.Product2_n';
    
xcp.signals(856).symbol =  'Copy_of_Robot_leg_3_0_B.Product3_a';
    
xcp.signals(857).symbol =  'Copy_of_Robot_leg_3_0_B.Product4_c';
    
xcp.signals(858).symbol =  'Copy_of_Robot_leg_3_0_B.Product5_j';
    
xcp.signals(859).symbol =  'Copy_of_Robot_leg_3_0_B.Sum_m4';
    
xcp.signals(860).symbol =  'Copy_of_Robot_leg_3_0_B.Sum1';
    
xcp.signals(861).symbol =  'Copy_of_Robot_leg_3_0_B.Sum2';
    
xcp.signals(862).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction_mn';
    
xcp.signals(863).symbol =  'Copy_of_Robot_leg_3_0_B.MathFunction1';
    
xcp.signals(864).symbol =  'Copy_of_Robot_leg_3_0_B.Product3';
    
xcp.signals(865).symbol =  'Copy_of_Robot_leg_3_0_B.Product4';
    
xcp.signals(866).symbol =  'Copy_of_Robot_leg_3_0_B.slipy';
    
xcp.signals(867).symbol =  'Copy_of_Robot_leg_3_0_B.slipx';
    
xcp.signals(868).symbol =  'Copy_of_Robot_leg_3_0_B.Sum3';
    
xcp.signals(869).symbol =  'Copy_of_Robot_leg_3_0_B.TrigonometricFunction';
    
xcp.signals(870).symbol =  'Copy_of_Robot_leg_3_0_B.Sqrt';
    
xcp.signals(871).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_Enable';
    
xcp.signals(872).symbol =  'Copy_of_Robot_leg_3_0_B.Stiffness_Force';
    
xcp.signals(873).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force';
    
xcp.signals(874).symbol =  'Copy_of_Robot_leg_3_0_B.Damping_Force_n';
    
xcp.signals(875).symbol =  'Copy_of_Robot_leg_3_0_B.Saturation';
    
xcp.signals(876).symbol =  'Copy_of_Robot_leg_3_0_B.Sign';
    
xcp.signals(877).symbol =  'Copy_of_Robot_leg_3_0_B.RESHAPE_j';
    
xcp.signals(878).symbol =  'Copy_of_Robot_leg_3_0_B.Friction_Force_p';
    
xcp.signals(879).symbol =  'Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_id';
    
xcp.signals(880).symbol =  'Copy_of_Robot_leg_3_0_B.Product_mc';
    
xcp.signals(881).symbol =  'Copy_of_Robot_leg_3_0_B.Friction_Force_m';
    
xcp.signals(882).symbol =  'Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_i';
    
xcp.signals(883).symbol =  'Copy_of_Robot_leg_3_0_B.Product_h';
    
xcp.signals(884).symbol =  'Copy_of_Robot_leg_3_0_B.Friction_Force_bg';
    
xcp.signals(885).symbol =  'Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_ow';
    
xcp.signals(886).symbol =  'Copy_of_Robot_leg_3_0_B.Product_ka';
    
xcp.signals(887).symbol =  'Copy_of_Robot_leg_3_0_B.Friction_Force_n';
    
xcp.signals(888).symbol =  'Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_o';
    
xcp.signals(889).symbol =  'Copy_of_Robot_leg_3_0_B.Product_db';
    
xcp.signals(890).symbol =  'Copy_of_Robot_leg_3_0_B.Friction_Force_l';
    
xcp.signals(891).symbol =  'Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloc_cu';
    
xcp.signals(892).symbol =  'Copy_of_Robot_leg_3_0_B.Product_a';
    
xcp.signals(893).symbol =  'Copy_of_Robot_leg_3_0_B.Friction_Force_b';
    
xcp.signals(894).symbol =  'Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_c';
    
xcp.signals(895).symbol =  'Copy_of_Robot_leg_3_0_B.Product_p';
    
xcp.signals(896).symbol =  'Copy_of_Robot_leg_3_0_B.Friction_Force_i';
    
xcp.signals(897).symbol =  'Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVeloci_e';
    
xcp.signals(898).symbol =  'Copy_of_Robot_leg_3_0_B.Product_bb';
    
xcp.signals(899).symbol =  'Copy_of_Robot_leg_3_0_B.Friction_Force';
    
xcp.signals(900).symbol =  'Copy_of_Robot_leg_3_0_B.CoefficientofFrictionvsVelocity';
    
xcp.signals(901).symbol =  'Copy_of_Robot_leg_3_0_B.Product_ke';
         
xcp.parameters(1).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_l';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_l';     
         
xcp.parameters(2).symbol = 'Copy_of_Robot_leg_3_0_P.Constant3_Value';
xcp.parameters(2).size   =  1;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant3_Value';     
         
xcp.parameters(3).symbol = 'Copy_of_Robot_leg_3_0_P.PulseGenerator_Amp';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&Copy_of_Robot_leg_3_0_P.PulseGenerator_Amp';     
         
xcp.parameters(4).symbol = 'Copy_of_Robot_leg_3_0_P.PulseGenerator_Period';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&Copy_of_Robot_leg_3_0_P.PulseGenerator_Period';     
         
xcp.parameters(5).symbol = 'Copy_of_Robot_leg_3_0_P.PulseGenerator_Duty';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&Copy_of_Robot_leg_3_0_P.PulseGenerator_Duty';     
         
xcp.parameters(6).symbol = 'Copy_of_Robot_leg_3_0_P.PulseGenerator_PhaseDelay';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&Copy_of_Robot_leg_3_0_P.PulseGenerator_PhaseDelay';     
         
xcp.parameters(7).symbol = 'Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P1';
xcp.parameters(7).size   =  35;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P1[0]';     
         
xcp.parameters(8).symbol = 'Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P2';
xcp.parameters(8).size   =  1;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P2';     
         
xcp.parameters(9).symbol = 'Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P3';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P3';     
         
xcp.parameters(10).symbol = 'Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P4';
xcp.parameters(10).size   =  12;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&Copy_of_Robot_leg_3_0_P.ASCIIEncode2_P4[0]';     
         
xcp.parameters(11).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P1';
xcp.parameters(11).size   =  4;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P1[0]';     
         
xcp.parameters(12).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P2';
xcp.parameters(12).size   =  4;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P2[0]';     
         
xcp.parameters(13).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P3';
xcp.parameters(13).size   =  4;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P3[0]';     
         
xcp.parameters(14).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P5';
xcp.parameters(14).size   =  1;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P5';     
         
xcp.parameters(15).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P8';
xcp.parameters(15).size   =  1;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P8';     
         
xcp.parameters(16).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P9';
xcp.parameters(16).size   =  1;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P9';     
         
xcp.parameters(17).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P10';
xcp.parameters(17).size   =  1;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P10';     
         
xcp.parameters(18).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P11';
xcp.parameters(18).size   =  1;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P11';     
         
xcp.parameters(19).symbol = 'Copy_of_Robot_leg_3_0_P.UDPConfigure_P12';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPConfigure_P12';     
         
xcp.parameters(20).symbol = 'Copy_of_Robot_leg_3_0_P.UDPSend_P1';
xcp.parameters(20).size   =  11;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPSend_P1[0]';     
         
xcp.parameters(21).symbol = 'Copy_of_Robot_leg_3_0_P.UDPSend_P2';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPSend_P2';     
         
xcp.parameters(22).symbol = 'Copy_of_Robot_leg_3_0_P.UDPSend_P3';
xcp.parameters(22).size   =  13;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPSend_P3[0]';     
         
xcp.parameters(23).symbol = 'Copy_of_Robot_leg_3_0_P.UDPSend_P4';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'real_T'; 
xcp.parameters(24).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPSend_P4';     
         
xcp.parameters(24).symbol = 'Copy_of_Robot_leg_3_0_P.UDPSend_P5';
xcp.parameters(24).size   =  1;       
xcp.parameters(24).dtname = 'real_T'; 
xcp.parameters(25).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPSend_P5';     
         
xcp.parameters(25).symbol = 'Copy_of_Robot_leg_3_0_P.UDPSend_P6';
xcp.parameters(25).size   =  1;       
xcp.parameters(25).dtname = 'real_T'; 
xcp.parameters(26).baseaddr = '&Copy_of_Robot_leg_3_0_P.UDPSend_P6';     
         
xcp.parameters(26).symbol = 'Copy_of_Robot_leg_3_0_P.TransportDelay_Delay';
xcp.parameters(26).size   =  1;       
xcp.parameters(26).dtname = 'real_T'; 
xcp.parameters(27).baseaddr = '&Copy_of_Robot_leg_3_0_P.TransportDelay_Delay';     
         
xcp.parameters(27).symbol = 'Copy_of_Robot_leg_3_0_P.TransportDelay_InitOutput';
xcp.parameters(27).size   =  1;       
xcp.parameters(27).dtname = 'real_T'; 
xcp.parameters(28).baseaddr = '&Copy_of_Robot_leg_3_0_P.TransportDelay_InitOutput';     
         
xcp.parameters(28).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain';
xcp.parameters(28).size   =  1;       
xcp.parameters(28).dtname = 'real_T'; 
xcp.parameters(29).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain';     
         
xcp.parameters(29).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_c0';
xcp.parameters(29).size   =  1;       
xcp.parameters(29).dtname = 'real_T'; 
xcp.parameters(30).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_c0';     
         
xcp.parameters(30).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_c';
xcp.parameters(30).size   =  40;       
xcp.parameters(30).dtname = 'real_T'; 
xcp.parameters(31).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_c[0]';     
         
xcp.parameters(31).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ld';
xcp.parameters(31).size   =  1;       
xcp.parameters(31).dtname = 'real_T'; 
xcp.parameters(32).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ld';     
         
xcp.parameters(32).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_pu';
xcp.parameters(32).size   =  40;       
xcp.parameters(32).dtname = 'real_T'; 
xcp.parameters(33).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_pu[0]';     
         
xcp.parameters(33).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ahx';
xcp.parameters(33).size   =  1;       
xcp.parameters(33).dtname = 'real_T'; 
xcp.parameters(34).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ahx';     
         
xcp.parameters(34).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_pc';
xcp.parameters(34).size   =  40;       
xcp.parameters(34).dtname = 'real_T'; 
xcp.parameters(35).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_pc[0]';     
         
xcp.parameters(35).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_e';
xcp.parameters(35).size   =  1;       
xcp.parameters(35).dtname = 'real_T'; 
xcp.parameters(36).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_e';     
         
xcp.parameters(36).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_cv';
xcp.parameters(36).size   =  40;       
xcp.parameters(36).dtname = 'real_T'; 
xcp.parameters(37).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_cv[0]';     
         
xcp.parameters(37).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ca';
xcp.parameters(37).size   =  1;       
xcp.parameters(37).dtname = 'real_T'; 
xcp.parameters(38).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ca';     
         
xcp.parameters(38).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_m4';
xcp.parameters(38).size   =  40;       
xcp.parameters(38).dtname = 'real_T'; 
xcp.parameters(39).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_m4[0]';     
         
xcp.parameters(39).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ci';
xcp.parameters(39).size   =  1;       
xcp.parameters(39).dtname = 'real_T'; 
xcp.parameters(40).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ci';     
         
xcp.parameters(40).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_cm';
xcp.parameters(40).size   =  40;       
xcp.parameters(40).dtname = 'real_T'; 
xcp.parameters(41).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_cm[0]';     
         
xcp.parameters(41).symbol = 'Copy_of_Robot_leg_3_0_P.Constant6_Value';
xcp.parameters(41).size   =  1;       
xcp.parameters(41).dtname = 'real_T'; 
xcp.parameters(42).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant6_Value';     
         
xcp.parameters(42).symbol = 'Copy_of_Robot_leg_3_0_P.Constant7_Value';
xcp.parameters(42).size   =  1;       
xcp.parameters(42).dtname = 'real_T'; 
xcp.parameters(43).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant7_Value';     
         
xcp.parameters(43).symbol = 'Copy_of_Robot_leg_3_0_P.Constant8_Value';
xcp.parameters(43).size   =  1;       
xcp.parameters(43).dtname = 'real_T'; 
xcp.parameters(44).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant8_Value';     
         
xcp.parameters(44).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_ap';
xcp.parameters(44).size   =  1;       
xcp.parameters(44).dtname = 'real_T'; 
xcp.parameters(45).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_ap';     
         
xcp.parameters(45).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain';
xcp.parameters(45).size   =  1;       
xcp.parameters(45).dtname = 'real_T'; 
xcp.parameters(46).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain';     
         
xcp.parameters(46).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_ax';
xcp.parameters(46).size   =  1;       
xcp.parameters(46).dtname = 'real_T'; 
xcp.parameters(47).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_ax';     
         
xcp.parameters(47).symbol = 'Copy_of_Robot_leg_3_0_P.Gain3_Gain';
xcp.parameters(47).size   =  1;       
xcp.parameters(47).dtname = 'real_T'; 
xcp.parameters(48).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain3_Gain';     
         
xcp.parameters(48).symbol = 'Copy_of_Robot_leg_3_0_P.Gain4_Gain';
xcp.parameters(48).size   =  1;       
xcp.parameters(48).dtname = 'real_T'; 
xcp.parameters(49).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain4_Gain';     
         
xcp.parameters(49).symbol = 'Copy_of_Robot_leg_3_0_P.Gain5_Gain';
xcp.parameters(49).size   =  1;       
xcp.parameters(49).dtname = 'real_T'; 
xcp.parameters(50).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain5_Gain';     
         
xcp.parameters(50).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad';
xcp.parameters(50).size   =  1;       
xcp.parameters(50).dtname = 'real_T'; 
xcp.parameters(51).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad';     
         
xcp.parameters(51).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_lenx_d';
xcp.parameters(51).size   =  1;       
xcp.parameters(51).dtname = 'real_T'; 
xcp.parameters(52).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_lenx_d';     
         
xcp.parameters(52).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_leny_n';
xcp.parameters(52).size   =  1;       
xcp.parameters(52).dtname = 'real_T'; 
xcp.parameters(53).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_leny_n';     
         
xcp.parameters(53).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_depth';
xcp.parameters(53).size   =  1;       
xcp.parameters(53).dtname = 'real_T'; 
xcp.parameters(54).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_depth';     
         
xcp.parameters(54).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_k_contact';
xcp.parameters(54).size   =  1;       
xcp.parameters(54).dtname = 'real_T'; 
xcp.parameters(55).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_k_contact';     
         
xcp.parameters(55).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_b_contact';
xcp.parameters(55).size   =  1;       
xcp.parameters(55).dtname = 'real_T'; 
xcp.parameters(56).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_b_contact';     
         
xcp.parameters(56).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_rad';
xcp.parameters(56).size   =  1;       
xcp.parameters(56).dtname = 'real_T'; 
xcp.parameters(57).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_rad';     
         
xcp.parameters(57).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_len_m';
xcp.parameters(57).size   =  1;       
xcp.parameters(57).dtname = 'real_T'; 
xcp.parameters(58).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_len_m';     
         
xcp.parameters(58).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_len_d';
xcp.parameters(58).size   =  1;       
xcp.parameters(58).dtname = 'real_T'; 
xcp.parameters(59).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_len_d';     
         
xcp.parameters(59).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_depth';
xcp.parameters(59).size   =  1;       
xcp.parameters(59).dtname = 'real_T'; 
xcp.parameters(60).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_depth';     
         
xcp.parameters(60).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_k_contact';
xcp.parameters(60).size   =  1;       
xcp.parameters(60).dtname = 'real_T'; 
xcp.parameters(61).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_k_contact';     
         
xcp.parameters(61).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_b_contact';
xcp.parameters(61).size   =  1;       
xcp.parameters(61).dtname = 'real_T'; 
xcp.parameters(62).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_b_contact';     
         
xcp.parameters(62).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_rad';
xcp.parameters(62).size   =  1;       
xcp.parameters(62).dtname = 'real_T'; 
xcp.parameters(63).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_rad';     
         
xcp.parameters(63).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_len_b';
xcp.parameters(63).size   =  1;       
xcp.parameters(63).dtname = 'real_T'; 
xcp.parameters(64).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_len_b';     
         
xcp.parameters(64).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_len_p';
xcp.parameters(64).size   =  1;       
xcp.parameters(64).dtname = 'real_T'; 
xcp.parameters(65).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_len_p';     
         
xcp.parameters(65).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_depth';
xcp.parameters(65).size   =  1;       
xcp.parameters(65).dtname = 'real_T'; 
xcp.parameters(66).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_depth';     
         
xcp.parameters(66).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_k_contact';
xcp.parameters(66).size   =  1;       
xcp.parameters(66).dtname = 'real_T'; 
xcp.parameters(67).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_k_contact';     
         
xcp.parameters(67).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_b_contact';
xcp.parameters(67).size   =  1;       
xcp.parameters(67).dtname = 'real_T'; 
xcp.parameters(68).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_b_contact';     
         
xcp.parameters(68).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_rad';
xcp.parameters(68).size   =  1;       
xcp.parameters(68).dtname = 'real_T'; 
xcp.parameters(69).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_rad';     
         
xcp.parameters(69).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_len_p';
xcp.parameters(69).size   =  1;       
xcp.parameters(69).dtname = 'real_T'; 
xcp.parameters(70).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_len_p';     
         
xcp.parameters(70).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_len_c';
xcp.parameters(70).size   =  1;       
xcp.parameters(70).dtname = 'real_T'; 
xcp.parameters(71).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_len_c';     
         
xcp.parameters(71).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_depth';
xcp.parameters(71).size   =  1;       
xcp.parameters(71).dtname = 'real_T'; 
xcp.parameters(72).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_depth';     
         
xcp.parameters(72).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_k_contact';
xcp.parameters(72).size   =  1;       
xcp.parameters(72).dtname = 'real_T'; 
xcp.parameters(73).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_k_contact';     
         
xcp.parameters(73).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_b_contact';
xcp.parameters(73).size   =  1;       
xcp.parameters(73).dtname = 'real_T'; 
xcp.parameters(74).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_b_contact';     
         
xcp.parameters(74).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ii';
xcp.parameters(74).size   =  1;       
xcp.parameters(74).dtname = 'real_T'; 
xcp.parameters(75).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ii';     
         
xcp.parameters(75).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_bl';
xcp.parameters(75).size   =  40;       
xcp.parameters(75).dtname = 'real_T'; 
xcp.parameters(76).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_bl[0]';     
         
xcp.parameters(76).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_n';
xcp.parameters(76).size   =  1;       
xcp.parameters(76).dtname = 'real_T'; 
xcp.parameters(77).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_n';     
         
xcp.parameters(77).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_fq';
xcp.parameters(77).size   =  40;       
xcp.parameters(77).dtname = 'real_T'; 
xcp.parameters(78).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_fq[0]';     
         
xcp.parameters(78).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_d';
xcp.parameters(78).size   =  1;       
xcp.parameters(78).dtname = 'real_T'; 
xcp.parameters(79).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_d';     
         
xcp.parameters(79).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_dg';
xcp.parameters(79).size   =  40;       
xcp.parameters(79).dtname = 'real_T'; 
xcp.parameters(80).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_dg[0]';     
         
xcp.parameters(80).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_de';
xcp.parameters(80).size   =  1;       
xcp.parameters(80).dtname = 'real_T'; 
xcp.parameters(81).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_de';     
         
xcp.parameters(81).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_jd';
xcp.parameters(81).size   =  40;       
xcp.parameters(81).dtname = 'real_T'; 
xcp.parameters(82).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_jd[0]';     
         
xcp.parameters(82).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_f';
xcp.parameters(82).size   =  1;       
xcp.parameters(82).dtname = 'real_T'; 
xcp.parameters(83).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_f';     
         
xcp.parameters(83).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_g';
xcp.parameters(83).size   =  40;       
xcp.parameters(83).dtname = 'real_T'; 
xcp.parameters(84).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_g[0]';     
         
xcp.parameters(84).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_hw';
xcp.parameters(84).size   =  1;       
xcp.parameters(84).dtname = 'real_T'; 
xcp.parameters(85).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_hw';     
         
xcp.parameters(85).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_gn';
xcp.parameters(85).size   =  40;       
xcp.parameters(85).dtname = 'real_T'; 
xcp.parameters(86).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_gn[0]';     
         
xcp.parameters(86).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_m';
xcp.parameters(86).size   =  1;       
xcp.parameters(86).dtname = 'real_T'; 
xcp.parameters(87).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_m';     
         
xcp.parameters(87).symbol = 'Copy_of_Robot_leg_3_0_P.Constant1_Value';
xcp.parameters(87).size   =  1;       
xcp.parameters(87).dtname = 'real_T'; 
xcp.parameters(88).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant1_Value';     
         
xcp.parameters(88).symbol = 'Copy_of_Robot_leg_3_0_P.Constant2_Value';
xcp.parameters(88).size   =  1;       
xcp.parameters(88).dtname = 'real_T'; 
xcp.parameters(89).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant2_Value';     
         
xcp.parameters(89).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_no';
xcp.parameters(89).size   =  1;       
xcp.parameters(89).dtname = 'real_T'; 
xcp.parameters(90).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_no';     
         
xcp.parameters(90).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_f';
xcp.parameters(90).size   =  1;       
xcp.parameters(90).dtname = 'real_T'; 
xcp.parameters(91).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_f';     
         
xcp.parameters(91).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_aq';
xcp.parameters(91).size   =  1;       
xcp.parameters(91).dtname = 'real_T'; 
xcp.parameters(92).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_aq';     
         
xcp.parameters(92).symbol = 'Copy_of_Robot_leg_3_0_P.Gain3_Gain_i';
xcp.parameters(92).size   =  1;       
xcp.parameters(92).dtname = 'real_T'; 
xcp.parameters(93).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain3_Gain_i';     
         
xcp.parameters(93).symbol = 'Copy_of_Robot_leg_3_0_P.Gain4_Gain_n';
xcp.parameters(93).size   =  1;       
xcp.parameters(93).dtname = 'real_T'; 
xcp.parameters(94).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain4_Gain_n';     
         
xcp.parameters(94).symbol = 'Copy_of_Robot_leg_3_0_P.Gain5_Gain_m';
xcp.parameters(94).size   =  1;       
xcp.parameters(94).dtname = 'real_T'; 
xcp.parameters(95).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain5_Gain_m';     
         
xcp.parameters(95).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad_m';
xcp.parameters(95).size   =  1;       
xcp.parameters(95).dtname = 'real_T'; 
xcp.parameters(96).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_sphere_rad_m';     
         
xcp.parameters(96).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_lenx';
xcp.parameters(96).size   =  1;       
xcp.parameters(96).dtname = 'real_T'; 
xcp.parameters(97).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_lenx';     
         
xcp.parameters(97).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_leny';
xcp.parameters(97).size   =  1;       
xcp.parameters(97).dtname = 'real_T'; 
xcp.parameters(98).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_leny';     
         
xcp.parameters(98).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_dept_p';
xcp.parameters(98).size   =  1;       
xcp.parameters(98).dtname = 'real_T'; 
xcp.parameters(99).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_plane_dept_p';     
         
xcp.parameters(99).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_k_contact_h';
xcp.parameters(99).size   =  1;       
xcp.parameters(99).dtname = 'real_T'; 
xcp.parameters(100).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_k_contact_h';     
         
xcp.parameters(100).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_b_contact_m';
xcp.parameters(100).size   =  1;       
xcp.parameters(100).dtname = 'real_T'; 
xcp.parameters(101).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce_b_contact_m';     
         
xcp.parameters(101).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_ra_b';
xcp.parameters(101).size   =  1;       
xcp.parameters(101).dtname = 'real_T'; 
xcp.parameters(102).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_sphere_ra_b';     
         
xcp.parameters(102).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_lenx';
xcp.parameters(102).size   =  1;       
xcp.parameters(102).dtname = 'real_T'; 
xcp.parameters(103).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_lenx';     
         
xcp.parameters(103).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_leny';
xcp.parameters(103).size   =  1;       
xcp.parameters(103).dtname = 'real_T'; 
xcp.parameters(104).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_leny';     
         
xcp.parameters(104).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_dep_h';
xcp.parameters(104).size   =  1;       
xcp.parameters(104).dtname = 'real_T'; 
xcp.parameters(105).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_plane_dep_h';     
         
xcp.parameters(105).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_k_contact_o';
xcp.parameters(105).size   =  1;       
xcp.parameters(105).dtname = 'real_T'; 
xcp.parameters(106).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_k_contact_o';     
         
xcp.parameters(106).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_b_contact_b';
xcp.parameters(106).size   =  1;       
xcp.parameters(106).dtname = 'real_T'; 
xcp.parameters(107).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce1_b_contact_b';     
         
xcp.parameters(107).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_ra_p';
xcp.parameters(107).size   =  1;       
xcp.parameters(107).dtname = 'real_T'; 
xcp.parameters(108).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_sphere_ra_p';     
         
xcp.parameters(108).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_lenx';
xcp.parameters(108).size   =  1;       
xcp.parameters(108).dtname = 'real_T'; 
xcp.parameters(109).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_lenx';     
         
xcp.parameters(109).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_leny';
xcp.parameters(109).size   =  1;       
xcp.parameters(109).dtname = 'real_T'; 
xcp.parameters(110).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_leny';     
         
xcp.parameters(110).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_dep_k';
xcp.parameters(110).size   =  1;       
xcp.parameters(110).dtname = 'real_T'; 
xcp.parameters(111).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_plane_dep_k';     
         
xcp.parameters(111).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_k_contact_d';
xcp.parameters(111).size   =  1;       
xcp.parameters(111).dtname = 'real_T'; 
xcp.parameters(112).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_k_contact_d';     
         
xcp.parameters(112).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_b_contact_j';
xcp.parameters(112).size   =  1;       
xcp.parameters(112).dtname = 'real_T'; 
xcp.parameters(113).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce2_b_contact_j';     
         
xcp.parameters(113).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_ra_i';
xcp.parameters(113).size   =  1;       
xcp.parameters(113).dtname = 'real_T'; 
xcp.parameters(114).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_sphere_ra_i';     
         
xcp.parameters(114).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_lenx';
xcp.parameters(114).size   =  1;       
xcp.parameters(114).dtname = 'real_T'; 
xcp.parameters(115).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_lenx';     
         
xcp.parameters(115).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_leny';
xcp.parameters(115).size   =  1;       
xcp.parameters(115).dtname = 'real_T'; 
xcp.parameters(116).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_leny';     
         
xcp.parameters(116).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_dep_a';
xcp.parameters(116).size   =  1;       
xcp.parameters(116).dtname = 'real_T'; 
xcp.parameters(117).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_plane_dep_a';     
         
xcp.parameters(117).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_k_contact_e';
xcp.parameters(117).size   =  1;       
xcp.parameters(117).dtname = 'real_T'; 
xcp.parameters(118).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_k_contact_e';     
         
xcp.parameters(118).symbol = 'Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_b_contact_h';
xcp.parameters(118).size   =  1;       
xcp.parameters(118).dtname = 'real_T'; 
xcp.parameters(119).baseaddr = '&Copy_of_Robot_leg_3_0_P.SpheretoPlaneForce3_b_contact_h';     
         
xcp.parameters(119).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ir';
xcp.parameters(119).size   =  1;       
xcp.parameters(119).dtname = 'real_T'; 
xcp.parameters(120).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ir';     
         
xcp.parameters(120).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_gm';
xcp.parameters(120).size   =  1;       
xcp.parameters(120).dtname = 'real_T'; 
xcp.parameters(121).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_gm';     
         
xcp.parameters(121).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_p';
xcp.parameters(121).size   =  1;       
xcp.parameters(121).dtname = 'real_T'; 
xcp.parameters(122).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_p';     
         
xcp.parameters(122).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_k';
xcp.parameters(122).size   =  1;       
xcp.parameters(122).dtname = 'real_T'; 
xcp.parameters(123).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_k';     
         
xcp.parameters(123).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_lc';
xcp.parameters(123).size   =  1;       
xcp.parameters(123).dtname = 'real_T'; 
xcp.parameters(124).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_lc';     
         
xcp.parameters(124).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_jt';
xcp.parameters(124).size   =  1;       
xcp.parameters(124).dtname = 'real_T'; 
xcp.parameters(125).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_jt';     
         
xcp.parameters(125).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_jj';
xcp.parameters(125).size   =  1;       
xcp.parameters(125).dtname = 'real_T'; 
xcp.parameters(126).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_jj';     
         
xcp.parameters(126).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_e';
xcp.parameters(126).size   =  1;       
xcp.parameters(126).dtname = 'real_T'; 
xcp.parameters(127).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_e';     
         
xcp.parameters(127).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_mm';
xcp.parameters(127).size   =  1;       
xcp.parameters(127).dtname = 'real_T'; 
xcp.parameters(128).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_mm';     
         
xcp.parameters(128).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_nv';
xcp.parameters(128).size   =  1;       
xcp.parameters(128).dtname = 'real_T'; 
xcp.parameters(129).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_nv';     
         
xcp.parameters(129).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_dr';
xcp.parameters(129).size   =  1;       
xcp.parameters(129).dtname = 'real_T'; 
xcp.parameters(130).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_dr';     
         
xcp.parameters(130).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_nu0';
xcp.parameters(130).size   =  1;       
xcp.parameters(130).dtname = 'real_T'; 
xcp.parameters(131).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_nu0';     
         
xcp.parameters(131).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_pq';
xcp.parameters(131).size   =  1;       
xcp.parameters(131).dtname = 'real_T'; 
xcp.parameters(132).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_pq';     
         
xcp.parameters(132).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_mo4';
xcp.parameters(132).size   =  1;       
xcp.parameters(132).dtname = 'real_T'; 
xcp.parameters(133).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_mo4';     
         
xcp.parameters(133).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_od';
xcp.parameters(133).size   =  1;       
xcp.parameters(133).dtname = 'real_T'; 
xcp.parameters(134).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_od';     
         
xcp.parameters(134).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_nx';
xcp.parameters(134).size   =  1;       
xcp.parameters(134).dtname = 'real_T'; 
xcp.parameters(135).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_nx';     
         
xcp.parameters(135).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_dx';
xcp.parameters(135).size   =  1;       
xcp.parameters(135).dtname = 'real_T'; 
xcp.parameters(136).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_dx';     
         
xcp.parameters(136).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_dl';
xcp.parameters(136).size   =  1;       
xcp.parameters(136).dtname = 'real_T'; 
xcp.parameters(137).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_dl';     
         
xcp.parameters(137).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ih';
xcp.parameters(137).size   =  1;       
xcp.parameters(137).dtname = 'real_T'; 
xcp.parameters(138).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ih';     
         
xcp.parameters(138).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_nu';
xcp.parameters(138).size   =  1;       
xcp.parameters(138).dtname = 'real_T'; 
xcp.parameters(139).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_nu';     
         
xcp.parameters(139).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_k0';
xcp.parameters(139).size   =  1;       
xcp.parameters(139).dtname = 'real_T'; 
xcp.parameters(140).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_k0';     
         
xcp.parameters(140).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_iz';
xcp.parameters(140).size   =  1;       
xcp.parameters(140).dtname = 'real_T'; 
xcp.parameters(141).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_iz';     
         
xcp.parameters(141).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ch';
xcp.parameters(141).size   =  1;       
xcp.parameters(141).dtname = 'real_T'; 
xcp.parameters(142).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ch';     
         
xcp.parameters(142).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_pn';
xcp.parameters(142).size   =  1;       
xcp.parameters(142).dtname = 'real_T'; 
xcp.parameters(143).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_pn';     
         
xcp.parameters(143).symbol = 'Copy_of_Robot_leg_3_0_P.SwitchCaseActionSubsystem.Out1_Y0';
xcp.parameters(143).size   =  1;       
xcp.parameters(143).dtname = 'real_T'; 
xcp.parameters(144).baseaddr = '&Copy_of_Robot_leg_3_0_P.SwitchCaseActionSubsystem.Out1_Y0';     
         
xcp.parameters(144).symbol = 'Copy_of_Robot_leg_3_0_P.SwitchCaseActionSubsystem1.Out1_Y0';
xcp.parameters(144).size   =  1;       
xcp.parameters(144).dtname = 'real_T'; 
xcp.parameters(145).baseaddr = '&Copy_of_Robot_leg_3_0_P.SwitchCaseActionSubsystem1.Out1_Y0';     
         
xcp.parameters(145).symbol = 'Copy_of_Robot_leg_3_0_P.Merge_InitialOutput';
xcp.parameters(145).size   =  1;       
xcp.parameters(145).dtname = 'real_T'; 
xcp.parameters(146).baseaddr = '&Copy_of_Robot_leg_3_0_P.Merge_InitialOutput';     
         
xcp.parameters(146).symbol = 'Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_n';
xcp.parameters(146).size   =  1;       
xcp.parameters(146).dtname = 'real_T'; 
xcp.parameters(147).baseaddr = '&Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_n';     
         
xcp.parameters(147).symbol = 'Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_d';
xcp.parameters(147).size   =  1;       
xcp.parameters(147).dtname = 'real_T'; 
xcp.parameters(148).baseaddr = '&Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_d';     
         
xcp.parameters(148).symbol = 'Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_nd';
xcp.parameters(148).size   =  1;       
xcp.parameters(148).dtname = 'real_T'; 
xcp.parameters(149).baseaddr = '&Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_nd';     
         
xcp.parameters(149).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_mq';
xcp.parameters(149).size   =  1;       
xcp.parameters(149).dtname = 'real_T'; 
xcp.parameters(150).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_mq';     
         
xcp.parameters(150).symbol = 'Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_k';
xcp.parameters(150).size   =  1;       
xcp.parameters(150).dtname = 'real_T'; 
xcp.parameters(151).baseaddr = '&Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_k';     
         
xcp.parameters(151).symbol = 'Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_o';
xcp.parameters(151).size   =  1;       
xcp.parameters(151).dtname = 'real_T'; 
xcp.parameters(152).baseaddr = '&Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_o';     
         
xcp.parameters(152).symbol = 'Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_m';
xcp.parameters(152).size   =  1;       
xcp.parameters(152).dtname = 'real_T'; 
xcp.parameters(153).baseaddr = '&Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_m';     
         
xcp.parameters(153).symbol = 'Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_e';
xcp.parameters(153).size   =  1;       
xcp.parameters(153).dtname = 'real_T'; 
xcp.parameters(154).baseaddr = '&Copy_of_Robot_leg_3_0_P.Merge_InitialOutput_e';     
         
xcp.parameters(154).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_i';
xcp.parameters(154).size   =  1;       
xcp.parameters(154).dtname = 'real_T'; 
xcp.parameters(155).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_i';     
         
xcp.parameters(155).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_f';
xcp.parameters(155).size   =  40;       
xcp.parameters(155).dtname = 'real_T'; 
xcp.parameters(156).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_f[0]';     
         
xcp.parameters(156).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value';
xcp.parameters(156).size   =  1;       
xcp.parameters(156).dtname = 'real_T'; 
xcp.parameters(157).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value';     
         
xcp.parameters(157).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data';
xcp.parameters(157).size   =  40;       
xcp.parameters(157).dtname = 'real_T'; 
xcp.parameters(158).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data[0]';     
         
xcp.parameters(158).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_ah';
xcp.parameters(158).size   =  1;       
xcp.parameters(158).dtname = 'real_T'; 
xcp.parameters(159).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_ah';     
         
xcp.parameters(159).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_n';
xcp.parameters(159).size   =  40;       
xcp.parameters(159).dtname = 'real_T'; 
xcp.parameters(160).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_n[0]';     
         
xcp.parameters(160).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_a';
xcp.parameters(160).size   =  1;       
xcp.parameters(160).dtname = 'real_T'; 
xcp.parameters(161).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_a';     
         
xcp.parameters(161).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_l';
xcp.parameters(161).size   =  40;       
xcp.parameters(161).dtname = 'real_T'; 
xcp.parameters(162).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_l[0]';     
         
xcp.parameters(162).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_c';
xcp.parameters(162).size   =  1;       
xcp.parameters(162).dtname = 'real_T'; 
xcp.parameters(163).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_c';     
         
xcp.parameters(163).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_i';
xcp.parameters(163).size   =  40;       
xcp.parameters(163).dtname = 'real_T'; 
xcp.parameters(164).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_i[0]';     
         
xcp.parameters(164).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_b';
xcp.parameters(164).size   =  1;       
xcp.parameters(164).dtname = 'real_T'; 
xcp.parameters(165).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_b';     
         
xcp.parameters(165).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_d';
xcp.parameters(165).size   =  40;       
xcp.parameters(165).dtname = 'real_T'; 
xcp.parameters(166).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_d[0]';     
         
xcp.parameters(166).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_k';
xcp.parameters(166).size   =  1;       
xcp.parameters(166).dtname = 'real_T'; 
xcp.parameters(167).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_k';     
         
xcp.parameters(167).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_k';
xcp.parameters(167).size   =  40;       
xcp.parameters(167).dtname = 'real_T'; 
xcp.parameters(168).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_k[0]';     
         
xcp.parameters(168).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_h';
xcp.parameters(168).size   =  1;       
xcp.parameters(168).dtname = 'real_T'; 
xcp.parameters(169).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_h';     
         
xcp.parameters(169).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_kg';
xcp.parameters(169).size   =  40;       
xcp.parameters(169).dtname = 'real_T'; 
xcp.parameters(170).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_kg[0]';     
         
xcp.parameters(170).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_j';
xcp.parameters(170).size   =  1;       
xcp.parameters(170).dtname = 'real_T'; 
xcp.parameters(171).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_j';     
         
xcp.parameters(171).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_j';
xcp.parameters(171).size   =  40;       
xcp.parameters(171).dtname = 'real_T'; 
xcp.parameters(172).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_j[0]';     
         
xcp.parameters(172).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_cw';
xcp.parameters(172).size   =  1;       
xcp.parameters(172).dtname = 'real_T'; 
xcp.parameters(173).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_cw';     
         
xcp.parameters(173).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_p';
xcp.parameters(173).size   =  40;       
xcp.parameters(173).dtname = 'real_T'; 
xcp.parameters(174).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_p[0]';     
         
xcp.parameters(174).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_o';
xcp.parameters(174).size   =  1;       
xcp.parameters(174).dtname = 'real_T'; 
xcp.parameters(175).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_o';     
         
xcp.parameters(175).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_m';
xcp.parameters(175).size   =  40;       
xcp.parameters(175).dtname = 'real_T'; 
xcp.parameters(176).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_m[0]';     
         
xcp.parameters(176).symbol = 'Copy_of_Robot_leg_3_0_P.Constant_Value_bu';
xcp.parameters(176).size   =  1;       
xcp.parameters(176).dtname = 'real_T'; 
xcp.parameters(177).baseaddr = '&Copy_of_Robot_leg_3_0_P.Constant_Value_bu';     
         
xcp.parameters(177).symbol = 'Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_b';
xcp.parameters(177).size   =  40;       
xcp.parameters(177).dtname = 'real_T'; 
xcp.parameters(178).baseaddr = '&Copy_of_Robot_leg_3_0_P.LookUpTable1_bp01Data_b[0]';     
         
xcp.parameters(178).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_nz';
xcp.parameters(178).size   =  1;       
xcp.parameters(178).dtname = 'real_T'; 
xcp.parameters(179).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_nz';     
         
xcp.parameters(179).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_d';
xcp.parameters(179).size   =  1;       
xcp.parameters(179).dtname = 'real_T'; 
xcp.parameters(180).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_d';     
         
xcp.parameters(180).symbol = 'Copy_of_Robot_leg_3_0_P.Out_Y0';
xcp.parameters(180).size   =  1;       
xcp.parameters(180).dtname = 'real_T'; 
xcp.parameters(181).baseaddr = '&Copy_of_Robot_leg_3_0_P.Out_Y0';     
         
xcp.parameters(181).symbol = 'Copy_of_Robot_leg_3_0_P.Zeros_Value';
xcp.parameters(181).size   =  12;       
xcp.parameters(181).dtname = 'real_T'; 
xcp.parameters(182).baseaddr = '&Copy_of_Robot_leg_3_0_P.Zeros_Value[0]';     
         
xcp.parameters(182).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_gs';
xcp.parameters(182).size   =  1;       
xcp.parameters(182).dtname = 'real_T'; 
xcp.parameters(183).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_gs';     
         
xcp.parameters(183).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_g';
xcp.parameters(183).size   =  1;       
xcp.parameters(183).dtname = 'real_T'; 
xcp.parameters(184).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_g';     
         
xcp.parameters(184).symbol = 'Copy_of_Robot_leg_3_0_P.Out_Y0_p';
xcp.parameters(184).size   =  1;       
xcp.parameters(184).dtname = 'real_T'; 
xcp.parameters(185).baseaddr = '&Copy_of_Robot_leg_3_0_P.Out_Y0_p';     
         
xcp.parameters(185).symbol = 'Copy_of_Robot_leg_3_0_P.Zeros_Value_m';
xcp.parameters(185).size   =  12;       
xcp.parameters(185).dtname = 'real_T'; 
xcp.parameters(186).baseaddr = '&Copy_of_Robot_leg_3_0_P.Zeros_Value_m[0]';     
         
xcp.parameters(186).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_gp';
xcp.parameters(186).size   =  1;       
xcp.parameters(186).dtname = 'real_T'; 
xcp.parameters(187).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_gp';     
         
xcp.parameters(187).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_kc';
xcp.parameters(187).size   =  1;       
xcp.parameters(187).dtname = 'real_T'; 
xcp.parameters(188).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_kc';     
         
xcp.parameters(188).symbol = 'Copy_of_Robot_leg_3_0_P.Out_Y0_d';
xcp.parameters(188).size   =  1;       
xcp.parameters(188).dtname = 'real_T'; 
xcp.parameters(189).baseaddr = '&Copy_of_Robot_leg_3_0_P.Out_Y0_d';     
         
xcp.parameters(189).symbol = 'Copy_of_Robot_leg_3_0_P.Zeros_Value_m2';
xcp.parameters(189).size   =  12;       
xcp.parameters(189).dtname = 'real_T'; 
xcp.parameters(190).baseaddr = '&Copy_of_Robot_leg_3_0_P.Zeros_Value_m2[0]';     
         
xcp.parameters(190).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_a0';
xcp.parameters(190).size   =  1;       
xcp.parameters(190).dtname = 'real_T'; 
xcp.parameters(191).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_a0';     
         
xcp.parameters(191).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_l';
xcp.parameters(191).size   =  1;       
xcp.parameters(191).dtname = 'real_T'; 
xcp.parameters(192).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_l';     
         
xcp.parameters(192).symbol = 'Copy_of_Robot_leg_3_0_P.Out_Y0_m';
xcp.parameters(192).size   =  1;       
xcp.parameters(192).dtname = 'real_T'; 
xcp.parameters(193).baseaddr = '&Copy_of_Robot_leg_3_0_P.Out_Y0_m';     
         
xcp.parameters(193).symbol = 'Copy_of_Robot_leg_3_0_P.Zeros_Value_m4';
xcp.parameters(193).size   =  12;       
xcp.parameters(193).dtname = 'real_T'; 
xcp.parameters(194).baseaddr = '&Copy_of_Robot_leg_3_0_P.Zeros_Value_m4[0]';     
         
xcp.parameters(194).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_d';
xcp.parameters(194).size   =  1;       
xcp.parameters(194).dtname = 'real_T'; 
xcp.parameters(195).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_d';     
         
xcp.parameters(195).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_k';
xcp.parameters(195).size   =  1;       
xcp.parameters(195).dtname = 'real_T'; 
xcp.parameters(196).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_k';     
         
xcp.parameters(196).symbol = 'Copy_of_Robot_leg_3_0_P.Out_Y0_n';
xcp.parameters(196).size   =  1;       
xcp.parameters(196).dtname = 'real_T'; 
xcp.parameters(197).baseaddr = '&Copy_of_Robot_leg_3_0_P.Out_Y0_n';     
         
xcp.parameters(197).symbol = 'Copy_of_Robot_leg_3_0_P.Zeros_Value_h';
xcp.parameters(197).size   =  12;       
xcp.parameters(197).dtname = 'real_T'; 
xcp.parameters(198).baseaddr = '&Copy_of_Robot_leg_3_0_P.Zeros_Value_h[0]';     
         
xcp.parameters(198).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_o';
xcp.parameters(198).size   =  1;       
xcp.parameters(198).dtname = 'real_T'; 
xcp.parameters(199).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_o';     
         
xcp.parameters(199).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_a';
xcp.parameters(199).size   =  1;       
xcp.parameters(199).dtname = 'real_T'; 
xcp.parameters(200).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_a';     
         
xcp.parameters(200).symbol = 'Copy_of_Robot_leg_3_0_P.Out_Y0_f';
xcp.parameters(200).size   =  1;       
xcp.parameters(200).dtname = 'real_T'; 
xcp.parameters(201).baseaddr = '&Copy_of_Robot_leg_3_0_P.Out_Y0_f';     
         
xcp.parameters(201).symbol = 'Copy_of_Robot_leg_3_0_P.Zeros_Value_c';
xcp.parameters(201).size   =  12;       
xcp.parameters(201).dtname = 'real_T'; 
xcp.parameters(202).baseaddr = '&Copy_of_Robot_leg_3_0_P.Zeros_Value_c[0]';     
         
xcp.parameters(202).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_i';
xcp.parameters(202).size   =  1;       
xcp.parameters(202).dtname = 'real_T'; 
xcp.parameters(203).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_i';     
         
xcp.parameters(203).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_h';
xcp.parameters(203).size   =  1;       
xcp.parameters(203).dtname = 'real_T'; 
xcp.parameters(204).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_h';     
         
xcp.parameters(204).symbol = 'Copy_of_Robot_leg_3_0_P.Out_Y0_e';
xcp.parameters(204).size   =  1;       
xcp.parameters(204).dtname = 'real_T'; 
xcp.parameters(205).baseaddr = '&Copy_of_Robot_leg_3_0_P.Out_Y0_e';     
         
xcp.parameters(205).symbol = 'Copy_of_Robot_leg_3_0_P.Zeros_Value_d';
xcp.parameters(205).size   =  12;       
xcp.parameters(205).dtname = 'real_T'; 
xcp.parameters(206).baseaddr = '&Copy_of_Robot_leg_3_0_P.Zeros_Value_d[0]';     
         
xcp.parameters(206).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_dr';
xcp.parameters(206).size   =  1;       
xcp.parameters(206).dtname = 'real_T'; 
xcp.parameters(207).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_dr';     
         
xcp.parameters(207).symbol = 'Copy_of_Robot_leg_3_0_P.Gain1_Gain_p';
xcp.parameters(207).size   =  1;       
xcp.parameters(207).dtname = 'real_T'; 
xcp.parameters(208).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain1_Gain_p';     
         
xcp.parameters(208).symbol = 'Copy_of_Robot_leg_3_0_P.Out_Y0_d3';
xcp.parameters(208).size   =  1;       
xcp.parameters(208).dtname = 'real_T'; 
xcp.parameters(209).baseaddr = '&Copy_of_Robot_leg_3_0_P.Out_Y0_d3';     
         
xcp.parameters(209).symbol = 'Copy_of_Robot_leg_3_0_P.Zeros_Value_du';
xcp.parameters(209).size   =  12;       
xcp.parameters(209).dtname = 'real_T'; 
xcp.parameters(210).baseaddr = '&Copy_of_Robot_leg_3_0_P.Zeros_Value_du[0]';     
         
xcp.parameters(210).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_a';
xcp.parameters(210).size   =  1;       
xcp.parameters(210).dtname = 'real_T'; 
xcp.parameters(211).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_a';     
         
xcp.parameters(211).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_hy';
xcp.parameters(211).size   =  1;       
xcp.parameters(211).dtname = 'real_T'; 
xcp.parameters(212).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_hy';     
         
xcp.parameters(212).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_cu';
xcp.parameters(212).size   =  1;       
xcp.parameters(212).dtname = 'real_T'; 
xcp.parameters(213).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_cu';     
         
xcp.parameters(213).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_e';
xcp.parameters(213).size   =  1;       
xcp.parameters(213).dtname = 'real_T'; 
xcp.parameters(214).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_e';     
         
xcp.parameters(214).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_pv';
xcp.parameters(214).size   =  1;       
xcp.parameters(214).dtname = 'real_T'; 
xcp.parameters(215).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_pv';     
         
xcp.parameters(215).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_m';
xcp.parameters(215).size   =  1;       
xcp.parameters(215).dtname = 'real_T'; 
xcp.parameters(216).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_m';     
         
xcp.parameters(216).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_Start';
xcp.parameters(216).size   =  1;       
xcp.parameters(216).dtname = 'real_T'; 
xcp.parameters(217).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_Start';     
         
xcp.parameters(217).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_End';
xcp.parameters(217).size   =  1;       
xcp.parameters(217).dtname = 'real_T'; 
xcp.parameters(218).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_End';     
         
xcp.parameters(218).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain';
xcp.parameters(218).size   =  1;       
xcp.parameters(218).dtname = 'real_T'; 
xcp.parameters(219).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain';     
         
xcp.parameters(219).symbol = 'Copy_of_Robot_leg_3_0_P.Fx1_Value';
xcp.parameters(219).size   =  1;       
xcp.parameters(219).dtname = 'real_T'; 
xcp.parameters(220).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx1_Value';     
         
xcp.parameters(220).symbol = 'Copy_of_Robot_leg_3_0_P.Fx2_Value';
xcp.parameters(220).size   =  3;       
xcp.parameters(220).dtname = 'real_T'; 
xcp.parameters(221).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx2_Value[0]';     
         
xcp.parameters(221).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_m';
xcp.parameters(221).size   =  1;       
xcp.parameters(221).dtname = 'real_T'; 
xcp.parameters(222).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_m';     
         
xcp.parameters(222).symbol = 'Copy_of_Robot_leg_3_0_P.Fx_Value';
xcp.parameters(222).size   =  1;       
xcp.parameters(222).dtname = 'real_T'; 
xcp.parameters(223).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx_Value';     
         
xcp.parameters(223).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain';
xcp.parameters(223).size   =  1;       
xcp.parameters(223).dtname = 'real_T'; 
xcp.parameters(224).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain';     
         
xcp.parameters(224).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_Start_b';
xcp.parameters(224).size   =  1;       
xcp.parameters(224).dtname = 'real_T'; 
xcp.parameters(225).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_Start_b';     
         
xcp.parameters(225).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_End_a';
xcp.parameters(225).size   =  1;       
xcp.parameters(225).dtname = 'real_T'; 
xcp.parameters(226).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_End_a';     
         
xcp.parameters(226).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_m';
xcp.parameters(226).size   =  1;       
xcp.parameters(226).dtname = 'real_T'; 
xcp.parameters(227).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_m';     
         
xcp.parameters(227).symbol = 'Copy_of_Robot_leg_3_0_P.Fx1_Value_l';
xcp.parameters(227).size   =  1;       
xcp.parameters(227).dtname = 'real_T'; 
xcp.parameters(228).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx1_Value_l';     
         
xcp.parameters(228).symbol = 'Copy_of_Robot_leg_3_0_P.Fx2_Value_n';
xcp.parameters(228).size   =  3;       
xcp.parameters(228).dtname = 'real_T'; 
xcp.parameters(229).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx2_Value_n[0]';     
         
xcp.parameters(229).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_j';
xcp.parameters(229).size   =  1;       
xcp.parameters(229).dtname = 'real_T'; 
xcp.parameters(230).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_j';     
         
xcp.parameters(230).symbol = 'Copy_of_Robot_leg_3_0_P.Fx_Value_c';
xcp.parameters(230).size   =  1;       
xcp.parameters(230).dtname = 'real_T'; 
xcp.parameters(231).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx_Value_c';     
         
xcp.parameters(231).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_n';
xcp.parameters(231).size   =  1;       
xcp.parameters(231).dtname = 'real_T'; 
xcp.parameters(232).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_n';     
         
xcp.parameters(232).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_Start_p';
xcp.parameters(232).size   =  1;       
xcp.parameters(232).dtname = 'real_T'; 
xcp.parameters(233).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_Start_p';     
         
xcp.parameters(233).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_End_i';
xcp.parameters(233).size   =  1;       
xcp.parameters(233).dtname = 'real_T'; 
xcp.parameters(234).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_End_i';     
         
xcp.parameters(234).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_b';
xcp.parameters(234).size   =  1;       
xcp.parameters(234).dtname = 'real_T'; 
xcp.parameters(235).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_b';     
         
xcp.parameters(235).symbol = 'Copy_of_Robot_leg_3_0_P.Fx1_Value_g';
xcp.parameters(235).size   =  1;       
xcp.parameters(235).dtname = 'real_T'; 
xcp.parameters(236).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx1_Value_g';     
         
xcp.parameters(236).symbol = 'Copy_of_Robot_leg_3_0_P.Fx2_Value_j';
xcp.parameters(236).size   =  3;       
xcp.parameters(236).dtname = 'real_T'; 
xcp.parameters(237).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx2_Value_j[0]';     
         
xcp.parameters(237).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_m4';
xcp.parameters(237).size   =  1;       
xcp.parameters(237).dtname = 'real_T'; 
xcp.parameters(238).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_m4';     
         
xcp.parameters(238).symbol = 'Copy_of_Robot_leg_3_0_P.Fx_Value_j';
xcp.parameters(238).size   =  1;       
xcp.parameters(238).dtname = 'real_T'; 
xcp.parameters(239).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx_Value_j';     
         
xcp.parameters(239).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_p';
xcp.parameters(239).size   =  1;       
xcp.parameters(239).dtname = 'real_T'; 
xcp.parameters(240).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_p';     
         
xcp.parameters(240).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_Start_a';
xcp.parameters(240).size   =  1;       
xcp.parameters(240).dtname = 'real_T'; 
xcp.parameters(241).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_Start_a';     
         
xcp.parameters(241).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_End_l';
xcp.parameters(241).size   =  1;       
xcp.parameters(241).dtname = 'real_T'; 
xcp.parameters(242).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_End_l';     
         
xcp.parameters(242).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_p';
xcp.parameters(242).size   =  1;       
xcp.parameters(242).dtname = 'real_T'; 
xcp.parameters(243).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_p';     
         
xcp.parameters(243).symbol = 'Copy_of_Robot_leg_3_0_P.Fx1_Value_f';
xcp.parameters(243).size   =  1;       
xcp.parameters(243).dtname = 'real_T'; 
xcp.parameters(244).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx1_Value_f';     
         
xcp.parameters(244).symbol = 'Copy_of_Robot_leg_3_0_P.Fx2_Value_i';
xcp.parameters(244).size   =  3;       
xcp.parameters(244).dtname = 'real_T'; 
xcp.parameters(245).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx2_Value_i[0]';     
         
xcp.parameters(245).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_a';
xcp.parameters(245).size   =  1;       
xcp.parameters(245).dtname = 'real_T'; 
xcp.parameters(246).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_a';     
         
xcp.parameters(246).symbol = 'Copy_of_Robot_leg_3_0_P.Fx_Value_p';
xcp.parameters(246).size   =  1;       
xcp.parameters(246).dtname = 'real_T'; 
xcp.parameters(247).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx_Value_p';     
         
xcp.parameters(247).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_h';
xcp.parameters(247).size   =  1;       
xcp.parameters(247).dtname = 'real_T'; 
xcp.parameters(248).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_h';     
         
xcp.parameters(248).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_ci';
xcp.parameters(248).size   =  1;       
xcp.parameters(248).dtname = 'real_T'; 
xcp.parameters(249).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_ci';     
         
xcp.parameters(249).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_h';
xcp.parameters(249).size   =  1;       
xcp.parameters(249).dtname = 'real_T'; 
xcp.parameters(250).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_h';     
         
xcp.parameters(250).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_o';
xcp.parameters(250).size   =  1;       
xcp.parameters(250).dtname = 'real_T'; 
xcp.parameters(251).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_o';     
         
xcp.parameters(251).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_p';
xcp.parameters(251).size   =  1;       
xcp.parameters(251).dtname = 'real_T'; 
xcp.parameters(252).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_p';     
         
xcp.parameters(252).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_c';
xcp.parameters(252).size   =  1;       
xcp.parameters(252).dtname = 'real_T'; 
xcp.parameters(253).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_c';     
         
xcp.parameters(253).symbol = 'Copy_of_Robot_leg_3_0_P.GAIN_Gain_k';
xcp.parameters(253).size   =  1;       
xcp.parameters(253).dtname = 'real_T'; 
xcp.parameters(254).baseaddr = '&Copy_of_Robot_leg_3_0_P.GAIN_Gain_k';     
         
xcp.parameters(254).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_Start_n';
xcp.parameters(254).size   =  1;       
xcp.parameters(254).dtname = 'real_T'; 
xcp.parameters(255).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_Start_n';     
         
xcp.parameters(255).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_End_ln';
xcp.parameters(255).size   =  1;       
xcp.parameters(255).dtname = 'real_T'; 
xcp.parameters(256).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_End_ln';     
         
xcp.parameters(256).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_j';
xcp.parameters(256).size   =  1;       
xcp.parameters(256).dtname = 'real_T'; 
xcp.parameters(257).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_j';     
         
xcp.parameters(257).symbol = 'Copy_of_Robot_leg_3_0_P.Fx1_Value_c';
xcp.parameters(257).size   =  1;       
xcp.parameters(257).dtname = 'real_T'; 
xcp.parameters(258).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx1_Value_c';     
         
xcp.parameters(258).symbol = 'Copy_of_Robot_leg_3_0_P.Fx2_Value_o';
xcp.parameters(258).size   =  3;       
xcp.parameters(258).dtname = 'real_T'; 
xcp.parameters(259).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx2_Value_o[0]';     
         
xcp.parameters(259).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_mo';
xcp.parameters(259).size   =  1;       
xcp.parameters(259).dtname = 'real_T'; 
xcp.parameters(260).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_mo';     
         
xcp.parameters(260).symbol = 'Copy_of_Robot_leg_3_0_P.Fx_Value_o';
xcp.parameters(260).size   =  1;       
xcp.parameters(260).dtname = 'real_T'; 
xcp.parameters(261).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx_Value_o';     
         
xcp.parameters(261).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_c';
xcp.parameters(261).size   =  1;       
xcp.parameters(261).dtname = 'real_T'; 
xcp.parameters(262).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_c';     
         
xcp.parameters(262).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_Start_i';
xcp.parameters(262).size   =  1;       
xcp.parameters(262).dtname = 'real_T'; 
xcp.parameters(263).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_Start_i';     
         
xcp.parameters(263).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_End_m';
xcp.parameters(263).size   =  1;       
xcp.parameters(263).dtname = 'real_T'; 
xcp.parameters(264).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_End_m';     
         
xcp.parameters(264).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_f3';
xcp.parameters(264).size   =  1;       
xcp.parameters(264).dtname = 'real_T'; 
xcp.parameters(265).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_f3';     
         
xcp.parameters(265).symbol = 'Copy_of_Robot_leg_3_0_P.Fx1_Value_j';
xcp.parameters(265).size   =  1;       
xcp.parameters(265).dtname = 'real_T'; 
xcp.parameters(266).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx1_Value_j';     
         
xcp.parameters(266).symbol = 'Copy_of_Robot_leg_3_0_P.Fx2_Value_h';
xcp.parameters(266).size   =  3;       
xcp.parameters(266).dtname = 'real_T'; 
xcp.parameters(267).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx2_Value_h[0]';     
         
xcp.parameters(267).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_b';
xcp.parameters(267).size   =  1;       
xcp.parameters(267).dtname = 'real_T'; 
xcp.parameters(268).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_b';     
         
xcp.parameters(268).symbol = 'Copy_of_Robot_leg_3_0_P.Fx_Value_b';
xcp.parameters(268).size   =  1;       
xcp.parameters(268).dtname = 'real_T'; 
xcp.parameters(269).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx_Value_b';     
         
xcp.parameters(269).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_mj';
xcp.parameters(269).size   =  1;       
xcp.parameters(269).dtname = 'real_T'; 
xcp.parameters(270).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_mj';     
         
xcp.parameters(270).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_Start_n5';
xcp.parameters(270).size   =  1;       
xcp.parameters(270).dtname = 'real_T'; 
xcp.parameters(271).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_Start_n5';     
         
xcp.parameters(271).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_End_k';
xcp.parameters(271).size   =  1;       
xcp.parameters(271).dtname = 'real_T'; 
xcp.parameters(272).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_End_k';     
         
xcp.parameters(272).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_h';
xcp.parameters(272).size   =  1;       
xcp.parameters(272).dtname = 'real_T'; 
xcp.parameters(273).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_h';     
         
xcp.parameters(273).symbol = 'Copy_of_Robot_leg_3_0_P.Fx1_Value_k';
xcp.parameters(273).size   =  1;       
xcp.parameters(273).dtname = 'real_T'; 
xcp.parameters(274).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx1_Value_k';     
         
xcp.parameters(274).symbol = 'Copy_of_Robot_leg_3_0_P.Fx2_Value_ip';
xcp.parameters(274).size   =  3;       
xcp.parameters(274).dtname = 'real_T'; 
xcp.parameters(275).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx2_Value_ip[0]';     
         
xcp.parameters(275).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_f';
xcp.parameters(275).size   =  1;       
xcp.parameters(275).dtname = 'real_T'; 
xcp.parameters(276).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_f';     
         
xcp.parameters(276).symbol = 'Copy_of_Robot_leg_3_0_P.Fx_Value_l';
xcp.parameters(276).size   =  1;       
xcp.parameters(276).dtname = 'real_T'; 
xcp.parameters(277).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx_Value_l';     
         
xcp.parameters(277).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_g';
xcp.parameters(277).size   =  1;       
xcp.parameters(277).dtname = 'real_T'; 
xcp.parameters(278).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_g';     
         
xcp.parameters(278).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_Start_o';
xcp.parameters(278).size   =  1;       
xcp.parameters(278).dtname = 'real_T'; 
xcp.parameters(279).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_Start_o';     
         
xcp.parameters(279).symbol = 'Copy_of_Robot_leg_3_0_P.DeadZone_End_j';
xcp.parameters(279).size   =  1;       
xcp.parameters(279).dtname = 'real_T'; 
xcp.parameters(280).baseaddr = '&Copy_of_Robot_leg_3_0_P.DeadZone_End_j';     
         
xcp.parameters(280).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_e';
xcp.parameters(280).size   =  1;       
xcp.parameters(280).dtname = 'real_T'; 
xcp.parameters(281).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_e';     
         
xcp.parameters(281).symbol = 'Copy_of_Robot_leg_3_0_P.Fx1_Value_o';
xcp.parameters(281).size   =  1;       
xcp.parameters(281).dtname = 'real_T'; 
xcp.parameters(282).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx1_Value_o';     
         
xcp.parameters(282).symbol = 'Copy_of_Robot_leg_3_0_P.Fx2_Value_he';
xcp.parameters(282).size   =  3;       
xcp.parameters(282).dtname = 'real_T'; 
xcp.parameters(283).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx2_Value_he[0]';     
         
xcp.parameters(283).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_jj';
xcp.parameters(283).size   =  1;       
xcp.parameters(283).dtname = 'real_T'; 
xcp.parameters(284).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_jj';     
         
xcp.parameters(284).symbol = 'Copy_of_Robot_leg_3_0_P.Fx_Value_oe';
xcp.parameters(284).size   =  1;       
xcp.parameters(284).dtname = 'real_T'; 
xcp.parameters(285).baseaddr = '&Copy_of_Robot_leg_3_0_P.Fx_Value_oe';     
         
xcp.parameters(285).symbol = 'Copy_of_Robot_leg_3_0_P.Gain_Gain_ns';
xcp.parameters(285).size   =  1;       
xcp.parameters(285).dtname = 'real_T'; 
xcp.parameters(286).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain_Gain_ns';     
         
xcp.parameters(286).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_UpperSat';
xcp.parameters(286).size   =  1;       
xcp.parameters(286).dtname = 'real_T'; 
xcp.parameters(287).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_UpperSat';     
         
xcp.parameters(287).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_LowerSat';
xcp.parameters(287).size   =  1;       
xcp.parameters(287).dtname = 'real_T'; 
xcp.parameters(288).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_LowerSat';     
         
xcp.parameters(288).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_l';
xcp.parameters(288).size   =  1;       
xcp.parameters(288).dtname = 'real_T'; 
xcp.parameters(289).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_l';     
         
xcp.parameters(289).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_g';
xcp.parameters(289).size   =  1;       
xcp.parameters(289).dtname = 'real_T'; 
xcp.parameters(290).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_g';     
         
xcp.parameters(290).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_b';
xcp.parameters(290).size   =  1;       
xcp.parameters(290).dtname = 'real_T'; 
xcp.parameters(291).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_b';     
         
xcp.parameters(291).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_j';
xcp.parameters(291).size   =  1;       
xcp.parameters(291).dtname = 'real_T'; 
xcp.parameters(292).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_j';     
         
xcp.parameters(292).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_d';
xcp.parameters(292).size   =  1;       
xcp.parameters(292).dtname = 'real_T'; 
xcp.parameters(293).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_d';     
         
xcp.parameters(293).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_c';
xcp.parameters(293).size   =  1;       
xcp.parameters(293).dtname = 'real_T'; 
xcp.parameters(294).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_c';     
         
xcp.parameters(294).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_p';
xcp.parameters(294).size   =  1;       
xcp.parameters(294).dtname = 'real_T'; 
xcp.parameters(295).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_p';     
         
xcp.parameters(295).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_d';
xcp.parameters(295).size   =  1;       
xcp.parameters(295).dtname = 'real_T'; 
xcp.parameters(296).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_d';     
         
xcp.parameters(296).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_o';
xcp.parameters(296).size   =  1;       
xcp.parameters(296).dtname = 'real_T'; 
xcp.parameters(297).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_o';     
         
xcp.parameters(297).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_a';
xcp.parameters(297).size   =  1;       
xcp.parameters(297).dtname = 'real_T'; 
xcp.parameters(298).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_a';     
         
xcp.parameters(298).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_e';
xcp.parameters(298).size   =  1;       
xcp.parameters(298).dtname = 'real_T'; 
xcp.parameters(299).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_e';     
         
xcp.parameters(299).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_g5';
xcp.parameters(299).size   =  1;       
xcp.parameters(299).dtname = 'real_T'; 
xcp.parameters(300).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_g5';     
         
xcp.parameters(300).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_f';
xcp.parameters(300).size   =  1;       
xcp.parameters(300).dtname = 'real_T'; 
xcp.parameters(301).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_UpperSat_f';     
         
xcp.parameters(301).symbol = 'Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_af';
xcp.parameters(301).size   =  1;       
xcp.parameters(301).dtname = 'real_T'; 
xcp.parameters(302).baseaddr = '&Copy_of_Robot_leg_3_0_P.Saturation_LowerSat_af';     
         
xcp.parameters(302).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_l';
xcp.parameters(302).size   =  1;       
xcp.parameters(302).dtname = 'real_T'; 
xcp.parameters(303).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_l';     
         
xcp.parameters(303).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVelocity';
xcp.parameters(303).size   =  6;       
xcp.parameters(303).dtname = 'real_T'; 
xcp.parameters(304).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVelocity[0]';     
         
xcp.parameters(304).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_l';
xcp.parameters(304).size   =  6;       
xcp.parameters(304).dtname = 'real_T'; 
xcp.parameters(305).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_l[0]';     
         
xcp.parameters(305).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_o';
xcp.parameters(305).size   =  1;       
xcp.parameters(305).dtname = 'real_T'; 
xcp.parameters(306).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_o';     
         
xcp.parameters(306).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_k';
xcp.parameters(306).size   =  6;       
xcp.parameters(306).dtname = 'real_T'; 
xcp.parameters(307).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_k[0]';     
         
xcp.parameters(307).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_j';
xcp.parameters(307).size   =  6;       
xcp.parameters(307).dtname = 'real_T'; 
xcp.parameters(308).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_j[0]';     
         
xcp.parameters(308).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_a';
xcp.parameters(308).size   =  1;       
xcp.parameters(308).dtname = 'real_T'; 
xcp.parameters(309).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_a';     
         
xcp.parameters(309).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_n';
xcp.parameters(309).size   =  6;       
xcp.parameters(309).dtname = 'real_T'; 
xcp.parameters(310).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_n[0]';     
         
xcp.parameters(310).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_d';
xcp.parameters(310).size   =  6;       
xcp.parameters(310).dtname = 'real_T'; 
xcp.parameters(311).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_d[0]';     
         
xcp.parameters(311).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_f';
xcp.parameters(311).size   =  1;       
xcp.parameters(311).dtname = 'real_T'; 
xcp.parameters(312).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_f';     
         
xcp.parameters(312).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_p';
xcp.parameters(312).size   =  6;       
xcp.parameters(312).dtname = 'real_T'; 
xcp.parameters(313).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_p[0]';     
         
xcp.parameters(313).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_a';
xcp.parameters(313).size   =  6;       
xcp.parameters(313).dtname = 'real_T'; 
xcp.parameters(314).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_a[0]';     
         
xcp.parameters(314).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_c';
xcp.parameters(314).size   =  1;       
xcp.parameters(314).dtname = 'real_T'; 
xcp.parameters(315).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_c';     
         
xcp.parameters(315).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_i';
xcp.parameters(315).size   =  6;       
xcp.parameters(315).dtname = 'real_T'; 
xcp.parameters(316).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_i[0]';     
         
xcp.parameters(316).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_ao';
xcp.parameters(316).size   =  6;       
xcp.parameters(316).dtname = 'real_T'; 
xcp.parameters(317).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_ao[0]';     
         
xcp.parameters(317).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_fy';
xcp.parameters(317).size   =  1;       
xcp.parameters(317).dtname = 'real_T'; 
xcp.parameters(318).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_fy';     
         
xcp.parameters(318).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_m';
xcp.parameters(318).size   =  6;       
xcp.parameters(318).dtname = 'real_T'; 
xcp.parameters(319).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloci_m[0]';     
         
xcp.parameters(319).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_mt';
xcp.parameters(319).size   =  6;       
xcp.parameters(319).dtname = 'real_T'; 
xcp.parameters(320).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_mt[0]';     
         
xcp.parameters(320).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_f1';
xcp.parameters(320).size   =  1;       
xcp.parameters(320).dtname = 'real_T'; 
xcp.parameters(321).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_f1';     
         
xcp.parameters(321).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_nk';
xcp.parameters(321).size   =  6;       
xcp.parameters(321).dtname = 'real_T'; 
xcp.parameters(322).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_nk[0]';     
         
xcp.parameters(322).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_ab';
xcp.parameters(322).size   =  6;       
xcp.parameters(322).dtname = 'real_T'; 
xcp.parameters(323).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_ab[0]';     
         
xcp.parameters(323).symbol = 'Copy_of_Robot_leg_3_0_P.Gain2_Gain_n';
xcp.parameters(323).size   =  1;       
xcp.parameters(323).dtname = 'real_T'; 
xcp.parameters(324).baseaddr = '&Copy_of_Robot_leg_3_0_P.Gain2_Gain_n';     
         
xcp.parameters(324).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_in';
xcp.parameters(324).size   =  6;       
xcp.parameters(324).dtname = 'real_T'; 
xcp.parameters(325).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_in[0]';     
         
xcp.parameters(325).symbol = 'Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_lt';
xcp.parameters(325).size   =  6;       
xcp.parameters(325).dtname = 'real_T'; 
xcp.parameters(326).baseaddr = '&Copy_of_Robot_leg_3_0_P.CoefficientofFrictionvsVeloc_lt[0]';     
         
xcp.parameters(326).symbol = 'Copy_of_Robot_leg_3_0_P.left_abduction';
xcp.parameters(326).size   =  40;       
xcp.parameters(326).dtname = 'real_T'; 
xcp.parameters(327).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_abduction[0]';     
         
xcp.parameters(327).symbol = 'Copy_of_Robot_leg_3_0_P.left_ankle';
xcp.parameters(327).size   =  40;       
xcp.parameters(327).dtname = 'real_T'; 
xcp.parameters(328).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_ankle[0]';     
         
xcp.parameters(328).symbol = 'Copy_of_Robot_leg_3_0_P.left_hip';
xcp.parameters(328).size   =  40;       
xcp.parameters(328).dtname = 'real_T'; 
xcp.parameters(329).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_hip[0]';     
         
xcp.parameters(329).symbol = 'Copy_of_Robot_leg_3_0_P.left_knee';
xcp.parameters(329).size   =  40;       
xcp.parameters(329).dtname = 'real_T'; 
xcp.parameters(330).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_knee[0]';     
         
xcp.parameters(330).symbol = 'Copy_of_Robot_leg_3_0_P.left_knee_twist';
xcp.parameters(330).size   =  40;       
xcp.parameters(330).dtname = 'real_T'; 
xcp.parameters(331).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_knee_twist[0]';     
         
xcp.parameters(331).symbol = 'Copy_of_Robot_leg_3_0_P.left_rotation';
xcp.parameters(331).size   =  40;       
xcp.parameters(331).dtname = 'real_T'; 
xcp.parameters(332).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_rotation[0]';     
         
xcp.parameters(332).symbol = 'Copy_of_Robot_leg_3_0_P.left_theta_1';
xcp.parameters(332).size   =  40;       
xcp.parameters(332).dtname = 'real_T'; 
xcp.parameters(333).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_theta_1[0]';     
         
xcp.parameters(333).symbol = 'Copy_of_Robot_leg_3_0_P.left_theta_2';
xcp.parameters(333).size   =  40;       
xcp.parameters(333).dtname = 'real_T'; 
xcp.parameters(334).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_theta_2[0]';     
         
xcp.parameters(334).symbol = 'Copy_of_Robot_leg_3_0_P.left_theta_3';
xcp.parameters(334).size   =  40;       
xcp.parameters(334).dtname = 'real_T'; 
xcp.parameters(335).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_theta_3[0]';     
         
xcp.parameters(335).symbol = 'Copy_of_Robot_leg_3_0_P.left_theta_4';
xcp.parameters(335).size   =  40;       
xcp.parameters(335).dtname = 'real_T'; 
xcp.parameters(336).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_theta_4[0]';     
         
xcp.parameters(336).symbol = 'Copy_of_Robot_leg_3_0_P.left_theta_5';
xcp.parameters(336).size   =  40;       
xcp.parameters(336).dtname = 'real_T'; 
xcp.parameters(337).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_theta_5[0]';     
         
xcp.parameters(337).symbol = 'Copy_of_Robot_leg_3_0_P.left_theta_6';
xcp.parameters(337).size   =  40;       
xcp.parameters(337).dtname = 'real_T'; 
xcp.parameters(338).baseaddr = '&Copy_of_Robot_leg_3_0_P.left_theta_6[0]';     
         
xcp.parameters(338).symbol = 'Copy_of_Robot_leg_3_0_P.right_abduction';
xcp.parameters(338).size   =  40;       
xcp.parameters(338).dtname = 'real_T'; 
xcp.parameters(339).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_abduction[0]';     
         
xcp.parameters(339).symbol = 'Copy_of_Robot_leg_3_0_P.right_ankle';
xcp.parameters(339).size   =  40;       
xcp.parameters(339).dtname = 'real_T'; 
xcp.parameters(340).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_ankle[0]';     
         
xcp.parameters(340).symbol = 'Copy_of_Robot_leg_3_0_P.right_hip';
xcp.parameters(340).size   =  40;       
xcp.parameters(340).dtname = 'real_T'; 
xcp.parameters(341).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_hip[0]';     
         
xcp.parameters(341).symbol = 'Copy_of_Robot_leg_3_0_P.right_knee';
xcp.parameters(341).size   =  40;       
xcp.parameters(341).dtname = 'real_T'; 
xcp.parameters(342).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_knee[0]';     
         
xcp.parameters(342).symbol = 'Copy_of_Robot_leg_3_0_P.right_knee_twist';
xcp.parameters(342).size   =  40;       
xcp.parameters(342).dtname = 'real_T'; 
xcp.parameters(343).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_knee_twist[0]';     
         
xcp.parameters(343).symbol = 'Copy_of_Robot_leg_3_0_P.right_rotation';
xcp.parameters(343).size   =  40;       
xcp.parameters(343).dtname = 'real_T'; 
xcp.parameters(344).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_rotation[0]';     
         
xcp.parameters(344).symbol = 'Copy_of_Robot_leg_3_0_P.right_theta_1';
xcp.parameters(344).size   =  40;       
xcp.parameters(344).dtname = 'real_T'; 
xcp.parameters(345).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_theta_1[0]';     
         
xcp.parameters(345).symbol = 'Copy_of_Robot_leg_3_0_P.right_theta_2';
xcp.parameters(345).size   =  40;       
xcp.parameters(345).dtname = 'real_T'; 
xcp.parameters(346).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_theta_2[0]';     
         
xcp.parameters(346).symbol = 'Copy_of_Robot_leg_3_0_P.right_theta_3';
xcp.parameters(346).size   =  40;       
xcp.parameters(346).dtname = 'real_T'; 
xcp.parameters(347).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_theta_3[0]';     
         
xcp.parameters(347).symbol = 'Copy_of_Robot_leg_3_0_P.right_theta_4';
xcp.parameters(347).size   =  40;       
xcp.parameters(347).dtname = 'real_T'; 
xcp.parameters(348).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_theta_4[0]';     
         
xcp.parameters(348).symbol = 'Copy_of_Robot_leg_3_0_P.right_theta_5';
xcp.parameters(348).size   =  40;       
xcp.parameters(348).dtname = 'real_T'; 
xcp.parameters(349).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_theta_5[0]';     
         
xcp.parameters(349).symbol = 'Copy_of_Robot_leg_3_0_P.right_theta_6';
xcp.parameters(349).size   =  40;       
xcp.parameters(349).dtname = 'real_T'; 
xcp.parameters(350).baseaddr = '&Copy_of_Robot_leg_3_0_P.right_theta_6[0]';     

function n = getNumParameters
n = 349;

function n = getNumSignals
n = 901;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

