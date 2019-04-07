################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_cache.c \
/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_check.c \
/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_gc.c \
/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_hydrogen.c \
/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_nucleus.c 

C_DEPS += \
./core/core/spiffs/spiffs_cache.c.d \
./core/core/spiffs/spiffs_check.c.d \
./core/core/spiffs/spiffs_gc.c.d \
./core/core/spiffs/spiffs_hydrogen.c.d \
./core/core/spiffs/spiffs_nucleus.c.d 

AR_OBJ += \
./core/core/spiffs/spiffs_cache.c.o \
./core/core/spiffs/spiffs_check.c.o \
./core/core/spiffs/spiffs_gc.c.o \
./core/core/spiffs/spiffs_hydrogen.c.o \
./core/core/spiffs/spiffs_nucleus.c.o 


# Each subdirectory must supply rules for building sources it contributes
core/core/spiffs/spiffs_cache.c.o: /home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_cache.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/lwip2/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/core" -c -Wall -Wextra -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536  -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 '-DARDUINO_BOARD="ESP8266_WEMOS_D1MINI"'  -DESP8266  -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/variants/d1_mini" -I"/home/ejosmol/Arduino/libraries/MPU6050" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/libraries/Wire" -I"/home/ejosmol/Arduino/libraries/I2Cdev" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/spiffs/spiffs_check.c.o: /home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_check.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/lwip2/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/core" -c -Wall -Wextra -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536  -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 '-DARDUINO_BOARD="ESP8266_WEMOS_D1MINI"'  -DESP8266  -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/variants/d1_mini" -I"/home/ejosmol/Arduino/libraries/MPU6050" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/libraries/Wire" -I"/home/ejosmol/Arduino/libraries/I2Cdev" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/spiffs/spiffs_gc.c.o: /home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_gc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/lwip2/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/core" -c -Wall -Wextra -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536  -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 '-DARDUINO_BOARD="ESP8266_WEMOS_D1MINI"'  -DESP8266  -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/variants/d1_mini" -I"/home/ejosmol/Arduino/libraries/MPU6050" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/libraries/Wire" -I"/home/ejosmol/Arduino/libraries/I2Cdev" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/spiffs/spiffs_hydrogen.c.o: /home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_hydrogen.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/lwip2/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/core" -c -Wall -Wextra -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536  -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 '-DARDUINO_BOARD="ESP8266_WEMOS_D1MINI"'  -DESP8266  -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/variants/d1_mini" -I"/home/ejosmol/Arduino/libraries/MPU6050" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/libraries/Wire" -I"/home/ejosmol/Arduino/libraries/I2Cdev" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/spiffs/spiffs_nucleus.c.o: /home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266/spiffs/spiffs_nucleus.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/lwip2/include" "-I/home/ejosmol/tools/sloeber//arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/tools/sdk/libc/xtensa-lx106-elf/include" "-I/home/ejosmol/git/arduinoLab/AccelSimpleMeter/Release/core" -c -Wall -Wextra -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536  -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 '-DARDUINO_BOARD="ESP8266_WEMOS_D1MINI"'  -DESP8266  -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/cores/esp8266" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/variants/d1_mini" -I"/home/ejosmol/Arduino/libraries/MPU6050" -I"/home/ejosmol/tools/sloeber/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.1/libraries/Wire" -I"/home/ejosmol/Arduino/libraries/I2Cdev" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


