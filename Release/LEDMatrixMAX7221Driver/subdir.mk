################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LEDMatrixMAX7221Driver/LEDMatrixDriverMAX7221.cpp 

OBJS += \
./LEDMatrixMAX7221Driver/LEDMatrixDriverMAX7221.o 

CPP_DEPS += \
./LEDMatrixMAX7221Driver/LEDMatrixDriverMAX7221.d 


# Each subdirectory must supply rules for building sources it contributes
LEDMatrixMAX7221Driver/%.o: ../LEDMatrixMAX7221Driver/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LEDMatrixDriver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LEDMatrixMAX7219Driver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LEDMatrixMAX7221Driver" -I"/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/MAX7219Driver" -I"/home/dalmir/workspace/ArduinoCore" -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

