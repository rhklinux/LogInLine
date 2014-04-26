#include "log.h"
#include <iostream>


int main(int argc, const char *argv[])
{
	string s("Hello again");

	LOG() << "Hello logger " << "world !\n";
	LOG() << s << "world !\n";
	return 0;
}
