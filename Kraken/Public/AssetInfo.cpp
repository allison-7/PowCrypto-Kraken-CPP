#include "AssetInfo.h"

namespace Kraken {
namespace Public {
AssetInfo::AssetInfo(struct kraken_api **kr_api) {
	(*kr_api)->pub_func->get_asset_info(kr_api); //Query API
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]; //Get data
	int i = 0;
	//const char* coins[32];
	for (auto& m : a.GetObject()) //Iterate through the assets
	{
		const char *asset = m.name.GetString();
		rapidjson::Value &b = a[asset];
		const char* aclass = b["aclass"].GetString();
		const char* altname = b["altname"].GetString();
		int decimals = b["decimals"].GetInt();
		int display_decimals = b["display_decimals"].GetInt();
		this->assets.push_back({aclass,altname,decimals,display_decimals});
		i++;
	}
}
std::vector<AssetInfo::Asset> AssetInfo::getAssets()
{
	return this->assets;
}
void AssetInfo::printAssetInfo()
{
	for(int i = 0; i<this->assets.size(); i++)
	{
		printf("%s ,%s ,%d , %d\n", this->assets[i].aclass,this->assets[i].altname,
				this->assets[i].decimals, this->assets[i].display_decimals);
	}
}
}
}
