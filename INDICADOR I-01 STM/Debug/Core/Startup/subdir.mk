################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f103rctx.s 

OBJS += \
./Core/Startup/startup_stm32f103rctx.o 

S_DEPS += \
./Core/Startup/startup_stm32f103rctx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -I"C:/Users/ENGENHARIA - GABRIEL/Documents/Caio/Projetos/PROJETOS VERSIONADOS/I-01-STM/INDICADOR I-01 STM/libC" -I"C:/Users/ENGENHARIA - GABRIEL/Documents/Caio/Projetos/PROJETOS VERSIONADOS/I-01-STM/INDICADOR I-01 STM/eeprom" -I"C:/Users/ENGENHARIA - GABRIEL/Documents/Caio/Projetos/PROJETOS VERSIONADOS/I-01-STM/INDICADOR I-01 STM/seriais" -I"C:/Users/ENGENHARIA - GABRIEL/Documents/Caio/Projetos/PROJETOS VERSIONADOS/I-01-STM/INDICADOR I-01 STM/controleModBusRtu" -I"C:/Users/ENGENHARIA - GABRIEL/Documents/Caio/Projetos/PROJETOS VERSIONADOS/I-01-STM/INDICADOR I-01 STM/funcoes" -I"C:/Users/ENGENHARIA - GABRIEL/Documents/Caio/Projetos/PROJETOS VERSIONADOS/I-01-STM/INDICADOR I-01 STM/header" -I"C:/Users/ENGENHARIA - GABRIEL/Documents/Caio/Projetos/PROJETOS VERSIONADOS/I-01-STM/INDICADOR I-01 STM/libC/hx711" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f103rctx.d ./Core/Startup/startup_stm32f103rctx.o

.PHONY: clean-Core-2f-Startup

