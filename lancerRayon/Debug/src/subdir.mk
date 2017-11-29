################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Screen.cpp \
../src/Sphere.cpp \
../src/lancerRayon.cpp 

OBJS += \
./src/Screen.o \
./src/Sphere.o \
./src/lancerRayon.o 

CPP_DEPS += \
./src/Screen.d \
./src/Sphere.d \
./src/lancerRayon.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


