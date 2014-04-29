#ifndef LINUX_COMMON_BQEA4DME

#define LINUX_COMMON_BQEA4DME

#define __PORTABLE_FORCE_INLINE__ __attribute__((always_inline))

#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <string>
#include <time.h>

using std::string;

inline string get_tid() __attribute__((always_inline));
inline string get_timestamp() __attribute__((always_inline));

string get_tid()
{
	pid_t id = syscall(SYS_gettid);
	return string(std::to_string(id));
}

string get_timestamp()
{
	time_t rawtime;
	size_t pos;

	time (&rawtime);
	string str(ctime(&rawtime));
	pos = str.find("\n");

	if (pos != string::npos)
	{
		str[pos] = '\0';
	}
	return str;
}

#endif /* end of include guard: LINUX_COMMON_BQEA4DME */
