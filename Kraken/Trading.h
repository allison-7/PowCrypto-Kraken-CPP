#ifndef KRAKEN_TRADING_H_
#define KRAKEN_TRADING_H_
#include "../rapidjson/document.h"
#include "kraken_api.h"
#include <stdarg.h>
namespace Kraken {

class Trading {
public:
	Trading(struct kraken_api **kr_api, const char *type, const char *order, const char *asset,
			const char* volume,const char* price1 = NULL,const char* price2 = NULL); //Place order
	Trading(struct kraken_api **kr_api, const char *txid); //Cancel order
	const char* getOrderDetails();
	const char* getTxid();
	void printTrading();
private:
	const char* order_details;
	const char* txid;
	unsigned char count;
};

}
#endif
