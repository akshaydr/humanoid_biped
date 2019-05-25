function xcp = slrttestmdlxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'slrttestmdl';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.00025;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'slrttestmdl_B.Gain';
    
xcp.signals(2).symbol =  'slrttestmdl_B.Gain1';
    
xcp.signals(3).symbol =  'slrttestmdl_B.Gain2';
    
xcp.signals(4).symbol =  'slrttestmdl_B.Integrator';
    
xcp.signals(5).symbol =  'slrttestmdl_B.Integrator1';
    
xcp.signals(6).symbol =  'slrttestmdl_B.SignalGenerator';
    
xcp.signals(7).symbol =  'slrttestmdl_B.Sum';
         
xcp.parameters(1).symbol = 'slrttestmdl_P.Gain_Gain';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&slrttestmdl_P.Gain_Gain';     
         
xcp.parameters(2).symbol = 'slrttestmdl_P.Gain1_Gain';
xcp.parameters(2).size   =  1;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&slrttestmdl_P.Gain1_Gain';     
         
xcp.parameters(3).symbol = 'slrttestmdl_P.Gain2_Gain';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&slrttestmdl_P.Gain2_Gain';     
         
xcp.parameters(4).symbol = 'slrttestmdl_P.Integrator_IC';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&slrttestmdl_P.Integrator_IC';     
         
xcp.parameters(5).symbol = 'slrttestmdl_P.Integrator1_IC';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&slrttestmdl_P.Integrator1_IC';     
         
xcp.parameters(6).symbol = 'slrttestmdl_P.SignalGenerator_Amplitude';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&slrttestmdl_P.SignalGenerator_Amplitude';     
         
xcp.parameters(7).symbol = 'slrttestmdl_P.SignalGenerator_Frequency';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&slrttestmdl_P.SignalGenerator_Frequency';     

function n = getNumParameters
n = 7;

function n = getNumSignals
n = 7;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

