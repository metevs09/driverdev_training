################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../devdriver/Src/EXTI.c \
../devdriver/Src/GPIO.c \
../devdriver/Src/RCC.c \
../devdriver/Src/SPI.c 

OBJS += \
./devdriver/Src/EXTI.o \
./devdriver/Src/GPIO.o \
./devdriver/Src/RCC.o \
./devdriver/Src/SPI.o 

C_DEPS += \
./devdriver/Src/EXTI.d \
./devdriver/Src/GPIO.d \
./devdriver/Src/RCC.d \
./devdriver/Src/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
devdriver/Src/%.o devdriver/Src/%.su devdriver/Src/%.cyclo: ../devdriver/Src/%.c devdriver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/lenovo/STM32CubeIDE/EmbeddedDrivers/driverdev_training/devdriver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-devdriver-2f-Src

clean-devdriver-2f-Src:
	-$(RM) ./devdriver/Src/EXTI.cyclo ./devdriver/Src/EXTI.d ./devdriver/Src/EXTI.o ./devdriver/Src/EXTI.su ./devdriver/Src/GPIO.cyclo ./devdriver/Src/GPIO.d ./devdriver/Src/GPIO.o ./devdriver/Src/GPIO.su ./devdriver/Src/RCC.cyclo ./devdriver/Src/RCC.d ./devdriver/Src/RCC.o ./devdriver/Src/RCC.su ./devdriver/Src/SPI.cyclo ./devdriver/Src/SPI.d ./devdriver/Src/SPI.o ./devdriver/Src/SPI.su

.PHONY: clean-devdriver-2f-Src

