################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Kraken/Private/AccountBalance.cpp \
../Kraken/Private/ClosedOrders.cpp \
../Kraken/Private/LedgersInfo.cpp \
../Kraken/Private/OpenOrders.cpp \
../Kraken/Private/OpenPositions.cpp \
../Kraken/Private/OrdersInfo.cpp \
../Kraken/Private/QueryLedgers.cpp \
../Kraken/Private/TradeBalance.cpp \
../Kraken/Private/TradeHistory.cpp \
../Kraken/Private/TradeVolume.cpp \
../Kraken/Private/TradesInfo.cpp 

OBJS += \
./Kraken/Private/AccountBalance.o \
./Kraken/Private/ClosedOrders.o \
./Kraken/Private/LedgersInfo.o \
./Kraken/Private/OpenOrders.o \
./Kraken/Private/OpenPositions.o \
./Kraken/Private/OrdersInfo.o \
./Kraken/Private/QueryLedgers.o \
./Kraken/Private/TradeBalance.o \
./Kraken/Private/TradeHistory.o \
./Kraken/Private/TradeVolume.o \
./Kraken/Private/TradesInfo.o 

CPP_DEPS += \
./Kraken/Private/AccountBalance.d \
./Kraken/Private/ClosedOrders.d \
./Kraken/Private/LedgersInfo.d \
./Kraken/Private/OpenOrders.d \
./Kraken/Private/OpenPositions.d \
./Kraken/Private/OrdersInfo.d \
./Kraken/Private/QueryLedgers.d \
./Kraken/Private/TradeBalance.d \
./Kraken/Private/TradeHistory.d \
./Kraken/Private/TradeVolume.d \
./Kraken/Private/TradesInfo.d 


# Each subdirectory must supply rules for building sources it contributes
Kraken/Private/%.o: ../Kraken/Private/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D_cplusplus=201130L -I/usr/local/ssl/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


