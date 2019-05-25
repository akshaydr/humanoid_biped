function bio=Robot_leg_3bio
bio = [];
bio(1).blkName='Robot/Switch';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[6,1];
bio(1).sigWidth=6;
bio(1).sigAddress='&Robot_leg_3_B.Switch[0]';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

bio(2).blkName='Robot/Switch1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[6,1];
bio(2).sigWidth=6;
bio(2).sigAddress='&Robot_leg_3_B.Switch1[0]';
bio(2).ndims=2;
bio(2).size=[];
bio(2).isStruct=false;

bio(3).blkName='Robot/Switch2';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[6,1];
bio(3).sigWidth=6;
bio(3).sigAddress='&Robot_leg_3_B.Switch2[0]';
bio(3).ndims=2;
bio(3).size=[];
bio(3).isStruct=false;

bio(4).blkName='Robot/Switch3';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[6,1];
bio(4).sigWidth=6;
bio(4).sigAddress='&Robot_leg_3_B.Switch3[0]';
bio(4).ndims=2;
bio(4).size=[];
bio(4).isStruct=false;

bio(5).blkName='Robot/Switch4';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[6,1];
bio(5).sigWidth=6;
bio(5).sigAddress='&Robot_leg_3_B.Switch4[0]';
bio(5).ndims=2;
bio(5).size=[];
bio(5).isStruct=false;

bio(6).blkName='Robot/Switch5';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[6,1];
bio(6).sigWidth=6;
bio(6).sigAddress='&Robot_leg_3_B.Switch5[0]';
bio(6).ndims=2;
bio(6).size=[];
bio(6).isStruct=false;

bio(7).blkName='PS-Simulink Converter/EVAL_KEY/GAIN';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&Robot_leg_3_B.GAIN';
bio(7).ndims=2;
bio(7).size=[];
bio(7).isStruct=false;

bio(8).blkName='Robot/If Action Subsystem/In1';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&Robot_leg_3_B.IfActionSubsystem.In1';
bio(8).ndims=2;
bio(8).size=[];
bio(8).isStruct=false;

bio(9).blkName='Robot/If Action Subsystem1/In1';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&Robot_leg_3_B.IfActionSubsystem1.In1';
bio(9).ndims=2;
bio(9).size=[];
bio(9).isStruct=false;

bio(10).blkName='Robot/If Action Subsystem3/In1';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&Robot_leg_3_B.IfActionSubsystem3.In1';
bio(10).ndims=2;
bio(10).size=[];
bio(10).isStruct=false;

bio(11).blkName='Robot/If Action Subsystem4/In1';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&Robot_leg_3_B.IfActionSubsystem4.In1';
bio(11).ndims=2;
bio(11).size=[];
bio(11).isStruct=false;

bio(12).blkName='Robot/If Action Subsystem5/In1';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&Robot_leg_3_B.IfActionSubsystem5.In1';
bio(12).ndims=2;
bio(12).size=[];
bio(12).isStruct=false;

bio(13).blkName='Robot/If Action Subsystem6/In1';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&Robot_leg_3_B.IfActionSubsystem6.In1';
bio(13).ndims=2;
bio(13).size=[];
bio(13).isStruct=false;

bio(14).blkName='Robot/u1_value /Clock';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&Robot_leg_3_B.Clock_j';
bio(14).ndims=2;
bio(14).size=[];
bio(14).isStruct=false;

bio(15).blkName='Robot/u1_value /Output';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&Robot_leg_3_B.Output';
bio(15).ndims=2;
bio(15).size=[];
bio(15).isStruct=false;

bio(16).blkName='Robot/u1_value /Look-Up Table1';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&Robot_leg_3_B.LookUpTable1_b';
bio(16).ndims=2;
bio(16).size=[];
bio(16).isStruct=false;

bio(17).blkName='Robot/u1_value /Math Function';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&Robot_leg_3_B.MathFunction_d';
bio(17).ndims=2;
bio(17).size=[];
bio(17).isStruct=false;

bio(18).blkName='Robot/u1_value /Sum';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&Robot_leg_3_B.Sum_o';
bio(18).ndims=2;
bio(18).size=[];
bio(18).isStruct=false;

bio(19).blkName='Solver Configuration/EVAL_KEY/INPUT_10_1_1';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[4,1];
bio(19).sigWidth=4;
bio(19).sigAddress='&Robot_leg_3_B.INPUT_10_1_1[0]';
bio(19).ndims=2;
bio(19).size=[];
bio(19).isStruct=false;

bio(20).blkName='Solver Configuration/EVAL_KEY/INPUT_10_1_2';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[4,1];
bio(20).sigWidth=4;
bio(20).sigAddress='&Robot_leg_3_B.INPUT_10_1_2[0]';
bio(20).ndims=2;
bio(20).size=[];
bio(20).isStruct=false;

bio(21).blkName='Solver Configuration/EVAL_KEY/INPUT_10_1_3';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[4,1];
bio(21).sigWidth=4;
bio(21).sigAddress='&Robot_leg_3_B.INPUT_10_1_3[0]';
bio(21).ndims=2;
bio(21).size=[];
bio(21).isStruct=false;

bio(22).blkName='Solver Configuration/EVAL_KEY/INPUT_11_1_1';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[4,1];
bio(22).sigWidth=4;
bio(22).sigAddress='&Robot_leg_3_B.INPUT_11_1_1[0]';
bio(22).ndims=2;
bio(22).size=[];
bio(22).isStruct=false;

bio(23).blkName='Solver Configuration/EVAL_KEY/INPUT_11_1_2';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[4,1];
bio(23).sigWidth=4;
bio(23).sigAddress='&Robot_leg_3_B.INPUT_11_1_2[0]';
bio(23).ndims=2;
bio(23).size=[];
bio(23).isStruct=false;

bio(24).blkName='Solver Configuration/EVAL_KEY/INPUT_11_1_3';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[4,1];
bio(24).sigWidth=4;
bio(24).sigAddress='&Robot_leg_3_B.INPUT_11_1_3[0]';
bio(24).ndims=2;
bio(24).size=[];
bio(24).isStruct=false;

bio(25).blkName='Solver Configuration/EVAL_KEY/INPUT_12_1_1';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[4,1];
bio(25).sigWidth=4;
bio(25).sigAddress='&Robot_leg_3_B.INPUT_12_1_1[0]';
bio(25).ndims=2;
bio(25).size=[];
bio(25).isStruct=false;

bio(26).blkName='Solver Configuration/EVAL_KEY/INPUT_12_1_2';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[4,1];
bio(26).sigWidth=4;
bio(26).sigAddress='&Robot_leg_3_B.INPUT_12_1_2[0]';
bio(26).ndims=2;
bio(26).size=[];
bio(26).isStruct=false;

bio(27).blkName='Solver Configuration/EVAL_KEY/INPUT_12_1_3';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[4,1];
bio(27).sigWidth=4;
bio(27).sigAddress='&Robot_leg_3_B.INPUT_12_1_3[0]';
bio(27).ndims=2;
bio(27).size=[];
bio(27).isStruct=false;

bio(28).blkName='Solver Configuration/EVAL_KEY/INPUT_13_1_1';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[4,1];
bio(28).sigWidth=4;
bio(28).sigAddress='&Robot_leg_3_B.INPUT_13_1_1[0]';
bio(28).ndims=2;
bio(28).size=[];
bio(28).isStruct=false;

bio(29).blkName='Solver Configuration/EVAL_KEY/INPUT_13_1_2';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[4,1];
bio(29).sigWidth=4;
bio(29).sigAddress='&Robot_leg_3_B.INPUT_13_1_2[0]';
bio(29).ndims=2;
bio(29).size=[];
bio(29).isStruct=false;

bio(30).blkName='Solver Configuration/EVAL_KEY/INPUT_13_1_3';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[4,1];
bio(30).sigWidth=4;
bio(30).sigAddress='&Robot_leg_3_B.INPUT_13_1_3[0]';
bio(30).ndims=2;
bio(30).size=[];
bio(30).isStruct=false;

bio(31).blkName='Solver Configuration/EVAL_KEY/INPUT_14_1_1';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[4,1];
bio(31).sigWidth=4;
bio(31).sigAddress='&Robot_leg_3_B.INPUT_14_1_1[0]';
bio(31).ndims=2;
bio(31).size=[];
bio(31).isStruct=false;

bio(32).blkName='Solver Configuration/EVAL_KEY/INPUT_14_1_2';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[4,1];
bio(32).sigWidth=4;
bio(32).sigAddress='&Robot_leg_3_B.INPUT_14_1_2[0]';
bio(32).ndims=2;
bio(32).size=[];
bio(32).isStruct=false;

bio(33).blkName='Solver Configuration/EVAL_KEY/INPUT_14_1_3';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[4,1];
bio(33).sigWidth=4;
bio(33).sigAddress='&Robot_leg_3_B.INPUT_14_1_3[0]';
bio(33).ndims=2;
bio(33).size=[];
bio(33).isStruct=false;

bio(34).blkName='Solver Configuration/EVAL_KEY/INPUT_15_1_1';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[4,1];
bio(34).sigWidth=4;
bio(34).sigAddress='&Robot_leg_3_B.INPUT_15_1_1[0]';
bio(34).ndims=2;
bio(34).size=[];
bio(34).isStruct=false;

bio(35).blkName='Solver Configuration/EVAL_KEY/INPUT_15_1_2';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[4,1];
bio(35).sigWidth=4;
bio(35).sigAddress='&Robot_leg_3_B.INPUT_15_1_2[0]';
bio(35).ndims=2;
bio(35).size=[];
bio(35).isStruct=false;

bio(36).blkName='Solver Configuration/EVAL_KEY/INPUT_15_1_3';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[4,1];
bio(36).sigWidth=4;
bio(36).sigAddress='&Robot_leg_3_B.INPUT_15_1_3[0]';
bio(36).ndims=2;
bio(36).size=[];
bio(36).isStruct=false;

bio(37).blkName='Solver Configuration/EVAL_KEY/INPUT_16_1_1';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[4,1];
bio(37).sigWidth=4;
bio(37).sigAddress='&Robot_leg_3_B.INPUT_16_1_1[0]';
bio(37).ndims=2;
bio(37).size=[];
bio(37).isStruct=false;

bio(38).blkName='Solver Configuration/EVAL_KEY/INPUT_16_1_2';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[4,1];
bio(38).sigWidth=4;
bio(38).sigAddress='&Robot_leg_3_B.INPUT_16_1_2[0]';
bio(38).ndims=2;
bio(38).size=[];
bio(38).isStruct=false;

bio(39).blkName='Solver Configuration/EVAL_KEY/INPUT_16_1_3';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[4,1];
bio(39).sigWidth=4;
bio(39).sigAddress='&Robot_leg_3_B.INPUT_16_1_3[0]';
bio(39).ndims=2;
bio(39).size=[];
bio(39).isStruct=false;

bio(40).blkName='Solver Configuration/EVAL_KEY/INPUT_17_1_1';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[4,1];
bio(40).sigWidth=4;
bio(40).sigAddress='&Robot_leg_3_B.INPUT_17_1_1[0]';
bio(40).ndims=2;
bio(40).size=[];
bio(40).isStruct=false;

bio(41).blkName='Solver Configuration/EVAL_KEY/INPUT_17_1_2';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[4,1];
bio(41).sigWidth=4;
bio(41).sigAddress='&Robot_leg_3_B.INPUT_17_1_2[0]';
bio(41).ndims=2;
bio(41).size=[];
bio(41).isStruct=false;

bio(42).blkName='Solver Configuration/EVAL_KEY/INPUT_17_1_3';
bio(42).sigName='';
bio(42).portIdx=0;
bio(42).dim=[4,1];
bio(42).sigWidth=4;
bio(42).sigAddress='&Robot_leg_3_B.INPUT_17_1_3[0]';
bio(42).ndims=2;
bio(42).size=[];
bio(42).isStruct=false;

bio(43).blkName='Solver Configuration/EVAL_KEY/INPUT_18_1_1';
bio(43).sigName='';
bio(43).portIdx=0;
bio(43).dim=[4,1];
bio(43).sigWidth=4;
bio(43).sigAddress='&Robot_leg_3_B.INPUT_18_1_1[0]';
bio(43).ndims=2;
bio(43).size=[];
bio(43).isStruct=false;

bio(44).blkName='Solver Configuration/EVAL_KEY/INPUT_18_1_2';
bio(44).sigName='';
bio(44).portIdx=0;
bio(44).dim=[4,1];
bio(44).sigWidth=4;
bio(44).sigAddress='&Robot_leg_3_B.INPUT_18_1_2[0]';
bio(44).ndims=2;
bio(44).size=[];
bio(44).isStruct=false;

bio(45).blkName='Solver Configuration/EVAL_KEY/INPUT_18_1_3';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[4,1];
bio(45).sigWidth=4;
bio(45).sigAddress='&Robot_leg_3_B.INPUT_18_1_3[0]';
bio(45).ndims=2;
bio(45).size=[];
bio(45).isStruct=false;

bio(46).blkName='Solver Configuration/EVAL_KEY/INPUT_19_1_1';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[4,1];
bio(46).sigWidth=4;
bio(46).sigAddress='&Robot_leg_3_B.INPUT_19_1_1[0]';
bio(46).ndims=2;
bio(46).size=[];
bio(46).isStruct=false;

bio(47).blkName='Solver Configuration/EVAL_KEY/INPUT_19_1_2';
bio(47).sigName='';
bio(47).portIdx=0;
bio(47).dim=[4,1];
bio(47).sigWidth=4;
bio(47).sigAddress='&Robot_leg_3_B.INPUT_19_1_2[0]';
bio(47).ndims=2;
bio(47).size=[];
bio(47).isStruct=false;

bio(48).blkName='Solver Configuration/EVAL_KEY/INPUT_19_1_3';
bio(48).sigName='';
bio(48).portIdx=0;
bio(48).dim=[4,1];
bio(48).sigWidth=4;
bio(48).sigAddress='&Robot_leg_3_B.INPUT_19_1_3[0]';
bio(48).ndims=2;
bio(48).size=[];
bio(48).isStruct=false;

bio(49).blkName='Solver Configuration/EVAL_KEY/INPUT_1_1_1';
bio(49).sigName='';
bio(49).portIdx=0;
bio(49).dim=[4,1];
bio(49).sigWidth=4;
bio(49).sigAddress='&Robot_leg_3_B.INPUT_1_1_1[0]';
bio(49).ndims=2;
bio(49).size=[];
bio(49).isStruct=false;

bio(50).blkName='Solver Configuration/EVAL_KEY/INPUT_20_1_1';
bio(50).sigName='';
bio(50).portIdx=0;
bio(50).dim=[4,1];
bio(50).sigWidth=4;
bio(50).sigAddress='&Robot_leg_3_B.INPUT_20_1_1[0]';
bio(50).ndims=2;
bio(50).size=[];
bio(50).isStruct=false;

bio(51).blkName='Solver Configuration/EVAL_KEY/INPUT_20_1_2';
bio(51).sigName='';
bio(51).portIdx=0;
bio(51).dim=[4,1];
bio(51).sigWidth=4;
bio(51).sigAddress='&Robot_leg_3_B.INPUT_20_1_2[0]';
bio(51).ndims=2;
bio(51).size=[];
bio(51).isStruct=false;

bio(52).blkName='Solver Configuration/EVAL_KEY/INPUT_20_1_3';
bio(52).sigName='';
bio(52).portIdx=0;
bio(52).dim=[4,1];
bio(52).sigWidth=4;
bio(52).sigAddress='&Robot_leg_3_B.INPUT_20_1_3[0]';
bio(52).ndims=2;
bio(52).size=[];
bio(52).isStruct=false;

bio(53).blkName='Solver Configuration/EVAL_KEY/INPUT_21_1_1';
bio(53).sigName='';
bio(53).portIdx=0;
bio(53).dim=[4,1];
bio(53).sigWidth=4;
bio(53).sigAddress='&Robot_leg_3_B.INPUT_21_1_1[0]';
bio(53).ndims=2;
bio(53).size=[];
bio(53).isStruct=false;

bio(54).blkName='Solver Configuration/EVAL_KEY/INPUT_21_1_2';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[4,1];
bio(54).sigWidth=4;
bio(54).sigAddress='&Robot_leg_3_B.INPUT_21_1_2[0]';
bio(54).ndims=2;
bio(54).size=[];
bio(54).isStruct=false;

bio(55).blkName='Solver Configuration/EVAL_KEY/INPUT_21_1_3';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[4,1];
bio(55).sigWidth=4;
bio(55).sigAddress='&Robot_leg_3_B.INPUT_21_1_3[0]';
bio(55).ndims=2;
bio(55).size=[];
bio(55).isStruct=false;

bio(56).blkName='Solver Configuration/EVAL_KEY/INPUT_22_1_1';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[4,1];
bio(56).sigWidth=4;
bio(56).sigAddress='&Robot_leg_3_B.INPUT_22_1_1[0]';
bio(56).ndims=2;
bio(56).size=[];
bio(56).isStruct=false;

bio(57).blkName='Solver Configuration/EVAL_KEY/INPUT_22_1_2';
bio(57).sigName='';
bio(57).portIdx=0;
bio(57).dim=[4,1];
bio(57).sigWidth=4;
bio(57).sigAddress='&Robot_leg_3_B.INPUT_22_1_2[0]';
bio(57).ndims=2;
bio(57).size=[];
bio(57).isStruct=false;

bio(58).blkName='Solver Configuration/EVAL_KEY/INPUT_22_1_3';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[4,1];
bio(58).sigWidth=4;
bio(58).sigAddress='&Robot_leg_3_B.INPUT_22_1_3[0]';
bio(58).ndims=2;
bio(58).size=[];
bio(58).isStruct=false;

bio(59).blkName='Solver Configuration/EVAL_KEY/INPUT_23_1_1';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[4,1];
bio(59).sigWidth=4;
bio(59).sigAddress='&Robot_leg_3_B.INPUT_23_1_1[0]';
bio(59).ndims=2;
bio(59).size=[];
bio(59).isStruct=false;

bio(60).blkName='Solver Configuration/EVAL_KEY/INPUT_24_1_1';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[4,1];
bio(60).sigWidth=4;
bio(60).sigAddress='&Robot_leg_3_B.INPUT_24_1_1[0]';
bio(60).ndims=2;
bio(60).size=[];
bio(60).isStruct=false;

bio(61).blkName='Solver Configuration/EVAL_KEY/INPUT_25_1_1';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[4,1];
bio(61).sigWidth=4;
bio(61).sigAddress='&Robot_leg_3_B.INPUT_25_1_1[0]';
bio(61).ndims=2;
bio(61).size=[];
bio(61).isStruct=false;

bio(62).blkName='Solver Configuration/EVAL_KEY/INPUT_26_1_1';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[4,1];
bio(62).sigWidth=4;
bio(62).sigAddress='&Robot_leg_3_B.INPUT_26_1_1[0]';
bio(62).ndims=2;
bio(62).size=[];
bio(62).isStruct=false;

bio(63).blkName='Solver Configuration/EVAL_KEY/INPUT_27_1_1';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[4,1];
bio(63).sigWidth=4;
bio(63).sigAddress='&Robot_leg_3_B.INPUT_27_1_1[0]';
bio(63).ndims=2;
bio(63).size=[];
bio(63).isStruct=false;

bio(64).blkName='Solver Configuration/EVAL_KEY/INPUT_28_1_1';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[4,1];
bio(64).sigWidth=4;
bio(64).sigAddress='&Robot_leg_3_B.INPUT_28_1_1[0]';
bio(64).ndims=2;
bio(64).size=[];
bio(64).isStruct=false;

bio(65).blkName='Solver Configuration/EVAL_KEY/INPUT_29_1_1';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[4,1];
bio(65).sigWidth=4;
bio(65).sigAddress='&Robot_leg_3_B.INPUT_29_1_1[0]';
bio(65).ndims=2;
bio(65).size=[];
bio(65).isStruct=false;

bio(66).blkName='Solver Configuration/EVAL_KEY/INPUT_29_1_2';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[4,1];
bio(66).sigWidth=4;
bio(66).sigAddress='&Robot_leg_3_B.INPUT_29_1_2[0]';
bio(66).ndims=2;
bio(66).size=[];
bio(66).isStruct=false;

bio(67).blkName='Solver Configuration/EVAL_KEY/INPUT_29_1_3';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[4,1];
bio(67).sigWidth=4;
bio(67).sigAddress='&Robot_leg_3_B.INPUT_29_1_3[0]';
bio(67).ndims=2;
bio(67).size=[];
bio(67).isStruct=false;

bio(68).blkName='Solver Configuration/EVAL_KEY/INPUT_2_1_1';
bio(68).sigName='';
bio(68).portIdx=0;
bio(68).dim=[4,1];
bio(68).sigWidth=4;
bio(68).sigAddress='&Robot_leg_3_B.INPUT_2_1_1[0]';
bio(68).ndims=2;
bio(68).size=[];
bio(68).isStruct=false;

bio(69).blkName='Solver Configuration/EVAL_KEY/INPUT_30_1_1';
bio(69).sigName='';
bio(69).portIdx=0;
bio(69).dim=[4,1];
bio(69).sigWidth=4;
bio(69).sigAddress='&Robot_leg_3_B.INPUT_30_1_1[0]';
bio(69).ndims=2;
bio(69).size=[];
bio(69).isStruct=false;

bio(70).blkName='Solver Configuration/EVAL_KEY/INPUT_30_1_2';
bio(70).sigName='';
bio(70).portIdx=0;
bio(70).dim=[4,1];
bio(70).sigWidth=4;
bio(70).sigAddress='&Robot_leg_3_B.INPUT_30_1_2[0]';
bio(70).ndims=2;
bio(70).size=[];
bio(70).isStruct=false;

bio(71).blkName='Solver Configuration/EVAL_KEY/INPUT_30_1_3';
bio(71).sigName='';
bio(71).portIdx=0;
bio(71).dim=[4,1];
bio(71).sigWidth=4;
bio(71).sigAddress='&Robot_leg_3_B.INPUT_30_1_3[0]';
bio(71).ndims=2;
bio(71).size=[];
bio(71).isStruct=false;

bio(72).blkName='Solver Configuration/EVAL_KEY/INPUT_31_1_1';
bio(72).sigName='';
bio(72).portIdx=0;
bio(72).dim=[4,1];
bio(72).sigWidth=4;
bio(72).sigAddress='&Robot_leg_3_B.INPUT_31_1_1[0]';
bio(72).ndims=2;
bio(72).size=[];
bio(72).isStruct=false;

bio(73).blkName='Solver Configuration/EVAL_KEY/INPUT_31_1_2';
bio(73).sigName='';
bio(73).portIdx=0;
bio(73).dim=[4,1];
bio(73).sigWidth=4;
bio(73).sigAddress='&Robot_leg_3_B.INPUT_31_1_2[0]';
bio(73).ndims=2;
bio(73).size=[];
bio(73).isStruct=false;

bio(74).blkName='Solver Configuration/EVAL_KEY/INPUT_31_1_3';
bio(74).sigName='';
bio(74).portIdx=0;
bio(74).dim=[4,1];
bio(74).sigWidth=4;
bio(74).sigAddress='&Robot_leg_3_B.INPUT_31_1_3[0]';
bio(74).ndims=2;
bio(74).size=[];
bio(74).isStruct=false;

bio(75).blkName='Solver Configuration/EVAL_KEY/INPUT_32_1_1';
bio(75).sigName='';
bio(75).portIdx=0;
bio(75).dim=[4,1];
bio(75).sigWidth=4;
bio(75).sigAddress='&Robot_leg_3_B.INPUT_32_1_1[0]';
bio(75).ndims=2;
bio(75).size=[];
bio(75).isStruct=false;

bio(76).blkName='Solver Configuration/EVAL_KEY/INPUT_32_1_2';
bio(76).sigName='';
bio(76).portIdx=0;
bio(76).dim=[4,1];
bio(76).sigWidth=4;
bio(76).sigAddress='&Robot_leg_3_B.INPUT_32_1_2[0]';
bio(76).ndims=2;
bio(76).size=[];
bio(76).isStruct=false;

bio(77).blkName='Solver Configuration/EVAL_KEY/INPUT_32_1_3';
bio(77).sigName='';
bio(77).portIdx=0;
bio(77).dim=[4,1];
bio(77).sigWidth=4;
bio(77).sigAddress='&Robot_leg_3_B.INPUT_32_1_3[0]';
bio(77).ndims=2;
bio(77).size=[];
bio(77).isStruct=false;

bio(78).blkName='Solver Configuration/EVAL_KEY/INPUT_33_1_1';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[4,1];
bio(78).sigWidth=4;
bio(78).sigAddress='&Robot_leg_3_B.INPUT_33_1_1[0]';
bio(78).ndims=2;
bio(78).size=[];
bio(78).isStruct=false;

bio(79).blkName='Solver Configuration/EVAL_KEY/INPUT_33_1_2';
bio(79).sigName='';
bio(79).portIdx=0;
bio(79).dim=[4,1];
bio(79).sigWidth=4;
bio(79).sigAddress='&Robot_leg_3_B.INPUT_33_1_2[0]';
bio(79).ndims=2;
bio(79).size=[];
bio(79).isStruct=false;

bio(80).blkName='Solver Configuration/EVAL_KEY/INPUT_33_1_3';
bio(80).sigName='';
bio(80).portIdx=0;
bio(80).dim=[4,1];
bio(80).sigWidth=4;
bio(80).sigAddress='&Robot_leg_3_B.INPUT_33_1_3[0]';
bio(80).ndims=2;
bio(80).size=[];
bio(80).isStruct=false;

bio(81).blkName='Solver Configuration/EVAL_KEY/INPUT_34_1_1';
bio(81).sigName='';
bio(81).portIdx=0;
bio(81).dim=[4,1];
bio(81).sigWidth=4;
bio(81).sigAddress='&Robot_leg_3_B.INPUT_34_1_1[0]';
bio(81).ndims=2;
bio(81).size=[];
bio(81).isStruct=false;

bio(82).blkName='Solver Configuration/EVAL_KEY/INPUT_34_1_2';
bio(82).sigName='';
bio(82).portIdx=0;
bio(82).dim=[4,1];
bio(82).sigWidth=4;
bio(82).sigAddress='&Robot_leg_3_B.INPUT_34_1_2[0]';
bio(82).ndims=2;
bio(82).size=[];
bio(82).isStruct=false;

bio(83).blkName='Solver Configuration/EVAL_KEY/INPUT_34_1_3';
bio(83).sigName='';
bio(83).portIdx=0;
bio(83).dim=[4,1];
bio(83).sigWidth=4;
bio(83).sigAddress='&Robot_leg_3_B.INPUT_34_1_3[0]';
bio(83).ndims=2;
bio(83).size=[];
bio(83).isStruct=false;

bio(84).blkName='Solver Configuration/EVAL_KEY/INPUT_35_1_1';
bio(84).sigName='';
bio(84).portIdx=0;
bio(84).dim=[4,1];
bio(84).sigWidth=4;
bio(84).sigAddress='&Robot_leg_3_B.INPUT_35_1_1[0]';
bio(84).ndims=2;
bio(84).size=[];
bio(84).isStruct=false;

bio(85).blkName='Solver Configuration/EVAL_KEY/INPUT_35_1_2';
bio(85).sigName='';
bio(85).portIdx=0;
bio(85).dim=[4,1];
bio(85).sigWidth=4;
bio(85).sigAddress='&Robot_leg_3_B.INPUT_35_1_2[0]';
bio(85).ndims=2;
bio(85).size=[];
bio(85).isStruct=false;

bio(86).blkName='Solver Configuration/EVAL_KEY/INPUT_35_1_3';
bio(86).sigName='';
bio(86).portIdx=0;
bio(86).dim=[4,1];
bio(86).sigWidth=4;
bio(86).sigAddress='&Robot_leg_3_B.INPUT_35_1_3[0]';
bio(86).ndims=2;
bio(86).size=[];
bio(86).isStruct=false;

bio(87).blkName='Solver Configuration/EVAL_KEY/INPUT_36_1_1';
bio(87).sigName='';
bio(87).portIdx=0;
bio(87).dim=[4,1];
bio(87).sigWidth=4;
bio(87).sigAddress='&Robot_leg_3_B.INPUT_36_1_1[0]';
bio(87).ndims=2;
bio(87).size=[];
bio(87).isStruct=false;

bio(88).blkName='Solver Configuration/EVAL_KEY/INPUT_36_1_2';
bio(88).sigName='';
bio(88).portIdx=0;
bio(88).dim=[4,1];
bio(88).sigWidth=4;
bio(88).sigAddress='&Robot_leg_3_B.INPUT_36_1_2[0]';
bio(88).ndims=2;
bio(88).size=[];
bio(88).isStruct=false;

bio(89).blkName='Solver Configuration/EVAL_KEY/INPUT_36_1_3';
bio(89).sigName='';
bio(89).portIdx=0;
bio(89).dim=[4,1];
bio(89).sigWidth=4;
bio(89).sigAddress='&Robot_leg_3_B.INPUT_36_1_3[0]';
bio(89).ndims=2;
bio(89).size=[];
bio(89).isStruct=false;

bio(90).blkName='Solver Configuration/EVAL_KEY/INPUT_37_1_1';
bio(90).sigName='';
bio(90).portIdx=0;
bio(90).dim=[4,1];
bio(90).sigWidth=4;
bio(90).sigAddress='&Robot_leg_3_B.INPUT_37_1_1[0]';
bio(90).ndims=2;
bio(90).size=[];
bio(90).isStruct=false;

bio(91).blkName='Solver Configuration/EVAL_KEY/INPUT_37_1_2';
bio(91).sigName='';
bio(91).portIdx=0;
bio(91).dim=[4,1];
bio(91).sigWidth=4;
bio(91).sigAddress='&Robot_leg_3_B.INPUT_37_1_2[0]';
bio(91).ndims=2;
bio(91).size=[];
bio(91).isStruct=false;

bio(92).blkName='Solver Configuration/EVAL_KEY/INPUT_37_1_3';
bio(92).sigName='';
bio(92).portIdx=0;
bio(92).dim=[4,1];
bio(92).sigWidth=4;
bio(92).sigAddress='&Robot_leg_3_B.INPUT_37_1_3[0]';
bio(92).ndims=2;
bio(92).size=[];
bio(92).isStruct=false;

bio(93).blkName='Solver Configuration/EVAL_KEY/INPUT_38_1_1';
bio(93).sigName='';
bio(93).portIdx=0;
bio(93).dim=[4,1];
bio(93).sigWidth=4;
bio(93).sigAddress='&Robot_leg_3_B.INPUT_38_1_1[0]';
bio(93).ndims=2;
bio(93).size=[];
bio(93).isStruct=false;

bio(94).blkName='Solver Configuration/EVAL_KEY/INPUT_38_1_2';
bio(94).sigName='';
bio(94).portIdx=0;
bio(94).dim=[4,1];
bio(94).sigWidth=4;
bio(94).sigAddress='&Robot_leg_3_B.INPUT_38_1_2[0]';
bio(94).ndims=2;
bio(94).size=[];
bio(94).isStruct=false;

bio(95).blkName='Solver Configuration/EVAL_KEY/INPUT_38_1_3';
bio(95).sigName='';
bio(95).portIdx=0;
bio(95).dim=[4,1];
bio(95).sigWidth=4;
bio(95).sigAddress='&Robot_leg_3_B.INPUT_38_1_3[0]';
bio(95).ndims=2;
bio(95).size=[];
bio(95).isStruct=false;

bio(96).blkName='Solver Configuration/EVAL_KEY/INPUT_39_1_1';
bio(96).sigName='';
bio(96).portIdx=0;
bio(96).dim=[4,1];
bio(96).sigWidth=4;
bio(96).sigAddress='&Robot_leg_3_B.INPUT_39_1_1[0]';
bio(96).ndims=2;
bio(96).size=[];
bio(96).isStruct=false;

bio(97).blkName='Solver Configuration/EVAL_KEY/INPUT_39_1_2';
bio(97).sigName='';
bio(97).portIdx=0;
bio(97).dim=[4,1];
bio(97).sigWidth=4;
bio(97).sigAddress='&Robot_leg_3_B.INPUT_39_1_2[0]';
bio(97).ndims=2;
bio(97).size=[];
bio(97).isStruct=false;

bio(98).blkName='Solver Configuration/EVAL_KEY/INPUT_39_1_3';
bio(98).sigName='';
bio(98).portIdx=0;
bio(98).dim=[4,1];
bio(98).sigWidth=4;
bio(98).sigAddress='&Robot_leg_3_B.INPUT_39_1_3[0]';
bio(98).ndims=2;
bio(98).size=[];
bio(98).isStruct=false;

bio(99).blkName='Solver Configuration/EVAL_KEY/INPUT_3_1_1';
bio(99).sigName='';
bio(99).portIdx=0;
bio(99).dim=[4,1];
bio(99).sigWidth=4;
bio(99).sigAddress='&Robot_leg_3_B.INPUT_3_1_1[0]';
bio(99).ndims=2;
bio(99).size=[];
bio(99).isStruct=false;

bio(100).blkName='Solver Configuration/EVAL_KEY/INPUT_40_1_1';
bio(100).sigName='';
bio(100).portIdx=0;
bio(100).dim=[4,1];
bio(100).sigWidth=4;
bio(100).sigAddress='&Robot_leg_3_B.INPUT_40_1_1[0]';
bio(100).ndims=2;
bio(100).size=[];
bio(100).isStruct=false;

bio(101).blkName='Solver Configuration/EVAL_KEY/INPUT_40_1_2';
bio(101).sigName='';
bio(101).portIdx=0;
bio(101).dim=[4,1];
bio(101).sigWidth=4;
bio(101).sigAddress='&Robot_leg_3_B.INPUT_40_1_2[0]';
bio(101).ndims=2;
bio(101).size=[];
bio(101).isStruct=false;

bio(102).blkName='Solver Configuration/EVAL_KEY/INPUT_40_1_3';
bio(102).sigName='';
bio(102).portIdx=0;
bio(102).dim=[4,1];
bio(102).sigWidth=4;
bio(102).sigAddress='&Robot_leg_3_B.INPUT_40_1_3[0]';
bio(102).ndims=2;
bio(102).size=[];
bio(102).isStruct=false;

bio(103).blkName='Solver Configuration/EVAL_KEY/INPUT_41_1_1';
bio(103).sigName='';
bio(103).portIdx=0;
bio(103).dim=[4,1];
bio(103).sigWidth=4;
bio(103).sigAddress='&Robot_leg_3_B.INPUT_41_1_1[0]';
bio(103).ndims=2;
bio(103).size=[];
bio(103).isStruct=false;

bio(104).blkName='Solver Configuration/EVAL_KEY/INPUT_41_1_2';
bio(104).sigName='';
bio(104).portIdx=0;
bio(104).dim=[4,1];
bio(104).sigWidth=4;
bio(104).sigAddress='&Robot_leg_3_B.INPUT_41_1_2[0]';
bio(104).ndims=2;
bio(104).size=[];
bio(104).isStruct=false;

bio(105).blkName='Solver Configuration/EVAL_KEY/INPUT_41_1_3';
bio(105).sigName='';
bio(105).portIdx=0;
bio(105).dim=[4,1];
bio(105).sigWidth=4;
bio(105).sigAddress='&Robot_leg_3_B.INPUT_41_1_3[0]';
bio(105).ndims=2;
bio(105).size=[];
bio(105).isStruct=false;

bio(106).blkName='Solver Configuration/EVAL_KEY/INPUT_42_1_1';
bio(106).sigName='';
bio(106).portIdx=0;
bio(106).dim=[4,1];
bio(106).sigWidth=4;
bio(106).sigAddress='&Robot_leg_3_B.INPUT_42_1_1[0]';
bio(106).ndims=2;
bio(106).size=[];
bio(106).isStruct=false;

bio(107).blkName='Solver Configuration/EVAL_KEY/INPUT_42_1_2';
bio(107).sigName='';
bio(107).portIdx=0;
bio(107).dim=[4,1];
bio(107).sigWidth=4;
bio(107).sigAddress='&Robot_leg_3_B.INPUT_42_1_2[0]';
bio(107).ndims=2;
bio(107).size=[];
bio(107).isStruct=false;

bio(108).blkName='Solver Configuration/EVAL_KEY/INPUT_42_1_3';
bio(108).sigName='';
bio(108).portIdx=0;
bio(108).dim=[4,1];
bio(108).sigWidth=4;
bio(108).sigAddress='&Robot_leg_3_B.INPUT_42_1_3[0]';
bio(108).ndims=2;
bio(108).size=[];
bio(108).isStruct=false;

bio(109).blkName='Solver Configuration/EVAL_KEY/INPUT_43_1_1';
bio(109).sigName='';
bio(109).portIdx=0;
bio(109).dim=[4,1];
bio(109).sigWidth=4;
bio(109).sigAddress='&Robot_leg_3_B.INPUT_43_1_1[0]';
bio(109).ndims=2;
bio(109).size=[];
bio(109).isStruct=false;

bio(110).blkName='Solver Configuration/EVAL_KEY/INPUT_43_1_2';
bio(110).sigName='';
bio(110).portIdx=0;
bio(110).dim=[4,1];
bio(110).sigWidth=4;
bio(110).sigAddress='&Robot_leg_3_B.INPUT_43_1_2[0]';
bio(110).ndims=2;
bio(110).size=[];
bio(110).isStruct=false;

bio(111).blkName='Solver Configuration/EVAL_KEY/INPUT_43_1_3';
bio(111).sigName='';
bio(111).portIdx=0;
bio(111).dim=[4,1];
bio(111).sigWidth=4;
bio(111).sigAddress='&Robot_leg_3_B.INPUT_43_1_3[0]';
bio(111).ndims=2;
bio(111).size=[];
bio(111).isStruct=false;

bio(112).blkName='Solver Configuration/EVAL_KEY/INPUT_44_1_1';
bio(112).sigName='';
bio(112).portIdx=0;
bio(112).dim=[4,1];
bio(112).sigWidth=4;
bio(112).sigAddress='&Robot_leg_3_B.INPUT_44_1_1[0]';
bio(112).ndims=2;
bio(112).size=[];
bio(112).isStruct=false;

bio(113).blkName='Solver Configuration/EVAL_KEY/INPUT_44_1_2';
bio(113).sigName='';
bio(113).portIdx=0;
bio(113).dim=[4,1];
bio(113).sigWidth=4;
bio(113).sigAddress='&Robot_leg_3_B.INPUT_44_1_2[0]';
bio(113).ndims=2;
bio(113).size=[];
bio(113).isStruct=false;

bio(114).blkName='Solver Configuration/EVAL_KEY/INPUT_44_1_3';
bio(114).sigName='';
bio(114).portIdx=0;
bio(114).dim=[4,1];
bio(114).sigWidth=4;
bio(114).sigAddress='&Robot_leg_3_B.INPUT_44_1_3[0]';
bio(114).ndims=2;
bio(114).size=[];
bio(114).isStruct=false;

bio(115).blkName='Solver Configuration/EVAL_KEY/INPUT_4_1_1';
bio(115).sigName='';
bio(115).portIdx=0;
bio(115).dim=[4,1];
bio(115).sigWidth=4;
bio(115).sigAddress='&Robot_leg_3_B.INPUT_4_1_1[0]';
bio(115).ndims=2;
bio(115).size=[];
bio(115).isStruct=false;

bio(116).blkName='Solver Configuration/EVAL_KEY/INPUT_5_1_1';
bio(116).sigName='';
bio(116).portIdx=0;
bio(116).dim=[4,1];
bio(116).sigWidth=4;
bio(116).sigAddress='&Robot_leg_3_B.INPUT_5_1_1[0]';
bio(116).ndims=2;
bio(116).size=[];
bio(116).isStruct=false;

bio(117).blkName='Solver Configuration/EVAL_KEY/INPUT_6_1_1';
bio(117).sigName='';
bio(117).portIdx=0;
bio(117).dim=[4,1];
bio(117).sigWidth=4;
bio(117).sigAddress='&Robot_leg_3_B.INPUT_6_1_1[0]';
bio(117).ndims=2;
bio(117).size=[];
bio(117).isStruct=false;

bio(118).blkName='Solver Configuration/EVAL_KEY/INPUT_7_1_1';
bio(118).sigName='';
bio(118).portIdx=0;
bio(118).dim=[4,1];
bio(118).sigWidth=4;
bio(118).sigAddress='&Robot_leg_3_B.INPUT_7_1_1[0]';
bio(118).ndims=2;
bio(118).size=[];
bio(118).isStruct=false;

bio(119).blkName='Solver Configuration/EVAL_KEY/INPUT_7_1_2';
bio(119).sigName='';
bio(119).portIdx=0;
bio(119).dim=[4,1];
bio(119).sigWidth=4;
bio(119).sigAddress='&Robot_leg_3_B.INPUT_7_1_2[0]';
bio(119).ndims=2;
bio(119).size=[];
bio(119).isStruct=false;

bio(120).blkName='Solver Configuration/EVAL_KEY/INPUT_7_1_3';
bio(120).sigName='';
bio(120).portIdx=0;
bio(120).dim=[4,1];
bio(120).sigWidth=4;
bio(120).sigAddress='&Robot_leg_3_B.INPUT_7_1_3[0]';
bio(120).ndims=2;
bio(120).size=[];
bio(120).isStruct=false;

bio(121).blkName='Solver Configuration/EVAL_KEY/INPUT_8_1_1';
bio(121).sigName='';
bio(121).portIdx=0;
bio(121).dim=[4,1];
bio(121).sigWidth=4;
bio(121).sigAddress='&Robot_leg_3_B.INPUT_8_1_1[0]';
bio(121).ndims=2;
bio(121).size=[];
bio(121).isStruct=false;

bio(122).blkName='Solver Configuration/EVAL_KEY/INPUT_8_1_2';
bio(122).sigName='';
bio(122).portIdx=0;
bio(122).dim=[4,1];
bio(122).sigWidth=4;
bio(122).sigAddress='&Robot_leg_3_B.INPUT_8_1_2[0]';
bio(122).ndims=2;
bio(122).size=[];
bio(122).isStruct=false;

bio(123).blkName='Solver Configuration/EVAL_KEY/INPUT_8_1_3';
bio(123).sigName='';
bio(123).portIdx=0;
bio(123).dim=[4,1];
bio(123).sigWidth=4;
bio(123).sigAddress='&Robot_leg_3_B.INPUT_8_1_3[0]';
bio(123).ndims=2;
bio(123).size=[];
bio(123).isStruct=false;

bio(124).blkName='Solver Configuration/EVAL_KEY/INPUT_9_1_1';
bio(124).sigName='';
bio(124).portIdx=0;
bio(124).dim=[4,1];
bio(124).sigWidth=4;
bio(124).sigAddress='&Robot_leg_3_B.INPUT_9_1_1[0]';
bio(124).ndims=2;
bio(124).size=[];
bio(124).isStruct=false;

bio(125).blkName='Solver Configuration/EVAL_KEY/INPUT_9_1_2';
bio(125).sigName='';
bio(125).portIdx=0;
bio(125).dim=[4,1];
bio(125).sigWidth=4;
bio(125).sigAddress='&Robot_leg_3_B.INPUT_9_1_2[0]';
bio(125).ndims=2;
bio(125).size=[];
bio(125).isStruct=false;

bio(126).blkName='Solver Configuration/EVAL_KEY/INPUT_9_1_3';
bio(126).sigName='';
bio(126).portIdx=0;
bio(126).dim=[4,1];
bio(126).sigWidth=4;
bio(126).sigAddress='&Robot_leg_3_B.INPUT_9_1_3[0]';
bio(126).ndims=2;
bio(126).size=[];
bio(126).isStruct=false;

bio(127).blkName='Solver Configuration/EVAL_KEY/OUTPUT_1_0';
bio(127).sigName='';
bio(127).portIdx=0;
bio(127).dim=[163,1];
bio(127).sigWidth=163;
bio(127).sigAddress='&Robot_leg_3_B.OUTPUT_1_0[0]';
bio(127).ndims=2;
bio(127).size=[];
bio(127).isStruct=false;

bio(128).blkName='Solver Configuration/EVAL_KEY/OUTPUT_1_1';
bio(128).sigName='';
bio(128).portIdx=0;
bio(128).dim=[12,1];
bio(128).sigWidth=12;
bio(128).sigAddress='&Robot_leg_3_B.OUTPUT_1_1[0]';
bio(128).ndims=2;
bio(128).size=[];
bio(128).isStruct=false;

bio(129).blkName='Solver Configuration/EVAL_KEY/STATE_1';
bio(129).sigName='';
bio(129).portIdx=0;
bio(129).dim=[13,1];
bio(129).sigWidth=13;
bio(129).sigAddress='&Robot_leg_3_B.STATE_1[0]';
bio(129).ndims=2;
bio(129).size=[];
bio(129).isStruct=false;

bio(130).blkName='Robot/Left First Step/Left_Abduction_Motion/Clock';
bio(130).sigName='';
bio(130).portIdx=0;
bio(130).dim=[1,1];
bio(130).sigWidth=1;
bio(130).sigAddress='&Robot_leg_3_B.Clock_o3';
bio(130).ndims=2;
bio(130).size=[];
bio(130).isStruct=false;

bio(131).blkName='Robot/Left First Step/Left_Abduction_Motion/Output';
bio(131).sigName='';
bio(131).portIdx=0;
bio(131).dim=[1,1];
bio(131).sigWidth=1;
bio(131).sigAddress='&Robot_leg_3_B.Output_k';
bio(131).ndims=2;
bio(131).size=[];
bio(131).isStruct=false;

bio(132).blkName='Robot/Left First Step/Left_Abduction_Motion/Look-Up Table1';
bio(132).sigName='';
bio(132).portIdx=0;
bio(132).dim=[1,1];
bio(132).sigWidth=1;
bio(132).sigAddress='&Robot_leg_3_B.LookUpTable1_j';
bio(132).ndims=2;
bio(132).size=[];
bio(132).isStruct=false;

bio(133).blkName='Robot/Left First Step/Left_Abduction_Motion/Math Function';
bio(133).sigName='';
bio(133).portIdx=0;
bio(133).dim=[1,1];
bio(133).sigWidth=1;
bio(133).sigAddress='&Robot_leg_3_B.MathFunction_ma';
bio(133).ndims=2;
bio(133).size=[];
bio(133).isStruct=false;

bio(134).blkName='Robot/Left First Step/Left_Abduction_Motion/Sum';
bio(134).sigName='';
bio(134).portIdx=0;
bio(134).dim=[1,1];
bio(134).sigWidth=1;
bio(134).sigAddress='&Robot_leg_3_B.Sum_oc';
bio(134).ndims=2;
bio(134).size=[];
bio(134).isStruct=false;

bio(135).blkName='Robot/Left First Step/Left_Ankle Motion/Clock';
bio(135).sigName='';
bio(135).portIdx=0;
bio(135).dim=[1,1];
bio(135).sigWidth=1;
bio(135).sigAddress='&Robot_leg_3_B.Clock_i';
bio(135).ndims=2;
bio(135).size=[];
bio(135).isStruct=false;

bio(136).blkName='Robot/Left First Step/Left_Ankle Motion/Output';
bio(136).sigName='';
bio(136).portIdx=0;
bio(136).dim=[1,1];
bio(136).sigWidth=1;
bio(136).sigAddress='&Robot_leg_3_B.Output_g0';
bio(136).ndims=2;
bio(136).size=[];
bio(136).isStruct=false;

bio(137).blkName='Robot/Left First Step/Left_Ankle Motion/Look-Up Table1';
bio(137).sigName='';
bio(137).portIdx=0;
bio(137).dim=[1,1];
bio(137).sigWidth=1;
bio(137).sigAddress='&Robot_leg_3_B.LookUpTable1_a';
bio(137).ndims=2;
bio(137).size=[];
bio(137).isStruct=false;

bio(138).blkName='Robot/Left First Step/Left_Ankle Motion/Math Function';
bio(138).sigName='';
bio(138).portIdx=0;
bio(138).dim=[1,1];
bio(138).sigWidth=1;
bio(138).sigAddress='&Robot_leg_3_B.MathFunction_n';
bio(138).ndims=2;
bio(138).size=[];
bio(138).isStruct=false;

bio(139).blkName='Robot/Left First Step/Left_Ankle Motion/Sum';
bio(139).sigName='';
bio(139).portIdx=0;
bio(139).dim=[1,1];
bio(139).sigWidth=1;
bio(139).sigAddress='&Robot_leg_3_B.Sum_i';
bio(139).ndims=2;
bio(139).size=[];
bio(139).isStruct=false;

bio(140).blkName='Robot/Left First Step/Left_Ankle_Twist_Motion/Clock';
bio(140).sigName='';
bio(140).portIdx=0;
bio(140).dim=[1,1];
bio(140).sigWidth=1;
bio(140).sigAddress='&Robot_leg_3_B.Clock_m';
bio(140).ndims=2;
bio(140).size=[];
bio(140).isStruct=false;

bio(141).blkName='Robot/Left First Step/Left_Ankle_Twist_Motion/Output';
bio(141).sigName='';
bio(141).portIdx=0;
bio(141).dim=[1,1];
bio(141).sigWidth=1;
bio(141).sigAddress='&Robot_leg_3_B.Output_og';
bio(141).ndims=2;
bio(141).size=[];
bio(141).isStruct=false;

bio(142).blkName='Robot/Left First Step/Left_Ankle_Twist_Motion/Look-Up Table1';
bio(142).sigName='';
bio(142).portIdx=0;
bio(142).dim=[1,1];
bio(142).sigWidth=1;
bio(142).sigAddress='&Robot_leg_3_B.LookUpTable1_m';
bio(142).ndims=2;
bio(142).size=[];
bio(142).isStruct=false;

bio(143).blkName='Robot/Left First Step/Left_Ankle_Twist_Motion/Math Function';
bio(143).sigName='';
bio(143).portIdx=0;
bio(143).dim=[1,1];
bio(143).sigWidth=1;
bio(143).sigAddress='&Robot_leg_3_B.MathFunction_jo2';
bio(143).ndims=2;
bio(143).size=[];
bio(143).isStruct=false;

bio(144).blkName='Robot/Left First Step/Left_Ankle_Twist_Motion/Sum';
bio(144).sigName='';
bio(144).portIdx=0;
bio(144).dim=[1,1];
bio(144).sigWidth=1;
bio(144).sigAddress='&Robot_leg_3_B.Sum_ge';
bio(144).ndims=2;
bio(144).size=[];
bio(144).isStruct=false;

bio(145).blkName='Robot/Left First Step/Left_Hip_Motion/Clock';
bio(145).sigName='';
bio(145).portIdx=0;
bio(145).dim=[1,1];
bio(145).sigWidth=1;
bio(145).sigAddress='&Robot_leg_3_B.Clock_hj';
bio(145).ndims=2;
bio(145).size=[];
bio(145).isStruct=false;

bio(146).blkName='Robot/Left First Step/Left_Hip_Motion/Output';
bio(146).sigName='';
bio(146).portIdx=0;
bio(146).dim=[1,1];
bio(146).sigWidth=1;
bio(146).sigAddress='&Robot_leg_3_B.Output_ny';
bio(146).ndims=2;
bio(146).size=[];
bio(146).isStruct=false;

bio(147).blkName='Robot/Left First Step/Left_Hip_Motion/Look-Up Table1';
bio(147).sigName='';
bio(147).portIdx=0;
bio(147).dim=[1,1];
bio(147).sigWidth=1;
bio(147).sigAddress='&Robot_leg_3_B.LookUpTable1_g';
bio(147).ndims=2;
bio(147).size=[];
bio(147).isStruct=false;

bio(148).blkName='Robot/Left First Step/Left_Hip_Motion/Math Function';
bio(148).sigName='';
bio(148).portIdx=0;
bio(148).dim=[1,1];
bio(148).sigWidth=1;
bio(148).sigAddress='&Robot_leg_3_B.MathFunction_a';
bio(148).ndims=2;
bio(148).size=[];
bio(148).isStruct=false;

bio(149).blkName='Robot/Left First Step/Left_Hip_Motion/Sum';
bio(149).sigName='';
bio(149).portIdx=0;
bio(149).dim=[1,1];
bio(149).sigWidth=1;
bio(149).sigAddress='&Robot_leg_3_B.Sum_a';
bio(149).ndims=2;
bio(149).size=[];
bio(149).isStruct=false;

bio(150).blkName='Robot/Left First Step/Left_Knee_Motion/Clock';
bio(150).sigName='';
bio(150).portIdx=0;
bio(150).dim=[1,1];
bio(150).sigWidth=1;
bio(150).sigAddress='&Robot_leg_3_B.Clock_nd';
bio(150).ndims=2;
bio(150).size=[];
bio(150).isStruct=false;

bio(151).blkName='Robot/Left First Step/Left_Knee_Motion/Output';
bio(151).sigName='';
bio(151).portIdx=0;
bio(151).dim=[1,1];
bio(151).sigWidth=1;
bio(151).sigAddress='&Robot_leg_3_B.Output_gv';
bio(151).ndims=2;
bio(151).size=[];
bio(151).isStruct=false;

bio(152).blkName='Robot/Left First Step/Left_Knee_Motion/Look-Up Table1';
bio(152).sigName='';
bio(152).portIdx=0;
bio(152).dim=[1,1];
bio(152).sigWidth=1;
bio(152).sigAddress='&Robot_leg_3_B.LookUpTable1_n';
bio(152).ndims=2;
bio(152).size=[];
bio(152).isStruct=false;

bio(153).blkName='Robot/Left First Step/Left_Knee_Motion/Math Function';
bio(153).sigName='';
bio(153).portIdx=0;
bio(153).dim=[1,1];
bio(153).sigWidth=1;
bio(153).sigAddress='&Robot_leg_3_B.MathFunction_nm';
bio(153).ndims=2;
bio(153).size=[];
bio(153).isStruct=false;

bio(154).blkName='Robot/Left First Step/Left_Knee_Motion/Sum';
bio(154).sigName='';
bio(154).portIdx=0;
bio(154).dim=[1,1];
bio(154).sigWidth=1;
bio(154).sigAddress='&Robot_leg_3_B.Sum_if';
bio(154).ndims=2;
bio(154).size=[];
bio(154).isStruct=false;

bio(155).blkName='Robot/Left First Step/Left_Rotation_Motion/Clock';
bio(155).sigName='';
bio(155).portIdx=0;
bio(155).dim=[1,1];
bio(155).sigWidth=1;
bio(155).sigAddress='&Robot_leg_3_B.Clock_by';
bio(155).ndims=2;
bio(155).size=[];
bio(155).isStruct=false;

bio(156).blkName='Robot/Left First Step/Left_Rotation_Motion/Output';
bio(156).sigName='';
bio(156).portIdx=0;
bio(156).dim=[1,1];
bio(156).sigWidth=1;
bio(156).sigAddress='&Robot_leg_3_B.Output_o0';
bio(156).ndims=2;
bio(156).size=[];
bio(156).isStruct=false;

bio(157).blkName='Robot/Left First Step/Left_Rotation_Motion/Look-Up Table1';
bio(157).sigName='';
bio(157).portIdx=0;
bio(157).dim=[1,1];
bio(157).sigWidth=1;
bio(157).sigAddress='&Robot_leg_3_B.LookUpTable1_j5';
bio(157).ndims=2;
bio(157).size=[];
bio(157).isStruct=false;

bio(158).blkName='Robot/Left First Step/Left_Rotation_Motion/Math Function';
bio(158).sigName='';
bio(158).portIdx=0;
bio(158).dim=[1,1];
bio(158).sigWidth=1;
bio(158).sigAddress='&Robot_leg_3_B.MathFunction_i';
bio(158).ndims=2;
bio(158).size=[];
bio(158).isStruct=false;

bio(159).blkName='Robot/Left First Step/Left_Rotation_Motion/Sum';
bio(159).sigName='';
bio(159).portIdx=0;
bio(159).dim=[1,1];
bio(159).sigWidth=1;
bio(159).sigAddress='&Robot_leg_3_B.Sum_gn';
bio(159).ndims=2;
bio(159).size=[];
bio(159).isStruct=false;

bio(160).blkName='Robot/Left Gait Motion/Left_Abduction_Motion/Clock';
bio(160).sigName='';
bio(160).portIdx=0;
bio(160).dim=[1,1];
bio(160).sigWidth=1;
bio(160).sigAddress='&Robot_leg_3_B.Clock_h';
bio(160).ndims=2;
bio(160).size=[];
bio(160).isStruct=false;

bio(161).blkName='Robot/Left Gait Motion/Left_Abduction_Motion/Output';
bio(161).sigName='';
bio(161).portIdx=0;
bio(161).dim=[1,1];
bio(161).sigWidth=1;
bio(161).sigAddress='&Robot_leg_3_B.Output_e';
bio(161).ndims=2;
bio(161).size=[];
bio(161).isStruct=false;

bio(162).blkName='Robot/Left Gait Motion/Left_Abduction_Motion/Look-Up Table1';
bio(162).sigName='';
bio(162).portIdx=0;
bio(162).dim=[1,1];
bio(162).sigWidth=1;
bio(162).sigAddress='&Robot_leg_3_B.LookUpTable1_h';
bio(162).ndims=2;
bio(162).size=[];
bio(162).isStruct=false;

bio(163).blkName='Robot/Left Gait Motion/Left_Abduction_Motion/Math Function';
bio(163).sigName='';
bio(163).portIdx=0;
bio(163).dim=[1,1];
bio(163).sigWidth=1;
bio(163).sigAddress='&Robot_leg_3_B.MathFunction_h';
bio(163).ndims=2;
bio(163).size=[];
bio(163).isStruct=false;

bio(164).blkName='Robot/Left Gait Motion/Left_Abduction_Motion/Sum';
bio(164).sigName='';
bio(164).portIdx=0;
bio(164).dim=[1,1];
bio(164).sigWidth=1;
bio(164).sigAddress='&Robot_leg_3_B.Sum_gg';
bio(164).ndims=2;
bio(164).size=[];
bio(164).isStruct=false;

bio(165).blkName='Robot/Left Gait Motion/Left_Ankle Motion/Clock';
bio(165).sigName='';
bio(165).portIdx=0;
bio(165).dim=[1,1];
bio(165).sigWidth=1;
bio(165).sigAddress='&Robot_leg_3_B.Clock_n';
bio(165).ndims=2;
bio(165).size=[];
bio(165).isStruct=false;

bio(166).blkName='Robot/Left Gait Motion/Left_Ankle Motion/Output';
bio(166).sigName='';
bio(166).portIdx=0;
bio(166).dim=[1,1];
bio(166).sigWidth=1;
bio(166).sigAddress='&Robot_leg_3_B.Output_js';
bio(166).ndims=2;
bio(166).size=[];
bio(166).isStruct=false;

bio(167).blkName='Robot/Left Gait Motion/Left_Ankle Motion/Look-Up Table1';
bio(167).sigName='';
bio(167).portIdx=0;
bio(167).dim=[1,1];
bio(167).sigWidth=1;
bio(167).sigAddress='&Robot_leg_3_B.LookUpTable1_k';
bio(167).ndims=2;
bio(167).size=[];
bio(167).isStruct=false;

bio(168).blkName='Robot/Left Gait Motion/Left_Ankle Motion/Math Function';
bio(168).sigName='';
bio(168).portIdx=0;
bio(168).dim=[1,1];
bio(168).sigWidth=1;
bio(168).sigAddress='&Robot_leg_3_B.MathFunction_m';
bio(168).ndims=2;
bio(168).size=[];
bio(168).isStruct=false;

bio(169).blkName='Robot/Left Gait Motion/Left_Ankle Motion/Sum';
bio(169).sigName='';
bio(169).portIdx=0;
bio(169).dim=[1,1];
bio(169).sigWidth=1;
bio(169).sigAddress='&Robot_leg_3_B.Sum_m';
bio(169).ndims=2;
bio(169).size=[];
bio(169).isStruct=false;

bio(170).blkName='Robot/Left Gait Motion/Left_Ankle_Twist_Motion/Clock';
bio(170).sigName='';
bio(170).portIdx=0;
bio(170).dim=[1,1];
bio(170).sigWidth=1;
bio(170).sigAddress='&Robot_leg_3_B.Clock';
bio(170).ndims=2;
bio(170).size=[];
bio(170).isStruct=false;

bio(171).blkName='Robot/Left Gait Motion/Left_Ankle_Twist_Motion/Output';
bio(171).sigName='';
bio(171).portIdx=0;
bio(171).dim=[1,1];
bio(171).sigWidth=1;
bio(171).sigAddress='&Robot_leg_3_B.Output_dn';
bio(171).ndims=2;
bio(171).size=[];
bio(171).isStruct=false;

bio(172).blkName='Robot/Left Gait Motion/Left_Ankle_Twist_Motion/Look-Up Table1';
bio(172).sigName='';
bio(172).portIdx=0;
bio(172).dim=[1,1];
bio(172).sigWidth=1;
bio(172).sigAddress='&Robot_leg_3_B.LookUpTable1';
bio(172).ndims=2;
bio(172).size=[];
bio(172).isStruct=false;

bio(173).blkName='Robot/Left Gait Motion/Left_Ankle_Twist_Motion/Math Function';
bio(173).sigName='';
bio(173).portIdx=0;
bio(173).dim=[1,1];
bio(173).sigWidth=1;
bio(173).sigAddress='&Robot_leg_3_B.MathFunction';
bio(173).ndims=2;
bio(173).size=[];
bio(173).isStruct=false;

bio(174).blkName='Robot/Left Gait Motion/Left_Ankle_Twist_Motion/Sum';
bio(174).sigName='';
bio(174).portIdx=0;
bio(174).dim=[1,1];
bio(174).sigWidth=1;
bio(174).sigAddress='&Robot_leg_3_B.Sum';
bio(174).ndims=2;
bio(174).size=[];
bio(174).isStruct=false;

bio(175).blkName='Robot/Left Gait Motion/Left_Hip_Motion/Clock';
bio(175).sigName='';
bio(175).portIdx=0;
bio(175).dim=[1,1];
bio(175).sigWidth=1;
bio(175).sigAddress='&Robot_leg_3_B.Clock_o';
bio(175).ndims=2;
bio(175).size=[];
bio(175).isStruct=false;

bio(176).blkName='Robot/Left Gait Motion/Left_Hip_Motion/Output';
bio(176).sigName='';
bio(176).portIdx=0;
bio(176).dim=[1,1];
bio(176).sigWidth=1;
bio(176).sigAddress='&Robot_leg_3_B.Output_ju';
bio(176).ndims=2;
bio(176).size=[];
bio(176).isStruct=false;

bio(177).blkName='Robot/Left Gait Motion/Left_Hip_Motion/Look-Up Table1';
bio(177).sigName='';
bio(177).portIdx=0;
bio(177).dim=[1,1];
bio(177).sigWidth=1;
bio(177).sigAddress='&Robot_leg_3_B.LookUpTable1_d';
bio(177).ndims=2;
bio(177).size=[];
bio(177).isStruct=false;

bio(178).blkName='Robot/Left Gait Motion/Left_Hip_Motion/Math Function';
bio(178).sigName='';
bio(178).portIdx=0;
bio(178).dim=[1,1];
bio(178).sigWidth=1;
bio(178).sigAddress='&Robot_leg_3_B.MathFunction_jo';
bio(178).ndims=2;
bio(178).size=[];
bio(178).isStruct=false;

bio(179).blkName='Robot/Left Gait Motion/Left_Hip_Motion/Sum';
bio(179).sigName='';
bio(179).portIdx=0;
bio(179).dim=[1,1];
bio(179).sigWidth=1;
bio(179).sigAddress='&Robot_leg_3_B.Sum_l';
bio(179).ndims=2;
bio(179).size=[];
bio(179).isStruct=false;

bio(180).blkName='Robot/Left Gait Motion/Left_Knee_Motion/Clock';
bio(180).sigName='';
bio(180).portIdx=0;
bio(180).dim=[1,1];
bio(180).sigWidth=1;
bio(180).sigAddress='&Robot_leg_3_B.Clock_b';
bio(180).ndims=2;
bio(180).size=[];
bio(180).isStruct=false;

bio(181).blkName='Robot/Left Gait Motion/Left_Knee_Motion/Output';
bio(181).sigName='';
bio(181).portIdx=0;
bio(181).dim=[1,1];
bio(181).sigWidth=1;
bio(181).sigAddress='&Robot_leg_3_B.Output_o2';
bio(181).ndims=2;
bio(181).size=[];
bio(181).isStruct=false;

bio(182).blkName='Robot/Left Gait Motion/Left_Knee_Motion/Look-Up Table1';
bio(182).sigName='';
bio(182).portIdx=0;
bio(182).dim=[1,1];
bio(182).sigWidth=1;
bio(182).sigAddress='&Robot_leg_3_B.LookUpTable1_e';
bio(182).ndims=2;
bio(182).size=[];
bio(182).isStruct=false;

bio(183).blkName='Robot/Left Gait Motion/Left_Knee_Motion/Math Function';
bio(183).sigName='';
bio(183).portIdx=0;
bio(183).dim=[1,1];
bio(183).sigWidth=1;
bio(183).sigAddress='&Robot_leg_3_B.MathFunction_j';
bio(183).ndims=2;
bio(183).size=[];
bio(183).isStruct=false;

bio(184).blkName='Robot/Left Gait Motion/Left_Knee_Motion/Sum';
bio(184).sigName='';
bio(184).portIdx=0;
bio(184).dim=[1,1];
bio(184).sigWidth=1;
bio(184).sigAddress='&Robot_leg_3_B.Sum_g';
bio(184).ndims=2;
bio(184).size=[];
bio(184).isStruct=false;

bio(185).blkName='Robot/Left Gait Motion/Left_Rotation_Motion/Clock';
bio(185).sigName='';
bio(185).portIdx=0;
bio(185).dim=[1,1];
bio(185).sigWidth=1;
bio(185).sigAddress='&Robot_leg_3_B.Clock_p';
bio(185).ndims=2;
bio(185).size=[];
bio(185).isStruct=false;

bio(186).blkName='Robot/Left Gait Motion/Left_Rotation_Motion/Output';
bio(186).sigName='';
bio(186).portIdx=0;
bio(186).dim=[1,1];
bio(186).sigWidth=1;
bio(186).sigAddress='&Robot_leg_3_B.Output_ie';
bio(186).ndims=2;
bio(186).size=[];
bio(186).isStruct=false;

bio(187).blkName='Robot/Left Gait Motion/Left_Rotation_Motion/Look-Up Table1';
bio(187).sigName='';
bio(187).portIdx=0;
bio(187).dim=[1,1];
bio(187).sigWidth=1;
bio(187).sigAddress='&Robot_leg_3_B.LookUpTable1_c';
bio(187).ndims=2;
bio(187).size=[];
bio(187).isStruct=false;

bio(188).blkName='Robot/Left Gait Motion/Left_Rotation_Motion/Math Function';
bio(188).sigName='';
bio(188).portIdx=0;
bio(188).dim=[1,1];
bio(188).sigWidth=1;
bio(188).sigAddress='&Robot_leg_3_B.MathFunction_o';
bio(188).ndims=2;
bio(188).size=[];
bio(188).isStruct=false;

bio(189).blkName='Robot/Left Gait Motion/Left_Rotation_Motion/Sum';
bio(189).sigName='';
bio(189).portIdx=0;
bio(189).dim=[1,1];
bio(189).sigWidth=1;
bio(189).sigAddress='&Robot_leg_3_B.Sum_k';
bio(189).ndims=2;
bio(189).size=[];
bio(189).isStruct=false;

bio(190).blkName='Robot/Left Gait Pos/Left_Abduction_Motion/Clock';
bio(190).sigName='';
bio(190).portIdx=0;
bio(190).dim=[1,1];
bio(190).sigWidth=1;
bio(190).sigAddress='&Robot_leg_3_B.Clock_pm';
bio(190).ndims=2;
bio(190).size=[];
bio(190).isStruct=false;

bio(191).blkName='Robot/Left Gait Pos/Left_Abduction_Motion/Output';
bio(191).sigName='';
bio(191).portIdx=0;
bio(191).dim=[1,1];
bio(191).sigWidth=1;
bio(191).sigAddress='&Robot_leg_3_B.Output_nc';
bio(191).ndims=2;
bio(191).size=[];
bio(191).isStruct=false;

bio(192).blkName='Robot/Left Gait Pos/Left_Abduction_Motion/Look-Up Table1';
bio(192).sigName='';
bio(192).portIdx=0;
bio(192).dim=[1,1];
bio(192).sigWidth=1;
bio(192).sigAddress='&Robot_leg_3_B.LookUpTable1_ad';
bio(192).ndims=2;
bio(192).size=[];
bio(192).isStruct=false;

bio(193).blkName='Robot/Left Gait Pos/Left_Abduction_Motion/Math Function';
bio(193).sigName='';
bio(193).portIdx=0;
bio(193).dim=[1,1];
bio(193).sigWidth=1;
bio(193).sigAddress='&Robot_leg_3_B.MathFunction_na';
bio(193).ndims=2;
bio(193).size=[];
bio(193).isStruct=false;

bio(194).blkName='Robot/Left Gait Pos/Left_Abduction_Motion/Sum';
bio(194).sigName='';
bio(194).portIdx=0;
bio(194).dim=[1,1];
bio(194).sigWidth=1;
bio(194).sigAddress='&Robot_leg_3_B.Sum_d';
bio(194).ndims=2;
bio(194).size=[];
bio(194).isStruct=false;

bio(195).blkName='Robot/Left Gait Pos/Left_Ankle Motion/Clock';
bio(195).sigName='';
bio(195).portIdx=0;
bio(195).dim=[1,1];
bio(195).sigWidth=1;
bio(195).sigAddress='&Robot_leg_3_B.Clock_c';
bio(195).ndims=2;
bio(195).size=[];
bio(195).isStruct=false;

bio(196).blkName='Robot/Left Gait Pos/Left_Ankle Motion/Output';
bio(196).sigName='';
bio(196).portIdx=0;
bio(196).dim=[1,1];
bio(196).sigWidth=1;
bio(196).sigAddress='&Robot_leg_3_B.Output_d0';
bio(196).ndims=2;
bio(196).size=[];
bio(196).isStruct=false;

bio(197).blkName='Robot/Left Gait Pos/Left_Ankle Motion/Look-Up Table1';
bio(197).sigName='';
bio(197).portIdx=0;
bio(197).dim=[1,1];
bio(197).sigWidth=1;
bio(197).sigAddress='&Robot_leg_3_B.LookUpTable1_j3';
bio(197).ndims=2;
bio(197).size=[];
bio(197).isStruct=false;

bio(198).blkName='Robot/Left Gait Pos/Left_Ankle Motion/Math Function';
bio(198).sigName='';
bio(198).portIdx=0;
bio(198).dim=[1,1];
bio(198).sigWidth=1;
bio(198).sigAddress='&Robot_leg_3_B.MathFunction_g';
bio(198).ndims=2;
bio(198).size=[];
bio(198).isStruct=false;

bio(199).blkName='Robot/Left Gait Pos/Left_Ankle Motion/Sum';
bio(199).sigName='';
bio(199).portIdx=0;
bio(199).dim=[1,1];
bio(199).sigWidth=1;
bio(199).sigAddress='&Robot_leg_3_B.Sum_n';
bio(199).ndims=2;
bio(199).size=[];
bio(199).isStruct=false;

bio(200).blkName='Robot/Left Gait Pos/Left_Ankle_Twist_Motion/Clock';
bio(200).sigName='';
bio(200).portIdx=0;
bio(200).dim=[1,1];
bio(200).sigWidth=1;
bio(200).sigAddress='&Robot_leg_3_B.Clock_ii';
bio(200).ndims=2;
bio(200).size=[];
bio(200).isStruct=false;

bio(201).blkName='Robot/Left Gait Pos/Left_Ankle_Twist_Motion/Output';
bio(201).sigName='';
bio(201).portIdx=0;
bio(201).dim=[1,1];
bio(201).sigWidth=1;
bio(201).sigAddress='&Robot_leg_3_B.Output_l2';
bio(201).ndims=2;
bio(201).size=[];
bio(201).isStruct=false;

bio(202).blkName='Robot/Left Gait Pos/Left_Ankle_Twist_Motion/Look-Up Table1';
bio(202).sigName='';
bio(202).portIdx=0;
bio(202).dim=[1,1];
bio(202).sigWidth=1;
bio(202).sigAddress='&Robot_leg_3_B.LookUpTable1_aq';
bio(202).ndims=2;
bio(202).size=[];
bio(202).isStruct=false;

bio(203).blkName='Robot/Left Gait Pos/Left_Ankle_Twist_Motion/Math Function';
bio(203).sigName='';
bio(203).portIdx=0;
bio(203).dim=[1,1];
bio(203).sigWidth=1;
bio(203).sigAddress='&Robot_leg_3_B.MathFunction_ia';
bio(203).ndims=2;
bio(203).size=[];
bio(203).isStruct=false;

bio(204).blkName='Robot/Left Gait Pos/Left_Ankle_Twist_Motion/Sum';
bio(204).sigName='';
bio(204).portIdx=0;
bio(204).dim=[1,1];
bio(204).sigWidth=1;
bio(204).sigAddress='&Robot_leg_3_B.Sum_b';
bio(204).ndims=2;
bio(204).size=[];
bio(204).isStruct=false;

bio(205).blkName='Robot/Left Gait Pos/Left_Hip_Motion/Clock';
bio(205).sigName='';
bio(205).portIdx=0;
bio(205).dim=[1,1];
bio(205).sigWidth=1;
bio(205).sigAddress='&Robot_leg_3_B.Clock_br';
bio(205).ndims=2;
bio(205).size=[];
bio(205).isStruct=false;

bio(206).blkName='Robot/Left Gait Pos/Left_Hip_Motion/Output';
bio(206).sigName='';
bio(206).portIdx=0;
bio(206).dim=[1,1];
bio(206).sigWidth=1;
bio(206).sigAddress='&Robot_leg_3_B.Output_ka';
bio(206).ndims=2;
bio(206).size=[];
bio(206).isStruct=false;

bio(207).blkName='Robot/Left Gait Pos/Left_Hip_Motion/Look-Up Table1';
bio(207).sigName='';
bio(207).portIdx=0;
bio(207).dim=[1,1];
bio(207).sigWidth=1;
bio(207).sigAddress='&Robot_leg_3_B.LookUpTable1_f';
bio(207).ndims=2;
bio(207).size=[];
bio(207).isStruct=false;

bio(208).blkName='Robot/Left Gait Pos/Left_Hip_Motion/Math Function';
bio(208).sigName='';
bio(208).portIdx=0;
bio(208).dim=[1,1];
bio(208).sigWidth=1;
bio(208).sigAddress='&Robot_leg_3_B.MathFunction_l';
bio(208).ndims=2;
bio(208).size=[];
bio(208).isStruct=false;

bio(209).blkName='Robot/Left Gait Pos/Left_Hip_Motion/Sum';
bio(209).sigName='';
bio(209).portIdx=0;
bio(209).dim=[1,1];
bio(209).sigWidth=1;
bio(209).sigAddress='&Robot_leg_3_B.Sum_e';
bio(209).ndims=2;
bio(209).size=[];
bio(209).isStruct=false;

bio(210).blkName='Robot/Left Gait Pos/Left_Knee_Motion/Clock';
bio(210).sigName='';
bio(210).portIdx=0;
bio(210).dim=[1,1];
bio(210).sigWidth=1;
bio(210).sigAddress='&Robot_leg_3_B.Clock_l';
bio(210).ndims=2;
bio(210).size=[];
bio(210).isStruct=false;

bio(211).blkName='Robot/Left Gait Pos/Left_Knee_Motion/Output';
bio(211).sigName='';
bio(211).portIdx=0;
bio(211).dim=[1,1];
bio(211).sigWidth=1;
bio(211).sigAddress='&Robot_leg_3_B.Output_iv';
bio(211).ndims=2;
bio(211).size=[];
bio(211).isStruct=false;

bio(212).blkName='Robot/Left Gait Pos/Left_Knee_Motion/Look-Up Table1';
bio(212).sigName='';
bio(212).portIdx=0;
bio(212).dim=[1,1];
bio(212).sigWidth=1;
bio(212).sigAddress='&Robot_leg_3_B.LookUpTable1_o';
bio(212).ndims=2;
bio(212).size=[];
bio(212).isStruct=false;

bio(213).blkName='Robot/Left Gait Pos/Left_Knee_Motion/Math Function';
bio(213).sigName='';
bio(213).portIdx=0;
bio(213).dim=[1,1];
bio(213).sigWidth=1;
bio(213).sigAddress='&Robot_leg_3_B.MathFunction_k';
bio(213).ndims=2;
bio(213).size=[];
bio(213).isStruct=false;

bio(214).blkName='Robot/Left Gait Pos/Left_Knee_Motion/Sum';
bio(214).sigName='';
bio(214).portIdx=0;
bio(214).dim=[1,1];
bio(214).sigWidth=1;
bio(214).sigAddress='&Robot_leg_3_B.Sum_o2';
bio(214).ndims=2;
bio(214).size=[];
bio(214).isStruct=false;

bio(215).blkName='Robot/Left Gait Pos/Left_Rotation_Motion/Clock';
bio(215).sigName='';
bio(215).portIdx=0;
bio(215).dim=[1,1];
bio(215).sigWidth=1;
bio(215).sigAddress='&Robot_leg_3_B.Clock_d';
bio(215).ndims=2;
bio(215).size=[];
bio(215).isStruct=false;

bio(216).blkName='Robot/Left Gait Pos/Left_Rotation_Motion/Output';
bio(216).sigName='';
bio(216).portIdx=0;
bio(216).dim=[1,1];
bio(216).sigWidth=1;
bio(216).sigAddress='&Robot_leg_3_B.Output_p';
bio(216).ndims=2;
bio(216).size=[];
bio(216).isStruct=false;

bio(217).blkName='Robot/Left Gait Pos/Left_Rotation_Motion/Look-Up Table1';
bio(217).sigName='';
bio(217).portIdx=0;
bio(217).dim=[1,1];
bio(217).sigWidth=1;
bio(217).sigAddress='&Robot_leg_3_B.LookUpTable1_i';
bio(217).ndims=2;
bio(217).size=[];
bio(217).isStruct=false;

bio(218).blkName='Robot/Left Gait Pos/Left_Rotation_Motion/Math Function';
bio(218).sigName='';
bio(218).portIdx=0;
bio(218).dim=[1,1];
bio(218).sigWidth=1;
bio(218).sigAddress='&Robot_leg_3_B.MathFunction_f';
bio(218).ndims=2;
bio(218).size=[];
bio(218).isStruct=false;

bio(219).blkName='Robot/Left Gait Pos/Left_Rotation_Motion/Sum';
bio(219).sigName='';
bio(219).portIdx=0;
bio(219).dim=[1,1];
bio(219).sigWidth=1;
bio(219).sigAddress='&Robot_leg_3_B.Sum_f';
bio(219).ndims=2;
bio(219).size=[];
bio(219).isStruct=false;

bio(220).blkName='Robot/Left Still/Left_Abduction_Motion/Clock';
bio(220).sigName='';
bio(220).portIdx=0;
bio(220).dim=[1,1];
bio(220).sigWidth=1;
bio(220).sigAddress='&Robot_leg_3_B.Clock_ha';
bio(220).ndims=2;
bio(220).size=[];
bio(220).isStruct=false;

bio(221).blkName='Robot/Left Still/Left_Abduction_Motion/Output';
bio(221).sigName='';
bio(221).portIdx=0;
bio(221).dim=[1,1];
bio(221).sigWidth=1;
bio(221).sigAddress='&Robot_leg_3_B.Output_j3';
bio(221).ndims=2;
bio(221).size=[];
bio(221).isStruct=false;

bio(222).blkName='Robot/Left Still/Left_Abduction_Motion/Look-Up Table1';
bio(222).sigName='';
bio(222).portIdx=0;
bio(222).dim=[1,1];
bio(222).sigWidth=1;
bio(222).sigAddress='&Robot_leg_3_B.LookUpTable1_fk';
bio(222).ndims=2;
bio(222).size=[];
bio(222).isStruct=false;

bio(223).blkName='Robot/Left Still/Left_Abduction_Motion/Math Function';
bio(223).sigName='';
bio(223).portIdx=0;
bio(223).dim=[1,1];
bio(223).sigWidth=1;
bio(223).sigAddress='&Robot_leg_3_B.MathFunction_id';
bio(223).ndims=2;
bio(223).size=[];
bio(223).isStruct=false;

bio(224).blkName='Robot/Left Still/Left_Abduction_Motion/Sum';
bio(224).sigName='';
bio(224).portIdx=0;
bio(224).dim=[1,1];
bio(224).sigWidth=1;
bio(224).sigAddress='&Robot_leg_3_B.Sum_li';
bio(224).ndims=2;
bio(224).size=[];
bio(224).isStruct=false;

bio(225).blkName='Robot/Left Still/Left_Ankle Motion/Clock';
bio(225).sigName='';
bio(225).portIdx=0;
bio(225).dim=[1,1];
bio(225).sigWidth=1;
bio(225).sigAddress='&Robot_leg_3_B.Clock_oi';
bio(225).ndims=2;
bio(225).size=[];
bio(225).isStruct=false;

bio(226).blkName='Robot/Left Still/Left_Ankle Motion/Output';
bio(226).sigName='';
bio(226).portIdx=0;
bio(226).dim=[1,1];
bio(226).sigWidth=1;
bio(226).sigAddress='&Robot_leg_3_B.Output_ja';
bio(226).ndims=2;
bio(226).size=[];
bio(226).isStruct=false;

bio(227).blkName='Robot/Left Still/Left_Ankle Motion/Look-Up Table1';
bio(227).sigName='';
bio(227).portIdx=0;
bio(227).dim=[1,1];
bio(227).sigWidth=1;
bio(227).sigAddress='&Robot_leg_3_B.LookUpTable1_ef';
bio(227).ndims=2;
bio(227).size=[];
bio(227).isStruct=false;

bio(228).blkName='Robot/Left Still/Left_Ankle Motion/Math Function';
bio(228).sigName='';
bio(228).portIdx=0;
bio(228).dim=[1,1];
bio(228).sigWidth=1;
bio(228).sigAddress='&Robot_leg_3_B.MathFunction_ln';
bio(228).ndims=2;
bio(228).size=[];
bio(228).isStruct=false;

bio(229).blkName='Robot/Left Still/Left_Ankle Motion/Sum';
bio(229).sigName='';
bio(229).portIdx=0;
bio(229).dim=[1,1];
bio(229).sigWidth=1;
bio(229).sigAddress='&Robot_leg_3_B.Sum_bf';
bio(229).ndims=2;
bio(229).size=[];
bio(229).isStruct=false;

bio(230).blkName='Robot/Left Still/Left_Ankle_Twist_Motion/Clock';
bio(230).sigName='';
bio(230).portIdx=0;
bio(230).dim=[1,1];
bio(230).sigWidth=1;
bio(230).sigAddress='&Robot_leg_3_B.Clock_f';
bio(230).ndims=2;
bio(230).size=[];
bio(230).isStruct=false;

bio(231).blkName='Robot/Left Still/Left_Ankle_Twist_Motion/Output';
bio(231).sigName='';
bio(231).portIdx=0;
bio(231).dim=[1,1];
bio(231).sigWidth=1;
bio(231).sigAddress='&Robot_leg_3_B.Output_mg';
bio(231).ndims=2;
bio(231).size=[];
bio(231).isStruct=false;

bio(232).blkName='Robot/Left Still/Left_Ankle_Twist_Motion/Look-Up Table1';
bio(232).sigName='';
bio(232).portIdx=0;
bio(232).dim=[1,1];
bio(232).sigWidth=1;
bio(232).sigAddress='&Robot_leg_3_B.LookUpTable1_hu';
bio(232).ndims=2;
bio(232).size=[];
bio(232).isStruct=false;

bio(233).blkName='Robot/Left Still/Left_Ankle_Twist_Motion/Math Function';
bio(233).sigName='';
bio(233).portIdx=0;
bio(233).dim=[1,1];
bio(233).sigWidth=1;
bio(233).sigAddress='&Robot_leg_3_B.MathFunction_b';
bio(233).ndims=2;
bio(233).size=[];
bio(233).isStruct=false;

bio(234).blkName='Robot/Left Still/Left_Ankle_Twist_Motion/Sum';
bio(234).sigName='';
bio(234).portIdx=0;
bio(234).dim=[1,1];
bio(234).sigWidth=1;
bio(234).sigAddress='&Robot_leg_3_B.Sum_iw';
bio(234).ndims=2;
bio(234).size=[];
bio(234).isStruct=false;

bio(235).blkName='Robot/Left Still/Left_Hip_Motion/Clock';
bio(235).sigName='';
bio(235).portIdx=0;
bio(235).dim=[1,1];
bio(235).sigWidth=1;
bio(235).sigAddress='&Robot_leg_3_B.Clock_hc';
bio(235).ndims=2;
bio(235).size=[];
bio(235).isStruct=false;

bio(236).blkName='Robot/Left Still/Left_Hip_Motion/Output';
bio(236).sigName='';
bio(236).portIdx=0;
bio(236).dim=[1,1];
bio(236).sigWidth=1;
bio(236).sigAddress='&Robot_leg_3_B.Output_dz';
bio(236).ndims=2;
bio(236).size=[];
bio(236).isStruct=false;

bio(237).blkName='Robot/Left Still/Left_Hip_Motion/Look-Up Table1';
bio(237).sigName='';
bio(237).portIdx=0;
bio(237).dim=[1,1];
bio(237).sigWidth=1;
bio(237).sigAddress='&Robot_leg_3_B.LookUpTable1_c3';
bio(237).ndims=2;
bio(237).size=[];
bio(237).isStruct=false;

bio(238).blkName='Robot/Left Still/Left_Hip_Motion/Math Function';
bio(238).sigName='';
bio(238).portIdx=0;
bio(238).dim=[1,1];
bio(238).sigWidth=1;
bio(238).sigAddress='&Robot_leg_3_B.MathFunction_oa';
bio(238).ndims=2;
bio(238).size=[];
bio(238).isStruct=false;

bio(239).blkName='Robot/Left Still/Left_Hip_Motion/Sum';
bio(239).sigName='';
bio(239).portIdx=0;
bio(239).dim=[1,1];
bio(239).sigWidth=1;
bio(239).sigAddress='&Robot_leg_3_B.Sum_m4';
bio(239).ndims=2;
bio(239).size=[];
bio(239).isStruct=false;

bio(240).blkName='Robot/Left Still/Left_Knee_Motion/Clock';
bio(240).sigName='';
bio(240).portIdx=0;
bio(240).dim=[1,1];
bio(240).sigWidth=1;
bio(240).sigAddress='&Robot_leg_3_B.Clock_d1';
bio(240).ndims=2;
bio(240).size=[];
bio(240).isStruct=false;

bio(241).blkName='Robot/Left Still/Left_Knee_Motion/Output';
bio(241).sigName='';
bio(241).portIdx=0;
bio(241).dim=[1,1];
bio(241).sigWidth=1;
bio(241).sigAddress='&Robot_leg_3_B.Output_am';
bio(241).ndims=2;
bio(241).size=[];
bio(241).isStruct=false;

bio(242).blkName='Robot/Left Still/Left_Knee_Motion/Look-Up Table1';
bio(242).sigName='';
bio(242).portIdx=0;
bio(242).dim=[1,1];
bio(242).sigWidth=1;
bio(242).sigAddress='&Robot_leg_3_B.LookUpTable1_bf';
bio(242).ndims=2;
bio(242).size=[];
bio(242).isStruct=false;

bio(243).blkName='Robot/Left Still/Left_Knee_Motion/Math Function';
bio(243).sigName='';
bio(243).portIdx=0;
bio(243).dim=[1,1];
bio(243).sigWidth=1;
bio(243).sigAddress='&Robot_leg_3_B.MathFunction_lu';
bio(243).ndims=2;
bio(243).size=[];
bio(243).isStruct=false;

bio(244).blkName='Robot/Left Still/Left_Knee_Motion/Sum';
bio(244).sigName='';
bio(244).portIdx=0;
bio(244).dim=[1,1];
bio(244).sigWidth=1;
bio(244).sigAddress='&Robot_leg_3_B.Sum_ko';
bio(244).ndims=2;
bio(244).size=[];
bio(244).isStruct=false;

bio(245).blkName='Robot/Left Still/Left_Rotation_Motion/Clock';
bio(245).sigName='';
bio(245).portIdx=0;
bio(245).dim=[1,1];
bio(245).sigWidth=1;
bio(245).sigAddress='&Robot_leg_3_B.Clock_jy';
bio(245).ndims=2;
bio(245).size=[];
bio(245).isStruct=false;

bio(246).blkName='Robot/Left Still/Left_Rotation_Motion/Output';
bio(246).sigName='';
bio(246).portIdx=0;
bio(246).dim=[1,1];
bio(246).sigWidth=1;
bio(246).sigAddress='&Robot_leg_3_B.Output_f';
bio(246).ndims=2;
bio(246).size=[];
bio(246).isStruct=false;

bio(247).blkName='Robot/Left Still/Left_Rotation_Motion/Look-Up Table1';
bio(247).sigName='';
bio(247).portIdx=0;
bio(247).dim=[1,1];
bio(247).sigWidth=1;
bio(247).sigAddress='&Robot_leg_3_B.LookUpTable1_ku';
bio(247).ndims=2;
bio(247).size=[];
bio(247).isStruct=false;

bio(248).blkName='Robot/Left Still/Left_Rotation_Motion/Math Function';
bio(248).sigName='';
bio(248).portIdx=0;
bio(248).dim=[1,1];
bio(248).sigWidth=1;
bio(248).sigAddress='&Robot_leg_3_B.MathFunction_ad';
bio(248).ndims=2;
bio(248).size=[];
bio(248).isStruct=false;

bio(249).blkName='Robot/Left Still/Left_Rotation_Motion/Sum';
bio(249).sigName='';
bio(249).portIdx=0;
bio(249).dim=[1,1];
bio(249).sigWidth=1;
bio(249).sigAddress='&Robot_leg_3_B.Sum_f0';
bio(249).ndims=2;
bio(249).size=[];
bio(249).isStruct=false;

bio(250).blkName='Robot/Left_leg/Contact Force Logging/Math Function';
bio(250).sigName='';
bio(250).portIdx=0;
bio(250).dim=[3,1];
bio(250).sigWidth=3;
bio(250).sigAddress='&Robot_leg_3_B.MathFunction_iy[0]';
bio(250).ndims=2;
bio(250).size=[];
bio(250).isStruct=false;

bio(251).blkName='Robot/Left_leg/Contact Force Logging/Add';
bio(251).sigName='Normal Force';
bio(251).portIdx=0;
bio(251).dim=[1,1];
bio(251).sigWidth=1;
bio(251).sigAddress='&Robot_leg_3_B.NormalForce_i';
bio(251).ndims=2;
bio(251).size=[];
bio(251).isStruct=false;

bio(252).blkName='Robot/Left_leg/Contact Force Logging/Add1';
bio(252).sigName='';
bio(252).portIdx=0;
bio(252).dim=[3,1];
bio(252).sigWidth=3;
bio(252).sigAddress='&Robot_leg_3_B.Add1_i[0]';
bio(252).ndims=2;
bio(252).size=[];
bio(252).isStruct=false;

bio(253).blkName='Robot/Left_leg/Contact Force Logging/Sum of Elements';
bio(253).sigName='';
bio(253).portIdx=0;
bio(253).dim=[1,1];
bio(253).sigWidth=1;
bio(253).sigAddress='&Robot_leg_3_B.SumofElements_l';
bio(253).ndims=2;
bio(253).size=[];
bio(253).isStruct=false;

bio(254).blkName='Robot/Left_leg/Contact Force Logging/Sqrt';
bio(254).sigName='Friction Force';
bio(254).portIdx=0;
bio(254).dim=[1,1];
bio(254).sigWidth=1;
bio(254).sigAddress='&Robot_leg_3_B.FrictionForce_k';
bio(254).ndims=2;
bio(254).size=[];
bio(254).isStruct=false;

bio(255).blkName='Robot/Left_leg/Sphere to Plane Force/Merge';
bio(255).sigName='FSph';
bio(255).portIdx=0;
bio(255).dim=[12,1];
bio(255).sigWidth=12;
bio(255).sigAddress='&Robot_leg_3_B.FSph[0]';
bio(255).ndims=2;
bio(255).size=[];
bio(255).isStruct=false;

bio(256).blkName='Robot/Left_leg/Sphere to Plane Force1/Merge';
bio(256).sigName='FSph';
bio(256).portIdx=0;
bio(256).dim=[12,1];
bio(256).sigWidth=12;
bio(256).sigAddress='&Robot_leg_3_B.FSph_m[0]';
bio(256).ndims=2;
bio(256).size=[];
bio(256).isStruct=false;

bio(257).blkName='Robot/Left_leg/Sphere to Plane Force2/Merge';
bio(257).sigName='FSph';
bio(257).portIdx=0;
bio(257).dim=[12,1];
bio(257).sigWidth=12;
bio(257).sigAddress='&Robot_leg_3_B.FSph_l[0]';
bio(257).ndims=2;
bio(257).size=[];
bio(257).isStruct=false;

bio(258).blkName='Robot/Left_leg/Sphere to Plane Force3/Merge';
bio(258).sigName='FSph';
bio(258).portIdx=0;
bio(258).dim=[12,1];
bio(258).sigWidth=12;
bio(258).sigAddress='&Robot_leg_3_B.FSph_a[0]';
bio(258).ndims=2;
bio(258).size=[];
bio(258).isStruct=false;

bio(259).blkName='Robot/Right First Step/Right_Abduction_Motion/Clock';
bio(259).sigName='';
bio(259).portIdx=0;
bio(259).dim=[1,1];
bio(259).sigWidth=1;
bio(259).sigAddress='&Robot_leg_3_B.Clock_gg';
bio(259).ndims=2;
bio(259).size=[];
bio(259).isStruct=false;

bio(260).blkName='Robot/Right First Step/Right_Abduction_Motion/Output';
bio(260).sigName='';
bio(260).portIdx=0;
bio(260).dim=[1,1];
bio(260).sigWidth=1;
bio(260).sigAddress='&Robot_leg_3_B.Output_m';
bio(260).ndims=2;
bio(260).size=[];
bio(260).isStruct=false;

bio(261).blkName='Robot/Right First Step/Right_Abduction_Motion/Look-Up Table1';
bio(261).sigName='';
bio(261).portIdx=0;
bio(261).dim=[1,1];
bio(261).sigWidth=1;
bio(261).sigAddress='&Robot_leg_3_B.LookUpTable1_fn';
bio(261).ndims=2;
bio(261).size=[];
bio(261).isStruct=false;

bio(262).blkName='Robot/Right First Step/Right_Abduction_Motion/Math Function';
bio(262).sigName='';
bio(262).portIdx=0;
bio(262).dim=[1,1];
bio(262).sigWidth=1;
bio(262).sigAddress='&Robot_leg_3_B.MathFunction_ae';
bio(262).ndims=2;
bio(262).size=[];
bio(262).isStruct=false;

bio(263).blkName='Robot/Right First Step/Right_Abduction_Motion/Sum';
bio(263).sigName='';
bio(263).portIdx=0;
bio(263).dim=[1,1];
bio(263).sigWidth=1;
bio(263).sigAddress='&Robot_leg_3_B.Sum_cg';
bio(263).ndims=2;
bio(263).size=[];
bio(263).isStruct=false;

bio(264).blkName='Robot/Right First Step/Right_Ankle_Motion/Clock';
bio(264).sigName='';
bio(264).portIdx=0;
bio(264).dim=[1,1];
bio(264).sigWidth=1;
bio(264).sigAddress='&Robot_leg_3_B.Clock_pr';
bio(264).ndims=2;
bio(264).size=[];
bio(264).isStruct=false;

bio(265).blkName='Robot/Right First Step/Right_Ankle_Motion/Output';
bio(265).sigName='';
bio(265).portIdx=0;
bio(265).dim=[1,1];
bio(265).sigWidth=1;
bio(265).sigAddress='&Robot_leg_3_B.Output_a';
bio(265).ndims=2;
bio(265).size=[];
bio(265).isStruct=false;

bio(266).blkName='Robot/Right First Step/Right_Ankle_Motion/Look-Up Table1';
bio(266).sigName='';
bio(266).portIdx=0;
bio(266).dim=[1,1];
bio(266).sigWidth=1;
bio(266).sigAddress='&Robot_leg_3_B.LookUpTable1_kf';
bio(266).ndims=2;
bio(266).size=[];
bio(266).isStruct=false;

bio(267).blkName='Robot/Right First Step/Right_Ankle_Motion/Math Function';
bio(267).sigName='';
bio(267).portIdx=0;
bio(267).dim=[1,1];
bio(267).sigWidth=1;
bio(267).sigAddress='&Robot_leg_3_B.MathFunction_ih';
bio(267).ndims=2;
bio(267).size=[];
bio(267).isStruct=false;

bio(268).blkName='Robot/Right First Step/Right_Ankle_Motion/Sum';
bio(268).sigName='';
bio(268).portIdx=0;
bio(268).dim=[1,1];
bio(268).sigWidth=1;
bio(268).sigAddress='&Robot_leg_3_B.Sum_ei';
bio(268).ndims=2;
bio(268).size=[];
bio(268).isStruct=false;

bio(269).blkName='Robot/Right First Step/Right_Ankle_Twist_Motion/Clock';
bio(269).sigName='';
bio(269).portIdx=0;
bio(269).dim=[1,1];
bio(269).sigWidth=1;
bio(269).sigAddress='&Robot_leg_3_B.Clock_b4';
bio(269).ndims=2;
bio(269).size=[];
bio(269).isStruct=false;

bio(270).blkName='Robot/Right First Step/Right_Ankle_Twist_Motion/Output';
bio(270).sigName='';
bio(270).portIdx=0;
bio(270).dim=[1,1];
bio(270).sigWidth=1;
bio(270).sigAddress='&Robot_leg_3_B.Output_o';
bio(270).ndims=2;
bio(270).size=[];
bio(270).isStruct=false;

bio(271).blkName='Robot/Right First Step/Right_Ankle_Twist_Motion/Look-Up Table1';
bio(271).sigName='';
bio(271).portIdx=0;
bio(271).dim=[1,1];
bio(271).sigWidth=1;
bio(271).sigAddress='&Robot_leg_3_B.LookUpTable1_m1';
bio(271).ndims=2;
bio(271).size=[];
bio(271).isStruct=false;

bio(272).blkName='Robot/Right First Step/Right_Ankle_Twist_Motion/Math Function';
bio(272).sigName='';
bio(272).portIdx=0;
bio(272).dim=[1,1];
bio(272).sigWidth=1;
bio(272).sigAddress='&Robot_leg_3_B.MathFunction_j0';
bio(272).ndims=2;
bio(272).size=[];
bio(272).isStruct=false;

bio(273).blkName='Robot/Right First Step/Right_Ankle_Twist_Motion/Sum';
bio(273).sigName='';
bio(273).portIdx=0;
bio(273).dim=[1,1];
bio(273).sigWidth=1;
bio(273).sigAddress='&Robot_leg_3_B.Sum_dv';
bio(273).ndims=2;
bio(273).size=[];
bio(273).isStruct=false;

bio(274).blkName='Robot/Right First Step/Right_Hip_Motion/Clock';
bio(274).sigName='';
bio(274).portIdx=0;
bio(274).dim=[1,1];
bio(274).sigWidth=1;
bio(274).sigAddress='&Robot_leg_3_B.Clock_cj';
bio(274).ndims=2;
bio(274).size=[];
bio(274).isStruct=false;

bio(275).blkName='Robot/Right First Step/Right_Hip_Motion/Output';
bio(275).sigName='';
bio(275).portIdx=0;
bio(275).dim=[1,1];
bio(275).sigWidth=1;
bio(275).sigAddress='&Robot_leg_3_B.Output_gk';
bio(275).ndims=2;
bio(275).size=[];
bio(275).isStruct=false;

bio(276).blkName='Robot/Right First Step/Right_Hip_Motion/Look-Up Table1';
bio(276).sigName='';
bio(276).portIdx=0;
bio(276).dim=[1,1];
bio(276).sigWidth=1;
bio(276).sigAddress='&Robot_leg_3_B.LookUpTable1_kfu';
bio(276).ndims=2;
bio(276).size=[];
bio(276).isStruct=false;

bio(277).blkName='Robot/Right First Step/Right_Hip_Motion/Math Function';
bio(277).sigName='';
bio(277).portIdx=0;
bio(277).dim=[1,1];
bio(277).sigWidth=1;
bio(277).sigAddress='&Robot_leg_3_B.MathFunction_du';
bio(277).ndims=2;
bio(277).size=[];
bio(277).isStruct=false;

bio(278).blkName='Robot/Right First Step/Right_Hip_Motion/Sum';
bio(278).sigName='';
bio(278).portIdx=0;
bio(278).dim=[1,1];
bio(278).sigWidth=1;
bio(278).sigAddress='&Robot_leg_3_B.Sum_fz';
bio(278).ndims=2;
bio(278).size=[];
bio(278).isStruct=false;

bio(279).blkName='Robot/Right First Step/Right_Knee_Motion/Clock';
bio(279).sigName='';
bio(279).portIdx=0;
bio(279).dim=[1,1];
bio(279).sigWidth=1;
bio(279).sigAddress='&Robot_leg_3_B.Clock_brf';
bio(279).ndims=2;
bio(279).size=[];
bio(279).isStruct=false;

bio(280).blkName='Robot/Right First Step/Right_Knee_Motion/Output';
bio(280).sigName='';
bio(280).portIdx=0;
bio(280).dim=[1,1];
bio(280).sigWidth=1;
bio(280).sigAddress='&Robot_leg_3_B.Output_g';
bio(280).ndims=2;
bio(280).size=[];
bio(280).isStruct=false;

bio(281).blkName='Robot/Right First Step/Right_Knee_Motion/Look-Up Table1';
bio(281).sigName='';
bio(281).portIdx=0;
bio(281).dim=[1,1];
bio(281).sigWidth=1;
bio(281).sigAddress='&Robot_leg_3_B.LookUpTable1_oe';
bio(281).ndims=2;
bio(281).size=[];
bio(281).isStruct=false;

bio(282).blkName='Robot/Right First Step/Right_Knee_Motion/Math Function';
bio(282).sigName='';
bio(282).portIdx=0;
bio(282).dim=[1,1];
bio(282).sigWidth=1;
bio(282).sigAddress='&Robot_leg_3_B.MathFunction_e';
bio(282).ndims=2;
bio(282).size=[];
bio(282).isStruct=false;

bio(283).blkName='Robot/Right First Step/Right_Knee_Motion/Sum';
bio(283).sigName='';
bio(283).portIdx=0;
bio(283).dim=[1,1];
bio(283).sigWidth=1;
bio(283).sigAddress='&Robot_leg_3_B.Sum_g3';
bio(283).ndims=2;
bio(283).size=[];
bio(283).isStruct=false;

bio(284).blkName='Robot/Right First Step/Right_Rotation_Motion/Clock';
bio(284).sigName='';
bio(284).portIdx=0;
bio(284).dim=[1,1];
bio(284).sigWidth=1;
bio(284).sigAddress='&Robot_leg_3_B.Clock_gw';
bio(284).ndims=2;
bio(284).size=[];
bio(284).isStruct=false;

bio(285).blkName='Robot/Right First Step/Right_Rotation_Motion/Output';
bio(285).sigName='';
bio(285).portIdx=0;
bio(285).dim=[1,1];
bio(285).sigWidth=1;
bio(285).sigAddress='&Robot_leg_3_B.Output_oy';
bio(285).ndims=2;
bio(285).size=[];
bio(285).isStruct=false;

bio(286).blkName='Robot/Right First Step/Right_Rotation_Motion/Look-Up Table1';
bio(286).sigName='';
bio(286).portIdx=0;
bio(286).dim=[1,1];
bio(286).sigWidth=1;
bio(286).sigAddress='&Robot_leg_3_B.LookUpTable1_fw';
bio(286).ndims=2;
bio(286).size=[];
bio(286).isStruct=false;

bio(287).blkName='Robot/Right First Step/Right_Rotation_Motion/Math Function';
bio(287).sigName='';
bio(287).portIdx=0;
bio(287).dim=[1,1];
bio(287).sigWidth=1;
bio(287).sigAddress='&Robot_leg_3_B.MathFunction_pw';
bio(287).ndims=2;
bio(287).size=[];
bio(287).isStruct=false;

bio(288).blkName='Robot/Right First Step/Right_Rotation_Motion/Sum';
bio(288).sigName='';
bio(288).portIdx=0;
bio(288).dim=[1,1];
bio(288).sigWidth=1;
bio(288).sigAddress='&Robot_leg_3_B.Sum_il';
bio(288).ndims=2;
bio(288).size=[];
bio(288).isStruct=false;

bio(289).blkName='Robot/Right Gait Motion/Right_Abduction_Motion/Clock';
bio(289).sigName='';
bio(289).portIdx=0;
bio(289).dim=[1,1];
bio(289).sigWidth=1;
bio(289).sigAddress='&Robot_leg_3_B.Clock_bv';
bio(289).ndims=2;
bio(289).size=[];
bio(289).isStruct=false;

bio(290).blkName='Robot/Right Gait Motion/Right_Abduction_Motion/Output';
bio(290).sigName='';
bio(290).portIdx=0;
bio(290).dim=[1,1];
bio(290).sigWidth=1;
bio(290).sigAddress='&Robot_leg_3_B.Output_bw';
bio(290).ndims=2;
bio(290).size=[];
bio(290).isStruct=false;

bio(291).blkName='Robot/Right Gait Motion/Right_Abduction_Motion/Look-Up Table1';
bio(291).sigName='';
bio(291).portIdx=0;
bio(291).dim=[1,1];
bio(291).sigWidth=1;
bio(291).sigAddress='&Robot_leg_3_B.LookUpTable1_ky';
bio(291).ndims=2;
bio(291).size=[];
bio(291).isStruct=false;

bio(292).blkName='Robot/Right Gait Motion/Right_Abduction_Motion/Math Function';
bio(292).sigName='';
bio(292).portIdx=0;
bio(292).dim=[1,1];
bio(292).sigWidth=1;
bio(292).sigAddress='&Robot_leg_3_B.MathFunction_p3';
bio(292).ndims=2;
bio(292).size=[];
bio(292).isStruct=false;

bio(293).blkName='Robot/Right Gait Motion/Right_Abduction_Motion/Sum';
bio(293).sigName='';
bio(293).portIdx=0;
bio(293).dim=[1,1];
bio(293).sigWidth=1;
bio(293).sigAddress='&Robot_leg_3_B.Sum_bfe';
bio(293).ndims=2;
bio(293).size=[];
bio(293).isStruct=false;

bio(294).blkName='Robot/Right Gait Motion/Right_Ankle_Motion/Clock';
bio(294).sigName='';
bio(294).portIdx=0;
bio(294).dim=[1,1];
bio(294).sigWidth=1;
bio(294).sigAddress='&Robot_leg_3_B.Clock_g';
bio(294).ndims=2;
bio(294).size=[];
bio(294).isStruct=false;

bio(295).blkName='Robot/Right Gait Motion/Right_Ankle_Motion/Output';
bio(295).sigName='';
bio(295).portIdx=0;
bio(295).dim=[1,1];
bio(295).sigWidth=1;
bio(295).sigAddress='&Robot_leg_3_B.Output_h';
bio(295).ndims=2;
bio(295).size=[];
bio(295).isStruct=false;

bio(296).blkName='Robot/Right Gait Motion/Right_Ankle_Motion/Look-Up Table1';
bio(296).sigName='';
bio(296).portIdx=0;
bio(296).dim=[1,1];
bio(296).sigWidth=1;
bio(296).sigAddress='&Robot_leg_3_B.LookUpTable1_l';
bio(296).ndims=2;
bio(296).size=[];
bio(296).isStruct=false;

bio(297).blkName='Robot/Right Gait Motion/Right_Ankle_Motion/Math Function';
bio(297).sigName='';
bio(297).portIdx=0;
bio(297).dim=[1,1];
bio(297).sigWidth=1;
bio(297).sigAddress='&Robot_leg_3_B.MathFunction_p';
bio(297).ndims=2;
bio(297).size=[];
bio(297).isStruct=false;

bio(298).blkName='Robot/Right Gait Motion/Right_Ankle_Motion/Sum';
bio(298).sigName='';
bio(298).portIdx=0;
bio(298).dim=[1,1];
bio(298).sigWidth=1;
bio(298).sigAddress='&Robot_leg_3_B.Sum_ml';
bio(298).ndims=2;
bio(298).size=[];
bio(298).isStruct=false;

bio(299).blkName='Robot/Right Gait Motion/Right_Ankle_Twist_Motion/Clock';
bio(299).sigName='';
bio(299).portIdx=0;
bio(299).dim=[1,1];
bio(299).sigWidth=1;
bio(299).sigAddress='&Robot_leg_3_B.Clock_k';
bio(299).ndims=2;
bio(299).size=[];
bio(299).isStruct=false;

bio(300).blkName='Robot/Right Gait Motion/Right_Ankle_Twist_Motion/Output';
bio(300).sigName='';
bio(300).portIdx=0;
bio(300).dim=[1,1];
bio(300).sigWidth=1;
bio(300).sigAddress='&Robot_leg_3_B.Output_l';
bio(300).ndims=2;
bio(300).size=[];
bio(300).isStruct=false;

bio(301).blkName='Robot/Right Gait Motion/Right_Ankle_Twist_Motion/Look-Up Table1';
bio(301).sigName='';
bio(301).portIdx=0;
bio(301).dim=[1,1];
bio(301).sigWidth=1;
bio(301).sigAddress='&Robot_leg_3_B.LookUpTable1_bs';
bio(301).ndims=2;
bio(301).size=[];
bio(301).isStruct=false;

bio(302).blkName='Robot/Right Gait Motion/Right_Ankle_Twist_Motion/Math Function';
bio(302).sigName='';
bio(302).portIdx=0;
bio(302).dim=[1,1];
bio(302).sigWidth=1;
bio(302).sigAddress='&Robot_leg_3_B.MathFunction_ho';
bio(302).ndims=2;
bio(302).size=[];
bio(302).isStruct=false;

bio(303).blkName='Robot/Right Gait Motion/Right_Ankle_Twist_Motion/Sum';
bio(303).sigName='';
bio(303).portIdx=0;
bio(303).dim=[1,1];
bio(303).sigWidth=1;
bio(303).sigAddress='&Robot_leg_3_B.Sum_de';
bio(303).ndims=2;
bio(303).size=[];
bio(303).isStruct=false;

bio(304).blkName='Robot/Right Gait Motion/Right_Hip_Motion/Clock';
bio(304).sigName='';
bio(304).portIdx=0;
bio(304).dim=[1,1];
bio(304).sigWidth=1;
bio(304).sigAddress='&Robot_leg_3_B.Clock_j2';
bio(304).ndims=2;
bio(304).size=[];
bio(304).isStruct=false;

bio(305).blkName='Robot/Right Gait Motion/Right_Hip_Motion/Output';
bio(305).sigName='';
bio(305).portIdx=0;
bio(305).dim=[1,1];
bio(305).sigWidth=1;
bio(305).sigAddress='&Robot_leg_3_B.Output_b';
bio(305).ndims=2;
bio(305).size=[];
bio(305).isStruct=false;

bio(306).blkName='Robot/Right Gait Motion/Right_Hip_Motion/Look-Up Table1';
bio(306).sigName='';
bio(306).portIdx=0;
bio(306).dim=[1,1];
bio(306).sigWidth=1;
bio(306).sigAddress='&Robot_leg_3_B.LookUpTable1_ho';
bio(306).ndims=2;
bio(306).size=[];
bio(306).isStruct=false;

bio(307).blkName='Robot/Right Gait Motion/Right_Hip_Motion/Math Function';
bio(307).sigName='';
bio(307).portIdx=0;
bio(307).dim=[1,1];
bio(307).sigWidth=1;
bio(307).sigAddress='&Robot_leg_3_B.MathFunction_g1';
bio(307).ndims=2;
bio(307).size=[];
bio(307).isStruct=false;

bio(308).blkName='Robot/Right Gait Motion/Right_Hip_Motion/Sum';
bio(308).sigName='';
bio(308).portIdx=0;
bio(308).dim=[1,1];
bio(308).sigWidth=1;
bio(308).sigAddress='&Robot_leg_3_B.Sum_kb';
bio(308).ndims=2;
bio(308).size=[];
bio(308).isStruct=false;

bio(309).blkName='Robot/Right Gait Motion/Right_Knee_Motion/Clock';
bio(309).sigName='';
bio(309).portIdx=0;
bio(309).dim=[1,1];
bio(309).sigWidth=1;
bio(309).sigAddress='&Robot_leg_3_B.Clock_op';
bio(309).ndims=2;
bio(309).size=[];
bio(309).isStruct=false;

bio(310).blkName='Robot/Right Gait Motion/Right_Knee_Motion/Output';
bio(310).sigName='';
bio(310).portIdx=0;
bio(310).dim=[1,1];
bio(310).sigWidth=1;
bio(310).sigAddress='&Robot_leg_3_B.Output_n';
bio(310).ndims=2;
bio(310).size=[];
bio(310).isStruct=false;

bio(311).blkName='Robot/Right Gait Motion/Right_Knee_Motion/Look-Up Table1';
bio(311).sigName='';
bio(311).portIdx=0;
bio(311).dim=[1,1];
bio(311).sigWidth=1;
bio(311).sigAddress='&Robot_leg_3_B.LookUpTable1_ea';
bio(311).ndims=2;
bio(311).size=[];
bio(311).isStruct=false;

bio(312).blkName='Robot/Right Gait Motion/Right_Knee_Motion/Math Function';
bio(312).sigName='';
bio(312).portIdx=0;
bio(312).dim=[1,1];
bio(312).sigWidth=1;
bio(312).sigAddress='&Robot_leg_3_B.MathFunction_p4';
bio(312).ndims=2;
bio(312).size=[];
bio(312).isStruct=false;

bio(313).blkName='Robot/Right Gait Motion/Right_Knee_Motion/Sum';
bio(313).sigName='';
bio(313).portIdx=0;
bio(313).dim=[1,1];
bio(313).sigWidth=1;
bio(313).sigAddress='&Robot_leg_3_B.Sum_c';
bio(313).ndims=2;
bio(313).size=[];
bio(313).isStruct=false;

bio(314).blkName='Robot/Right Gait Motion/Right_Rotation_Motion/Clock';
bio(314).sigName='';
bio(314).portIdx=0;
bio(314).dim=[1,1];
bio(314).sigWidth=1;
bio(314).sigAddress='&Robot_leg_3_B.Clock_mx';
bio(314).ndims=2;
bio(314).size=[];
bio(314).isStruct=false;

bio(315).blkName='Robot/Right Gait Motion/Right_Rotation_Motion/Output';
bio(315).sigName='';
bio(315).portIdx=0;
bio(315).dim=[1,1];
bio(315).sigWidth=1;
bio(315).sigAddress='&Robot_leg_3_B.Output_i';
bio(315).ndims=2;
bio(315).size=[];
bio(315).isStruct=false;

bio(316).blkName='Robot/Right Gait Motion/Right_Rotation_Motion/Look-Up Table1';
bio(316).sigName='';
bio(316).portIdx=0;
bio(316).dim=[1,1];
bio(316).sigWidth=1;
bio(316).sigAddress='&Robot_leg_3_B.LookUpTable1_dq';
bio(316).ndims=2;
bio(316).size=[];
bio(316).isStruct=false;

bio(317).blkName='Robot/Right Gait Motion/Right_Rotation_Motion/Math Function';
bio(317).sigName='';
bio(317).portIdx=0;
bio(317).dim=[1,1];
bio(317).sigWidth=1;
bio(317).sigAddress='&Robot_leg_3_B.MathFunction_c';
bio(317).ndims=2;
bio(317).size=[];
bio(317).isStruct=false;

bio(318).blkName='Robot/Right Gait Motion/Right_Rotation_Motion/Sum';
bio(318).sigName='';
bio(318).portIdx=0;
bio(318).dim=[1,1];
bio(318).sigWidth=1;
bio(318).sigAddress='&Robot_leg_3_B.Sum_au';
bio(318).ndims=2;
bio(318).size=[];
bio(318).isStruct=false;

bio(319).blkName='Robot/Right Gait Pos/Right_Abduction_Motion/Clock';
bio(319).sigName='';
bio(319).portIdx=0;
bio(319).dim=[1,1];
bio(319).sigWidth=1;
bio(319).sigAddress='&Robot_leg_3_B.Clock_ic';
bio(319).ndims=2;
bio(319).size=[];
bio(319).isStruct=false;

bio(320).blkName='Robot/Right Gait Pos/Right_Abduction_Motion/Output';
bio(320).sigName='';
bio(320).portIdx=0;
bio(320).dim=[1,1];
bio(320).sigWidth=1;
bio(320).sigAddress='&Robot_leg_3_B.Output_go';
bio(320).ndims=2;
bio(320).size=[];
bio(320).isStruct=false;

bio(321).blkName='Robot/Right Gait Pos/Right_Abduction_Motion/Look-Up Table1';
bio(321).sigName='';
bio(321).portIdx=0;
bio(321).dim=[1,1];
bio(321).sigWidth=1;
bio(321).sigAddress='&Robot_leg_3_B.LookUpTable1_mg';
bio(321).ndims=2;
bio(321).size=[];
bio(321).isStruct=false;

bio(322).blkName='Robot/Right Gait Pos/Right_Abduction_Motion/Math Function';
bio(322).sigName='';
bio(322).portIdx=0;
bio(322).dim=[1,1];
bio(322).sigWidth=1;
bio(322).sigAddress='&Robot_leg_3_B.MathFunction_gx';
bio(322).ndims=2;
bio(322).size=[];
bio(322).isStruct=false;

bio(323).blkName='Robot/Right Gait Pos/Right_Abduction_Motion/Sum';
bio(323).sigName='';
bio(323).portIdx=0;
bio(323).dim=[1,1];
bio(323).sigWidth=1;
bio(323).sigAddress='&Robot_leg_3_B.Sum_p';
bio(323).ndims=2;
bio(323).size=[];
bio(323).isStruct=false;

bio(324).blkName='Robot/Right Gait Pos/Right_Ankle_Motion/Clock';
bio(324).sigName='';
bio(324).portIdx=0;
bio(324).dim=[1,1];
bio(324).sigWidth=1;
bio(324).sigAddress='&Robot_leg_3_B.Clock_ax';
bio(324).ndims=2;
bio(324).size=[];
bio(324).isStruct=false;

bio(325).blkName='Robot/Right Gait Pos/Right_Ankle_Motion/Output';
bio(325).sigName='';
bio(325).portIdx=0;
bio(325).dim=[1,1];
bio(325).sigWidth=1;
bio(325).sigAddress='&Robot_leg_3_B.Output_li';
bio(325).ndims=2;
bio(325).size=[];
bio(325).isStruct=false;

bio(326).blkName='Robot/Right Gait Pos/Right_Ankle_Motion/Look-Up Table1';
bio(326).sigName='';
bio(326).portIdx=0;
bio(326).dim=[1,1];
bio(326).sigWidth=1;
bio(326).sigAddress='&Robot_leg_3_B.LookUpTable1_gz';
bio(326).ndims=2;
bio(326).size=[];
bio(326).isStruct=false;

bio(327).blkName='Robot/Right Gait Pos/Right_Ankle_Motion/Math Function';
bio(327).sigName='';
bio(327).portIdx=0;
bio(327).dim=[1,1];
bio(327).sigWidth=1;
bio(327).sigAddress='&Robot_leg_3_B.MathFunction_d5';
bio(327).ndims=2;
bio(327).size=[];
bio(327).isStruct=false;

bio(328).blkName='Robot/Right Gait Pos/Right_Ankle_Motion/Sum';
bio(328).sigName='';
bio(328).portIdx=0;
bio(328).dim=[1,1];
bio(328).sigWidth=1;
bio(328).sigAddress='&Robot_leg_3_B.Sum_np';
bio(328).ndims=2;
bio(328).size=[];
bio(328).isStruct=false;

bio(329).blkName='Robot/Right Gait Pos/Right_Ankle_Twist_Motion/Clock';
bio(329).sigName='';
bio(329).portIdx=0;
bio(329).dim=[1,1];
bio(329).sigWidth=1;
bio(329).sigAddress='&Robot_leg_3_B.Clock_a';
bio(329).ndims=2;
bio(329).size=[];
bio(329).isStruct=false;

bio(330).blkName='Robot/Right Gait Pos/Right_Ankle_Twist_Motion/Output';
bio(330).sigName='';
bio(330).portIdx=0;
bio(330).dim=[1,1];
bio(330).sigWidth=1;
bio(330).sigAddress='&Robot_leg_3_B.Output_nv';
bio(330).ndims=2;
bio(330).size=[];
bio(330).isStruct=false;

bio(331).blkName='Robot/Right Gait Pos/Right_Ankle_Twist_Motion/Look-Up Table1';
bio(331).sigName='';
bio(331).portIdx=0;
bio(331).dim=[1,1];
bio(331).sigWidth=1;
bio(331).sigAddress='&Robot_leg_3_B.LookUpTable1_as';
bio(331).ndims=2;
bio(331).size=[];
bio(331).isStruct=false;

bio(332).blkName='Robot/Right Gait Pos/Right_Ankle_Twist_Motion/Math Function';
bio(332).sigName='';
bio(332).portIdx=0;
bio(332).dim=[1,1];
bio(332).sigWidth=1;
bio(332).sigAddress='&Robot_leg_3_B.MathFunction_ki';
bio(332).ndims=2;
bio(332).size=[];
bio(332).isStruct=false;

bio(333).blkName='Robot/Right Gait Pos/Right_Ankle_Twist_Motion/Sum';
bio(333).sigName='';
bio(333).portIdx=0;
bio(333).dim=[1,1];
bio(333).sigWidth=1;
bio(333).sigAddress='&Robot_leg_3_B.Sum_j';
bio(333).ndims=2;
bio(333).size=[];
bio(333).isStruct=false;

bio(334).blkName='Robot/Right Gait Pos/Right_Hip_Motion/Clock';
bio(334).sigName='';
bio(334).portIdx=0;
bio(334).dim=[1,1];
bio(334).sigWidth=1;
bio(334).sigAddress='&Robot_leg_3_B.Clock_fa';
bio(334).ndims=2;
bio(334).size=[];
bio(334).isStruct=false;

bio(335).blkName='Robot/Right Gait Pos/Right_Hip_Motion/Output';
bio(335).sigName='';
bio(335).portIdx=0;
bio(335).dim=[1,1];
bio(335).sigWidth=1;
bio(335).sigAddress='&Robot_leg_3_B.Output_bj';
bio(335).ndims=2;
bio(335).size=[];
bio(335).isStruct=false;

bio(336).blkName='Robot/Right Gait Pos/Right_Hip_Motion/Look-Up Table1';
bio(336).sigName='';
bio(336).portIdx=0;
bio(336).dim=[1,1];
bio(336).sigWidth=1;
bio(336).sigAddress='&Robot_leg_3_B.LookUpTable1_bq';
bio(336).ndims=2;
bio(336).size=[];
bio(336).isStruct=false;

bio(337).blkName='Robot/Right Gait Pos/Right_Hip_Motion/Math Function';
bio(337).sigName='';
bio(337).portIdx=0;
bio(337).dim=[1,1];
bio(337).sigWidth=1;
bio(337).sigAddress='&Robot_leg_3_B.MathFunction_ay';
bio(337).ndims=2;
bio(337).size=[];
bio(337).isStruct=false;

bio(338).blkName='Robot/Right Gait Pos/Right_Hip_Motion/Sum';
bio(338).sigName='';
bio(338).portIdx=0;
bio(338).dim=[1,1];
bio(338).sigWidth=1;
bio(338).sigAddress='&Robot_leg_3_B.Sum_kk';
bio(338).ndims=2;
bio(338).size=[];
bio(338).isStruct=false;

bio(339).blkName='Robot/Right Gait Pos/Right_Knee_Motion/Clock';
bio(339).sigName='';
bio(339).portIdx=0;
bio(339).dim=[1,1];
bio(339).sigWidth=1;
bio(339).sigAddress='&Robot_leg_3_B.Clock_li';
bio(339).ndims=2;
bio(339).size=[];
bio(339).isStruct=false;

bio(340).blkName='Robot/Right Gait Pos/Right_Knee_Motion/Output';
bio(340).sigName='';
bio(340).portIdx=0;
bio(340).dim=[1,1];
bio(340).sigWidth=1;
bio(340).sigAddress='&Robot_leg_3_B.Output_gs';
bio(340).ndims=2;
bio(340).size=[];
bio(340).isStruct=false;

bio(341).blkName='Robot/Right Gait Pos/Right_Knee_Motion/Look-Up Table1';
bio(341).sigName='';
bio(341).portIdx=0;
bio(341).dim=[1,1];
bio(341).sigWidth=1;
bio(341).sigAddress='&Robot_leg_3_B.LookUpTable1_c4';
bio(341).ndims=2;
bio(341).size=[];
bio(341).isStruct=false;

bio(342).blkName='Robot/Right Gait Pos/Right_Knee_Motion/Math Function';
bio(342).sigName='';
bio(342).portIdx=0;
bio(342).dim=[1,1];
bio(342).sigWidth=1;
bio(342).sigAddress='&Robot_leg_3_B.MathFunction_dz';
bio(342).ndims=2;
bio(342).size=[];
bio(342).isStruct=false;

bio(343).blkName='Robot/Right Gait Pos/Right_Knee_Motion/Sum';
bio(343).sigName='';
bio(343).portIdx=0;
bio(343).dim=[1,1];
bio(343).sigWidth=1;
bio(343).sigAddress='&Robot_leg_3_B.Sum_kv';
bio(343).ndims=2;
bio(343).size=[];
bio(343).isStruct=false;

bio(344).blkName='Robot/Right Gait Pos/Right_Rotation_Motion/Clock';
bio(344).sigName='';
bio(344).portIdx=0;
bio(344).dim=[1,1];
bio(344).sigWidth=1;
bio(344).sigAddress='&Robot_leg_3_B.Clock_jg';
bio(344).ndims=2;
bio(344).size=[];
bio(344).isStruct=false;

bio(345).blkName='Robot/Right Gait Pos/Right_Rotation_Motion/Output';
bio(345).sigName='';
bio(345).portIdx=0;
bio(345).dim=[1,1];
bio(345).sigWidth=1;
bio(345).sigAddress='&Robot_leg_3_B.Output_j';
bio(345).ndims=2;
bio(345).size=[];
bio(345).isStruct=false;

bio(346).blkName='Robot/Right Gait Pos/Right_Rotation_Motion/Look-Up Table1';
bio(346).sigName='';
bio(346).portIdx=0;
bio(346).dim=[1,1];
bio(346).sigWidth=1;
bio(346).sigAddress='&Robot_leg_3_B.LookUpTable1_e2';
bio(346).ndims=2;
bio(346).size=[];
bio(346).isStruct=false;

bio(347).blkName='Robot/Right Gait Pos/Right_Rotation_Motion/Math Function';
bio(347).sigName='';
bio(347).portIdx=0;
bio(347).dim=[1,1];
bio(347).sigWidth=1;
bio(347).sigAddress='&Robot_leg_3_B.MathFunction_es';
bio(347).ndims=2;
bio(347).size=[];
bio(347).isStruct=false;

bio(348).blkName='Robot/Right Gait Pos/Right_Rotation_Motion/Sum';
bio(348).sigName='';
bio(348).portIdx=0;
bio(348).dim=[1,1];
bio(348).sigWidth=1;
bio(348).sigAddress='&Robot_leg_3_B.Sum_mw';
bio(348).ndims=2;
bio(348).size=[];
bio(348).isStruct=false;

bio(349).blkName='Robot/Right Still/Right_Abduction_Motion/Clock';
bio(349).sigName='';
bio(349).portIdx=0;
bio(349).dim=[1,1];
bio(349).sigWidth=1;
bio(349).sigAddress='&Robot_leg_3_B.Clock_im';
bio(349).ndims=2;
bio(349).size=[];
bio(349).isStruct=false;

bio(350).blkName='Robot/Right Still/Right_Abduction_Motion/Output';
bio(350).sigName='';
bio(350).portIdx=0;
bio(350).dim=[1,1];
bio(350).sigWidth=1;
bio(350).sigAddress='&Robot_leg_3_B.Output_dc';
bio(350).ndims=2;
bio(350).size=[];
bio(350).isStruct=false;

bio(351).blkName='Robot/Right Still/Right_Abduction_Motion/Look-Up Table1';
bio(351).sigName='';
bio(351).portIdx=0;
bio(351).dim=[1,1];
bio(351).sigWidth=1;
bio(351).sigAddress='&Robot_leg_3_B.LookUpTable1_gn';
bio(351).ndims=2;
bio(351).size=[];
bio(351).isStruct=false;

bio(352).blkName='Robot/Right Still/Right_Abduction_Motion/Math Function';
bio(352).sigName='';
bio(352).portIdx=0;
bio(352).dim=[1,1];
bio(352).sigWidth=1;
bio(352).sigAddress='&Robot_leg_3_B.MathFunction_hz';
bio(352).ndims=2;
bio(352).size=[];
bio(352).isStruct=false;

bio(353).blkName='Robot/Right Still/Right_Abduction_Motion/Sum';
bio(353).sigName='';
bio(353).portIdx=0;
bio(353).dim=[1,1];
bio(353).sigWidth=1;
bio(353).sigAddress='&Robot_leg_3_B.Sum_is';
bio(353).ndims=2;
bio(353).size=[];
bio(353).isStruct=false;

bio(354).blkName='Robot/Right Still/Right_Ankle_Motion/Clock';
bio(354).sigName='';
bio(354).portIdx=0;
bio(354).dim=[1,1];
bio(354).sigWidth=1;
bio(354).sigAddress='&Robot_leg_3_B.Clock_ln';
bio(354).ndims=2;
bio(354).size=[];
bio(354).isStruct=false;

bio(355).blkName='Robot/Right Still/Right_Ankle_Motion/Output';
bio(355).sigName='';
bio(355).portIdx=0;
bio(355).dim=[1,1];
bio(355).sigWidth=1;
bio(355).sigAddress='&Robot_leg_3_B.Output_np';
bio(355).ndims=2;
bio(355).size=[];
bio(355).isStruct=false;

bio(356).blkName='Robot/Right Still/Right_Ankle_Motion/Look-Up Table1';
bio(356).sigName='';
bio(356).portIdx=0;
bio(356).dim=[1,1];
bio(356).sigWidth=1;
bio(356).sigAddress='&Robot_leg_3_B.LookUpTable1_an';
bio(356).ndims=2;
bio(356).size=[];
bio(356).isStruct=false;

bio(357).blkName='Robot/Right Still/Right_Ankle_Motion/Math Function';
bio(357).sigName='';
bio(357).portIdx=0;
bio(357).dim=[1,1];
bio(357).sigWidth=1;
bio(357).sigAddress='&Robot_leg_3_B.MathFunction_ko';
bio(357).ndims=2;
bio(357).size=[];
bio(357).isStruct=false;

bio(358).blkName='Robot/Right Still/Right_Ankle_Motion/Sum';
bio(358).sigName='';
bio(358).portIdx=0;
bio(358).dim=[1,1];
bio(358).sigWidth=1;
bio(358).sigAddress='&Robot_leg_3_B.Sum_pl';
bio(358).ndims=2;
bio(358).size=[];
bio(358).isStruct=false;

bio(359).blkName='Robot/Right Still/Right_Ankle_Twist_Motion/Clock';
bio(359).sigName='';
bio(359).portIdx=0;
bio(359).dim=[1,1];
bio(359).sigWidth=1;
bio(359).sigAddress='&Robot_leg_3_B.Clock_oq';
bio(359).ndims=2;
bio(359).size=[];
bio(359).isStruct=false;

bio(360).blkName='Robot/Right Still/Right_Ankle_Twist_Motion/Output';
bio(360).sigName='';
bio(360).portIdx=0;
bio(360).dim=[1,1];
bio(360).sigWidth=1;
bio(360).sigAddress='&Robot_leg_3_B.Output_d';
bio(360).ndims=2;
bio(360).size=[];
bio(360).isStruct=false;

bio(361).blkName='Robot/Right Still/Right_Ankle_Twist_Motion/Look-Up Table1';
bio(361).sigName='';
bio(361).portIdx=0;
bio(361).dim=[1,1];
bio(361).sigWidth=1;
bio(361).sigAddress='&Robot_leg_3_B.LookUpTable1_en';
bio(361).ndims=2;
bio(361).size=[];
bio(361).isStruct=false;

bio(362).blkName='Robot/Right Still/Right_Ankle_Twist_Motion/Math Function';
bio(362).sigName='';
bio(362).portIdx=0;
bio(362).dim=[1,1];
bio(362).sigWidth=1;
bio(362).sigAddress='&Robot_leg_3_B.MathFunction_gp';
bio(362).ndims=2;
bio(362).size=[];
bio(362).isStruct=false;

bio(363).blkName='Robot/Right Still/Right_Ankle_Twist_Motion/Sum';
bio(363).sigName='';
bio(363).portIdx=0;
bio(363).dim=[1,1];
bio(363).sigWidth=1;
bio(363).sigAddress='&Robot_leg_3_B.Sum_h';
bio(363).ndims=2;
bio(363).size=[];
bio(363).isStruct=false;

bio(364).blkName='Robot/Right Still/Right_Hip_Motion/Clock';
bio(364).sigName='';
bio(364).portIdx=0;
bio(364).dim=[1,1];
bio(364).sigWidth=1;
bio(364).sigAddress='&Robot_leg_3_B.Clock_ju';
bio(364).ndims=2;
bio(364).size=[];
bio(364).isStruct=false;

bio(365).blkName='Robot/Right Still/Right_Hip_Motion/Output';
bio(365).sigName='';
bio(365).portIdx=0;
bio(365).dim=[1,1];
bio(365).sigWidth=1;
bio(365).sigAddress='&Robot_leg_3_B.Output_hg';
bio(365).ndims=2;
bio(365).size=[];
bio(365).isStruct=false;

bio(366).blkName='Robot/Right Still/Right_Hip_Motion/Look-Up Table1';
bio(366).sigName='';
bio(366).portIdx=0;
bio(366).dim=[1,1];
bio(366).sigWidth=1;
bio(366).sigAddress='&Robot_leg_3_B.LookUpTable1_nq';
bio(366).ndims=2;
bio(366).size=[];
bio(366).isStruct=false;

bio(367).blkName='Robot/Right Still/Right_Hip_Motion/Math Function';
bio(367).sigName='';
bio(367).portIdx=0;
bio(367).dim=[1,1];
bio(367).sigWidth=1;
bio(367).sigAddress='&Robot_leg_3_B.MathFunction_h1';
bio(367).ndims=2;
bio(367).size=[];
bio(367).isStruct=false;

bio(368).blkName='Robot/Right Still/Right_Hip_Motion/Sum';
bio(368).sigName='';
bio(368).portIdx=0;
bio(368).dim=[1,1];
bio(368).sigWidth=1;
bio(368).sigAddress='&Robot_leg_3_B.Sum_ks';
bio(368).ndims=2;
bio(368).size=[];
bio(368).isStruct=false;

bio(369).blkName='Robot/Right Still/Right_Knee_Motion/Clock';
bio(369).sigName='';
bio(369).portIdx=0;
bio(369).dim=[1,1];
bio(369).sigWidth=1;
bio(369).sigAddress='&Robot_leg_3_B.Clock_c4';
bio(369).ndims=2;
bio(369).size=[];
bio(369).isStruct=false;

bio(370).blkName='Robot/Right Still/Right_Knee_Motion/Output';
bio(370).sigName='';
bio(370).portIdx=0;
bio(370).dim=[1,1];
bio(370).sigWidth=1;
bio(370).sigAddress='&Robot_leg_3_B.Output_m0';
bio(370).ndims=2;
bio(370).size=[];
bio(370).isStruct=false;

bio(371).blkName='Robot/Right Still/Right_Knee_Motion/Look-Up Table1';
bio(371).sigName='';
bio(371).portIdx=0;
bio(371).dim=[1,1];
bio(371).sigWidth=1;
bio(371).sigAddress='&Robot_leg_3_B.LookUpTable1_el';
bio(371).ndims=2;
bio(371).size=[];
bio(371).isStruct=false;

bio(372).blkName='Robot/Right Still/Right_Knee_Motion/Math Function';
bio(372).sigName='';
bio(372).portIdx=0;
bio(372).dim=[1,1];
bio(372).sigWidth=1;
bio(372).sigAddress='&Robot_leg_3_B.MathFunction_bb';
bio(372).ndims=2;
bio(372).size=[];
bio(372).isStruct=false;

bio(373).blkName='Robot/Right Still/Right_Knee_Motion/Sum';
bio(373).sigName='';
bio(373).portIdx=0;
bio(373).dim=[1,1];
bio(373).sigWidth=1;
bio(373).sigAddress='&Robot_leg_3_B.Sum_du';
bio(373).ndims=2;
bio(373).size=[];
bio(373).isStruct=false;

bio(374).blkName='Robot/Right Still/Right_Rotation_Motion/Clock';
bio(374).sigName='';
bio(374).portIdx=0;
bio(374).dim=[1,1];
bio(374).sigWidth=1;
bio(374).sigAddress='&Robot_leg_3_B.Clock_e';
bio(374).ndims=2;
bio(374).size=[];
bio(374).isStruct=false;

bio(375).blkName='Robot/Right Still/Right_Rotation_Motion/Output';
bio(375).sigName='';
bio(375).portIdx=0;
bio(375).dim=[1,1];
bio(375).sigWidth=1;
bio(375).sigAddress='&Robot_leg_3_B.Output_gb';
bio(375).ndims=2;
bio(375).size=[];
bio(375).isStruct=false;

bio(376).blkName='Robot/Right Still/Right_Rotation_Motion/Look-Up Table1';
bio(376).sigName='';
bio(376).portIdx=0;
bio(376).dim=[1,1];
bio(376).sigWidth=1;
bio(376).sigAddress='&Robot_leg_3_B.LookUpTable1_cv';
bio(376).ndims=2;
bio(376).size=[];
bio(376).isStruct=false;

bio(377).blkName='Robot/Right Still/Right_Rotation_Motion/Math Function';
bio(377).sigName='';
bio(377).portIdx=0;
bio(377).dim=[1,1];
bio(377).sigWidth=1;
bio(377).sigAddress='&Robot_leg_3_B.MathFunction_g2';
bio(377).ndims=2;
bio(377).size=[];
bio(377).isStruct=false;

bio(378).blkName='Robot/Right Still/Right_Rotation_Motion/Sum';
bio(378).sigName='';
bio(378).portIdx=0;
bio(378).dim=[1,1];
bio(378).sigWidth=1;
bio(378).sigAddress='&Robot_leg_3_B.Sum_ed';
bio(378).ndims=2;
bio(378).size=[];
bio(378).isStruct=false;

bio(379).blkName='Robot/Right_leg/Contact Force Logging/Math Function';
bio(379).sigName='';
bio(379).portIdx=0;
bio(379).dim=[3,1];
bio(379).sigWidth=3;
bio(379).sigAddress='&Robot_leg_3_B.MathFunction_g0[0]';
bio(379).ndims=2;
bio(379).size=[];
bio(379).isStruct=false;

bio(380).blkName='Robot/Right_leg/Contact Force Logging/Add';
bio(380).sigName='Normal Force';
bio(380).portIdx=0;
bio(380).dim=[1,1];
bio(380).sigWidth=1;
bio(380).sigAddress='&Robot_leg_3_B.NormalForce';
bio(380).ndims=2;
bio(380).size=[];
bio(380).isStruct=false;

bio(381).blkName='Robot/Right_leg/Contact Force Logging/Add1';
bio(381).sigName='';
bio(381).portIdx=0;
bio(381).dim=[3,1];
bio(381).sigWidth=3;
bio(381).sigAddress='&Robot_leg_3_B.Add1[0]';
bio(381).ndims=2;
bio(381).size=[];
bio(381).isStruct=false;

bio(382).blkName='Robot/Right_leg/Contact Force Logging/Sum of Elements';
bio(382).sigName='';
bio(382).portIdx=0;
bio(382).dim=[1,1];
bio(382).sigWidth=1;
bio(382).sigAddress='&Robot_leg_3_B.SumofElements';
bio(382).ndims=2;
bio(382).size=[];
bio(382).isStruct=false;

bio(383).blkName='Robot/Right_leg/Contact Force Logging/Sqrt';
bio(383).sigName='Friction Force';
bio(383).portIdx=0;
bio(383).dim=[1,1];
bio(383).sigWidth=1;
bio(383).sigAddress='&Robot_leg_3_B.FrictionForce';
bio(383).ndims=2;
bio(383).size=[];
bio(383).isStruct=false;

bio(384).blkName='Robot/Right_leg/Sphere to Plane Force/Merge';
bio(384).sigName='FSph';
bio(384).portIdx=0;
bio(384).dim=[12,1];
bio(384).sigWidth=12;
bio(384).sigAddress='&Robot_leg_3_B.FSph_i[0]';
bio(384).ndims=2;
bio(384).size=[];
bio(384).isStruct=false;

bio(385).blkName='Robot/Right_leg/Sphere to Plane Force1/Merge';
bio(385).sigName='FSph';
bio(385).portIdx=0;
bio(385).dim=[12,1];
bio(385).sigWidth=12;
bio(385).sigAddress='&Robot_leg_3_B.FSph_mf[0]';
bio(385).ndims=2;
bio(385).size=[];
bio(385).isStruct=false;

bio(386).blkName='Robot/Right_leg/Sphere to Plane Force2/Merge';
bio(386).sigName='FSph';
bio(386).portIdx=0;
bio(386).dim=[12,1];
bio(386).sigWidth=12;
bio(386).sigAddress='&Robot_leg_3_B.FSph_a0[0]';
bio(386).ndims=2;
bio(386).size=[];
bio(386).isStruct=false;

bio(387).blkName='Robot/Right_leg/Sphere to Plane Force3/Merge';
bio(387).sigName='FSph';
bio(387).portIdx=0;
bio(387).dim=[12,1];
bio(387).sigWidth=12;
bio(387).sigAddress='&Robot_leg_3_B.FSph_n[0]';
bio(387).ndims=2;
bio(387).size=[];
bio(387).isStruct=false;

bio(388).blkName='Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Abs';
bio(388).sigName='';
bio(388).portIdx=0;
bio(388).dim=[1,1];
bio(388).sigWidth=1;
bio(388).sigAddress='&Robot_leg_3_B.Abs_f';
bio(388).ndims=2;
bio(388).size=[];
bio(388).isStruct=false;

bio(389).blkName='Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Abs1';
bio(389).sigName='';
bio(389).portIdx=0;
bio(389).dim=[1,1];
bio(389).sigWidth=1;
bio(389).sigAddress='&Robot_leg_3_B.Abs1_k';
bio(389).ndims=2;
bio(389).size=[];
bio(389).isStruct=false;

bio(390).blkName='Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Data Type Conversion';
bio(390).sigName='';
bio(390).portIdx=0;
bio(390).dim=[1,1];
bio(390).sigWidth=1;
bio(390).sigAddress='&Robot_leg_3_B.DataTypeConversion_a';
bio(390).ndims=2;
bio(390).size=[];
bio(390).isStruct=false;

bio(391).blkName='Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Gain';
bio(391).sigName='';
bio(391).portIdx=0;
bio(391).dim=[1,1];
bio(391).sigWidth=1;
bio(391).sigAddress='&Robot_leg_3_B.Gain_p1';
bio(391).ndims=2;
bio(391).size=[];
bio(391).isStruct=false;

bio(392).blkName='Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Gain1';
bio(392).sigName='';
bio(392).portIdx=0;
bio(392).dim=[1,1];
bio(392).sigWidth=1;
bio(392).sigAddress='&Robot_leg_3_B.Gain1_b';
bio(392).ndims=2;
bio(392).size=[];
bio(392).isStruct=false;

bio(393).blkName='Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Logical Operator';
bio(393).sigName='';
bio(393).portIdx=0;
bio(393).dim=[1,1];
bio(393).sigWidth=1;
bio(393).sigAddress='&Robot_leg_3_B.LogicalOperator_n';
bio(393).ndims=2;
bio(393).size=[];
bio(393).isStruct=false;

bio(394).blkName='Robot/Left_leg/Sphere to Plane Force/Enable Outputs/Product';
bio(394).sigName='';
bio(394).portIdx=0;
bio(394).dim=[8,1];
bio(394).sigWidth=8;
bio(394).sigAddress='&Robot_leg_3_B.Product_d[0]';
bio(394).ndims=2;
bio(394).size=[];
bio(394).isStruct=false;

bio(395).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Copy for Merge';
bio(395).sigName='';
bio(395).portIdx=0;
bio(395).dim=[12,1];
bio(395).sigWidth=12;
bio(395).sigAddress='&Robot_leg_3_B.FSph[0]';
bio(395).ndims=2;
bio(395).size=[];
bio(395).isStruct=false;

bio(396).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Product';
bio(396).sigName='Spr Force';
bio(396).portIdx=0;
bio(396).dim=[1,1];
bio(396).sigWidth=1;
bio(396).sigAddress='&Robot_leg_3_B.SprForce_ny';
bio(396).ndims=2;
bio(396).size=[];
bio(396).isStruct=false;

bio(397).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Product1';
bio(397).sigName='Damp Force';
bio(397).portIdx=0;
bio(397).dim=[1,1];
bio(397).sigWidth=1;
bio(397).sigAddress='&Robot_leg_3_B.DampForce_b';
bio(397).ndims=2;
bio(397).size=[];
bio(397).isStruct=false;

bio(398).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Sum';
bio(398).sigName='FSph';
bio(398).portIdx=0;
bio(398).dim=[12,1];
bio(398).sigWidth=12;
bio(398).sigAddress='&Robot_leg_3_B.FSph[0]';
bio(398).ndims=2;
bio(398).size=[];
bio(398).isStruct=false;

bio(399).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Sum1';
bio(399).sigName='FPla';
bio(399).portIdx=0;
bio(399).dim=[3,1];
bio(399).sigWidth=3;
bio(399).sigAddress='&Robot_leg_3_B.FPla_j[0]';
bio(399).ndims=2;
bio(399).size=[];
bio(399).isStruct=false;

bio(400).blkName='Robot/Left_leg/Sphere to Plane Force/No Force/Zeros';
bio(400).sigName='';
bio(400).portIdx=0;
bio(400).dim=[12,1];
bio(400).sigWidth=12;
bio(400).sigAddress='&Robot_leg_3_B.FSph[0]';
bio(400).ndims=2;
bio(400).size=[];
bio(400).isStruct=false;

bio(401).blkName='Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Abs';
bio(401).sigName='';
bio(401).portIdx=0;
bio(401).dim=[1,1];
bio(401).sigWidth=1;
bio(401).sigAddress='&Robot_leg_3_B.Abs_k';
bio(401).ndims=2;
bio(401).size=[];
bio(401).isStruct=false;

bio(402).blkName='Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Abs1';
bio(402).sigName='';
bio(402).portIdx=0;
bio(402).dim=[1,1];
bio(402).sigWidth=1;
bio(402).sigAddress='&Robot_leg_3_B.Abs1_o2';
bio(402).ndims=2;
bio(402).size=[];
bio(402).isStruct=false;

bio(403).blkName='Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Data Type Conversion';
bio(403).sigName='';
bio(403).portIdx=0;
bio(403).dim=[1,1];
bio(403).sigWidth=1;
bio(403).sigAddress='&Robot_leg_3_B.DataTypeConversion_p';
bio(403).ndims=2;
bio(403).size=[];
bio(403).isStruct=false;

bio(404).blkName='Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Gain';
bio(404).sigName='';
bio(404).portIdx=0;
bio(404).dim=[1,1];
bio(404).sigWidth=1;
bio(404).sigAddress='&Robot_leg_3_B.Gain_m';
bio(404).ndims=2;
bio(404).size=[];
bio(404).isStruct=false;

bio(405).blkName='Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Gain1';
bio(405).sigName='';
bio(405).portIdx=0;
bio(405).dim=[1,1];
bio(405).sigWidth=1;
bio(405).sigAddress='&Robot_leg_3_B.Gain1_n';
bio(405).ndims=2;
bio(405).size=[];
bio(405).isStruct=false;

bio(406).blkName='Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Logical Operator';
bio(406).sigName='';
bio(406).portIdx=0;
bio(406).dim=[1,1];
bio(406).sigWidth=1;
bio(406).sigAddress='&Robot_leg_3_B.LogicalOperator_k';
bio(406).ndims=2;
bio(406).size=[];
bio(406).isStruct=false;

bio(407).blkName='Robot/Left_leg/Sphere to Plane Force1/Enable Outputs/Product';
bio(407).sigName='';
bio(407).portIdx=0;
bio(407).dim=[8,1];
bio(407).sigWidth=8;
bio(407).sigAddress='&Robot_leg_3_B.Product_m[0]';
bio(407).ndims=2;
bio(407).size=[];
bio(407).isStruct=false;

bio(408).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Copy for Merge';
bio(408).sigName='';
bio(408).portIdx=0;
bio(408).dim=[12,1];
bio(408).sigWidth=12;
bio(408).sigAddress='&Robot_leg_3_B.FSph_m[0]';
bio(408).ndims=2;
bio(408).size=[];
bio(408).isStruct=false;

bio(409).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Product';
bio(409).sigName='Spr Force';
bio(409).portIdx=0;
bio(409).dim=[1,1];
bio(409).sigWidth=1;
bio(409).sigAddress='&Robot_leg_3_B.SprForce_a';
bio(409).ndims=2;
bio(409).size=[];
bio(409).isStruct=false;

bio(410).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Product1';
bio(410).sigName='Damp Force';
bio(410).portIdx=0;
bio(410).dim=[1,1];
bio(410).sigWidth=1;
bio(410).sigAddress='&Robot_leg_3_B.DampForce_hs';
bio(410).ndims=2;
bio(410).size=[];
bio(410).isStruct=false;

bio(411).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Sum';
bio(411).sigName='FSph';
bio(411).portIdx=0;
bio(411).dim=[12,1];
bio(411).sigWidth=12;
bio(411).sigAddress='&Robot_leg_3_B.FSph_m[0]';
bio(411).ndims=2;
bio(411).size=[];
bio(411).isStruct=false;

bio(412).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Sum1';
bio(412).sigName='FPla';
bio(412).portIdx=0;
bio(412).dim=[3,1];
bio(412).sigWidth=3;
bio(412).sigAddress='&Robot_leg_3_B.FPla_p[0]';
bio(412).ndims=2;
bio(412).size=[];
bio(412).isStruct=false;

bio(413).blkName='Robot/Left_leg/Sphere to Plane Force1/No Force/Zeros';
bio(413).sigName='';
bio(413).portIdx=0;
bio(413).dim=[12,1];
bio(413).sigWidth=12;
bio(413).sigAddress='&Robot_leg_3_B.FSph_m[0]';
bio(413).ndims=2;
bio(413).size=[];
bio(413).isStruct=false;

bio(414).blkName='Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Abs';
bio(414).sigName='';
bio(414).portIdx=0;
bio(414).dim=[1,1];
bio(414).sigWidth=1;
bio(414).sigAddress='&Robot_leg_3_B.Abs_n';
bio(414).ndims=2;
bio(414).size=[];
bio(414).isStruct=false;

bio(415).blkName='Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Abs1';
bio(415).sigName='';
bio(415).portIdx=0;
bio(415).dim=[1,1];
bio(415).sigWidth=1;
bio(415).sigAddress='&Robot_leg_3_B.Abs1_n';
bio(415).ndims=2;
bio(415).size=[];
bio(415).isStruct=false;

bio(416).blkName='Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Data Type Conversion';
bio(416).sigName='';
bio(416).portIdx=0;
bio(416).dim=[1,1];
bio(416).sigWidth=1;
bio(416).sigAddress='&Robot_leg_3_B.DataTypeConversion_b';
bio(416).ndims=2;
bio(416).size=[];
bio(416).isStruct=false;

bio(417).blkName='Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Gain';
bio(417).sigName='';
bio(417).portIdx=0;
bio(417).dim=[1,1];
bio(417).sigWidth=1;
bio(417).sigAddress='&Robot_leg_3_B.Gain_g';
bio(417).ndims=2;
bio(417).size=[];
bio(417).isStruct=false;

bio(418).blkName='Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Gain1';
bio(418).sigName='';
bio(418).portIdx=0;
bio(418).dim=[1,1];
bio(418).sigWidth=1;
bio(418).sigAddress='&Robot_leg_3_B.Gain1_gi';
bio(418).ndims=2;
bio(418).size=[];
bio(418).isStruct=false;

bio(419).blkName='Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Logical Operator';
bio(419).sigName='';
bio(419).portIdx=0;
bio(419).dim=[1,1];
bio(419).sigWidth=1;
bio(419).sigAddress='&Robot_leg_3_B.LogicalOperator_aj';
bio(419).ndims=2;
bio(419).size=[];
bio(419).isStruct=false;

bio(420).blkName='Robot/Left_leg/Sphere to Plane Force2/Enable Outputs/Product';
bio(420).sigName='';
bio(420).portIdx=0;
bio(420).dim=[8,1];
bio(420).sigWidth=8;
bio(420).sigAddress='&Robot_leg_3_B.Product_e[0]';
bio(420).ndims=2;
bio(420).size=[];
bio(420).isStruct=false;

bio(421).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Copy for Merge';
bio(421).sigName='';
bio(421).portIdx=0;
bio(421).dim=[12,1];
bio(421).sigWidth=12;
bio(421).sigAddress='&Robot_leg_3_B.FSph_l[0]';
bio(421).ndims=2;
bio(421).size=[];
bio(421).isStruct=false;

bio(422).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Product';
bio(422).sigName='Spr Force';
bio(422).portIdx=0;
bio(422).dim=[1,1];
bio(422).sigWidth=1;
bio(422).sigAddress='&Robot_leg_3_B.SprForce_e';
bio(422).ndims=2;
bio(422).size=[];
bio(422).isStruct=false;

bio(423).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Product1';
bio(423).sigName='Damp Force';
bio(423).portIdx=0;
bio(423).dim=[1,1];
bio(423).sigWidth=1;
bio(423).sigAddress='&Robot_leg_3_B.DampForce_f';
bio(423).ndims=2;
bio(423).size=[];
bio(423).isStruct=false;

bio(424).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Sum';
bio(424).sigName='FSph';
bio(424).portIdx=0;
bio(424).dim=[12,1];
bio(424).sigWidth=12;
bio(424).sigAddress='&Robot_leg_3_B.FSph_l[0]';
bio(424).ndims=2;
bio(424).size=[];
bio(424).isStruct=false;

bio(425).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Sum1';
bio(425).sigName='FPla';
bio(425).portIdx=0;
bio(425).dim=[3,1];
bio(425).sigWidth=3;
bio(425).sigAddress='&Robot_leg_3_B.FPla_n[0]';
bio(425).ndims=2;
bio(425).size=[];
bio(425).isStruct=false;

bio(426).blkName='Robot/Left_leg/Sphere to Plane Force2/No Force/Zeros';
bio(426).sigName='';
bio(426).portIdx=0;
bio(426).dim=[12,1];
bio(426).sigWidth=12;
bio(426).sigAddress='&Robot_leg_3_B.FSph_l[0]';
bio(426).ndims=2;
bio(426).size=[];
bio(426).isStruct=false;

bio(427).blkName='Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Abs';
bio(427).sigName='';
bio(427).portIdx=0;
bio(427).dim=[1,1];
bio(427).sigWidth=1;
bio(427).sigAddress='&Robot_leg_3_B.Abs_ff';
bio(427).ndims=2;
bio(427).size=[];
bio(427).isStruct=false;

bio(428).blkName='Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Abs1';
bio(428).sigName='';
bio(428).portIdx=0;
bio(428).dim=[1,1];
bio(428).sigWidth=1;
bio(428).sigAddress='&Robot_leg_3_B.Abs1_b';
bio(428).ndims=2;
bio(428).size=[];
bio(428).isStruct=false;

bio(429).blkName='Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Data Type Conversion';
bio(429).sigName='';
bio(429).portIdx=0;
bio(429).dim=[1,1];
bio(429).sigWidth=1;
bio(429).sigAddress='&Robot_leg_3_B.DataTypeConversion_bu';
bio(429).ndims=2;
bio(429).size=[];
bio(429).isStruct=false;

bio(430).blkName='Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Gain';
bio(430).sigName='';
bio(430).portIdx=0;
bio(430).dim=[1,1];
bio(430).sigWidth=1;
bio(430).sigAddress='&Robot_leg_3_B.Gain_m5';
bio(430).ndims=2;
bio(430).size=[];
bio(430).isStruct=false;

bio(431).blkName='Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Gain1';
bio(431).sigName='';
bio(431).portIdx=0;
bio(431).dim=[1,1];
bio(431).sigWidth=1;
bio(431).sigAddress='&Robot_leg_3_B.Gain1_c';
bio(431).ndims=2;
bio(431).size=[];
bio(431).isStruct=false;

bio(432).blkName='Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Logical Operator';
bio(432).sigName='';
bio(432).portIdx=0;
bio(432).dim=[1,1];
bio(432).sigWidth=1;
bio(432).sigAddress='&Robot_leg_3_B.LogicalOperator_nt';
bio(432).ndims=2;
bio(432).size=[];
bio(432).isStruct=false;

bio(433).blkName='Robot/Left_leg/Sphere to Plane Force3/Enable Outputs/Product';
bio(433).sigName='';
bio(433).portIdx=0;
bio(433).dim=[8,1];
bio(433).sigWidth=8;
bio(433).sigAddress='&Robot_leg_3_B.Product_j[0]';
bio(433).ndims=2;
bio(433).size=[];
bio(433).isStruct=false;

bio(434).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Copy for Merge';
bio(434).sigName='';
bio(434).portIdx=0;
bio(434).dim=[12,1];
bio(434).sigWidth=12;
bio(434).sigAddress='&Robot_leg_3_B.FSph_a[0]';
bio(434).ndims=2;
bio(434).size=[];
bio(434).isStruct=false;

bio(435).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Product';
bio(435).sigName='Spr Force';
bio(435).portIdx=0;
bio(435).dim=[1,1];
bio(435).sigWidth=1;
bio(435).sigAddress='&Robot_leg_3_B.SprForce_m';
bio(435).ndims=2;
bio(435).size=[];
bio(435).isStruct=false;

bio(436).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Product1';
bio(436).sigName='Damp Force';
bio(436).portIdx=0;
bio(436).dim=[1,1];
bio(436).sigWidth=1;
bio(436).sigAddress='&Robot_leg_3_B.DampForce_n';
bio(436).ndims=2;
bio(436).size=[];
bio(436).isStruct=false;

bio(437).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Sum';
bio(437).sigName='FSph';
bio(437).portIdx=0;
bio(437).dim=[12,1];
bio(437).sigWidth=12;
bio(437).sigAddress='&Robot_leg_3_B.FSph_a[0]';
bio(437).ndims=2;
bio(437).size=[];
bio(437).isStruct=false;

bio(438).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Sum1';
bio(438).sigName='FPla';
bio(438).portIdx=0;
bio(438).dim=[3,1];
bio(438).sigWidth=3;
bio(438).sigAddress='&Robot_leg_3_B.FPla_d[0]';
bio(438).ndims=2;
bio(438).size=[];
bio(438).isStruct=false;

bio(439).blkName='Robot/Left_leg/Sphere to Plane Force3/No Force/Zeros';
bio(439).sigName='';
bio(439).portIdx=0;
bio(439).dim=[12,1];
bio(439).sigWidth=12;
bio(439).sigAddress='&Robot_leg_3_B.FSph_a[0]';
bio(439).ndims=2;
bio(439).size=[];
bio(439).isStruct=false;

bio(440).blkName='Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Abs';
bio(440).sigName='';
bio(440).portIdx=0;
bio(440).dim=[1,1];
bio(440).sigWidth=1;
bio(440).sigAddress='&Robot_leg_3_B.Abs';
bio(440).ndims=2;
bio(440).size=[];
bio(440).isStruct=false;

bio(441).blkName='Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Abs1';
bio(441).sigName='';
bio(441).portIdx=0;
bio(441).dim=[1,1];
bio(441).sigWidth=1;
bio(441).sigAddress='&Robot_leg_3_B.Abs1';
bio(441).ndims=2;
bio(441).size=[];
bio(441).isStruct=false;

bio(442).blkName='Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Data Type Conversion';
bio(442).sigName='';
bio(442).portIdx=0;
bio(442).dim=[1,1];
bio(442).sigWidth=1;
bio(442).sigAddress='&Robot_leg_3_B.DataTypeConversion';
bio(442).ndims=2;
bio(442).size=[];
bio(442).isStruct=false;

bio(443).blkName='Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Gain';
bio(443).sigName='';
bio(443).portIdx=0;
bio(443).dim=[1,1];
bio(443).sigWidth=1;
bio(443).sigAddress='&Robot_leg_3_B.Gain';
bio(443).ndims=2;
bio(443).size=[];
bio(443).isStruct=false;

bio(444).blkName='Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Gain1';
bio(444).sigName='';
bio(444).portIdx=0;
bio(444).dim=[1,1];
bio(444).sigWidth=1;
bio(444).sigAddress='&Robot_leg_3_B.Gain1';
bio(444).ndims=2;
bio(444).size=[];
bio(444).isStruct=false;

bio(445).blkName='Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Logical Operator';
bio(445).sigName='';
bio(445).portIdx=0;
bio(445).dim=[1,1];
bio(445).sigWidth=1;
bio(445).sigAddress='&Robot_leg_3_B.LogicalOperator';
bio(445).ndims=2;
bio(445).size=[];
bio(445).isStruct=false;

bio(446).blkName='Robot/Right_leg/Sphere to Plane Force/Enable Outputs/Product';
bio(446).sigName='';
bio(446).portIdx=0;
bio(446).dim=[8,1];
bio(446).sigWidth=8;
bio(446).sigAddress='&Robot_leg_3_B.Product[0]';
bio(446).ndims=2;
bio(446).size=[];
bio(446).isStruct=false;

bio(447).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Copy for Merge';
bio(447).sigName='';
bio(447).portIdx=0;
bio(447).dim=[12,1];
bio(447).sigWidth=12;
bio(447).sigAddress='&Robot_leg_3_B.FSph_i[0]';
bio(447).ndims=2;
bio(447).size=[];
bio(447).isStruct=false;

bio(448).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Product';
bio(448).sigName='Spr Force';
bio(448).portIdx=0;
bio(448).dim=[1,1];
bio(448).sigWidth=1;
bio(448).sigAddress='&Robot_leg_3_B.SprForce_p';
bio(448).ndims=2;
bio(448).size=[];
bio(448).isStruct=false;

bio(449).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Product1';
bio(449).sigName='Damp Force';
bio(449).portIdx=0;
bio(449).dim=[1,1];
bio(449).sigWidth=1;
bio(449).sigAddress='&Robot_leg_3_B.DampForce_h';
bio(449).ndims=2;
bio(449).size=[];
bio(449).isStruct=false;

bio(450).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Sum';
bio(450).sigName='FSph';
bio(450).portIdx=0;
bio(450).dim=[12,1];
bio(450).sigWidth=12;
bio(450).sigAddress='&Robot_leg_3_B.FSph_i[0]';
bio(450).ndims=2;
bio(450).size=[];
bio(450).isStruct=false;

bio(451).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Sum1';
bio(451).sigName='FPla';
bio(451).portIdx=0;
bio(451).dim=[3,1];
bio(451).sigWidth=3;
bio(451).sigAddress='&Robot_leg_3_B.FPla_h[0]';
bio(451).ndims=2;
bio(451).size=[];
bio(451).isStruct=false;

bio(452).blkName='Robot/Right_leg/Sphere to Plane Force/No Force/Zeros';
bio(452).sigName='';
bio(452).portIdx=0;
bio(452).dim=[12,1];
bio(452).sigWidth=12;
bio(452).sigAddress='&Robot_leg_3_B.FSph_i[0]';
bio(452).ndims=2;
bio(452).size=[];
bio(452).isStruct=false;

bio(453).blkName='Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Abs';
bio(453).sigName='';
bio(453).portIdx=0;
bio(453).dim=[1,1];
bio(453).sigWidth=1;
bio(453).sigAddress='&Robot_leg_3_B.Abs_g';
bio(453).ndims=2;
bio(453).size=[];
bio(453).isStruct=false;

bio(454).blkName='Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Abs1';
bio(454).sigName='';
bio(454).portIdx=0;
bio(454).dim=[1,1];
bio(454).sigWidth=1;
bio(454).sigAddress='&Robot_leg_3_B.Abs1_o';
bio(454).ndims=2;
bio(454).size=[];
bio(454).isStruct=false;

bio(455).blkName='Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Data Type Conversion';
bio(455).sigName='';
bio(455).portIdx=0;
bio(455).dim=[1,1];
bio(455).sigWidth=1;
bio(455).sigAddress='&Robot_leg_3_B.DataTypeConversion_m';
bio(455).ndims=2;
bio(455).size=[];
bio(455).isStruct=false;

bio(456).blkName='Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Gain';
bio(456).sigName='';
bio(456).portIdx=0;
bio(456).dim=[1,1];
bio(456).sigWidth=1;
bio(456).sigAddress='&Robot_leg_3_B.Gain_f';
bio(456).ndims=2;
bio(456).size=[];
bio(456).isStruct=false;

bio(457).blkName='Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Gain1';
bio(457).sigName='';
bio(457).portIdx=0;
bio(457).dim=[1,1];
bio(457).sigWidth=1;
bio(457).sigAddress='&Robot_leg_3_B.Gain1_g';
bio(457).ndims=2;
bio(457).size=[];
bio(457).isStruct=false;

bio(458).blkName='Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Logical Operator';
bio(458).sigName='';
bio(458).portIdx=0;
bio(458).dim=[1,1];
bio(458).sigWidth=1;
bio(458).sigAddress='&Robot_leg_3_B.LogicalOperator_a';
bio(458).ndims=2;
bio(458).size=[];
bio(458).isStruct=false;

bio(459).blkName='Robot/Right_leg/Sphere to Plane Force1/Enable Outputs/Product';
bio(459).sigName='';
bio(459).portIdx=0;
bio(459).dim=[8,1];
bio(459).sigWidth=8;
bio(459).sigAddress='&Robot_leg_3_B.Product_g[0]';
bio(459).ndims=2;
bio(459).size=[];
bio(459).isStruct=false;

bio(460).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Copy for Merge';
bio(460).sigName='';
bio(460).portIdx=0;
bio(460).dim=[12,1];
bio(460).sigWidth=12;
bio(460).sigAddress='&Robot_leg_3_B.FSph_mf[0]';
bio(460).ndims=2;
bio(460).size=[];
bio(460).isStruct=false;

bio(461).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Product';
bio(461).sigName='Spr Force';
bio(461).portIdx=0;
bio(461).dim=[1,1];
bio(461).sigWidth=1;
bio(461).sigAddress='&Robot_leg_3_B.SprForce_n';
bio(461).ndims=2;
bio(461).size=[];
bio(461).isStruct=false;

bio(462).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Product1';
bio(462).sigName='Damp Force';
bio(462).portIdx=0;
bio(462).dim=[1,1];
bio(462).sigWidth=1;
bio(462).sigAddress='&Robot_leg_3_B.DampForce_c';
bio(462).ndims=2;
bio(462).size=[];
bio(462).isStruct=false;

bio(463).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Sum';
bio(463).sigName='FSph';
bio(463).portIdx=0;
bio(463).dim=[12,1];
bio(463).sigWidth=12;
bio(463).sigAddress='&Robot_leg_3_B.FSph_mf[0]';
bio(463).ndims=2;
bio(463).size=[];
bio(463).isStruct=false;

bio(464).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Sum1';
bio(464).sigName='FPla';
bio(464).portIdx=0;
bio(464).dim=[3,1];
bio(464).sigWidth=3;
bio(464).sigAddress='&Robot_leg_3_B.FPla_a[0]';
bio(464).ndims=2;
bio(464).size=[];
bio(464).isStruct=false;

bio(465).blkName='Robot/Right_leg/Sphere to Plane Force1/No Force/Zeros';
bio(465).sigName='';
bio(465).portIdx=0;
bio(465).dim=[12,1];
bio(465).sigWidth=12;
bio(465).sigAddress='&Robot_leg_3_B.FSph_mf[0]';
bio(465).ndims=2;
bio(465).size=[];
bio(465).isStruct=false;

bio(466).blkName='Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Abs';
bio(466).sigName='';
bio(466).portIdx=0;
bio(466).dim=[1,1];
bio(466).sigWidth=1;
bio(466).sigAddress='&Robot_leg_3_B.Abs_e';
bio(466).ndims=2;
bio(466).size=[];
bio(466).isStruct=false;

bio(467).blkName='Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Abs1';
bio(467).sigName='';
bio(467).portIdx=0;
bio(467).dim=[1,1];
bio(467).sigWidth=1;
bio(467).sigAddress='&Robot_leg_3_B.Abs1_d';
bio(467).ndims=2;
bio(467).size=[];
bio(467).isStruct=false;

bio(468).blkName='Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Data Type Conversion';
bio(468).sigName='';
bio(468).portIdx=0;
bio(468).dim=[1,1];
bio(468).sigWidth=1;
bio(468).sigAddress='&Robot_leg_3_B.DataTypeConversion_mc';
bio(468).ndims=2;
bio(468).size=[];
bio(468).isStruct=false;

bio(469).blkName='Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Gain';
bio(469).sigName='';
bio(469).portIdx=0;
bio(469).dim=[1,1];
bio(469).sigWidth=1;
bio(469).sigAddress='&Robot_leg_3_B.Gain_j';
bio(469).ndims=2;
bio(469).size=[];
bio(469).isStruct=false;

bio(470).blkName='Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Gain1';
bio(470).sigName='';
bio(470).portIdx=0;
bio(470).dim=[1,1];
bio(470).sigWidth=1;
bio(470).sigAddress='&Robot_leg_3_B.Gain1_j';
bio(470).ndims=2;
bio(470).size=[];
bio(470).isStruct=false;

bio(471).blkName='Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Logical Operator';
bio(471).sigName='';
bio(471).portIdx=0;
bio(471).dim=[1,1];
bio(471).sigWidth=1;
bio(471).sigAddress='&Robot_leg_3_B.LogicalOperator_l';
bio(471).ndims=2;
bio(471).size=[];
bio(471).isStruct=false;

bio(472).blkName='Robot/Right_leg/Sphere to Plane Force2/Enable Outputs/Product';
bio(472).sigName='';
bio(472).portIdx=0;
bio(472).dim=[8,1];
bio(472).sigWidth=8;
bio(472).sigAddress='&Robot_leg_3_B.Product_k[0]';
bio(472).ndims=2;
bio(472).size=[];
bio(472).isStruct=false;

bio(473).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Copy for Merge';
bio(473).sigName='';
bio(473).portIdx=0;
bio(473).dim=[12,1];
bio(473).sigWidth=12;
bio(473).sigAddress='&Robot_leg_3_B.FSph_a0[0]';
bio(473).ndims=2;
bio(473).size=[];
bio(473).isStruct=false;

bio(474).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Product';
bio(474).sigName='Spr Force';
bio(474).portIdx=0;
bio(474).dim=[1,1];
bio(474).sigWidth=1;
bio(474).sigAddress='&Robot_leg_3_B.SprForce_j';
bio(474).ndims=2;
bio(474).size=[];
bio(474).isStruct=false;

bio(475).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Product1';
bio(475).sigName='Damp Force';
bio(475).portIdx=0;
bio(475).dim=[1,1];
bio(475).sigWidth=1;
bio(475).sigAddress='&Robot_leg_3_B.DampForce_j';
bio(475).ndims=2;
bio(475).size=[];
bio(475).isStruct=false;

bio(476).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Sum';
bio(476).sigName='FSph';
bio(476).portIdx=0;
bio(476).dim=[12,1];
bio(476).sigWidth=12;
bio(476).sigAddress='&Robot_leg_3_B.FSph_a0[0]';
bio(476).ndims=2;
bio(476).size=[];
bio(476).isStruct=false;

bio(477).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Sum1';
bio(477).sigName='FPla';
bio(477).portIdx=0;
bio(477).dim=[3,1];
bio(477).sigWidth=3;
bio(477).sigAddress='&Robot_leg_3_B.FPla_o[0]';
bio(477).ndims=2;
bio(477).size=[];
bio(477).isStruct=false;

bio(478).blkName='Robot/Right_leg/Sphere to Plane Force2/No Force/Zeros';
bio(478).sigName='';
bio(478).portIdx=0;
bio(478).dim=[12,1];
bio(478).sigWidth=12;
bio(478).sigAddress='&Robot_leg_3_B.FSph_a0[0]';
bio(478).ndims=2;
bio(478).size=[];
bio(478).isStruct=false;

bio(479).blkName='Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Abs';
bio(479).sigName='';
bio(479).portIdx=0;
bio(479).dim=[1,1];
bio(479).sigWidth=1;
bio(479).sigAddress='&Robot_leg_3_B.Abs_d';
bio(479).ndims=2;
bio(479).size=[];
bio(479).isStruct=false;

bio(480).blkName='Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Abs1';
bio(480).sigName='';
bio(480).portIdx=0;
bio(480).dim=[1,1];
bio(480).sigWidth=1;
bio(480).sigAddress='&Robot_leg_3_B.Abs1_l';
bio(480).ndims=2;
bio(480).size=[];
bio(480).isStruct=false;

bio(481).blkName='Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Data Type Conversion';
bio(481).sigName='';
bio(481).portIdx=0;
bio(481).dim=[1,1];
bio(481).sigWidth=1;
bio(481).sigAddress='&Robot_leg_3_B.DataTypeConversion_l';
bio(481).ndims=2;
bio(481).size=[];
bio(481).isStruct=false;

bio(482).blkName='Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Gain';
bio(482).sigName='';
bio(482).portIdx=0;
bio(482).dim=[1,1];
bio(482).sigWidth=1;
bio(482).sigAddress='&Robot_leg_3_B.Gain_p';
bio(482).ndims=2;
bio(482).size=[];
bio(482).isStruct=false;

bio(483).blkName='Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Gain1';
bio(483).sigName='';
bio(483).portIdx=0;
bio(483).dim=[1,1];
bio(483).sigWidth=1;
bio(483).sigAddress='&Robot_leg_3_B.Gain1_o';
bio(483).ndims=2;
bio(483).size=[];
bio(483).isStruct=false;

bio(484).blkName='Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Logical Operator';
bio(484).sigName='';
bio(484).portIdx=0;
bio(484).dim=[1,1];
bio(484).sigWidth=1;
bio(484).sigAddress='&Robot_leg_3_B.LogicalOperator_e';
bio(484).ndims=2;
bio(484).size=[];
bio(484).isStruct=false;

bio(485).blkName='Robot/Right_leg/Sphere to Plane Force3/Enable Outputs/Product';
bio(485).sigName='';
bio(485).portIdx=0;
bio(485).dim=[8,1];
bio(485).sigWidth=8;
bio(485).sigAddress='&Robot_leg_3_B.Product_f[0]';
bio(485).ndims=2;
bio(485).size=[];
bio(485).isStruct=false;

bio(486).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Copy for Merge';
bio(486).sigName='';
bio(486).portIdx=0;
bio(486).dim=[12,1];
bio(486).sigWidth=12;
bio(486).sigAddress='&Robot_leg_3_B.FSph_n[0]';
bio(486).ndims=2;
bio(486).size=[];
bio(486).isStruct=false;

bio(487).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Product';
bio(487).sigName='Spr Force';
bio(487).portIdx=0;
bio(487).dim=[1,1];
bio(487).sigWidth=1;
bio(487).sigAddress='&Robot_leg_3_B.SprForce';
bio(487).ndims=2;
bio(487).size=[];
bio(487).isStruct=false;

bio(488).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Product1';
bio(488).sigName='Damp Force';
bio(488).portIdx=0;
bio(488).dim=[1,1];
bio(488).sigWidth=1;
bio(488).sigAddress='&Robot_leg_3_B.DampForce';
bio(488).ndims=2;
bio(488).size=[];
bio(488).isStruct=false;

bio(489).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Sum';
bio(489).sigName='FSph';
bio(489).portIdx=0;
bio(489).dim=[12,1];
bio(489).sigWidth=12;
bio(489).sigAddress='&Robot_leg_3_B.FSph_n[0]';
bio(489).ndims=2;
bio(489).size=[];
bio(489).isStruct=false;

bio(490).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Sum1';
bio(490).sigName='FPla';
bio(490).portIdx=0;
bio(490).dim=[3,1];
bio(490).sigWidth=3;
bio(490).sigAddress='&Robot_leg_3_B.FPla[0]';
bio(490).ndims=2;
bio(490).size=[];
bio(490).isStruct=false;

bio(491).blkName='Robot/Right_leg/Sphere to Plane Force3/No Force/Zeros';
bio(491).sigName='';
bio(491).portIdx=0;
bio(491).dim=[12,1];
bio(491).sigWidth=12;
bio(491).sigAddress='&Robot_leg_3_B.FSph_n[0]';
bio(491).ndims=2;
bio(491).size=[];
bio(491).isStruct=false;

bio(492).blkName='Robot/Left_leg/Abduction Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(492).sigName='';
bio(492).portIdx=0;
bio(492).dim=[1,1];
bio(492).sigWidth=1;
bio(492).sigAddress='&Robot_leg_3_B.GAIN_m';
bio(492).ndims=2;
bio(492).size=[];
bio(492).isStruct=false;

bio(493).blkName='Robot/Left_leg/Ankle Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(493).sigName='';
bio(493).portIdx=0;
bio(493).dim=[1,1];
bio(493).sigWidth=1;
bio(493).sigAddress='&Robot_leg_3_B.GAIN_b';
bio(493).ndims=2;
bio(493).size=[];
bio(493).isStruct=false;

bio(494).blkName='Robot/Left_leg/Ankle Twist Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(494).sigName='';
bio(494).portIdx=0;
bio(494).dim=[1,1];
bio(494).sigWidth=1;
bio(494).sigAddress='&Robot_leg_3_B.GAIN_dq';
bio(494).ndims=2;
bio(494).size=[];
bio(494).isStruct=false;

bio(495).blkName='Robot/Left_leg/Hip Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(495).sigName='';
bio(495).portIdx=0;
bio(495).dim=[1,1];
bio(495).sigWidth=1;
bio(495).sigAddress='&Robot_leg_3_B.GAIN_hq';
bio(495).ndims=2;
bio(495).size=[];
bio(495).isStruct=false;

bio(496).blkName='Robot/Left_leg/Knee Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(496).sigName='';
bio(496).portIdx=0;
bio(496).dim=[1,1];
bio(496).sigWidth=1;
bio(496).sigAddress='&Robot_leg_3_B.GAIN_eg';
bio(496).ndims=2;
bio(496).size=[];
bio(496).isStruct=false;

bio(497).blkName='Robot/Left_leg/Rotation Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(497).sigName='';
bio(497).portIdx=0;
bio(497).dim=[1,1];
bio(497).sigWidth=1;
bio(497).sigAddress='&Robot_leg_3_B.GAIN_em';
bio(497).ndims=2;
bio(497).size=[];
bio(497).isStruct=false;

bio(498).blkName='Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Check loc x-axis/Compare';
bio(498).sigName='';
bio(498).portIdx=0;
bio(498).dim=[1,1];
bio(498).sigWidth=1;
bio(498).sigAddress='&Robot_leg_3_B.Compare_n1';
bio(498).ndims=2;
bio(498).size=[];
bio(498).isStruct=false;

bio(499).blkName='Robot/Left_leg/Sphere to Plane Force/Check Sphere on Plane/Check loc y-axis/Compare';
bio(499).sigName='';
bio(499).portIdx=0;
bio(499).dim=[1,1];
bio(499).sigWidth=1;
bio(499).sigAddress='&Robot_leg_3_B.Compare_k';
bio(499).ndims=2;
bio(499).size=[];
bio(499).isStruct=false;

bio(500).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Calculate Penetration/Abs';
bio(500).sigName='';
bio(500).portIdx=0;
bio(500).dim=[1,1];
bio(500).sigWidth=1;
bio(500).sigAddress='&Robot_leg_3_B.Abs_ky';
bio(500).ndims=2;
bio(500).size=[];
bio(500).isStruct=false;

bio(501).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Calculate Penetration/Dead Zone';
bio(501).sigName='';
bio(501).portIdx=0;
bio(501).dim=[1,1];
bio(501).sigWidth=1;
bio(501).sigAddress='&Robot_leg_3_B.DeadZone_ko';
bio(501).ndims=2;
bio(501).size=[];
bio(501).isStruct=false;

bio(502).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Calculate Penetration/Gain2';
bio(502).sigName='';
bio(502).portIdx=0;
bio(502).dim=[1,1];
bio(502).sigWidth=1;
bio(502).sigAddress='&Robot_leg_3_B.Gain2_l';
bio(502).ndims=2;
bio(502).size=[];
bio(502).isStruct=false;

bio(503).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Calculate Penetration/Product';
bio(503).sigName='';
bio(503).portIdx=0;
bio(503).dim=[1,1];
bio(503).sigWidth=1;
bio(503).sigAddress='&Robot_leg_3_B.Product_g0';
bio(503).ndims=2;
bio(503).size=[];
bio(503).isStruct=false;

bio(504).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Calculate Penetration/Sign vx';
bio(504).sigName='';
bio(504).portIdx=0;
bio(504).dim=[1,1];
bio(504).sigWidth=1;
bio(504).sigAddress='&Robot_leg_3_B.Signvx_ax';
bio(504).ndims=2;
bio(504).size=[];
bio(504).isStruct=false;

bio(505).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Calculate Penetration/Sign x';
bio(505).sigName='';
bio(505).portIdx=0;
bio(505).dim=[1,1];
bio(505).sigWidth=1;
bio(505).sigAddress='&Robot_leg_3_B.Signx_l2';
bio(505).ndims=2;
bio(505).size=[];
bio(505).isStruct=false;

bio(506).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Calculate Penetration/Sum';
bio(506).sigName='';
bio(506).portIdx=0;
bio(506).dim=[1,1];
bio(506).sigWidth=1;
bio(506).sigAddress='&Robot_leg_3_B.Sum_l4';
bio(506).ndims=2;
bio(506).size=[];
bio(506).isStruct=false;

bio(507).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Product';
bio(507).sigName='';
bio(507).portIdx=0;
bio(507).dim=[1,1];
bio(507).sigWidth=1;
bio(507).sigAddress='&Robot_leg_3_B.Product_mw';
bio(507).ndims=2;
bio(507).size=[];
bio(507).isStruct=false;

bio(508).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Product1';
bio(508).sigName='';
bio(508).portIdx=0;
bio(508).dim=[1,1];
bio(508).sigWidth=1;
bio(508).sigAddress='&Robot_leg_3_B.Product1_oq';
bio(508).ndims=2;
bio(508).size=[];
bio(508).isStruct=false;

bio(509).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Product2';
bio(509).sigName='';
bio(509).portIdx=0;
bio(509).dim=[1,1];
bio(509).sigWidth=1;
bio(509).sigAddress='&Robot_leg_3_B.Product2_f';
bio(509).ndims=2;
bio(509).size=[];
bio(509).isStruct=false;

bio(510).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Product3';
bio(510).sigName='';
bio(510).portIdx=0;
bio(510).dim=[1,1];
bio(510).sigWidth=1;
bio(510).sigAddress='&Robot_leg_3_B.Product3_ax';
bio(510).ndims=2;
bio(510).size=[];
bio(510).isStruct=false;

bio(511).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Product4';
bio(511).sigName='';
bio(511).portIdx=0;
bio(511).dim=[1,1];
bio(511).sigWidth=1;
bio(511).sigAddress='&Robot_leg_3_B.Product4_ab';
bio(511).ndims=2;
bio(511).size=[];
bio(511).isStruct=false;

bio(512).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Product5';
bio(512).sigName='';
bio(512).portIdx=0;
bio(512).dim=[1,1];
bio(512).sigWidth=1;
bio(512).sigAddress='&Robot_leg_3_B.Product5_gg';
bio(512).ndims=2;
bio(512).size=[];
bio(512).isStruct=false;

bio(513).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Sum';
bio(513).sigName='';
bio(513).portIdx=0;
bio(513).dim=[12,1];
bio(513).sigWidth=12;
bio(513).sigAddress='&Robot_leg_3_B.FSph[0]';
bio(513).ndims=2;
bio(513).size=[];
bio(513).isStruct=false;

bio(514).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Sum1';
bio(514).sigName='';
bio(514).portIdx=0;
bio(514).dim=[12,1];
bio(514).sigWidth=12;
bio(514).sigAddress='&Robot_leg_3_B.FSph[0]';
bio(514).ndims=2;
bio(514).size=[];
bio(514).isStruct=false;

bio(515).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Cross Product/Sum2';
bio(515).sigName='';
bio(515).portIdx=0;
bio(515).dim=[12,1];
bio(515).sigWidth=12;
bio(515).sigAddress='&Robot_leg_3_B.FSph[0]';
bio(515).ndims=2;
bio(515).size=[];
bio(515).isStruct=false;

bio(516).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Gain';
bio(516).sigName='';
bio(516).portIdx=0;
bio(516).dim=[3,1];
bio(516).sigWidth=3;
bio(516).sigAddress='&Robot_leg_3_B.Gain_h[0]';
bio(516).ndims=2;
bio(516).size=[];
bio(516).isStruct=false;

bio(517).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Product1';
bio(517).sigName='';
bio(517).portIdx=0;
bio(517).dim=[3,1];
bio(517).sigWidth=3;
bio(517).sigAddress='&Robot_leg_3_B.Product1_e[0]';
bio(517).ndims=2;
bio(517).size=[];
bio(517).isStruct=false;

bio(518).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Product2';
bio(518).sigName='';
bio(518).portIdx=0;
bio(518).dim=[12,1];
bio(518).sigWidth=12;
bio(518).sigAddress='&Robot_leg_3_B.FSph[0]';
bio(518).ndims=2;
bio(518).size=[];
bio(518).isStruct=false;

bio(519).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Product3';
bio(519).sigName='';
bio(519).portIdx=0;
bio(519).dim=[1,1];
bio(519).sigWidth=1;
bio(519).sigAddress='&Robot_leg_3_B.Product3_bw';
bio(519).ndims=2;
bio(519).size=[];
bio(519).isStruct=false;

bio(520).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Product4';
bio(520).sigName='';
bio(520).portIdx=0;
bio(520).dim=[1,1];
bio(520).sigWidth=1;
bio(520).sigAddress='&Robot_leg_3_B.Product4_at';
bio(520).ndims=2;
bio(520).size=[];
bio(520).isStruct=false;

bio(521).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Product5';
bio(521).sigName='';
bio(521).portIdx=0;
bio(521).dim=[1,1];
bio(521).sigWidth=1;
bio(521).sigAddress='&Robot_leg_3_B.Product5_mo';
bio(521).ndims=2;
bio(521).size=[];
bio(521).isStruct=false;

bio(522).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Product6';
bio(522).sigName='';
bio(522).portIdx=0;
bio(522).dim=[1,1];
bio(522).sigWidth=1;
bio(522).sigAddress='&Robot_leg_3_B.Product6_a';
bio(522).ndims=2;
bio(522).size=[];
bio(522).isStruct=false;

bio(523).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Product7';
bio(523).sigName='';
bio(523).portIdx=0;
bio(523).dim=[3,1];
bio(523).sigWidth=3;
bio(523).sigAddress='&Robot_leg_3_B.Product7_c[0]';
bio(523).ndims=2;
bio(523).size=[];
bio(523).isStruct=false;

bio(524).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Trigonometric Function';
bio(524).sigName='';
bio(524).portIdx=0;
bio(524).dim=[1,1];
bio(524).sigWidth=1;
bio(524).sigAddress='&Robot_leg_3_B.TrigonometricFunction_lx';
bio(524).ndims=2;
bio(524).size=[];
bio(524).isStruct=false;

bio(525).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Trigonometric Function1';
bio(525).sigName='';
bio(525).portIdx=0;
bio(525).dim=[1,1];
bio(525).sigWidth=1;
bio(525).sigAddress='&Robot_leg_3_B.TrigonometricFunction1_oc';
bio(525).ndims=2;
bio(525).size=[];
bio(525).isStruct=false;

bio(526).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Fn/Gain';
bio(526).sigName='';
bio(526).portIdx=0;
bio(526).dim=[3,1];
bio(526).sigWidth=3;
bio(526).sigAddress='&Robot_leg_3_B.Gain_em[0]';
bio(526).ndims=2;
bio(526).size=[];
bio(526).isStruct=false;

bio(527).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Fn/Product2';
bio(527).sigName='';
bio(527).portIdx=0;
bio(527).dim=[3,1];
bio(527).sigWidth=3;
bio(527).sigAddress='&Robot_leg_3_B.Product2_g[0]';
bio(527).ndims=2;
bio(527).size=[];
bio(527).isStruct=false;

bio(528).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Fn/Sum';
bio(528).sigName='';
bio(528).portIdx=0;
bio(528).dim=[1,1];
bio(528).sigWidth=1;
bio(528).sigAddress='&Robot_leg_3_B.Sum_bz';
bio(528).ndims=2;
bio(528).size=[];
bio(528).isStruct=false;

bio(529).blkName='Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Check loc x-axis/Compare';
bio(529).sigName='';
bio(529).portIdx=0;
bio(529).dim=[1,1];
bio(529).sigWidth=1;
bio(529).sigAddress='&Robot_leg_3_B.Compare_nc';
bio(529).ndims=2;
bio(529).size=[];
bio(529).isStruct=false;

bio(530).blkName='Robot/Left_leg/Sphere to Plane Force1/Check Sphere on Plane/Check loc y-axis/Compare';
bio(530).sigName='';
bio(530).portIdx=0;
bio(530).dim=[1,1];
bio(530).sigWidth=1;
bio(530).sigAddress='&Robot_leg_3_B.Compare_j';
bio(530).ndims=2;
bio(530).size=[];
bio(530).isStruct=false;

bio(531).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Abs';
bio(531).sigName='';
bio(531).portIdx=0;
bio(531).dim=[1,1];
bio(531).sigWidth=1;
bio(531).sigAddress='&Robot_leg_3_B.Abs_kv';
bio(531).ndims=2;
bio(531).size=[];
bio(531).isStruct=false;

bio(532).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Dead Zone';
bio(532).sigName='';
bio(532).portIdx=0;
bio(532).dim=[1,1];
bio(532).sigWidth=1;
bio(532).sigAddress='&Robot_leg_3_B.DeadZone_l';
bio(532).ndims=2;
bio(532).size=[];
bio(532).isStruct=false;

bio(533).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Gain2';
bio(533).sigName='';
bio(533).portIdx=0;
bio(533).dim=[1,1];
bio(533).sigWidth=1;
bio(533).sigAddress='&Robot_leg_3_B.Gain2_f';
bio(533).ndims=2;
bio(533).size=[];
bio(533).isStruct=false;

bio(534).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Product';
bio(534).sigName='';
bio(534).portIdx=0;
bio(534).dim=[1,1];
bio(534).sigWidth=1;
bio(534).sigAddress='&Robot_leg_3_B.Product_gr';
bio(534).ndims=2;
bio(534).size=[];
bio(534).isStruct=false;

bio(535).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Sign vx';
bio(535).sigName='';
bio(535).portIdx=0;
bio(535).dim=[1,1];
bio(535).sigWidth=1;
bio(535).sigAddress='&Robot_leg_3_B.Signvx_p';
bio(535).ndims=2;
bio(535).size=[];
bio(535).isStruct=false;

bio(536).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Sign x';
bio(536).sigName='';
bio(536).portIdx=0;
bio(536).dim=[1,1];
bio(536).sigWidth=1;
bio(536).sigAddress='&Robot_leg_3_B.Signx_j';
bio(536).ndims=2;
bio(536).size=[];
bio(536).isStruct=false;

bio(537).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Sum';
bio(537).sigName='';
bio(537).portIdx=0;
bio(537).dim=[1,1];
bio(537).sigWidth=1;
bio(537).sigAddress='&Robot_leg_3_B.Sum_la';
bio(537).ndims=2;
bio(537).size=[];
bio(537).isStruct=false;

bio(538).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Product';
bio(538).sigName='';
bio(538).portIdx=0;
bio(538).dim=[1,1];
bio(538).sigWidth=1;
bio(538).sigAddress='&Robot_leg_3_B.Product_jf';
bio(538).ndims=2;
bio(538).size=[];
bio(538).isStruct=false;

bio(539).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Product1';
bio(539).sigName='';
bio(539).portIdx=0;
bio(539).dim=[1,1];
bio(539).sigWidth=1;
bio(539).sigAddress='&Robot_leg_3_B.Product1_l';
bio(539).ndims=2;
bio(539).size=[];
bio(539).isStruct=false;

bio(540).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Product2';
bio(540).sigName='';
bio(540).portIdx=0;
bio(540).dim=[1,1];
bio(540).sigWidth=1;
bio(540).sigAddress='&Robot_leg_3_B.Product2_jh';
bio(540).ndims=2;
bio(540).size=[];
bio(540).isStruct=false;

bio(541).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Product3';
bio(541).sigName='';
bio(541).portIdx=0;
bio(541).dim=[1,1];
bio(541).sigWidth=1;
bio(541).sigAddress='&Robot_leg_3_B.Product3_ep';
bio(541).ndims=2;
bio(541).size=[];
bio(541).isStruct=false;

bio(542).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Product4';
bio(542).sigName='';
bio(542).portIdx=0;
bio(542).dim=[1,1];
bio(542).sigWidth=1;
bio(542).sigAddress='&Robot_leg_3_B.Product4_o';
bio(542).ndims=2;
bio(542).size=[];
bio(542).isStruct=false;

bio(543).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Product5';
bio(543).sigName='';
bio(543).portIdx=0;
bio(543).dim=[1,1];
bio(543).sigWidth=1;
bio(543).sigAddress='&Robot_leg_3_B.Product5_np';
bio(543).ndims=2;
bio(543).size=[];
bio(543).isStruct=false;

bio(544).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Sum';
bio(544).sigName='';
bio(544).portIdx=0;
bio(544).dim=[12,1];
bio(544).sigWidth=12;
bio(544).sigAddress='&Robot_leg_3_B.FSph_m[0]';
bio(544).ndims=2;
bio(544).size=[];
bio(544).isStruct=false;

bio(545).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Sum1';
bio(545).sigName='';
bio(545).portIdx=0;
bio(545).dim=[12,1];
bio(545).sigWidth=12;
bio(545).sigAddress='&Robot_leg_3_B.FSph_m[0]';
bio(545).ndims=2;
bio(545).size=[];
bio(545).isStruct=false;

bio(546).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Cross Product/Sum2';
bio(546).sigName='';
bio(546).portIdx=0;
bio(546).dim=[12,1];
bio(546).sigWidth=12;
bio(546).sigAddress='&Robot_leg_3_B.FSph_m[0]';
bio(546).ndims=2;
bio(546).size=[];
bio(546).isStruct=false;

bio(547).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Gain';
bio(547).sigName='';
bio(547).portIdx=0;
bio(547).dim=[3,1];
bio(547).sigWidth=3;
bio(547).sigAddress='&Robot_leg_3_B.Gain_d1[0]';
bio(547).ndims=2;
bio(547).size=[];
bio(547).isStruct=false;

bio(548).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Product1';
bio(548).sigName='';
bio(548).portIdx=0;
bio(548).dim=[3,1];
bio(548).sigWidth=3;
bio(548).sigAddress='&Robot_leg_3_B.Product1_o4[0]';
bio(548).ndims=2;
bio(548).size=[];
bio(548).isStruct=false;

bio(549).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Product2';
bio(549).sigName='';
bio(549).portIdx=0;
bio(549).dim=[12,1];
bio(549).sigWidth=12;
bio(549).sigAddress='&Robot_leg_3_B.FSph_m[0]';
bio(549).ndims=2;
bio(549).size=[];
bio(549).isStruct=false;

bio(550).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Product3';
bio(550).sigName='';
bio(550).portIdx=0;
bio(550).dim=[1,1];
bio(550).sigWidth=1;
bio(550).sigAddress='&Robot_leg_3_B.Product3_ab';
bio(550).ndims=2;
bio(550).size=[];
bio(550).isStruct=false;

bio(551).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Product4';
bio(551).sigName='';
bio(551).portIdx=0;
bio(551).dim=[1,1];
bio(551).sigWidth=1;
bio(551).sigAddress='&Robot_leg_3_B.Product4_j';
bio(551).ndims=2;
bio(551).size=[];
bio(551).isStruct=false;

bio(552).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Product5';
bio(552).sigName='';
bio(552).portIdx=0;
bio(552).dim=[1,1];
bio(552).sigWidth=1;
bio(552).sigAddress='&Robot_leg_3_B.Product5_is';
bio(552).ndims=2;
bio(552).size=[];
bio(552).isStruct=false;

bio(553).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Product6';
bio(553).sigName='';
bio(553).portIdx=0;
bio(553).dim=[1,1];
bio(553).sigWidth=1;
bio(553).sigAddress='&Robot_leg_3_B.Product6_b';
bio(553).ndims=2;
bio(553).size=[];
bio(553).isStruct=false;

bio(554).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Product7';
bio(554).sigName='';
bio(554).portIdx=0;
bio(554).dim=[3,1];
bio(554).sigWidth=3;
bio(554).sigAddress='&Robot_leg_3_B.Product7_j[0]';
bio(554).ndims=2;
bio(554).size=[];
bio(554).isStruct=false;

bio(555).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Trigonometric Function';
bio(555).sigName='';
bio(555).portIdx=0;
bio(555).dim=[1,1];
bio(555).sigWidth=1;
bio(555).sigAddress='&Robot_leg_3_B.TrigonometricFunction_jh';
bio(555).ndims=2;
bio(555).size=[];
bio(555).isStruct=false;

bio(556).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Trigonometric Function1';
bio(556).sigName='';
bio(556).portIdx=0;
bio(556).dim=[1,1];
bio(556).sigWidth=1;
bio(556).sigAddress='&Robot_leg_3_B.TrigonometricFunction1_n';
bio(556).ndims=2;
bio(556).size=[];
bio(556).isStruct=false;

bio(557).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Fn/Gain';
bio(557).sigName='';
bio(557).portIdx=0;
bio(557).dim=[3,1];
bio(557).sigWidth=3;
bio(557).sigAddress='&Robot_leg_3_B.Gain_fu[0]';
bio(557).ndims=2;
bio(557).size=[];
bio(557).isStruct=false;

bio(558).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Fn/Product2';
bio(558).sigName='';
bio(558).portIdx=0;
bio(558).dim=[3,1];
bio(558).sigWidth=3;
bio(558).sigAddress='&Robot_leg_3_B.Product2_ib[0]';
bio(558).ndims=2;
bio(558).size=[];
bio(558).isStruct=false;

bio(559).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Fn/Sum';
bio(559).sigName='';
bio(559).portIdx=0;
bio(559).dim=[1,1];
bio(559).sigWidth=1;
bio(559).sigAddress='&Robot_leg_3_B.Sum_aw';
bio(559).ndims=2;
bio(559).size=[];
bio(559).isStruct=false;

bio(560).blkName='Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Check loc x-axis/Compare';
bio(560).sigName='';
bio(560).portIdx=0;
bio(560).dim=[1,1];
bio(560).sigWidth=1;
bio(560).sigAddress='&Robot_leg_3_B.Compare_p';
bio(560).ndims=2;
bio(560).size=[];
bio(560).isStruct=false;

bio(561).blkName='Robot/Left_leg/Sphere to Plane Force2/Check Sphere on Plane/Check loc y-axis/Compare';
bio(561).sigName='';
bio(561).portIdx=0;
bio(561).dim=[1,1];
bio(561).sigWidth=1;
bio(561).sigAddress='&Robot_leg_3_B.Compare_a';
bio(561).ndims=2;
bio(561).size=[];
bio(561).isStruct=false;

bio(562).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Abs';
bio(562).sigName='';
bio(562).portIdx=0;
bio(562).dim=[1,1];
bio(562).sigWidth=1;
bio(562).sigAddress='&Robot_leg_3_B.Abs_b';
bio(562).ndims=2;
bio(562).size=[];
bio(562).isStruct=false;

bio(563).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Dead Zone';
bio(563).sigName='';
bio(563).portIdx=0;
bio(563).dim=[1,1];
bio(563).sigWidth=1;
bio(563).sigAddress='&Robot_leg_3_B.DeadZone_k';
bio(563).ndims=2;
bio(563).size=[];
bio(563).isStruct=false;

bio(564).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Gain2';
bio(564).sigName='';
bio(564).portIdx=0;
bio(564).dim=[1,1];
bio(564).sigWidth=1;
bio(564).sigAddress='&Robot_leg_3_B.Gain2_b';
bio(564).ndims=2;
bio(564).size=[];
bio(564).isStruct=false;

bio(565).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Product';
bio(565).sigName='';
bio(565).portIdx=0;
bio(565).dim=[1,1];
bio(565).sigWidth=1;
bio(565).sigAddress='&Robot_leg_3_B.Product_if';
bio(565).ndims=2;
bio(565).size=[];
bio(565).isStruct=false;

bio(566).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Sign vx';
bio(566).sigName='';
bio(566).portIdx=0;
bio(566).dim=[1,1];
bio(566).sigWidth=1;
bio(566).sigAddress='&Robot_leg_3_B.Signvx_h';
bio(566).ndims=2;
bio(566).size=[];
bio(566).isStruct=false;

bio(567).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Sign x';
bio(567).sigName='';
bio(567).portIdx=0;
bio(567).dim=[1,1];
bio(567).sigWidth=1;
bio(567).sigAddress='&Robot_leg_3_B.Signx_e';
bio(567).ndims=2;
bio(567).size=[];
bio(567).isStruct=false;

bio(568).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Sum';
bio(568).sigName='';
bio(568).portIdx=0;
bio(568).dim=[1,1];
bio(568).sigWidth=1;
bio(568).sigAddress='&Robot_leg_3_B.Sum_j4';
bio(568).ndims=2;
bio(568).size=[];
bio(568).isStruct=false;

bio(569).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Product';
bio(569).sigName='';
bio(569).portIdx=0;
bio(569).dim=[1,1];
bio(569).sigWidth=1;
bio(569).sigAddress='&Robot_leg_3_B.Product_fd';
bio(569).ndims=2;
bio(569).size=[];
bio(569).isStruct=false;

bio(570).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Product1';
bio(570).sigName='';
bio(570).portIdx=0;
bio(570).dim=[1,1];
bio(570).sigWidth=1;
bio(570).sigAddress='&Robot_leg_3_B.Product1_ij';
bio(570).ndims=2;
bio(570).size=[];
bio(570).isStruct=false;

bio(571).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Product2';
bio(571).sigName='';
bio(571).portIdx=0;
bio(571).dim=[1,1];
bio(571).sigWidth=1;
bio(571).sigAddress='&Robot_leg_3_B.Product2_e';
bio(571).ndims=2;
bio(571).size=[];
bio(571).isStruct=false;

bio(572).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Product3';
bio(572).sigName='';
bio(572).portIdx=0;
bio(572).dim=[1,1];
bio(572).sigWidth=1;
bio(572).sigAddress='&Robot_leg_3_B.Product3_ma';
bio(572).ndims=2;
bio(572).size=[];
bio(572).isStruct=false;

bio(573).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Product4';
bio(573).sigName='';
bio(573).portIdx=0;
bio(573).dim=[1,1];
bio(573).sigWidth=1;
bio(573).sigAddress='&Robot_leg_3_B.Product4_ae';
bio(573).ndims=2;
bio(573).size=[];
bio(573).isStruct=false;

bio(574).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Product5';
bio(574).sigName='';
bio(574).portIdx=0;
bio(574).dim=[1,1];
bio(574).sigWidth=1;
bio(574).sigAddress='&Robot_leg_3_B.Product5_jh';
bio(574).ndims=2;
bio(574).size=[];
bio(574).isStruct=false;

bio(575).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Sum';
bio(575).sigName='';
bio(575).portIdx=0;
bio(575).dim=[12,1];
bio(575).sigWidth=12;
bio(575).sigAddress='&Robot_leg_3_B.FSph_l[0]';
bio(575).ndims=2;
bio(575).size=[];
bio(575).isStruct=false;

bio(576).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Sum1';
bio(576).sigName='';
bio(576).portIdx=0;
bio(576).dim=[12,1];
bio(576).sigWidth=12;
bio(576).sigAddress='&Robot_leg_3_B.FSph_l[0]';
bio(576).ndims=2;
bio(576).size=[];
bio(576).isStruct=false;

bio(577).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Cross Product/Sum2';
bio(577).sigName='';
bio(577).portIdx=0;
bio(577).dim=[12,1];
bio(577).sigWidth=12;
bio(577).sigAddress='&Robot_leg_3_B.FSph_l[0]';
bio(577).ndims=2;
bio(577).size=[];
bio(577).isStruct=false;

bio(578).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Gain';
bio(578).sigName='';
bio(578).portIdx=0;
bio(578).dim=[3,1];
bio(578).sigWidth=3;
bio(578).sigAddress='&Robot_leg_3_B.Gain_ib[0]';
bio(578).ndims=2;
bio(578).size=[];
bio(578).isStruct=false;

bio(579).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Product1';
bio(579).sigName='';
bio(579).portIdx=0;
bio(579).dim=[3,1];
bio(579).sigWidth=3;
bio(579).sigAddress='&Robot_leg_3_B.Product1_m[0]';
bio(579).ndims=2;
bio(579).size=[];
bio(579).isStruct=false;

bio(580).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Product2';
bio(580).sigName='';
bio(580).portIdx=0;
bio(580).dim=[12,1];
bio(580).sigWidth=12;
bio(580).sigAddress='&Robot_leg_3_B.FSph_l[0]';
bio(580).ndims=2;
bio(580).size=[];
bio(580).isStruct=false;

bio(581).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Product3';
bio(581).sigName='';
bio(581).portIdx=0;
bio(581).dim=[1,1];
bio(581).sigWidth=1;
bio(581).sigAddress='&Robot_leg_3_B.Product3_kn';
bio(581).ndims=2;
bio(581).size=[];
bio(581).isStruct=false;

bio(582).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Product4';
bio(582).sigName='';
bio(582).portIdx=0;
bio(582).dim=[1,1];
bio(582).sigWidth=1;
bio(582).sigAddress='&Robot_leg_3_B.Product4_iys';
bio(582).ndims=2;
bio(582).size=[];
bio(582).isStruct=false;

bio(583).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Product5';
bio(583).sigName='';
bio(583).portIdx=0;
bio(583).dim=[1,1];
bio(583).sigWidth=1;
bio(583).sigAddress='&Robot_leg_3_B.Product5_jn';
bio(583).ndims=2;
bio(583).size=[];
bio(583).isStruct=false;

bio(584).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Product6';
bio(584).sigName='';
bio(584).portIdx=0;
bio(584).dim=[1,1];
bio(584).sigWidth=1;
bio(584).sigAddress='&Robot_leg_3_B.Product6_c';
bio(584).ndims=2;
bio(584).size=[];
bio(584).isStruct=false;

bio(585).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Product7';
bio(585).sigName='';
bio(585).portIdx=0;
bio(585).dim=[3,1];
bio(585).sigWidth=3;
bio(585).sigAddress='&Robot_leg_3_B.Product7_bi[0]';
bio(585).ndims=2;
bio(585).size=[];
bio(585).isStruct=false;

bio(586).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Trigonometric Function';
bio(586).sigName='';
bio(586).portIdx=0;
bio(586).dim=[1,1];
bio(586).sigWidth=1;
bio(586).sigAddress='&Robot_leg_3_B.TrigonometricFunction_iw';
bio(586).ndims=2;
bio(586).size=[];
bio(586).isStruct=false;

bio(587).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Trigonometric Function1';
bio(587).sigName='';
bio(587).portIdx=0;
bio(587).dim=[1,1];
bio(587).sigWidth=1;
bio(587).sigAddress='&Robot_leg_3_B.TrigonometricFunction1_dl';
bio(587).ndims=2;
bio(587).size=[];
bio(587).isStruct=false;

bio(588).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Fn/Gain';
bio(588).sigName='';
bio(588).portIdx=0;
bio(588).dim=[3,1];
bio(588).sigWidth=3;
bio(588).sigAddress='&Robot_leg_3_B.Gain_ar[0]';
bio(588).ndims=2;
bio(588).size=[];
bio(588).isStruct=false;

bio(589).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Fn/Product2';
bio(589).sigName='';
bio(589).portIdx=0;
bio(589).dim=[3,1];
bio(589).sigWidth=3;
bio(589).sigAddress='&Robot_leg_3_B.Product2_d[0]';
bio(589).ndims=2;
bio(589).size=[];
bio(589).isStruct=false;

bio(590).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Fn/Sum';
bio(590).sigName='';
bio(590).portIdx=0;
bio(590).dim=[1,1];
bio(590).sigWidth=1;
bio(590).sigAddress='&Robot_leg_3_B.Sum_iz';
bio(590).ndims=2;
bio(590).size=[];
bio(590).isStruct=false;

bio(591).blkName='Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Check loc x-axis/Compare';
bio(591).sigName='';
bio(591).portIdx=0;
bio(591).dim=[1,1];
bio(591).sigWidth=1;
bio(591).sigAddress='&Robot_leg_3_B.Compare_aq';
bio(591).ndims=2;
bio(591).size=[];
bio(591).isStruct=false;

bio(592).blkName='Robot/Left_leg/Sphere to Plane Force3/Check Sphere on Plane/Check loc y-axis/Compare';
bio(592).sigName='';
bio(592).portIdx=0;
bio(592).dim=[1,1];
bio(592).sigWidth=1;
bio(592).sigAddress='&Robot_leg_3_B.Compare_i';
bio(592).ndims=2;
bio(592).size=[];
bio(592).isStruct=false;

bio(593).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Abs';
bio(593).sigName='';
bio(593).portIdx=0;
bio(593).dim=[1,1];
bio(593).sigWidth=1;
bio(593).sigAddress='&Robot_leg_3_B.Abs_g4';
bio(593).ndims=2;
bio(593).size=[];
bio(593).isStruct=false;

bio(594).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Dead Zone';
bio(594).sigName='';
bio(594).portIdx=0;
bio(594).dim=[1,1];
bio(594).sigWidth=1;
bio(594).sigAddress='&Robot_leg_3_B.DeadZone_ap';
bio(594).ndims=2;
bio(594).size=[];
bio(594).isStruct=false;

bio(595).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Gain2';
bio(595).sigName='';
bio(595).portIdx=0;
bio(595).dim=[1,1];
bio(595).sigWidth=1;
bio(595).sigAddress='&Robot_leg_3_B.Gain2_e';
bio(595).ndims=2;
bio(595).size=[];
bio(595).isStruct=false;

bio(596).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Product';
bio(596).sigName='';
bio(596).portIdx=0;
bio(596).dim=[1,1];
bio(596).sigWidth=1;
bio(596).sigAddress='&Robot_leg_3_B.Product_gy';
bio(596).ndims=2;
bio(596).size=[];
bio(596).isStruct=false;

bio(597).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Sign vx';
bio(597).sigName='';
bio(597).portIdx=0;
bio(597).dim=[1,1];
bio(597).sigWidth=1;
bio(597).sigAddress='&Robot_leg_3_B.Signvx_l';
bio(597).ndims=2;
bio(597).size=[];
bio(597).isStruct=false;

bio(598).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Sign x';
bio(598).sigName='';
bio(598).portIdx=0;
bio(598).dim=[1,1];
bio(598).sigWidth=1;
bio(598).sigAddress='&Robot_leg_3_B.Signx_lq';
bio(598).ndims=2;
bio(598).size=[];
bio(598).isStruct=false;

bio(599).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Sum';
bio(599).sigName='';
bio(599).portIdx=0;
bio(599).dim=[1,1];
bio(599).sigWidth=1;
bio(599).sigAddress='&Robot_leg_3_B.Sum_eb';
bio(599).ndims=2;
bio(599).size=[];
bio(599).isStruct=false;

bio(600).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Product';
bio(600).sigName='';
bio(600).portIdx=0;
bio(600).dim=[1,1];
bio(600).sigWidth=1;
bio(600).sigAddress='&Robot_leg_3_B.Product_a4';
bio(600).ndims=2;
bio(600).size=[];
bio(600).isStruct=false;

bio(601).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Product1';
bio(601).sigName='';
bio(601).portIdx=0;
bio(601).dim=[1,1];
bio(601).sigWidth=1;
bio(601).sigAddress='&Robot_leg_3_B.Product1_hn';
bio(601).ndims=2;
bio(601).size=[];
bio(601).isStruct=false;

bio(602).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Product2';
bio(602).sigName='';
bio(602).portIdx=0;
bio(602).dim=[1,1];
bio(602).sigWidth=1;
bio(602).sigAddress='&Robot_leg_3_B.Product2_k';
bio(602).ndims=2;
bio(602).size=[];
bio(602).isStruct=false;

bio(603).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Product3';
bio(603).sigName='';
bio(603).portIdx=0;
bio(603).dim=[1,1];
bio(603).sigWidth=1;
bio(603).sigAddress='&Robot_leg_3_B.Product3_k';
bio(603).ndims=2;
bio(603).size=[];
bio(603).isStruct=false;

bio(604).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Product4';
bio(604).sigName='';
bio(604).portIdx=0;
bio(604).dim=[1,1];
bio(604).sigWidth=1;
bio(604).sigAddress='&Robot_leg_3_B.Product4_ku';
bio(604).ndims=2;
bio(604).size=[];
bio(604).isStruct=false;

bio(605).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Product5';
bio(605).sigName='';
bio(605).portIdx=0;
bio(605).dim=[1,1];
bio(605).sigWidth=1;
bio(605).sigAddress='&Robot_leg_3_B.Product5_ae';
bio(605).ndims=2;
bio(605).size=[];
bio(605).isStruct=false;

bio(606).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Sum';
bio(606).sigName='';
bio(606).portIdx=0;
bio(606).dim=[12,1];
bio(606).sigWidth=12;
bio(606).sigAddress='&Robot_leg_3_B.FSph_a[0]';
bio(606).ndims=2;
bio(606).size=[];
bio(606).isStruct=false;

bio(607).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Sum1';
bio(607).sigName='';
bio(607).portIdx=0;
bio(607).dim=[12,1];
bio(607).sigWidth=12;
bio(607).sigAddress='&Robot_leg_3_B.FSph_a[0]';
bio(607).ndims=2;
bio(607).size=[];
bio(607).isStruct=false;

bio(608).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Cross Product/Sum2';
bio(608).sigName='';
bio(608).portIdx=0;
bio(608).dim=[12,1];
bio(608).sigWidth=12;
bio(608).sigAddress='&Robot_leg_3_B.FSph_a[0]';
bio(608).ndims=2;
bio(608).size=[];
bio(608).isStruct=false;

bio(609).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Gain';
bio(609).sigName='';
bio(609).portIdx=0;
bio(609).dim=[3,1];
bio(609).sigWidth=3;
bio(609).sigAddress='&Robot_leg_3_B.Gain_e[0]';
bio(609).ndims=2;
bio(609).size=[];
bio(609).isStruct=false;

bio(610).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Product1';
bio(610).sigName='';
bio(610).portIdx=0;
bio(610).dim=[3,1];
bio(610).sigWidth=3;
bio(610).sigAddress='&Robot_leg_3_B.Product1_km[0]';
bio(610).ndims=2;
bio(610).size=[];
bio(610).isStruct=false;

bio(611).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Product2';
bio(611).sigName='';
bio(611).portIdx=0;
bio(611).dim=[12,1];
bio(611).sigWidth=12;
bio(611).sigAddress='&Robot_leg_3_B.FSph_a[0]';
bio(611).ndims=2;
bio(611).size=[];
bio(611).isStruct=false;

bio(612).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Product3';
bio(612).sigName='';
bio(612).portIdx=0;
bio(612).dim=[1,1];
bio(612).sigWidth=1;
bio(612).sigAddress='&Robot_leg_3_B.Product3_dh';
bio(612).ndims=2;
bio(612).size=[];
bio(612).isStruct=false;

bio(613).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Product4';
bio(613).sigName='';
bio(613).portIdx=0;
bio(613).dim=[1,1];
bio(613).sigWidth=1;
bio(613).sigAddress='&Robot_leg_3_B.Product4_k5';
bio(613).ndims=2;
bio(613).size=[];
bio(613).isStruct=false;

bio(614).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Product5';
bio(614).sigName='';
bio(614).portIdx=0;
bio(614).dim=[1,1];
bio(614).sigWidth=1;
bio(614).sigAddress='&Robot_leg_3_B.Product5_a';
bio(614).ndims=2;
bio(614).size=[];
bio(614).isStruct=false;

bio(615).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Product6';
bio(615).sigName='';
bio(615).portIdx=0;
bio(615).dim=[1,1];
bio(615).sigWidth=1;
bio(615).sigAddress='&Robot_leg_3_B.Product6_p';
bio(615).ndims=2;
bio(615).size=[];
bio(615).isStruct=false;

bio(616).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Product7';
bio(616).sigName='';
bio(616).portIdx=0;
bio(616).dim=[3,1];
bio(616).sigWidth=3;
bio(616).sigAddress='&Robot_leg_3_B.Product7_f[0]';
bio(616).ndims=2;
bio(616).size=[];
bio(616).isStruct=false;

bio(617).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Trigonometric Function';
bio(617).sigName='';
bio(617).portIdx=0;
bio(617).dim=[1,1];
bio(617).sigWidth=1;
bio(617).sigAddress='&Robot_leg_3_B.TrigonometricFunction_h';
bio(617).ndims=2;
bio(617).size=[];
bio(617).isStruct=false;

bio(618).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Trigonometric Function1';
bio(618).sigName='';
bio(618).portIdx=0;
bio(618).dim=[1,1];
bio(618).sigWidth=1;
bio(618).sigAddress='&Robot_leg_3_B.TrigonometricFunction1_d';
bio(618).ndims=2;
bio(618).size=[];
bio(618).isStruct=false;

bio(619).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Fn/Gain';
bio(619).sigName='';
bio(619).portIdx=0;
bio(619).dim=[3,1];
bio(619).sigWidth=3;
bio(619).sigAddress='&Robot_leg_3_B.Gain_d[0]';
bio(619).ndims=2;
bio(619).size=[];
bio(619).isStruct=false;

bio(620).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Fn/Product2';
bio(620).sigName='';
bio(620).portIdx=0;
bio(620).dim=[3,1];
bio(620).sigWidth=3;
bio(620).sigAddress='&Robot_leg_3_B.Product2_ld[0]';
bio(620).ndims=2;
bio(620).size=[];
bio(620).isStruct=false;

bio(621).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Fn/Sum';
bio(621).sigName='';
bio(621).portIdx=0;
bio(621).dim=[1,1];
bio(621).sigWidth=1;
bio(621).sigAddress='&Robot_leg_3_B.Sum_jg';
bio(621).ndims=2;
bio(621).size=[];
bio(621).isStruct=false;

bio(622).blkName='Robot/Right_leg/Abduction Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(622).sigName='';
bio(622).portIdx=0;
bio(622).dim=[1,1];
bio(622).sigWidth=1;
bio(622).sigAddress='&Robot_leg_3_B.GAIN_hs';
bio(622).ndims=2;
bio(622).size=[];
bio(622).isStruct=false;

bio(623).blkName='Robot/Right_leg/Ankle Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(623).sigName='';
bio(623).portIdx=0;
bio(623).dim=[1,1];
bio(623).sigWidth=1;
bio(623).sigAddress='&Robot_leg_3_B.GAIN_h';
bio(623).ndims=2;
bio(623).size=[];
bio(623).isStruct=false;

bio(624).blkName='Robot/Right_leg/Ankle Twist Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(624).sigName='';
bio(624).portIdx=0;
bio(624).dim=[1,1];
bio(624).sigWidth=1;
bio(624).sigAddress='&Robot_leg_3_B.GAIN_e';
bio(624).ndims=2;
bio(624).size=[];
bio(624).isStruct=false;

bio(625).blkName='Robot/Right_leg/Hip Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(625).sigName='';
bio(625).portIdx=0;
bio(625).dim=[1,1];
bio(625).sigWidth=1;
bio(625).sigAddress='&Robot_leg_3_B.GAIN_i';
bio(625).ndims=2;
bio(625).size=[];
bio(625).isStruct=false;

bio(626).blkName='Robot/Right_leg/Knee Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(626).sigName='';
bio(626).portIdx=0;
bio(626).dim=[1,1];
bio(626).sigWidth=1;
bio(626).sigAddress='&Robot_leg_3_B.GAIN_d';
bio(626).ndims=2;
bio(626).size=[];
bio(626).isStruct=false;

bio(627).blkName='Robot/Right_leg/Rotation Meas/PS-Simulink Converter/EVAL_KEY/GAIN';
bio(627).sigName='';
bio(627).portIdx=0;
bio(627).dim=[1,1];
bio(627).sigWidth=1;
bio(627).sigAddress='&Robot_leg_3_B.GAIN_p';
bio(627).ndims=2;
bio(627).size=[];
bio(627).isStruct=false;

bio(628).blkName='Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Check loc x-axis/Compare';
bio(628).sigName='';
bio(628).portIdx=0;
bio(628).dim=[1,1];
bio(628).sigWidth=1;
bio(628).sigAddress='&Robot_leg_3_B.Compare';
bio(628).ndims=2;
bio(628).size=[];
bio(628).isStruct=false;

bio(629).blkName='Robot/Right_leg/Sphere to Plane Force/Check Sphere on Plane/Check loc y-axis/Compare';
bio(629).sigName='';
bio(629).portIdx=0;
bio(629).dim=[1,1];
bio(629).sigWidth=1;
bio(629).sigAddress='&Robot_leg_3_B.Compare_n';
bio(629).ndims=2;
bio(629).size=[];
bio(629).isStruct=false;

bio(630).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Calculate Penetration/Abs';
bio(630).sigName='';
bio(630).portIdx=0;
bio(630).dim=[1,1];
bio(630).sigWidth=1;
bio(630).sigAddress='&Robot_leg_3_B.Abs_a';
bio(630).ndims=2;
bio(630).size=[];
bio(630).isStruct=false;

bio(631).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Calculate Penetration/Dead Zone';
bio(631).sigName='';
bio(631).portIdx=0;
bio(631).dim=[1,1];
bio(631).sigWidth=1;
bio(631).sigAddress='&Robot_leg_3_B.DeadZone_e';
bio(631).ndims=2;
bio(631).size=[];
bio(631).isStruct=false;

bio(632).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Calculate Penetration/Gain2';
bio(632).sigName='';
bio(632).portIdx=0;
bio(632).dim=[1,1];
bio(632).sigWidth=1;
bio(632).sigAddress='&Robot_leg_3_B.Gain2_k';
bio(632).ndims=2;
bio(632).size=[];
bio(632).isStruct=false;

bio(633).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Calculate Penetration/Product';
bio(633).sigName='';
bio(633).portIdx=0;
bio(633).dim=[1,1];
bio(633).sigWidth=1;
bio(633).sigAddress='&Robot_leg_3_B.Product_br';
bio(633).ndims=2;
bio(633).size=[];
bio(633).isStruct=false;

bio(634).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Calculate Penetration/Sign vx';
bio(634).sigName='';
bio(634).portIdx=0;
bio(634).dim=[1,1];
bio(634).sigWidth=1;
bio(634).sigAddress='&Robot_leg_3_B.Signvx_e';
bio(634).ndims=2;
bio(634).size=[];
bio(634).isStruct=false;

bio(635).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Calculate Penetration/Sign x';
bio(635).sigName='';
bio(635).portIdx=0;
bio(635).dim=[1,1];
bio(635).sigWidth=1;
bio(635).sigAddress='&Robot_leg_3_B.Signx_h';
bio(635).ndims=2;
bio(635).size=[];
bio(635).isStruct=false;

bio(636).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Calculate Penetration/Sum';
bio(636).sigName='';
bio(636).portIdx=0;
bio(636).dim=[1,1];
bio(636).sigWidth=1;
bio(636).sigAddress='&Robot_leg_3_B.Sum_p0';
bio(636).ndims=2;
bio(636).size=[];
bio(636).isStruct=false;

bio(637).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Product';
bio(637).sigName='';
bio(637).portIdx=0;
bio(637).dim=[1,1];
bio(637).sigWidth=1;
bio(637).sigAddress='&Robot_leg_3_B.Product_np';
bio(637).ndims=2;
bio(637).size=[];
bio(637).isStruct=false;

bio(638).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Product1';
bio(638).sigName='';
bio(638).portIdx=0;
bio(638).dim=[1,1];
bio(638).sigWidth=1;
bio(638).sigAddress='&Robot_leg_3_B.Product1_cpr';
bio(638).ndims=2;
bio(638).size=[];
bio(638).isStruct=false;

bio(639).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Product2';
bio(639).sigName='';
bio(639).portIdx=0;
bio(639).dim=[1,1];
bio(639).sigWidth=1;
bio(639).sigAddress='&Robot_leg_3_B.Product2_i';
bio(639).ndims=2;
bio(639).size=[];
bio(639).isStruct=false;

bio(640).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Product3';
bio(640).sigName='';
bio(640).portIdx=0;
bio(640).dim=[1,1];
bio(640).sigWidth=1;
bio(640).sigAddress='&Robot_leg_3_B.Product3_gk';
bio(640).ndims=2;
bio(640).size=[];
bio(640).isStruct=false;

bio(641).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Product4';
bio(641).sigName='';
bio(641).portIdx=0;
bio(641).dim=[1,1];
bio(641).sigWidth=1;
bio(641).sigAddress='&Robot_leg_3_B.Product4_p4';
bio(641).ndims=2;
bio(641).size=[];
bio(641).isStruct=false;

bio(642).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Product5';
bio(642).sigName='';
bio(642).portIdx=0;
bio(642).dim=[1,1];
bio(642).sigWidth=1;
bio(642).sigAddress='&Robot_leg_3_B.Product5_k';
bio(642).ndims=2;
bio(642).size=[];
bio(642).isStruct=false;

bio(643).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Sum';
bio(643).sigName='';
bio(643).portIdx=0;
bio(643).dim=[12,1];
bio(643).sigWidth=12;
bio(643).sigAddress='&Robot_leg_3_B.FSph_i[0]';
bio(643).ndims=2;
bio(643).size=[];
bio(643).isStruct=false;

bio(644).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Sum1';
bio(644).sigName='';
bio(644).portIdx=0;
bio(644).dim=[12,1];
bio(644).sigWidth=12;
bio(644).sigAddress='&Robot_leg_3_B.FSph_i[0]';
bio(644).ndims=2;
bio(644).size=[];
bio(644).isStruct=false;

bio(645).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Cross Product/Sum2';
bio(645).sigName='';
bio(645).portIdx=0;
bio(645).dim=[12,1];
bio(645).sigWidth=12;
bio(645).sigAddress='&Robot_leg_3_B.FSph_i[0]';
bio(645).ndims=2;
bio(645).size=[];
bio(645).isStruct=false;

bio(646).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Gain';
bio(646).sigName='';
bio(646).portIdx=0;
bio(646).dim=[3,1];
bio(646).sigWidth=3;
bio(646).sigAddress='&Robot_leg_3_B.Gain_jd[0]';
bio(646).ndims=2;
bio(646).size=[];
bio(646).isStruct=false;

bio(647).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Product1';
bio(647).sigName='';
bio(647).portIdx=0;
bio(647).dim=[3,1];
bio(647).sigWidth=3;
bio(647).sigAddress='&Robot_leg_3_B.Product1_oi[0]';
bio(647).ndims=2;
bio(647).size=[];
bio(647).isStruct=false;

bio(648).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Product2';
bio(648).sigName='';
bio(648).portIdx=0;
bio(648).dim=[12,1];
bio(648).sigWidth=12;
bio(648).sigAddress='&Robot_leg_3_B.FSph_i[0]';
bio(648).ndims=2;
bio(648).size=[];
bio(648).isStruct=false;

bio(649).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Product3';
bio(649).sigName='';
bio(649).portIdx=0;
bio(649).dim=[1,1];
bio(649).sigWidth=1;
bio(649).sigAddress='&Robot_leg_3_B.Product3_l1';
bio(649).ndims=2;
bio(649).size=[];
bio(649).isStruct=false;

bio(650).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Product4';
bio(650).sigName='';
bio(650).portIdx=0;
bio(650).dim=[1,1];
bio(650).sigWidth=1;
bio(650).sigAddress='&Robot_leg_3_B.Product4_a';
bio(650).ndims=2;
bio(650).size=[];
bio(650).isStruct=false;

bio(651).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Product5';
bio(651).sigName='';
bio(651).portIdx=0;
bio(651).dim=[1,1];
bio(651).sigWidth=1;
bio(651).sigAddress='&Robot_leg_3_B.Product5_ij';
bio(651).ndims=2;
bio(651).size=[];
bio(651).isStruct=false;

bio(652).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Product6';
bio(652).sigName='';
bio(652).portIdx=0;
bio(652).dim=[1,1];
bio(652).sigWidth=1;
bio(652).sigAddress='&Robot_leg_3_B.Product6_l';
bio(652).ndims=2;
bio(652).size=[];
bio(652).isStruct=false;

bio(653).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Product7';
bio(653).sigName='';
bio(653).portIdx=0;
bio(653).dim=[3,1];
bio(653).sigWidth=3;
bio(653).sigAddress='&Robot_leg_3_B.Product7_b[0]';
bio(653).ndims=2;
bio(653).size=[];
bio(653).isStruct=false;

bio(654).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Trigonometric Function';
bio(654).sigName='';
bio(654).portIdx=0;
bio(654).dim=[1,1];
bio(654).sigWidth=1;
bio(654).sigAddress='&Robot_leg_3_B.TrigonometricFunction_c';
bio(654).ndims=2;
bio(654).size=[];
bio(654).isStruct=false;

bio(655).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Trigonometric Function1';
bio(655).sigName='';
bio(655).portIdx=0;
bio(655).dim=[1,1];
bio(655).sigWidth=1;
bio(655).sigAddress='&Robot_leg_3_B.TrigonometricFunction1_k';
bio(655).ndims=2;
bio(655).size=[];
bio(655).isStruct=false;

bio(656).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Fn/Gain';
bio(656).sigName='';
bio(656).portIdx=0;
bio(656).dim=[3,1];
bio(656).sigWidth=3;
bio(656).sigAddress='&Robot_leg_3_B.Gain_i[0]';
bio(656).ndims=2;
bio(656).size=[];
bio(656).isStruct=false;

bio(657).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Fn/Product2';
bio(657).sigName='';
bio(657).portIdx=0;
bio(657).dim=[3,1];
bio(657).sigWidth=3;
bio(657).sigAddress='&Robot_leg_3_B.Product2_j2[0]';
bio(657).ndims=2;
bio(657).size=[];
bio(657).isStruct=false;

bio(658).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Fn/Sum';
bio(658).sigName='';
bio(658).portIdx=0;
bio(658).dim=[1,1];
bio(658).sigWidth=1;
bio(658).sigAddress='&Robot_leg_3_B.Sum_kge';
bio(658).ndims=2;
bio(658).size=[];
bio(658).isStruct=false;

bio(659).blkName='Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Check loc x-axis/Compare';
bio(659).sigName='';
bio(659).portIdx=0;
bio(659).dim=[1,1];
bio(659).sigWidth=1;
bio(659).sigAddress='&Robot_leg_3_B.Compare_o';
bio(659).ndims=2;
bio(659).size=[];
bio(659).isStruct=false;

bio(660).blkName='Robot/Right_leg/Sphere to Plane Force1/Check Sphere on Plane/Check loc y-axis/Compare';
bio(660).sigName='';
bio(660).portIdx=0;
bio(660).dim=[1,1];
bio(660).sigWidth=1;
bio(660).sigAddress='&Robot_leg_3_B.Compare_m';
bio(660).ndims=2;
bio(660).size=[];
bio(660).isStruct=false;

bio(661).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Abs';
bio(661).sigName='';
bio(661).portIdx=0;
bio(661).dim=[1,1];
bio(661).sigWidth=1;
bio(661).sigAddress='&Robot_leg_3_B.Abs_db';
bio(661).ndims=2;
bio(661).size=[];
bio(661).isStruct=false;

bio(662).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Dead Zone';
bio(662).sigName='';
bio(662).portIdx=0;
bio(662).dim=[1,1];
bio(662).sigWidth=1;
bio(662).sigAddress='&Robot_leg_3_B.DeadZone_a';
bio(662).ndims=2;
bio(662).size=[];
bio(662).isStruct=false;

bio(663).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Gain2';
bio(663).sigName='';
bio(663).portIdx=0;
bio(663).dim=[1,1];
bio(663).sigWidth=1;
bio(663).sigAddress='&Robot_leg_3_B.Gain2_m';
bio(663).ndims=2;
bio(663).size=[];
bio(663).isStruct=false;

bio(664).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Product';
bio(664).sigName='';
bio(664).portIdx=0;
bio(664).dim=[1,1];
bio(664).sigWidth=1;
bio(664).sigAddress='&Robot_leg_3_B.Product_jh';
bio(664).ndims=2;
bio(664).size=[];
bio(664).isStruct=false;

bio(665).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Sign vx';
bio(665).sigName='';
bio(665).portIdx=0;
bio(665).dim=[1,1];
bio(665).sigWidth=1;
bio(665).sigAddress='&Robot_leg_3_B.Signvx_c';
bio(665).ndims=2;
bio(665).size=[];
bio(665).isStruct=false;

bio(666).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Sign x';
bio(666).sigName='';
bio(666).portIdx=0;
bio(666).dim=[1,1];
bio(666).sigWidth=1;
bio(666).sigAddress='&Robot_leg_3_B.Signx_o';
bio(666).ndims=2;
bio(666).size=[];
bio(666).isStruct=false;

bio(667).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Calculate Penetration/Sum';
bio(667).sigName='';
bio(667).portIdx=0;
bio(667).dim=[1,1];
bio(667).sigWidth=1;
bio(667).sigAddress='&Robot_leg_3_B.Sum_pm';
bio(667).ndims=2;
bio(667).size=[];
bio(667).isStruct=false;

bio(668).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Product';
bio(668).sigName='';
bio(668).portIdx=0;
bio(668).dim=[1,1];
bio(668).sigWidth=1;
bio(668).sigAddress='&Robot_leg_3_B.Product_o';
bio(668).ndims=2;
bio(668).size=[];
bio(668).isStruct=false;

bio(669).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Product1';
bio(669).sigName='';
bio(669).portIdx=0;
bio(669).dim=[1,1];
bio(669).sigWidth=1;
bio(669).sigAddress='&Robot_leg_3_B.Product1_k';
bio(669).ndims=2;
bio(669).size=[];
bio(669).isStruct=false;

bio(670).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Product2';
bio(670).sigName='';
bio(670).portIdx=0;
bio(670).dim=[1,1];
bio(670).sigWidth=1;
bio(670).sigAddress='&Robot_leg_3_B.Product2_h';
bio(670).ndims=2;
bio(670).size=[];
bio(670).isStruct=false;

bio(671).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Product3';
bio(671).sigName='';
bio(671).portIdx=0;
bio(671).dim=[1,1];
bio(671).sigWidth=1;
bio(671).sigAddress='&Robot_leg_3_B.Product3_n';
bio(671).ndims=2;
bio(671).size=[];
bio(671).isStruct=false;

bio(672).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Product4';
bio(672).sigName='';
bio(672).portIdx=0;
bio(672).dim=[1,1];
bio(672).sigWidth=1;
bio(672).sigAddress='&Robot_leg_3_B.Product4_ew';
bio(672).ndims=2;
bio(672).size=[];
bio(672).isStruct=false;

bio(673).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Product5';
bio(673).sigName='';
bio(673).portIdx=0;
bio(673).dim=[1,1];
bio(673).sigWidth=1;
bio(673).sigAddress='&Robot_leg_3_B.Product5_n';
bio(673).ndims=2;
bio(673).size=[];
bio(673).isStruct=false;

bio(674).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Sum';
bio(674).sigName='';
bio(674).portIdx=0;
bio(674).dim=[12,1];
bio(674).sigWidth=12;
bio(674).sigAddress='&Robot_leg_3_B.FSph_mf[0]';
bio(674).ndims=2;
bio(674).size=[];
bio(674).isStruct=false;

bio(675).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Sum1';
bio(675).sigName='';
bio(675).portIdx=0;
bio(675).dim=[12,1];
bio(675).sigWidth=12;
bio(675).sigAddress='&Robot_leg_3_B.FSph_mf[0]';
bio(675).ndims=2;
bio(675).size=[];
bio(675).isStruct=false;

bio(676).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Cross Product/Sum2';
bio(676).sigName='';
bio(676).portIdx=0;
bio(676).dim=[12,1];
bio(676).sigWidth=12;
bio(676).sigAddress='&Robot_leg_3_B.FSph_mf[0]';
bio(676).ndims=2;
bio(676).size=[];
bio(676).isStruct=false;

bio(677).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Gain';
bio(677).sigName='';
bio(677).portIdx=0;
bio(677).dim=[3,1];
bio(677).sigWidth=3;
bio(677).sigAddress='&Robot_leg_3_B.Gain_ph[0]';
bio(677).ndims=2;
bio(677).size=[];
bio(677).isStruct=false;

bio(678).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Product1';
bio(678).sigName='';
bio(678).portIdx=0;
bio(678).dim=[3,1];
bio(678).sigWidth=3;
bio(678).sigAddress='&Robot_leg_3_B.Product1_o[0]';
bio(678).ndims=2;
bio(678).size=[];
bio(678).isStruct=false;

bio(679).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Product2';
bio(679).sigName='';
bio(679).portIdx=0;
bio(679).dim=[12,1];
bio(679).sigWidth=12;
bio(679).sigAddress='&Robot_leg_3_B.FSph_mf[0]';
bio(679).ndims=2;
bio(679).size=[];
bio(679).isStruct=false;

bio(680).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Product3';
bio(680).sigName='';
bio(680).portIdx=0;
bio(680).dim=[1,1];
bio(680).sigWidth=1;
bio(680).sigAddress='&Robot_leg_3_B.Product3_gs';
bio(680).ndims=2;
bio(680).size=[];
bio(680).isStruct=false;

bio(681).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Product4';
bio(681).sigName='';
bio(681).portIdx=0;
bio(681).dim=[1,1];
bio(681).sigWidth=1;
bio(681).sigAddress='&Robot_leg_3_B.Product4_d';
bio(681).ndims=2;
bio(681).size=[];
bio(681).isStruct=false;

bio(682).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Product5';
bio(682).sigName='';
bio(682).portIdx=0;
bio(682).dim=[1,1];
bio(682).sigWidth=1;
bio(682).sigAddress='&Robot_leg_3_B.Product5_m';
bio(682).ndims=2;
bio(682).size=[];
bio(682).isStruct=false;

bio(683).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Product6';
bio(683).sigName='';
bio(683).portIdx=0;
bio(683).dim=[1,1];
bio(683).sigWidth=1;
bio(683).sigAddress='&Robot_leg_3_B.Product6_d';
bio(683).ndims=2;
bio(683).size=[];
bio(683).isStruct=false;

bio(684).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Product7';
bio(684).sigName='';
bio(684).portIdx=0;
bio(684).dim=[3,1];
bio(684).sigWidth=3;
bio(684).sigAddress='&Robot_leg_3_B.Product7_p[0]';
bio(684).ndims=2;
bio(684).size=[];
bio(684).isStruct=false;

bio(685).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Trigonometric Function';
bio(685).sigName='';
bio(685).portIdx=0;
bio(685).dim=[1,1];
bio(685).sigWidth=1;
bio(685).sigAddress='&Robot_leg_3_B.TrigonometricFunction_js';
bio(685).ndims=2;
bio(685).size=[];
bio(685).isStruct=false;

bio(686).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Trigonometric Function1';
bio(686).sigName='';
bio(686).portIdx=0;
bio(686).dim=[1,1];
bio(686).sigWidth=1;
bio(686).sigAddress='&Robot_leg_3_B.TrigonometricFunction1_o';
bio(686).ndims=2;
bio(686).size=[];
bio(686).isStruct=false;

bio(687).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Fn/Gain';
bio(687).sigName='';
bio(687).portIdx=0;
bio(687).dim=[3,1];
bio(687).sigWidth=3;
bio(687).sigAddress='&Robot_leg_3_B.Gain_a[0]';
bio(687).ndims=2;
bio(687).size=[];
bio(687).isStruct=false;

bio(688).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Fn/Product2';
bio(688).sigName='';
bio(688).portIdx=0;
bio(688).dim=[3,1];
bio(688).sigWidth=3;
bio(688).sigAddress='&Robot_leg_3_B.Product2_hxv[0]';
bio(688).ndims=2;
bio(688).size=[];
bio(688).isStruct=false;

bio(689).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Fn/Sum';
bio(689).sigName='';
bio(689).portIdx=0;
bio(689).dim=[1,1];
bio(689).sigWidth=1;
bio(689).sigAddress='&Robot_leg_3_B.Sum_o3';
bio(689).ndims=2;
bio(689).size=[];
bio(689).isStruct=false;

bio(690).blkName='Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Check loc x-axis/Compare';
bio(690).sigName='';
bio(690).portIdx=0;
bio(690).dim=[1,1];
bio(690).sigWidth=1;
bio(690).sigAddress='&Robot_leg_3_B.Compare_l';
bio(690).ndims=2;
bio(690).size=[];
bio(690).isStruct=false;

bio(691).blkName='Robot/Right_leg/Sphere to Plane Force2/Check Sphere on Plane/Check loc y-axis/Compare';
bio(691).sigName='';
bio(691).portIdx=0;
bio(691).dim=[1,1];
bio(691).sigWidth=1;
bio(691).sigAddress='&Robot_leg_3_B.Compare_g';
bio(691).ndims=2;
bio(691).size=[];
bio(691).isStruct=false;

bio(692).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Abs';
bio(692).sigName='';
bio(692).portIdx=0;
bio(692).dim=[1,1];
bio(692).sigWidth=1;
bio(692).sigAddress='&Robot_leg_3_B.Abs_i';
bio(692).ndims=2;
bio(692).size=[];
bio(692).isStruct=false;

bio(693).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Dead Zone';
bio(693).sigName='';
bio(693).portIdx=0;
bio(693).dim=[1,1];
bio(693).sigWidth=1;
bio(693).sigAddress='&Robot_leg_3_B.DeadZone_b';
bio(693).ndims=2;
bio(693).size=[];
bio(693).isStruct=false;

bio(694).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Gain2';
bio(694).sigName='';
bio(694).portIdx=0;
bio(694).dim=[1,1];
bio(694).sigWidth=1;
bio(694).sigAddress='&Robot_leg_3_B.Gain2_g';
bio(694).ndims=2;
bio(694).size=[];
bio(694).isStruct=false;

bio(695).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Product';
bio(695).sigName='';
bio(695).portIdx=0;
bio(695).dim=[1,1];
bio(695).sigWidth=1;
bio(695).sigAddress='&Robot_leg_3_B.Product_i';
bio(695).ndims=2;
bio(695).size=[];
bio(695).isStruct=false;

bio(696).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Sign vx';
bio(696).sigName='';
bio(696).portIdx=0;
bio(696).dim=[1,1];
bio(696).sigWidth=1;
bio(696).sigAddress='&Robot_leg_3_B.Signvx_a';
bio(696).ndims=2;
bio(696).size=[];
bio(696).isStruct=false;

bio(697).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Sign x';
bio(697).sigName='';
bio(697).portIdx=0;
bio(697).dim=[1,1];
bio(697).sigWidth=1;
bio(697).sigAddress='&Robot_leg_3_B.Signx_l';
bio(697).ndims=2;
bio(697).size=[];
bio(697).isStruct=false;

bio(698).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Calculate Penetration/Sum';
bio(698).sigName='';
bio(698).portIdx=0;
bio(698).dim=[1,1];
bio(698).sigWidth=1;
bio(698).sigAddress='&Robot_leg_3_B.Sum_lb';
bio(698).ndims=2;
bio(698).size=[];
bio(698).isStruct=false;

bio(699).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Product';
bio(699).sigName='';
bio(699).portIdx=0;
bio(699).dim=[1,1];
bio(699).sigWidth=1;
bio(699).sigAddress='&Robot_leg_3_B.Product_n';
bio(699).ndims=2;
bio(699).size=[];
bio(699).isStruct=false;

bio(700).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Product1';
bio(700).sigName='';
bio(700).portIdx=0;
bio(700).dim=[1,1];
bio(700).sigWidth=1;
bio(700).sigAddress='&Robot_leg_3_B.Product1_h';
bio(700).ndims=2;
bio(700).size=[];
bio(700).isStruct=false;

bio(701).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Product2';
bio(701).sigName='';
bio(701).portIdx=0;
bio(701).dim=[1,1];
bio(701).sigWidth=1;
bio(701).sigAddress='&Robot_leg_3_B.Product2_o';
bio(701).ndims=2;
bio(701).size=[];
bio(701).isStruct=false;

bio(702).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Product3';
bio(702).sigName='';
bio(702).portIdx=0;
bio(702).dim=[1,1];
bio(702).sigWidth=1;
bio(702).sigAddress='&Robot_leg_3_B.Product3_h';
bio(702).ndims=2;
bio(702).size=[];
bio(702).isStruct=false;

bio(703).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Product4';
bio(703).sigName='';
bio(703).portIdx=0;
bio(703).dim=[1,1];
bio(703).sigWidth=1;
bio(703).sigAddress='&Robot_leg_3_B.Product4_e';
bio(703).ndims=2;
bio(703).size=[];
bio(703).isStruct=false;

bio(704).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Product5';
bio(704).sigName='';
bio(704).portIdx=0;
bio(704).dim=[1,1];
bio(704).sigWidth=1;
bio(704).sigAddress='&Robot_leg_3_B.Product5_jd';
bio(704).ndims=2;
bio(704).size=[];
bio(704).isStruct=false;

bio(705).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Sum';
bio(705).sigName='';
bio(705).portIdx=0;
bio(705).dim=[12,1];
bio(705).sigWidth=12;
bio(705).sigAddress='&Robot_leg_3_B.FSph_a0[0]';
bio(705).ndims=2;
bio(705).size=[];
bio(705).isStruct=false;

bio(706).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Sum1';
bio(706).sigName='';
bio(706).portIdx=0;
bio(706).dim=[12,1];
bio(706).sigWidth=12;
bio(706).sigAddress='&Robot_leg_3_B.FSph_a0[0]';
bio(706).ndims=2;
bio(706).size=[];
bio(706).isStruct=false;

bio(707).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Cross Product/Sum2';
bio(707).sigName='';
bio(707).portIdx=0;
bio(707).dim=[12,1];
bio(707).sigWidth=12;
bio(707).sigAddress='&Robot_leg_3_B.FSph_a0[0]';
bio(707).ndims=2;
bio(707).size=[];
bio(707).isStruct=false;

bio(708).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Gain';
bio(708).sigName='';
bio(708).portIdx=0;
bio(708).dim=[3,1];
bio(708).sigWidth=3;
bio(708).sigAddress='&Robot_leg_3_B.Gain_cp[0]';
bio(708).ndims=2;
bio(708).size=[];
bio(708).isStruct=false;

bio(709).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Product1';
bio(709).sigName='';
bio(709).portIdx=0;
bio(709).dim=[3,1];
bio(709).sigWidth=3;
bio(709).sigAddress='&Robot_leg_3_B.Product1_cp[0]';
bio(709).ndims=2;
bio(709).size=[];
bio(709).isStruct=false;

bio(710).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Product2';
bio(710).sigName='';
bio(710).portIdx=0;
bio(710).dim=[12,1];
bio(710).sigWidth=12;
bio(710).sigAddress='&Robot_leg_3_B.FSph_a0[0]';
bio(710).ndims=2;
bio(710).size=[];
bio(710).isStruct=false;

bio(711).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Product3';
bio(711).sigName='';
bio(711).portIdx=0;
bio(711).dim=[1,1];
bio(711).sigWidth=1;
bio(711).sigAddress='&Robot_leg_3_B.Product3_l';
bio(711).ndims=2;
bio(711).size=[];
bio(711).isStruct=false;

bio(712).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Product4';
bio(712).sigName='';
bio(712).portIdx=0;
bio(712).dim=[1,1];
bio(712).sigWidth=1;
bio(712).sigAddress='&Robot_leg_3_B.Product4_po';
bio(712).ndims=2;
bio(712).size=[];
bio(712).isStruct=false;

bio(713).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Product5';
bio(713).sigName='';
bio(713).portIdx=0;
bio(713).dim=[1,1];
bio(713).sigWidth=1;
bio(713).sigAddress='&Robot_leg_3_B.Product5_ha';
bio(713).ndims=2;
bio(713).size=[];
bio(713).isStruct=false;

bio(714).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Product6';
bio(714).sigName='';
bio(714).portIdx=0;
bio(714).dim=[1,1];
bio(714).sigWidth=1;
bio(714).sigAddress='&Robot_leg_3_B.Product6_g';
bio(714).ndims=2;
bio(714).size=[];
bio(714).isStruct=false;

bio(715).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Product7';
bio(715).sigName='';
bio(715).portIdx=0;
bio(715).dim=[3,1];
bio(715).sigWidth=3;
bio(715).sigAddress='&Robot_leg_3_B.Product7_a[0]';
bio(715).ndims=2;
bio(715).size=[];
bio(715).isStruct=false;

bio(716).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Trigonometric Function';
bio(716).sigName='';
bio(716).portIdx=0;
bio(716).dim=[1,1];
bio(716).sigWidth=1;
bio(716).sigAddress='&Robot_leg_3_B.TrigonometricFunction_j';
bio(716).ndims=2;
bio(716).size=[];
bio(716).isStruct=false;

bio(717).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Trigonometric Function1';
bio(717).sigName='';
bio(717).portIdx=0;
bio(717).dim=[1,1];
bio(717).sigWidth=1;
bio(717).sigAddress='&Robot_leg_3_B.TrigonometricFunction1_g';
bio(717).ndims=2;
bio(717).size=[];
bio(717).isStruct=false;

bio(718).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Fn/Gain';
bio(718).sigName='';
bio(718).portIdx=0;
bio(718).dim=[3,1];
bio(718).sigWidth=3;
bio(718).sigAddress='&Robot_leg_3_B.Gain_c[0]';
bio(718).ndims=2;
bio(718).size=[];
bio(718).isStruct=false;

bio(719).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Fn/Product2';
bio(719).sigName='';
bio(719).portIdx=0;
bio(719).dim=[3,1];
bio(719).sigWidth=3;
bio(719).sigAddress='&Robot_leg_3_B.Product2_m[0]';
bio(719).ndims=2;
bio(719).size=[];
bio(719).isStruct=false;

bio(720).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Fn/Sum';
bio(720).sigName='';
bio(720).portIdx=0;
bio(720).dim=[1,1];
bio(720).sigWidth=1;
bio(720).sigAddress='&Robot_leg_3_B.Sum_kg';
bio(720).ndims=2;
bio(720).size=[];
bio(720).isStruct=false;

bio(721).blkName='Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Check loc x-axis/Compare';
bio(721).sigName='';
bio(721).portIdx=0;
bio(721).dim=[1,1];
bio(721).sigWidth=1;
bio(721).sigAddress='&Robot_leg_3_B.Compare_b';
bio(721).ndims=2;
bio(721).size=[];
bio(721).isStruct=false;

bio(722).blkName='Robot/Right_leg/Sphere to Plane Force3/Check Sphere on Plane/Check loc y-axis/Compare';
bio(722).sigName='';
bio(722).portIdx=0;
bio(722).dim=[1,1];
bio(722).sigWidth=1;
bio(722).sigAddress='&Robot_leg_3_B.Compare_f';
bio(722).ndims=2;
bio(722).size=[];
bio(722).isStruct=false;

bio(723).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Abs';
bio(723).sigName='';
bio(723).portIdx=0;
bio(723).dim=[1,1];
bio(723).sigWidth=1;
bio(723).sigAddress='&Robot_leg_3_B.Abs_c';
bio(723).ndims=2;
bio(723).size=[];
bio(723).isStruct=false;

bio(724).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Dead Zone';
bio(724).sigName='';
bio(724).portIdx=0;
bio(724).dim=[1,1];
bio(724).sigWidth=1;
bio(724).sigAddress='&Robot_leg_3_B.DeadZone';
bio(724).ndims=2;
bio(724).size=[];
bio(724).isStruct=false;

bio(725).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Gain2';
bio(725).sigName='';
bio(725).portIdx=0;
bio(725).dim=[1,1];
bio(725).sigWidth=1;
bio(725).sigAddress='&Robot_leg_3_B.Gain2';
bio(725).ndims=2;
bio(725).size=[];
bio(725).isStruct=false;

bio(726).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Product';
bio(726).sigName='';
bio(726).portIdx=0;
bio(726).dim=[1,1];
bio(726).sigWidth=1;
bio(726).sigAddress='&Robot_leg_3_B.Product_b';
bio(726).ndims=2;
bio(726).size=[];
bio(726).isStruct=false;

bio(727).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Sign vx';
bio(727).sigName='';
bio(727).portIdx=0;
bio(727).dim=[1,1];
bio(727).sigWidth=1;
bio(727).sigAddress='&Robot_leg_3_B.Signvx';
bio(727).ndims=2;
bio(727).size=[];
bio(727).isStruct=false;

bio(728).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Sign x';
bio(728).sigName='';
bio(728).portIdx=0;
bio(728).dim=[1,1];
bio(728).sigWidth=1;
bio(728).sigAddress='&Robot_leg_3_B.Signx';
bio(728).ndims=2;
bio(728).size=[];
bio(728).isStruct=false;

bio(729).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Calculate Penetration/Sum';
bio(729).sigName='';
bio(729).portIdx=0;
bio(729).dim=[1,1];
bio(729).sigWidth=1;
bio(729).sigAddress='&Robot_leg_3_B.Sum_mlb';
bio(729).ndims=2;
bio(729).size=[];
bio(729).isStruct=false;

bio(730).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Product';
bio(730).sigName='';
bio(730).portIdx=0;
bio(730).dim=[1,1];
bio(730).sigWidth=1;
bio(730).sigAddress='&Robot_leg_3_B.Product_jb';
bio(730).ndims=2;
bio(730).size=[];
bio(730).isStruct=false;

bio(731).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Product1';
bio(731).sigName='';
bio(731).portIdx=0;
bio(731).dim=[1,1];
bio(731).sigWidth=1;
bio(731).sigAddress='&Robot_leg_3_B.Product1';
bio(731).ndims=2;
bio(731).size=[];
bio(731).isStruct=false;

bio(732).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Product2';
bio(732).sigName='';
bio(732).portIdx=0;
bio(732).dim=[1,1];
bio(732).sigWidth=1;
bio(732).sigAddress='&Robot_leg_3_B.Product2';
bio(732).ndims=2;
bio(732).size=[];
bio(732).isStruct=false;

bio(733).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Product3';
bio(733).sigName='';
bio(733).portIdx=0;
bio(733).dim=[1,1];
bio(733).sigWidth=1;
bio(733).sigAddress='&Robot_leg_3_B.Product3_m';
bio(733).ndims=2;
bio(733).size=[];
bio(733).isStruct=false;

bio(734).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Product4';
bio(734).sigName='';
bio(734).portIdx=0;
bio(734).dim=[1,1];
bio(734).sigWidth=1;
bio(734).sigAddress='&Robot_leg_3_B.Product4_b';
bio(734).ndims=2;
bio(734).size=[];
bio(734).isStruct=false;

bio(735).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Product5';
bio(735).sigName='';
bio(735).portIdx=0;
bio(735).dim=[1,1];
bio(735).sigWidth=1;
bio(735).sigAddress='&Robot_leg_3_B.Product5_h';
bio(735).ndims=2;
bio(735).size=[];
bio(735).isStruct=false;

bio(736).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Sum';
bio(736).sigName='';
bio(736).portIdx=0;
bio(736).dim=[12,1];
bio(736).sigWidth=12;
bio(736).sigAddress='&Robot_leg_3_B.FSph_n[0]';
bio(736).ndims=2;
bio(736).size=[];
bio(736).isStruct=false;

bio(737).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Sum1';
bio(737).sigName='';
bio(737).portIdx=0;
bio(737).dim=[12,1];
bio(737).sigWidth=12;
bio(737).sigAddress='&Robot_leg_3_B.FSph_n[0]';
bio(737).ndims=2;
bio(737).size=[];
bio(737).isStruct=false;

bio(738).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Cross Product/Sum2';
bio(738).sigName='';
bio(738).portIdx=0;
bio(738).dim=[12,1];
bio(738).sigWidth=12;
bio(738).sigAddress='&Robot_leg_3_B.FSph_n[0]';
bio(738).ndims=2;
bio(738).size=[];
bio(738).isStruct=false;

bio(739).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Gain';
bio(739).sigName='';
bio(739).portIdx=0;
bio(739).dim=[3,1];
bio(739).sigWidth=3;
bio(739).sigAddress='&Robot_leg_3_B.Gain_b[0]';
bio(739).ndims=2;
bio(739).size=[];
bio(739).isStruct=false;

bio(740).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Product1';
bio(740).sigName='';
bio(740).portIdx=0;
bio(740).dim=[3,1];
bio(740).sigWidth=3;
bio(740).sigAddress='&Robot_leg_3_B.Product1_i[0]';
bio(740).ndims=2;
bio(740).size=[];
bio(740).isStruct=false;

bio(741).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Product2';
bio(741).sigName='';
bio(741).portIdx=0;
bio(741).dim=[12,1];
bio(741).sigWidth=12;
bio(741).sigAddress='&Robot_leg_3_B.FSph_n[0]';
bio(741).ndims=2;
bio(741).size=[];
bio(741).isStruct=false;

bio(742).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Product3';
bio(742).sigName='';
bio(742).portIdx=0;
bio(742).dim=[1,1];
bio(742).sigWidth=1;
bio(742).sigAddress='&Robot_leg_3_B.Product3_g';
bio(742).ndims=2;
bio(742).size=[];
bio(742).isStruct=false;

bio(743).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Product4';
bio(743).sigName='';
bio(743).portIdx=0;
bio(743).dim=[1,1];
bio(743).sigWidth=1;
bio(743).sigAddress='&Robot_leg_3_B.Product4_k';
bio(743).ndims=2;
bio(743).size=[];
bio(743).isStruct=false;

bio(744).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Product5';
bio(744).sigName='';
bio(744).portIdx=0;
bio(744).dim=[1,1];
bio(744).sigWidth=1;
bio(744).sigAddress='&Robot_leg_3_B.Product5';
bio(744).ndims=2;
bio(744).size=[];
bio(744).isStruct=false;

bio(745).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Product6';
bio(745).sigName='';
bio(745).portIdx=0;
bio(745).dim=[1,1];
bio(745).sigWidth=1;
bio(745).sigAddress='&Robot_leg_3_B.Product6';
bio(745).ndims=2;
bio(745).size=[];
bio(745).isStruct=false;

bio(746).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Product7';
bio(746).sigName='';
bio(746).portIdx=0;
bio(746).dim=[3,1];
bio(746).sigWidth=3;
bio(746).sigAddress='&Robot_leg_3_B.Product7[0]';
bio(746).ndims=2;
bio(746).size=[];
bio(746).isStruct=false;

bio(747).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Trigonometric Function';
bio(747).sigName='';
bio(747).portIdx=0;
bio(747).dim=[1,1];
bio(747).sigWidth=1;
bio(747).sigAddress='&Robot_leg_3_B.TrigonometricFunction_d';
bio(747).ndims=2;
bio(747).size=[];
bio(747).isStruct=false;

bio(748).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Trigonometric Function1';
bio(748).sigName='';
bio(748).portIdx=0;
bio(748).dim=[1,1];
bio(748).sigWidth=1;
bio(748).sigAddress='&Robot_leg_3_B.TrigonometricFunction1';
bio(748).ndims=2;
bio(748).size=[];
bio(748).isStruct=false;

bio(749).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Fn/Gain';
bio(749).sigName='';
bio(749).portIdx=0;
bio(749).dim=[3,1];
bio(749).sigWidth=3;
bio(749).sigAddress='&Robot_leg_3_B.Gain_mv[0]';
bio(749).ndims=2;
bio(749).size=[];
bio(749).isStruct=false;

bio(750).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Fn/Product2';
bio(750).sigName='';
bio(750).portIdx=0;
bio(750).dim=[3,1];
bio(750).sigWidth=3;
bio(750).sigAddress='&Robot_leg_3_B.Product2_j[0]';
bio(750).ndims=2;
bio(750).size=[];
bio(750).isStruct=false;

bio(751).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Fn/Sum';
bio(751).sigName='';
bio(751).portIdx=0;
bio(751).dim=[1,1];
bio(751).sigWidth=1;
bio(751).sigAddress='&Robot_leg_3_B.Sum_kn';
bio(751).ndims=2;
bio(751).size=[];
bio(751).isStruct=false;

bio(752).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product';
bio(752).sigName='';
bio(752).portIdx=0;
bio(752).dim=[1,1];
bio(752).sigWidth=1;
bio(752).sigAddress='&Robot_leg_3_B.Product_ms';
bio(752).ndims=2;
bio(752).size=[];
bio(752).isStruct=false;

bio(753).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product1';
bio(753).sigName='';
bio(753).portIdx=0;
bio(753).dim=[1,1];
bio(753).sigWidth=1;
bio(753).sigAddress='&Robot_leg_3_B.Product1_kj';
bio(753).ndims=2;
bio(753).size=[];
bio(753).isStruct=false;

bio(754).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product2';
bio(754).sigName='';
bio(754).portIdx=0;
bio(754).dim=[1,1];
bio(754).sigWidth=1;
bio(754).sigAddress='&Robot_leg_3_B.Product2_i1';
bio(754).ndims=2;
bio(754).size=[];
bio(754).isStruct=false;

bio(755).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product3';
bio(755).sigName='';
bio(755).portIdx=0;
bio(755).dim=[1,1];
bio(755).sigWidth=1;
bio(755).sigAddress='&Robot_leg_3_B.Product3_ny';
bio(755).ndims=2;
bio(755).size=[];
bio(755).isStruct=false;

bio(756).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product4';
bio(756).sigName='';
bio(756).portIdx=0;
bio(756).dim=[1,1];
bio(756).sigWidth=1;
bio(756).sigAddress='&Robot_leg_3_B.Product4_d1';
bio(756).ndims=2;
bio(756).size=[];
bio(756).isStruct=false;

bio(757).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product5';
bio(757).sigName='';
bio(757).portIdx=0;
bio(757).dim=[1,1];
bio(757).sigWidth=1;
bio(757).sigAddress='&Robot_leg_3_B.Product5_i3';
bio(757).ndims=2;
bio(757).size=[];
bio(757).isStruct=false;

bio(758).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Sum';
bio(758).sigName='';
bio(758).portIdx=0;
bio(758).dim=[1,1];
bio(758).sigWidth=1;
bio(758).sigAddress='&Robot_leg_3_B.Sum_iwg';
bio(758).ndims=2;
bio(758).size=[];
bio(758).isStruct=false;

bio(759).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Sum1';
bio(759).sigName='';
bio(759).portIdx=0;
bio(759).dim=[1,1];
bio(759).sigWidth=1;
bio(759).sigAddress='&Robot_leg_3_B.Sum1_f';
bio(759).ndims=2;
bio(759).size=[];
bio(759).isStruct=false;

bio(760).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Sum2';
bio(760).sigName='';
bio(760).portIdx=0;
bio(760).dim=[1,1];
bio(760).sigWidth=1;
bio(760).sigAddress='&Robot_leg_3_B.Sum2_k';
bio(760).ndims=2;
bio(760).size=[];
bio(760).isStruct=false;

bio(761).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Math Function';
bio(761).sigName='';
bio(761).portIdx=0;
bio(761).dim=[1,1];
bio(761).sigWidth=1;
bio(761).sigAddress='&Robot_leg_3_B.MathFunction_gn';
bio(761).ndims=2;
bio(761).size=[];
bio(761).isStruct=false;

bio(762).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Math Function1';
bio(762).sigName='';
bio(762).portIdx=0;
bio(762).dim=[1,1];
bio(762).sigWidth=1;
bio(762).sigAddress='&Robot_leg_3_B.MathFunction1_aw';
bio(762).ndims=2;
bio(762).size=[];
bio(762).isStruct=false;

bio(763).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Product3';
bio(763).sigName='';
bio(763).portIdx=0;
bio(763).dim=[1,1];
bio(763).sigWidth=1;
bio(763).sigAddress='&Robot_leg_3_B.Product3_nd';
bio(763).ndims=2;
bio(763).size=[];
bio(763).isStruct=false;

bio(764).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Product4';
bio(764).sigName='';
bio(764).portIdx=0;
bio(764).dim=[1,1];
bio(764).sigWidth=1;
bio(764).sigAddress='&Robot_leg_3_B.Product4_m';
bio(764).ndims=2;
bio(764).size=[];
bio(764).isStruct=false;

bio(765).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Sum1';
bio(765).sigName='slipy';
bio(765).portIdx=0;
bio(765).dim=[1,1];
bio(765).sigWidth=1;
bio(765).sigAddress='&Robot_leg_3_B.slipy_j';
bio(765).ndims=2;
bio(765).size=[];
bio(765).isStruct=false;

bio(766).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Sum2';
bio(766).sigName='slipx';
bio(766).portIdx=0;
bio(766).dim=[1,1];
bio(766).sigWidth=1;
bio(766).sigAddress='&Robot_leg_3_B.slipx_p';
bio(766).ndims=2;
bio(766).size=[];
bio(766).isStruct=false;

bio(767).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Sum3';
bio(767).sigName='';
bio(767).portIdx=0;
bio(767).dim=[1,1];
bio(767).sigWidth=1;
bio(767).sigAddress='&Robot_leg_3_B.Sum3_dn';
bio(767).ndims=2;
bio(767).size=[];
bio(767).isStruct=false;

bio(768).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Trigonometric Function';
bio(768).sigName='';
bio(768).portIdx=0;
bio(768).dim=[1,1];
bio(768).sigWidth=1;
bio(768).sigAddress='&Robot_leg_3_B.TrigonometricFunction_pg';
bio(768).ndims=2;
bio(768).size=[];
bio(768).isStruct=false;

bio(769).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Sqrt';
bio(769).sigName='';
bio(769).portIdx=0;
bio(769).dim=[1,1];
bio(769).sigWidth=1;
bio(769).sigAddress='&Robot_leg_3_B.Sqrt_o';
bio(769).ndims=2;
bio(769).size=[];
bio(769).isStruct=false;

bio(770).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Linear/Abs';
bio(770).sigName='Damping_Force_Enable';
bio(770).portIdx=0;
bio(770).dim=[1,1];
bio(770).sigWidth=1;
bio(770).sigAddress='&Robot_leg_3_B.Damping_Force_Enable_o';
bio(770).ndims=2;
bio(770).size=[];
bio(770).isStruct=false;

bio(771).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Linear/Gain1';
bio(771).sigName='Stiffness_Force';
bio(771).portIdx=0;
bio(771).dim=[1,1];
bio(771).sigWidth=1;
bio(771).sigAddress='&Robot_leg_3_B.Stiffness_Force_k0';
bio(771).ndims=2;
bio(771).size=[];
bio(771).isStruct=false;

bio(772).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Linear/Gain2';
bio(772).sigName='Damping_Force';
bio(772).portIdx=0;
bio(772).dim=[1,1];
bio(772).sigWidth=1;
bio(772).sigAddress='&Robot_leg_3_B.Damping_Force_l';
bio(772).ndims=2;
bio(772).size=[];
bio(772).isStruct=false;

bio(773).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Linear/Product';
bio(773).sigName='Damping_Force';
bio(773).portIdx=0;
bio(773).dim=[1,1];
bio(773).sigWidth=1;
bio(773).sigAddress='&Robot_leg_3_B.Damping_Force_d2';
bio(773).ndims=2;
bio(773).size=[];
bio(773).isStruct=false;

bio(774).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Linear/Saturation';
bio(774).sigName='';
bio(774).portIdx=0;
bio(774).dim=[1,1];
bio(774).sigWidth=1;
bio(774).sigAddress='&Robot_leg_3_B.Saturation_dc';
bio(774).ndims=2;
bio(774).size=[];
bio(774).isStruct=false;

bio(775).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Force Law/Linear/Sign';
bio(775).sigName='';
bio(775).portIdx=0;
bio(775).dim=[1,1];
bio(775).sigWidth=1;
bio(775).sigAddress='&Robot_leg_3_B.Sign_kv';
bio(775).ndims=2;
bio(775).size=[];
bio(775).isStruct=false;

bio(776).blkName='Robot/Left_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter2/EVAL_KEY/RESHAPE';
bio(776).sigName='';
bio(776).portIdx=0;
bio(776).dim=[3,3];
bio(776).sigWidth=9;
bio(776).sigAddress='&Robot_leg_3_B.RESHAPE_l[0]';
bio(776).ndims=2;
bio(776).size=[];
bio(776).isStruct=false;

bio(777).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product';
bio(777).sigName='';
bio(777).portIdx=0;
bio(777).dim=[1,1];
bio(777).sigWidth=1;
bio(777).sigAddress='&Robot_leg_3_B.Product_n4';
bio(777).ndims=2;
bio(777).size=[];
bio(777).isStruct=false;

bio(778).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product1';
bio(778).sigName='';
bio(778).portIdx=0;
bio(778).dim=[1,1];
bio(778).sigWidth=1;
bio(778).sigAddress='&Robot_leg_3_B.Product1_g';
bio(778).ndims=2;
bio(778).size=[];
bio(778).isStruct=false;

bio(779).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product2';
bio(779).sigName='';
bio(779).portIdx=0;
bio(779).dim=[1,1];
bio(779).sigWidth=1;
bio(779).sigAddress='&Robot_leg_3_B.Product2_ox';
bio(779).ndims=2;
bio(779).size=[];
bio(779).isStruct=false;

bio(780).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product3';
bio(780).sigName='';
bio(780).portIdx=0;
bio(780).dim=[1,1];
bio(780).sigWidth=1;
bio(780).sigAddress='&Robot_leg_3_B.Product3_in';
bio(780).ndims=2;
bio(780).size=[];
bio(780).isStruct=false;

bio(781).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product4';
bio(781).sigName='';
bio(781).portIdx=0;
bio(781).dim=[1,1];
bio(781).sigWidth=1;
bio(781).sigAddress='&Robot_leg_3_B.Product4_fk';
bio(781).ndims=2;
bio(781).size=[];
bio(781).isStruct=false;

bio(782).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product5';
bio(782).sigName='';
bio(782).portIdx=0;
bio(782).dim=[1,1];
bio(782).sigWidth=1;
bio(782).sigAddress='&Robot_leg_3_B.Product5_id';
bio(782).ndims=2;
bio(782).size=[];
bio(782).isStruct=false;

bio(783).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Sum';
bio(783).sigName='';
bio(783).portIdx=0;
bio(783).dim=[1,1];
bio(783).sigWidth=1;
bio(783).sigAddress='&Robot_leg_3_B.Sum_d0';
bio(783).ndims=2;
bio(783).size=[];
bio(783).isStruct=false;

bio(784).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Sum1';
bio(784).sigName='';
bio(784).portIdx=0;
bio(784).dim=[1,1];
bio(784).sigWidth=1;
bio(784).sigAddress='&Robot_leg_3_B.Sum1_o';
bio(784).ndims=2;
bio(784).size=[];
bio(784).isStruct=false;

bio(785).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Sum2';
bio(785).sigName='';
bio(785).portIdx=0;
bio(785).dim=[1,1];
bio(785).sigWidth=1;
bio(785).sigAddress='&Robot_leg_3_B.Sum2_j';
bio(785).ndims=2;
bio(785).size=[];
bio(785).isStruct=false;

bio(786).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Math Function';
bio(786).sigName='';
bio(786).portIdx=0;
bio(786).dim=[1,1];
bio(786).sigWidth=1;
bio(786).sigAddress='&Robot_leg_3_B.MathFunction_ke';
bio(786).ndims=2;
bio(786).size=[];
bio(786).isStruct=false;

bio(787).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Math Function1';
bio(787).sigName='';
bio(787).portIdx=0;
bio(787).dim=[1,1];
bio(787).sigWidth=1;
bio(787).sigAddress='&Robot_leg_3_B.MathFunction1_p';
bio(787).ndims=2;
bio(787).size=[];
bio(787).isStruct=false;

bio(788).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Product3';
bio(788).sigName='';
bio(788).portIdx=0;
bio(788).dim=[1,1];
bio(788).sigWidth=1;
bio(788).sigAddress='&Robot_leg_3_B.Product3_c3';
bio(788).ndims=2;
bio(788).size=[];
bio(788).isStruct=false;

bio(789).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Product4';
bio(789).sigName='';
bio(789).portIdx=0;
bio(789).dim=[1,1];
bio(789).sigWidth=1;
bio(789).sigAddress='&Robot_leg_3_B.Product4_bh';
bio(789).ndims=2;
bio(789).size=[];
bio(789).isStruct=false;

bio(790).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Sum1';
bio(790).sigName='slipy';
bio(790).portIdx=0;
bio(790).dim=[1,1];
bio(790).sigWidth=1;
bio(790).sigAddress='&Robot_leg_3_B.slipy_n';
bio(790).ndims=2;
bio(790).size=[];
bio(790).isStruct=false;

bio(791).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Sum2';
bio(791).sigName='slipx';
bio(791).portIdx=0;
bio(791).dim=[1,1];
bio(791).sigWidth=1;
bio(791).sigAddress='&Robot_leg_3_B.slipx_f';
bio(791).ndims=2;
bio(791).size=[];
bio(791).isStruct=false;

bio(792).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Sum3';
bio(792).sigName='';
bio(792).portIdx=0;
bio(792).dim=[1,1];
bio(792).sigWidth=1;
bio(792).sigAddress='&Robot_leg_3_B.Sum3_g';
bio(792).ndims=2;
bio(792).size=[];
bio(792).isStruct=false;

bio(793).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Trigonometric Function';
bio(793).sigName='';
bio(793).portIdx=0;
bio(793).dim=[1,1];
bio(793).sigWidth=1;
bio(793).sigAddress='&Robot_leg_3_B.TrigonometricFunction_f';
bio(793).ndims=2;
bio(793).size=[];
bio(793).isStruct=false;

bio(794).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Sqrt';
bio(794).sigName='';
bio(794).portIdx=0;
bio(794).dim=[1,1];
bio(794).sigWidth=1;
bio(794).sigAddress='&Robot_leg_3_B.Sqrt_d';
bio(794).ndims=2;
bio(794).size=[];
bio(794).isStruct=false;

bio(795).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Abs';
bio(795).sigName='Damping_Force_Enable';
bio(795).portIdx=0;
bio(795).dim=[1,1];
bio(795).sigWidth=1;
bio(795).sigAddress='&Robot_leg_3_B.Damping_Force_Enable_i';
bio(795).ndims=2;
bio(795).size=[];
bio(795).isStruct=false;

bio(796).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Gain1';
bio(796).sigName='Stiffness_Force';
bio(796).portIdx=0;
bio(796).dim=[1,1];
bio(796).sigWidth=1;
bio(796).sigAddress='&Robot_leg_3_B.Stiffness_Force_kw';
bio(796).ndims=2;
bio(796).size=[];
bio(796).isStruct=false;

bio(797).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Gain2';
bio(797).sigName='Damping_Force';
bio(797).portIdx=0;
bio(797).dim=[1,1];
bio(797).sigWidth=1;
bio(797).sigAddress='&Robot_leg_3_B.Damping_Force_mh';
bio(797).ndims=2;
bio(797).size=[];
bio(797).isStruct=false;

bio(798).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Product';
bio(798).sigName='Damping_Force';
bio(798).portIdx=0;
bio(798).dim=[1,1];
bio(798).sigWidth=1;
bio(798).sigAddress='&Robot_leg_3_B.Damping_Force_g';
bio(798).ndims=2;
bio(798).size=[];
bio(798).isStruct=false;

bio(799).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Saturation';
bio(799).sigName='';
bio(799).portIdx=0;
bio(799).dim=[1,1];
bio(799).sigWidth=1;
bio(799).sigAddress='&Robot_leg_3_B.Saturation_el';
bio(799).ndims=2;
bio(799).size=[];
bio(799).isStruct=false;

bio(800).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Sign';
bio(800).sigName='';
bio(800).portIdx=0;
bio(800).dim=[1,1];
bio(800).sigWidth=1;
bio(800).sigAddress='&Robot_leg_3_B.Sign_g';
bio(800).ndims=2;
bio(800).size=[];
bio(800).isStruct=false;

bio(801).blkName='Robot/Left_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter2/EVAL_KEY/RESHAPE';
bio(801).sigName='';
bio(801).portIdx=0;
bio(801).dim=[3,3];
bio(801).sigWidth=9;
bio(801).sigAddress='&Robot_leg_3_B.RESHAPE_b[0]';
bio(801).ndims=2;
bio(801).size=[];
bio(801).isStruct=false;

bio(802).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product';
bio(802).sigName='';
bio(802).portIdx=0;
bio(802).dim=[1,1];
bio(802).sigWidth=1;
bio(802).sigAddress='&Robot_leg_3_B.Product_j2';
bio(802).ndims=2;
bio(802).size=[];
bio(802).isStruct=false;

bio(803).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product1';
bio(803).sigName='';
bio(803).portIdx=0;
bio(803).dim=[1,1];
bio(803).sigWidth=1;
bio(803).sigAddress='&Robot_leg_3_B.Product1_f';
bio(803).ndims=2;
bio(803).size=[];
bio(803).isStruct=false;

bio(804).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product2';
bio(804).sigName='';
bio(804).portIdx=0;
bio(804).dim=[1,1];
bio(804).sigWidth=1;
bio(804).sigAddress='&Robot_leg_3_B.Product2_hu';
bio(804).ndims=2;
bio(804).size=[];
bio(804).isStruct=false;

bio(805).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product3';
bio(805).sigName='';
bio(805).portIdx=0;
bio(805).dim=[1,1];
bio(805).sigWidth=1;
bio(805).sigAddress='&Robot_leg_3_B.Product3_b';
bio(805).ndims=2;
bio(805).size=[];
bio(805).isStruct=false;

bio(806).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product4';
bio(806).sigName='';
bio(806).portIdx=0;
bio(806).dim=[1,1];
bio(806).sigWidth=1;
bio(806).sigAddress='&Robot_leg_3_B.Product4_ad';
bio(806).ndims=2;
bio(806).size=[];
bio(806).isStruct=false;

bio(807).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product5';
bio(807).sigName='';
bio(807).portIdx=0;
bio(807).dim=[1,1];
bio(807).sigWidth=1;
bio(807).sigAddress='&Robot_leg_3_B.Product5_gd';
bio(807).ndims=2;
bio(807).size=[];
bio(807).isStruct=false;

bio(808).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Sum';
bio(808).sigName='';
bio(808).portIdx=0;
bio(808).dim=[1,1];
bio(808).sigWidth=1;
bio(808).sigAddress='&Robot_leg_3_B.Sum_ec';
bio(808).ndims=2;
bio(808).size=[];
bio(808).isStruct=false;

bio(809).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Sum1';
bio(809).sigName='';
bio(809).portIdx=0;
bio(809).dim=[1,1];
bio(809).sigWidth=1;
bio(809).sigAddress='&Robot_leg_3_B.Sum1_cv';
bio(809).ndims=2;
bio(809).size=[];
bio(809).isStruct=false;

bio(810).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Sum2';
bio(810).sigName='';
bio(810).portIdx=0;
bio(810).dim=[1,1];
bio(810).sigWidth=1;
bio(810).sigAddress='&Robot_leg_3_B.Sum2_n';
bio(810).ndims=2;
bio(810).size=[];
bio(810).isStruct=false;

bio(811).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Math Function';
bio(811).sigName='';
bio(811).portIdx=0;
bio(811).dim=[1,1];
bio(811).sigWidth=1;
bio(811).sigAddress='&Robot_leg_3_B.MathFunction_hr';
bio(811).ndims=2;
bio(811).size=[];
bio(811).isStruct=false;

bio(812).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Math Function1';
bio(812).sigName='';
bio(812).portIdx=0;
bio(812).dim=[1,1];
bio(812).sigWidth=1;
bio(812).sigAddress='&Robot_leg_3_B.MathFunction1_a2';
bio(812).ndims=2;
bio(812).size=[];
bio(812).isStruct=false;

bio(813).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Product3';
bio(813).sigName='';
bio(813).portIdx=0;
bio(813).dim=[1,1];
bio(813).sigWidth=1;
bio(813).sigAddress='&Robot_leg_3_B.Product3_ao';
bio(813).ndims=2;
bio(813).size=[];
bio(813).isStruct=false;

bio(814).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Product4';
bio(814).sigName='';
bio(814).portIdx=0;
bio(814).dim=[1,1];
bio(814).sigWidth=1;
bio(814).sigAddress='&Robot_leg_3_B.Product4_a5';
bio(814).ndims=2;
bio(814).size=[];
bio(814).isStruct=false;

bio(815).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Sum1';
bio(815).sigName='slipy';
bio(815).portIdx=0;
bio(815).dim=[1,1];
bio(815).sigWidth=1;
bio(815).sigAddress='&Robot_leg_3_B.slipy_o';
bio(815).ndims=2;
bio(815).size=[];
bio(815).isStruct=false;

bio(816).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Sum2';
bio(816).sigName='slipx';
bio(816).portIdx=0;
bio(816).dim=[1,1];
bio(816).sigWidth=1;
bio(816).sigAddress='&Robot_leg_3_B.slipx_l';
bio(816).ndims=2;
bio(816).size=[];
bio(816).isStruct=false;

bio(817).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Sum3';
bio(817).sigName='';
bio(817).portIdx=0;
bio(817).dim=[1,1];
bio(817).sigWidth=1;
bio(817).sigAddress='&Robot_leg_3_B.Sum3_a';
bio(817).ndims=2;
bio(817).size=[];
bio(817).isStruct=false;

bio(818).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Trigonometric Function';
bio(818).sigName='';
bio(818).portIdx=0;
bio(818).dim=[1,1];
bio(818).sigWidth=1;
bio(818).sigAddress='&Robot_leg_3_B.TrigonometricFunction_pt';
bio(818).ndims=2;
bio(818).size=[];
bio(818).isStruct=false;

bio(819).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Sqrt';
bio(819).sigName='';
bio(819).portIdx=0;
bio(819).dim=[1,1];
bio(819).sigWidth=1;
bio(819).sigAddress='&Robot_leg_3_B.Sqrt_h';
bio(819).ndims=2;
bio(819).size=[];
bio(819).isStruct=false;

bio(820).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Abs';
bio(820).sigName='Damping_Force_Enable';
bio(820).portIdx=0;
bio(820).dim=[1,1];
bio(820).sigWidth=1;
bio(820).sigAddress='&Robot_leg_3_B.Damping_Force_Enable_df';
bio(820).ndims=2;
bio(820).size=[];
bio(820).isStruct=false;

bio(821).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Gain1';
bio(821).sigName='Stiffness_Force';
bio(821).portIdx=0;
bio(821).dim=[1,1];
bio(821).sigWidth=1;
bio(821).sigAddress='&Robot_leg_3_B.Stiffness_Force_kv';
bio(821).ndims=2;
bio(821).size=[];
bio(821).isStruct=false;

bio(822).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Gain2';
bio(822).sigName='Damping_Force';
bio(822).portIdx=0;
bio(822).dim=[1,1];
bio(822).sigWidth=1;
bio(822).sigAddress='&Robot_leg_3_B.Damping_Force_m';
bio(822).ndims=2;
bio(822).size=[];
bio(822).isStruct=false;

bio(823).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Product';
bio(823).sigName='Damping_Force';
bio(823).portIdx=0;
bio(823).dim=[1,1];
bio(823).sigWidth=1;
bio(823).sigAddress='&Robot_leg_3_B.Damping_Force_a';
bio(823).ndims=2;
bio(823).size=[];
bio(823).isStruct=false;

bio(824).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Saturation';
bio(824).sigName='';
bio(824).portIdx=0;
bio(824).dim=[1,1];
bio(824).sigWidth=1;
bio(824).sigAddress='&Robot_leg_3_B.Saturation_d';
bio(824).ndims=2;
bio(824).size=[];
bio(824).isStruct=false;

bio(825).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Sign';
bio(825).sigName='';
bio(825).portIdx=0;
bio(825).dim=[1,1];
bio(825).sigWidth=1;
bio(825).sigAddress='&Robot_leg_3_B.Sign_m';
bio(825).ndims=2;
bio(825).size=[];
bio(825).isStruct=false;

bio(826).blkName='Robot/Left_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter2/EVAL_KEY/RESHAPE';
bio(826).sigName='';
bio(826).portIdx=0;
bio(826).dim=[3,3];
bio(826).sigWidth=9;
bio(826).sigAddress='&Robot_leg_3_B.RESHAPE_j1[0]';
bio(826).ndims=2;
bio(826).size=[];
bio(826).isStruct=false;

bio(827).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product';
bio(827).sigName='';
bio(827).portIdx=0;
bio(827).dim=[1,1];
bio(827).sigWidth=1;
bio(827).sigAddress='&Robot_leg_3_B.Product_pw';
bio(827).ndims=2;
bio(827).size=[];
bio(827).isStruct=false;

bio(828).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product1';
bio(828).sigName='';
bio(828).portIdx=0;
bio(828).dim=[1,1];
bio(828).sigWidth=1;
bio(828).sigAddress='&Robot_leg_3_B.Product1_a';
bio(828).ndims=2;
bio(828).size=[];
bio(828).isStruct=false;

bio(829).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product2';
bio(829).sigName='';
bio(829).portIdx=0;
bio(829).dim=[1,1];
bio(829).sigWidth=1;
bio(829).sigAddress='&Robot_leg_3_B.Product2_l';
bio(829).ndims=2;
bio(829).size=[];
bio(829).isStruct=false;

bio(830).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product3';
bio(830).sigName='';
bio(830).portIdx=0;
bio(830).dim=[1,1];
bio(830).sigWidth=1;
bio(830).sigAddress='&Robot_leg_3_B.Product3_c';
bio(830).ndims=2;
bio(830).size=[];
bio(830).isStruct=false;

bio(831).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product4';
bio(831).sigName='';
bio(831).portIdx=0;
bio(831).dim=[1,1];
bio(831).sigWidth=1;
bio(831).sigAddress='&Robot_leg_3_B.Product4_iy';
bio(831).ndims=2;
bio(831).size=[];
bio(831).isStruct=false;

bio(832).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product5';
bio(832).sigName='';
bio(832).portIdx=0;
bio(832).dim=[1,1];
bio(832).sigWidth=1;
bio(832).sigAddress='&Robot_leg_3_B.Product5_g';
bio(832).ndims=2;
bio(832).size=[];
bio(832).isStruct=false;

bio(833).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Sum';
bio(833).sigName='';
bio(833).portIdx=0;
bio(833).dim=[1,1];
bio(833).sigWidth=1;
bio(833).sigAddress='&Robot_leg_3_B.Sum_ein';
bio(833).ndims=2;
bio(833).size=[];
bio(833).isStruct=false;

bio(834).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Sum1';
bio(834).sigName='';
bio(834).portIdx=0;
bio(834).dim=[1,1];
bio(834).sigWidth=1;
bio(834).sigAddress='&Robot_leg_3_B.Sum1_ck';
bio(834).ndims=2;
bio(834).size=[];
bio(834).isStruct=false;

bio(835).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Sum2';
bio(835).sigName='';
bio(835).portIdx=0;
bio(835).dim=[1,1];
bio(835).sigWidth=1;
bio(835).sigAddress='&Robot_leg_3_B.Sum2_g';
bio(835).ndims=2;
bio(835).size=[];
bio(835).isStruct=false;

bio(836).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Math Function';
bio(836).sigName='';
bio(836).portIdx=0;
bio(836).dim=[1,1];
bio(836).sigWidth=1;
bio(836).sigAddress='&Robot_leg_3_B.MathFunction_pq';
bio(836).ndims=2;
bio(836).size=[];
bio(836).isStruct=false;

bio(837).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Math Function1';
bio(837).sigName='';
bio(837).portIdx=0;
bio(837).dim=[1,1];
bio(837).sigWidth=1;
bio(837).sigAddress='&Robot_leg_3_B.MathFunction1_m';
bio(837).ndims=2;
bio(837).size=[];
bio(837).isStruct=false;

bio(838).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Product3';
bio(838).sigName='';
bio(838).portIdx=0;
bio(838).dim=[1,1];
bio(838).sigWidth=1;
bio(838).sigAddress='&Robot_leg_3_B.Product3_j';
bio(838).ndims=2;
bio(838).size=[];
bio(838).isStruct=false;

bio(839).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Product4';
bio(839).sigName='';
bio(839).portIdx=0;
bio(839).dim=[1,1];
bio(839).sigWidth=1;
bio(839).sigAddress='&Robot_leg_3_B.Product4_i';
bio(839).ndims=2;
bio(839).size=[];
bio(839).isStruct=false;

bio(840).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Sum1';
bio(840).sigName='slipy';
bio(840).portIdx=0;
bio(840).dim=[1,1];
bio(840).sigWidth=1;
bio(840).sigAddress='&Robot_leg_3_B.slipy_h';
bio(840).ndims=2;
bio(840).size=[];
bio(840).isStruct=false;

bio(841).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Sum2';
bio(841).sigName='slipx';
bio(841).portIdx=0;
bio(841).dim=[1,1];
bio(841).sigWidth=1;
bio(841).sigAddress='&Robot_leg_3_B.slipx_m';
bio(841).ndims=2;
bio(841).size=[];
bio(841).isStruct=false;

bio(842).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Sum3';
bio(842).sigName='';
bio(842).portIdx=0;
bio(842).dim=[1,1];
bio(842).sigWidth=1;
bio(842).sigAddress='&Robot_leg_3_B.Sum3_c';
bio(842).ndims=2;
bio(842).size=[];
bio(842).isStruct=false;

bio(843).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Trigonometric Function';
bio(843).sigName='';
bio(843).portIdx=0;
bio(843).dim=[1,1];
bio(843).sigWidth=1;
bio(843).sigAddress='&Robot_leg_3_B.TrigonometricFunction_p';
bio(843).ndims=2;
bio(843).size=[];
bio(843).isStruct=false;

bio(844).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Sqrt';
bio(844).sigName='';
bio(844).portIdx=0;
bio(844).dim=[1,1];
bio(844).sigWidth=1;
bio(844).sigAddress='&Robot_leg_3_B.Sqrt_l3';
bio(844).ndims=2;
bio(844).size=[];
bio(844).isStruct=false;

bio(845).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Abs';
bio(845).sigName='Damping_Force_Enable';
bio(845).portIdx=0;
bio(845).dim=[1,1];
bio(845).sigWidth=1;
bio(845).sigAddress='&Robot_leg_3_B.Damping_Force_Enable_h';
bio(845).ndims=2;
bio(845).size=[];
bio(845).isStruct=false;

bio(846).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Gain1';
bio(846).sigName='Stiffness_Force';
bio(846).portIdx=0;
bio(846).dim=[1,1];
bio(846).sigWidth=1;
bio(846).sigAddress='&Robot_leg_3_B.Stiffness_Force_kg';
bio(846).ndims=2;
bio(846).size=[];
bio(846).isStruct=false;

bio(847).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Gain2';
bio(847).sigName='Damping_Force';
bio(847).portIdx=0;
bio(847).dim=[1,1];
bio(847).sigWidth=1;
bio(847).sigAddress='&Robot_leg_3_B.Damping_Force_d';
bio(847).ndims=2;
bio(847).size=[];
bio(847).isStruct=false;

bio(848).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Product';
bio(848).sigName='Damping_Force';
bio(848).portIdx=0;
bio(848).dim=[1,1];
bio(848).sigWidth=1;
bio(848).sigAddress='&Robot_leg_3_B.Damping_Force_cq';
bio(848).ndims=2;
bio(848).size=[];
bio(848).isStruct=false;

bio(849).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Saturation';
bio(849).sigName='';
bio(849).portIdx=0;
bio(849).dim=[1,1];
bio(849).sigWidth=1;
bio(849).sigAddress='&Robot_leg_3_B.Saturation_jq';
bio(849).ndims=2;
bio(849).size=[];
bio(849).isStruct=false;

bio(850).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Sign';
bio(850).sigName='';
bio(850).portIdx=0;
bio(850).dim=[1,1];
bio(850).sigWidth=1;
bio(850).sigAddress='&Robot_leg_3_B.Sign_f';
bio(850).ndims=2;
bio(850).size=[];
bio(850).isStruct=false;

bio(851).blkName='Robot/Left_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter2/EVAL_KEY/RESHAPE';
bio(851).sigName='';
bio(851).portIdx=0;
bio(851).dim=[3,3];
bio(851).sigWidth=9;
bio(851).sigAddress='&Robot_leg_3_B.RESHAPE_jw[0]';
bio(851).ndims=2;
bio(851).size=[];
bio(851).isStruct=false;

bio(852).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product';
bio(852).sigName='';
bio(852).portIdx=0;
bio(852).dim=[1,1];
bio(852).sigWidth=1;
bio(852).sigAddress='&Robot_leg_3_B.Product_bl';
bio(852).ndims=2;
bio(852).size=[];
bio(852).isStruct=false;

bio(853).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product1';
bio(853).sigName='';
bio(853).portIdx=0;
bio(853).dim=[1,1];
bio(853).sigWidth=1;
bio(853).sigAddress='&Robot_leg_3_B.Product1_ik';
bio(853).ndims=2;
bio(853).size=[];
bio(853).isStruct=false;

bio(854).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product2';
bio(854).sigName='';
bio(854).portIdx=0;
bio(854).dim=[1,1];
bio(854).sigWidth=1;
bio(854).sigAddress='&Robot_leg_3_B.Product2_b';
bio(854).ndims=2;
bio(854).size=[];
bio(854).isStruct=false;

bio(855).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product3';
bio(855).sigName='';
bio(855).portIdx=0;
bio(855).dim=[1,1];
bio(855).sigWidth=1;
bio(855).sigAddress='&Robot_leg_3_B.Product3_d';
bio(855).ndims=2;
bio(855).size=[];
bio(855).isStruct=false;

bio(856).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product4';
bio(856).sigName='';
bio(856).portIdx=0;
bio(856).dim=[1,1];
bio(856).sigWidth=1;
bio(856).sigAddress='&Robot_leg_3_B.Product4_cw';
bio(856).ndims=2;
bio(856).size=[];
bio(856).isStruct=false;

bio(857).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Product5';
bio(857).sigName='';
bio(857).portIdx=0;
bio(857).dim=[1,1];
bio(857).sigWidth=1;
bio(857).sigAddress='&Robot_leg_3_B.Product5_e';
bio(857).ndims=2;
bio(857).size=[];
bio(857).isStruct=false;

bio(858).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Sum';
bio(858).sigName='';
bio(858).portIdx=0;
bio(858).dim=[1,1];
bio(858).sigWidth=1;
bio(858).sigAddress='&Robot_leg_3_B.Sum_ph';
bio(858).ndims=2;
bio(858).size=[];
bio(858).isStruct=false;

bio(859).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Sum1';
bio(859).sigName='';
bio(859).portIdx=0;
bio(859).dim=[1,1];
bio(859).sigWidth=1;
bio(859).sigAddress='&Robot_leg_3_B.Sum1_c';
bio(859).ndims=2;
bio(859).size=[];
bio(859).isStruct=false;

bio(860).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Cross Product/Sum2';
bio(860).sigName='';
bio(860).portIdx=0;
bio(860).dim=[1,1];
bio(860).sigWidth=1;
bio(860).sigAddress='&Robot_leg_3_B.Sum2_h';
bio(860).ndims=2;
bio(860).size=[];
bio(860).isStruct=false;

bio(861).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Math Function';
bio(861).sigName='';
bio(861).portIdx=0;
bio(861).dim=[1,1];
bio(861).sigWidth=1;
bio(861).sigAddress='&Robot_leg_3_B.MathFunction_c2';
bio(861).ndims=2;
bio(861).size=[];
bio(861).isStruct=false;

bio(862).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Math Function1';
bio(862).sigName='';
bio(862).portIdx=0;
bio(862).dim=[1,1];
bio(862).sigWidth=1;
bio(862).sigAddress='&Robot_leg_3_B.MathFunction1_a';
bio(862).ndims=2;
bio(862).size=[];
bio(862).isStruct=false;

bio(863).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Product3';
bio(863).sigName='';
bio(863).portIdx=0;
bio(863).dim=[1,1];
bio(863).sigWidth=1;
bio(863).sigAddress='&Robot_leg_3_B.Product3_p';
bio(863).ndims=2;
bio(863).size=[];
bio(863).isStruct=false;

bio(864).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Product4';
bio(864).sigName='';
bio(864).portIdx=0;
bio(864).dim=[1,1];
bio(864).sigWidth=1;
bio(864).sigAddress='&Robot_leg_3_B.Product4_l';
bio(864).ndims=2;
bio(864).size=[];
bio(864).isStruct=false;

bio(865).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Sum1';
bio(865).sigName='slipy';
bio(865).portIdx=0;
bio(865).dim=[1,1];
bio(865).sigWidth=1;
bio(865).sigAddress='&Robot_leg_3_B.slipy_c';
bio(865).ndims=2;
bio(865).size=[];
bio(865).isStruct=false;

bio(866).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Sum2';
bio(866).sigName='slipx';
bio(866).portIdx=0;
bio(866).dim=[1,1];
bio(866).sigWidth=1;
bio(866).sigAddress='&Robot_leg_3_B.slipx_c';
bio(866).ndims=2;
bio(866).size=[];
bio(866).isStruct=false;

bio(867).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Sum3';
bio(867).sigName='';
bio(867).portIdx=0;
bio(867).dim=[1,1];
bio(867).sigWidth=1;
bio(867).sigAddress='&Robot_leg_3_B.Sum3_d';
bio(867).ndims=2;
bio(867).size=[];
bio(867).isStruct=false;

bio(868).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Trigonometric Function';
bio(868).sigName='';
bio(868).portIdx=0;
bio(868).dim=[1,1];
bio(868).sigWidth=1;
bio(868).sigAddress='&Robot_leg_3_B.TrigonometricFunction_i';
bio(868).ndims=2;
bio(868).size=[];
bio(868).isStruct=false;

bio(869).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/SlipVel/Sqrt';
bio(869).sigName='';
bio(869).portIdx=0;
bio(869).dim=[1,1];
bio(869).sigWidth=1;
bio(869).sigAddress='&Robot_leg_3_B.Sqrt_m';
bio(869).ndims=2;
bio(869).size=[];
bio(869).isStruct=false;

bio(870).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Linear/Abs';
bio(870).sigName='Damping_Force_Enable';
bio(870).portIdx=0;
bio(870).dim=[1,1];
bio(870).sigWidth=1;
bio(870).sigAddress='&Robot_leg_3_B.Damping_Force_Enable_k';
bio(870).ndims=2;
bio(870).size=[];
bio(870).isStruct=false;

bio(871).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Linear/Gain1';
bio(871).sigName='Stiffness_Force';
bio(871).portIdx=0;
bio(871).dim=[1,1];
bio(871).sigWidth=1;
bio(871).sigAddress='&Robot_leg_3_B.Stiffness_Force_k';
bio(871).ndims=2;
bio(871).size=[];
bio(871).isStruct=false;

bio(872).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Linear/Gain2';
bio(872).sigName='Damping_Force';
bio(872).portIdx=0;
bio(872).dim=[1,1];
bio(872).sigWidth=1;
bio(872).sigAddress='&Robot_leg_3_B.Damping_Force_e';
bio(872).ndims=2;
bio(872).size=[];
bio(872).isStruct=false;

bio(873).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Linear/Product';
bio(873).sigName='Damping_Force';
bio(873).portIdx=0;
bio(873).dim=[1,1];
bio(873).sigWidth=1;
bio(873).sigAddress='&Robot_leg_3_B.Damping_Force_cz';
bio(873).ndims=2;
bio(873).size=[];
bio(873).isStruct=false;

bio(874).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Linear/Saturation';
bio(874).sigName='';
bio(874).portIdx=0;
bio(874).dim=[1,1];
bio(874).sigWidth=1;
bio(874).sigAddress='&Robot_leg_3_B.Saturation_e';
bio(874).ndims=2;
bio(874).size=[];
bio(874).isStruct=false;

bio(875).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Force Law/Linear/Sign';
bio(875).sigName='';
bio(875).portIdx=0;
bio(875).dim=[1,1];
bio(875).sigWidth=1;
bio(875).sigAddress='&Robot_leg_3_B.Sign_b';
bio(875).ndims=2;
bio(875).size=[];
bio(875).isStruct=false;

bio(876).blkName='Robot/Right_leg/Sphere to Plane Force/Sensing/PS-Simulink Converter2/EVAL_KEY/RESHAPE';
bio(876).sigName='';
bio(876).portIdx=0;
bio(876).dim=[3,3];
bio(876).sigWidth=9;
bio(876).sigAddress='&Robot_leg_3_B.RESHAPE[0]';
bio(876).ndims=2;
bio(876).size=[];
bio(876).isStruct=false;

bio(877).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product';
bio(877).sigName='';
bio(877).portIdx=0;
bio(877).dim=[1,1];
bio(877).sigWidth=1;
bio(877).sigAddress='&Robot_leg_3_B.Product_nx';
bio(877).ndims=2;
bio(877).size=[];
bio(877).isStruct=false;

bio(878).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product1';
bio(878).sigName='';
bio(878).portIdx=0;
bio(878).dim=[1,1];
bio(878).sigWidth=1;
bio(878).sigAddress='&Robot_leg_3_B.Product1_b';
bio(878).ndims=2;
bio(878).size=[];
bio(878).isStruct=false;

bio(879).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product2';
bio(879).sigName='';
bio(879).portIdx=0;
bio(879).dim=[1,1];
bio(879).sigWidth=1;
bio(879).sigAddress='&Robot_leg_3_B.Product2_hx';
bio(879).ndims=2;
bio(879).size=[];
bio(879).isStruct=false;

bio(880).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product3';
bio(880).sigName='';
bio(880).portIdx=0;
bio(880).dim=[1,1];
bio(880).sigWidth=1;
bio(880).sigAddress='&Robot_leg_3_B.Product3_hs';
bio(880).ndims=2;
bio(880).size=[];
bio(880).isStruct=false;

bio(881).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product4';
bio(881).sigName='';
bio(881).portIdx=0;
bio(881).dim=[1,1];
bio(881).sigWidth=1;
bio(881).sigAddress='&Robot_leg_3_B.Product4_bz';
bio(881).ndims=2;
bio(881).size=[];
bio(881).isStruct=false;

bio(882).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Product5';
bio(882).sigName='';
bio(882).portIdx=0;
bio(882).dim=[1,1];
bio(882).sigWidth=1;
bio(882).sigAddress='&Robot_leg_3_B.Product5_i';
bio(882).ndims=2;
bio(882).size=[];
bio(882).isStruct=false;

bio(883).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Sum';
bio(883).sigName='';
bio(883).portIdx=0;
bio(883).dim=[1,1];
bio(883).sigWidth=1;
bio(883).sigAddress='&Robot_leg_3_B.Sum_mh';
bio(883).ndims=2;
bio(883).size=[];
bio(883).isStruct=false;

bio(884).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Sum1';
bio(884).sigName='';
bio(884).portIdx=0;
bio(884).dim=[1,1];
bio(884).sigWidth=1;
bio(884).sigAddress='&Robot_leg_3_B.Sum1_e';
bio(884).ndims=2;
bio(884).size=[];
bio(884).isStruct=false;

bio(885).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Cross Product/Sum2';
bio(885).sigName='';
bio(885).portIdx=0;
bio(885).dim=[1,1];
bio(885).sigWidth=1;
bio(885).sigAddress='&Robot_leg_3_B.Sum2_m';
bio(885).ndims=2;
bio(885).size=[];
bio(885).isStruct=false;

bio(886).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Math Function';
bio(886).sigName='';
bio(886).portIdx=0;
bio(886).dim=[1,1];
bio(886).sigWidth=1;
bio(886).sigAddress='&Robot_leg_3_B.MathFunction_mw';
bio(886).ndims=2;
bio(886).size=[];
bio(886).isStruct=false;

bio(887).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Math Function1';
bio(887).sigName='';
bio(887).portIdx=0;
bio(887).dim=[1,1];
bio(887).sigWidth=1;
bio(887).sigAddress='&Robot_leg_3_B.MathFunction1_j';
bio(887).ndims=2;
bio(887).size=[];
bio(887).isStruct=false;

bio(888).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Product3';
bio(888).sigName='';
bio(888).portIdx=0;
bio(888).dim=[1,1];
bio(888).sigWidth=1;
bio(888).sigAddress='&Robot_leg_3_B.Product3_f';
bio(888).ndims=2;
bio(888).size=[];
bio(888).isStruct=false;

bio(889).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Product4';
bio(889).sigName='';
bio(889).portIdx=0;
bio(889).dim=[1,1];
bio(889).sigWidth=1;
bio(889).sigAddress='&Robot_leg_3_B.Product4_ft';
bio(889).ndims=2;
bio(889).size=[];
bio(889).isStruct=false;

bio(890).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Sum1';
bio(890).sigName='slipy';
bio(890).portIdx=0;
bio(890).dim=[1,1];
bio(890).sigWidth=1;
bio(890).sigAddress='&Robot_leg_3_B.slipy_a';
bio(890).ndims=2;
bio(890).size=[];
bio(890).isStruct=false;

bio(891).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Sum2';
bio(891).sigName='slipx';
bio(891).portIdx=0;
bio(891).dim=[1,1];
bio(891).sigWidth=1;
bio(891).sigAddress='&Robot_leg_3_B.slipx_h';
bio(891).ndims=2;
bio(891).size=[];
bio(891).isStruct=false;

bio(892).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Sum3';
bio(892).sigName='';
bio(892).portIdx=0;
bio(892).dim=[1,1];
bio(892).sigWidth=1;
bio(892).sigAddress='&Robot_leg_3_B.Sum3_i';
bio(892).ndims=2;
bio(892).size=[];
bio(892).isStruct=false;

bio(893).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Trigonometric Function';
bio(893).sigName='';
bio(893).portIdx=0;
bio(893).dim=[1,1];
bio(893).sigWidth=1;
bio(893).sigAddress='&Robot_leg_3_B.TrigonometricFunction_j1';
bio(893).ndims=2;
bio(893).size=[];
bio(893).isStruct=false;

bio(894).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/SlipVel/Sqrt';
bio(894).sigName='';
bio(894).portIdx=0;
bio(894).dim=[1,1];
bio(894).sigWidth=1;
bio(894).sigAddress='&Robot_leg_3_B.Sqrt_f';
bio(894).ndims=2;
bio(894).size=[];
bio(894).isStruct=false;

bio(895).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Abs';
bio(895).sigName='Damping_Force_Enable';
bio(895).portIdx=0;
bio(895).dim=[1,1];
bio(895).sigWidth=1;
bio(895).sigAddress='&Robot_leg_3_B.Damping_Force_Enable_d';
bio(895).ndims=2;
bio(895).size=[];
bio(895).isStruct=false;

bio(896).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Gain1';
bio(896).sigName='Stiffness_Force';
bio(896).portIdx=0;
bio(896).dim=[1,1];
bio(896).sigWidth=1;
bio(896).sigAddress='&Robot_leg_3_B.Stiffness_Force_i';
bio(896).ndims=2;
bio(896).size=[];
bio(896).isStruct=false;

bio(897).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Gain2';
bio(897).sigName='Damping_Force';
bio(897).portIdx=0;
bio(897).dim=[1,1];
bio(897).sigWidth=1;
bio(897).sigAddress='&Robot_leg_3_B.Damping_Force_c';
bio(897).ndims=2;
bio(897).size=[];
bio(897).isStruct=false;

bio(898).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Product';
bio(898).sigName='Damping_Force';
bio(898).portIdx=0;
bio(898).dim=[1,1];
bio(898).sigWidth=1;
bio(898).sigAddress='&Robot_leg_3_B.Damping_Force_o';
bio(898).ndims=2;
bio(898).size=[];
bio(898).isStruct=false;

bio(899).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Saturation';
bio(899).sigName='';
bio(899).portIdx=0;
bio(899).dim=[1,1];
bio(899).sigWidth=1;
bio(899).sigAddress='&Robot_leg_3_B.Saturation_f';
bio(899).ndims=2;
bio(899).size=[];
bio(899).isStruct=false;

bio(900).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Force Law/Linear/Sign';
bio(900).sigName='';
bio(900).portIdx=0;
bio(900).dim=[1,1];
bio(900).sigWidth=1;
bio(900).sigAddress='&Robot_leg_3_B.Sign_l';
bio(900).ndims=2;
bio(900).size=[];
bio(900).isStruct=false;

bio(901).blkName='Robot/Right_leg/Sphere to Plane Force1/Sensing/PS-Simulink Converter2/EVAL_KEY/RESHAPE';
bio(901).sigName='';
bio(901).portIdx=0;
bio(901).dim=[3,3];
bio(901).sigWidth=9;
bio(901).sigAddress='&Robot_leg_3_B.RESHAPE_f[0]';
bio(901).ndims=2;
bio(901).size=[];
bio(901).isStruct=false;

bio(902).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product';
bio(902).sigName='';
bio(902).portIdx=0;
bio(902).dim=[1,1];
bio(902).sigWidth=1;
bio(902).sigAddress='&Robot_leg_3_B.Product_bbt';
bio(902).ndims=2;
bio(902).size=[];
bio(902).isStruct=false;

bio(903).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product1';
bio(903).sigName='';
bio(903).portIdx=0;
bio(903).dim=[1,1];
bio(903).sigWidth=1;
bio(903).sigAddress='&Robot_leg_3_B.Product1_h1';
bio(903).ndims=2;
bio(903).size=[];
bio(903).isStruct=false;

bio(904).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product2';
bio(904).sigName='';
bio(904).portIdx=0;
bio(904).dim=[1,1];
bio(904).sigWidth=1;
bio(904).sigAddress='&Robot_leg_3_B.Product2_a';
bio(904).ndims=2;
bio(904).size=[];
bio(904).isStruct=false;

bio(905).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product3';
bio(905).sigName='';
bio(905).portIdx=0;
bio(905).dim=[1,1];
bio(905).sigWidth=1;
bio(905).sigAddress='&Robot_leg_3_B.Product3_i';
bio(905).ndims=2;
bio(905).size=[];
bio(905).isStruct=false;

bio(906).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product4';
bio(906).sigName='';
bio(906).portIdx=0;
bio(906).dim=[1,1];
bio(906).sigWidth=1;
bio(906).sigAddress='&Robot_leg_3_B.Product4_f';
bio(906).ndims=2;
bio(906).size=[];
bio(906).isStruct=false;

bio(907).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Product5';
bio(907).sigName='';
bio(907).portIdx=0;
bio(907).dim=[1,1];
bio(907).sigWidth=1;
bio(907).sigAddress='&Robot_leg_3_B.Product5_ju';
bio(907).ndims=2;
bio(907).size=[];
bio(907).isStruct=false;

bio(908).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Sum';
bio(908).sigName='';
bio(908).portIdx=0;
bio(908).dim=[1,1];
bio(908).sigWidth=1;
bio(908).sigAddress='&Robot_leg_3_B.Sum_gny';
bio(908).ndims=2;
bio(908).size=[];
bio(908).isStruct=false;

bio(909).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Sum1';
bio(909).sigName='';
bio(909).portIdx=0;
bio(909).dim=[1,1];
bio(909).sigWidth=1;
bio(909).sigAddress='&Robot_leg_3_B.Sum1_j';
bio(909).ndims=2;
bio(909).size=[];
bio(909).isStruct=false;

bio(910).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Cross Product/Sum2';
bio(910).sigName='';
bio(910).portIdx=0;
bio(910).dim=[1,1];
bio(910).sigWidth=1;
bio(910).sigAddress='&Robot_leg_3_B.Sum2_e';
bio(910).ndims=2;
bio(910).size=[];
bio(910).isStruct=false;

bio(911).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Math Function';
bio(911).sigName='';
bio(911).portIdx=0;
bio(911).dim=[1,1];
bio(911).sigWidth=1;
bio(911).sigAddress='&Robot_leg_3_B.MathFunction_o2';
bio(911).ndims=2;
bio(911).size=[];
bio(911).isStruct=false;

bio(912).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Math Function1';
bio(912).sigName='';
bio(912).portIdx=0;
bio(912).dim=[1,1];
bio(912).sigWidth=1;
bio(912).sigAddress='&Robot_leg_3_B.MathFunction1_n';
bio(912).ndims=2;
bio(912).size=[];
bio(912).isStruct=false;

bio(913).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Product3';
bio(913).sigName='';
bio(913).portIdx=0;
bio(913).dim=[1,1];
bio(913).sigWidth=1;
bio(913).sigAddress='&Robot_leg_3_B.Product3_e';
bio(913).ndims=2;
bio(913).size=[];
bio(913).isStruct=false;

bio(914).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Product4';
bio(914).sigName='';
bio(914).portIdx=0;
bio(914).dim=[1,1];
bio(914).sigWidth=1;
bio(914).sigAddress='&Robot_leg_3_B.Product4_p';
bio(914).ndims=2;
bio(914).size=[];
bio(914).isStruct=false;

bio(915).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Sum1';
bio(915).sigName='slipy';
bio(915).portIdx=0;
bio(915).dim=[1,1];
bio(915).sigWidth=1;
bio(915).sigAddress='&Robot_leg_3_B.slipy_e';
bio(915).ndims=2;
bio(915).size=[];
bio(915).isStruct=false;

bio(916).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Sum2';
bio(916).sigName='slipx';
bio(916).portIdx=0;
bio(916).dim=[1,1];
bio(916).sigWidth=1;
bio(916).sigAddress='&Robot_leg_3_B.slipx_k';
bio(916).ndims=2;
bio(916).size=[];
bio(916).isStruct=false;

bio(917).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Sum3';
bio(917).sigName='';
bio(917).portIdx=0;
bio(917).dim=[1,1];
bio(917).sigWidth=1;
bio(917).sigAddress='&Robot_leg_3_B.Sum3_p';
bio(917).ndims=2;
bio(917).size=[];
bio(917).isStruct=false;

bio(918).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Trigonometric Function';
bio(918).sigName='';
bio(918).portIdx=0;
bio(918).dim=[1,1];
bio(918).sigWidth=1;
bio(918).sigAddress='&Robot_leg_3_B.TrigonometricFunction_l';
bio(918).ndims=2;
bio(918).size=[];
bio(918).isStruct=false;

bio(919).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/SlipVel/Sqrt';
bio(919).sigName='';
bio(919).portIdx=0;
bio(919).dim=[1,1];
bio(919).sigWidth=1;
bio(919).sigAddress='&Robot_leg_3_B.Sqrt_l';
bio(919).ndims=2;
bio(919).size=[];
bio(919).isStruct=false;

bio(920).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Abs';
bio(920).sigName='Damping_Force_Enable';
bio(920).portIdx=0;
bio(920).dim=[1,1];
bio(920).sigWidth=1;
bio(920).sigAddress='&Robot_leg_3_B.Damping_Force_Enable_b';
bio(920).ndims=2;
bio(920).size=[];
bio(920).isStruct=false;

bio(921).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Gain1';
bio(921).sigName='Stiffness_Force';
bio(921).portIdx=0;
bio(921).dim=[1,1];
bio(921).sigWidth=1;
bio(921).sigAddress='&Robot_leg_3_B.Stiffness_Force_m';
bio(921).ndims=2;
bio(921).size=[];
bio(921).isStruct=false;

bio(922).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Gain2';
bio(922).sigName='Damping_Force';
bio(922).portIdx=0;
bio(922).dim=[1,1];
bio(922).sigWidth=1;
bio(922).sigAddress='&Robot_leg_3_B.Damping_Force_p';
bio(922).ndims=2;
bio(922).size=[];
bio(922).isStruct=false;

bio(923).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Product';
bio(923).sigName='Damping_Force';
bio(923).portIdx=0;
bio(923).dim=[1,1];
bio(923).sigWidth=1;
bio(923).sigAddress='&Robot_leg_3_B.Damping_Force_nm';
bio(923).ndims=2;
bio(923).size=[];
bio(923).isStruct=false;

bio(924).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Saturation';
bio(924).sigName='';
bio(924).portIdx=0;
bio(924).dim=[1,1];
bio(924).sigWidth=1;
bio(924).sigAddress='&Robot_leg_3_B.Saturation_j';
bio(924).ndims=2;
bio(924).size=[];
bio(924).isStruct=false;

bio(925).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Force Law/Linear/Sign';
bio(925).sigName='';
bio(925).portIdx=0;
bio(925).dim=[1,1];
bio(925).sigWidth=1;
bio(925).sigAddress='&Robot_leg_3_B.Sign_k';
bio(925).ndims=2;
bio(925).size=[];
bio(925).isStruct=false;

bio(926).blkName='Robot/Right_leg/Sphere to Plane Force2/Sensing/PS-Simulink Converter2/EVAL_KEY/RESHAPE';
bio(926).sigName='';
bio(926).portIdx=0;
bio(926).dim=[3,3];
bio(926).sigWidth=9;
bio(926).sigAddress='&Robot_leg_3_B.RESHAPE_p[0]';
bio(926).ndims=2;
bio(926).size=[];
bio(926).isStruct=false;

bio(927).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product';
bio(927).sigName='';
bio(927).portIdx=0;
bio(927).dim=[1,1];
bio(927).sigWidth=1;
bio(927).sigAddress='&Robot_leg_3_B.Product_eg';
bio(927).ndims=2;
bio(927).size=[];
bio(927).isStruct=false;

bio(928).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product1';
bio(928).sigName='';
bio(928).portIdx=0;
bio(928).dim=[1,1];
bio(928).sigWidth=1;
bio(928).sigAddress='&Robot_leg_3_B.Product1_c';
bio(928).ndims=2;
bio(928).size=[];
bio(928).isStruct=false;

bio(929).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product2';
bio(929).sigName='';
bio(929).portIdx=0;
bio(929).dim=[1,1];
bio(929).sigWidth=1;
bio(929).sigAddress='&Robot_leg_3_B.Product2_n';
bio(929).ndims=2;
bio(929).size=[];
bio(929).isStruct=false;

bio(930).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product3';
bio(930).sigName='';
bio(930).portIdx=0;
bio(930).dim=[1,1];
bio(930).sigWidth=1;
bio(930).sigAddress='&Robot_leg_3_B.Product3_a';
bio(930).ndims=2;
bio(930).size=[];
bio(930).isStruct=false;

bio(931).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product4';
bio(931).sigName='';
bio(931).portIdx=0;
bio(931).dim=[1,1];
bio(931).sigWidth=1;
bio(931).sigAddress='&Robot_leg_3_B.Product4_c';
bio(931).ndims=2;
bio(931).size=[];
bio(931).isStruct=false;

bio(932).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Product5';
bio(932).sigName='';
bio(932).portIdx=0;
bio(932).dim=[1,1];
bio(932).sigWidth=1;
bio(932).sigAddress='&Robot_leg_3_B.Product5_j';
bio(932).ndims=2;
bio(932).size=[];
bio(932).isStruct=false;

bio(933).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Sum';
bio(933).sigName='';
bio(933).portIdx=0;
bio(933).dim=[1,1];
bio(933).sigWidth=1;
bio(933).sigAddress='&Robot_leg_3_B.Sum_m4o';
bio(933).ndims=2;
bio(933).size=[];
bio(933).isStruct=false;

bio(934).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Sum1';
bio(934).sigName='';
bio(934).portIdx=0;
bio(934).dim=[1,1];
bio(934).sigWidth=1;
bio(934).sigAddress='&Robot_leg_3_B.Sum1';
bio(934).ndims=2;
bio(934).size=[];
bio(934).isStruct=false;

bio(935).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Cross Product/Sum2';
bio(935).sigName='';
bio(935).portIdx=0;
bio(935).dim=[1,1];
bio(935).sigWidth=1;
bio(935).sigAddress='&Robot_leg_3_B.Sum2';
bio(935).ndims=2;
bio(935).size=[];
bio(935).isStruct=false;

bio(936).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Math Function';
bio(936).sigName='';
bio(936).portIdx=0;
bio(936).dim=[1,1];
bio(936).sigWidth=1;
bio(936).sigAddress='&Robot_leg_3_B.MathFunction_mn';
bio(936).ndims=2;
bio(936).size=[];
bio(936).isStruct=false;

bio(937).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Math Function1';
bio(937).sigName='';
bio(937).portIdx=0;
bio(937).dim=[1,1];
bio(937).sigWidth=1;
bio(937).sigAddress='&Robot_leg_3_B.MathFunction1';
bio(937).ndims=2;
bio(937).size=[];
bio(937).isStruct=false;

bio(938).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Product3';
bio(938).sigName='';
bio(938).portIdx=0;
bio(938).dim=[1,1];
bio(938).sigWidth=1;
bio(938).sigAddress='&Robot_leg_3_B.Product3';
bio(938).ndims=2;
bio(938).size=[];
bio(938).isStruct=false;

bio(939).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Product4';
bio(939).sigName='';
bio(939).portIdx=0;
bio(939).dim=[1,1];
bio(939).sigWidth=1;
bio(939).sigAddress='&Robot_leg_3_B.Product4';
bio(939).ndims=2;
bio(939).size=[];
bio(939).isStruct=false;

bio(940).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Sum1';
bio(940).sigName='slipy';
bio(940).portIdx=0;
bio(940).dim=[1,1];
bio(940).sigWidth=1;
bio(940).sigAddress='&Robot_leg_3_B.slipy';
bio(940).ndims=2;
bio(940).size=[];
bio(940).isStruct=false;

bio(941).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Sum2';
bio(941).sigName='slipx';
bio(941).portIdx=0;
bio(941).dim=[1,1];
bio(941).sigWidth=1;
bio(941).sigAddress='&Robot_leg_3_B.slipx';
bio(941).ndims=2;
bio(941).size=[];
bio(941).isStruct=false;

bio(942).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Sum3';
bio(942).sigName='';
bio(942).portIdx=0;
bio(942).dim=[1,1];
bio(942).sigWidth=1;
bio(942).sigAddress='&Robot_leg_3_B.Sum3';
bio(942).ndims=2;
bio(942).size=[];
bio(942).isStruct=false;

bio(943).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Trigonometric Function';
bio(943).sigName='';
bio(943).portIdx=0;
bio(943).dim=[1,1];
bio(943).sigWidth=1;
bio(943).sigAddress='&Robot_leg_3_B.TrigonometricFunction';
bio(943).ndims=2;
bio(943).size=[];
bio(943).isStruct=false;

bio(944).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/SlipVel/Sqrt';
bio(944).sigName='';
bio(944).portIdx=0;
bio(944).dim=[1,1];
bio(944).sigWidth=1;
bio(944).sigAddress='&Robot_leg_3_B.Sqrt';
bio(944).ndims=2;
bio(944).size=[];
bio(944).isStruct=false;

bio(945).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Abs';
bio(945).sigName='Damping_Force_Enable';
bio(945).portIdx=0;
bio(945).dim=[1,1];
bio(945).sigWidth=1;
bio(945).sigAddress='&Robot_leg_3_B.Damping_Force_Enable';
bio(945).ndims=2;
bio(945).size=[];
bio(945).isStruct=false;

bio(946).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Gain1';
bio(946).sigName='Stiffness_Force';
bio(946).portIdx=0;
bio(946).dim=[1,1];
bio(946).sigWidth=1;
bio(946).sigAddress='&Robot_leg_3_B.Stiffness_Force';
bio(946).ndims=2;
bio(946).size=[];
bio(946).isStruct=false;

bio(947).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Gain2';
bio(947).sigName='Damping_Force';
bio(947).portIdx=0;
bio(947).dim=[1,1];
bio(947).sigWidth=1;
bio(947).sigAddress='&Robot_leg_3_B.Damping_Force';
bio(947).ndims=2;
bio(947).size=[];
bio(947).isStruct=false;

bio(948).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Product';
bio(948).sigName='Damping_Force';
bio(948).portIdx=0;
bio(948).dim=[1,1];
bio(948).sigWidth=1;
bio(948).sigAddress='&Robot_leg_3_B.Damping_Force_n';
bio(948).ndims=2;
bio(948).size=[];
bio(948).isStruct=false;

bio(949).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Saturation';
bio(949).sigName='';
bio(949).portIdx=0;
bio(949).dim=[1,1];
bio(949).sigWidth=1;
bio(949).sigAddress='&Robot_leg_3_B.Saturation';
bio(949).ndims=2;
bio(949).size=[];
bio(949).isStruct=false;

bio(950).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Force Law/Linear/Sign';
bio(950).sigName='';
bio(950).portIdx=0;
bio(950).dim=[1,1];
bio(950).sigWidth=1;
bio(950).sigAddress='&Robot_leg_3_B.Sign';
bio(950).ndims=2;
bio(950).size=[];
bio(950).isStruct=false;

bio(951).blkName='Robot/Right_leg/Sphere to Plane Force3/Sensing/PS-Simulink Converter2/EVAL_KEY/RESHAPE';
bio(951).sigName='';
bio(951).portIdx=0;
bio(951).dim=[3,3];
bio(951).sigWidth=9;
bio(951).sigAddress='&Robot_leg_3_B.RESHAPE_j[0]';
bio(951).ndims=2;
bio(951).size=[];
bio(951).isStruct=false;

bio(952).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Friction Law/Stick-Slip C /Gain2';
bio(952).sigName='Friction_Force';
bio(952).portIdx=0;
bio(952).dim=[1,1];
bio(952).sigWidth=1;
bio(952).sigAddress='&Robot_leg_3_B.Friction_Force_p';
bio(952).ndims=2;
bio(952).size=[];
bio(952).isStruct=false;

bio(953).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Friction Law/Stick-Slip C /Coefficient of Friction vs Velocity';
bio(953).sigName='';
bio(953).portIdx=0;
bio(953).dim=[1,1];
bio(953).sigWidth=1;
bio(953).sigAddress='&Robot_leg_3_B.CoefficientofFrictionvsVeloc_id';
bio(953).ndims=2;
bio(953).size=[];
bio(953).isStruct=false;

bio(954).blkName='Robot/Left_leg/Sphere to Plane Force/Forces/Ff/Friction Law/Stick-Slip C /Product';
bio(954).sigName='';
bio(954).portIdx=0;
bio(954).dim=[1,1];
bio(954).sigWidth=1;
bio(954).sigAddress='&Robot_leg_3_B.Product_mc';
bio(954).ndims=2;
bio(954).size=[];
bio(954).isStruct=false;

bio(955).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/Stick-Slip C /Gain2';
bio(955).sigName='Friction_Force';
bio(955).portIdx=0;
bio(955).dim=[1,1];
bio(955).sigWidth=1;
bio(955).sigAddress='&Robot_leg_3_B.Friction_Force_m';
bio(955).ndims=2;
bio(955).size=[];
bio(955).isStruct=false;

bio(956).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/Stick-Slip C /Coefficient of Friction vs Velocity';
bio(956).sigName='';
bio(956).portIdx=0;
bio(956).dim=[1,1];
bio(956).sigWidth=1;
bio(956).sigAddress='&Robot_leg_3_B.CoefficientofFrictionvsVeloci_i';
bio(956).ndims=2;
bio(956).size=[];
bio(956).isStruct=false;

bio(957).blkName='Robot/Left_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/Stick-Slip C /Product';
bio(957).sigName='';
bio(957).portIdx=0;
bio(957).dim=[1,1];
bio(957).sigWidth=1;
bio(957).sigAddress='&Robot_leg_3_B.Product_h';
bio(957).ndims=2;
bio(957).size=[];
bio(957).isStruct=false;

bio(958).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/Stick-Slip C /Gain2';
bio(958).sigName='Friction_Force';
bio(958).portIdx=0;
bio(958).dim=[1,1];
bio(958).sigWidth=1;
bio(958).sigAddress='&Robot_leg_3_B.Friction_Force_bg';
bio(958).ndims=2;
bio(958).size=[];
bio(958).isStruct=false;

bio(959).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/Stick-Slip C /Coefficient of Friction vs Velocity';
bio(959).sigName='';
bio(959).portIdx=0;
bio(959).dim=[1,1];
bio(959).sigWidth=1;
bio(959).sigAddress='&Robot_leg_3_B.CoefficientofFrictionvsVeloc_ow';
bio(959).ndims=2;
bio(959).size=[];
bio(959).isStruct=false;

bio(960).blkName='Robot/Left_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/Stick-Slip C /Product';
bio(960).sigName='';
bio(960).portIdx=0;
bio(960).dim=[1,1];
bio(960).sigWidth=1;
bio(960).sigAddress='&Robot_leg_3_B.Product_ka';
bio(960).ndims=2;
bio(960).size=[];
bio(960).isStruct=false;

bio(961).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/Stick-Slip C /Gain2';
bio(961).sigName='Friction_Force';
bio(961).portIdx=0;
bio(961).dim=[1,1];
bio(961).sigWidth=1;
bio(961).sigAddress='&Robot_leg_3_B.Friction_Force_n';
bio(961).ndims=2;
bio(961).size=[];
bio(961).isStruct=false;

bio(962).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/Stick-Slip C /Coefficient of Friction vs Velocity';
bio(962).sigName='';
bio(962).portIdx=0;
bio(962).dim=[1,1];
bio(962).sigWidth=1;
bio(962).sigAddress='&Robot_leg_3_B.CoefficientofFrictionvsVeloci_o';
bio(962).ndims=2;
bio(962).size=[];
bio(962).isStruct=false;

bio(963).blkName='Robot/Left_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/Stick-Slip C /Product';
bio(963).sigName='';
bio(963).portIdx=0;
bio(963).dim=[1,1];
bio(963).sigWidth=1;
bio(963).sigAddress='&Robot_leg_3_B.Product_db';
bio(963).ndims=2;
bio(963).size=[];
bio(963).isStruct=false;

bio(964).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Friction Law/Stick-Slip C /Gain2';
bio(964).sigName='Friction_Force';
bio(964).portIdx=0;
bio(964).dim=[1,1];
bio(964).sigWidth=1;
bio(964).sigAddress='&Robot_leg_3_B.Friction_Force_l';
bio(964).ndims=2;
bio(964).size=[];
bio(964).isStruct=false;

bio(965).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Friction Law/Stick-Slip C /Coefficient of Friction vs Velocity';
bio(965).sigName='';
bio(965).portIdx=0;
bio(965).dim=[1,1];
bio(965).sigWidth=1;
bio(965).sigAddress='&Robot_leg_3_B.CoefficientofFrictionvsVeloc_cu';
bio(965).ndims=2;
bio(965).size=[];
bio(965).isStruct=false;

bio(966).blkName='Robot/Right_leg/Sphere to Plane Force/Forces/Ff/Friction Law/Stick-Slip C /Product';
bio(966).sigName='';
bio(966).portIdx=0;
bio(966).dim=[1,1];
bio(966).sigWidth=1;
bio(966).sigAddress='&Robot_leg_3_B.Product_a';
bio(966).ndims=2;
bio(966).size=[];
bio(966).isStruct=false;

bio(967).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/Stick-Slip C /Gain2';
bio(967).sigName='Friction_Force';
bio(967).portIdx=0;
bio(967).dim=[1,1];
bio(967).sigWidth=1;
bio(967).sigAddress='&Robot_leg_3_B.Friction_Force_b';
bio(967).ndims=2;
bio(967).size=[];
bio(967).isStruct=false;

bio(968).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/Stick-Slip C /Coefficient of Friction vs Velocity';
bio(968).sigName='';
bio(968).portIdx=0;
bio(968).dim=[1,1];
bio(968).sigWidth=1;
bio(968).sigAddress='&Robot_leg_3_B.CoefficientofFrictionvsVeloci_c';
bio(968).ndims=2;
bio(968).size=[];
bio(968).isStruct=false;

bio(969).blkName='Robot/Right_leg/Sphere to Plane Force1/Forces/Ff/Friction Law/Stick-Slip C /Product';
bio(969).sigName='';
bio(969).portIdx=0;
bio(969).dim=[1,1];
bio(969).sigWidth=1;
bio(969).sigAddress='&Robot_leg_3_B.Product_p';
bio(969).ndims=2;
bio(969).size=[];
bio(969).isStruct=false;

bio(970).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/Stick-Slip C /Gain2';
bio(970).sigName='Friction_Force';
bio(970).portIdx=0;
bio(970).dim=[1,1];
bio(970).sigWidth=1;
bio(970).sigAddress='&Robot_leg_3_B.Friction_Force_i';
bio(970).ndims=2;
bio(970).size=[];
bio(970).isStruct=false;

bio(971).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/Stick-Slip C /Coefficient of Friction vs Velocity';
bio(971).sigName='';
bio(971).portIdx=0;
bio(971).dim=[1,1];
bio(971).sigWidth=1;
bio(971).sigAddress='&Robot_leg_3_B.CoefficientofFrictionvsVeloci_e';
bio(971).ndims=2;
bio(971).size=[];
bio(971).isStruct=false;

bio(972).blkName='Robot/Right_leg/Sphere to Plane Force2/Forces/Ff/Friction Law/Stick-Slip C /Product';
bio(972).sigName='';
bio(972).portIdx=0;
bio(972).dim=[1,1];
bio(972).sigWidth=1;
bio(972).sigAddress='&Robot_leg_3_B.Product_bb';
bio(972).ndims=2;
bio(972).size=[];
bio(972).isStruct=false;

bio(973).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/Stick-Slip C /Gain2';
bio(973).sigName='Friction_Force';
bio(973).portIdx=0;
bio(973).dim=[1,1];
bio(973).sigWidth=1;
bio(973).sigAddress='&Robot_leg_3_B.Friction_Force';
bio(973).ndims=2;
bio(973).size=[];
bio(973).isStruct=false;

bio(974).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/Stick-Slip C /Coefficient of Friction vs Velocity';
bio(974).sigName='';
bio(974).portIdx=0;
bio(974).dim=[1,1];
bio(974).sigWidth=1;
bio(974).sigAddress='&Robot_leg_3_B.CoefficientofFrictionvsVelocity';
bio(974).ndims=2;
bio(974).size=[];
bio(974).isStruct=false;

bio(975).blkName='Robot/Right_leg/Sphere to Plane Force3/Forces/Ff/Friction Law/Stick-Slip C /Product';
bio(975).sigName='';
bio(975).portIdx=0;
bio(975).dim=[1,1];
bio(975).sigWidth=1;
bio(975).sigAddress='&Robot_leg_3_B.Product_ke';
bio(975).ndims=2;
bio(975).size=[];
bio(975).isStruct=false;

function len = getlenBIO
len = 975;

