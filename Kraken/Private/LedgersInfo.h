#ifndef KRAKEN_LEDGERSINFO_H_
#define KRAKEN_LEDGERSINFO_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
#include <vector>
namespace Kraken {
namespace Private {
class LedgersInfo {
public:
	LedgersInfo(struct kraken_api **kr_api);
	struct Ledger
	{
		const char* ledger_id; //ledger info
		const char* refid; //reference id
		double time; //unix timestamp of ledger
		const char* type; //type of ledger entry
		const char* aclass; //asset class
		const char *asset; //asset
		double amount; //transaction amount
		double fee; //transaction fee
		double balance; //resulting balance
	};
	std::vector<Ledger> getLedgers();
	void printLedgers();
private:
	std::vector<Ledger> ledgers;
	int count; //Number of ledgers
};
}
}

#endif
