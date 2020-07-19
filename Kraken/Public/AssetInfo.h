#ifndef KRAKEN_ASSETINFO_H_
#define KRAKEN_ASSETINFO_H_
#include<vector>
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Public{
class AssetInfo {
public:
	AssetInfo(struct kraken_api **kr_api);
	struct Asset
	{
		const char* aclass;
		const char* altname;
		int decimals;
		int display_decimals;
	};
	std::vector<Asset> getAssets();
	void printAssetInfo();
private:
	std::vector<Asset> assets;
};
}
}

#endif
