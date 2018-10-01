function pt=testpt
pt = [];

  
pt(1).blockname = 'u1_value /Constant';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'test_P.Constant_Value';
pt(1).baseaddr   = '&test_P.Constant_Value';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'u1_value /Look-Up Table1';
pt(2).paramname = 'BreakpointsForDimension1';
pt(2).class     = 'vector';
pt(2).nrows     = 1;
pt(2).ncols     = 40;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'test_P.LookUpTable1_bp01Data';
pt(2).baseaddr   = '&test_P.LookUpTable1_bp01Data[0]';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = '';
pt(3).paramname = 'u1';
pt(3).class     = 'vector';
pt(3).nrows     = 1;
pt(3).ncols     = 40;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'test_P.u1';
pt(3).baseaddr   = '&test_P.u1[0]';
pt(3).dtname     = 'real_T';


function len = getlenPT
len = 3;

