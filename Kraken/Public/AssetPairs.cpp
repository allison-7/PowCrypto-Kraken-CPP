#include "AssetPairs.h"
#include <string>
#include <sstream>
namespace Kraken {
namespace Public {
AssetPairs::AssetPairs(struct kraken_api **kr_api) {
	(*kr_api)->pub_func->get_tradable_asset_pairs(kr_api); //Query API
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]; //Get data
	int i = 0;
	for (auto& m : a.GetObject()) //Iterate through the asset pairs
	{
		const char *asset = m.name.GetString();
		rapidjson::Value &b = a[asset];
		const char* altname = b["altname"].GetString();
		const char* aclass_base = b["aclass_base"].GetString();
		const char* base = b["base"].GetString();
		const char* aclass_quote = b["aclass_quote"].GetString();
		const char* quote = b["quote"].GetString();
		const char* lot = b["lot"].GetString() ;
		int pair_decimals = b["pair_decimals"].GetInt();
		int lot_decimals = b["lot_decimals"].GetInt();
		int lot_multiplier = b["lot_multiplier"].GetInt();
		std::vector<int> leverage_buy;
		if(b["leverage_buy"].Size()!=0) //Check if array is empty
		{
			rapidjson::Value &c = b["leverage_buy"];
			for(unsigned int i = 0; i<c.Size(); i++)
			{
				leverage_buy.push_back(c[i].GetInt());
			}
		}
		std::vector<int> leverage_sell;
		if(b["leverage_sell"].Size()!=0) //Check if array is empty
		{
			rapidjson::Value &c = b["leverage_sell"];
			for(unsigned int i = 0; i<c.Size(); i++)
			{
				leverage_sell.push_back(c[i].GetInt());
			}
		}
		std::vector<std::vector<double>> fees;
		rapidjson::Value &c = b["fees"];
		for(unsigned int i = 0; i<c.Size(); i++)
		{
			std::vector<double> inner;
			inner.push_back(c[i][0].GetInt());
			inner.push_back(c[i][1].GetFloat());
			fees.push_back(inner);
		}
		std::vector<std::vector<double>> fees_maker;
		std::stringstream testStream;
		testStream << "/document/results/" << asset << "/fees_maker";
		std::string testString = testStream.str();
		const char* ctest = testString.c_str();
		if(rapidjson::Value* test = rapidjson::Pointer(ctest).Get(document)) //check for the "fees_maker" field
		{
			c = b["fees_maker"];
			for(unsigned int i = 0; i<c.Size(); i++)
			{
				std::vector<double> inner;
				inner.push_back(c[i][0].GetInt());
				inner.push_back(c[i][1].GetFloat());
				fees_maker.push_back(inner);
			}
		}
		const char* fee_volume_currency = b["fee_volume_currency"].GetString();
		int margin_call = b["margin_call"].GetInt();
		int margin_stop = b["margin_stop"].GetInt();

		this->assetPairs.push_back({altname, aclass_base, base, aclass_quote, quote, lot, pair_decimals, lot_decimals,
		lot_multiplier, leverage_buy, leverage_sell, fees, fees_maker, fee_volume_currency, margin_call, margin_stop});
		i++;
	}
}
std::vector<AssetPairs::AssetPair> AssetPairs::getAssetPairs()
{
	return this->assetPairs;
}
void AssetPairs::printAssetPairs(const int index)
{
	if(index == -1)
	{
		for (unsigned int i = 0; i<this->assetPairs.size(); i++)
		{
			printf("%s, %s, %s, %s, %s, %s %d, %d, %d\n", this->assetPairs[i].altname, this->assetPairs[i].aclass_base,
					this->assetPairs[i].base,this->assetPairs[i].aclass_quote,this->assetPairs[i].quote,this->assetPairs[i].lot,
					this->assetPairs[i].pair_decimals, this->assetPairs[i].lot_decimals, this->assetPairs[i].lot_multiplier);
			for(unsigned int j = 0; j <this->assetPairs[i].leverage_buy.size(); i++)
			{
				if(j == 0)
				{
					printf("\t");
				}
				printf("%d", this->assetPairs[i].leverage_buy[j]);
			}
			printf("\n");
			for(unsigned int j = 0; j <this->assetPairs[i].leverage_sell.size(); j++)
			{
				printf("\t%d", this->assetPairs[i].leverage_sell[j]);
			}
			printf("\n");
			for(unsigned int j = 0; j <this->assetPairs[i].fees.size(); j++)
			{
				printf("\t\t%.0f, %.2f\n", this->assetPairs[i].fees[j][0],this->assetPairs[i].fees[j][1]);
			}
			printf("\n");
			for(unsigned int j = 0; j <this->assetPairs[i].fees_maker.size(); j++)
			{
				printf("\t\t%.0f, %.2f\n", this->assetPairs[i].fees_maker[j][0],this->assetPairs[i].fees_maker[j][1]);
			}
			printf("\t%s, %d, %d\n",this->assetPairs[i].fee_volume_currency,this->assetPairs[i].margin_call,
					this->assetPairs[i].margin_stop);
		}
	}
	else
	{
		printf("%s, %s, %s, %s, %s, %s %d, %d, %d\n", this->assetPairs[index].altname, this->assetPairs[index].aclass_base,
				this->assetPairs[index].base,this->assetPairs[index].aclass_quote,this->assetPairs[index].quote,
				this->assetPairs[index].lot,this->assetPairs[index].pair_decimals, this->assetPairs[index].lot_decimals,
				this->assetPairs[index].lot_multiplier);
		for(unsigned int j = 0; j <this->assetPairs[index].leverage_buy.size(); j++)
		{

			printf("\t%d\n", this->assetPairs[index].leverage_buy[j]);
		}
		for(unsigned int j = 0; j <this->assetPairs[index].leverage_sell.size(); j++)
		{
			printf("\t%d\n", this->assetPairs[index].leverage_sell[j]);
		}
		for(unsigned int j = 0; j <this->assetPairs[index].fees.size(); j++)
		{
			printf("\t\t%.0f, %.2f\n", this->assetPairs[index].fees[j][0],this->assetPairs[index].fees[j][1]);
		}
		for(unsigned int j = 0; j <this->assetPairs[index].fees_maker.size(); j++)
		{
			printf("\t\t%.0f, %.2f\n", this->assetPairs[index].fees_maker[j][0],this->assetPairs[index].fees_maker[j][1]);
		}
		printf("\t%s, %d, %d\n",this->assetPairs[index].fee_volume_currency,this->assetPairs[index].margin_call,
				this->assetPairs[index].margin_stop);
	}
}
}
}
