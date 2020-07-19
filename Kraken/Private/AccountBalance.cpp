#include "AccountBalance.h"

namespace Kraken {
namespace Private {


AccountBalance::AccountBalance(struct kraken_api **kr_api) {
	(*kr_api)->priv_func->get_account_balance(kr_api);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"];
	for (auto& m : a.GetObject()) //Iterate through the assets
	{
		const char *asset = m.name.GetString(); //Store the name of the asset such as XBT
		rapidjson::Value &b = a[asset];
		double value = atof(b.GetString()); //Get the amount of the asset
		this->assets.push_back({asset,value});
	}
}
std::vector<AccountBalance::Assets> AccountBalance::getBalance()
{
	return this->assets;
}
void AccountBalance::printAccountBalance()
{
	for (unsigned int i = 0; i<this->assets.size(); i++)
	{
		printf("%s, %.10f\n", this->assets[i].asset, this->assets[i].amount);
	}
}
}
}
