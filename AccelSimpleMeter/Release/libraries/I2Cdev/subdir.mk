################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ejosmol/Arduino/libraries/I2Cdev/I2Cdev.cpp 

LINK_OBJ += \
./libraries/I2Cdev/I2Cdev.cpp.o 

CPP_DEPS += \
./libraries/I2Cdev/I2Cdev.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/I2Cdev/I2Cdev.cpp.o: /home/ejosmol/Arduino/libraries/I2Cdev/I2Cdev.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/lwip2/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/core" -c -Wall -Wextra -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536  -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 '-DARDUINO_BOARD="ESP8266_WEMOS_D1MINI"'  -DESP8266  -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/variants/d1_mini" -I"/home/ejosmol/Arduino/libraries/MPU6050" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/libraries/Wire" -I"/home/ejosmol/Arduino/libraries/I2Cdev" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


