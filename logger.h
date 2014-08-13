#ifndef LOG_C4ALMVVY

#define LOG_C4ALMVVY

#include <string>
#include <iostream>
#include <fstream>
#include <string.h>

#include "os/common.h"
#include "debug.h"

using std::string;
using std::filebuf;
using std::ostream;

class logger
{

	public:
	logger ();
	logger (string &path);
	~logger();

	inline  logger &operator<<(string &msg) __PORTABLE_FORCE_INLINE__ 
	{
#if DEBUG 
		*log_stream << msg;
	//	if (msg.find("\n") != string::npos) // todo may be instead of find just compare last char ?
	//	{
	//		log_stream->flush();
	//	}
#endif // DEBUG
		return *this;
	}
	
	inline logger &operator<<(const char *msg) __PORTABLE_FORCE_INLINE__ 
	{
#if DEBUG
		string s(msg);
		*this << s;
#endif // DEBUG
		return *this;
	}
	
	inline logger &operator<<(unsigned int msg) __PORTABLE_FORCE_INLINE__ 
	{
#if DEBUG
		string s = std::to_string(msg);
		*this << s;
#endif // DEBUG
		return *this;
	}
	
	inline logger &operator<<(int msg) __PORTABLE_FORCE_INLINE__ 
	{
#if DEBUG
		string s = std::to_string(msg);
		*this << s;
#endif // DEBUG
		return *this;
	}

	inline logger &operator<<(double msg) __PORTABLE_FORCE_INLINE__ 
	{
#if DEBUG
		string s = std::to_string(msg);
		*this << s;
#endif // DEBUG
		return *this;
	}
	
	inline void set_timestamp() __PORTABLE_FORCE_INLINE__
	{
		*log_stream << get_timestamp() << " ";
	}

	inline void set_tid() __PORTABLE_FORCE_INLINE__
	{
#if THREAD_SAFE
		*log_stream << get_tid() << " ";
#endif
	}
	
	//
	// Never call outside this file. !!
	// Use LOG macro.
	//
	inline void set_pre_string(string func_name) __PORTABLE_FORCE_INLINE__
	{
#if DEBUG
		set_tid();
		set_timestamp();
		*log_stream << func_name << " : ";
#endif
	}

	inline void flush_stream () __PORTABLE_FORCE_INLINE__
	{
#if DEBUG
		std::cout << "flushing stream\n";
		if (!log_stream->fail())
		{
			log_stream->flush();
		}
#endif
	}
	private:
	ostream *log_stream;
	filebuf fb;
};

//#if DEBUG
extern logger *lobj;
//#endif // DEBUG

#include "os/mutex.h"


//
//  Thanks to Sammer for Temp obj creation idea !! :)
//

#if DEBUG // DEBUG
#define LOG() MutexHolder().set_stream (lobj), lobj->set_pre_string(__PRETTY_FUNCTION__), *lobj 
#else
#define LOG() *lobj
#endif // DEBUG


#endif /* end of include guard: LOG_C4ALMVVY */
