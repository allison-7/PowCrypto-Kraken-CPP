#include "TickerInformation.h"
namespace Kraken {
namespace Public {
TickerInformation::TickerInformation(struct kraken_api **kr_api, const char* pair)
{
	(*kr_api)->pub_func->get_ticker_info(kr_api, pair); //Query API
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"][pair]; //Get data
	for(rapidjson::SizeType i = 0; i<3; i++)
	{
		this->ticker.a[i]=atof(a["a"][i].GetString());
	}
	for(rapidjson::SizeType i = 0; i<3; i++)
	{
		this->ticker.b[i]=atof(a["b"][i].GetString());
	}
	for(rapidjson::SizeType i = 0; i<2; i++)
	{
		this->ticker.c[i]=atof(a["c"][i].GetString());
	}
	for(rapidjson::SizeType i = 0; i<2; i++)
	{
		this->ticker.v[i]=atof(a["v"][i].GetString());
	}
	for(rapidjson::SizeType i = 0; i<2; i++)
	{
		this->ticker.p[i]=atof(a["p"][i].GetString());
	}
	for(rapidjson::SizeType i = 0; i<2; i++)
	{
		this->ticker.p[i]=atof(a["p"][i].GetString());
	}
	for(rapidjson::SizeType i = 0; i<2; i++)
	{
		this->ticker.t[i]=a["t"][i].GetInt();
	}
	for(rapidjson::SizeType i = 0; i<2; i++)
	{
		this->ticker.l[i]=atof(a["l"][i].GetString());
	}
	for(rapidjson::SizeType i = 0; i<2; i++)
	{
		this->ticker.h[i]=atof(a["h"][i].GetString());
	}
	this->ticker.o=atof(a["o"].GetString());
}
TickerInformation::Ticker TickerInformation::getTickerInformation()
{
	return this->ticker;
}
void TickerInformation::printTickerInformation()
{
	printf("\t %.5f, %.0f, %.3f\n",this->ticker.a[0],this->ticker.a[1],this->ticker.a[2]);
	printf("\t %.5f, %.0f, %.3f\n",this->ticker.b[0],this->ticker.b[1],this->ticker.b[2]);
	printf("\t %.5f, %.8f, \n", this->ticker.c[0],this->ticker.c[1]);
	printf("\t %.8f, %.8f, \n", this->ticker.v[0],this->ticker.v[1]);
	printf("\t %.5f, %.5f, \n", this->ticker.p[0],this->ticker.p[1]);
	printf("\t %i, %i, \n",this->ticker.t[0],this->ticker.t[1]);
	printf("\t %.5f, %.5f, \n", this->ticker.l[0],this->ticker.l[1]);
	printf("\t %.5f, %.5f, \n", this->ticker.h[0],this->ticker.h[1]);
	printf("\t %.5f\n",this->ticker.o);
}
}
}
