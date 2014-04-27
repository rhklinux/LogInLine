#ifndef MUTEX_45RV0ODG

#define MUTEX_45RV0ODG

#include <mutex>
#include <iostream>

using std::cerr;
using std::mutex;

typedef mutex mutex_t;

inline void init_mutex(mutex_t *m)__attribute__((always_inline));
inline void destroy_mutex(mutex_t *m) __attribute__((always_inline));
inline void lock_mutex(mutex_t *m) __attribute__((always_inline));
inline void unlock_mutex(mutex_t *m) __attribute__((always_inline));

void init_mutex(mutex_t *m)
{
	m = new mutex();
}


void destroy_mutex(mutex_t *m) 
{
	delete (m);
}

void lock_mutex(mutex_t *m)
{
	m->lock();
}

void unlock_mutex(mutex_t *m)
{
	m->unlock();
}

#endif /* end of include guard: MUTEX_45RV0ODG */
