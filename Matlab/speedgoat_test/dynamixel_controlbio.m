function bio=dynamixel_controlbio
bio = [];
bio(1).blkName='Constant32';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&dynamixel_control_B.Constant32';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

bio(2).blkName='ASCII Encode ';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[128,1];
bio(2).sigWidth=128;
bio(2).sigAddress='&dynamixel_control_B.ASCIIEncode[0]';
bio(2).ndims=2;
bio(2).size=[];
bio(2).isStruct=false;

bio(3).blkName='Baseboard Serial/Rate Transition';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&dynamixel_control_B.RateTransition';
bio(3).ndims=2;
bio(3).size=[];
bio(3).isStruct=false;

bio(4).blkName='Baseboard Serial/Rate Transition1';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&dynamixel_control_B.RateTransition1';
bio(4).ndims=2;
bio(4).size=[];
bio(4).isStruct=false;

bio(5).blkName='Baseboard Serial/Rate Transition2';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&dynamixel_control_B.RateTransition2';
bio(5).ndims=2;
bio(5).size=[];
bio(5).isStruct=false;

bio(6).blkName='Baseboard Serial/Rate Transition3';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&dynamixel_control_B.RateTransition3';
bio(6).ndims=2;
bio(6).size=[];
bio(6).isStruct=false;

bio(7).blkName='Baseboard Serial/FIFO read 1';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[2049,1];
bio(7).sigWidth=2049;
bio(7).sigAddress='&dynamixel_control_B.FIFOread1[0]';
bio(7).ndims=2;
bio(7).size=[];
bio(7).isStruct=false;

bio(8).blkName='Baseboard Serial/FIFO read 2';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[1025,1];
bio(8).sigWidth=1025;
bio(8).sigAddress='&dynamixel_control_B.FIFOread2[0]';
bio(8).ndims=2;
bio(8).size=[];
bio(8).isStruct=false;

bio(9).blkName='Baseboard Serial/FIFO write 1/p1';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&dynamixel_control_B.FIFOwrite1_o1';
bio(9).ndims=2;
bio(9).size=[];
bio(9).isStruct=false;

bio(10).blkName='Baseboard Serial/FIFO write 1/p2';
bio(10).sigName='';
bio(10).portIdx=1;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&dynamixel_control_B.FIFOwrite1_o2';
bio(10).ndims=2;
bio(10).size=[];
bio(10).isStruct=false;

bio(11).blkName='Baseboard Serial/FIFO write 2/p1';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&dynamixel_control_B.FIFOwrite2_o1';
bio(11).ndims=2;
bio(11).size=[];
bio(11).isStruct=false;

bio(12).blkName='Baseboard Serial/FIFO write 2/p2';
bio(12).sigName='';
bio(12).portIdx=1;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&dynamixel_control_B.FIFOwrite2_o2';
bio(12).ndims=2;
bio(12).size=[];
bio(12).isStruct=false;

bio(13).blkName='Baseboard Serial/RS232 ISR/Read Int Status FC1';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&dynamixel_control_B.ReadIntStatusFC1_o2';
bio(13).ndims=2;
bio(13).size=[];
bio(13).isStruct=false;

bio(14).blkName='Baseboard Serial/RS232 ISR/Receive 1/FIFO write 1';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&dynamixel_control_B.FIFOwrite1';
bio(14).ndims=2;
bio(14).size=[];
bio(14).isStruct=false;

bio(15).blkName='Baseboard Serial/RS232 ISR/Receive 1/Read HW FIFO1';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[65,1];
bio(15).sigWidth=65;
bio(15).sigAddress='&dynamixel_control_B.ReadHWFIFO1[0]';
bio(15).ndims=2;
bio(15).size=[];
bio(15).isStruct=false;

bio(16).blkName='Baseboard Serial/RS232 ISR/Receive 2/FIFO write 2';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&dynamixel_control_B.FIFOwrite2';
bio(16).ndims=2;
bio(16).size=[];
bio(16).isStruct=false;

bio(17).blkName='Baseboard Serial/RS232 ISR/Receive 2/Read HW FIFO2';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[65,1];
bio(17).sigWidth=65;
bio(17).sigAddress='&dynamixel_control_B.ReadHWFIFO2[0]';
bio(17).ndims=2;
bio(17).size=[];
bio(17).isStruct=false;

bio(18).blkName='Baseboard Serial/RS232 ISR/Transmit 1/FIFO read 1/p1';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[61,1];
bio(18).sigWidth=61;
bio(18).sigAddress='&dynamixel_control_B.FIFOread1_o1[0]';
bio(18).ndims=2;
bio(18).size=[];
bio(18).isStruct=false;

bio(19).blkName='Baseboard Serial/RS232 ISR/Transmit 1/FIFO read 1/p2';
bio(19).sigName='';
bio(19).portIdx=1;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&dynamixel_control_B.FIFOread1_o2';
bio(19).ndims=2;
bio(19).size=[];
bio(19).isStruct=false;

bio(20).blkName='Baseboard Serial/RS232 ISR/Transmit 2/FIFO read 2/p1';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[61,1];
bio(20).sigWidth=61;
bio(20).sigAddress='&dynamixel_control_B.FIFOread2_o1[0]';
bio(20).ndims=2;
bio(20).size=[];
bio(20).isStruct=false;

bio(21).blkName='Baseboard Serial/RS232 ISR/Transmit 2/FIFO read 2/p2';
bio(21).sigName='';
bio(21).portIdx=1;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&dynamixel_control_B.FIFOread2_o2';
bio(21).ndims=2;
bio(21).size=[];
bio(21).isStruct=false;

function len = getlenBIO
len = 21;

