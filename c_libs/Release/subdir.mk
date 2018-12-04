################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Differentiator.cpp \
../Function.cpp \
../Integrator.cpp \
../JavaFunction.cpp \
../de_lab4inf_wrb_Differentiator.cpp \
../de_lab4inf_wrb_Integrator.cpp \
../main.cpp 

C_SRCS += \
../CUnit.c 

OBJS += \
./CUnit.o \
./Differentiator.o \
./Function.o \
./Integrator.o \
./JavaFunction.o \
./de_lab4inf_wrb_Differentiator.o \
./de_lab4inf_wrb_Integrator.o \
./main.o 

CPP_DEPS += \
./Differentiator.d \
./Function.d \
./Integrator.d \
./JavaFunction.d \
./de_lab4inf_wrb_Differentiator.d \
./de_lab4inf_wrb_Integrator.d \
./main.d 

C_DEPS += \
./CUnit.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/Library/Java/JavaVirtualMachines/jdk1.8.0_101.jdk/Contents/Home/include -I/Library/Java/JavaVirtualMachines/jdk1.8.0_101.jdk/Contents/Home/include/darwin -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Library/Java/JavaVirtualMachines/jdk1.8.0_101.jdk/Contents/Home/include -I/Library/Java/JavaVirtualMachines/jdk1.8.0_101.jdk/Contents/Home/include/darwin -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


