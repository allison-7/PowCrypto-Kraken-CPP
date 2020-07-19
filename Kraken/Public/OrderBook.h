#ifndef KRAKEN_ORDERBOOK_H_
#define KRAKEN_ORDERBOOK_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Public {
class OrderBook {
public:
	OrderBook(struct kraken_api **kr_api, const char* pair);
	struct Orders
	{
		 double asks [100][3]; //ask side array of array entries(<price>, <volume>, <timestamp>)
		 double bids [100][3]; //bid side array of array entries(<price>, <volume>, <timestamp>)
	};
	Orders getOrders();
	void printOrderBook(const int index = -1);
private:
	Orders orderBook;
};

}
}
#endif
