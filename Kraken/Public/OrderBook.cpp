#include "OrderBook.h"
namespace Kraken {
namespace Public {
OrderBook::OrderBook(struct kraken_api **kr_api, const char* pair)
{
	(*kr_api)->pub_func->get_order_book(kr_api, pair); //Query API
	char* result = (*kr_api)->s_result; //Store result
	rapidjson::Document document;
	document.Parse(result); //Parse JSON data
	rapidjson::Value &a = document["result"][pair]; //Get the Order Book data for the pair
	for (rapidjson::SizeType i = 0; i<100; i++)
	{
		this->orderBook.asks[i][0] = atof(a["asks"][i][0].GetString());
		this->orderBook.asks[i][1] = atof(a["asks"][i][1].GetString());
		this->orderBook.asks[i][2] = a["asks"][i][2].GetInt();
		this->orderBook.bids[i][0] = atof(a["bids"][i][0].GetString());
		this->orderBook.bids[i][1] = atof(a["bids"][i][1].GetString());
		this->orderBook.bids[i][2] = a["bids"][i][2].GetInt();
	}
}
OrderBook::Orders OrderBook::getOrders()
{
	return this->orderBook;
}
void OrderBook::printOrderBook(const int index)
{
	if(index==-1) //Print all orders
	{
		for(unsigned int i = 0; i<100; i++)
		{
			printf("%.5f, %.3f, %.0f, %.5f, %.3f, %.0f \n", this->orderBook.asks[i][0], this->orderBook.asks[i][1],
					this->orderBook.asks[i][2], this->orderBook.bids[i][0], this->orderBook.bids[i][1],
					this->orderBook.bids[i][2]);
		}
	}
	else //Only print the order at the index
	{
		printf("%.5f, %.3f, %.0f, %.5f, %.3f, %.0f \n", this->orderBook.asks[index][0], this->orderBook.asks[index][1],
				this->orderBook.asks[index][2], this->orderBook.bids[index][0], this->orderBook.bids[index][1],
				this->orderBook.bids[index][2]);
	}
}
}
}
