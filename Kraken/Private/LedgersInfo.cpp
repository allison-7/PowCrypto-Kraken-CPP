#include "LedgersInfo.h"

namespace Kraken {
namespace Private {
LedgersInfo::LedgersInfo(struct kraken_api **kr_api) {
	(*kr_api)->priv_func->get_ledgers_info(kr_api);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]["ledger"]; //Get the ledger details
	for (auto& m : a.GetObject()) //Iterate through the ledgers
	{
		const char* ledger_id = m.name.GetString(); //ledger info
		rapidjson::Value &b = a[ledger_id];
		const char* refid =b["refid"].GetString(); //reference id
		double time = b["time"].GetDouble(); //unix timestamp of ledger
		const char* type = b["type"].GetString(); //type of ledger entry
		const char* aclass = b["aclass"].GetString(); //asset class
		const char *asset = b["asset"].GetString(); //asset
		double amount = atof(b["amount"].GetString()); //transaction amount
		double fee = atof(b["fee"].GetString()); //transaction fee
		double balance = atof(b["balance"].GetString()); //resulting balance
		this->ledgers.push_back({ledger_id,refid,time,type,aclass,asset,amount,fee,balance});
	}
	this->count = document["result"]["count"].GetInt();
}
std::vector<LedgersInfo::Ledger> LedgersInfo::getLedgers()
{
	return this->ledgers;
}
void LedgersInfo::printLedgers()
{
	for(unsigned int i = 0; i<this->ledgers.size(); i++)
	{
		printf("%s, %s, %.4f, %s, %s, %s, %.10f, %.10f, %.10f\n",this->ledgers[i].ledger_id,this->ledgers[i].refid,this->ledgers[i].time,
				this->ledgers[i].type,this->ledgers[i].aclass,this->ledgers[i].asset,this->ledgers[i].amount,
				this->ledgers[i].fee,this->ledgers[i].balance);
	}
	printf("%d\n",this->count);
}
}
}
