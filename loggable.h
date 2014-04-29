#ifndef LOGABLE // change
#define LOGABLE

#include <string>

#include "./logger.h"

using std::string;

class loggable
{
	public:
		friend logger& operator<<(logger&, const loggable&);
			
};

#endif
