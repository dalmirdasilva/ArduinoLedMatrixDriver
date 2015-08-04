################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MAX7219Driver/subdir.mk
-include LedMatrixMAX7221Driver/subdir.mk
-include LedMatrixMAX7219Driver/subdir.mk
-include LedMatrixDriver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
libArduinoLedMatrixDriver.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libArduinoLedMatrixDriver.a secondary-outputs

# Tool invocations
libArduinoLedMatrixDriver.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libArduinoLedMatrixDriver.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libArduinoLedMatrixDriver.lss: libArduinoLedMatrixDriver.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libArduinoLedMatrixDriver.a  >"libArduinoLedMatrixDriver.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libArduinoLedMatrixDriver.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p libArduinoLedMatrixDriver.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(ARCHIVES)$(S_DEPS)$(LSS)$(C_DEPS)$(CC_DEPS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) libArduinoLedMatrixDriver.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
