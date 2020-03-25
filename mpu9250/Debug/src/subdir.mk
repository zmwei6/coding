################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mpu.c 

OBJS += \
./src/mpu.o 

C_DEPS += \
./src/mpu.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I/home/zwei/agl-nxm/build/tmp/work/beaglebone-agl-linux-gnueabi/base-files/3.0.14-r89/recipe-sysroot-native/usr -I"/home/zwei/eclipse-workspace/mpu9250/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


