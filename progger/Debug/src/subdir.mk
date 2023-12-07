################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Console.c \
../src/Cursor.c \
../src/Game.c \
../src/Input.c \
../src/Player.c \
../src/Progger.c \
../src/Scoreboard.c \
../src/Street.c \
../src/progger.c 

C_DEPS += \
./src/Console.d \
./src/Cursor.d \
./src/Game.d \
./src/Input.d \
./src/Player.d \
./src/Progger.d \
./src/Scoreboard.d \
./src/Street.d \
./src/progger.d 

OBJS += \
./src/Console.o \
./src/Cursor.o \
./src/Game.o \
./src/Input.o \
./src/Player.o \
./src/Progger.o \
./src/Scoreboard.o \
./src/Street.o \
./src/progger.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Console.d ./src/Console.o ./src/Cursor.d ./src/Cursor.o ./src/Game.d ./src/Game.o ./src/Input.d ./src/Input.o ./src/Player.d ./src/Player.o ./src/Progger.d ./src/Progger.o ./src/Scoreboard.d ./src/Scoreboard.o ./src/Street.d ./src/Street.o ./src/progger.d ./src/progger.o

.PHONY: clean-src

