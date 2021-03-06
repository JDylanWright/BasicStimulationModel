###########################################################################
## Makefile generated for component 'UECU_Speedgoat_threshold'. 
## 
## Makefile     : UECU_Speedgoat_threshold.mk
## Generated on : Thu Apr 14 16:43:09 2022
## Final product: $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = UECU_Speedgoat_threshold
MAKEFILE                  = UECU_Speedgoat_threshold.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2020b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/Graczyk/Desktop/ThresholdBasics
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C++
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ../..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
LIBUECU_OBJS              = ./LCDbacklight.o ./blockop.o ./ch_ev_owner.o ./ch_ev_param.o ./ch_ev_sched.o ./ch_sched.o ./ch_sched_state.o ./chan_setup.o ./clock_get.o ./create_ev.o ./create_sched.o ./del_ev.o ./del_sched.o ./errorpkt.o ./ev_cmd.o ./impl_setup.o ./melody.o ./morse.o ./newsync.o ./parityw.o ./sync.o ./textout.o ./uerror.o ./byteorder.o ./compat.o ./mailbox.o ./network.o ./packet.o ./qnx_ser.o ./slip.o ./uerrno.o ./ustrerror.o

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Simulink Real-Time Toolchain
# Supported Version(s):    
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# SLREALTIME_QNX_SP_ROOT

#-----------
# MACROS
#-----------

QCC_TARGET             = gcc_ntox86_64

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -L$(MATLAB_ROOT)/toolbox/slrealtime/target/lib -ltraceparser -lpps -lslrealtime_kernel -lslrealtime_rtps -lsocket -lboost_system -lboost_log -lpci -lopenblas

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: QNX C Compiler
CC = qcc

# Linker: QCC Linker
LD = q++

# C++ Compiler: QNX C++ Compiler
CPP = q++

# C++ Linker: QCC C++ Linker
CPP_LD = q++

# Archiver: QNX Archiver
AR = ntox86_64-gcc-ar

# Builder: GMAKE Utility
MAKE = make


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g -O0 -finstrument-functions
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g -O0 -finstrument-functions
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -V$(QCC_TARGET) -g \
                       -O2 -ffast-math -fwrapv
CPPFLAGS             = -c -V$(QCC_TARGET) -g -std=gnu++14 -stdlib=libstdc++ \
                       -O2 -ffast-math -fwrapv
CPP_LDFLAGS          = -V$(QCC_TARGET) -g -std=gnu++14 -stdlib=libstdc++
CPP_SHAREDLIB_LDFLAGS  = -V$(QCC_TARGET) -shared -Wl,--no-undefined -g
LDFLAGS              = -V$(QCC_TARGET) -g -std=gnu++14 -stdlib=libstdc++
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -V$(QCC_TARGET) -shared -Wl,--no-undefined -g



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -IC:/UECU/xpc/include -IC:/UECU/msglib -I$(MATLAB_ROOT)/toolbox/slrealtime/target/kernel/dist/include -I$(MATLAB_ROOT)/toolbox/slrealtime/simulink/blocks/dist/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DSIMULINK_REAL_TIME
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DEXT_MODE=1 -DMAT_FILE=0 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=UECU_Speedgoat_threshold -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/slrealtime_datatype_ground.c $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold.cpp $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold_cal.cpp $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold_data.cpp $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/rtGetInf.cpp $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/rtGetNaN.cpp $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/rt_nonfinite.cpp $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold_calintf.cpp $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/main.cpp $(MATLAB_ROOT)/toolbox/coder/profile/src/host_timer_x86.c $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/slrealtime_code_profiling_utility_functions.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = slrealtime_datatype_ground.o UECU_Speedgoat_threshold.o UECU_Speedgoat_threshold_cal.o UECU_Speedgoat_threshold_data.o rtGetInf.o rtGetNaN.o rt_nonfinite.o UECU_Speedgoat_threshold_calintf.o main.o host_timer_x86.o slrealtime_code_profiling_utility_functions.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = ./uecu.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) -Wl,--start-group $(LIBS) -Wl,--end-group $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/UECU/msglib/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : C:/UECU/msglib/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/UECU/xpc/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : C:/UECU/xpc/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : ../%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : ../%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/profile/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/profile/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


slrealtime_datatype_ground.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/slrealtime_datatype_ground.c
	$(CC) $(CFLAGS) -o $@ $<


UECU_Speedgoat_threshold.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


UECU_Speedgoat_threshold_cal.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold_cal.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


UECU_Speedgoat_threshold_data.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold_data.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rtGetInf.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rtGetNaN.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rt_nonfinite.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


UECU_Speedgoat_threshold_calintf.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/UECU_Speedgoat_threshold_calintf.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


main.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/main.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


host_timer_x86.o : $(MATLAB_ROOT)/toolbox/coder/profile/src/host_timer_x86.c
	$(CC) $(CFLAGS) -o $@ $<


slrealtime_code_profiling_utility_functions.o : $(START_DIR)/UECU_Speedgoat_threshold_slrealtime_rtw/slrealtime_code_profiling_utility_functions.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


#------------------------
# BUILDABLE LIBRARIES
#------------------------

./uecu.a : $(LIBUECU_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBUECU_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


