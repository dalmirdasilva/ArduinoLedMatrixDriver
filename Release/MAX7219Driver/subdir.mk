################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MAX7219Driver/MAX7219Driver.cpp 

OBJS += \
./MAX7219Driver/MAX7219Driver.o 

CPP_DEPS += \
./MAX7219Driver/MAX7219Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MAX7219Driver/%.o: ../MAX7219Driver/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/storage/microcontroller/arduino/driver/led/ArduinoLedMatrixDriver/LedMatrixDriver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLedMatrixDriver/LedMatrixMAX7219Driver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLedMatrixDriver/LedMatrixMAX7221Driver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLedMatrixDriver/MAX7219Driver" -I"/home/dalmir/workspace/ArduinoCore" -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


