#include "logger.h"

#include <iostream>
#include <fstream>
#include <memory>

#include "os/mutex.h"

using std::string;
using std::ostream;
using std::unique_ptr;
using std::cerr;
using std::filebuf;

//
// if LOG_FILE macro defined then use else print on stderr.
//
#if DEBUG
#ifdef LOG_FILE
string filename(LOG_FILE); 
logger *lobj = new logger(filename);
#else
logger *lobj = new logger;
#endif // LOG_FILE
#endif // DEBUG

#if DEBUG
#if THREAD_SAFE
mutex_t lock;
#endif // THREAD_SAFE
#endif // DEBUG

logger::logger ()
{
#if DEBUG
	log_stream = &cerr;
#if THREAD_SAFE
	init_mutex(&lock);	
#endif // THREAD_SAFE
#endif // DEBUG
}

logger::logger (string &path)
{
#if DEBUG
	fb.open(path, std::ios::out);
	log_stream = new ostream(&fb);
#if THREAD_SAFE
	init_mutex(&lock);
#endif // THREAD_SAFE
#endif // DEBUG

}

logger::~logger()
{
#if DEBUG
	log_stream->flush();
	if (fb.is_open())
	{
		fb.close();
	} 
#if THREAD_SAFE
	destroy_mutex(&lock);
#endif // THREAD_SAFE
#endif // DEBUG
}




