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
	avr-g++ -I"/home/dalmir/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LedMatrixDriver" -I"/home/dalmir/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LEDMatrixDriverMAX7219" -I"/home/dalmir/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LEDMatrixDriverMAX7221" -I"/home/dalmir/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LedMatrixMAX7219Driver" -I"/home/dalmir/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/LedMatrixMAX7221Driver" -I"/home/dalmir/storage/microcontroller/arduino/driver/led/ArduinoLEDMatrixDriver/MAX7219Driver" -I"/home/dalmir/storage/microcontroller/arduino/core/ArduinoCore" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


