#include "log.h"

#include <iostream>
#include <fstream>
#include <memory>

using std::string;
using std::ostream;
using std::unique_ptr;
using std::cerr;
using std::filebuf;

logger::logger ()
{
#if DEBUG
	log_stream = &cerr;
#endif
}

logger::logger (string &path)
{
#if DEBUG
	fb.open(path, std::ios::out);
	log_stream = new ostream(&fb);
#endif
}

logger::~logger()
{
#if DEBUG
	if (fb.is_open())
	{
		fb.close();
	} 
#endif	
}

inline void logger::operator<< (string &msg) 
{
#if DEBUG
	*log_stream << msg << std::endl;
	log_stream->flush();
#endif
}
	
inline void logger::operator<< (string msg) 
{
#if DEBUG
	*log_stream << func_name << " " << msg << std::endl;
#endif
}

inline void logger::set_func_name (string msg) 
{
#if DEBUG
	this->func_name = std::move(msg);
#endif
}


//
// if LOG_FILE macro defined then use else print on stderr.
//
#ifdef LOG_FILE
string filename(LOG_FILE); 
logger *lobj = new logger(filename);
#else
logger *lobj = new logger;
#endif


//
// this is to be used by user.
//
#define LOG() lobj->set_func_name(__PRETTY_FUNCTION__); *lobj

int main(int argc, const char *argv[])
{
	LOG() << "Hello logger world !";
	return 0;
}
