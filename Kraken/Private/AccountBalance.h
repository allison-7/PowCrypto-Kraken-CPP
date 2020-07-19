#ifndef KRAKEN_ACCOUNTBALANCE_H_
#define KRAKEN_ACCOUNTBALANCE_H_
#include <vector>
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Private {


class AccountBalance {
public:
	AccountBalance(struct kraken_api **kr_api);
	struct Assets
	{
		const char *asset;
		double amount;
	};
	std::vector<Assets> getBalance();
	void printAccountBalance();
private:
	 std::vector<Assets> assets;
};

}
}

#endif
