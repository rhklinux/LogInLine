#include <iostream>

#include "./custom.h"
#include "logger.h"

int main(int argc, const char *argv[])
{
	string s("Hello again");
	custom_t t;

	LOG() << "Hello logger " << t << "world !\n";
	LOG() << s << 8 << 67.899 << -1 << " world !\n";
	return 0;
}
