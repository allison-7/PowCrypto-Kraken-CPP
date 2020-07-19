#ifndef KRAKEN_QUERYLEDGERS_H_
#define KRAKEN_QUERYLEDGERS_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Private {
class QueryLedgers {
public:
	QueryLedgers(struct kraken_api **kr_api,const char* ledger_id);
	struct Ledger
	{
		const char* ledger_id;
		const char* refid; //reference id
		double time; //unix timestamp of ledger
		const char* type; //type of ledger entry
		const char* aclass; //asset class
		const char *asset; //asset
		double amount; //transaction amount
		double fee; //transaction fee
		double balance; //resulting balance
	};
	struct Ledger getLedgerInfo();
	void printLedgerInfo();
private:
	struct Ledger ledger;
};
}
}

#endif
