################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries/Wire/subdir.mk
-include libraries/MPU6050/subdir.mk
-include libraries/I2Cdev/subdir.mk
-include core/core/umm_malloc/subdir.mk
-include core/core/spiffs/subdir.mk
-include core/core/libb64/subdir.mk
-include core/core/subdir.mk
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
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/arduino.ar \

ELF += \
AccelSimpleMeter.elf \

HEX += \
AccelSimpleMeter.hex \


# All Target
all: AccelSimpleMeter

# Tool invocations
AccelSimpleMeter: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-size" -A "/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/AccelSimpleMeter.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru "/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/arduino.ar"    /home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

AccelSimpleMeter.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -g -Wall -Wextra -Os -nostdlib -Wl,--no-check-sections -u call_user_start -u _printf_float -u _scanf_float -Wl,-static "-L/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/lib" "-L/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/ld" "-L/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/libc/xtensa-lx106-elf/lib" "-Teagle.flash.4m1m.ld" -Wl,--gc-sections -Wl,-wrap,system_restart_local -Wl,-wrap,spi_flash_read -o "/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/AccelSimpleMeter.elf" -Wl,--start-group   $(LINK_OBJ)  "/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/arduino.ar" -lhal -lphy -lpp -lnet80211 -llwip2 -lwpa -lcrypto -lmain -lwps -laxtls -lespnow -lsmartconfig -lairkiss -lwpa2 -lstdc++ -lm -lc -lgcc -Wl,--end-group "-L/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release" /home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/arduino.ar
	@echo 'Finished building: $@'
	@echo ' '

AccelSimpleMeter.hex: $(ELF)
	@echo 'Create eeprom image'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/esptool/0.4.13/esptool" -eo "/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/bootloaders/eboot/eboot.elf" -bo "/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/AccelSimpleMeter.bin" -bm dio -bf 40 -bz 4M -bs .text -bp 4096 -ec -eo "/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/AccelSimpleMeter.elf" -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
