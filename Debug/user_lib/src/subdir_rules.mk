################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
user_lib/src/DSP2833x_Adc.obj: ../user_lib/src/DSP2833x_Adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_Adc.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_CpuTimers.obj: ../user_lib/src/DSP2833x_CpuTimers.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_CpuTimers.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_DefaultIsr.obj: ../user_lib/src/DSP2833x_DefaultIsr.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_DefaultIsr.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_ECan.obj: ../user_lib/src/DSP2833x_ECan.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_ECan.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_GlobalVariableDefs.obj: ../user_lib/src/DSP2833x_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_GlobalVariableDefs.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_Gpio.obj: ../user_lib/src/DSP2833x_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_Gpio.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_MemCopy.obj: ../user_lib/src/DSP2833x_MemCopy.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_MemCopy.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_PieCtrl.obj: ../user_lib/src/DSP2833x_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_PieCtrl.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_PieVect.obj: ../user_lib/src/DSP2833x_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_PieVect.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_Sci.obj: ../user_lib/src/DSP2833x_Sci.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_Sci.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/DSP2833x_SysCtrl.obj: ../user_lib/src/DSP2833x_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/DSP2833x_SysCtrl.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

user_lib/src/delay.obj: ../user_lib/src/delay.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="user_lib/src/delay.d_raw" --obj_directory="user_lib/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


