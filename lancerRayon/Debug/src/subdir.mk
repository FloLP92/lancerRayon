################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Light.cpp \
../src/Parsing.cpp \
../src/Rayon.cpp \
../src/Screen.cpp \
../src/Sphere.cpp \
../src/Struct.cpp \
../src/lancerRayon.cpp 

OBJS += \
./src/Light.o \
./src/Parsing.o \
./src/Rayon.o \
./src/Screen.o \
./src/Sphere.o \
./src/Struct.o \
./src/lancerRayon.o 

CPP_DEPS += \
./src/Light.d \
./src/Parsing.d \
./src/Rayon.d \
./src/Screen.d \
./src/Sphere.d \
./src/Struct.d \
./src/lancerRayon.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


