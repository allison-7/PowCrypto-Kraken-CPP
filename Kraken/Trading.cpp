#include "Trading.h"

namespace Kraken {

Trading::Trading(struct kraken_api **kr_api, const char *type, const char *order, const char *asset,
		const char* volume,const char* price1, const char* price2) { //Place Order
	(*kr_api)->priv_func->add_order(kr_api,type,order,asset,volume,price1,price2);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]["descr"]["order"]; //Get the order details
	rapidjson::Value &b = document["result"]["txid"][0]; //Get the transaction id
	this->order_details = a.GetString();
	this->txid = b.GetString();
	this->count = NULL;


}
Trading::Trading(struct kraken_api **kr_api, const char *txid) //Cancel Order
{
	(*kr_api)->priv_func->cancel_order(kr_api,txid);
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"]["count"];
	this->order_details = NULL;
	this->txid = txid;
	this->count = a.GetInt();
}
const char* Trading::getOrderDetails()
{
	return this->order_details;
}
const char* Trading::getTxid()
{
	return this->txid;
}
void Trading::printTrading()
{
	if(this->count==NULL)
		printf("%s, %s\n", this->order_details,this->txid);
	else if(this->count>=1)
		printf("%s canceled\n",txid);
}
}
