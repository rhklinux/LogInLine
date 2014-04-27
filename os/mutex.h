#ifndef MUTEX_BACJ452T

#define MUTEX_BACJ452T

#ifdef USE_STL
#include "stl/mutex.h"
#else
#ifdef OS_LINUX
#include "linux/mutex.h"
#endif // OS_LINUX
#endif // USE_STL

#endif /* end of include guard: MUTEX_BACJ452T */
