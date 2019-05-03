function xcp = Robot_leg_3xcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'Robot_leg_3';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.2;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'Robot_leg_3_B.Switch';
    
xcp.signals(2).symbol =  'Robot_leg_3_B.Switch1';
    
xcp.signals(3).symbol =  'Robot_leg_3_B.Switch2';
    
xcp.signals(4).symbol =  'Robot_leg_3_B.Switch3';
    
xcp.signals(5).symbol =  'Robot_leg_3_B.Switch4';
    
xcp.signals(6).symbol =  'Robot_leg_3_B.Switch5';
    
xcp.signals(7).symbol =  'Robot_leg_3_B.GAIN';
    
xcp.signals(8).symbol =  'Robot_leg_3_B.IfActionSubsystem.In1';
    
xcp.signals(9).symbol =  'Robot_leg_3_B.IfActionSubsystem1.In1';
    
xcp.signals(10).symbol =  'Robot_leg_3_B.IfActionSubsystem3.In1';
    
xcp.signals(11).symbol =  'Robot_leg_3_B.IfActionSubsystem4.In1';
    
xcp.signals(12).symbol =  'Robot_leg_3_B.IfActionSubsystem5.In1';
    
xcp.signals(13).symbol =  'Robot_leg_3_B.IfActionSubsystem6.In1';
    
xcp.signals(14).symbol =  'Robot_leg_3_B.Clock_j';
    
xcp.signals(15).symbol =  'Robot_leg_3_B.Output';
    
xcp.signals(16).symbol =  'Robot_leg_3_B.LookUpTable1_b';
    
xcp.signals(17).symbol =  'Robot_leg_3_B.MathFunction_d';
    
xcp.signals(18).symbol =  'Robot_leg_3_B.Sum_o';
    
xcp.signals(19).symbol =  'Robot_leg_3_B.INPUT_10_1_1';
    
xcp.signals(20).symbol =  'Robot_leg_3_B.INPUT_10_1_2';
    
xcp.signals(21).symbol =  'Robot_leg_3_B.INPUT_10_1_3';
    
xcp.signals(22).symbol =  'Robot_leg_3_B.INPUT_11_1_1';
    
xcp.signals(23).symbol =  'Robot_leg_3_B.INPUT_11_1_2';
    
xcp.signals(24).symbol =  'Robot_leg_3_B.INPUT_11_1_3';
    
xcp.signals(25).symbol =  'Robot_leg_3_B.INPUT_12_1_1';
    
xcp.signals(26).symbol =  'Robot_leg_3_B.INPUT_12_1_2';
    
xcp.signals(27).symbol =  'Robot_leg_3_B.INPUT_12_1_3';
    
xcp.signals(28).symbol =  'Robot_leg_3_B.INPUT_13_1_1';
    
xcp.signals(29).symbol =  'Robot_leg_3_B.INPUT_13_1_2';
    
xcp.signals(30).symbol =  'Robot_leg_3_B.INPUT_13_1_3';
    
xcp.signals(31).symbol =  'Robot_leg_3_B.INPUT_14_1_1';
    
xcp.signals(32).symbol =  'Robot_leg_3_B.INPUT_14_1_2';
    
xcp.signals(33).symbol =  'Robot_leg_3_B.INPUT_14_1_3';
    
xcp.signals(34).symbol =  'Robot_leg_3_B.INPUT_15_1_1';
    
xcp.signals(35).symbol =  'Robot_leg_3_B.INPUT_15_1_2';
    
xcp.signals(36).symbol =  'Robot_leg_3_B.INPUT_15_1_3';
    
xcp.signals(37).symbol =  'Robot_leg_3_B.INPUT_16_1_1';
    
xcp.signals(38).symbol =  'Robot_leg_3_B.INPUT_16_1_2';
    
xcp.signals(39).symbol =  'Robot_leg_3_B.INPUT_16_1_3';
    
xcp.signals(40).symbol =  'Robot_leg_3_B.INPUT_17_1_1';
    
xcp.signals(41).symbol =  'Robot_leg_3_B.INPUT_17_1_2';
    
xcp.signals(42).symbol =  'Robot_leg_3_B.INPUT_17_1_3';
    
xcp.signals(43).symbol =  'Robot_leg_3_B.INPUT_18_1_1';
    
xcp.signals(44).symbol =  'Robot_leg_3_B.INPUT_18_1_2';
    
xcp.signals(45).symbol =  'Robot_leg_3_B.INPUT_18_1_3';
    
xcp.signals(46).symbol =  'Robot_leg_3_B.INPUT_19_1_1';
    
xcp.signals(47).symbol =  'Robot_leg_3_B.INPUT_19_1_2';
    
xcp.signals(48).symbol =  'Robot_leg_3_B.INPUT_19_1_3';
    
xcp.signals(49).symbol =  'Robot_leg_3_B.INPUT_1_1_1';
    
xcp.signals(50).symbol =  'Robot_leg_3_B.INPUT_20_1_1';
    
xcp.signals(51).symbol =  'Robot_leg_3_B.INPUT_20_1_2';
    
xcp.signals(52).symbol =  'Robot_leg_3_B.INPUT_20_1_3';
    
xcp.signals(53).symbol =  'Robot_leg_3_B.INPUT_21_1_1';
    
xcp.signals(54).symbol =  'Robot_leg_3_B.INPUT_21_1_2';
    
xcp.signals(55).symbol =  'Robot_leg_3_B.INPUT_21_1_3';
    
xcp.signals(56).symbol =  'Robot_leg_3_B.INPUT_22_1_1';
    
xcp.signals(57).symbol =  'Robot_leg_3_B.INPUT_22_1_2';
    
xcp.signals(58).symbol =  'Robot_leg_3_B.INPUT_22_1_3';
    
xcp.signals(59).symbol =  'Robot_leg_3_B.INPUT_23_1_1';
    
xcp.signals(60).symbol =  'Robot_leg_3_B.INPUT_24_1_1';
    
xcp.signals(61).symbol =  'Robot_leg_3_B.INPUT_25_1_1';
    
xcp.signals(62).symbol =  'Robot_leg_3_B.INPUT_26_1_1';
    
xcp.signals(63).symbol =  'Robot_leg_3_B.INPUT_27_1_1';
    
xcp.signals(64).symbol =  'Robot_leg_3_B.INPUT_28_1_1';
    
xcp.signals(65).symbol =  'Robot_leg_3_B.INPUT_29_1_1';
    
xcp.signals(66).symbol =  'Robot_leg_3_B.INPUT_29_1_2';
    
xcp.signals(67).symbol =  'Robot_leg_3_B.INPUT_29_1_3';
    
xcp.signals(68).symbol =  'Robot_leg_3_B.INPUT_2_1_1';
    
xcp.signals(69).symbol =  'Robot_leg_3_B.INPUT_30_1_1';
    
xcp.signals(70).symbol =  'Robot_leg_3_B.INPUT_30_1_2';
    
xcp.signals(71).symbol =  'Robot_leg_3_B.INPUT_30_1_3';
    
xcp.signals(72).symbol =  'Robot_leg_3_B.INPUT_31_1_1';
    
xcp.signals(73).symbol =  'Robot_leg_3_B.INPUT_31_1_2';
    
xcp.signals(74).symbol =  'Robot_leg_3_B.INPUT_31_1_3';
    
xcp.signals(75).symbol =  'Robot_leg_3_B.INPUT_32_1_1';
    
xcp.signals(76).symbol =  'Robot_leg_3_B.INPUT_32_1_2';
    
xcp.signals(77).symbol =  'Robot_leg_3_B.INPUT_32_1_3';
    
xcp.signals(78).symbol =  'Robot_leg_3_B.INPUT_33_1_1';
    
xcp.signals(79).symbol =  'Robot_leg_3_B.INPUT_33_1_2';
    
xcp.signals(80).symbol =  'Robot_leg_3_B.INPUT_33_1_3';
    
xcp.signals(81).symbol =  'Robot_leg_3_B.INPUT_34_1_1';
    
xcp.signals(82).symbol =  'Robot_leg_3_B.INPUT_34_1_2';
    
xcp.signals(83).symbol =  'Robot_leg_3_B.INPUT_34_1_3';
    
xcp.signals(84).symbol =  'Robot_leg_3_B.INPUT_35_1_1';
    
xcp.signals(85).symbol =  'Robot_leg_3_B.INPUT_35_1_2';
    
xcp.signals(86).symbol =  'Robot_leg_3_B.INPUT_35_1_3';
    
xcp.signals(87).symbol =  'Robot_leg_3_B.INPUT_36_1_1';
    
xcp.signals(88).symbol =  'Robot_leg_3_B.INPUT_36_1_2';
    
xcp.signals(89).symbol =  'Robot_leg_3_B.INPUT_36_1_3';
    
xcp.signals(90).symbol =  'Robot_leg_3_B.INPUT_37_1_1';
    
xcp.signals(91).symbol =  'Robot_leg_3_B.INPUT_37_1_2';
    
xcp.signals(92).symbol =  'Robot_leg_3_B.INPUT_37_1_3';
    
xcp.signals(93).symbol =  'Robot_leg_3_B.INPUT_38_1_1';
    
xcp.signals(94).symbol =  'Robot_leg_3_B.INPUT_38_1_2';
    
xcp.signals(95).symbol =  'Robot_leg_3_B.INPUT_38_1_3';
    
xcp.signals(96).symbol =  'Robot_leg_3_B.INPUT_39_1_1';
    
xcp.signals(97).symbol =  'Robot_leg_3_B.INPUT_39_1_2';
    
xcp.signals(98).symbol =  'Robot_leg_3_B.INPUT_39_1_3';
    
xcp.signals(99).symbol =  'Robot_leg_3_B.INPUT_3_1_1';
    
xcp.signals(100).symbol =  'Robot_leg_3_B.INPUT_40_1_1';
    
xcp.signals(101).symbol =  'Robot_leg_3_B.INPUT_40_1_2';
    
xcp.signals(102).symbol =  'Robot_leg_3_B.INPUT_40_1_3';
    
xcp.signals(103).symbol =  'Robot_leg_3_B.INPUT_41_1_1';
    
xcp.signals(104).symbol =  'Robot_leg_3_B.INPUT_41_1_2';
    
xcp.signals(105).symbol =  'Robot_leg_3_B.INPUT_41_1_3';
    
xcp.signals(106).symbol =  'Robot_leg_3_B.INPUT_42_1_1';
    
xcp.signals(107).symbol =  'Robot_leg_3_B.INPUT_42_1_2';
    
xcp.signals(108).symbol =  'Robot_leg_3_B.INPUT_42_1_3';
    
xcp.signals(109).symbol =  'Robot_leg_3_B.INPUT_43_1_1';
    
xcp.signals(110).symbol =  'Robot_leg_3_B.INPUT_43_1_2';
    
xcp.signals(111).symbol =  'Robot_leg_3_B.INPUT_43_1_3';
    
xcp.signals(112).symbol =  'Robot_leg_3_B.INPUT_44_1_1';
    
xcp.signals(113).symbol =  'Robot_leg_3_B.INPUT_44_1_2';
    
xcp.signals(114).symbol =  'Robot_leg_3_B.INPUT_44_1_3';
    
xcp.signals(115).symbol =  'Robot_leg_3_B.INPUT_4_1_1';
    
xcp.signals(116).symbol =  'Robot_leg_3_B.INPUT_5_1_1';
    
xcp.signals(117).symbol =  'Robot_leg_3_B.INPUT_6_1_1';
    
xcp.signals(118).symbol =  'Robot_leg_3_B.INPUT_7_1_1';
    
xcp.signals(119).symbol =  'Robot_leg_3_B.INPUT_7_1_2';
    
xcp.signals(120).symbol =  'Robot_leg_3_B.INPUT_7_1_3';
    
xcp.signals(121).symbol =  'Robot_leg_3_B.INPUT_8_1_1';
    
xcp.signals(122).symbol =  'Robot_leg_3_B.INPUT_8_1_2';
    
xcp.signals(123).symbol =  'Robot_leg_3_B.INPUT_8_1_3';
    
xcp.signals(124).symbol =  'Robot_leg_3_B.INPUT_9_1_1';
    
xcp.signals(125).symbol =  'Robot_leg_3_B.INPUT_9_1_2';
    
xcp.signals(126).symbol =  'Robot_leg_3_B.INPUT_9_1_3';
    
xcp.signals(127).symbol =  'Robot_leg_3_B.OUTPUT_1_0';
    
xcp.signals(128).symbol =  'Robot_leg_3_B.OUTPUT_1_1';
    
xcp.signals(129).symbol =  'Robot_leg_3_B.STATE_1';
    
xcp.signals(130).symbol =  'Robot_leg_3_B.Clock_o3';
    
xcp.signals(131).symbol =  'Robot_leg_3_B.Output_k';
    
xcp.signals(132).symbol =  'Robot_leg_3_B.LookUpTable1_j';
    
xcp.signals(133).symbol =  'Robot_leg_3_B.MathFunction_ma';
    
xcp.signals(134).symbol =  'Robot_leg_3_B.Sum_oc';
    
xcp.signals(135).symbol =  'Robot_leg_3_B.Clock_i';
    
xcp.signals(136).symbol =  'Robot_leg_3_B.Output_g0';
    
xcp.signals(137).symbol =  'Robot_leg_3_B.LookUpTable1_a';
    
xcp.signals(138).symbol =  'Robot_leg_3_B.MathFunction_n';
    
xcp.signals(139).symbol =  'Robot_leg_3_B.Sum_i';
    
xcp.signals(140).symbol =  'Robot_leg_3_B.Clock_m';
    
xcp.signals(141).symbol =  'Robot_leg_3_B.Output_og';
    
xcp.signals(142).symbol =  'Robot_leg_3_B.LookUpTable1_m';
    
xcp.signals(143).symbol =  'Robot_leg_3_B.MathFunction_jo2';
    
xcp.signals(144).symbol =  'Robot_leg_3_B.Sum_ge';
    
xcp.signals(145).symbol =  'Robot_leg_3_B.Clock_hj';
    
xcp.signals(146).symbol =  'Robot_leg_3_B.Output_ny';
    
xcp.signals(147).symbol =  'Robot_leg_3_B.LookUpTable1_g';
    
xcp.signals(148).symbol =  'Robot_leg_3_B.MathFunction_a';
    
xcp.signals(149).symbol =  'Robot_leg_3_B.Sum_a';
    
xcp.signals(150).symbol =  'Robot_leg_3_B.Clock_nd';
    
xcp.signals(151).symbol =  'Robot_leg_3_B.Output_gv';
    
xcp.signals(152).symbol =  'Robot_leg_3_B.LookUpTable1_n';
    
xcp.signals(153).symbol =  'Robot_leg_3_B.MathFunction_nm';
    
xcp.signals(154).symbol =  'Robot_leg_3_B.Sum_if';
    
xcp.signals(155).symbol =  'Robot_leg_3_B.Clock_by';
    
xcp.signals(156).symbol =  'Robot_leg_3_B.Output_o0';
    
xcp.signals(157).symbol =  'Robot_leg_3_B.LookUpTable1_j5';
    
xcp.signals(158).symbol =  'Robot_leg_3_B.MathFunction_i';
    
xcp.signals(159).symbol =  'Robot_leg_3_B.Sum_gn';
    
xcp.signals(160).symbol =  'Robot_leg_3_B.Clock_h';
    
xcp.signals(161).symbol =  'Robot_leg_3_B.Output_e';
    
xcp.signals(162).symbol =  'Robot_leg_3_B.LookUpTable1_h';
    
xcp.signals(163).symbol =  'Robot_leg_3_B.MathFunction_h';
    
xcp.signals(164).symbol =  'Robot_leg_3_B.Sum_gg';
    
xcp.signals(165).symbol =  'Robot_leg_3_B.Clock_n';
    
xcp.signals(166).symbol =  'Robot_leg_3_B.Output_js';
    
xcp.signals(167).symbol =  'Robot_leg_3_B.LookUpTable1_k';
    
xcp.signals(168).symbol =  'Robot_leg_3_B.MathFunction_m';
    
xcp.signals(169).symbol =  'Robot_leg_3_B.Sum_m';
    
xcp.signals(170).symbol =  'Robot_leg_3_B.Clock';
    
xcp.signals(171).symbol =  'Robot_leg_3_B.Output_dn';
    
xcp.signals(172).symbol =  'Robot_leg_3_B.LookUpTable1';
    
xcp.signals(173).symbol =  'Robot_leg_3_B.MathFunction';
    
xcp.signals(174).symbol =  'Robot_leg_3_B.Sum';
    
xcp.signals(175).symbol =  'Robot_leg_3_B.Clock_o';
    
xcp.signals(176).symbol =  'Robot_leg_3_B.Output_ju';
    
xcp.signals(177).symbol =  'Robot_leg_3_B.LookUpTable1_d';
    
xcp.signals(178).symbol =  'Robot_leg_3_B.MathFunction_jo';
    
xcp.signals(179).symbol =  'Robot_leg_3_B.Sum_l';
    
xcp.signals(180).symbol =  'Robot_leg_3_B.Clock_b';
    
xcp.signals(181).symbol =  'Robot_leg_3_B.Output_o2';
    
xcp.signals(182).symbol =  'Robot_leg_3_B.LookUpTable1_e';
    
xcp.signals(183).symbol =  'Robot_leg_3_B.MathFunction_j';
    
xcp.signals(184).symbol =  'Robot_leg_3_B.Sum_g';
    
xcp.signals(185).symbol =  'Robot_leg_3_B.Clock_p';
    
xcp.signals(186).symbol =  'Robot_leg_3_B.Output_ie';
    
xcp.signals(187).symbol =  'Robot_leg_3_B.LookUpTable1_c';
    
xcp.signals(188).symbol =  'Robot_leg_3_B.MathFunction_o';
    
xcp.signals(189).symbol =  'Robot_leg_3_B.Sum_k';
    
xcp.signals(190).symbol =  'Robot_leg_3_B.Clock_pm';
    
xcp.signals(191).symbol =  'Robot_leg_3_B.Output_nc';
    
xcp.signals(192).symbol =  'Robot_leg_3_B.LookUpTable1_ad';
    
xcp.signals(193).symbol =  'Robot_leg_3_B.MathFunction_na';
    
xcp.signals(194).symbol =  'Robot_leg_3_B.Sum_d';
    
xcp.signals(195).symbol =  'Robot_leg_3_B.Clock_c';
    
xcp.signals(196).symbol =  'Robot_leg_3_B.Output_d0';
    
xcp.signals(197).symbol =  'Robot_leg_3_B.LookUpTable1_j3';
    
xcp.signals(198).symbol =  'Robot_leg_3_B.MathFunction_g';
    
xcp.signals(199).symbol =  'Robot_leg_3_B.Sum_n';
    
xcp.signals(200).symbol =  'Robot_leg_3_B.Clock_ii';
    
xcp.signals(201).symbol =  'Robot_leg_3_B.Output_l2';
    
xcp.signals(202).symbol =  'Robot_leg_3_B.LookUpTable1_aq';
    
xcp.signals(203).symbol =  'Robot_leg_3_B.MathFunction_ia';
    
xcp.signals(204).symbol =  'Robot_leg_3_B.Sum_b';
    
xcp.signals(205).symbol =  'Robot_leg_3_B.Clock_br';
    
xcp.signals(206).symbol =  'Robot_leg_3_B.Output_ka';
    
xcp.signals(207).symbol =  'Robot_leg_3_B.LookUpTable1_f';
    
xcp.signals(208).symbol =  'Robot_leg_3_B.MathFunction_l';
    
xcp.signals(209).symbol =  'Robot_leg_3_B.Sum_e';
    
xcp.signals(210).symbol =  'Robot_leg_3_B.Clock_l';
    
xcp.signals(211).symbol =  'Robot_leg_3_B.Output_iv';
    
xcp.signals(212).symbol =  'Robot_leg_3_B.LookUpTable1_o';
    
xcp.signals(213).symbol =  'Robot_leg_3_B.MathFunction_k';
    
xcp.signals(214).symbol =  'Robot_leg_3_B.Sum_o2';
    
xcp.signals(215).symbol =  'Robot_leg_3_B.Clock_d';
    
xcp.signals(216).symbol =  'Robot_leg_3_B.Output_p';
    
xcp.signals(217).symbol =  'Robot_leg_3_B.LookUpTable1_i';
    
xcp.signals(218).symbol =  'Robot_leg_3_B.MathFunction_f';
    
xcp.signals(219).symbol =  'Robot_leg_3_B.Sum_f';
    
xcp.signals(220).symbol =  'Robot_leg_3_B.Clock_ha';
    
xcp.signals(221).symbol =  'Robot_leg_3_B.Output_j3';
    
xcp.signals(222).symbol =  'Robot_leg_3_B.LookUpTable1_fk';
    
xcp.signals(223).symbol =  'Robot_leg_3_B.MathFunction_id';
    
xcp.signals(224).symbol =  'Robot_leg_3_B.Sum_li';
    
xcp.signals(225).symbol =  'Robot_leg_3_B.Clock_oi';
    
xcp.signals(226).symbol =  'Robot_leg_3_B.Output_ja';
    
xcp.signals(227).symbol =  'Robot_leg_3_B.LookUpTable1_ef';
    
xcp.signals(228).symbol =  'Robot_leg_3_B.MathFunction_ln';
    
xcp.signals(229).symbol =  'Robot_leg_3_B.Sum_bf';
    
xcp.signals(230).symbol =  'Robot_leg_3_B.Clock_f';
    
xcp.signals(231).symbol =  'Robot_leg_3_B.Output_mg';
    
xcp.signals(232).symbol =  'Robot_leg_3_B.LookUpTable1_hu';
    
xcp.signals(233).symbol =  'Robot_leg_3_B.MathFunction_b';
    
xcp.signals(234).symbol =  'Robot_leg_3_B.Sum_iw';
    
xcp.signals(235).symbol =  'Robot_leg_3_B.Clock_hc';
    
xcp.signals(236).symbol =  'Robot_leg_3_B.Output_dz';
    
xcp.signals(237).symbol =  'Robot_leg_3_B.LookUpTable1_c3';
    
xcp.signals(238).symbol =  'Robot_leg_3_B.MathFunction_oa';
    
xcp.signals(239).symbol =  'Robot_leg_3_B.Sum_m4';
    
xcp.signals(240).symbol =  'Robot_leg_3_B.Clock_d1';
    
xcp.signals(241).symbol =  'Robot_leg_3_B.Output_am';
    
xcp.signals(242).symbol =  'Robot_leg_3_B.LookUpTable1_bf';
    
xcp.signals(243).symbol =  'Robot_leg_3_B.MathFunction_lu';
    
xcp.signals(244).symbol =  'Robot_leg_3_B.Sum_ko';
    
xcp.signals(245).symbol =  'Robot_leg_3_B.Clock_jy';
    
xcp.signals(246).symbol =  'Robot_leg_3_B.Output_f';
    
xcp.signals(247).symbol =  'Robot_leg_3_B.LookUpTable1_ku';
    
xcp.signals(248).symbol =  'Robot_leg_3_B.MathFunction_ad';
    
xcp.signals(249).symbol =  'Robot_leg_3_B.Sum_f0';
    
xcp.signals(250).symbol =  'Robot_leg_3_B.MathFunction_iy';
    
xcp.signals(251).symbol =  'Robot_leg_3_B.NormalForce_i';
    
xcp.signals(252).symbol =  'Robot_leg_3_B.Add1_i';
    
xcp.signals(253).symbol =  'Robot_leg_3_B.SumofElements_l';
    
xcp.signals(254).symbol =  'Robot_leg_3_B.FrictionForce_k';
    
xcp.signals(255).symbol =  'Robot_leg_3_B.FSph';
    
xcp.signals(256).symbol =  'Robot_leg_3_B.FSph_m';
    
xcp.signals(257).symbol =  'Robot_leg_3_B.FSph_l';
    
xcp.signals(258).symbol =  'Robot_leg_3_B.FSph_a';
    
xcp.signals(259).symbol =  'Robot_leg_3_B.Clock_gg';
    
xcp.signals(260).symbol =  'Robot_leg_3_B.Output_m';
    
xcp.signals(261).symbol =  'Robot_leg_3_B.LookUpTable1_fn';
    
xcp.signals(262).symbol =  'Robot_leg_3_B.MathFunction_ae';
    
xcp.signals(263).symbol =  'Robot_leg_3_B.Sum_cg';
    
xcp.signals(264).symbol =  'Robot_leg_3_B.Clock_pr';
    
xcp.signals(265).symbol =  'Robot_leg_3_B.Output_a';
    
xcp.signals(266).symbol =  'Robot_leg_3_B.LookUpTable1_kf';
    
xcp.signals(267).symbol =  'Robot_leg_3_B.MathFunction_ih';
    
xcp.signals(268).symbol =  'Robot_leg_3_B.Sum_ei';
    
xcp.signals(269).symbol =  'Robot_leg_3_B.Clock_b4';
    
xcp.signals(270).symbol =  'Robot_leg_3_B.Output_o';
    
xcp.signals(271).symbol =  'Robot_leg_3_B.LookUpTable1_m1';
    
xcp.signals(272).symbol =  'Robot_leg_3_B.MathFunction_j0';
    
xcp.signals(273).symbol =  'Robot_leg_3_B.Sum_dv';
    
xcp.signals(274).symbol =  'Robot_leg_3_B.Clock_cj';
    
xcp.signals(275).symbol =  'Robot_leg_3_B.Output_gk';
    
xcp.signals(276).symbol =  'Robot_leg_3_B.LookUpTable1_kfu';
    
xcp.signals(277).symbol =  'Robot_leg_3_B.MathFunction_du';
    
xcp.signals(278).symbol =  'Robot_leg_3_B.Sum_fz';
    
xcp.signals(279).symbol =  'Robot_leg_3_B.Clock_brf';
    
xcp.signals(280).symbol =  'Robot_leg_3_B.Output_g';
    
xcp.signals(281).symbol =  'Robot_leg_3_B.LookUpTable1_oe';
    
xcp.signals(282).symbol =  'Robot_leg_3_B.MathFunction_e';
    
xcp.signals(283).symbol =  'Robot_leg_3_B.Sum_g3';
    
xcp.signals(284).symbol =  'Robot_leg_3_B.Clock_gw';
    
xcp.signals(285).symbol =  'Robot_leg_3_B.Output_oy';
    
xcp.signals(286).symbol =  'Robot_leg_3_B.LookUpTable1_fw';
    
xcp.signals(287).symbol =  'Robot_leg_3_B.MathFunction_pw';
    
xcp.signals(288).symbol =  'Robot_leg_3_B.Sum_il';
    
xcp.signals(289).symbol =  'Robot_leg_3_B.Clock_bv';
    
xcp.signals(290).symbol =  'Robot_leg_3_B.Output_bw';
    
xcp.signals(291).symbol =  'Robot_leg_3_B.LookUpTable1_ky';
    
xcp.signals(292).symbol =  'Robot_leg_3_B.MathFunction_p3';
    
xcp.signals(293).symbol =  'Robot_leg_3_B.Sum_bfe';
    
xcp.signals(294).symbol =  'Robot_leg_3_B.Clock_g';
    
xcp.signals(295).symbol =  'Robot_leg_3_B.Output_h';
    
xcp.signals(296).symbol =  'Robot_leg_3_B.LookUpTable1_l';
    
xcp.signals(297).symbol =  'Robot_leg_3_B.MathFunction_p';
    
xcp.signals(298).symbol =  'Robot_leg_3_B.Sum_ml';
    
xcp.signals(299).symbol =  'Robot_leg_3_B.Clock_k';
    
xcp.signals(300).symbol =  'Robot_leg_3_B.Output_l';
    
xcp.signals(301).symbol =  'Robot_leg_3_B.LookUpTable1_bs';
    
xcp.signals(302).symbol =  'Robot_leg_3_B.MathFunction_ho';
    
xcp.signals(303).symbol =  'Robot_leg_3_B.Sum_de';
    
xcp.signals(304).symbol =  'Robot_leg_3_B.Clock_j2';
    
xcp.signals(305).symbol =  'Robot_leg_3_B.Output_b';
    
xcp.signals(306).symbol =  'Robot_leg_3_B.LookUpTable1_ho';
    
xcp.signals(307).symbol =  'Robot_leg_3_B.MathFunction_g1';
    
xcp.signals(308).symbol =  'Robot_leg_3_B.Sum_kb';
    
xcp.signals(309).symbol =  'Robot_leg_3_B.Clock_op';
    
xcp.signals(310).symbol =  'Robot_leg_3_B.Output_n';
    
xcp.signals(311).symbol =  'Robot_leg_3_B.LookUpTable1_ea';
    
xcp.signals(312).symbol =  'Robot_leg_3_B.MathFunction_p4';
    
xcp.signals(313).symbol =  'Robot_leg_3_B.Sum_c';
    
xcp.signals(314).symbol =  'Robot_leg_3_B.Clock_mx';
    
xcp.signals(315).symbol =  'Robot_leg_3_B.Output_i';
    
xcp.signals(316).symbol =  'Robot_leg_3_B.LookUpTable1_dq';
    
xcp.signals(317).symbol =  'Robot_leg_3_B.MathFunction_c';
    
xcp.signals(318).symbol =  'Robot_leg_3_B.Sum_au';
    
xcp.signals(319).symbol =  'Robot_leg_3_B.Clock_ic';
    
xcp.signals(320).symbol =  'Robot_leg_3_B.Output_go';
    
xcp.signals(321).symbol =  'Robot_leg_3_B.LookUpTable1_mg';
    
xcp.signals(322).symbol =  'Robot_leg_3_B.MathFunction_gx';
    
xcp.signals(323).symbol =  'Robot_leg_3_B.Sum_p';
    
xcp.signals(324).symbol =  'Robot_leg_3_B.Clock_ax';
    
xcp.signals(325).symbol =  'Robot_leg_3_B.Output_li';
    
xcp.signals(326).symbol =  'Robot_leg_3_B.LookUpTable1_gz';
    
xcp.signals(327).symbol =  'Robot_leg_3_B.MathFunction_d5';
    
xcp.signals(328).symbol =  'Robot_leg_3_B.Sum_np';
    
xcp.signals(329).symbol =  'Robot_leg_3_B.Clock_a';
    
xcp.signals(330).symbol =  'Robot_leg_3_B.Output_nv';
    
xcp.signals(331).symbol =  'Robot_leg_3_B.LookUpTable1_as';
    
xcp.signals(332).symbol =  'Robot_leg_3_B.MathFunction_ki';
    
xcp.signals(333).symbol =  'Robot_leg_3_B.Sum_j';
    
xcp.signals(334).symbol =  'Robot_leg_3_B.Clock_fa';
    
xcp.signals(335).symbol =  'Robot_leg_3_B.Output_bj';
    
xcp.signals(336).symbol =  'Robot_leg_3_B.LookUpTable1_bq';
    
xcp.signals(337).symbol =  'Robot_leg_3_B.MathFunction_ay';
    
xcp.signals(338).symbol =  'Robot_leg_3_B.Sum_kk';
    
xcp.signals(339).symbol =  'Robot_leg_3_B.Clock_li';
    
xcp.signals(340).symbol =  'Robot_leg_3_B.Output_gs';
    
xcp.signals(341).symbol =  'Robot_leg_3_B.LookUpTable1_c4';
    
xcp.signals(342).symbol =  'Robot_leg_3_B.MathFunction_dz';
    
xcp.signals(343).symbol =  'Robot_leg_3_B.Sum_kv';
    
xcp.signals(344).symbol =  'Robot_leg_3_B.Clock_jg';
    
xcp.signals(345).symbol =  'Robot_leg_3_B.Output_j';
    
xcp.signals(346).symbol =  'Robot_leg_3_B.LookUpTable1_e2';
    
xcp.signals(347).symbol =  'Robot_leg_3_B.MathFunction_es';
    
xcp.signals(348).symbol =  'Robot_leg_3_B.Sum_mw';
    
xcp.signals(349).symbol =  'Robot_leg_3_B.Clock_im';
    
xcp.signals(350).symbol =  'Robot_leg_3_B.Output_dc';
    
xcp.signals(351).symbol =  'Robot_leg_3_B.LookUpTable1_gn';
    
xcp.signals(352).symbol =  'Robot_leg_3_B.MathFunction_hz';
    
xcp.signals(353).symbol =  'Robot_leg_3_B.Sum_is';
    
xcp.signals(354).symbol =  'Robot_leg_3_B.Clock_ln';
    
xcp.signals(355).symbol =  'Robot_leg_3_B.Output_np';
    
xcp.signals(356).symbol =  'Robot_leg_3_B.LookUpTable1_an';
    
xcp.signals(357).symbol =  'Robot_leg_3_B.MathFunction_ko';
    
xcp.signals(358).symbol =  'Robot_leg_3_B.Sum_pl';
    
xcp.signals(359).symbol =  'Robot_leg_3_B.Clock_oq';
    
xcp.signals(360).symbol =  'Robot_leg_3_B.Output_d';
    
xcp.signals(361).symbol =  'Robot_leg_3_B.LookUpTable1_en';
    
xcp.signals(362).symbol =  'Robot_leg_3_B.MathFunction_gp';
    
xcp.signals(363).symbol =  'Robot_leg_3_B.Sum_h';
    
xcp.signals(364).symbol =  'Robot_leg_3_B.Clock_ju';
    
xcp.signals(365).symbol =  'Robot_leg_3_B.Output_hg';
    
xcp.signals(366).symbol =  'Robot_leg_3_B.LookUpTable1_nq';
    
xcp.signals(367).symbol =  'Robot_leg_3_B.MathFunction_h1';
    
xcp.signals(368).symbol =  'Robot_leg_3_B.Sum_ks';
    
xcp.signals(369).symbol =  'Robot_leg_3_B.Clock_c4';
    
xcp.signals(370).symbol =  'Robot_leg_3_B.Output_m0';
    
xcp.signals(371).symbol =  'Robot_leg_3_B.LookUpTable1_el';
    
xcp.signals(372).symbol =  'Robot_leg_3_B.MathFunction_bb';
    
xcp.signals(373).symbol =  'Robot_leg_3_B.Sum_du';
    
xcp.signals(374).symbol =  'Robot_leg_3_B.Clock_e';
    
xcp.signals(375).symbol =  'Robot_leg_3_B.Output_gb';
    
xcp.signals(376).symbol =  'Robot_leg_3_B.LookUpTable1_cv';
    
xcp.signals(377).symbol =  'Robot_leg_3_B.MathFunction_g2';
    
xcp.signals(378).symbol =  'Robot_leg_3_B.Sum_ed';
    
xcp.signals(379).symbol =  'Robot_leg_3_B.MathFunction_g0';
    
xcp.signals(380).symbol =  'Robot_leg_3_B.NormalForce';
    
xcp.signals(381).symbol =  'Robot_leg_3_B.Add1';
    
xcp.signals(382).symbol =  'Robot_leg_3_B.SumofElements';
    
xcp.signals(383).symbol =  'Robot_leg_3_B.FrictionForce';
    
xcp.signals(384).symbol =  'Robot_leg_3_B.FSph_i';
    
xcp.signals(385).symbol =  'Robot_leg_3_B.FSph_mf';
    
xcp.signals(386).symbol =  'Robot_leg_3_B.FSph_a0';
    
xcp.signals(387).symbol =  'Robot_leg_3_B.FSph_n';
    
xcp.signals(388).symbol =  'Robot_leg_3_B.Abs_f';
    
xcp.signals(389).symbol =  'Robot_leg_3_B.Abs1_k';
    
xcp.signals(390).symbol =  'Robot_leg_3_B.DataTypeConversion_a';
    
xcp.signals(391).symbol =  'Robot_leg_3_B.Gain_p1';
    
xcp.signals(392).symbol =  'Robot_leg_3_B.Gain1_b';
    
xcp.signals(393).symbol =  'Robot_leg_3_B.LogicalOperator_n';
    
xcp.signals(394).symbol =  'Robot_leg_3_B.Product_d';
    
xcp.signals(395).symbol =  'Robot_leg_3_B.FSph';
    
xcp.signals(396).symbol =  'Robot_leg_3_B.SprForce_ny';
    
xcp.signals(397).symbol =  'Robot_leg_3_B.DampForce_b';
    
xcp.signals(398).symbol =  'Robot_leg_3_B.FSph';
    
xcp.signals(399).symbol =  'Robot_leg_3_B.FPla_j';
    
xcp.signals(400).symbol =  'Robot_leg_3_B.FSph';
    
xcp.signals(401).symbol =  'Robot_leg_3_B.Abs_k';
    
xcp.signals(402).symbol =  'Robot_leg_3_B.Abs1_o2';
    
xcp.signals(403).symbol =  'Robot_leg_3_B.DataTypeConversion_p';
    
xcp.signals(404).symbol =  'Robot_leg_3_B.Gain_m';
    
xcp.signals(405).symbol =  'Robot_leg_3_B.Gain1_n';
    
xcp.signals(406).symbol =  'Robot_leg_3_B.LogicalOperator_k';
    
xcp.signals(407).symbol =  'Robot_leg_3_B.Product_m';
    
xcp.signals(408).symbol =  'Robot_leg_3_B.FSph_m';
    
xcp.signals(409).symbol =  'Robot_leg_3_B.SprForce_a';
    
xcp.signals(410).symbol =  'Robot_leg_3_B.DampForce_hs';
    
xcp.signals(411).symbol =  'Robot_leg_3_B.FSph_m';
    
xcp.signals(412).symbol =  'Robot_leg_3_B.FPla_p';
    
xcp.signals(413).symbol =  'Robot_leg_3_B.FSph_m';
    
xcp.signals(414).symbol =  'Robot_leg_3_B.Abs_n';
    
xcp.signals(415).symbol =  'Robot_leg_3_B.Abs1_n';
    
xcp.signals(416).symbol =  'Robot_leg_3_B.DataTypeConversion_b';
    
xcp.signals(417).symbol =  'Robot_leg_3_B.Gain_g';
    
xcp.signals(418).symbol =  'Robot_leg_3_B.Gain1_gi';
    
xcp.signals(419).symbol =  'Robot_leg_3_B.LogicalOperator_aj';
    
xcp.signals(420).symbol =  'Robot_leg_3_B.Product_e';
    
xcp.signals(421).symbol =  'Robot_leg_3_B.FSph_l';
    
xcp.signals(422).symbol =  'Robot_leg_3_B.SprForce_e';
    
xcp.signals(423).symbol =  'Robot_leg_3_B.DampForce_f';
    
xcp.signals(424).symbol =  'Robot_leg_3_B.FSph_l';
    
xcp.signals(425).symbol =  'Robot_leg_3_B.FPla_n';
    
xcp.signals(426).symbol =  'Robot_leg_3_B.FSph_l';
    
xcp.signals(427).symbol =  'Robot_leg_3_B.Abs_ff';
    
xcp.signals(428).symbol =  'Robot_leg_3_B.Abs1_b';
    
xcp.signals(429).symbol =  'Robot_leg_3_B.DataTypeConversion_bu';
    
xcp.signals(430).symbol =  'Robot_leg_3_B.Gain_m5';
    
xcp.signals(431).symbol =  'Robot_leg_3_B.Gain1_c';
    
xcp.signals(432).symbol =  'Robot_leg_3_B.LogicalOperator_nt';
    
xcp.signals(433).symbol =  'Robot_leg_3_B.Product_j';
    
xcp.signals(434).symbol =  'Robot_leg_3_B.FSph_a';
    
xcp.signals(435).symbol =  'Robot_leg_3_B.SprForce_m';
    
xcp.signals(436).symbol =  'Robot_leg_3_B.DampForce_n';
    
xcp.signals(437).symbol =  'Robot_leg_3_B.FSph_a';
    
xcp.signals(438).symbol =  'Robot_leg_3_B.FPla_d';
    
xcp.signals(439).symbol =  'Robot_leg_3_B.FSph_a';
    
xcp.signals(440).symbol =  'Robot_leg_3_B.Abs';
    
xcp.signals(441).symbol =  'Robot_leg_3_B.Abs1';
    
xcp.signals(442).symbol =  'Robot_leg_3_B.DataTypeConversion';
    
xcp.signals(443).symbol =  'Robot_leg_3_B.Gain';
    
xcp.signals(444).symbol =  'Robot_leg_3_B.Gain1';
    
xcp.signals(445).symbol =  'Robot_leg_3_B.LogicalOperator';
    
xcp.signals(446).symbol =  'Robot_leg_3_B.Product';
    
xcp.signals(447).symbol =  'Robot_leg_3_B.FSph_i';
    
xcp.signals(448).symbol =  'Robot_leg_3_B.SprForce_p';
    
xcp.signals(449).symbol =  'Robot_leg_3_B.DampForce_h';
    
xcp.signals(450).symbol =  'Robot_leg_3_B.FSph_i';
    
xcp.signals(451).symbol =  'Robot_leg_3_B.FPla_h';
    
xcp.signals(452).symbol =  'Robot_leg_3_B.FSph_i';
    
xcp.signals(453).symbol =  'Robot_leg_3_B.Abs_g';
    
xcp.signals(454).symbol =  'Robot_leg_3_B.Abs1_o';
    
xcp.signals(455).symbol =  'Robot_leg_3_B.DataTypeConversion_m';
    
xcp.signals(456).symbol =  'Robot_leg_3_B.Gain_f';
    
xcp.signals(457).symbol =  'Robot_leg_3_B.Gain1_g';
    
xcp.signals(458).symbol =  'Robot_leg_3_B.LogicalOperator_a';
    
xcp.signals(459).symbol =  'Robot_leg_3_B.Product_g';
    
xcp.signals(460).symbol =  'Robot_leg_3_B.FSph_mf';
    
xcp.signals(461).symbol =  'Robot_leg_3_B.SprForce_n';
    
xcp.signals(462).symbol =  'Robot_leg_3_B.DampForce_c';
    
xcp.signals(463).symbol =  'Robot_leg_3_B.FSph_mf';
    
xcp.signals(464).symbol =  'Robot_leg_3_B.FPla_a';
    
xcp.signals(465).symbol =  'Robot_leg_3_B.FSph_mf';
    
xcp.signals(466).symbol =  'Robot_leg_3_B.Abs_e';
    
xcp.signals(467).symbol =  'Robot_leg_3_B.Abs1_d';
    
xcp.signals(468).symbol =  'Robot_leg_3_B.DataTypeConversion_mc';
    
xcp.signals(469).symbol =  'Robot_leg_3_B.Gain_j';
    
xcp.signals(470).symbol =  'Robot_leg_3_B.Gain1_j';
    
xcp.signals(471).symbol =  'Robot_leg_3_B.LogicalOperator_l';
    
xcp.signals(472).symbol =  'Robot_leg_3_B.Product_k';
    
xcp.signals(473).symbol =  'Robot_leg_3_B.FSph_a0';
    
xcp.signals(474).symbol =  'Robot_leg_3_B.SprForce_j';
    
xcp.signals(475).symbol =  'Robot_leg_3_B.DampForce_j';
    
xcp.signals(476).symbol =  'Robot_leg_3_B.FSph_a0';
    
xcp.signals(477).symbol =  'Robot_leg_3_B.FPla_o';
    
xcp.signals(478).symbol =  'Robot_leg_3_B.FSph_a0';
    
xcp.signals(479).symbol =  'Robot_leg_3_B.Abs_d';
    
xcp.signals(480).symbol =  'Robot_leg_3_B.Abs1_l';
    
xcp.signals(481).symbol =  'Robot_leg_3_B.DataTypeConversion_l';
    
xcp.signals(482).symbol =  'Robot_leg_3_B.Gain_p';
    
xcp.signals(483).symbol =  'Robot_leg_3_B.Gain1_o';
    
xcp.signals(484).symbol =  'Robot_leg_3_B.LogicalOperator_e';
    
xcp.signals(485).symbol =  'Robot_leg_3_B.Product_f';
    
xcp.signals(486).symbol =  'Robot_leg_3_B.FSph_n';
    
xcp.signals(487).symbol =  'Robot_leg_3_B.SprForce';
    
xcp.signals(488).symbol =  'Robot_leg_3_B.DampForce';
    
xcp.signals(489).symbol =  'Robot_leg_3_B.FSph_n';
    
xcp.signals(490).symbol =  'Robot_leg_3_B.FPla';
    
xcp.signals(491).symbol =  'Robot_leg_3_B.FSph_n';
    
xcp.signals(492).symbol =  'Robot_leg_3_B.GAIN_m';
    
xcp.signals(493).symbol =  'Robot_leg_3_B.GAIN_b';
    
xcp.signals(494).symbol =  'Robot_leg_3_B.GAIN_dq';
    
xcp.signals(495).symbol =  'Robot_leg_3_B.GAIN_hq';
    
xcp.signals(496).symbol =  'Robot_leg_3_B.GAIN_eg';
    
xcp.signals(497).symbol =  'Robot_leg_3_B.GAIN_em';
    
xcp.signals(498).symbol =  'Robot_leg_3_B.Compare_n1';
    
xcp.signals(499).symbol =  'Robot_leg_3_B.Compare_k';
    
xcp.signals(500).symbol =  'Robot_leg_3_B.Abs_ky';
    
xcp.signals(501).symbol =  'Robot_leg_3_B.DeadZone_ko';
    
xcp.signals(502).symbol =  'Robot_leg_3_B.Gain2_l';
    
xcp.signals(503).symbol =  'Robot_leg_3_B.Product_g0';
    
xcp.signals(504).symbol =  'Robot_leg_3_B.Signvx_ax';
    
xcp.signals(505).symbol =  'Robot_leg_3_B.Signx_l2';
    
xcp.signals(506).symbol =  'Robot_leg_3_B.Sum_l4';
    
xcp.signals(507).symbol =  'Robot_leg_3_B.Product_mw';
    
xcp.signals(508).symbol =  'Robot_leg_3_B.Product1_oq';
    
xcp.signals(509).symbol =  'Robot_leg_3_B.Product2_f';
    
xcp.signals(510).symbol =  'Robot_leg_3_B.Product3_ax';
    
xcp.signals(511).symbol =  'Robot_leg_3_B.Product4_ab';
    
xcp.signals(512).symbol =  'Robot_leg_3_B.Product5_gg';
    
xcp.signals(513).symbol =  'Robot_leg_3_B.FSph';
    
xcp.signals(514).symbol =  'Robot_leg_3_B.FSph';
    
xcp.signals(515).symbol =  'Robot_leg_3_B.FSph';
    
xcp.signals(516).symbol =  'Robot_leg_3_B.Gain_h';
    
xcp.signals(517).symbol =  'Robot_leg_3_B.Product1_e';
    
xcp.signals(518).symbol =  'Robot_leg_3_B.FSph';
    
xcp.signals(519).symbol =  'Robot_leg_3_B.Product3_bw';
    
xcp.signals(520).symbol =  'Robot_leg_3_B.Product4_at';
    
xcp.signals(521).symbol =  'Robot_leg_3_B.Product5_mo';
    
xcp.signals(522).symbol =  'Robot_leg_3_B.Product6_a';
    
xcp.signals(523).symbol =  'Robot_leg_3_B.Product7_c';
    
xcp.signals(524).symbol =  'Robot_leg_3_B.TrigonometricFunction_lx';
    
xcp.signals(525).symbol =  'Robot_leg_3_B.TrigonometricFunction1_oc';
    
xcp.signals(526).symbol =  'Robot_leg_3_B.Gain_em';
    
xcp.signals(527).symbol =  'Robot_leg_3_B.Product2_g';
    
xcp.signals(528).symbol =  'Robot_leg_3_B.Sum_bz';
    
xcp.signals(529).symbol =  'Robot_leg_3_B.Compare_nc';
    
xcp.signals(530).symbol =  'Robot_leg_3_B.Compare_j';
    
xcp.signals(531).symbol =  'Robot_leg_3_B.Abs_kv';
    
xcp.signals(532).symbol =  'Robot_leg_3_B.DeadZone_l';
    
xcp.signals(533).symbol =  'Robot_leg_3_B.Gain2_f';
    
xcp.signals(534).symbol =  'Robot_leg_3_B.Product_gr';
    
xcp.signals(535).symbol =  'Robot_leg_3_B.Signvx_p';
    
xcp.signals(536).symbol =  'Robot_leg_3_B.Signx_j';
    
xcp.signals(537).symbol =  'Robot_leg_3_B.Sum_la';
    
xcp.signals(538).symbol =  'Robot_leg_3_B.Product_jf';
    
xcp.signals(539).symbol =  'Robot_leg_3_B.Product1_l';
    
xcp.signals(540).symbol =  'Robot_leg_3_B.Product2_jh';
    
xcp.signals(541).symbol =  'Robot_leg_3_B.Product3_ep';
    
xcp.signals(542).symbol =  'Robot_leg_3_B.Product4_o';
    
xcp.signals(543).symbol =  'Robot_leg_3_B.Product5_np';
    
xcp.signals(544).symbol =  'Robot_leg_3_B.FSph_m';
    
xcp.signals(545).symbol =  'Robot_leg_3_B.FSph_m';
    
xcp.signals(546).symbol =  'Robot_leg_3_B.FSph_m';
    
xcp.signals(547).symbol =  'Robot_leg_3_B.Gain_d1';
    
xcp.signals(548).symbol =  'Robot_leg_3_B.Product1_o4';
    
xcp.signals(549).symbol =  'Robot_leg_3_B.FSph_m';
    
xcp.signals(550).symbol =  'Robot_leg_3_B.Product3_ab';
    
xcp.signals(551).symbol =  'Robot_leg_3_B.Product4_j';
    
xcp.signals(552).symbol =  'Robot_leg_3_B.Product5_is';
    
xcp.signals(553).symbol =  'Robot_leg_3_B.Product6_b';
    
xcp.signals(554).symbol =  'Robot_leg_3_B.Product7_j';
    
xcp.signals(555).symbol =  'Robot_leg_3_B.TrigonometricFunction_jh';
    
xcp.signals(556).symbol =  'Robot_leg_3_B.TrigonometricFunction1_n';
    
xcp.signals(557).symbol =  'Robot_leg_3_B.Gain_fu';
    
xcp.signals(558).symbol =  'Robot_leg_3_B.Product2_ib';
    
xcp.signals(559).symbol =  'Robot_leg_3_B.Sum_aw';
    
xcp.signals(560).symbol =  'Robot_leg_3_B.Compare_p';
    
xcp.signals(561).symbol =  'Robot_leg_3_B.Compare_a';
    
xcp.signals(562).symbol =  'Robot_leg_3_B.Abs_b';
    
xcp.signals(563).symbol =  'Robot_leg_3_B.DeadZone_k';
    
xcp.signals(564).symbol =  'Robot_leg_3_B.Gain2_b';
    
xcp.signals(565).symbol =  'Robot_leg_3_B.Product_if';
    
xcp.signals(566).symbol =  'Robot_leg_3_B.Signvx_h';
    
xcp.signals(567).symbol =  'Robot_leg_3_B.Signx_e';
    
xcp.signals(568).symbol =  'Robot_leg_3_B.Sum_j4';
    
xcp.signals(569).symbol =  'Robot_leg_3_B.Product_fd';
    
xcp.signals(570).symbol =  'Robot_leg_3_B.Product1_ij';
    
xcp.signals(571).symbol =  'Robot_leg_3_B.Product2_e';
    
xcp.signals(572).symbol =  'Robot_leg_3_B.Product3_ma';
    
xcp.signals(573).symbol =  'Robot_leg_3_B.Product4_ae';
    
xcp.signals(574).symbol =  'Robot_leg_3_B.Product5_jh';
    
xcp.signals(575).symbol =  'Robot_leg_3_B.FSph_l';
    
xcp.signals(576).symbol =  'Robot_leg_3_B.FSph_l';
    
xcp.signals(577).symbol =  'Robot_leg_3_B.FSph_l';
    
xcp.signals(578).symbol =  'Robot_leg_3_B.Gain_ib';
    
xcp.signals(579).symbol =  'Robot_leg_3_B.Product1_m';
    
xcp.signals(580).symbol =  'Robot_leg_3_B.FSph_l';
    
xcp.signals(581).symbol =  'Robot_leg_3_B.Product3_kn';
    
xcp.signals(582).symbol =  'Robot_leg_3_B.Product4_iys';
    
xcp.signals(583).symbol =  'Robot_leg_3_B.Product5_jn';
    
xcp.signals(584).symbol =  'Robot_leg_3_B.Product6_c';
    
xcp.signals(585).symbol =  'Robot_leg_3_B.Product7_bi';
    
xcp.signals(586).symbol =  'Robot_leg_3_B.TrigonometricFunction_iw';
    
xcp.signals(587).symbol =  'Robot_leg_3_B.TrigonometricFunction1_dl';
    
xcp.signals(588).symbol =  'Robot_leg_3_B.Gain_ar';
    
xcp.signals(589).symbol =  'Robot_leg_3_B.Product2_d';
    
xcp.signals(590).symbol =  'Robot_leg_3_B.Sum_iz';
    
xcp.signals(591).symbol =  'Robot_leg_3_B.Compare_aq';
    
xcp.signals(592).symbol =  'Robot_leg_3_B.Compare_i';
    
xcp.signals(593).symbol =  'Robot_leg_3_B.Abs_g4';
    
xcp.signals(594).symbol =  'Robot_leg_3_B.DeadZone_ap';
    
xcp.signals(595).symbol =  'Robot_leg_3_B.Gain2_e';
    
xcp.signals(596).symbol =  'Robot_leg_3_B.Product_gy';
    
xcp.signals(597).symbol =  'Robot_leg_3_B.Signvx_l';
    
xcp.signals(598).symbol =  'Robot_leg_3_B.Signx_lq';
    
xcp.signals(599).symbol =  'Robot_leg_3_B.Sum_eb';
    
xcp.signals(600).symbol =  'Robot_leg_3_B.Product_a4';
    
xcp.signals(601).symbol =  'Robot_leg_3_B.Product1_hn';
    
xcp.signals(602).symbol =  'Robot_leg_3_B.Product2_k';
    
xcp.signals(603).symbol =  'Robot_leg_3_B.Product3_k';
    
xcp.signals(604).symbol =  'Robot_leg_3_B.Product4_ku';
    
xcp.signals(605).symbol =  'Robot_leg_3_B.Product5_ae';
    
xcp.signals(606).symbol =  'Robot_leg_3_B.FSph_a';
    
xcp.signals(607).symbol =  'Robot_leg_3_B.FSph_a';
    
xcp.signals(608).symbol =  'Robot_leg_3_B.FSph_a';
    
xcp.signals(609).symbol =  'Robot_leg_3_B.Gain_e';
    
xcp.signals(610).symbol =  'Robot_leg_3_B.Product1_km';
    
xcp.signals(611).symbol =  'Robot_leg_3_B.FSph_a';
    
xcp.signals(612).symbol =  'Robot_leg_3_B.Product3_dh';
    
xcp.signals(613).symbol =  'Robot_leg_3_B.Product4_k5';
    
xcp.signals(614).symbol =  'Robot_leg_3_B.Product5_a';
    
xcp.signals(615).symbol =  'Robot_leg_3_B.Product6_p';
    
xcp.signals(616).symbol =  'Robot_leg_3_B.Product7_f';
    
xcp.signals(617).symbol =  'Robot_leg_3_B.TrigonometricFunction_h';
    
xcp.signals(618).symbol =  'Robot_leg_3_B.TrigonometricFunction1_d';
    
xcp.signals(619).symbol =  'Robot_leg_3_B.Gain_d';
    
xcp.signals(620).symbol =  'Robot_leg_3_B.Product2_ld';
    
xcp.signals(621).symbol =  'Robot_leg_3_B.Sum_jg';
    
xcp.signals(622).symbol =  'Robot_leg_3_B.GAIN_hs';
    
xcp.signals(623).symbol =  'Robot_leg_3_B.GAIN_h';
    
xcp.signals(624).symbol =  'Robot_leg_3_B.GAIN_e';
    
xcp.signals(625).symbol =  'Robot_leg_3_B.GAIN_i';
    
xcp.signals(626).symbol =  'Robot_leg_3_B.GAIN_d';
    
xcp.signals(627).symbol =  'Robot_leg_3_B.GAIN_p';
    
xcp.signals(628).symbol =  'Robot_leg_3_B.Compare';
    
xcp.signals(629).symbol =  'Robot_leg_3_B.Compare_n';
    
xcp.signals(630).symbol =  'Robot_leg_3_B.Abs_a';
    
xcp.signals(631).symbol =  'Robot_leg_3_B.DeadZone_e';
    
xcp.signals(632).symbol =  'Robot_leg_3_B.Gain2_k';
    
xcp.signals(633).symbol =  'Robot_leg_3_B.Product_br';
    
xcp.signals(634).symbol =  'Robot_leg_3_B.Signvx_e';
    
xcp.signals(635).symbol =  'Robot_leg_3_B.Signx_h';
    
xcp.signals(636).symbol =  'Robot_leg_3_B.Sum_p0';
    
xcp.signals(637).symbol =  'Robot_leg_3_B.Product_np';
    
xcp.signals(638).symbol =  'Robot_leg_3_B.Product1_cpr';
    
xcp.signals(639).symbol =  'Robot_leg_3_B.Product2_i';
    
xcp.signals(640).symbol =  'Robot_leg_3_B.Product3_gk';
    
xcp.signals(641).symbol =  'Robot_leg_3_B.Product4_p4';
    
xcp.signals(642).symbol =  'Robot_leg_3_B.Product5_k';
    
xcp.signals(643).symbol =  'Robot_leg_3_B.FSph_i';
    
xcp.signals(644).symbol =  'Robot_leg_3_B.FSph_i';
    
xcp.signals(645).symbol =  'Robot_leg_3_B.FSph_i';
    
xcp.signals(646).symbol =  'Robot_leg_3_B.Gain_jd';
    
xcp.signals(647).symbol =  'Robot_leg_3_B.Product1_oi';
    
xcp.signals(648).symbol =  'Robot_leg_3_B.FSph_i';
    
xcp.signals(649).symbol =  'Robot_leg_3_B.Product3_l1';
    
xcp.signals(650).symbol =  'Robot_leg_3_B.Product4_a';
    
xcp.signals(651).symbol =  'Robot_leg_3_B.Product5_ij';
    
xcp.signals(652).symbol =  'Robot_leg_3_B.Product6_l';
    
xcp.signals(653).symbol =  'Robot_leg_3_B.Product7_b';
    
xcp.signals(654).symbol =  'Robot_leg_3_B.TrigonometricFunction_c';
    
xcp.signals(655).symbol =  'Robot_leg_3_B.TrigonometricFunction1_k';
    
xcp.signals(656).symbol =  'Robot_leg_3_B.Gain_i';
    
xcp.signals(657).symbol =  'Robot_leg_3_B.Product2_j2';
    
xcp.signals(658).symbol =  'Robot_leg_3_B.Sum_kge';
    
xcp.signals(659).symbol =  'Robot_leg_3_B.Compare_o';
    
xcp.signals(660).symbol =  'Robot_leg_3_B.Compare_m';
    
xcp.signals(661).symbol =  'Robot_leg_3_B.Abs_db';
    
xcp.signals(662).symbol =  'Robot_leg_3_B.DeadZone_a';
    
xcp.signals(663).symbol =  'Robot_leg_3_B.Gain2_m';
    
xcp.signals(664).symbol =  'Robot_leg_3_B.Product_jh';
    
xcp.signals(665).symbol =  'Robot_leg_3_B.Signvx_c';
    
xcp.signals(666).symbol =  'Robot_leg_3_B.Signx_o';
    
xcp.signals(667).symbol =  'Robot_leg_3_B.Sum_pm';
    
xcp.signals(668).symbol =  'Robot_leg_3_B.Product_o';
    
xcp.signals(669).symbol =  'Robot_leg_3_B.Product1_k';
    
xcp.signals(670).symbol =  'Robot_leg_3_B.Product2_h';
    
xcp.signals(671).symbol =  'Robot_leg_3_B.Product3_n';
    
xcp.signals(672).symbol =  'Robot_leg_3_B.Product4_ew';
    
xcp.signals(673).symbol =  'Robot_leg_3_B.Product5_n';
    
xcp.signals(674).symbol =  'Robot_leg_3_B.FSph_mf';
    
xcp.signals(675).symbol =  'Robot_leg_3_B.FSph_mf';
    
xcp.signals(676).symbol =  'Robot_leg_3_B.FSph_mf';
    
xcp.signals(677).symbol =  'Robot_leg_3_B.Gain_ph';
    
xcp.signals(678).symbol =  'Robot_leg_3_B.Product1_o';
    
xcp.signals(679).symbol =  'Robot_leg_3_B.FSph_mf';
    
xcp.signals(680).symbol =  'Robot_leg_3_B.Product3_gs';
    
xcp.signals(681).symbol =  'Robot_leg_3_B.Product4_d';
    
xcp.signals(682).symbol =  'Robot_leg_3_B.Product5_m';
    
xcp.signals(683).symbol =  'Robot_leg_3_B.Product6_d';
    
xcp.signals(684).symbol =  'Robot_leg_3_B.Product7_p';
    
xcp.signals(685).symbol =  'Robot_leg_3_B.TrigonometricFunction_js';
    
xcp.signals(686).symbol =  'Robot_leg_3_B.TrigonometricFunction1_o';
    
xcp.signals(687).symbol =  'Robot_leg_3_B.Gain_a';
    
xcp.signals(688).symbol =  'Robot_leg_3_B.Product2_hxv';
    
xcp.signals(689).symbol =  'Robot_leg_3_B.Sum_o3';
    
xcp.signals(690).symbol =  'Robot_leg_3_B.Compare_l';
    
xcp.signals(691).symbol =  'Robot_leg_3_B.Compare_g';
    
xcp.signals(692).symbol =  'Robot_leg_3_B.Abs_i';
    
xcp.signals(693).symbol =  'Robot_leg_3_B.DeadZone_b';
    
xcp.signals(694).symbol =  'Robot_leg_3_B.Gain2_g';
    
xcp.signals(695).symbol =  'Robot_leg_3_B.Product_i';
    
xcp.signals(696).symbol =  'Robot_leg_3_B.Signvx_a';
    
xcp.signals(697).symbol =  'Robot_leg_3_B.Signx_l';
    
xcp.signals(698).symbol =  'Robot_leg_3_B.Sum_lb';
    
xcp.signals(699).symbol =  'Robot_leg_3_B.Product_n';
    
xcp.signals(700).symbol =  'Robot_leg_3_B.Product1_h';
    
xcp.signals(701).symbol =  'Robot_leg_3_B.Product2_o';
    
xcp.signals(702).symbol =  'Robot_leg_3_B.Product3_h';
    
xcp.signals(703).symbol =  'Robot_leg_3_B.Product4_e';
    
xcp.signals(704).symbol =  'Robot_leg_3_B.Product5_jd';
    
xcp.signals(705).symbol =  'Robot_leg_3_B.FSph_a0';
    
xcp.signals(706).symbol =  'Robot_leg_3_B.FSph_a0';
    
xcp.signals(707).symbol =  'Robot_leg_3_B.FSph_a0';
    
xcp.signals(708).symbol =  'Robot_leg_3_B.Gain_cp';
    
xcp.signals(709).symbol =  'Robot_leg_3_B.Product1_cp';
    
xcp.signals(710).symbol =  'Robot_leg_3_B.FSph_a0';
    
xcp.signals(711).symbol =  'Robot_leg_3_B.Product3_l';
    
xcp.signals(712).symbol =  'Robot_leg_3_B.Product4_po';
    
xcp.signals(713).symbol =  'Robot_leg_3_B.Product5_ha';
    
xcp.signals(714).symbol =  'Robot_leg_3_B.Product6_g';
    
xcp.signals(715).symbol =  'Robot_leg_3_B.Product7_a';
    
xcp.signals(716).symbol =  'Robot_leg_3_B.TrigonometricFunction_j';
    
xcp.signals(717).symbol =  'Robot_leg_3_B.TrigonometricFunction1_g';
    
xcp.signals(718).symbol =  'Robot_leg_3_B.Gain_c';
    
xcp.signals(719).symbol =  'Robot_leg_3_B.Product2_m';
    
xcp.signals(720).symbol =  'Robot_leg_3_B.Sum_kg';
    
xcp.signals(721).symbol =  'Robot_leg_3_B.Compare_b';
    
xcp.signals(722).symbol =  'Robot_leg_3_B.Compare_f';
    
xcp.signals(723).symbol =  'Robot_leg_3_B.Abs_c';
    
xcp.signals(724).symbol =  'Robot_leg_3_B.DeadZone';
    
xcp.signals(725).symbol =  'Robot_leg_3_B.Gain2';
    
xcp.signals(726).symbol =  'Robot_leg_3_B.Product_b';
    
xcp.signals(727).symbol =  'Robot_leg_3_B.Signvx';
    
xcp.signals(728).symbol =  'Robot_leg_3_B.Signx';
    
xcp.signals(729).symbol =  'Robot_leg_3_B.Sum_mlb';
    
xcp.signals(730).symbol =  'Robot_leg_3_B.Product_jb';
    
xcp.signals(731).symbol =  'Robot_leg_3_B.Product1';
    
xcp.signals(732).symbol =  'Robot_leg_3_B.Product2';
    
xcp.signals(733).symbol =  'Robot_leg_3_B.Product3_m';
    
xcp.signals(734).symbol =  'Robot_leg_3_B.Product4_b';
    
xcp.signals(735).symbol =  'Robot_leg_3_B.Product5_h';
    
xcp.signals(736).symbol =  'Robot_leg_3_B.FSph_n';
    
xcp.signals(737).symbol =  'Robot_leg_3_B.FSph_n';
    
xcp.signals(738).symbol =  'Robot_leg_3_B.FSph_n';
    
xcp.signals(739).symbol =  'Robot_leg_3_B.Gain_b';
    
xcp.signals(740).symbol =  'Robot_leg_3_B.Product1_i';
    
xcp.signals(741).symbol =  'Robot_leg_3_B.FSph_n';
    
xcp.signals(742).symbol =  'Robot_leg_3_B.Product3_g';
    
xcp.signals(743).symbol =  'Robot_leg_3_B.Product4_k';
    
xcp.signals(744).symbol =  'Robot_leg_3_B.Product5';
    
xcp.signals(745).symbol =  'Robot_leg_3_B.Product6';
    
xcp.signals(746).symbol =  'Robot_leg_3_B.Product7';
    
xcp.signals(747).symbol =  'Robot_leg_3_B.TrigonometricFunction_d';
    
xcp.signals(748).symbol =  'Robot_leg_3_B.TrigonometricFunction1';
    
xcp.signals(749).symbol =  'Robot_leg_3_B.Gain_mv';
    
xcp.signals(750).symbol =  'Robot_leg_3_B.Product2_j';
    
xcp.signals(751).symbol =  'Robot_leg_3_B.Sum_kn';
    
xcp.signals(752).symbol =  'Robot_leg_3_B.Product_ms';
    
xcp.signals(753).symbol =  'Robot_leg_3_B.Product1_kj';
    
xcp.signals(754).symbol =  'Robot_leg_3_B.Product2_i1';
    
xcp.signals(755).symbol =  'Robot_leg_3_B.Product3_ny';
    
xcp.signals(756).symbol =  'Robot_leg_3_B.Product4_d1';
    
xcp.signals(757).symbol =  'Robot_leg_3_B.Product5_i3';
    
xcp.signals(758).symbol =  'Robot_leg_3_B.Sum_iwg';
    
xcp.signals(759).symbol =  'Robot_leg_3_B.Sum1_f';
    
xcp.signals(760).symbol =  'Robot_leg_3_B.Sum2_k';
    
xcp.signals(761).symbol =  'Robot_leg_3_B.MathFunction_gn';
    
xcp.signals(762).symbol =  'Robot_leg_3_B.MathFunction1_aw';
    
xcp.signals(763).symbol =  'Robot_leg_3_B.Product3_nd';
    
xcp.signals(764).symbol =  'Robot_leg_3_B.Product4_m';
    
xcp.signals(765).symbol =  'Robot_leg_3_B.slipy_j';
    
xcp.signals(766).symbol =  'Robot_leg_3_B.slipx_p';
    
xcp.signals(767).symbol =  'Robot_leg_3_B.Sum3_dn';
    
xcp.signals(768).symbol =  'Robot_leg_3_B.TrigonometricFunction_pg';
    
xcp.signals(769).symbol =  'Robot_leg_3_B.Sqrt_o';
    
xcp.signals(770).symbol =  'Robot_leg_3_B.Damping_Force_Enable_o';
    
xcp.signals(771).symbol =  'Robot_leg_3_B.Stiffness_Force_k0';
    
xcp.signals(772).symbol =  'Robot_leg_3_B.Damping_Force_l';
    
xcp.signals(773).symbol =  'Robot_leg_3_B.Damping_Force_d2';
    
xcp.signals(774).symbol =  'Robot_leg_3_B.Saturation_dc';
    
xcp.signals(775).symbol =  'Robot_leg_3_B.Sign_kv';
    
xcp.signals(776).symbol =  'Robot_leg_3_B.RESHAPE_l';
    
xcp.signals(777).symbol =  'Robot_leg_3_B.Product_n4';
    
xcp.signals(778).symbol =  'Robot_leg_3_B.Product1_g';
    
xcp.signals(779).symbol =  'Robot_leg_3_B.Product2_ox';
    
xcp.signals(780).symbol =  'Robot_leg_3_B.Product3_in';
    
xcp.signals(781).symbol =  'Robot_leg_3_B.Product4_fk';
    
xcp.signals(782).symbol =  'Robot_leg_3_B.Product5_id';
    
xcp.signals(783).symbol =  'Robot_leg_3_B.Sum_d0';
    
xcp.signals(784).symbol =  'Robot_leg_3_B.Sum1_o';
    
xcp.signals(785).symbol =  'Robot_leg_3_B.Sum2_j';
    
xcp.signals(786).symbol =  'Robot_leg_3_B.MathFunction_ke';
    
xcp.signals(787).symbol =  'Robot_leg_3_B.MathFunction1_p';
    
xcp.signals(788).symbol =  'Robot_leg_3_B.Product3_c3';
    
xcp.signals(789).symbol =  'Robot_leg_3_B.Product4_bh';
    
xcp.signals(790).symbol =  'Robot_leg_3_B.slipy_n';
    
xcp.signals(791).symbol =  'Robot_leg_3_B.slipx_f';
    
xcp.signals(792).symbol =  'Robot_leg_3_B.Sum3_g';
    
xcp.signals(793).symbol =  'Robot_leg_3_B.TrigonometricFunction_f';
    
xcp.signals(794).symbol =  'Robot_leg_3_B.Sqrt_d';
    
xcp.signals(795).symbol =  'Robot_leg_3_B.Damping_Force_Enable_i';
    
xcp.signals(796).symbol =  'Robot_leg_3_B.Stiffness_Force_kw';
    
xcp.signals(797).symbol =  'Robot_leg_3_B.Damping_Force_mh';
    
xcp.signals(798).symbol =  'Robot_leg_3_B.Damping_Force_g';
    
xcp.signals(799).symbol =  'Robot_leg_3_B.Saturation_el';
    
xcp.signals(800).symbol =  'Robot_leg_3_B.Sign_g';
    
xcp.signals(801).symbol =  'Robot_leg_3_B.RESHAPE_b';
    
xcp.signals(802).symbol =  'Robot_leg_3_B.Product_j2';
    
xcp.signals(803).symbol =  'Robot_leg_3_B.Product1_f';
    
xcp.signals(804).symbol =  'Robot_leg_3_B.Product2_hu';
    
xcp.signals(805).symbol =  'Robot_leg_3_B.Product3_b';
    
xcp.signals(806).symbol =  'Robot_leg_3_B.Product4_ad';
    
xcp.signals(807).symbol =  'Robot_leg_3_B.Product5_gd';
    
xcp.signals(808).symbol =  'Robot_leg_3_B.Sum_ec';
    
xcp.signals(809).symbol =  'Robot_leg_3_B.Sum1_cv';
    
xcp.signals(810).symbol =  'Robot_leg_3_B.Sum2_n';
    
xcp.signals(811).symbol =  'Robot_leg_3_B.MathFunction_hr';
    
xcp.signals(812).symbol =  'Robot_leg_3_B.MathFunction1_a2';
    
xcp.signals(813).symbol =  'Robot_leg_3_B.Product3_ao';
    
xcp.signals(814).symbol =  'Robot_leg_3_B.Product4_a5';
    
xcp.signals(815).symbol =  'Robot_leg_3_B.slipy_o';
    
xcp.signals(816).symbol =  'Robot_leg_3_B.slipx_l';
    
xcp.signals(817).symbol =  'Robot_leg_3_B.Sum3_a';
    
xcp.signals(818).symbol =  'Robot_leg_3_B.TrigonometricFunction_pt';
    
xcp.signals(819).symbol =  'Robot_leg_3_B.Sqrt_h';
    
xcp.signals(820).symbol =  'Robot_leg_3_B.Damping_Force_Enable_df';
    
xcp.signals(821).symbol =  'Robot_leg_3_B.Stiffness_Force_kv';
    
xcp.signals(822).symbol =  'Robot_leg_3_B.Damping_Force_m';
    
xcp.signals(823).symbol =  'Robot_leg_3_B.Damping_Force_a';
    
xcp.signals(824).symbol =  'Robot_leg_3_B.Saturation_d';
    
xcp.signals(825).symbol =  'Robot_leg_3_B.Sign_m';
    
xcp.signals(826).symbol =  'Robot_leg_3_B.RESHAPE_j1';
    
xcp.signals(827).symbol =  'Robot_leg_3_B.Product_pw';
    
xcp.signals(828).symbol =  'Robot_leg_3_B.Product1_a';
    
xcp.signals(829).symbol =  'Robot_leg_3_B.Product2_l';
    
xcp.signals(830).symbol =  'Robot_leg_3_B.Product3_c';
    
xcp.signals(831).symbol =  'Robot_leg_3_B.Product4_iy';
    
xcp.signals(832).symbol =  'Robot_leg_3_B.Product5_g';
    
xcp.signals(833).symbol =  'Robot_leg_3_B.Sum_ein';
    
xcp.signals(834).symbol =  'Robot_leg_3_B.Sum1_ck';
    
xcp.signals(835).symbol =  'Robot_leg_3_B.Sum2_g';
    
xcp.signals(836).symbol =  'Robot_leg_3_B.MathFunction_pq';
    
xcp.signals(837).symbol =  'Robot_leg_3_B.MathFunction1_m';
    
xcp.signals(838).symbol =  'Robot_leg_3_B.Product3_j';
    
xcp.signals(839).symbol =  'Robot_leg_3_B.Product4_i';
    
xcp.signals(840).symbol =  'Robot_leg_3_B.slipy_h';
    
xcp.signals(841).symbol =  'Robot_leg_3_B.slipx_m';
    
xcp.signals(842).symbol =  'Robot_leg_3_B.Sum3_c';
    
xcp.signals(843).symbol =  'Robot_leg_3_B.TrigonometricFunction_p';
    
xcp.signals(844).symbol =  'Robot_leg_3_B.Sqrt_l3';
    
xcp.signals(845).symbol =  'Robot_leg_3_B.Damping_Force_Enable_h';
    
xcp.signals(846).symbol =  'Robot_leg_3_B.Stiffness_Force_kg';
    
xcp.signals(847).symbol =  'Robot_leg_3_B.Damping_Force_d';
    
xcp.signals(848).symbol =  'Robot_leg_3_B.Damping_Force_cq';
    
xcp.signals(849).symbol =  'Robot_leg_3_B.Saturation_jq';
    
xcp.signals(850).symbol =  'Robot_leg_3_B.Sign_f';
    
xcp.signals(851).symbol =  'Robot_leg_3_B.RESHAPE_jw';
    
xcp.signals(852).symbol =  'Robot_leg_3_B.Product_bl';
    
xcp.signals(853).symbol =  'Robot_leg_3_B.Product1_ik';
    
xcp.signals(854).symbol =  'Robot_leg_3_B.Product2_b';
    
xcp.signals(855).symbol =  'Robot_leg_3_B.Product3_d';
    
xcp.signals(856).symbol =  'Robot_leg_3_B.Product4_cw';
    
xcp.signals(857).symbol =  'Robot_leg_3_B.Product5_e';
    
xcp.signals(858).symbol =  'Robot_leg_3_B.Sum_ph';
    
xcp.signals(859).symbol =  'Robot_leg_3_B.Sum1_c';
    
xcp.signals(860).symbol =  'Robot_leg_3_B.Sum2_h';
    
xcp.signals(861).symbol =  'Robot_leg_3_B.MathFunction_c2';
    
xcp.signals(862).symbol =  'Robot_leg_3_B.MathFunction1_a';
    
xcp.signals(863).symbol =  'Robot_leg_3_B.Product3_p';
    
xcp.signals(864).symbol =  'Robot_leg_3_B.Product4_l';
    
xcp.signals(865).symbol =  'Robot_leg_3_B.slipy_c';
    
xcp.signals(866).symbol =  'Robot_leg_3_B.slipx_c';
    
xcp.signals(867).symbol =  'Robot_leg_3_B.Sum3_d';
    
xcp.signals(868).symbol =  'Robot_leg_3_B.TrigonometricFunction_i';
    
xcp.signals(869).symbol =  'Robot_leg_3_B.Sqrt_m';
    
xcp.signals(870).symbol =  'Robot_leg_3_B.Damping_Force_Enable_k';
    
xcp.signals(871).symbol =  'Robot_leg_3_B.Stiffness_Force_k';
    
xcp.signals(872).symbol =  'Robot_leg_3_B.Damping_Force_e';
    
xcp.signals(873).symbol =  'Robot_leg_3_B.Damping_Force_cz';
    
xcp.signals(874).symbol =  'Robot_leg_3_B.Saturation_e';
    
xcp.signals(875).symbol =  'Robot_leg_3_B.Sign_b';
    
xcp.signals(876).symbol =  'Robot_leg_3_B.RESHAPE';
    
xcp.signals(877).symbol =  'Robot_leg_3_B.Product_nx';
    
xcp.signals(878).symbol =  'Robot_leg_3_B.Product1_b';
    
xcp.signals(879).symbol =  'Robot_leg_3_B.Product2_hx';
    
xcp.signals(880).symbol =  'Robot_leg_3_B.Product3_hs';
    
xcp.signals(881).symbol =  'Robot_leg_3_B.Product4_bz';
    
xcp.signals(882).symbol =  'Robot_leg_3_B.Product5_i';
    
xcp.signals(883).symbol =  'Robot_leg_3_B.Sum_mh';
    
xcp.signals(884).symbol =  'Robot_leg_3_B.Sum1_e';
    
xcp.signals(885).symbol =  'Robot_leg_3_B.Sum2_m';
    
xcp.signals(886).symbol =  'Robot_leg_3_B.MathFunction_mw';
    
xcp.signals(887).symbol =  'Robot_leg_3_B.MathFunction1_j';
    
xcp.signals(888).symbol =  'Robot_leg_3_B.Product3_f';
    
xcp.signals(889).symbol =  'Robot_leg_3_B.Product4_ft';
    
xcp.signals(890).symbol =  'Robot_leg_3_B.slipy_a';
    
xcp.signals(891).symbol =  'Robot_leg_3_B.slipx_h';
    
xcp.signals(892).symbol =  'Robot_leg_3_B.Sum3_i';
    
xcp.signals(893).symbol =  'Robot_leg_3_B.TrigonometricFunction_j1';
    
xcp.signals(894).symbol =  'Robot_leg_3_B.Sqrt_f';
    
xcp.signals(895).symbol =  'Robot_leg_3_B.Damping_Force_Enable_d';
    
xcp.signals(896).symbol =  'Robot_leg_3_B.Stiffness_Force_i';
    
xcp.signals(897).symbol =  'Robot_leg_3_B.Damping_Force_c';
    
xcp.signals(898).symbol =  'Robot_leg_3_B.Damping_Force_o';
    
xcp.signals(899).symbol =  'Robot_leg_3_B.Saturation_f';
    
xcp.signals(900).symbol =  'Robot_leg_3_B.Sign_l';
    
xcp.signals(901).symbol =  'Robot_leg_3_B.RESHAPE_f';
    
xcp.signals(902).symbol =  'Robot_leg_3_B.Product_bbt';
    
xcp.signals(903).symbol =  'Robot_leg_3_B.Product1_h1';
    
xcp.signals(904).symbol =  'Robot_leg_3_B.Product2_a';
    
xcp.signals(905).symbol =  'Robot_leg_3_B.Product3_i';
    
xcp.signals(906).symbol =  'Robot_leg_3_B.Product4_f';
    
xcp.signals(907).symbol =  'Robot_leg_3_B.Product5_ju';
    
xcp.signals(908).symbol =  'Robot_leg_3_B.Sum_gny';
    
xcp.signals(909).symbol =  'Robot_leg_3_B.Sum1_j';
    
xcp.signals(910).symbol =  'Robot_leg_3_B.Sum2_e';
    
xcp.signals(911).symbol =  'Robot_leg_3_B.MathFunction_o2';
    
xcp.signals(912).symbol =  'Robot_leg_3_B.MathFunction1_n';
    
xcp.signals(913).symbol =  'Robot_leg_3_B.Product3_e';
    
xcp.signals(914).symbol =  'Robot_leg_3_B.Product4_p';
    
xcp.signals(915).symbol =  'Robot_leg_3_B.slipy_e';
    
xcp.signals(916).symbol =  'Robot_leg_3_B.slipx_k';
    
xcp.signals(917).symbol =  'Robot_leg_3_B.Sum3_p';
    
xcp.signals(918).symbol =  'Robot_leg_3_B.TrigonometricFunction_l';
    
xcp.signals(919).symbol =  'Robot_leg_3_B.Sqrt_l';
    
xcp.signals(920).symbol =  'Robot_leg_3_B.Damping_Force_Enable_b';
    
xcp.signals(921).symbol =  'Robot_leg_3_B.Stiffness_Force_m';
    
xcp.signals(922).symbol =  'Robot_leg_3_B.Damping_Force_p';
    
xcp.signals(923).symbol =  'Robot_leg_3_B.Damping_Force_nm';
    
xcp.signals(924).symbol =  'Robot_leg_3_B.Saturation_j';
    
xcp.signals(925).symbol =  'Robot_leg_3_B.Sign_k';
    
xcp.signals(926).symbol =  'Robot_leg_3_B.RESHAPE_p';
    
xcp.signals(927).symbol =  'Robot_leg_3_B.Product_eg';
    
xcp.signals(928).symbol =  'Robot_leg_3_B.Product1_c';
    
xcp.signals(929).symbol =  'Robot_leg_3_B.Product2_n';
    
xcp.signals(930).symbol =  'Robot_leg_3_B.Product3_a';
    
xcp.signals(931).symbol =  'Robot_leg_3_B.Product4_c';
    
xcp.signals(932).symbol =  'Robot_leg_3_B.Product5_j';
    
xcp.signals(933).symbol =  'Robot_leg_3_B.Sum_m4o';
    
xcp.signals(934).symbol =  'Robot_leg_3_B.Sum1';
    
xcp.signals(935).symbol =  'Robot_leg_3_B.Sum2';
    
xcp.signals(936).symbol =  'Robot_leg_3_B.MathFunction_mn';
    
xcp.signals(937).symbol =  'Robot_leg_3_B.MathFunction1';
    
xcp.signals(938).symbol =  'Robot_leg_3_B.Product3';
    
xcp.signals(939).symbol =  'Robot_leg_3_B.Product4';
    
xcp.signals(940).symbol =  'Robot_leg_3_B.slipy';
    
xcp.signals(941).symbol =  'Robot_leg_3_B.slipx';
    
xcp.signals(942).symbol =  'Robot_leg_3_B.Sum3';
    
xcp.signals(943).symbol =  'Robot_leg_3_B.TrigonometricFunction';
    
xcp.signals(944).symbol =  'Robot_leg_3_B.Sqrt';
    
xcp.signals(945).symbol =  'Robot_leg_3_B.Damping_Force_Enable';
    
xcp.signals(946).symbol =  'Robot_leg_3_B.Stiffness_Force';
    
xcp.signals(947).symbol =  'Robot_leg_3_B.Damping_Force';
    
xcp.signals(948).symbol =  'Robot_leg_3_B.Damping_Force_n';
    
xcp.signals(949).symbol =  'Robot_leg_3_B.Saturation';
    
xcp.signals(950).symbol =  'Robot_leg_3_B.Sign';
    
xcp.signals(951).symbol =  'Robot_leg_3_B.RESHAPE_j';
    
xcp.signals(952).symbol =  'Robot_leg_3_B.Friction_Force_p';
    
xcp.signals(953).symbol =  'Robot_leg_3_B.CoefficientofFrictionvsVeloc_id';
    
xcp.signals(954).symbol =  'Robot_leg_3_B.Product_mc';
    
xcp.signals(955).symbol =  'Robot_leg_3_B.Friction_Force_m';
    
xcp.signals(956).symbol =  'Robot_leg_3_B.CoefficientofFrictionvsVeloci_i';
    
xcp.signals(957).symbol =  'Robot_leg_3_B.Product_h';
    
xcp.signals(958).symbol =  'Robot_leg_3_B.Friction_Force_bg';
    
xcp.signals(959).symbol =  'Robot_leg_3_B.CoefficientofFrictionvsVeloc_ow';
    
xcp.signals(960).symbol =  'Robot_leg_3_B.Product_ka';
    
xcp.signals(961).symbol =  'Robot_leg_3_B.Friction_Force_n';
    
xcp.signals(962).symbol =  'Robot_leg_3_B.CoefficientofFrictionvsVeloci_o';
    
xcp.signals(963).symbol =  'Robot_leg_3_B.Product_db';
    
xcp.signals(964).symbol =  'Robot_leg_3_B.Friction_Force_l';
    
xcp.signals(965).symbol =  'Robot_leg_3_B.CoefficientofFrictionvsVeloc_cu';
    
xcp.signals(966).symbol =  'Robot_leg_3_B.Product_a';
    
xcp.signals(967).symbol =  'Robot_leg_3_B.Friction_Force_b';
    
xcp.signals(968).symbol =  'Robot_leg_3_B.CoefficientofFrictionvsVeloci_c';
    
xcp.signals(969).symbol =  'Robot_leg_3_B.Product_p';
    
xcp.signals(970).symbol =  'Robot_leg_3_B.Friction_Force_i';
    
xcp.signals(971).symbol =  'Robot_leg_3_B.CoefficientofFrictionvsVeloci_e';
    
xcp.signals(972).symbol =  'Robot_leg_3_B.Product_bb';
    
xcp.signals(973).symbol =  'Robot_leg_3_B.Friction_Force';
    
xcp.signals(974).symbol =  'Robot_leg_3_B.CoefficientofFrictionvsVelocity';
    
xcp.signals(975).symbol =  'Robot_leg_3_B.Product_ke';
         
xcp.parameters(1).symbol = 'Robot_leg_3_P.Constant1_Value';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&Robot_leg_3_P.Constant1_Value';     
         
xcp.parameters(2).symbol = 'Robot_leg_3_P.Constant11_Value';
xcp.parameters(2).size   =  1;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&Robot_leg_3_P.Constant11_Value';     
         
xcp.parameters(3).symbol = 'Robot_leg_3_P.Constant2_Value';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&Robot_leg_3_P.Constant2_Value';     
         
xcp.parameters(4).symbol = 'Robot_leg_3_P.Constant3_Value';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&Robot_leg_3_P.Constant3_Value';     
         
xcp.parameters(5).symbol = 'Robot_leg_3_P.Constant6_Value';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&Robot_leg_3_P.Constant6_Value';     
         
xcp.parameters(6).symbol = 'Robot_leg_3_P.Constant7_Value';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&Robot_leg_3_P.Constant7_Value';     
         
xcp.parameters(7).symbol = 'Robot_leg_3_P.Switch_Threshold';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&Robot_leg_3_P.Switch_Threshold';     
         
xcp.parameters(8).symbol = 'Robot_leg_3_P.Switch1_Threshold';
xcp.parameters(8).size   =  1;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&Robot_leg_3_P.Switch1_Threshold';     
         
xcp.parameters(9).symbol = 'Robot_leg_3_P.Switch2_Threshold';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&Robot_leg_3_P.Switch2_Threshold';     
         
xcp.parameters(10).symbol = 'Robot_leg_3_P.Switch3_Threshold';
xcp.parameters(10).size   =  1;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&Robot_leg_3_P.Switch3_Threshold';     
         
xcp.parameters(11).symbol = 'Robot_leg_3_P.Switch4_Threshold';
xcp.parameters(11).size   =  1;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&Robot_leg_3_P.Switch4_Threshold';     
         
xcp.parameters(12).symbol = 'Robot_leg_3_P.Switch5_Threshold';
xcp.parameters(12).size   =  1;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&Robot_leg_3_P.Switch5_Threshold';     
         
xcp.parameters(13).symbol = 'Robot_leg_3_P.GAIN_Gain';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&Robot_leg_3_P.GAIN_Gain';     
         
xcp.parameters(14).symbol = 'Robot_leg_3_P.IfActionSubsystem.Out1_Y0';
xcp.parameters(14).size   =  1;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&Robot_leg_3_P.IfActionSubsystem.Out1_Y0';     
         
xcp.parameters(15).symbol = 'Robot_leg_3_P.IfActionSubsystem1.Out1_Y0';
xcp.parameters(15).size   =  1;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&Robot_leg_3_P.IfActionSubsystem1.Out1_Y0';     
         
xcp.parameters(16).symbol = 'Robot_leg_3_P.IfActionSubsystem3.Out1_Y0';
xcp.parameters(16).size   =  1;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&Robot_leg_3_P.IfActionSubsystem3.Out1_Y0';     
         
xcp.parameters(17).symbol = 'Robot_leg_3_P.IfActionSubsystem4.Out1_Y0';
xcp.parameters(17).size   =  1;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&Robot_leg_3_P.IfActionSubsystem4.Out1_Y0';     
         
xcp.parameters(18).symbol = 'Robot_leg_3_P.IfActionSubsystem5.Out1_Y0';
xcp.parameters(18).size   =  1;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&Robot_leg_3_P.IfActionSubsystem5.Out1_Y0';     
         
xcp.parameters(19).symbol = 'Robot_leg_3_P.IfActionSubsystem6.Out1_Y0';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&Robot_leg_3_P.IfActionSubsystem6.Out1_Y0';     
         
xcp.parameters(20).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_sphere_rad';
xcp.parameters(20).size   =  1;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_sphere_rad';     
         
xcp.parameters(21).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_plane_lenx_d';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_plane_lenx_d';     
         
xcp.parameters(22).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_plane_leny_n';
xcp.parameters(22).size   =  1;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_plane_leny_n';     
         
xcp.parameters(23).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_plane_depth';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'real_T'; 
xcp.parameters(24).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_plane_depth';     
         
xcp.parameters(24).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_k_contact';
xcp.parameters(24).size   =  1;       
xcp.parameters(24).dtname = 'real_T'; 
xcp.parameters(25).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_k_contact';     
         
xcp.parameters(25).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_b_contact';
xcp.parameters(25).size   =  1;       
xcp.parameters(25).dtname = 'real_T'; 
xcp.parameters(26).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_b_contact';     
         
xcp.parameters(26).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_sphere_rad';
xcp.parameters(26).size   =  1;       
xcp.parameters(26).dtname = 'real_T'; 
xcp.parameters(27).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_sphere_rad';     
         
xcp.parameters(27).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_plane_len_m';
xcp.parameters(27).size   =  1;       
xcp.parameters(27).dtname = 'real_T'; 
xcp.parameters(28).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_plane_len_m';     
         
xcp.parameters(28).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_plane_len_d';
xcp.parameters(28).size   =  1;       
xcp.parameters(28).dtname = 'real_T'; 
xcp.parameters(29).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_plane_len_d';     
         
xcp.parameters(29).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_plane_depth';
xcp.parameters(29).size   =  1;       
xcp.parameters(29).dtname = 'real_T'; 
xcp.parameters(30).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_plane_depth';     
         
xcp.parameters(30).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_k_contact';
xcp.parameters(30).size   =  1;       
xcp.parameters(30).dtname = 'real_T'; 
xcp.parameters(31).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_k_contact';     
         
xcp.parameters(31).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_b_contact';
xcp.parameters(31).size   =  1;       
xcp.parameters(31).dtname = 'real_T'; 
xcp.parameters(32).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_b_contact';     
         
xcp.parameters(32).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_sphere_rad';
xcp.parameters(32).size   =  1;       
xcp.parameters(32).dtname = 'real_T'; 
xcp.parameters(33).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_sphere_rad';     
         
xcp.parameters(33).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_plane_len_b';
xcp.parameters(33).size   =  1;       
xcp.parameters(33).dtname = 'real_T'; 
xcp.parameters(34).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_plane_len_b';     
         
xcp.parameters(34).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_plane_len_p';
xcp.parameters(34).size   =  1;       
xcp.parameters(34).dtname = 'real_T'; 
xcp.parameters(35).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_plane_len_p';     
         
xcp.parameters(35).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_plane_depth';
xcp.parameters(35).size   =  1;       
xcp.parameters(35).dtname = 'real_T'; 
xcp.parameters(36).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_plane_depth';     
         
xcp.parameters(36).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_k_contact';
xcp.parameters(36).size   =  1;       
xcp.parameters(36).dtname = 'real_T'; 
xcp.parameters(37).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_k_contact';     
         
xcp.parameters(37).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_b_contact';
xcp.parameters(37).size   =  1;       
xcp.parameters(37).dtname = 'real_T'; 
xcp.parameters(38).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_b_contact';     
         
xcp.parameters(38).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_sphere_rad';
xcp.parameters(38).size   =  1;       
xcp.parameters(38).dtname = 'real_T'; 
xcp.parameters(39).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_sphere_rad';     
         
xcp.parameters(39).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_plane_len_p';
xcp.parameters(39).size   =  1;       
xcp.parameters(39).dtname = 'real_T'; 
xcp.parameters(40).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_plane_len_p';     
         
xcp.parameters(40).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_plane_len_c';
xcp.parameters(40).size   =  1;       
xcp.parameters(40).dtname = 'real_T'; 
xcp.parameters(41).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_plane_len_c';     
         
xcp.parameters(41).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_plane_depth';
xcp.parameters(41).size   =  1;       
xcp.parameters(41).dtname = 'real_T'; 
xcp.parameters(42).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_plane_depth';     
         
xcp.parameters(42).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_k_contact';
xcp.parameters(42).size   =  1;       
xcp.parameters(42).dtname = 'real_T'; 
xcp.parameters(43).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_k_contact';     
         
xcp.parameters(43).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_b_contact';
xcp.parameters(43).size   =  1;       
xcp.parameters(43).dtname = 'real_T'; 
xcp.parameters(44).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_b_contact';     
         
xcp.parameters(44).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_sphere_rad_m';
xcp.parameters(44).size   =  1;       
xcp.parameters(44).dtname = 'real_T'; 
xcp.parameters(45).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_sphere_rad_m';     
         
xcp.parameters(45).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_plane_lenx';
xcp.parameters(45).size   =  1;       
xcp.parameters(45).dtname = 'real_T'; 
xcp.parameters(46).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_plane_lenx';     
         
xcp.parameters(46).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_plane_leny';
xcp.parameters(46).size   =  1;       
xcp.parameters(46).dtname = 'real_T'; 
xcp.parameters(47).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_plane_leny';     
         
xcp.parameters(47).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_plane_dept_p';
xcp.parameters(47).size   =  1;       
xcp.parameters(47).dtname = 'real_T'; 
xcp.parameters(48).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_plane_dept_p';     
         
xcp.parameters(48).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_k_contact_h';
xcp.parameters(48).size   =  1;       
xcp.parameters(48).dtname = 'real_T'; 
xcp.parameters(49).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_k_contact_h';     
         
xcp.parameters(49).symbol = 'Robot_leg_3_P.SpheretoPlaneForce_b_contact_m';
xcp.parameters(49).size   =  1;       
xcp.parameters(49).dtname = 'real_T'; 
xcp.parameters(50).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce_b_contact_m';     
         
xcp.parameters(50).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_sphere_ra_b';
xcp.parameters(50).size   =  1;       
xcp.parameters(50).dtname = 'real_T'; 
xcp.parameters(51).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_sphere_ra_b';     
         
xcp.parameters(51).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_plane_lenx';
xcp.parameters(51).size   =  1;       
xcp.parameters(51).dtname = 'real_T'; 
xcp.parameters(52).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_plane_lenx';     
         
xcp.parameters(52).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_plane_leny';
xcp.parameters(52).size   =  1;       
xcp.parameters(52).dtname = 'real_T'; 
xcp.parameters(53).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_plane_leny';     
         
xcp.parameters(53).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_plane_dep_h';
xcp.parameters(53).size   =  1;       
xcp.parameters(53).dtname = 'real_T'; 
xcp.parameters(54).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_plane_dep_h';     
         
xcp.parameters(54).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_k_contact_o';
xcp.parameters(54).size   =  1;       
xcp.parameters(54).dtname = 'real_T'; 
xcp.parameters(55).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_k_contact_o';     
         
xcp.parameters(55).symbol = 'Robot_leg_3_P.SpheretoPlaneForce1_b_contact_b';
xcp.parameters(55).size   =  1;       
xcp.parameters(55).dtname = 'real_T'; 
xcp.parameters(56).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce1_b_contact_b';     
         
xcp.parameters(56).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_sphere_ra_p';
xcp.parameters(56).size   =  1;       
xcp.parameters(56).dtname = 'real_T'; 
xcp.parameters(57).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_sphere_ra_p';     
         
xcp.parameters(57).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_plane_lenx';
xcp.parameters(57).size   =  1;       
xcp.parameters(57).dtname = 'real_T'; 
xcp.parameters(58).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_plane_lenx';     
         
xcp.parameters(58).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_plane_leny';
xcp.parameters(58).size   =  1;       
xcp.parameters(58).dtname = 'real_T'; 
xcp.parameters(59).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_plane_leny';     
         
xcp.parameters(59).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_plane_dep_k';
xcp.parameters(59).size   =  1;       
xcp.parameters(59).dtname = 'real_T'; 
xcp.parameters(60).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_plane_dep_k';     
         
xcp.parameters(60).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_k_contact_d';
xcp.parameters(60).size   =  1;       
xcp.parameters(60).dtname = 'real_T'; 
xcp.parameters(61).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_k_contact_d';     
         
xcp.parameters(61).symbol = 'Robot_leg_3_P.SpheretoPlaneForce2_b_contact_j';
xcp.parameters(61).size   =  1;       
xcp.parameters(61).dtname = 'real_T'; 
xcp.parameters(62).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce2_b_contact_j';     
         
xcp.parameters(62).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_sphere_ra_i';
xcp.parameters(62).size   =  1;       
xcp.parameters(62).dtname = 'real_T'; 
xcp.parameters(63).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_sphere_ra_i';     
         
xcp.parameters(63).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_plane_lenx';
xcp.parameters(63).size   =  1;       
xcp.parameters(63).dtname = 'real_T'; 
xcp.parameters(64).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_plane_lenx';     
         
xcp.parameters(64).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_plane_leny';
xcp.parameters(64).size   =  1;       
xcp.parameters(64).dtname = 'real_T'; 
xcp.parameters(65).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_plane_leny';     
         
xcp.parameters(65).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_plane_dep_a';
xcp.parameters(65).size   =  1;       
xcp.parameters(65).dtname = 'real_T'; 
xcp.parameters(66).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_plane_dep_a';     
         
xcp.parameters(66).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_k_contact_e';
xcp.parameters(66).size   =  1;       
xcp.parameters(66).dtname = 'real_T'; 
xcp.parameters(67).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_k_contact_e';     
         
xcp.parameters(67).symbol = 'Robot_leg_3_P.SpheretoPlaneForce3_b_contact_h';
xcp.parameters(67).size   =  1;       
xcp.parameters(67).dtname = 'real_T'; 
xcp.parameters(68).baseaddr = '&Robot_leg_3_P.SpheretoPlaneForce3_b_contact_h';     
         
xcp.parameters(68).symbol = 'Robot_leg_3_P.Constant_Value_pg';
xcp.parameters(68).size   =  1;       
xcp.parameters(68).dtname = 'real_T'; 
xcp.parameters(69).baseaddr = '&Robot_leg_3_P.Constant_Value_pg';     
         
xcp.parameters(69).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_a';
xcp.parameters(69).size   =  40;       
xcp.parameters(69).dtname = 'real_T'; 
xcp.parameters(70).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_a[0]';     
         
xcp.parameters(70).symbol = 'Robot_leg_3_P.Constant_Value_lf';
xcp.parameters(70).size   =  1;       
xcp.parameters(70).dtname = 'real_T'; 
xcp.parameters(71).baseaddr = '&Robot_leg_3_P.Constant_Value_lf';     
         
xcp.parameters(71).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_i';
xcp.parameters(71).size   =  40;       
xcp.parameters(71).dtname = 'real_T'; 
xcp.parameters(72).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_i[0]';     
         
xcp.parameters(72).symbol = 'Robot_leg_3_P.Constant_Value_i';
xcp.parameters(72).size   =  1;       
xcp.parameters(72).dtname = 'real_T'; 
xcp.parameters(73).baseaddr = '&Robot_leg_3_P.Constant_Value_i';     
         
xcp.parameters(73).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_cl';
xcp.parameters(73).size   =  20;       
xcp.parameters(73).dtname = 'real_T'; 
xcp.parameters(74).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_cl[0]';     
         
xcp.parameters(74).symbol = 'Robot_leg_3_P.Constant_Value_e';
xcp.parameters(74).size   =  1;       
xcp.parameters(74).dtname = 'real_T'; 
xcp.parameters(75).baseaddr = '&Robot_leg_3_P.Constant_Value_e';     
         
xcp.parameters(75).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_c';
xcp.parameters(75).size   =  40;       
xcp.parameters(75).dtname = 'real_T'; 
xcp.parameters(76).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_c[0]';     
         
xcp.parameters(76).symbol = 'Robot_leg_3_P.Constant_Value_b';
xcp.parameters(76).size   =  1;       
xcp.parameters(76).dtname = 'real_T'; 
xcp.parameters(77).baseaddr = '&Robot_leg_3_P.Constant_Value_b';     
         
xcp.parameters(77).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_n';
xcp.parameters(77).size   =  20;       
xcp.parameters(77).dtname = 'real_T'; 
xcp.parameters(78).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_n[0]';     
         
xcp.parameters(78).symbol = 'Robot_leg_3_P.Constant_Value_m';
xcp.parameters(78).size   =  1;       
xcp.parameters(78).dtname = 'real_T'; 
xcp.parameters(79).baseaddr = '&Robot_leg_3_P.Constant_Value_m';     
         
xcp.parameters(79).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_e';
xcp.parameters(79).size   =  20;       
xcp.parameters(79).dtname = 'real_T'; 
xcp.parameters(80).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_e[0]';     
         
xcp.parameters(80).symbol = 'Robot_leg_3_P.Constant_Value_mj';
xcp.parameters(80).size   =  1;       
xcp.parameters(80).dtname = 'real_T'; 
xcp.parameters(81).baseaddr = '&Robot_leg_3_P.Constant_Value_mj';     
         
xcp.parameters(81).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_b';
xcp.parameters(81).size   =  20;       
xcp.parameters(81).dtname = 'real_T'; 
xcp.parameters(82).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_b[0]';     
         
xcp.parameters(82).symbol = 'Robot_leg_3_P.Constant_Value_c';
xcp.parameters(82).size   =  1;       
xcp.parameters(82).dtname = 'real_T'; 
xcp.parameters(83).baseaddr = '&Robot_leg_3_P.Constant_Value_c';     
         
xcp.parameters(83).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_k';
xcp.parameters(83).size   =  40;       
xcp.parameters(83).dtname = 'real_T'; 
xcp.parameters(84).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_k[0]';     
         
xcp.parameters(84).symbol = 'Robot_leg_3_P.Constant_Value_n';
xcp.parameters(84).size   =  1;       
xcp.parameters(84).dtname = 'real_T'; 
xcp.parameters(85).baseaddr = '&Robot_leg_3_P.Constant_Value_n';     
         
xcp.parameters(85).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_d';
xcp.parameters(85).size   =  40;       
xcp.parameters(85).dtname = 'real_T'; 
xcp.parameters(86).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_d[0]';     
         
xcp.parameters(86).symbol = 'Robot_leg_3_P.Constant_Value';
xcp.parameters(86).size   =  1;       
xcp.parameters(86).dtname = 'real_T'; 
xcp.parameters(87).baseaddr = '&Robot_leg_3_P.Constant_Value';     
         
xcp.parameters(87).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data';
xcp.parameters(87).size   =  40;       
xcp.parameters(87).dtname = 'real_T'; 
xcp.parameters(88).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data[0]';     
         
xcp.parameters(88).symbol = 'Robot_leg_3_P.Constant_Value_p';
xcp.parameters(88).size   =  1;       
xcp.parameters(88).dtname = 'real_T'; 
xcp.parameters(89).baseaddr = '&Robot_leg_3_P.Constant_Value_p';     
         
xcp.parameters(89).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_f';
xcp.parameters(89).size   =  40;       
xcp.parameters(89).dtname = 'real_T'; 
xcp.parameters(90).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_f[0]';     
         
xcp.parameters(90).symbol = 'Robot_leg_3_P.Constant_Value_h';
xcp.parameters(90).size   =  1;       
xcp.parameters(90).dtname = 'real_T'; 
xcp.parameters(91).baseaddr = '&Robot_leg_3_P.Constant_Value_h';     
         
xcp.parameters(91).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_o';
xcp.parameters(91).size   =  40;       
xcp.parameters(91).dtname = 'real_T'; 
xcp.parameters(92).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_o[0]';     
         
xcp.parameters(92).symbol = 'Robot_leg_3_P.Constant_Value_l';
xcp.parameters(92).size   =  1;       
xcp.parameters(92).dtname = 'real_T'; 
xcp.parameters(93).baseaddr = '&Robot_leg_3_P.Constant_Value_l';     
         
xcp.parameters(93).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_fc';
xcp.parameters(93).size   =  40;       
xcp.parameters(93).dtname = 'real_T'; 
xcp.parameters(94).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_fc[0]';     
         
xcp.parameters(94).symbol = 'Robot_leg_3_P.Constant_Value_d';
xcp.parameters(94).size   =  1;       
xcp.parameters(94).dtname = 'real_T'; 
xcp.parameters(95).baseaddr = '&Robot_leg_3_P.Constant_Value_d';     
         
xcp.parameters(95).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_m';
xcp.parameters(95).size   =  40;       
xcp.parameters(95).dtname = 'real_T'; 
xcp.parameters(96).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_m[0]';     
         
xcp.parameters(96).symbol = 'Robot_leg_3_P.Constant_Value_o';
xcp.parameters(96).size   =  1;       
xcp.parameters(96).dtname = 'real_T'; 
xcp.parameters(97).baseaddr = '&Robot_leg_3_P.Constant_Value_o';     
         
xcp.parameters(97).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_iz';
xcp.parameters(97).size   =  40;       
xcp.parameters(97).dtname = 'real_T'; 
xcp.parameters(98).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_iz[0]';     
         
xcp.parameters(98).symbol = 'Robot_leg_3_P.Constant_Value_f';
xcp.parameters(98).size   =  1;       
xcp.parameters(98).dtname = 'real_T'; 
xcp.parameters(99).baseaddr = '&Robot_leg_3_P.Constant_Value_f';     
         
xcp.parameters(99).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_g';
xcp.parameters(99).size   =  40;       
xcp.parameters(99).dtname = 'real_T'; 
xcp.parameters(100).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_g[0]';     
         
xcp.parameters(100).symbol = 'Robot_leg_3_P.Constant_Value_og';
xcp.parameters(100).size   =  1;       
xcp.parameters(100).dtname = 'real_T'; 
xcp.parameters(101).baseaddr = '&Robot_leg_3_P.Constant_Value_og';     
         
xcp.parameters(101).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_h';
xcp.parameters(101).size   =  40;       
xcp.parameters(101).dtname = 'real_T'; 
xcp.parameters(102).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_h[0]';     
         
xcp.parameters(102).symbol = 'Robot_leg_3_P.Constant_Value_fr';
xcp.parameters(102).size   =  1;       
xcp.parameters(102).dtname = 'real_T'; 
xcp.parameters(103).baseaddr = '&Robot_leg_3_P.Constant_Value_fr';     
         
xcp.parameters(103).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_kh';
xcp.parameters(103).size   =  40;       
xcp.parameters(103).dtname = 'real_T'; 
xcp.parameters(104).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_kh[0]';     
         
xcp.parameters(104).symbol = 'Robot_leg_3_P.Constant_Value_df';
xcp.parameters(104).size   =  1;       
xcp.parameters(104).dtname = 'real_T'; 
xcp.parameters(105).baseaddr = '&Robot_leg_3_P.Constant_Value_df';     
         
xcp.parameters(105).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_nk';
xcp.parameters(105).size   =  40;       
xcp.parameters(105).dtname = 'real_T'; 
xcp.parameters(106).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_nk[0]';     
         
xcp.parameters(106).symbol = 'Robot_leg_3_P.Constant_Value_n3';
xcp.parameters(106).size   =  1;       
xcp.parameters(106).dtname = 'real_T'; 
xcp.parameters(107).baseaddr = '&Robot_leg_3_P.Constant_Value_n3';     
         
xcp.parameters(107).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_ac';
xcp.parameters(107).size   =  40;       
xcp.parameters(107).dtname = 'real_T'; 
xcp.parameters(108).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_ac[0]';     
         
xcp.parameters(108).symbol = 'Robot_leg_3_P.Constant_Value_lv';
xcp.parameters(108).size   =  1;       
xcp.parameters(108).dtname = 'real_T'; 
xcp.parameters(109).baseaddr = '&Robot_leg_3_P.Constant_Value_lv';     
         
xcp.parameters(109).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_j';
xcp.parameters(109).size   =  40;       
xcp.parameters(109).dtname = 'real_T'; 
xcp.parameters(110).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_j[0]';     
         
xcp.parameters(110).symbol = 'Robot_leg_3_P.Constant_Value_pk';
xcp.parameters(110).size   =  1;       
xcp.parameters(110).dtname = 'real_T'; 
xcp.parameters(111).baseaddr = '&Robot_leg_3_P.Constant_Value_pk';     
         
xcp.parameters(111).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_kx';
xcp.parameters(111).size   =  40;       
xcp.parameters(111).dtname = 'real_T'; 
xcp.parameters(112).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_kx[0]';     
         
xcp.parameters(112).symbol = 'Robot_leg_3_P.Constant_Value_da';
xcp.parameters(112).size   =  1;       
xcp.parameters(112).dtname = 'real_T'; 
xcp.parameters(113).baseaddr = '&Robot_leg_3_P.Constant_Value_da';     
         
xcp.parameters(113).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_gz';
xcp.parameters(113).size   =  40;       
xcp.parameters(113).dtname = 'real_T'; 
xcp.parameters(114).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_gz[0]';     
         
xcp.parameters(114).symbol = 'Robot_leg_3_P.Constant_Value_nq';
xcp.parameters(114).size   =  1;       
xcp.parameters(114).dtname = 'real_T'; 
xcp.parameters(115).baseaddr = '&Robot_leg_3_P.Constant_Value_nq';     
         
xcp.parameters(115).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_fq';
xcp.parameters(115).size   =  40;       
xcp.parameters(115).dtname = 'real_T'; 
xcp.parameters(116).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_fq[0]';     
         
xcp.parameters(116).symbol = 'Robot_leg_3_P.Constant_Value_a';
xcp.parameters(116).size   =  1;       
xcp.parameters(116).dtname = 'real_T'; 
xcp.parameters(117).baseaddr = '&Robot_leg_3_P.Constant_Value_a';     
         
xcp.parameters(117).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_p';
xcp.parameters(117).size   =  40;       
xcp.parameters(117).dtname = 'real_T'; 
xcp.parameters(118).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_p[0]';     
         
xcp.parameters(118).symbol = 'Robot_leg_3_P.Merge_InitialOutput';
xcp.parameters(118).size   =  1;       
xcp.parameters(118).dtname = 'real_T'; 
xcp.parameters(119).baseaddr = '&Robot_leg_3_P.Merge_InitialOutput';     
         
xcp.parameters(119).symbol = 'Robot_leg_3_P.Merge_InitialOutput_n';
xcp.parameters(119).size   =  1;       
xcp.parameters(119).dtname = 'real_T'; 
xcp.parameters(120).baseaddr = '&Robot_leg_3_P.Merge_InitialOutput_n';     
         
xcp.parameters(120).symbol = 'Robot_leg_3_P.Merge_InitialOutput_d';
xcp.parameters(120).size   =  1;       
xcp.parameters(120).dtname = 'real_T'; 
xcp.parameters(121).baseaddr = '&Robot_leg_3_P.Merge_InitialOutput_d';     
         
xcp.parameters(121).symbol = 'Robot_leg_3_P.Merge_InitialOutput_nd';
xcp.parameters(121).size   =  1;       
xcp.parameters(121).dtname = 'real_T'; 
xcp.parameters(122).baseaddr = '&Robot_leg_3_P.Merge_InitialOutput_nd';     
         
xcp.parameters(122).symbol = 'Robot_leg_3_P.Constant_Value_e1';
xcp.parameters(122).size   =  1;       
xcp.parameters(122).dtname = 'real_T'; 
xcp.parameters(123).baseaddr = '&Robot_leg_3_P.Constant_Value_e1';     
         
xcp.parameters(123).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_gb';
xcp.parameters(123).size   =  40;       
xcp.parameters(123).dtname = 'real_T'; 
xcp.parameters(124).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_gb[0]';     
         
xcp.parameters(124).symbol = 'Robot_leg_3_P.Constant_Value_j';
xcp.parameters(124).size   =  1;       
xcp.parameters(124).dtname = 'real_T'; 
xcp.parameters(125).baseaddr = '&Robot_leg_3_P.Constant_Value_j';     
         
xcp.parameters(125).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_a0o';
xcp.parameters(125).size   =  40;       
xcp.parameters(125).dtname = 'real_T'; 
xcp.parameters(126).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_a0o[0]';     
         
xcp.parameters(126).symbol = 'Robot_leg_3_P.Constant_Value_k';
xcp.parameters(126).size   =  1;       
xcp.parameters(126).dtname = 'real_T'; 
xcp.parameters(127).baseaddr = '&Robot_leg_3_P.Constant_Value_k';     
         
xcp.parameters(127).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_kj';
xcp.parameters(127).size   =  40;       
xcp.parameters(127).dtname = 'real_T'; 
xcp.parameters(128).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_kj[0]';     
         
xcp.parameters(128).symbol = 'Robot_leg_3_P.Constant_Value_co';
xcp.parameters(128).size   =  1;       
xcp.parameters(128).dtname = 'real_T'; 
xcp.parameters(129).baseaddr = '&Robot_leg_3_P.Constant_Value_co';     
         
xcp.parameters(129).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_pv';
xcp.parameters(129).size   =  40;       
xcp.parameters(129).dtname = 'real_T'; 
xcp.parameters(130).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_pv[0]';     
         
xcp.parameters(130).symbol = 'Robot_leg_3_P.Constant_Value_ov';
xcp.parameters(130).size   =  1;       
xcp.parameters(130).dtname = 'real_T'; 
xcp.parameters(131).baseaddr = '&Robot_leg_3_P.Constant_Value_ov';     
         
xcp.parameters(131).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_hz';
xcp.parameters(131).size   =  40;       
xcp.parameters(131).dtname = 'real_T'; 
xcp.parameters(132).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_hz[0]';     
         
xcp.parameters(132).symbol = 'Robot_leg_3_P.Constant_Value_oj';
xcp.parameters(132).size   =  1;       
xcp.parameters(132).dtname = 'real_T'; 
xcp.parameters(133).baseaddr = '&Robot_leg_3_P.Constant_Value_oj';     
         
xcp.parameters(133).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_dq';
xcp.parameters(133).size   =  20;       
xcp.parameters(133).dtname = 'real_T'; 
xcp.parameters(134).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_dq[0]';     
         
xcp.parameters(134).symbol = 'Robot_leg_3_P.Constant_Value_po';
xcp.parameters(134).size   =  1;       
xcp.parameters(134).dtname = 'real_T'; 
xcp.parameters(135).baseaddr = '&Robot_leg_3_P.Constant_Value_po';     
         
xcp.parameters(135).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_a0';
xcp.parameters(135).size   =  40;       
xcp.parameters(135).dtname = 'real_T'; 
xcp.parameters(136).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_a0[0]';     
         
xcp.parameters(136).symbol = 'Robot_leg_3_P.Constant_Value_ad';
xcp.parameters(136).size   =  1;       
xcp.parameters(136).dtname = 'real_T'; 
xcp.parameters(137).baseaddr = '&Robot_leg_3_P.Constant_Value_ad';     
         
xcp.parameters(137).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_bi';
xcp.parameters(137).size   =  40;       
xcp.parameters(137).dtname = 'real_T'; 
xcp.parameters(138).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_bi[0]';     
         
xcp.parameters(138).symbol = 'Robot_leg_3_P.Constant_Value_or';
xcp.parameters(138).size   =  1;       
xcp.parameters(138).dtname = 'real_T'; 
xcp.parameters(139).baseaddr = '&Robot_leg_3_P.Constant_Value_or';     
         
xcp.parameters(139).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_l';
xcp.parameters(139).size   =  40;       
xcp.parameters(139).dtname = 'real_T'; 
xcp.parameters(140).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_l[0]';     
         
xcp.parameters(140).symbol = 'Robot_leg_3_P.Constant_Value_or3';
xcp.parameters(140).size   =  1;       
xcp.parameters(140).dtname = 'real_T'; 
xcp.parameters(141).baseaddr = '&Robot_leg_3_P.Constant_Value_or3';     
         
xcp.parameters(141).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_pq';
xcp.parameters(141).size   =  40;       
xcp.parameters(141).dtname = 'real_T'; 
xcp.parameters(142).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_pq[0]';     
         
xcp.parameters(142).symbol = 'Robot_leg_3_P.Constant_Value_d0';
xcp.parameters(142).size   =  1;       
xcp.parameters(142).dtname = 'real_T'; 
xcp.parameters(143).baseaddr = '&Robot_leg_3_P.Constant_Value_d0';     
         
xcp.parameters(143).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_ej';
xcp.parameters(143).size   =  40;       
xcp.parameters(143).dtname = 'real_T'; 
xcp.parameters(144).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_ej[0]';     
         
xcp.parameters(144).symbol = 'Robot_leg_3_P.Constant_Value_bt';
xcp.parameters(144).size   =  1;       
xcp.parameters(144).dtname = 'real_T'; 
xcp.parameters(145).baseaddr = '&Robot_leg_3_P.Constant_Value_bt';     
         
xcp.parameters(145).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_ml';
xcp.parameters(145).size   =  40;       
xcp.parameters(145).dtname = 'real_T'; 
xcp.parameters(146).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_ml[0]';     
         
xcp.parameters(146).symbol = 'Robot_leg_3_P.Constant_Value_ev';
xcp.parameters(146).size   =  1;       
xcp.parameters(146).dtname = 'real_T'; 
xcp.parameters(147).baseaddr = '&Robot_leg_3_P.Constant_Value_ev';     
         
xcp.parameters(147).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_aw';
xcp.parameters(147).size   =  40;       
xcp.parameters(147).dtname = 'real_T'; 
xcp.parameters(148).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_aw[0]';     
         
xcp.parameters(148).symbol = 'Robot_leg_3_P.Constant_Value_oh';
xcp.parameters(148).size   =  1;       
xcp.parameters(148).dtname = 'real_T'; 
xcp.parameters(149).baseaddr = '&Robot_leg_3_P.Constant_Value_oh';     
         
xcp.parameters(149).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_jx';
xcp.parameters(149).size   =  40;       
xcp.parameters(149).dtname = 'real_T'; 
xcp.parameters(150).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_jx[0]';     
         
xcp.parameters(150).symbol = 'Robot_leg_3_P.Constant_Value_ot';
xcp.parameters(150).size   =  1;       
xcp.parameters(150).dtname = 'real_T'; 
xcp.parameters(151).baseaddr = '&Robot_leg_3_P.Constant_Value_ot';     
         
xcp.parameters(151).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_jw';
xcp.parameters(151).size   =  40;       
xcp.parameters(151).dtname = 'real_T'; 
xcp.parameters(152).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_jw[0]';     
         
xcp.parameters(152).symbol = 'Robot_leg_3_P.Constant_Value_j5';
xcp.parameters(152).size   =  1;       
xcp.parameters(152).dtname = 'real_T'; 
xcp.parameters(153).baseaddr = '&Robot_leg_3_P.Constant_Value_j5';     
         
xcp.parameters(153).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_l0';
xcp.parameters(153).size   =  40;       
xcp.parameters(153).dtname = 'real_T'; 
xcp.parameters(154).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_l0[0]';     
         
xcp.parameters(154).symbol = 'Robot_leg_3_P.Constant_Value_ma';
xcp.parameters(154).size   =  1;       
xcp.parameters(154).dtname = 'real_T'; 
xcp.parameters(155).baseaddr = '&Robot_leg_3_P.Constant_Value_ma';     
         
xcp.parameters(155).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_ns';
xcp.parameters(155).size   =  40;       
xcp.parameters(155).dtname = 'real_T'; 
xcp.parameters(156).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_ns[0]';     
         
xcp.parameters(156).symbol = 'Robot_leg_3_P.Constant_Value_km';
xcp.parameters(156).size   =  1;       
xcp.parameters(156).dtname = 'real_T'; 
xcp.parameters(157).baseaddr = '&Robot_leg_3_P.Constant_Value_km';     
         
xcp.parameters(157).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_og';
xcp.parameters(157).size   =  40;       
xcp.parameters(157).dtname = 'real_T'; 
xcp.parameters(158).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_og[0]';     
         
xcp.parameters(158).symbol = 'Robot_leg_3_P.Constant_Value_em';
xcp.parameters(158).size   =  1;       
xcp.parameters(158).dtname = 'real_T'; 
xcp.parameters(159).baseaddr = '&Robot_leg_3_P.Constant_Value_em';     
         
xcp.parameters(159).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_ev';
xcp.parameters(159).size   =  40;       
xcp.parameters(159).dtname = 'real_T'; 
xcp.parameters(160).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_ev[0]';     
         
xcp.parameters(160).symbol = 'Robot_leg_3_P.Constant_Value_js';
xcp.parameters(160).size   =  1;       
xcp.parameters(160).dtname = 'real_T'; 
xcp.parameters(161).baseaddr = '&Robot_leg_3_P.Constant_Value_js';     
         
xcp.parameters(161).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_clj';
xcp.parameters(161).size   =  40;       
xcp.parameters(161).dtname = 'real_T'; 
xcp.parameters(162).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_clj[0]';     
         
xcp.parameters(162).symbol = 'Robot_leg_3_P.Constant_Value_bs';
xcp.parameters(162).size   =  1;       
xcp.parameters(162).dtname = 'real_T'; 
xcp.parameters(163).baseaddr = '&Robot_leg_3_P.Constant_Value_bs';     
         
xcp.parameters(163).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_jt';
xcp.parameters(163).size   =  40;       
xcp.parameters(163).dtname = 'real_T'; 
xcp.parameters(164).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_jt[0]';     
         
xcp.parameters(164).symbol = 'Robot_leg_3_P.Constant_Value_g';
xcp.parameters(164).size   =  1;       
xcp.parameters(164).dtname = 'real_T'; 
xcp.parameters(165).baseaddr = '&Robot_leg_3_P.Constant_Value_g';     
         
xcp.parameters(165).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_ib';
xcp.parameters(165).size   =  40;       
xcp.parameters(165).dtname = 'real_T'; 
xcp.parameters(166).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_ib[0]';     
         
xcp.parameters(166).symbol = 'Robot_leg_3_P.Constant_Value_ay';
xcp.parameters(166).size   =  1;       
xcp.parameters(166).dtname = 'real_T'; 
xcp.parameters(167).baseaddr = '&Robot_leg_3_P.Constant_Value_ay';     
         
xcp.parameters(167).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_hf';
xcp.parameters(167).size   =  40;       
xcp.parameters(167).dtname = 'real_T'; 
xcp.parameters(168).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_hf[0]';     
         
xcp.parameters(168).symbol = 'Robot_leg_3_P.Constant_Value_au';
xcp.parameters(168).size   =  1;       
xcp.parameters(168).dtname = 'real_T'; 
xcp.parameters(169).baseaddr = '&Robot_leg_3_P.Constant_Value_au';     
         
xcp.parameters(169).symbol = 'Robot_leg_3_P.LookUpTable1_bp01Data_cz';
xcp.parameters(169).size   =  40;       
xcp.parameters(169).dtname = 'real_T'; 
xcp.parameters(170).baseaddr = '&Robot_leg_3_P.LookUpTable1_bp01Data_cz[0]';     
         
xcp.parameters(170).symbol = 'Robot_leg_3_P.Merge_InitialOutput_k';
xcp.parameters(170).size   =  1;       
xcp.parameters(170).dtname = 'real_T'; 
xcp.parameters(171).baseaddr = '&Robot_leg_3_P.Merge_InitialOutput_k';     
         
xcp.parameters(171).symbol = 'Robot_leg_3_P.Merge_InitialOutput_o';
xcp.parameters(171).size   =  1;       
xcp.parameters(171).dtname = 'real_T'; 
xcp.parameters(172).baseaddr = '&Robot_leg_3_P.Merge_InitialOutput_o';     
         
xcp.parameters(172).symbol = 'Robot_leg_3_P.Merge_InitialOutput_m';
xcp.parameters(172).size   =  1;       
xcp.parameters(172).dtname = 'real_T'; 
xcp.parameters(173).baseaddr = '&Robot_leg_3_P.Merge_InitialOutput_m';     
         
xcp.parameters(173).symbol = 'Robot_leg_3_P.Merge_InitialOutput_e';
xcp.parameters(173).size   =  1;       
xcp.parameters(173).dtname = 'real_T'; 
xcp.parameters(174).baseaddr = '&Robot_leg_3_P.Merge_InitialOutput_e';     
         
xcp.parameters(174).symbol = 'Robot_leg_3_P.Gain_Gain_nz';
xcp.parameters(174).size   =  1;       
xcp.parameters(174).dtname = 'real_T'; 
xcp.parameters(175).baseaddr = '&Robot_leg_3_P.Gain_Gain_nz';     
         
xcp.parameters(175).symbol = 'Robot_leg_3_P.Gain1_Gain_d';
xcp.parameters(175).size   =  1;       
xcp.parameters(175).dtname = 'real_T'; 
xcp.parameters(176).baseaddr = '&Robot_leg_3_P.Gain1_Gain_d';     
         
xcp.parameters(176).symbol = 'Robot_leg_3_P.Out_Y0';
xcp.parameters(176).size   =  1;       
xcp.parameters(176).dtname = 'real_T'; 
xcp.parameters(177).baseaddr = '&Robot_leg_3_P.Out_Y0';     
         
xcp.parameters(177).symbol = 'Robot_leg_3_P.Zeros_Value';
xcp.parameters(177).size   =  12;       
xcp.parameters(177).dtname = 'real_T'; 
xcp.parameters(178).baseaddr = '&Robot_leg_3_P.Zeros_Value[0]';     
         
xcp.parameters(178).symbol = 'Robot_leg_3_P.Gain_Gain_gs';
xcp.parameters(178).size   =  1;       
xcp.parameters(178).dtname = 'real_T'; 
xcp.parameters(179).baseaddr = '&Robot_leg_3_P.Gain_Gain_gs';     
         
xcp.parameters(179).symbol = 'Robot_leg_3_P.Gain1_Gain_g';
xcp.parameters(179).size   =  1;       
xcp.parameters(179).dtname = 'real_T'; 
xcp.parameters(180).baseaddr = '&Robot_leg_3_P.Gain1_Gain_g';     
         
xcp.parameters(180).symbol = 'Robot_leg_3_P.Out_Y0_p';
xcp.parameters(180).size   =  1;       
xcp.parameters(180).dtname = 'real_T'; 
xcp.parameters(181).baseaddr = '&Robot_leg_3_P.Out_Y0_p';     
         
xcp.parameters(181).symbol = 'Robot_leg_3_P.Zeros_Value_m';
xcp.parameters(181).size   =  12;       
xcp.parameters(181).dtname = 'real_T'; 
xcp.parameters(182).baseaddr = '&Robot_leg_3_P.Zeros_Value_m[0]';     
         
xcp.parameters(182).symbol = 'Robot_leg_3_P.Gain_Gain_gp';
xcp.parameters(182).size   =  1;       
xcp.parameters(182).dtname = 'real_T'; 
xcp.parameters(183).baseaddr = '&Robot_leg_3_P.Gain_Gain_gp';     
         
xcp.parameters(183).symbol = 'Robot_leg_3_P.Gain1_Gain_k';
xcp.parameters(183).size   =  1;       
xcp.parameters(183).dtname = 'real_T'; 
xcp.parameters(184).baseaddr = '&Robot_leg_3_P.Gain1_Gain_k';     
         
xcp.parameters(184).symbol = 'Robot_leg_3_P.Out_Y0_d';
xcp.parameters(184).size   =  1;       
xcp.parameters(184).dtname = 'real_T'; 
xcp.parameters(185).baseaddr = '&Robot_leg_3_P.Out_Y0_d';     
         
xcp.parameters(185).symbol = 'Robot_leg_3_P.Zeros_Value_m2';
xcp.parameters(185).size   =  12;       
xcp.parameters(185).dtname = 'real_T'; 
xcp.parameters(186).baseaddr = '&Robot_leg_3_P.Zeros_Value_m2[0]';     
         
xcp.parameters(186).symbol = 'Robot_leg_3_P.Gain_Gain_a0';
xcp.parameters(186).size   =  1;       
xcp.parameters(186).dtname = 'real_T'; 
xcp.parameters(187).baseaddr = '&Robot_leg_3_P.Gain_Gain_a0';     
         
xcp.parameters(187).symbol = 'Robot_leg_3_P.Gain1_Gain_l';
xcp.parameters(187).size   =  1;       
xcp.parameters(187).dtname = 'real_T'; 
xcp.parameters(188).baseaddr = '&Robot_leg_3_P.Gain1_Gain_l';     
         
xcp.parameters(188).symbol = 'Robot_leg_3_P.Out_Y0_m';
xcp.parameters(188).size   =  1;       
xcp.parameters(188).dtname = 'real_T'; 
xcp.parameters(189).baseaddr = '&Robot_leg_3_P.Out_Y0_m';     
         
xcp.parameters(189).symbol = 'Robot_leg_3_P.Zeros_Value_m4';
xcp.parameters(189).size   =  12;       
xcp.parameters(189).dtname = 'real_T'; 
xcp.parameters(190).baseaddr = '&Robot_leg_3_P.Zeros_Value_m4[0]';     
         
xcp.parameters(190).symbol = 'Robot_leg_3_P.Gain_Gain_d';
xcp.parameters(190).size   =  1;       
xcp.parameters(190).dtname = 'real_T'; 
xcp.parameters(191).baseaddr = '&Robot_leg_3_P.Gain_Gain_d';     
         
xcp.parameters(191).symbol = 'Robot_leg_3_P.Gain1_Gain';
xcp.parameters(191).size   =  1;       
xcp.parameters(191).dtname = 'real_T'; 
xcp.parameters(192).baseaddr = '&Robot_leg_3_P.Gain1_Gain';     
         
xcp.parameters(192).symbol = 'Robot_leg_3_P.Out_Y0_n';
xcp.parameters(192).size   =  1;       
xcp.parameters(192).dtname = 'real_T'; 
xcp.parameters(193).baseaddr = '&Robot_leg_3_P.Out_Y0_n';     
         
xcp.parameters(193).symbol = 'Robot_leg_3_P.Zeros_Value_h';
xcp.parameters(193).size   =  12;       
xcp.parameters(193).dtname = 'real_T'; 
xcp.parameters(194).baseaddr = '&Robot_leg_3_P.Zeros_Value_h[0]';     
         
xcp.parameters(194).symbol = 'Robot_leg_3_P.Gain_Gain_o';
xcp.parameters(194).size   =  1;       
xcp.parameters(194).dtname = 'real_T'; 
xcp.parameters(195).baseaddr = '&Robot_leg_3_P.Gain_Gain_o';     
         
xcp.parameters(195).symbol = 'Robot_leg_3_P.Gain1_Gain_a';
xcp.parameters(195).size   =  1;       
xcp.parameters(195).dtname = 'real_T'; 
xcp.parameters(196).baseaddr = '&Robot_leg_3_P.Gain1_Gain_a';     
         
xcp.parameters(196).symbol = 'Robot_leg_3_P.Out_Y0_f';
xcp.parameters(196).size   =  1;       
xcp.parameters(196).dtname = 'real_T'; 
xcp.parameters(197).baseaddr = '&Robot_leg_3_P.Out_Y0_f';     
         
xcp.parameters(197).symbol = 'Robot_leg_3_P.Zeros_Value_c';
xcp.parameters(197).size   =  12;       
xcp.parameters(197).dtname = 'real_T'; 
xcp.parameters(198).baseaddr = '&Robot_leg_3_P.Zeros_Value_c[0]';     
         
xcp.parameters(198).symbol = 'Robot_leg_3_P.Gain_Gain_i';
xcp.parameters(198).size   =  1;       
xcp.parameters(198).dtname = 'real_T'; 
xcp.parameters(199).baseaddr = '&Robot_leg_3_P.Gain_Gain_i';     
         
xcp.parameters(199).symbol = 'Robot_leg_3_P.Gain1_Gain_h';
xcp.parameters(199).size   =  1;       
xcp.parameters(199).dtname = 'real_T'; 
xcp.parameters(200).baseaddr = '&Robot_leg_3_P.Gain1_Gain_h';     
         
xcp.parameters(200).symbol = 'Robot_leg_3_P.Out_Y0_e';
xcp.parameters(200).size   =  1;       
xcp.parameters(200).dtname = 'real_T'; 
xcp.parameters(201).baseaddr = '&Robot_leg_3_P.Out_Y0_e';     
         
xcp.parameters(201).symbol = 'Robot_leg_3_P.Zeros_Value_d';
xcp.parameters(201).size   =  12;       
xcp.parameters(201).dtname = 'real_T'; 
xcp.parameters(202).baseaddr = '&Robot_leg_3_P.Zeros_Value_d[0]';     
         
xcp.parameters(202).symbol = 'Robot_leg_3_P.Gain_Gain_dr';
xcp.parameters(202).size   =  1;       
xcp.parameters(202).dtname = 'real_T'; 
xcp.parameters(203).baseaddr = '&Robot_leg_3_P.Gain_Gain_dr';     
         
xcp.parameters(203).symbol = 'Robot_leg_3_P.Gain1_Gain_p';
xcp.parameters(203).size   =  1;       
xcp.parameters(203).dtname = 'real_T'; 
xcp.parameters(204).baseaddr = '&Robot_leg_3_P.Gain1_Gain_p';     
         
xcp.parameters(204).symbol = 'Robot_leg_3_P.Out_Y0_d3';
xcp.parameters(204).size   =  1;       
xcp.parameters(204).dtname = 'real_T'; 
xcp.parameters(205).baseaddr = '&Robot_leg_3_P.Out_Y0_d3';     
         
xcp.parameters(205).symbol = 'Robot_leg_3_P.Zeros_Value_du';
xcp.parameters(205).size   =  12;       
xcp.parameters(205).dtname = 'real_T'; 
xcp.parameters(206).baseaddr = '&Robot_leg_3_P.Zeros_Value_du[0]';     
         
xcp.parameters(206).symbol = 'Robot_leg_3_P.GAIN_Gain_a';
xcp.parameters(206).size   =  1;       
xcp.parameters(206).dtname = 'real_T'; 
xcp.parameters(207).baseaddr = '&Robot_leg_3_P.GAIN_Gain_a';     
         
xcp.parameters(207).symbol = 'Robot_leg_3_P.GAIN_Gain_hy';
xcp.parameters(207).size   =  1;       
xcp.parameters(207).dtname = 'real_T'; 
xcp.parameters(208).baseaddr = '&Robot_leg_3_P.GAIN_Gain_hy';     
         
xcp.parameters(208).symbol = 'Robot_leg_3_P.GAIN_Gain_cu';
xcp.parameters(208).size   =  1;       
xcp.parameters(208).dtname = 'real_T'; 
xcp.parameters(209).baseaddr = '&Robot_leg_3_P.GAIN_Gain_cu';     
         
xcp.parameters(209).symbol = 'Robot_leg_3_P.GAIN_Gain_e';
xcp.parameters(209).size   =  1;       
xcp.parameters(209).dtname = 'real_T'; 
xcp.parameters(210).baseaddr = '&Robot_leg_3_P.GAIN_Gain_e';     
         
xcp.parameters(210).symbol = 'Robot_leg_3_P.GAIN_Gain_pv';
xcp.parameters(210).size   =  1;       
xcp.parameters(210).dtname = 'real_T'; 
xcp.parameters(211).baseaddr = '&Robot_leg_3_P.GAIN_Gain_pv';     
         
xcp.parameters(211).symbol = 'Robot_leg_3_P.GAIN_Gain_m';
xcp.parameters(211).size   =  1;       
xcp.parameters(211).dtname = 'real_T'; 
xcp.parameters(212).baseaddr = '&Robot_leg_3_P.GAIN_Gain_m';     
         
xcp.parameters(212).symbol = 'Robot_leg_3_P.DeadZone_Start';
xcp.parameters(212).size   =  1;       
xcp.parameters(212).dtname = 'real_T'; 
xcp.parameters(213).baseaddr = '&Robot_leg_3_P.DeadZone_Start';     
         
xcp.parameters(213).symbol = 'Robot_leg_3_P.DeadZone_End';
xcp.parameters(213).size   =  1;       
xcp.parameters(213).dtname = 'real_T'; 
xcp.parameters(214).baseaddr = '&Robot_leg_3_P.DeadZone_End';     
         
xcp.parameters(214).symbol = 'Robot_leg_3_P.Gain2_Gain';
xcp.parameters(214).size   =  1;       
xcp.parameters(214).dtname = 'real_T'; 
xcp.parameters(215).baseaddr = '&Robot_leg_3_P.Gain2_Gain';     
         
xcp.parameters(215).symbol = 'Robot_leg_3_P.Fx1_Value';
xcp.parameters(215).size   =  1;       
xcp.parameters(215).dtname = 'real_T'; 
xcp.parameters(216).baseaddr = '&Robot_leg_3_P.Fx1_Value';     
         
xcp.parameters(216).symbol = 'Robot_leg_3_P.Fx2_Value';
xcp.parameters(216).size   =  3;       
xcp.parameters(216).dtname = 'real_T'; 
xcp.parameters(217).baseaddr = '&Robot_leg_3_P.Fx2_Value[0]';     
         
xcp.parameters(217).symbol = 'Robot_leg_3_P.Gain_Gain_m';
xcp.parameters(217).size   =  1;       
xcp.parameters(217).dtname = 'real_T'; 
xcp.parameters(218).baseaddr = '&Robot_leg_3_P.Gain_Gain_m';     
         
xcp.parameters(218).symbol = 'Robot_leg_3_P.Fx_Value';
xcp.parameters(218).size   =  1;       
xcp.parameters(218).dtname = 'real_T'; 
xcp.parameters(219).baseaddr = '&Robot_leg_3_P.Fx_Value';     
         
xcp.parameters(219).symbol = 'Robot_leg_3_P.Gain_Gain';
xcp.parameters(219).size   =  1;       
xcp.parameters(219).dtname = 'real_T'; 
xcp.parameters(220).baseaddr = '&Robot_leg_3_P.Gain_Gain';     
         
xcp.parameters(220).symbol = 'Robot_leg_3_P.DeadZone_Start_b';
xcp.parameters(220).size   =  1;       
xcp.parameters(220).dtname = 'real_T'; 
xcp.parameters(221).baseaddr = '&Robot_leg_3_P.DeadZone_Start_b';     
         
xcp.parameters(221).symbol = 'Robot_leg_3_P.DeadZone_End_a';
xcp.parameters(221).size   =  1;       
xcp.parameters(221).dtname = 'real_T'; 
xcp.parameters(222).baseaddr = '&Robot_leg_3_P.DeadZone_End_a';     
         
xcp.parameters(222).symbol = 'Robot_leg_3_P.Gain2_Gain_m';
xcp.parameters(222).size   =  1;       
xcp.parameters(222).dtname = 'real_T'; 
xcp.parameters(223).baseaddr = '&Robot_leg_3_P.Gain2_Gain_m';     
         
xcp.parameters(223).symbol = 'Robot_leg_3_P.Fx1_Value_l';
xcp.parameters(223).size   =  1;       
xcp.parameters(223).dtname = 'real_T'; 
xcp.parameters(224).baseaddr = '&Robot_leg_3_P.Fx1_Value_l';     
         
xcp.parameters(224).symbol = 'Robot_leg_3_P.Fx2_Value_n';
xcp.parameters(224).size   =  3;       
xcp.parameters(224).dtname = 'real_T'; 
xcp.parameters(225).baseaddr = '&Robot_leg_3_P.Fx2_Value_n[0]';     
         
xcp.parameters(225).symbol = 'Robot_leg_3_P.Gain_Gain_j';
xcp.parameters(225).size   =  1;       
xcp.parameters(225).dtname = 'real_T'; 
xcp.parameters(226).baseaddr = '&Robot_leg_3_P.Gain_Gain_j';     
         
xcp.parameters(226).symbol = 'Robot_leg_3_P.Fx_Value_c';
xcp.parameters(226).size   =  1;       
xcp.parameters(226).dtname = 'real_T'; 
xcp.parameters(227).baseaddr = '&Robot_leg_3_P.Fx_Value_c';     
         
xcp.parameters(227).symbol = 'Robot_leg_3_P.Gain_Gain_n';
xcp.parameters(227).size   =  1;       
xcp.parameters(227).dtname = 'real_T'; 
xcp.parameters(228).baseaddr = '&Robot_leg_3_P.Gain_Gain_n';     
         
xcp.parameters(228).symbol = 'Robot_leg_3_P.DeadZone_Start_p';
xcp.parameters(228).size   =  1;       
xcp.parameters(228).dtname = 'real_T'; 
xcp.parameters(229).baseaddr = '&Robot_leg_3_P.DeadZone_Start_p';     
         
xcp.parameters(229).symbol = 'Robot_leg_3_P.DeadZone_End_i';
xcp.parameters(229).size   =  1;       
xcp.parameters(229).dtname = 'real_T'; 
xcp.parameters(230).baseaddr = '&Robot_leg_3_P.DeadZone_End_i';     
         
xcp.parameters(230).symbol = 'Robot_leg_3_P.Gain2_Gain_b';
xcp.parameters(230).size   =  1;       
xcp.parameters(230).dtname = 'real_T'; 
xcp.parameters(231).baseaddr = '&Robot_leg_3_P.Gain2_Gain_b';     
         
xcp.parameters(231).symbol = 'Robot_leg_3_P.Fx1_Value_g';
xcp.parameters(231).size   =  1;       
xcp.parameters(231).dtname = 'real_T'; 
xcp.parameters(232).baseaddr = '&Robot_leg_3_P.Fx1_Value_g';     
         
xcp.parameters(232).symbol = 'Robot_leg_3_P.Fx2_Value_j';
xcp.parameters(232).size   =  3;       
xcp.parameters(232).dtname = 'real_T'; 
xcp.parameters(233).baseaddr = '&Robot_leg_3_P.Fx2_Value_j[0]';     
         
xcp.parameters(233).symbol = 'Robot_leg_3_P.Gain_Gain_m4';
xcp.parameters(233).size   =  1;       
xcp.parameters(233).dtname = 'real_T'; 
xcp.parameters(234).baseaddr = '&Robot_leg_3_P.Gain_Gain_m4';     
         
xcp.parameters(234).symbol = 'Robot_leg_3_P.Fx_Value_j';
xcp.parameters(234).size   =  1;       
xcp.parameters(234).dtname = 'real_T'; 
xcp.parameters(235).baseaddr = '&Robot_leg_3_P.Fx_Value_j';     
         
xcp.parameters(235).symbol = 'Robot_leg_3_P.Gain_Gain_p';
xcp.parameters(235).size   =  1;       
xcp.parameters(235).dtname = 'real_T'; 
xcp.parameters(236).baseaddr = '&Robot_leg_3_P.Gain_Gain_p';     
         
xcp.parameters(236).symbol = 'Robot_leg_3_P.DeadZone_Start_a';
xcp.parameters(236).size   =  1;       
xcp.parameters(236).dtname = 'real_T'; 
xcp.parameters(237).baseaddr = '&Robot_leg_3_P.DeadZone_Start_a';     
         
xcp.parameters(237).symbol = 'Robot_leg_3_P.DeadZone_End_l';
xcp.parameters(237).size   =  1;       
xcp.parameters(237).dtname = 'real_T'; 
xcp.parameters(238).baseaddr = '&Robot_leg_3_P.DeadZone_End_l';     
         
xcp.parameters(238).symbol = 'Robot_leg_3_P.Gain2_Gain_p';
xcp.parameters(238).size   =  1;       
xcp.parameters(238).dtname = 'real_T'; 
xcp.parameters(239).baseaddr = '&Robot_leg_3_P.Gain2_Gain_p';     
         
xcp.parameters(239).symbol = 'Robot_leg_3_P.Fx1_Value_f';
xcp.parameters(239).size   =  1;       
xcp.parameters(239).dtname = 'real_T'; 
xcp.parameters(240).baseaddr = '&Robot_leg_3_P.Fx1_Value_f';     
         
xcp.parameters(240).symbol = 'Robot_leg_3_P.Fx2_Value_i';
xcp.parameters(240).size   =  3;       
xcp.parameters(240).dtname = 'real_T'; 
xcp.parameters(241).baseaddr = '&Robot_leg_3_P.Fx2_Value_i[0]';     
         
xcp.parameters(241).symbol = 'Robot_leg_3_P.Gain_Gain_a';
xcp.parameters(241).size   =  1;       
xcp.parameters(241).dtname = 'real_T'; 
xcp.parameters(242).baseaddr = '&Robot_leg_3_P.Gain_Gain_a';     
         
xcp.parameters(242).symbol = 'Robot_leg_3_P.Fx_Value_p';
xcp.parameters(242).size   =  1;       
xcp.parameters(242).dtname = 'real_T'; 
xcp.parameters(243).baseaddr = '&Robot_leg_3_P.Fx_Value_p';     
         
xcp.parameters(243).symbol = 'Robot_leg_3_P.Gain_Gain_h';
xcp.parameters(243).size   =  1;       
xcp.parameters(243).dtname = 'real_T'; 
xcp.parameters(244).baseaddr = '&Robot_leg_3_P.Gain_Gain_h';     
         
xcp.parameters(244).symbol = 'Robot_leg_3_P.GAIN_Gain_ci';
xcp.parameters(244).size   =  1;       
xcp.parameters(244).dtname = 'real_T'; 
xcp.parameters(245).baseaddr = '&Robot_leg_3_P.GAIN_Gain_ci';     
         
xcp.parameters(245).symbol = 'Robot_leg_3_P.GAIN_Gain_h';
xcp.parameters(245).size   =  1;       
xcp.parameters(245).dtname = 'real_T'; 
xcp.parameters(246).baseaddr = '&Robot_leg_3_P.GAIN_Gain_h';     
         
xcp.parameters(246).symbol = 'Robot_leg_3_P.GAIN_Gain_o';
xcp.parameters(246).size   =  1;       
xcp.parameters(246).dtname = 'real_T'; 
xcp.parameters(247).baseaddr = '&Robot_leg_3_P.GAIN_Gain_o';     
         
xcp.parameters(247).symbol = 'Robot_leg_3_P.GAIN_Gain_p';
xcp.parameters(247).size   =  1;       
xcp.parameters(247).dtname = 'real_T'; 
xcp.parameters(248).baseaddr = '&Robot_leg_3_P.GAIN_Gain_p';     
         
xcp.parameters(248).symbol = 'Robot_leg_3_P.GAIN_Gain_c';
xcp.parameters(248).size   =  1;       
xcp.parameters(248).dtname = 'real_T'; 
xcp.parameters(249).baseaddr = '&Robot_leg_3_P.GAIN_Gain_c';     
         
xcp.parameters(249).symbol = 'Robot_leg_3_P.GAIN_Gain_k';
xcp.parameters(249).size   =  1;       
xcp.parameters(249).dtname = 'real_T'; 
xcp.parameters(250).baseaddr = '&Robot_leg_3_P.GAIN_Gain_k';     
         
xcp.parameters(250).symbol = 'Robot_leg_3_P.DeadZone_Start_n';
xcp.parameters(250).size   =  1;       
xcp.parameters(250).dtname = 'real_T'; 
xcp.parameters(251).baseaddr = '&Robot_leg_3_P.DeadZone_Start_n';     
         
xcp.parameters(251).symbol = 'Robot_leg_3_P.DeadZone_End_ln';
xcp.parameters(251).size   =  1;       
xcp.parameters(251).dtname = 'real_T'; 
xcp.parameters(252).baseaddr = '&Robot_leg_3_P.DeadZone_End_ln';     
         
xcp.parameters(252).symbol = 'Robot_leg_3_P.Gain2_Gain_j';
xcp.parameters(252).size   =  1;       
xcp.parameters(252).dtname = 'real_T'; 
xcp.parameters(253).baseaddr = '&Robot_leg_3_P.Gain2_Gain_j';     
         
xcp.parameters(253).symbol = 'Robot_leg_3_P.Fx1_Value_c';
xcp.parameters(253).size   =  1;       
xcp.parameters(253).dtname = 'real_T'; 
xcp.parameters(254).baseaddr = '&Robot_leg_3_P.Fx1_Value_c';     
         
xcp.parameters(254).symbol = 'Robot_leg_3_P.Fx2_Value_o';
xcp.parameters(254).size   =  3;       
xcp.parameters(254).dtname = 'real_T'; 
xcp.parameters(255).baseaddr = '&Robot_leg_3_P.Fx2_Value_o[0]';     
         
xcp.parameters(255).symbol = 'Robot_leg_3_P.Gain_Gain_mo';
xcp.parameters(255).size   =  1;       
xcp.parameters(255).dtname = 'real_T'; 
xcp.parameters(256).baseaddr = '&Robot_leg_3_P.Gain_Gain_mo';     
         
xcp.parameters(256).symbol = 'Robot_leg_3_P.Fx_Value_o';
xcp.parameters(256).size   =  1;       
xcp.parameters(256).dtname = 'real_T'; 
xcp.parameters(257).baseaddr = '&Robot_leg_3_P.Fx_Value_o';     
         
xcp.parameters(257).symbol = 'Robot_leg_3_P.Gain_Gain_c';
xcp.parameters(257).size   =  1;       
xcp.parameters(257).dtname = 'real_T'; 
xcp.parameters(258).baseaddr = '&Robot_leg_3_P.Gain_Gain_c';     
         
xcp.parameters(258).symbol = 'Robot_leg_3_P.DeadZone_Start_i';
xcp.parameters(258).size   =  1;       
xcp.parameters(258).dtname = 'real_T'; 
xcp.parameters(259).baseaddr = '&Robot_leg_3_P.DeadZone_Start_i';     
         
xcp.parameters(259).symbol = 'Robot_leg_3_P.DeadZone_End_m';
xcp.parameters(259).size   =  1;       
xcp.parameters(259).dtname = 'real_T'; 
xcp.parameters(260).baseaddr = '&Robot_leg_3_P.DeadZone_End_m';     
         
xcp.parameters(260).symbol = 'Robot_leg_3_P.Gain2_Gain_f3';
xcp.parameters(260).size   =  1;       
xcp.parameters(260).dtname = 'real_T'; 
xcp.parameters(261).baseaddr = '&Robot_leg_3_P.Gain2_Gain_f3';     
         
xcp.parameters(261).symbol = 'Robot_leg_3_P.Fx1_Value_j';
xcp.parameters(261).size   =  1;       
xcp.parameters(261).dtname = 'real_T'; 
xcp.parameters(262).baseaddr = '&Robot_leg_3_P.Fx1_Value_j';     
         
xcp.parameters(262).symbol = 'Robot_leg_3_P.Fx2_Value_h';
xcp.parameters(262).size   =  3;       
xcp.parameters(262).dtname = 'real_T'; 
xcp.parameters(263).baseaddr = '&Robot_leg_3_P.Fx2_Value_h[0]';     
         
xcp.parameters(263).symbol = 'Robot_leg_3_P.Gain_Gain_b';
xcp.parameters(263).size   =  1;       
xcp.parameters(263).dtname = 'real_T'; 
xcp.parameters(264).baseaddr = '&Robot_leg_3_P.Gain_Gain_b';     
         
xcp.parameters(264).symbol = 'Robot_leg_3_P.Fx_Value_b';
xcp.parameters(264).size   =  1;       
xcp.parameters(264).dtname = 'real_T'; 
xcp.parameters(265).baseaddr = '&Robot_leg_3_P.Fx_Value_b';     
         
xcp.parameters(265).symbol = 'Robot_leg_3_P.Gain_Gain_mj';
xcp.parameters(265).size   =  1;       
xcp.parameters(265).dtname = 'real_T'; 
xcp.parameters(266).baseaddr = '&Robot_leg_3_P.Gain_Gain_mj';     
         
xcp.parameters(266).symbol = 'Robot_leg_3_P.DeadZone_Start_n5';
xcp.parameters(266).size   =  1;       
xcp.parameters(266).dtname = 'real_T'; 
xcp.parameters(267).baseaddr = '&Robot_leg_3_P.DeadZone_Start_n5';     
         
xcp.parameters(267).symbol = 'Robot_leg_3_P.DeadZone_End_k';
xcp.parameters(267).size   =  1;       
xcp.parameters(267).dtname = 'real_T'; 
xcp.parameters(268).baseaddr = '&Robot_leg_3_P.DeadZone_End_k';     
         
xcp.parameters(268).symbol = 'Robot_leg_3_P.Gain2_Gain_h';
xcp.parameters(268).size   =  1;       
xcp.parameters(268).dtname = 'real_T'; 
xcp.parameters(269).baseaddr = '&Robot_leg_3_P.Gain2_Gain_h';     
         
xcp.parameters(269).symbol = 'Robot_leg_3_P.Fx1_Value_k';
xcp.parameters(269).size   =  1;       
xcp.parameters(269).dtname = 'real_T'; 
xcp.parameters(270).baseaddr = '&Robot_leg_3_P.Fx1_Value_k';     
         
xcp.parameters(270).symbol = 'Robot_leg_3_P.Fx2_Value_ip';
xcp.parameters(270).size   =  3;       
xcp.parameters(270).dtname = 'real_T'; 
xcp.parameters(271).baseaddr = '&Robot_leg_3_P.Fx2_Value_ip[0]';     
         
xcp.parameters(271).symbol = 'Robot_leg_3_P.Gain_Gain_f';
xcp.parameters(271).size   =  1;       
xcp.parameters(271).dtname = 'real_T'; 
xcp.parameters(272).baseaddr = '&Robot_leg_3_P.Gain_Gain_f';     
         
xcp.parameters(272).symbol = 'Robot_leg_3_P.Fx_Value_l';
xcp.parameters(272).size   =  1;       
xcp.parameters(272).dtname = 'real_T'; 
xcp.parameters(273).baseaddr = '&Robot_leg_3_P.Fx_Value_l';     
         
xcp.parameters(273).symbol = 'Robot_leg_3_P.Gain_Gain_g';
xcp.parameters(273).size   =  1;       
xcp.parameters(273).dtname = 'real_T'; 
xcp.parameters(274).baseaddr = '&Robot_leg_3_P.Gain_Gain_g';     
         
xcp.parameters(274).symbol = 'Robot_leg_3_P.DeadZone_Start_o';
xcp.parameters(274).size   =  1;       
xcp.parameters(274).dtname = 'real_T'; 
xcp.parameters(275).baseaddr = '&Robot_leg_3_P.DeadZone_Start_o';     
         
xcp.parameters(275).symbol = 'Robot_leg_3_P.DeadZone_End_j';
xcp.parameters(275).size   =  1;       
xcp.parameters(275).dtname = 'real_T'; 
xcp.parameters(276).baseaddr = '&Robot_leg_3_P.DeadZone_End_j';     
         
xcp.parameters(276).symbol = 'Robot_leg_3_P.Gain2_Gain_e';
xcp.parameters(276).size   =  1;       
xcp.parameters(276).dtname = 'real_T'; 
xcp.parameters(277).baseaddr = '&Robot_leg_3_P.Gain2_Gain_e';     
         
xcp.parameters(277).symbol = 'Robot_leg_3_P.Fx1_Value_o';
xcp.parameters(277).size   =  1;       
xcp.parameters(277).dtname = 'real_T'; 
xcp.parameters(278).baseaddr = '&Robot_leg_3_P.Fx1_Value_o';     
         
xcp.parameters(278).symbol = 'Robot_leg_3_P.Fx2_Value_he';
xcp.parameters(278).size   =  3;       
xcp.parameters(278).dtname = 'real_T'; 
xcp.parameters(279).baseaddr = '&Robot_leg_3_P.Fx2_Value_he[0]';     
         
xcp.parameters(279).symbol = 'Robot_leg_3_P.Gain_Gain_jj';
xcp.parameters(279).size   =  1;       
xcp.parameters(279).dtname = 'real_T'; 
xcp.parameters(280).baseaddr = '&Robot_leg_3_P.Gain_Gain_jj';     
         
xcp.parameters(280).symbol = 'Robot_leg_3_P.Fx_Value_oe';
xcp.parameters(280).size   =  1;       
xcp.parameters(280).dtname = 'real_T'; 
xcp.parameters(281).baseaddr = '&Robot_leg_3_P.Fx_Value_oe';     
         
xcp.parameters(281).symbol = 'Robot_leg_3_P.Gain_Gain_ns';
xcp.parameters(281).size   =  1;       
xcp.parameters(281).dtname = 'real_T'; 
xcp.parameters(282).baseaddr = '&Robot_leg_3_P.Gain_Gain_ns';     
         
xcp.parameters(282).symbol = 'Robot_leg_3_P.Saturation_UpperSat';
xcp.parameters(282).size   =  1;       
xcp.parameters(282).dtname = 'real_T'; 
xcp.parameters(283).baseaddr = '&Robot_leg_3_P.Saturation_UpperSat';     
         
xcp.parameters(283).symbol = 'Robot_leg_3_P.Saturation_LowerSat';
xcp.parameters(283).size   =  1;       
xcp.parameters(283).dtname = 'real_T'; 
xcp.parameters(284).baseaddr = '&Robot_leg_3_P.Saturation_LowerSat';     
         
xcp.parameters(284).symbol = 'Robot_leg_3_P.Saturation_UpperSat_l';
xcp.parameters(284).size   =  1;       
xcp.parameters(284).dtname = 'real_T'; 
xcp.parameters(285).baseaddr = '&Robot_leg_3_P.Saturation_UpperSat_l';     
         
xcp.parameters(285).symbol = 'Robot_leg_3_P.Saturation_LowerSat_g';
xcp.parameters(285).size   =  1;       
xcp.parameters(285).dtname = 'real_T'; 
xcp.parameters(286).baseaddr = '&Robot_leg_3_P.Saturation_LowerSat_g';     
         
xcp.parameters(286).symbol = 'Robot_leg_3_P.Saturation_UpperSat_b';
xcp.parameters(286).size   =  1;       
xcp.parameters(286).dtname = 'real_T'; 
xcp.parameters(287).baseaddr = '&Robot_leg_3_P.Saturation_UpperSat_b';     
         
xcp.parameters(287).symbol = 'Robot_leg_3_P.Saturation_LowerSat_j';
xcp.parameters(287).size   =  1;       
xcp.parameters(287).dtname = 'real_T'; 
xcp.parameters(288).baseaddr = '&Robot_leg_3_P.Saturation_LowerSat_j';     
         
xcp.parameters(288).symbol = 'Robot_leg_3_P.Saturation_UpperSat_d';
xcp.parameters(288).size   =  1;       
xcp.parameters(288).dtname = 'real_T'; 
xcp.parameters(289).baseaddr = '&Robot_leg_3_P.Saturation_UpperSat_d';     
         
xcp.parameters(289).symbol = 'Robot_leg_3_P.Saturation_LowerSat_c';
xcp.parameters(289).size   =  1;       
xcp.parameters(289).dtname = 'real_T'; 
xcp.parameters(290).baseaddr = '&Robot_leg_3_P.Saturation_LowerSat_c';     
         
xcp.parameters(290).symbol = 'Robot_leg_3_P.Saturation_UpperSat_p';
xcp.parameters(290).size   =  1;       
xcp.parameters(290).dtname = 'real_T'; 
xcp.parameters(291).baseaddr = '&Robot_leg_3_P.Saturation_UpperSat_p';     
         
xcp.parameters(291).symbol = 'Robot_leg_3_P.Saturation_LowerSat_d';
xcp.parameters(291).size   =  1;       
xcp.parameters(291).dtname = 'real_T'; 
xcp.parameters(292).baseaddr = '&Robot_leg_3_P.Saturation_LowerSat_d';     
         
xcp.parameters(292).symbol = 'Robot_leg_3_P.Saturation_UpperSat_o';
xcp.parameters(292).size   =  1;       
xcp.parameters(292).dtname = 'real_T'; 
xcp.parameters(293).baseaddr = '&Robot_leg_3_P.Saturation_UpperSat_o';     
         
xcp.parameters(293).symbol = 'Robot_leg_3_P.Saturation_LowerSat_a';
xcp.parameters(293).size   =  1;       
xcp.parameters(293).dtname = 'real_T'; 
xcp.parameters(294).baseaddr = '&Robot_leg_3_P.Saturation_LowerSat_a';     
         
xcp.parameters(294).symbol = 'Robot_leg_3_P.Saturation_UpperSat_e';
xcp.parameters(294).size   =  1;       
xcp.parameters(294).dtname = 'real_T'; 
xcp.parameters(295).baseaddr = '&Robot_leg_3_P.Saturation_UpperSat_e';     
         
xcp.parameters(295).symbol = 'Robot_leg_3_P.Saturation_LowerSat_g5';
xcp.parameters(295).size   =  1;       
xcp.parameters(295).dtname = 'real_T'; 
xcp.parameters(296).baseaddr = '&Robot_leg_3_P.Saturation_LowerSat_g5';     
         
xcp.parameters(296).symbol = 'Robot_leg_3_P.Saturation_UpperSat_f';
xcp.parameters(296).size   =  1;       
xcp.parameters(296).dtname = 'real_T'; 
xcp.parameters(297).baseaddr = '&Robot_leg_3_P.Saturation_UpperSat_f';     
         
xcp.parameters(297).symbol = 'Robot_leg_3_P.Saturation_LowerSat_af';
xcp.parameters(297).size   =  1;       
xcp.parameters(297).dtname = 'real_T'; 
xcp.parameters(298).baseaddr = '&Robot_leg_3_P.Saturation_LowerSat_af';     
         
xcp.parameters(298).symbol = 'Robot_leg_3_P.Gain2_Gain_l';
xcp.parameters(298).size   =  1;       
xcp.parameters(298).dtname = 'real_T'; 
xcp.parameters(299).baseaddr = '&Robot_leg_3_P.Gain2_Gain_l';     
         
xcp.parameters(299).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVelocity';
xcp.parameters(299).size   =  6;       
xcp.parameters(299).dtname = 'real_T'; 
xcp.parameters(300).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVelocity[0]';     
         
xcp.parameters(300).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_l';
xcp.parameters(300).size   =  6;       
xcp.parameters(300).dtname = 'real_T'; 
xcp.parameters(301).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_l[0]';     
         
xcp.parameters(301).symbol = 'Robot_leg_3_P.Gain2_Gain_o';
xcp.parameters(301).size   =  1;       
xcp.parameters(301).dtname = 'real_T'; 
xcp.parameters(302).baseaddr = '&Robot_leg_3_P.Gain2_Gain_o';     
         
xcp.parameters(302).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_k';
xcp.parameters(302).size   =  6;       
xcp.parameters(302).dtname = 'real_T'; 
xcp.parameters(303).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_k[0]';     
         
xcp.parameters(303).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_j';
xcp.parameters(303).size   =  6;       
xcp.parameters(303).dtname = 'real_T'; 
xcp.parameters(304).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_j[0]';     
         
xcp.parameters(304).symbol = 'Robot_leg_3_P.Gain2_Gain_a';
xcp.parameters(304).size   =  1;       
xcp.parameters(304).dtname = 'real_T'; 
xcp.parameters(305).baseaddr = '&Robot_leg_3_P.Gain2_Gain_a';     
         
xcp.parameters(305).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_n';
xcp.parameters(305).size   =  6;       
xcp.parameters(305).dtname = 'real_T'; 
xcp.parameters(306).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_n[0]';     
         
xcp.parameters(306).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_d';
xcp.parameters(306).size   =  6;       
xcp.parameters(306).dtname = 'real_T'; 
xcp.parameters(307).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_d[0]';     
         
xcp.parameters(307).symbol = 'Robot_leg_3_P.Gain2_Gain_f';
xcp.parameters(307).size   =  1;       
xcp.parameters(307).dtname = 'real_T'; 
xcp.parameters(308).baseaddr = '&Robot_leg_3_P.Gain2_Gain_f';     
         
xcp.parameters(308).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_p';
xcp.parameters(308).size   =  6;       
xcp.parameters(308).dtname = 'real_T'; 
xcp.parameters(309).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_p[0]';     
         
xcp.parameters(309).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_a';
xcp.parameters(309).size   =  6;       
xcp.parameters(309).dtname = 'real_T'; 
xcp.parameters(310).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_a[0]';     
         
xcp.parameters(310).symbol = 'Robot_leg_3_P.Gain2_Gain_c';
xcp.parameters(310).size   =  1;       
xcp.parameters(310).dtname = 'real_T'; 
xcp.parameters(311).baseaddr = '&Robot_leg_3_P.Gain2_Gain_c';     
         
xcp.parameters(311).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_i';
xcp.parameters(311).size   =  6;       
xcp.parameters(311).dtname = 'real_T'; 
xcp.parameters(312).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_i[0]';     
         
xcp.parameters(312).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloc_ao';
xcp.parameters(312).size   =  6;       
xcp.parameters(312).dtname = 'real_T'; 
xcp.parameters(313).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloc_ao[0]';     
         
xcp.parameters(313).symbol = 'Robot_leg_3_P.Gain2_Gain_fy';
xcp.parameters(313).size   =  1;       
xcp.parameters(313).dtname = 'real_T'; 
xcp.parameters(314).baseaddr = '&Robot_leg_3_P.Gain2_Gain_fy';     
         
xcp.parameters(314).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloci_m';
xcp.parameters(314).size   =  6;       
xcp.parameters(314).dtname = 'real_T'; 
xcp.parameters(315).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloci_m[0]';     
         
xcp.parameters(315).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloc_mt';
xcp.parameters(315).size   =  6;       
xcp.parameters(315).dtname = 'real_T'; 
xcp.parameters(316).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloc_mt[0]';     
         
xcp.parameters(316).symbol = 'Robot_leg_3_P.Gain2_Gain_f1';
xcp.parameters(316).size   =  1;       
xcp.parameters(316).dtname = 'real_T'; 
xcp.parameters(317).baseaddr = '&Robot_leg_3_P.Gain2_Gain_f1';     
         
xcp.parameters(317).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloc_nk';
xcp.parameters(317).size   =  6;       
xcp.parameters(317).dtname = 'real_T'; 
xcp.parameters(318).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloc_nk[0]';     
         
xcp.parameters(318).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloc_ab';
xcp.parameters(318).size   =  6;       
xcp.parameters(318).dtname = 'real_T'; 
xcp.parameters(319).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloc_ab[0]';     
         
xcp.parameters(319).symbol = 'Robot_leg_3_P.Gain2_Gain_n';
xcp.parameters(319).size   =  1;       
xcp.parameters(319).dtname = 'real_T'; 
xcp.parameters(320).baseaddr = '&Robot_leg_3_P.Gain2_Gain_n';     
         
xcp.parameters(320).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloc_in';
xcp.parameters(320).size   =  6;       
xcp.parameters(320).dtname = 'real_T'; 
xcp.parameters(321).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloc_in[0]';     
         
xcp.parameters(321).symbol = 'Robot_leg_3_P.CoefficientofFrictionvsVeloc_lt';
xcp.parameters(321).size   =  6;       
xcp.parameters(321).dtname = 'real_T'; 
xcp.parameters(322).baseaddr = '&Robot_leg_3_P.CoefficientofFrictionvsVeloc_lt[0]';     
         
xcp.parameters(322).symbol = 'Robot_leg_3_P.left_theta_1';
xcp.parameters(322).size   =  40;       
xcp.parameters(322).dtname = 'real_T'; 
xcp.parameters(323).baseaddr = '&Robot_leg_3_P.left_theta_1[0]';     
         
xcp.parameters(323).symbol = 'Robot_leg_3_P.left_theta_2';
xcp.parameters(323).size   =  40;       
xcp.parameters(323).dtname = 'real_T'; 
xcp.parameters(324).baseaddr = '&Robot_leg_3_P.left_theta_2[0]';     
         
xcp.parameters(324).symbol = 'Robot_leg_3_P.left_theta_3';
xcp.parameters(324).size   =  40;       
xcp.parameters(324).dtname = 'real_T'; 
xcp.parameters(325).baseaddr = '&Robot_leg_3_P.left_theta_3[0]';     
         
xcp.parameters(325).symbol = 'Robot_leg_3_P.left_theta_4';
xcp.parameters(325).size   =  40;       
xcp.parameters(325).dtname = 'real_T'; 
xcp.parameters(326).baseaddr = '&Robot_leg_3_P.left_theta_4[0]';     
         
xcp.parameters(326).symbol = 'Robot_leg_3_P.left_theta_5';
xcp.parameters(326).size   =  40;       
xcp.parameters(326).dtname = 'real_T'; 
xcp.parameters(327).baseaddr = '&Robot_leg_3_P.left_theta_5[0]';     
         
xcp.parameters(327).symbol = 'Robot_leg_3_P.left_theta_6';
xcp.parameters(327).size   =  40;       
xcp.parameters(327).dtname = 'real_T'; 
xcp.parameters(328).baseaddr = '&Robot_leg_3_P.left_theta_6[0]';     
         
xcp.parameters(328).symbol = 'Robot_leg_3_P.left_theta_first_1';
xcp.parameters(328).size   =  20;       
xcp.parameters(328).dtname = 'real_T'; 
xcp.parameters(329).baseaddr = '&Robot_leg_3_P.left_theta_first_1[0]';     
         
xcp.parameters(329).symbol = 'Robot_leg_3_P.left_theta_first_2';
xcp.parameters(329).size   =  20;       
xcp.parameters(329).dtname = 'real_T'; 
xcp.parameters(330).baseaddr = '&Robot_leg_3_P.left_theta_first_2[0]';     
         
xcp.parameters(330).symbol = 'Robot_leg_3_P.left_theta_first_3';
xcp.parameters(330).size   =  20;       
xcp.parameters(330).dtname = 'real_T'; 
xcp.parameters(331).baseaddr = '&Robot_leg_3_P.left_theta_first_3[0]';     
         
xcp.parameters(331).symbol = 'Robot_leg_3_P.left_theta_first_4';
xcp.parameters(331).size   =  40;       
xcp.parameters(331).dtname = 'real_T'; 
xcp.parameters(332).baseaddr = '&Robot_leg_3_P.left_theta_first_4[0]';     
         
xcp.parameters(332).symbol = 'Robot_leg_3_P.left_theta_first_5';
xcp.parameters(332).size   =  40;       
xcp.parameters(332).dtname = 'real_T'; 
xcp.parameters(333).baseaddr = '&Robot_leg_3_P.left_theta_first_5[0]';     
         
xcp.parameters(333).symbol = 'Robot_leg_3_P.left_theta_first_6';
xcp.parameters(333).size   =  20;       
xcp.parameters(333).dtname = 'real_T'; 
xcp.parameters(334).baseaddr = '&Robot_leg_3_P.left_theta_first_6[0]';     
         
xcp.parameters(334).symbol = 'Robot_leg_3_P.left_theta_init_1';
xcp.parameters(334).size   =  40;       
xcp.parameters(334).dtname = 'real_T'; 
xcp.parameters(335).baseaddr = '&Robot_leg_3_P.left_theta_init_1[0]';     
         
xcp.parameters(335).symbol = 'Robot_leg_3_P.left_theta_init_2';
xcp.parameters(335).size   =  40;       
xcp.parameters(335).dtname = 'real_T'; 
xcp.parameters(336).baseaddr = '&Robot_leg_3_P.left_theta_init_2[0]';     
         
xcp.parameters(336).symbol = 'Robot_leg_3_P.left_theta_init_3';
xcp.parameters(336).size   =  40;       
xcp.parameters(336).dtname = 'real_T'; 
xcp.parameters(337).baseaddr = '&Robot_leg_3_P.left_theta_init_3[0]';     
         
xcp.parameters(337).symbol = 'Robot_leg_3_P.left_theta_init_4';
xcp.parameters(337).size   =  40;       
xcp.parameters(337).dtname = 'real_T'; 
xcp.parameters(338).baseaddr = '&Robot_leg_3_P.left_theta_init_4[0]';     
         
xcp.parameters(338).symbol = 'Robot_leg_3_P.left_theta_init_5';
xcp.parameters(338).size   =  40;       
xcp.parameters(338).dtname = 'real_T'; 
xcp.parameters(339).baseaddr = '&Robot_leg_3_P.left_theta_init_5[0]';     
         
xcp.parameters(339).symbol = 'Robot_leg_3_P.left_theta_init_6';
xcp.parameters(339).size   =  40;       
xcp.parameters(339).dtname = 'real_T'; 
xcp.parameters(340).baseaddr = '&Robot_leg_3_P.left_theta_init_6[0]';     
         
xcp.parameters(340).symbol = 'Robot_leg_3_P.left_theta_pos_1';
xcp.parameters(340).size   =  40;       
xcp.parameters(340).dtname = 'real_T'; 
xcp.parameters(341).baseaddr = '&Robot_leg_3_P.left_theta_pos_1[0]';     
         
xcp.parameters(341).symbol = 'Robot_leg_3_P.left_theta_pos_2';
xcp.parameters(341).size   =  40;       
xcp.parameters(341).dtname = 'real_T'; 
xcp.parameters(342).baseaddr = '&Robot_leg_3_P.left_theta_pos_2[0]';     
         
xcp.parameters(342).symbol = 'Robot_leg_3_P.left_theta_pos_3';
xcp.parameters(342).size   =  40;       
xcp.parameters(342).dtname = 'real_T'; 
xcp.parameters(343).baseaddr = '&Robot_leg_3_P.left_theta_pos_3[0]';     
         
xcp.parameters(343).symbol = 'Robot_leg_3_P.left_theta_pos_4';
xcp.parameters(343).size   =  40;       
xcp.parameters(343).dtname = 'real_T'; 
xcp.parameters(344).baseaddr = '&Robot_leg_3_P.left_theta_pos_4[0]';     
         
xcp.parameters(344).symbol = 'Robot_leg_3_P.left_theta_pos_5';
xcp.parameters(344).size   =  40;       
xcp.parameters(344).dtname = 'real_T'; 
xcp.parameters(345).baseaddr = '&Robot_leg_3_P.left_theta_pos_5[0]';     
         
xcp.parameters(345).symbol = 'Robot_leg_3_P.left_theta_pos_6';
xcp.parameters(345).size   =  40;       
xcp.parameters(345).dtname = 'real_T'; 
xcp.parameters(346).baseaddr = '&Robot_leg_3_P.left_theta_pos_6[0]';     
         
xcp.parameters(346).symbol = 'Robot_leg_3_P.right_theta_1';
xcp.parameters(346).size   =  40;       
xcp.parameters(346).dtname = 'real_T'; 
xcp.parameters(347).baseaddr = '&Robot_leg_3_P.right_theta_1[0]';     
         
xcp.parameters(347).symbol = 'Robot_leg_3_P.right_theta_2';
xcp.parameters(347).size   =  40;       
xcp.parameters(347).dtname = 'real_T'; 
xcp.parameters(348).baseaddr = '&Robot_leg_3_P.right_theta_2[0]';     
         
xcp.parameters(348).symbol = 'Robot_leg_3_P.right_theta_3';
xcp.parameters(348).size   =  40;       
xcp.parameters(348).dtname = 'real_T'; 
xcp.parameters(349).baseaddr = '&Robot_leg_3_P.right_theta_3[0]';     
         
xcp.parameters(349).symbol = 'Robot_leg_3_P.right_theta_4';
xcp.parameters(349).size   =  40;       
xcp.parameters(349).dtname = 'real_T'; 
xcp.parameters(350).baseaddr = '&Robot_leg_3_P.right_theta_4[0]';     
         
xcp.parameters(350).symbol = 'Robot_leg_3_P.right_theta_5';
xcp.parameters(350).size   =  40;       
xcp.parameters(350).dtname = 'real_T'; 
xcp.parameters(351).baseaddr = '&Robot_leg_3_P.right_theta_5[0]';     
         
xcp.parameters(351).symbol = 'Robot_leg_3_P.right_theta_6';
xcp.parameters(351).size   =  40;       
xcp.parameters(351).dtname = 'real_T'; 
xcp.parameters(352).baseaddr = '&Robot_leg_3_P.right_theta_6[0]';     
         
xcp.parameters(352).symbol = 'Robot_leg_3_P.right_theta_first_1';
xcp.parameters(352).size   =  40;       
xcp.parameters(352).dtname = 'real_T'; 
xcp.parameters(353).baseaddr = '&Robot_leg_3_P.right_theta_first_1[0]';     
         
xcp.parameters(353).symbol = 'Robot_leg_3_P.right_theta_first_2';
xcp.parameters(353).size   =  40;       
xcp.parameters(353).dtname = 'real_T'; 
xcp.parameters(354).baseaddr = '&Robot_leg_3_P.right_theta_first_2[0]';     
         
xcp.parameters(354).symbol = 'Robot_leg_3_P.right_theta_first_3';
xcp.parameters(354).size   =  40;       
xcp.parameters(354).dtname = 'real_T'; 
xcp.parameters(355).baseaddr = '&Robot_leg_3_P.right_theta_first_3[0]';     
         
xcp.parameters(355).symbol = 'Robot_leg_3_P.right_theta_first_4';
xcp.parameters(355).size   =  40;       
xcp.parameters(355).dtname = 'real_T'; 
xcp.parameters(356).baseaddr = '&Robot_leg_3_P.right_theta_first_4[0]';     
         
xcp.parameters(356).symbol = 'Robot_leg_3_P.right_theta_first_5';
xcp.parameters(356).size   =  40;       
xcp.parameters(356).dtname = 'real_T'; 
xcp.parameters(357).baseaddr = '&Robot_leg_3_P.right_theta_first_5[0]';     
         
xcp.parameters(357).symbol = 'Robot_leg_3_P.right_theta_first_6';
xcp.parameters(357).size   =  20;       
xcp.parameters(357).dtname = 'real_T'; 
xcp.parameters(358).baseaddr = '&Robot_leg_3_P.right_theta_first_6[0]';     
         
xcp.parameters(358).symbol = 'Robot_leg_3_P.right_theta_init_1';
xcp.parameters(358).size   =  40;       
xcp.parameters(358).dtname = 'real_T'; 
xcp.parameters(359).baseaddr = '&Robot_leg_3_P.right_theta_init_1[0]';     
         
xcp.parameters(359).symbol = 'Robot_leg_3_P.right_theta_init_2';
xcp.parameters(359).size   =  40;       
xcp.parameters(359).dtname = 'real_T'; 
xcp.parameters(360).baseaddr = '&Robot_leg_3_P.right_theta_init_2[0]';     
         
xcp.parameters(360).symbol = 'Robot_leg_3_P.right_theta_init_3';
xcp.parameters(360).size   =  40;       
xcp.parameters(360).dtname = 'real_T'; 
xcp.parameters(361).baseaddr = '&Robot_leg_3_P.right_theta_init_3[0]';     
         
xcp.parameters(361).symbol = 'Robot_leg_3_P.right_theta_init_4';
xcp.parameters(361).size   =  40;       
xcp.parameters(361).dtname = 'real_T'; 
xcp.parameters(362).baseaddr = '&Robot_leg_3_P.right_theta_init_4[0]';     
         
xcp.parameters(362).symbol = 'Robot_leg_3_P.right_theta_init_5';
xcp.parameters(362).size   =  40;       
xcp.parameters(362).dtname = 'real_T'; 
xcp.parameters(363).baseaddr = '&Robot_leg_3_P.right_theta_init_5[0]';     
         
xcp.parameters(363).symbol = 'Robot_leg_3_P.right_theta_init_6';
xcp.parameters(363).size   =  40;       
xcp.parameters(363).dtname = 'real_T'; 
xcp.parameters(364).baseaddr = '&Robot_leg_3_P.right_theta_init_6[0]';     
         
xcp.parameters(364).symbol = 'Robot_leg_3_P.right_theta_pos_1';
xcp.parameters(364).size   =  40;       
xcp.parameters(364).dtname = 'real_T'; 
xcp.parameters(365).baseaddr = '&Robot_leg_3_P.right_theta_pos_1[0]';     
         
xcp.parameters(365).symbol = 'Robot_leg_3_P.right_theta_pos_2';
xcp.parameters(365).size   =  40;       
xcp.parameters(365).dtname = 'real_T'; 
xcp.parameters(366).baseaddr = '&Robot_leg_3_P.right_theta_pos_2[0]';     
         
xcp.parameters(366).symbol = 'Robot_leg_3_P.right_theta_pos_3';
xcp.parameters(366).size   =  40;       
xcp.parameters(366).dtname = 'real_T'; 
xcp.parameters(367).baseaddr = '&Robot_leg_3_P.right_theta_pos_3[0]';     
         
xcp.parameters(367).symbol = 'Robot_leg_3_P.right_theta_pos_4';
xcp.parameters(367).size   =  40;       
xcp.parameters(367).dtname = 'real_T'; 
xcp.parameters(368).baseaddr = '&Robot_leg_3_P.right_theta_pos_4[0]';     
         
xcp.parameters(368).symbol = 'Robot_leg_3_P.right_theta_pos_5';
xcp.parameters(368).size   =  40;       
xcp.parameters(368).dtname = 'real_T'; 
xcp.parameters(369).baseaddr = '&Robot_leg_3_P.right_theta_pos_5[0]';     
         
xcp.parameters(369).symbol = 'Robot_leg_3_P.right_theta_pos_6';
xcp.parameters(369).size   =  40;       
xcp.parameters(369).dtname = 'real_T'; 
xcp.parameters(370).baseaddr = '&Robot_leg_3_P.right_theta_pos_6[0]';     
         
xcp.parameters(370).symbol = 'Robot_leg_3_P.u1';
xcp.parameters(370).size   =  40;       
xcp.parameters(370).dtname = 'real_T'; 
xcp.parameters(371).baseaddr = '&Robot_leg_3_P.u1[0]';     

function n = getNumParameters
n = 370;

function n = getNumSignals
n = 975;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

