#ifndef KRAKEN_ORDERSINFO_H_
#define KRAKEN_ORDERSINFO_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
#include <vector>
namespace Kraken {
namespace Private {
class OrdersInfo {
public:
	OrdersInfo(struct kraken_api **kr_api, const char* txid);
	struct Order
	{
		const char *refid; //Referral order transaction id that created this order
		double userref; //user reference id
		const char* status; // = status of order: pending = order pending book entry; open = open order
			//closed = closed order; canceled = order canceled; expired = order expired
		const char* reason; //additional info on status (if any)
		double opentm; //unix timestamp of when order was placed
		double closetm; //unix timestamp of when order was closed
		double starttm; //unix timestamp of order start time (or 0 if not set)
		double expiretm; //unix timestamp of order end time (or 0 if not set)

		const char*pair; //asset pair
		const char*type; //type of order (buy/sell)
		const char*ordertype; //order type (See Add standard order)
		double price; //primary price (convert to double)
		double price2; //secondary price (convert to double)
		const char* leverage; //amount of leverage
		const char* order; //order description
		const char* close; //conditional close order description (if conditional close set)

		double vol; //volume of order (base currency unless viqc set in oflags) (convert to double)
		double vol_exec; //volume executed (base currency unless viqc set in oflags) (convert to double)
		double cost; //total cost (quote currency unless unless viqc set in oflags) (convert to double)
		double fee; //total fee (quote currency) (convert to double)
		double averagePrice; //average price (quote currency unless viqc set in oflags) (convert to double)
		double stopprice; //stop price (quote currency, for trailing stops)(convert to double)
		double limitprice; //triggered limit price (quote currency, when limit based order type triggered) (convert to double)
	};
	std::vector<Order> getOrderInfo();
	void printOrderInfo();
private:
	std::vector<Order> orders;
};
}
}

#endif
