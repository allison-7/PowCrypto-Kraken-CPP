#include "QueryLedgers.h"

namespace Kraken {
namespace Private {
QueryLedgers::QueryLedgers(struct kraken_api **kr_api,const char* ledger_id) {
	(*kr_api)->priv_func->query_ledgers(kr_api,ledger_id);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]; //Get the ledger details
	for (auto& m : a.GetObject())
	{
		const char* id = m.name.GetString();
		rapidjson::Value &b = a[id]; //must be done for rapidjson
		this->ledger.ledger_id = id;
		this->ledger.refid = b["refid"].GetString(); //reference id
		this->ledger.time = b["time"].GetDouble(); //unix timestamp of ledger
		this->ledger.type = b["type"].GetString(); //type of ledger entry
		this->ledger.aclass = b["aclass"].GetString(); //asset class
		this->ledger.asset = b["asset"].GetString(); //asset
		this->ledger.amount = atof(b["amount"].GetString()); //transaction amount
		this->ledger.fee = atof(b["fee"].GetString()); //transaction fee
		this->ledger.balance = atof(b["balance"].GetString()); //resulting balance
	}
}
struct QueryLedgers::Ledger QueryLedgers::getLedgerInfo()
{
	return this->ledger;
}
void QueryLedgers::printLedgerInfo()
{
	printf("%s, %s, %.4f, %s, %s, %s, %.10f, %.10f, %.10f\n", this->ledger.ledger_id,this->ledger.refid,this->ledger.time,
			this->ledger.type,this->ledger.aclass,this->ledger.asset,this->ledger.amount,this->ledger.fee,this->ledger.balance);
}
}
}
