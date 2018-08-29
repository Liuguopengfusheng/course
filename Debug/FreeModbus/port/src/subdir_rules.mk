################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FreeModbus/port/src/port.obj: ../FreeModbus/port/src/port.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeModbus/port/src/port.d_raw" --obj_directory="FreeModbus/port/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeModbus/port/src/portevent.obj: ../FreeModbus/port/src/portevent.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeModbus/port/src/portevent.d_raw" --obj_directory="FreeModbus/port/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeModbus/port/src/portevent_m.obj: ../FreeModbus/port/src/portevent_m.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeModbus/port/src/portevent_m.d_raw" --obj_directory="FreeModbus/port/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeModbus/port/src/portserial.obj: ../FreeModbus/port/src/portserial.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeModbus/port/src/portserial.d_raw" --obj_directory="FreeModbus/port/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeModbus/port/src/portserial_m.obj: ../FreeModbus/port/src/portserial_m.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeModbus/port/src/portserial_m.d_raw" --obj_directory="FreeModbus/port/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeModbus/port/src/porttimer.obj: ../FreeModbus/port/src/porttimer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeModbus/port/src/porttimer.d_raw" --obj_directory="FreeModbus/port/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeModbus/port/src/porttimer_m.obj: ../FreeModbus/port/src/porttimer_m.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/ascii" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/user_lib/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/functions" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/include" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/port/inc" --include_path="D:/workspace_v8/FreeModBus_Master_Slaver/FreeModbus/modbus/rtu" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="FreeModbus/port/src/porttimer_m.d_raw" --obj_directory="FreeModbus/port/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


