################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/Camera.cc \
../src/Color.cc \
../src/Cube.cc \
../src/Cylinder.cc \
../src/DrawStyle.cc \
../src/Example.cc \
../src/GLViewer.cc \
../src/Geometry.cc \
../src/Light.cc \
../src/LightOff.cc \
../src/Line.cc \
../src/Material.cc \
../src/Node.cc \
../src/Polygon.cc \
../src/Sphere.cc \
../src/Transformation.cc 

CC_DEPS += \
./src/Camera.d \
./src/Color.d \
./src/Cube.d \
./src/Cylinder.d \
./src/DrawStyle.d \
./src/Example.d \
./src/GLViewer.d \
./src/Geometry.d \
./src/Light.d \
./src/LightOff.d \
./src/Line.d \
./src/Material.d \
./src/Node.d \
./src/Polygon.d \
./src/Sphere.d \
./src/Transformation.d 

OBJS += \
./src/Camera.o \
./src/Color.o \
./src/Cube.o \
./src/Cylinder.o \
./src/DrawStyle.o \
./src/Example.o \
./src/GLViewer.o \
./src/Geometry.o \
./src/Light.o \
./src/LightOff.o \
./src/Line.o \
./src/Material.o \
./src/Node.o \
./src/Polygon.o \
./src/Sphere.o \
./src/Transformation.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


