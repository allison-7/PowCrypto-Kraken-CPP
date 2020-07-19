#ifndef KRAKEN_TICKERINFORMATION_H_
#define KRAKEN_TICKERINFORMATION_H_
#include<vector>
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Public {
class TickerInformation {
public:
	TickerInformation(struct kraken_api **kr_api, const char* pair);
	struct Ticker
	{
		double a [3]; //ask array(<price>, <whole lot volume>, <lot volume>),
		double b [3]; //bid array(<price>, <whole lot volume>, <lot volume>),
		double c [3]; //last trade closed array(<price>, <lot volume>),
		double v [2]; //volume array(<today>, <last 24 hours>),
		double p [2]; //volume weighted average price array(<today>, <last 24 hours>),
		int t [2]; //number of trades array(<today>, <last 24 hours>),
		double l [2]; //low array(<today>, <last 24 hours>),
		double h [2]; // high array(<today>, <last 24 hours>),
		double o; //today's opening price
	};
	Ticker getTickerInformation();
	void printTickerInformation();
private:
	Ticker ticker;
};
}
}

#endif
