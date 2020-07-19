#include "TradeBalance.h"
#include <string>
#include <sstream>
namespace Kraken {
namespace Private {

TradeBalance::TradeBalance(struct kraken_api **kr_api) {
	(*kr_api)->priv_func->get_trade_balance(kr_api);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"];
	this->t.eb = atof(a["eb"].GetString());
	this->t.tb = atof(a["tb"].GetString());
	this->t.m = atof(a["m"].GetString());
	this->t.n = atof(a["n"].GetString());
	this->t.c = atof(a["c"].GetString());
	this->t.v = atof(a["v"].GetString());
	this->t.e = atof(a["e"].GetString());
	this->t.mf =atof(a["mf"].GetString());
	std::stringstream testStream;
	testStream << "/document/results/mb";
	std::string testString = testStream.str();
	const char* ctest = testString.c_str();
	if(rapidjson::Value* test = rapidjson::Pointer(ctest).Get(document)) //check for the "ml field"
	{
		this->t.ml = atof(a["ml"].GetString());
	}
}
void TradeBalance::printTradeBalance()
{
	printf("%f, %f, %f, %f, %f, %f, %f, %f, %f\n", this->t.eb,this->t.tb,this->t.m,this->t.n,this->t.c,this->t.v,this->t.e,
			this->t.mf,this->t.ml);
}
}
}
