#include "OHLC.h"
namespace Kraken {
namespace Public {
OHLC::OHLC(struct kraken_api **kr_api, const char* pair) {
	(*kr_api)->pub_func->get_ohlc_data(kr_api, pair); //Query API
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"][pair]; //Get the OHLC data for the pair
	for (rapidjson::SizeType i = 0; i<a.Size(); i++)
	{
		this->time[i] = a[i][0].GetInt();
		this->open[i] = atof(a[i][1].GetString());
		this->high[i] = atof(a[i][2].GetString());
		this->low[i] = atof(a[i][3].GetString());
		this->close[i] = atof(a[i][4].GetString());
		this->vwap[i] = atof(a[i][5].GetString());
		this->volume[i] = atof(a[i][6].GetString());
		this->count[i] = a[i][7].GetInt();
	}
}
int* OHLC::getTime()
{
	return this->time;
}
double* OHLC::getOpen()
{
	return this->open;
}
double* OHLC::getHigh()
{
	return this->high;
}
double* OHLC::getLow()
{
	return this->low;
}
double* OHLC::getClose()
{
	return this->close;
}
double* OHLC::getVWAP()
{
	return this->vwap;
}
double* OHLC::getVolume()
{
	return this->volume;
}
int* OHLC::getCount()
{
	return this->count;
}
void OHLC::printOHLC(const int index)
{
	if(index == -1)
	{
		for(unsigned int i = 0; i<this->buffer; i++)
		{
			printf("%d, %.1f, %.1f, %.1f, %.1f, %.1f, %.8f, %d\n",this->time[i],this->open[i],this->high[i],this->low[i],this->close[i],this->vwap[i],
					this->volume[i],this->count[i]);
		}
	}
	else
	{

	printf("%d, %.1f, %.1f, %.1f, %.1f, %.1f, %.8f, %d\n",this->time[index],this->open[index],this->high[index],this->low[index],
			this->close[index],this->vwap[index],
			this->volume[index],this->count[index]);

	}
}
}
}
