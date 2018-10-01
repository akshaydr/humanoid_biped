function xcp = testxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'test';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.2;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'test_B.Output';
         
xcp.parameters(1).symbol = 'test_P.Constant_Value';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&test_P.Constant_Value';     
         
xcp.parameters(2).symbol = 'test_P.LookUpTable1_bp01Data';
xcp.parameters(2).size   =  40;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&test_P.LookUpTable1_bp01Data[0]';     
         
xcp.parameters(3).symbol = 'test_P.u1';
xcp.parameters(3).size   =  40;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&test_P.u1[0]';     

function n = getNumParameters
n = 3;

function n = getNumSignals
n = 1;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

