#ifndef KRAKEN_TIME_H_
#define KRAKEN_TIME_H_
#include "../../rapidjson/document.h"
#include "../kraken_api.h"
namespace Kraken {
namespace Public {
class Time
{
public:
	Time(struct kraken_api **kr_api);
	int getUnixtime();
	const char *getrfc1123();
	void printTime();
private:
	int unixtime;
	const char *rfc1123;
};
}
}
#endif
