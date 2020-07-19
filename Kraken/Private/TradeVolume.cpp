#include "TradeVolume.h"

namespace Kraken {
namespace Private {
TradeVolume::TradeVolume(struct kraken_api **kr_api) {
	(*kr_api)->priv_func->get_trade_volume(kr_api);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]; //Get the volume details
	this->tradeVolume.currency = a["currency"].GetString();
	this->tradeVolume.volume = atof(a["volume"].GetString());
}
struct TradeVolume::t TradeVolume::getTradeVolume()
{
	return this->tradeVolume;
}
void TradeVolume::printTradeVolume()
{
	printf("%s, %.4f\n",this->tradeVolume.currency,this->tradeVolume.volume);
}
}
}
