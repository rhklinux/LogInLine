#ifndef MUTEX_BACJ452T

#define MUTEX_BACJ452T

#include <iostream>

#ifdef USE_STL
#include "stl/mutex.h"
#else
#ifdef OS_LINUX
#include "linux/mutex.h"
#endif // OS_LINUX
#endif // USE_STL

#include "../debug.h"
using std::ostream;

extern mutex_t lock;

// change the name of the class
class MutexHolder 
{
public:
	MutexHolder (logger* _logger)
	{
#if THREAD_SAFE
		lock_mutex(&lock);
#endif
		this->_logger = _logger;
	}

	~MutexHolder ()
	{
#if THREAD_SAFE
		unlock_mutex(&lock);
#endif
		_logger->flush_stream ();
	}
private:
	logger* _logger;
};


#endif /* end of include guard: MUTEX_BACJ452T */
