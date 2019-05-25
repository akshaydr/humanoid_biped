function bio=testbio
bio = [];
bio(1).blkName='u1_value /Output';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&test_B.Output';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

function len = getlenBIO
len = 1;

