#include "Kraken/kraken_api.h"
#include "Kraken/Public/Time.h"
#include "Kraken/Public/RecentTrades.h"
#include "Kraken/Public/OHLC.h"
#include "Kraken/Public/SpreadData.h"
#include "Kraken/Public/AssetInfo.h"
#include "Kraken/Public/AssetPairs.h"
#include "Kraken/Public/TickerInformation.h"
#include "Kraken/Public/OrderBook.h"
#include "Kraken/Private/TradeBalance.h"
#include "Kraken/Private/AccountBalance.h"
#include "Kraken/Private/OpenOrders.h"
#include "Kraken/Private/ClosedOrders.h"
#include "Kraken/Private/OrdersInfo.h"
#include "Kraken/Private/TradeHistory.h"
#include "Kraken/Private/TradesInfo.h"
#include "Kraken/Private/LedgersInfo.h"
#include "Kraken/Private/QueryLedgers.h"
#include "Kraken/Private/TradeVolume.h"
#include "Kraken/Private/OpenPositions.h"
#include "Kraken/Trading.h"
#include <stdlib.h>
#include <stdio.h>
/***use internal builder & c++11***/
/***needs command line curl***/
/***depends on openssl --> include crypto.a, pthread.a, dl.a, rt.a, & ssl.a***/

int main (void)
{
	struct kraken_api *kr_api = NULL;
	const char *api_key = /*	*/;
	const char *sec_key = /*	*/;
	const char* pair = "XXBTZUSD";
	//kraken_set_opt(&kr_api, "validate", "true");
	/***Trading***/
	kraken_init(&kr_api, api_key, sec_key); //Initialize Kraken API
	Kraken::Trading trading(&kr_api, "sell","limit",pair,"0.005","100000.00"); //Place order
	trading.printTrading();
	Kraken::Trading cancel(&kr_api, trading.getTxid()); //Cancel order
	cancel.printTrading();
	/***PUBLIC***/
	/*Kraken::Public::Time time(&kr_api); //Get Server time
	time.printTime();

	Kraken::Public::RecentTrades recentTrades(&kr_api,pair); //Get recent trades
	recentTrades.printRecentTrades(0);

	Kraken::Public::OHLC ohlc(&kr_api,pair); //Get OHLC data
	ohlc.printOHLC(0);

	Kraken::Public::SpreadData spreadData(&kr_api,pair); //Get spread data
	spreadData.printSpreadData(0);

	Kraken::Public::AssetPairs assetPairs(&kr_api); //Get asset pairs
	assetPairs.printAssetPairs(0);

	Kraken::Public::TickerInformation tickerInfo(&kr_api, pair); //Get Ticker Information
	tickerInfo.printTickerInformation();

	Kraken::Public::OrderBook orderBook(&kr_api, pair);
	orderBook.printOrderBook(0);

	Kraken::Public::AssetInfo a(&kr_api); //Get tradable assets
	a.printAssetInfo();
	*/

	/***PRIVATE***/
	/*Kraken::Private::AccountBalance accountBalance(&kr_api);
	accountBalance.printAccountBalance();

	Kraken::Private::TradeBalance tradeBalance(&kr_api);
	tradeBalance.printTradeBalance();

	Kraken::Private::OpenOrders openOrders(&kr_api);
	openOrders.printOrders();

	Kraken::Private::ClosedOrders closedOrders(&kr_api);
	closedOrders.printOrders();

	Kraken::Private::OrdersInfo ordersInfo(&kr_api, closedOrders.getOrders()[0].txid);
	ordersInfo.printOrderInfo();

	Kraken::Private::TradeHistory tradeHistory(&kr_api);
	tradeHistory.printTrades();

	Kraken::Private::TradesInfo tradesInfo(&kr_api, tradeHistory.getTrades()[0].tradesTXID);
	tradesInfo.printTrades();

	Kraken::Private::LedgersInfo ledgersInfo(&kr_api);
	ledgersInfo.printLedgers();

	Kraken::Private::QueryLedgers queryLedgers(&kr_api,ledgersInfo.getLedgers()[0].ledger_id);
	queryLedgers.printLedgerInfo();

	Kraken::Private::TradeVolume tradeVolume(&kr_api);
	tradeVolume.printTradeVolume();

	if(!(openOrders.getOrders().empty()))
	{
		Kraken::Private::OpenPositions openPositions(&kr_api, openOrders.getOrders()[0].txid);
		openPositions.printPositionInfo();
	}
	else
	{
		Kraken::Private::OpenPositions openPositions(&kr_api,0);
		openPositions.printPositionInfo();
	}*/
	kraken_clean(&kr_api); //Free memory and exit
	return 0;
}



