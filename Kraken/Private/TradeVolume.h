#ifndef KRAKEN_TRADEVOLUME_H_
#define KRAKEN_TRADEVOLUME_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Private {
class TradeVolume {
public:
	TradeVolume(struct kraken_api **kr_api);
	struct t
	{
		const char* currency; // volume currency
		double volume; //current discount volume
	};
struct t getTradeVolume();
void printTradeVolume();
private:
struct t tradeVolume;
};
}
}

#endif
