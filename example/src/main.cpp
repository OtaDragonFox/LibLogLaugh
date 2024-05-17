#include <logger.h>
int main()
{
	LOGGER().setup();

	LOG(LTRACE, "HELL WORLD");
	LOG(LWARNG, "HELL WORLD");
	LOG(LERROR, "HELL WORLD");
	LOG(LFATAL, "HELL WORLD");

	LOG(LTRACE, "HELL WORLD %i", 18);
	LOG(LWARNG, "HELL WORLD %i", 17);
	LOG(LERROR, "HELL WORLD %i", 16);
	LOG(LFATAL, "HELL WORLD %i", 15);



	LOGGER().shutdown();
	return 0;
}


