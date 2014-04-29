#ifndef CUSTOM_H // to be changed
#define CUSTOM_H

#include <ostream>

#include "./loggable.h"

using std::ostream;

class custom_t : public loggable {
public:
	custom_t () { member = 9; }
	virtual ~custom_t () {};
	friend logger& operator<<(logger& os, const custom_t& c);
private:
	int member;
};


#endif
