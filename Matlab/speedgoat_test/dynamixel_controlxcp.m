function xcp = dynamixel_controlxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'dynamixel_control';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.001;
xcp.events(1).offset     = 0.0;
         
xcp.events(2).id         = 1;
xcp.events(2).sampletime = 0.01;
xcp.events(2).offset     = 0.0;
         
xcp.events(3).id         = 2;
xcp.events(3).sampletime = -1.0;
xcp.events(3).offset     = -2.0;
    
xcp.signals(1).symbol =  'dynamixel_control_B.Constant32';
    
xcp.signals(2).symbol =  'dynamixel_control_B.ASCIIEncode';
    
xcp.signals(3).symbol =  'dynamixel_control_B.RateTransition';
    
xcp.signals(4).symbol =  'dynamixel_control_B.RateTransition1';
    
xcp.signals(5).symbol =  'dynamixel_control_B.RateTransition2';
    
xcp.signals(6).symbol =  'dynamixel_control_B.RateTransition3';
    
xcp.signals(7).symbol =  'dynamixel_control_B.FIFOread1';
    
xcp.signals(8).symbol =  'dynamixel_control_B.FIFOread2';
    
xcp.signals(9).symbol =  'dynamixel_control_B.FIFOwrite1_o1';
    
xcp.signals(10).symbol =  'dynamixel_control_B.FIFOwrite1_o2';
    
xcp.signals(11).symbol =  'dynamixel_control_B.FIFOwrite2_o1';
    
xcp.signals(12).symbol =  'dynamixel_control_B.FIFOwrite2_o2';
    
xcp.signals(13).symbol =  'dynamixel_control_B.ReadIntStatusFC1_o2';
    
xcp.signals(14).symbol =  'dynamixel_control_B.FIFOwrite1';
    
xcp.signals(15).symbol =  'dynamixel_control_B.ReadHWFIFO1';
    
xcp.signals(16).symbol =  'dynamixel_control_B.FIFOwrite2';
    
xcp.signals(17).symbol =  'dynamixel_control_B.ReadHWFIFO2';
    
xcp.signals(18).symbol =  'dynamixel_control_B.FIFOread1_o1';
    
xcp.signals(19).symbol =  'dynamixel_control_B.FIFOread1_o2';
    
xcp.signals(20).symbol =  'dynamixel_control_B.FIFOread2_o1';
    
xcp.signals(21).symbol =  'dynamixel_control_B.FIFOread2_o2';
         
xcp.parameters(1).symbol = 'dynamixel_control_P.Constant32_Value';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&dynamixel_control_P.Constant32_Value';     
         
xcp.parameters(2).symbol = 'dynamixel_control_P.ASCIIEncode_P1';
xcp.parameters(2).size   =  15;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&dynamixel_control_P.ASCIIEncode_P1[0]';     
         
xcp.parameters(3).symbol = 'dynamixel_control_P.ASCIIEncode_P2';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&dynamixel_control_P.ASCIIEncode_P2';     
         
xcp.parameters(4).symbol = 'dynamixel_control_P.ASCIIEncode_P3';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&dynamixel_control_P.ASCIIEncode_P3';     
         
xcp.parameters(5).symbol = 'dynamixel_control_P.ASCIIEncode_P4';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&dynamixel_control_P.ASCIIEncode_P4';     
         
xcp.parameters(6).symbol = 'dynamixel_control_P.Setup1_P1';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&dynamixel_control_P.Setup1_P1';     
         
xcp.parameters(7).symbol = 'dynamixel_control_P.Setup1_P2';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&dynamixel_control_P.Setup1_P2';     
         
xcp.parameters(8).symbol = 'dynamixel_control_P.Setup1_P3';
xcp.parameters(8).size   =  1;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&dynamixel_control_P.Setup1_P3';     
         
xcp.parameters(9).symbol = 'dynamixel_control_P.Setup1_P4';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&dynamixel_control_P.Setup1_P4';     
         
xcp.parameters(10).symbol = 'dynamixel_control_P.Setup1_P5';
xcp.parameters(10).size   =  1;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&dynamixel_control_P.Setup1_P5';     
         
xcp.parameters(11).symbol = 'dynamixel_control_P.Setup1_P6';
xcp.parameters(11).size   =  1;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&dynamixel_control_P.Setup1_P6';     
         
xcp.parameters(12).symbol = 'dynamixel_control_P.Setup1_P7';
xcp.parameters(12).size   =  1;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&dynamixel_control_P.Setup1_P7';     
         
xcp.parameters(13).symbol = 'dynamixel_control_P.Setup1_P8';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&dynamixel_control_P.Setup1_P8';     
         
xcp.parameters(14).symbol = 'dynamixel_control_P.Setup2_P1';
xcp.parameters(14).size   =  1;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&dynamixel_control_P.Setup2_P1';     
         
xcp.parameters(15).symbol = 'dynamixel_control_P.Setup2_P2';
xcp.parameters(15).size   =  1;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&dynamixel_control_P.Setup2_P2';     
         
xcp.parameters(16).symbol = 'dynamixel_control_P.Setup2_P3';
xcp.parameters(16).size   =  1;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&dynamixel_control_P.Setup2_P3';     
         
xcp.parameters(17).symbol = 'dynamixel_control_P.Setup2_P4';
xcp.parameters(17).size   =  1;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&dynamixel_control_P.Setup2_P4';     
         
xcp.parameters(18).symbol = 'dynamixel_control_P.Setup2_P5';
xcp.parameters(18).size   =  1;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&dynamixel_control_P.Setup2_P5';     
         
xcp.parameters(19).symbol = 'dynamixel_control_P.Setup2_P6';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&dynamixel_control_P.Setup2_P6';     
         
xcp.parameters(20).symbol = 'dynamixel_control_P.Setup2_P7';
xcp.parameters(20).size   =  1;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&dynamixel_control_P.Setup2_P7';     
         
xcp.parameters(21).symbol = 'dynamixel_control_P.Setup2_P8';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&dynamixel_control_P.Setup2_P8';     
         
xcp.parameters(22).symbol = 'dynamixel_control_P.Constant_Value';
xcp.parameters(22).size   =  1;       
xcp.parameters(22).dtname = 'uint32_T'; 
xcp.parameters(23).baseaddr = '&dynamixel_control_P.Constant_Value';     
         
xcp.parameters(23).symbol = 'dynamixel_control_P.Constant_Value_e';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'uint32_T'; 
xcp.parameters(24).baseaddr = '&dynamixel_control_P.Constant_Value_e';     
         
xcp.parameters(24).symbol = 'dynamixel_control_P.Constant1_Value';
xcp.parameters(24).size   =  1;       
xcp.parameters(24).dtname = 'uint32_T'; 
xcp.parameters(25).baseaddr = '&dynamixel_control_P.Constant1_Value';     
         
xcp.parameters(25).symbol = 'dynamixel_control_P.Constant2_Value';
xcp.parameters(25).size   =  1;       
xcp.parameters(25).dtname = 'uint32_T'; 
xcp.parameters(26).baseaddr = '&dynamixel_control_P.Constant2_Value';     

function n = getNumParameters
n = 25;

function n = getNumSignals
n = 21;

function n = getNumEvents
n = 3;

function n = getNumModels
n = 1;

