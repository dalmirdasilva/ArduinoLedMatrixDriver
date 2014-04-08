################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LEDMatrixDriverMAX7219/LEDMatrixDriverMAX7219.cpp 

OBJS += \
./LEDMatrixDriverMAX7219/LEDMatrixDriverMAX7219.o 

CPP_DEPS += \
./LEDMatrixDriverMAX7219/LEDMatrixDriverMAX7219.d 


# Each subdirectory must supply rules for building sources it contributes
LEDMatrixDriverMAX7219/%.o: ../LEDMatrixDriverMAX7219/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LEDMatrixDriver" -I"/home/dalmir/workspace/ArduinoCore" -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard -I"/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LEDMatrixDriverMAX7219" -I"/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LEDMatrixDriverMAX7221" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


