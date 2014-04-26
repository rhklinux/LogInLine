#ifndef LOG_C4ALMVVY

#define LOG_C4ALMVVY

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::filebuf;
using std::ostream;

#define DEBUG 1
#define LOG_FILE "test.log"

class logger
{

	public:
	logger ();
	logger (string &path);
	~logger();

	inline void operator<< (string &msg) __attribute__((always_inline));
	inline void operator<< (string msg) __attribute__((always_inline));
	inline void set_func_name (string msg) __attribute__((always_inline));

	private:
	ostream *log_stream;
	filebuf fb;
	string func_name;
};


#endif /* end of include guard: LOG_C4ALMVVY */
