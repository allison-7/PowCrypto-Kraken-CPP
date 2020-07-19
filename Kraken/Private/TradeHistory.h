#ifndef KRAKEN_TRADEHISTORY_H_
#define KRAKEN_TRADEHISTORY_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
#include<vector>
namespace Kraken {
namespace Private {
class TradeHistory {
public:
	TradeHistory(struct kraken_api **kr_api);
	struct Trade
	{
		const char* tradesTXID; //array of trade info with txid as the key
		const char* ordertxid; //order responsible for execution of trade
		const char* postxid;
		const char* pair; //asset pair
		double time; //unix timestamp of trade
		const char* type; //type of order (buy/sell)
		const char* ordertype; //order type
		double price; //average price order was executed at (quote currency)
		double cost; //total cost of order (quote currency)
		double fee; //total fee (quote currency)
		double vol; //volume (base currency)
		double margin; //initial margin (quote currency)
	};
	std::vector<Trade> getTrades();
	void printTrades();
private:
	int count; //amount of available trades info matching criteria
	std::vector<Trade> trades;
};
}
}

#endif
