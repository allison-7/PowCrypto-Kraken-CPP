#ifndef KRAKEN_SPREADDATA_H_
#define KRAKEN_SPREADDATA_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Public {
class SpreadData {
public:
	SpreadData(struct kraken_api **kr_api, const char* pair);
	int* getTime();
	double* getBid();
	double* getAsk();
	void printSpreadData(const int index = -1);
private:
	static const int buffer = 200;
	int time[buffer];
	double bid[buffer];
	double ask[buffer];
};
}
}
#endif
