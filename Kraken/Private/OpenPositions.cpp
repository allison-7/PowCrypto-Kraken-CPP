#include "OpenPositions.h"

namespace Kraken {
namespace Private {

OpenPositions::OpenPositions(struct kraken_api **kr_api, const char* txid) {
	(*kr_api)->priv_func->get_open_orders(kr_api);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]["open"]; //Get the order details
	for (auto& m : a.GetObject()) //Iterate through the orders
	{
		const char* _txid = m.name.GetString();
		this->position.txid = _txid; //transaction id
		rapidjson::Value &b = a[_txid];
		//const char *refid; //Referral order transaction id that created this order
		if(!b["refid"].IsNull())
			this->position.refid = b["refid"].GetString(); //May need to be changed
		else
			this->position.refid = "0"; //Put something there if the field is empty
		this->position.userref = b["userref"].GetDouble(); //user reference id
		this->position.status =b["status"].GetString(); //status of order: pending = order pending book entry; open = open order
			//closed = closed order; canceled = order canceled; expired = order expired
		this->position.opentm = b["opentm"].GetDouble(); //unix timestamp of when order was placed
		this->position.starttm = b["starttm"].GetDouble(); //unix timestamp of order start time (or 0 if not set)
		this->position.expiretm = b["expiretm"].GetDouble(); //unix timestamp of order end time (or 0 if not set)

		rapidjson::Value &c = b["descr"];
		this->position.pair = c["pair"].GetString(); //asset pair
		this->position.type = c["type"].GetString(); //type of order (buy/sell)
		this->position.ordertype = c["ordertype"].GetString(); //order type (See Add standard order)
		this->position.price = atof(c["price"].GetString()); //primary price (convert to double)
		this->position.price2 = atof(c["price2"].GetString()); //secondary price (convert to double)
		this->position.leverage = c["leverage"].GetString(); //amount of leverage
		this->position.order = c["order"].GetString(); //order description
		this->position.close = c["close"].GetString(); //conditional close order description (if conditional close set)

		this->position.vol = atof(b["vol"].GetString()); //volume of order (base currency unless viqc set in oflags) (convert to double)
		this->position.vol_exec = atof(b["vol_exec"].GetString()); //volume executed (base currency unless viqc set in oflags) (convert to double)
		this->position.cost = atof(b["cost"].GetString()); //total cost (quote currency unless unless viqc set in oflags) (convert to double)
		this->position.fee =atof(b["fee"].GetString()); //total fee (quote currency) (convert to double)
		this->position.averagePrice = atof(b["price"].GetString()); //average price (quote currency unless viqc set in oflags) (convert to double)
		this->position.stopprice = atof(b["stopprice"].GetString()); //stop price (quote currency, for trailing stops)(convert to double)
		this->position.limitprice = atof(b["limitprice"].GetString()); //triggered limit price (quote currency, when limit based order type triggered) (convert to double)
	}
}
struct OpenPositions::Position OpenPositions::getPositionInfo()
{
	return this->position;
}
void OpenPositions::printPositionInfo()
{
	if(this->position.txid==NULL)
		printf("No open positions\n");
	else
		printf("%s, %s, %f, %s, %f, %f, %f, %s, %s, %s, %f, %f, %s, %s, %s, %f, %f, %f, %f, %f, %f, %f\n",
			this->position.txid,this->position.refid,this->position.userref,this->position.status,this->position.opentm,
			this->position.starttm,this->position.expiretm,this->position.pair,this->position.type,this->position.ordertype,
			this->position.price,this->position.price2,this->position.leverage,this->position.order,this->position.close,
			this->position.vol,this->position.vol_exec,this->position.cost,this->position.fee,this->position.averagePrice,
			this->position.stopprice,this->position.limitprice);

}
}
}
