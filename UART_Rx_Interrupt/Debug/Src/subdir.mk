################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4 -DSTM32 -DSTM32L452RETx -DNUCLEO_L452RE -DDEBUG -c -I../Inc -I"D:/STM Workspace/Practice_WorkSpace/UART_Rx_Interrupt/CMSIS/Include" -I"D:/STM Workspace/Practice_WorkSpace/UART_Rx_Interrupt/CMSIS/Device/ST/STM32L4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4 -DSTM32 -DSTM32L452RETx -DNUCLEO_L452RE -DDEBUG -c -I../Inc -I"D:/STM Workspace/Practice_WorkSpace/UART_Rx_Interrupt/CMSIS/Include" -I"D:/STM Workspace/Practice_WorkSpace/UART_Rx_Interrupt/CMSIS/Device/ST/STM32L4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4 -DSTM32 -DSTM32L452RETx -DNUCLEO_L452RE -DDEBUG -c -I../Inc -I"D:/STM Workspace/Practice_WorkSpace/UART_Rx_Interrupt/CMSIS/Include" -I"D:/STM Workspace/Practice_WorkSpace/UART_Rx_Interrupt/CMSIS/Device/ST/STM32L4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

