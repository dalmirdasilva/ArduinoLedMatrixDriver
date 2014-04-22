################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LedMatrixDriver/LedMatrixDriver.cpp 

OBJS += \
./LedMatrixDriver/LedMatrixDriver.o 

CPP_DEPS += \
./LedMatrixDriver/LedMatrixDriver.d 


# Each subdirectory must supply rules for building sources it contributes
LedMatrixDriver/%.o: ../LedMatrixDriver/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard -I"/home/dalmir/workspace/ArduinoCore" -I"/storage/microcontroller/arduino/driver/led/ArduinoLedMatrixDriver/LedMatrixDriver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLedMatrixDriver/LedMatrixMAX7219Driver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLedMatrixDriver/LedMatrixMAX7221Driver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLedMatrixDriver/MAX7219Driver" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


