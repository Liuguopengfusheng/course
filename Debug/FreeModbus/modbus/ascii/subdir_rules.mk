################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FreeModbus/modbus/ascii/mbascii.obj: ../FreeModbus/modbus/ascii/mbascii.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeModbus/modbus/ascii/mbascii.d_raw" --obj_directory="FreeModbus/modbus/ascii" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


