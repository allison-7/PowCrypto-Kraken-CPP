#include "SpreadData.h"
namespace Kraken {
namespace Public {
SpreadData::SpreadData(struct kraken_api **kr_api, const char* pair)
{
	(*kr_api)->pub_func->get_recent_spread_data(kr_api, pair); //Query API
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"][pair]; //Get the OHLC data for the pair
	for (rapidjson::SizeType i = 0; i<a.Size(); i++)
	{
		this->time[i] = a[i][0].GetInt();
		this->bid[i] = atof(a[i][1].GetString());
		this->ask[i] = atof(a[i][2].GetString());
	}
}
int* SpreadData::getTime()
{
	return this->time;
}
double* SpreadData::getBid()
{
	return this->bid;
}
double* SpreadData::getAsk()
{
	return this->ask;
}
void SpreadData::printSpreadData(const int index)
{
	if(index == -1)
	{
		for(unsigned int i = 0; i<this->buffer; i++)
		{
			printf("%d, %.5f, %.5f\n", this->time[i], this->bid[i], this->ask[i]);
		}
	}
	else
		printf("%d, %.5f, %.5f\n", this->time[index], this->bid[index], this->ask[index]);
}
}
}
