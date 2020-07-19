#ifndef KRAKEN_TRADEBALANCE_H_
#define KRAKEN_TRADEBALANCE_H_
#include "../../rapidjson/pointer.h"
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken{
namespace Private {

class TradeBalance {
public:
	TradeBalance(struct kraken_api **kr_api);
	struct tradeBalance
	{
		double eb; //equivalent balance (combined balance of all currencies) (default = ZUSD)
		double tb; //trade balance (combined balance of all equity currencies)
		double m; //margin amount of open positions
		double n; //unrealized net profit/loss of open positions
		double c; //cost basis of open positions
		double v; //current floating valuation of open positions
		double e; //equity = trade balance + unrealized net profit/loss
		double mf; //free margin = equity - initial margin (maximum margin available to open new positions)
		double ml; //margin level = (equity / initial margin) * 100
	};
	void printTradeBalance();
private:
	struct tradeBalance t;
};

}
}
#endif
