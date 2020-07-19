#ifndef KRAKEN_OHLC_H_
#define KRAKEN_OHLC_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Public {
//Gets OLHC data that is 1 minute apart(default)
class OHLC {
public:
	OHLC(struct kraken_api **kr_api, const char* pair);
	int* getTime();
	double* getOpen();
	double* getHigh();
	double* getLow();
	double* getClose();
	double* getVWAP();
	double* getVolume();
	int* getCount();
	void printOHLC(const int index = -1);
private:
	static const int buffer= 720;
	int time[buffer];
	double open[buffer];
	double high[buffer];
	double low[buffer];
	double close[buffer];
	double vwap[buffer]; //volume weighted average price
	double volume[buffer];
	int count[buffer];
};
}
}
#endif /* KRAKEN_OHLC_H_ */
