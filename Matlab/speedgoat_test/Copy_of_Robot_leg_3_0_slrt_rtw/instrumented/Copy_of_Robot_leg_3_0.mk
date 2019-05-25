# Copyright 1996-2017 The MathWorks, Inc.
#
# File    : slrt_vc.tmf 
#
#
# Abstract:
#       Makefile for building a Simulink Real-Time application from a Simulink
#       model using generated C code and a supported Microsoft Visual C/C++
#       compiler
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#    OPT_OPTS       - Optimization option. Default is -O2. To enable
#                     debugging specify as OPT_OPTS=-Zd.
#    OPTS           - User specific options.
#    USER_SRCS      - Additional user sources, such as files needed by
#                     S-functions.
#    USER_INCLUDES  - Additional include paths
#                     (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the code generation build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the code generation build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.
HOST            = PC
BUILD           = yes
MAKECMD         = nmake
SYS_TARGET_FILE = slrt.tlc
COMPILER_TOOL_CHAIN = vc

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = [\
    "Microsoft Visual C++ 2017 v15.0 | nmake (64-bit Windows)", \
    "Microsoft Visual C++ 2015 v14.0 | nmake (64-bit Windows)", \
    "Microsoft Visual C++ 2013 v12.0 | nmake (64-bit Windows)"]

DEBUG_BUILD     = 0

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "|<" are expanded by the
# build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to were MATLAB is installed.
#  MATLAB_BIN      - Path to MATLAB executable.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  BUILDARGS       - Options passed in at the command line.
#  MULTITASKING    - yes (1) or no (0): Is solver mode multitasking
#  MEX_OPT_FILE    - Original file name of the mexopt.bat.

MODEL           = Copy_of_Robot_leg_3_0
MODULES         = Copy_of_Robot_leg_3_0_7d8ca6e_1.c Copy_of_Robot_leg_3_0_7d8ca6e_1_create.c Copy_of_Robot_leg_3_0_7d8ca6e_1_setParameters.c Copy_of_Robot_leg_3_0_7d8ca6e_1_asserts.c Copy_of_Robot_leg_3_0_7d8ca6e_1_deriv.c Copy_of_Robot_leg_3_0_7d8ca6e_1_checkDynamics.c Copy_of_Robot_leg_3_0_7d8ca6e_1_outputKin.c Copy_of_Robot_leg_3_0_7d8ca6e_1_outputDyn.c Copy_of_Robot_leg_3_0_7d8ca6e_1_assembly.c Copy_of_Robot_leg_3_0_7d8ca6e_1_computeConstraintError.c Copy_of_Robot_leg_3_0_7d8ca6e_1_gateway.c pm_printf.c rt_matrx.c rt_printf.c rt_logging.c rt_backsubrr_dbl.c rt_forwardsubrr_dbl.c rt_lu_real.c rt_matrixlib_dbl.c Copy_of_Robot_leg_3_0.c Copy_of_Robot_leg_3_0_capi.c Copy_of_Robot_leg_3_0_data.c Copy_of_Robot_leg_3_0_xcp.c Copy_of_Robot_leg_3_0_xcp_TET.c rtGetInf.c rtGetNaN.c rt_nonfinite.c xpc_datatype_ground.c rt_logging_mmi.c rtw_modelmap_utils.c host_timer_x86.c xpc_code_profiling_utility_functions.c
MAKEFILE        = Copy_of_Robot_leg_3_0.mk
MATLAB_ROOT     = C:\Program Files\MATLAB\R2018a
ALT_MATLAB_ROOT = C:\PROGRA~1\MATLAB\R2018a
MATLAB_BIN      = C:\Program Files\MATLAB\R2018a\bin
ALT_MATLAB_BIN  = C:\PROGRA~1\MATLAB\R2018a\bin
MASTER_ANCHOR_DIR = 
START_DIR       = C:\Users\KLETech\Documents\Work\humanoid_biped-master\speedgoat_test
S_FUNCTIONS     = asciiencode.c slrtIPConfig.c slrtUDPSend.c
S_FUNCTIONS_LIB = 
NUMST           = 2
TID01EQ         = 1
NCSTATES        = 37
BUILDARGS       =  COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 ISPROTECTINGMODEL=NOTPROTECTING
MULTITASKING    = 0
MEX_OPT_FILE    = -f "C:\Program Files\MATLAB\R2018a\bin\win64\mexopts\msvc2017.xml"

MODELREFS       = 
SHARED_SRC      = 
SHARED_SRC_DIR  = 
SHARED_BIN_DIR  = 
SHARED_LIB      = 
VISUAL_VER      = 15.0
TGT_FCN_LIB     = XPC_BLAS

OPTIMIZATION_FLAGS   = /O2 /Oy-
ADDITIONAL_LDFLAGS   = 
DEFINES_CUSTOM       = 

#--------------------------- Model and reference models -----------------------
MODELLIB                  = Copy_of_Robot_leg_3_0lib.lib
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = Copy_of_Robot_leg_3_0_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..\..
# ..\..\..\..\..\..\.. or .. or even . if you want it
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif
MATLAB_ARCH_BIN = $(MATLAB_BIN)\win64

#--------------------------- Tool Specifications ------------------------------

CPU=i386
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

CMD_FILE             = $(MODEL).rsp

#------------------------------ Include/Lib Path ------------------------------

MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\libsrc
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional file include paths
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)\Copy_of_Robot_leg_3_0_slrt_rtw
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\sm\core\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\pm_math\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\network_engine\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\common\math\core\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\common\lang\core\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\common\external\library\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c\win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\simulink\include\messages
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\include


XPC_BASE = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build

XPC_INCLUDES = $(XPC_BASE)\include;$(XPC_BASE)\xpcblocks\include
XPC_INCLUDES = $(XPC_INCLUDES);$(XPC_BASE)\xpcblocks\thirdpartydrivers
XPC_INCLUDES = $(XPC_INCLUDES);$(MATLAB_ROOT)\toolbox\slrt\target\kernel\include
INCLUDE      = .;..;$(XPC_INCLUDES);$(MATLAB_INCLUDES);$(INCLUDE);$(MODELREF_INC_PATH)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)
!endif

#----------------- Compiler and Linker Options --------------------------------
# Optimization Options
DEFAULT_OPT_OPTS = /W3 /Z7
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =
#/GD

CC_OPTS = $(OPTS) $(OPT_OPTS) /c /nologo $(OPTIMIZATION_FLAGS) 

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
                  -DMT=$(MULTITASKING) -DHAVESTDIO -DXPCMSVISUALC \
                  -DXPCCALLCONV=__cdecl  -DUSE_RTMODEL -DERT_CORE \
                  $(DEFINES_CUSTOM)

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS = $(cvarsmt) /wd4996 /fp:fast /arch:SSE2 $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
CPPFLAGS = $(cflags) $(cvarsmt) /wd4996 /fp:fast /arch:SSE2 /EHsc \
           $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
!if "$(SLRTFTZOFF)" != ""
CFLAGS = $(cvarsmt) $(CFLAGS_VERSPECIFIC) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
CPPFLAGS = $(cflags) $(cvarsmt) $(CPPFLAGS_VERSPECIFIC) /EHsc \
           $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
!endif


LDFLAGS = /NOLOGO /DLL /SUBSYSTEM:CONSOLE /DEF:xpcvcdll.def  /Include:_malloc /MAP /DEBUG /IGNORE:4099 $(ADDITIONAL_LDFLAGS)

#----------------------------- Source Files -----------------------------------
#Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).dlm
SLRT_SRCS = xpctarget.c appmappingData.c legacy_stdio.c
REQ_SRCS  = $(MODULES) $(SLRT_SRCS)

#Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)
!endif


USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
SHARED_OBJS = $(SHARED_BIN_DIR)\*.obj

# Special handling for object files that are not in the pre-generated linker
# response file
SLRT_OBJS = $(SLRT_SRCS:.c=.obj)

# ------------------------- Libraries ------------------------------
LIBS =

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\sm\ssci\lib\win64\sm_ssci_vc.lib
!else
LIBS = $(LIBS) sm_ssci.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\sm\core\lib\win64\sm_vc.lib
!else
LIBS = $(LIBS) sm.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\pm_math\lib\win64\pm_math_vc.lib
!else
LIBS = $(LIBS) pm_math.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\lib\win64\ssc_sli_vc.lib
!else
LIBS = $(LIBS) ssc_sli.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\lib\win64\ssc_core_vc.lib
!else
LIBS = $(LIBS) ssc_core.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\network_engine\lib\win64\ne_vc.lib
!else
LIBS = $(LIBS) ne.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\common\math\core\lib\win64\mc_vc.lib
!else
LIBS = $(LIBS) mc.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\common\external\library\lib\win64\ex_vc.lib
!else
LIBS = $(LIBS) ex.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\lib\win64\pm_vc.lib
!else
LIBS = $(LIBS) pm.lib
!endif 

LIBS = $(LIBS) xpcruntime.lib

!if "$(TGT_FCN_LIB)" == "XPC_BLAS"
BLASLIBS = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\lib\libatlas.a $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\lib\libcblas.a
!else
BLASLIBS = 
!endif

#--------------------------------- Rules --------------------------------------
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).dlm : $(MODEL)_slrt.dll
	$(MATLAB_ROOT)\toolbox\slrt\target\thirdparty\OnTime\bin\mkusrdlm -c+ -q+ $(MODEL)_slrt.dll $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL)
	@cmd /C "echo ### Created DLM $@"
	@del $(MODEL)_slrt.lib

$(MODEL)_slrt.dll : set_environment_variables $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) $(LDFLAGS) $(BLASLIBS) $(LIBS) $(S_FUNCTIONS_LIB) $(CANLIB) $(SHARED_LIB) $(SLRT_OBJS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@cmd /C "echo ### Created DLL $@"

!else
#--- Model reference Target ---
$(PRODUCT) : set_environment_variables $(OBJS) $(SHARED_LIB) $(LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB) $(BLASLIBS)
	@cmd /C "echo ### Created static library $(MODELLIB)"
!endif

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

xpcruntime.lib: xpcimports.obj xpcPCFunctions.obj
	$(LIBCMD) /nologo /out:$@ $**

# Additional sources

{$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\sm\core\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\pm_math\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\network_engine\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\common\math\core\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\common\lang\core\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\common\external\library\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c\win64}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\slrt\blocks\UDP}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{..}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\coder\profile\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<


{$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\sm\core\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\pm_math\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\network_engine\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\common\math\core\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\common\lang\core\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\common\external\library\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c\win64}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\slrt\blocks\UDP}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{..}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\profile\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

# Libraries:



MODULES_sm_ssci = \
	sm_ssci_3dd14f0a.obj \
	sm_ssci_646478c5.obj \
	sm_ssci_916e6db1.obj \
	sm_ssci_b2b6b422.obj \
	sm_ssci_c16a187b.obj \


sm_ssci.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_sm_ssci)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_sm_ssci)
	@cmd /C "echo ### Created $@"

MODULES_sm = \
	sm_440126a7.obj \
	sm_6166f1eb.obj \
	sm_62d41fb5.obj \
	sm_67d72683.obj \
	sm_6fbd150d.obj \
	sm_73d210b9.obj \
	sm_9abcb56e.obj \
	sm_acba2496.obj \
	sm_badd8656.obj \
	sm_bc63e36c.obj \
	sm_c0ba649d.obj \
	sm_d3d946fd.obj \
	sm_e8bab6d7.obj \
	sm_efdfa66e.obj \
	sm_f7683dd1.obj \


sm.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_sm)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_sm)
	@cmd /C "echo ### Created $@"

MODULES_pm_math = \
	pm_math_1966ea7d.obj \
	pm_math_1ad202b7.obj \
	pm_math_1c69d5b2.obj \
	pm_math_2cdd2951.obj \
	pm_math_3463da5d.obj \
	pm_math_360e4b46.obj \
	pm_math_48bd51fb.obj \
	pm_math_5a01dda4.obj \
	pm_math_646fa971.obj \
	pm_math_a001e9ec.obj \
	pm_math_b7b980b1.obj \
	pm_math_bad43c87.obj \
	pm_math_d1be0f30.obj \
	pm_math_da630bd2.obj \
	pm_math_f760e8f6.obj \


pm_math.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_pm_math)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_pm_math)
	@cmd /C "echo ### Created $@"

MODULES_ssc_sli = \
	ssc_sli_0763c151.obj \
	ssc_sli_0bd269e6.obj \
	ssc_sli_136b443c.obj \
	ssc_sli_140b3534.obj \
	ssc_sli_2bbd58a4.obj \
	ssc_sli_360cfd63.obj \
	ssc_sli_43618287.obj \
	ssc_sli_466b08dd.obj \
	ssc_sli_4e028390.obj \
	ssc_sli_51dbd3b5.obj \
	ssc_sli_550a4805.obj \
	ssc_sli_5a0cb974.obj \
	ssc_sli_5d63aeeb.obj \
	ssc_sli_62d81790.obj \
	ssc_sli_77063d8b.obj \
	ssc_sli_7a618260.obj \
	ssc_sli_7f630b0f.obj \
	ssc_sli_880e593a.obj \
	ssc_sli_89d0f30a.obj \
	ssc_sli_8a64c4e2.obj \
	ssc_sli_93019ea6.obj \
	ssc_sli_9abcdb7f.obj \
	ssc_sli_9b67747c.obj \
	ssc_sli_9c030181.obj \
	ssc_sli_c7dda239.obj \
	ssc_sli_d064c978.obj \
	ssc_sli_dcd66f69.obj \
	ssc_sli_e7b327bb.obj \
	ssc_sli_eb0a5702.obj \
	ssc_sli_f6bd9cc8.obj \
	ssc_sli_f9b5dbc5.obj \
	ssc_sli_fa0ce53e.obj \
	ssc_sli_fbdf29da.obj \


ssc_sli.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ssc_sli)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ssc_sli)
	@cmd /C "echo ### Created $@"

MODULES_ssc_core = \
	ssc_core_01dcc633.obj \
	ssc_core_04da2c69.obj \
	ssc_core_05058dd9.obj \
	ssc_core_06ba68a6.obj \
	ssc_core_09b5fa6e.obj \
	ssc_core_0bd666aa.obj \
	ssc_core_0f019bd9.obj \
	ssc_core_0f0420a6.obj \
	ssc_core_18bf4d77.obj \
	ssc_core_1b0cafd5.obj \
	ssc_core_1c6b0332.obj \
	ssc_core_1fd25120.obj \
	ssc_core_24b4cdee.obj \
	ssc_core_2568b075.obj \
	ssc_core_280c0222.obj \
	ssc_core_2cd54448.obj \
	ssc_core_3169e4b7.obj \
	ssc_core_360a4baf.obj \
	ssc_core_37d4ea84.obj \
	ssc_core_40dfdbdc.obj \
	ssc_core_41017299.obj \
	ssc_core_4666b45b.obj \
	ssc_core_48b08af1.obj \
	ssc_core_48b1386a.obj \
	ssc_core_4965213d.obj \
	ssc_core_4ad9135b.obj \
	ssc_core_4db6bd68.obj \
	ssc_core_4db86fcc.obj \
	ssc_core_4e03e39d.obj \
	ssc_core_4e04eecd.obj \
	ssc_core_54d55ae9.obj \
	ssc_core_5505224d.obj \
	ssc_core_56b1a2bf.obj \
	ssc_core_576cd129.obj \
	ssc_core_59b034b8.obj \
	ssc_core_5d6ba758.obj \
	ssc_core_67d1f118.obj \
	ssc_core_68da074b.obj \
	ssc_core_6b6b89d2.obj \
	ssc_core_6dd833f3.obj \
	ssc_core_73d9c2b7.obj \
	ssc_core_76d825be.obj \
	ssc_core_79dd08ab.obj \
	ssc_core_7a613edb.obj \
	ssc_core_83db8762.obj \
	ssc_core_856738f2.obj \
	ssc_core_8569edc5.obj \
	ssc_core_8a6471dc.obj \
	ssc_core_8d0064b8.obj \
	ssc_core_96061071.obj \
	ssc_core_97d767fe.obj \
	ssc_core_9b607b15.obj \
	ssc_core_9c016445.obj \
	ssc_core_9c01d168.obj \
	ssc_core_9dd110ad.obj \
	ssc_core_9fb0e229.obj \
	ssc_core_9fb25b4f.obj \
	ssc_core_a1d393be.obj \
	ssc_core_a4d4c45e.obj \
	ssc_core_a4da1d0a.obj \
	ssc_core_a6b78ccc.obj \
	ssc_core_a76299bc.obj \
	ssc_core_a867d880.obj \
	ssc_core_a9bf1ff2.obj \
	ssc_core_abd05c18.obj \
	ssc_core_abd5e7b4.obj \
	ssc_core_acb64294.obj \
	ssc_core_acb6462e.obj \
	ssc_core_b1038cbb.obj \
	ssc_core_b10e34f4.obj \
	ssc_core_b2b3b239.obj \
	ssc_core_b3671372.obj \
	ssc_core_b402b40d.obj \
	ssc_core_b7b88213.obj \
	ssc_core_b96ebc21.obj \
	ssc_core_bb0b2992.obj \
	ssc_core_bc648043.obj \
	ssc_core_c3003040.obj \
	ssc_core_c5b050d7.obj \
	ssc_core_c5b63cb2.obj \
	ssc_core_c607b660.obj \
	ssc_core_c8d83e88.obj \
	ssc_core_cab615c8.obj \
	ssc_core_cabdc251.obj \
	ssc_core_cc067f58.obj \
	ssc_core_ce6a84bb.obj \
	ssc_core_d06d763c.obj \
	ssc_core_d3d34d7c.obj \
	ssc_core_d70a6a09.obj \
	ssc_core_d807fa59.obj \
	ssc_core_d9d13dac.obj \
	ssc_core_dcda6edd.obj \
	ssc_core_deb7fd8d.obj \
	ssc_core_e0d0866d.obj \
	ssc_core_e2b61d72.obj \
	ssc_core_e400c1c2.obj \
	ssc_core_ee000fbe.obj \
	ssc_core_ee01086d.obj \
	ssc_core_ee0f0141.obj \
	ssc_core_f9b6dbed.obj \
	ssc_core_fa09e9e6.obj \
	ssc_core_fbd34e62.obj \
	ssc_core_ff06d9a4.obj \


ssc_core.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ssc_core)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ssc_core)
	@cmd /C "echo ### Created $@"

MODULES_ne = \
	ne_59b4e14a.obj \


ne.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ne)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ne)
	@cmd /C "echo ### Created $@"

MODULES_mc = \
	mc_026e4f4b.obj \
	mc_03b98f6f.obj \
	mc_0bd30dee.obj \
	mc_0d6fd085.obj \
	mc_0ed73c49.obj \
	mc_11086079.obj \
	mc_110e6c6c.obj \
	mc_15d12d95.obj \
	mc_15d828ca.obj \
	mc_220ba961.obj \
	mc_2565d6e0.obj \
	mc_2a642f54.obj \
	mc_2a6a9b24.obj \
	mc_2bbf87e3.obj \
	mc_2cdc96b4.obj \
	mc_32d501e3.obj \
	mc_32dc008a.obj \
	mc_3b6a945d.obj \
	mc_3e66abdf.obj \
	mc_4105189f.obj \
	mc_47b8cebe.obj \
	mc_47b91db1.obj \
	mc_4b0301c6.obj \
	mc_4c6117e3.obj \
	mc_51d4094e.obj \
	mc_52623861.obj \
	mc_52688a58.obj \
	mc_53b1fc84.obj \
	mc_550847c3.obj \
	mc_5766048f.obj \
	mc_59b6e413.obj \
	mc_5d65cd86.obj \
	mc_630208f8.obj \
	mc_630dda0e.obj \
	mc_67da200d.obj \
	mc_67da4f41.obj \
	mc_6b6d311a.obj \
	mc_6e61d16c.obj \
	mc_6fb1c336.obj \
	mc_7a613aec.obj \
	mc_7bbf41f0.obj \
	mc_7cd58f0b.obj \
	mc_7cdbe436.obj \
	mc_7d0547c8.obj \
	mc_7d099de7.obj \
	mc_7eb21b39.obj \
	mc_81b0ada5.obj \
	mc_81b5717e.obj \
	mc_870ec75e.obj \
	mc_89d597cf.obj \
	mc_90b6aa0a.obj \
	mc_95b62b73.obj \
	mc_9ab7d9b0.obj \
	mc_9b6376d1.obj \
	mc_9b6c1529.obj \
	mc_a2647600.obj \
	mc_a26bab1a.obj \
	mc_a3b90582.obj \
	mc_a865d1dd.obj \
	mc_acb3fad7.obj \
	mc_af0cc4c9.obj \
	mc_b0de9cbc.obj \
	mc_b362c5eb.obj \
	mc_b7b03d44.obj \
	mc_b96a0bad.obj \
	mc_bb0520ee.obj \
	mc_bdbb9b78.obj \
	mc_c2dbf4b2.obj \
	mc_c8d25d23.obj \
	mc_cab8a1f9.obj \
	mc_d20085b7.obj \
	mc_d9d38185.obj \
	mc_dbbb14d2.obj \
	mc_dcdddfae.obj \
	mc_debb448f.obj \
	mc_e7bc2f1a.obj \
	mc_e969ae87.obj \
	mc_edbf543c.obj \
	mc_ee000fbe.obj \
	mc_efdea3a7.obj \
	mc_f3be157c.obj \
	mc_fcb15a9b.obj \
	mc_fd619d14.obj \
	mc_fd6341bb.obj \


mc.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_mc)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_mc)
	@cmd /C "echo ### Created $@"

MODULES_ex = \
	ex_04d5441d.obj \
	ex_136645f8.obj \
	ex_17bc61ac.obj \
	ex_18b4440a.obj \
	ex_2ebcd5b2.obj \
	ex_316a81de.obj \
	ex_40d5be33.obj \
	ex_47b11894.obj \
	ex_690b7cd0.obj \
	ex_79d100f1.obj \
	ex_8a6fc761.obj \
	ex_b2b40ad5.obj \
	ex_bb0efd4b.obj \
	ex_debffef2.obj \
	ex_e40d74b8.obj \
	ex_f866102d.obj \


ex.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ex)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ex)
	@cmd /C "echo ### Created $@"

MODULES_pm = \
	pm_09bc42e2.obj \
	pm_14098e54.obj \
	pm_26dc3230.obj \
	pm_4fd5f5b9.obj \
	pm_fed8c2c9.obj \


pm.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_pm)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_pm)
	@cmd /C "echo ### Created $@"



# Put this rule last, otherwise nmake will check toolboxes first

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\include}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

xpctarget.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src\xpctarget.c xpcoptions.h
	@cmd /C "echo ### Compiling xpctarget.c"
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src\xpctarget.c

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\thirdpartydrivers}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{..}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@cmd /C "echo ### Creating $@"
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ $?
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@cmd /C "echo ### $@ Created"
!endif

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

xpcPCFunctions.obj xpcimports.obj: $(MAKEFILE) rtw_proj.tmw
