#include "TradeHistory.h"

namespace Kraken {
namespace Private {
TradeHistory::TradeHistory(struct kraken_api **kr_api) {
	(*kr_api)->priv_func->get_trades_history(kr_api);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]["trades"]; //Get the order details
	for (auto& m : a.GetObject()) //Iterate through the orders
	{
		const char* tradesTXID = m.name.GetString(); //array of trade info with txid as the key
		rapidjson::Value &b = a[tradesTXID];
		const char* ordertxid = b["ordertxid"].GetString(); //order responsible for execution of trade
		const char* postxid = b["postxid"].GetString();
		const char* pair = b["pair"].GetString(); //asset pair
		double time = b["time"].GetDouble(); //unix timestamp of trade
		const char* type = b["type"].GetString(); //type of order (buy/sell)
		const char* ordertype = b["ordertype"].GetString(); //order type
		double price = atof(b["price"].GetString()); //average price order was executed at (quote currency)
		double cost = atof(b["cost"].GetString()); //total cost of order (quote currency)
		double fee = atof(b["fee"].GetString()); //total fee (quote currency)
		double vol = atof(b["vol"].GetString()); //volume (base currency)
		double margin = atof(b["margin"].GetString()); //initial margin (quote currency)
		this->trades.push_back({tradesTXID,ordertxid,postxid,pair,time,type,ordertype,price,cost,fee,vol,margin});
	}
	this->count = document["result"]["count"].GetInt();
}
std::vector<TradeHistory::Trade> TradeHistory::getTrades()
{
	return this->trades;
}
void TradeHistory::printTrades()
{
	for(unsigned int i = 0; i<this->trades.size(); i++)
	{
		printf("%s, %s, %s, %s, %f, %s, %s, %f, %f, %f, %f, %f, %d\n",this->trades[i].tradesTXID,this->trades[i].ordertxid,
				this->trades[i].postxid,this->trades[i].pair,this->trades[i].time,this->trades[i].type,this->trades[i].ordertype,
				this->trades[i].price,this->trades[i].cost,this->trades[i].fee,this->trades[i].vol,this->trades[i].margin,this->count);
	}
}
}
}
