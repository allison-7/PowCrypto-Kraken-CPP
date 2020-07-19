################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Kraken/Public/AssetPairs.cpp \
../Kraken/Public/OHLC.cpp \
../Kraken/Public/RecentTrades.cpp \
../Kraken/Public/SpreadData.cpp \
../Kraken/Public/Time.cpp 

OBJS += \
./Kraken/Public/AssetPairs.o \
./Kraken/Public/OHLC.o \
./Kraken/Public/RecentTrades.o \
./Kraken/Public/SpreadData.o \
./Kraken/Public/Time.o 

CPP_DEPS += \
./Kraken/Public/AssetPairs.d \
./Kraken/Public/OHLC.d \
./Kraken/Public/RecentTrades.d \
./Kraken/Public/SpreadData.d \
./Kraken/Public/Time.d 


# Each subdirectory must supply rules for building sources it contributes
Kraken/Public/%.o: ../Kraken/Public/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D_cplusplus=201130L -I/usr/local/ssl/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


