function sys=Copy_of_Robot_leg_3_0ref
sys = [];
sys.child = [];
sys.NumDataTypes = 4; 
sys.DataTypes = [];
temp.EnumNames='';
temp.EnumValues = [];
temp.Name = '';
sys.DataTypes = repmat(temp,1,4);
sys.DataTypes(1).Name = 'real_T';
sys.DataTypes(2).Name = 'uint8_T';
sys.DataTypes(3).Name = 'uint32_T';
sys.DataTypes(4).Name = 'boolean_T';
