################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayPassenger.c \
../src/Funciones.c \
../src/TP2.c 

C_DEPS += \
./src/ArrayPassenger.d \
./src/Funciones.d \
./src/TP2.d 

OBJS += \
./src/ArrayPassenger.o \
./src/Funciones.o \
./src/TP2.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ArrayPassenger.d ./src/ArrayPassenger.o ./src/Funciones.d ./src/Funciones.o ./src/TP2.d ./src/TP2.o

.PHONY: clean-src

