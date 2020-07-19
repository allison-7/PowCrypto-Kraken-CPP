#ifndef RECENTTRADES_H_
#define RECENTTRADES_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
#include <vector>
namespace Kraken {
namespace Public {
class RecentTrades {
public:
	RecentTrades(struct kraken_api **kr_api, const char* pair);
	struct recentTrades
	{
		double price;
		double volume;
		double time;
		const char* buysell;
		const char* orderType;
		const char* miscellaneous;
	};
	struct recentTrades getRecentTrades(const int index);
	void printRecentTrades(const int index = -1);
private:
	std::vector<recentTrades> trades;
};
}
}
#endif /* RECENTTRADES_H_ */
