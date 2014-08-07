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
#include "../logger.h"
using std::ostream;

extern mutex_t lock;

// change the name of the class
class MutexHolder 
{
public:
	MutexHolder ()
	{
#if THREAD_SAFE
		std::cout << "Locking\n";
		lock_mutex(&lock);
#endif
	}

	~MutexHolder ()
	{
#if THREAD_SAFE
		std::cout << "Unlocking\n";
		unlock_mutex(&lock);
#endif
	}
};


#endif /* end of include guard: MUTEX_BACJ452T */
