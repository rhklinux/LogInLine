#ifndef MUTEX_BACJ452T

#define MUTEX_BACJ452T

#ifdef USE_STL
#include "stl/mutex.h"
#else
#ifdef OS_LINUX
#include "linux/mutex.h"
#endif // OS_LINUX
#endif // USE_STL

extern mutex_t lock;

class MutexHolder 
{
public:
	MutexHolder ()
	{
		lock_mutex(&lock);
	}

	~MutexHolder ()
	{
		unlock_mutex(&lock);
	}
};


#endif /* end of include guard: MUTEX_BACJ452T */
