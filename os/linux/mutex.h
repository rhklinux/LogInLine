#ifndef LINUX_MUTEX_WM0DX9BW

#define LINUX_MUTEX_WM0DX9BW

#include <pthread.h>

typedef pthread_mutex_t mutex_t;

inline void init_mutex(mutex_t *m)__attribute__((always_inline));
inline void destroy_mutex(mutex_t *m) __attribute__((always_inline));
inline void lock_mutex(mutex_t *m) __attribute__((always_inline));
inline void unlock_mutex(mutex_t *m) __attribute__((always_inline));

void init_mutex(mutex_t *m)
{
	pthread_mutex_init(m, NULL);
}

void destroy_mutex(mutex_t *m) 
{
	pthread_mutex_destroy(m);
}

void lock_mutex(mutex_t *m)
{
	pthread_mutex_lock(m);
}

void unlock_mutex(mutex_t *m)
{
	pthread_mutex_unlock(m);
}

#endif /* end of include guard: LINUX_MUTEX_WM0DX9BW */
