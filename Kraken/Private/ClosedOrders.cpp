#include "ClosedOrders.h"

namespace Kraken {
namespace Private {
ClosedOrders::ClosedOrders(struct kraken_api **kr_api) {
	(*kr_api)->priv_func->get_closed_orders(kr_api);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]["closed"]; //Get the order details
	for (auto& m : a.GetObject()) //Iterate through the orders
	{
		const char* txid = m.name.GetString(); //transaction id
		rapidjson::Value &b = a[txid];
		const char *refid; //Referral order transaction id that created this order
		if(!b["refid"].IsNull())
				refid = b["refid"].GetString(); //May need to be changed
		else
			refid = "0"; //Put something there if the field is empty
		double userref = b["userref"].GetDouble(); //user reference id
		const char* status = b["status"].GetString(); //status of order: pending = order pending book entry; open = open order
			//closed = closed order; canceled = order canceled; expired = order expired
		const char* reason;
		if(!b["reason"].IsNull())
			reason = b["reason"].GetString(); //additional info on status (if any)
		else
			reason = "0";
		double opentm = b["opentm"].GetDouble(); //unix timestamp of when order was placed
		double closetm = b["closetm"].GetDouble(); //unix timestamp of when order was closed
		double starttm = b["starttm"].GetDouble(); //unix timestamp of order start time (or 0 if not set)
		double expiretm = b["expiretm"].GetDouble(); //unix timestamp of order end time (or 0 if not set)
		rapidjson::Value &c = b["descr"];
		const char*pair = c["pair"].GetString(); //asset pair
		const char*type = c["type"].GetString(); //type of order (buy/sell)
		const char*ordertype = c["ordertype"].GetString(); //order type (See Add standard order)
		double price = atof(c["price"].GetString()); //primary price (convert to double)
		double price2 = atof(c["price2"].GetString()); //secondary price (convert to double)
		const char* leverage = c["leverage"].GetString(); //amount of leverage
		const char* order = c["order"].GetString(); //order description
		const char* close = c["close"].GetString(); //conditional close order description (if conditional close set)

		double vol = atof(b["vol"].GetString()); //volume of order (base currency unless viqc set in oflags) (convert to double)
		double vol_exec = atof(b["vol_exec"].GetString()); //volume executed (base currency unless viqc set in oflags) (convert to double)
		double cost = atof(b["cost"].GetString()); //total cost (quote currency unless unless viqc set in oflags) (convert to double)
		double fee =atof(b["fee"].GetString()); //total fee (quote currency) (convert to double)
		double averagePrice = atof(b["price"].GetString()); //average price (quote currency unless viqc set in oflags) (convert to double)
		double stopprice = atof(b["stopprice"].GetString()); //stop price (quote currency, for trailing stops)(convert to double)
		double limitprice = atof(b["limitprice"].GetString()); //triggered limit price (quote currency, when limit based order type triggered) (convert to double)
		this->orders.push_back({txid,refid,userref,status,reason,opentm,closetm,starttm,expiretm,pair,type,ordertype,price,price2,
			leverage,order,close,vol,vol_exec,cost,fee,averagePrice,stopprice,limitprice});
	}
}
std::vector<ClosedOrders::Order> ClosedOrders::getOrders()
{
	return this->orders;
}

void ClosedOrders::printOrders ()
{
	if(orders.empty())
		printf("No closed orders\n");
	for(unsigned int i = 0; i<this->orders.size(); i++)
	{
		printf("%s\n",this->orders[i].txid);
		printf("\t%s, %f, %s, %s, %f, %f, %f, %f, %s, %s, %s, %f, %f, %s, %s, %s, %f, %f, %f, %f, %f, %f, %f\n",
			this->orders[i].refid,this->orders[i].userref,this->orders[i].status, this->orders[i].reason,this->orders[i].opentm,
				this->orders[i].closetm, this->orders[i].starttm,this->orders[i].expiretm,this->orders[i].pair,this->orders[i].type,
				this->orders[i].ordertype,this->orders[i].price,this->orders[i].price2,this->orders[i].leverage, this->orders[i].order,
				this->orders[i].close,this->orders[i].vol, this->orders[i].vol_exec,this->orders[i].cost,this->orders[i].fee,
				this->orders[i].averagePrice,this->orders[i].stopprice,this->orders[i].limitprice);
	}

}
}
}
