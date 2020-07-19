#include "RecentTrades.h"
namespace Kraken {
namespace Public {
RecentTrades::RecentTrades(struct kraken_api **kr_api, const char* pair)
{
	(*kr_api)->pub_func->get_recent_trades(kr_api, pair); //Query API
	char* result = (*kr_api)->s_result; //Store the result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"][pair]; //Get the trade data for the pair
	for (rapidjson::SizeType i = 0; i<a.Size(); i++)
	{
		double price = atof(a[i][0].GetString());
		double volume = atof(a[i][1].GetString());
		double time = a[i][2].GetDouble();
		const char* buysell = a[i][3].GetString();
		const char* orderType = a[i][4].GetString();
		const char* miscellaneous;
		if(!a[i][5].IsNull())
			miscellaneous = a[i][5].GetString();
		else
			miscellaneous = "0";
		this->trades.push_back({price,volume,time,buysell,orderType,miscellaneous});
		/*
		this->price.push_back(atof(a[i][0].GetString()));
		this->volume.push_back(atof(a[i][1].GetString()));
		this->time.push_back((a[i][2]).GetDouble());
		this->buysell.push_back(a[i][3].GetString());
		this->orderType.push_back(a[i][4].GetString());
		this->miscellaneous.push_back(a[i][5].GetString());
		*/
	}
}
struct RecentTrades::recentTrades RecentTrades::getRecentTrades(const int index)
{
	return this->trades[index];
}
void RecentTrades::printRecentTrades(const int index)
{
	if(index == -1)
	{
		for(unsigned int i = 0; i<this->trades.size(); i++)
		{
			printf("%.5f, %.8f, %.4f, %s, %s, %s\n", this->trades[i].price, this->trades[i].volume, this->trades[i].time,
					this->trades[i].buysell, this->trades[i].orderType, this->trades[i].miscellaneous);
		}
	}
	else
	{
		printf("%.5f, %.8f, %.4f, %s, %s, %s\n", this->trades[index].price, this->trades[index].volume, this->trades[index].time,
							this->trades[index].buysell, this->trades[index].orderType, this->trades[index].miscellaneous);
	}
}
}
}
