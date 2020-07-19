#include "Time.h"
namespace Kraken {
namespace Public {
Time::Time(struct kraken_api **kr_api)
{
	(*kr_api)->pub_func->get_server_time(kr_api);
	char *result = (*kr_api)->s_result;
	rapidjson::Document document;
	document.Parse(result);
	this->unixtime=(document["result"]["unixtime"]).GetInt();
	this->rfc1123=(document["result"]["rfc1123"]).GetString();
}
int Time::getUnixtime()
{
	return this->unixtime;
}
const char* Time::getrfc1123()
{
	return this->rfc1123;
}
void Time::printTime()
{
	printf("%d, %s\n", this->unixtime, this->rfc1123);
}
}
}



