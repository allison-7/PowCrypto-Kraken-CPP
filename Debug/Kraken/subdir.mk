################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Kraken/crypto.c \
../Kraken/curl.c \
../Kraken/examples.c \
../Kraken/kr_helper.c \
../Kraken/kr_private_trading_functions.c \
../Kraken/kr_private_user_functions.c \
../Kraken/kr_public_functions.c \
../Kraken/kraken_api.c \
../Kraken/url.c 

CPP_SRCS += \
../Kraken/AssetInfo.cpp \
../Kraken/OrderBook.cpp \
../Kraken/TickerInformation.cpp 

OBJS += \
./Kraken/AssetInfo.o \
./Kraken/OrderBook.o \
./Kraken/TickerInformation.o \
./Kraken/crypto.o \
./Kraken/curl.o \
./Kraken/examples.o \
./Kraken/kr_helper.o \
./Kraken/kr_private_trading_functions.o \
./Kraken/kr_private_user_functions.o \
./Kraken/kr_public_functions.o \
./Kraken/kraken_api.o \
./Kraken/url.o 

C_DEPS += \
./Kraken/crypto.d \
./Kraken/curl.d \
./Kraken/examples.d \
./Kraken/kr_helper.d \
./Kraken/kr_private_trading_functions.d \
./Kraken/kr_private_user_functions.d \
./Kraken/kr_public_functions.d \
./Kraken/kraken_api.d \
./Kraken/url.d 

CPP_DEPS += \
./Kraken/AssetInfo.d \
./Kraken/OrderBook.d \
./Kraken/TickerInformation.d 


# Each subdirectory must supply rules for building sources it contributes
Kraken/%.o: ../Kraken/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D_cplusplus=201130L -I/usr/local/ssl/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Kraken/%.o: ../Kraken/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I/usr/local/ssl/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


