#ifndef KRAKEN_ASSETPAIRS_H_
#define KRAKEN_ASSETPAIRS_H_
#include<vector>
#include "../../rapidjson/document.h"
#include "../../rapidjson/pointer.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Public {
class AssetPairs {
public:
	AssetPairs(struct kraken_api **kr_api);
	struct AssetPair
	{
		const char* altname; // alternate pair name
		const char* aclass_base; //asset class of base component
		const char* base; //asset id of base component
		const char* aclass_quote; //asset class of quote component
		const char* quote; //asset id of quote component
		const char* lot; //volume lot size
		int pair_decimals; //scaling decimal places for pair
		int lot_decimals; //scaling decimal places for volume
		int lot_multiplier; //amount to multiply lot volume by to get currency volume
		std::vector<int> leverage_buy; //array of leverage amounts available when buying
		std::vector<int> leverage_sell; //array of leverage amounts available when selling
		std::vector<std::vector<double>> fees; //fee schedule array in [volume, percent fee] tuples
		std::vector<std::vector<double>> fees_maker; //maker fee schedule array in [volume, percent fee] tuples (if on maker/taker)
		const char* fee_volume_currency; //volume discount currency
		int margin_call; //margin call level
		int margin_stop; //stop-out/liquidation margin level
	};
	std::vector<AssetPair> getAssetPairs();
	void printAssetPairs(const int index = -1);
private:
	std::vector<AssetPair> assetPairs;
};
}
}

#endif
