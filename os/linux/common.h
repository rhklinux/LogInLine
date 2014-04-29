#ifndef LINUX_COMMON_BQEA4DME

#define LINUX_COMMON_BQEA4DME

#define __PORTABLE_FORCE_INLINE__ __attribute__((always_inline))

#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <string>

using std::string;

inline string get_tid() __attribute__((always_inline));

string get_tid()
{
	pid_t id = syscall(SYS_gettid);
	return string(std::to_string(id));
}

#endif /* end of include guard: LINUX_COMMON_BQEA4DME */
