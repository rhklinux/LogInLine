
HEADERS = logger.h \
	  os/common.h \
	  os/mutex.h \
	  custom.h \
	  ./loggable.h
	  	
HEADERS_LINUX = os/linux/common.h \
		os/linux/mutex.h 
		
HEADERS_STL = os/stl/mutex.h

SOURCES = logger.cpp \
	  main.cpp \
	  custom.cpp

USE_STL = USE_STL
OS = OS_LINUX
THREAD_SAFE_VALUE = 1
THREAD_SAFE_MACRO = THREAD_SAFE

all : target-linux-stl target-linux

target-linux-stl: $(SOURCES) $(HEADERS) $(HEADERS_LINUX) $(HEADERS_STL)
	g++ -std=c++11 -DUSE_STL -D$(OS) -D$(THREAD_SAFE_MACRO)=$(THREAD_SAFE_VALUE) -o target-linux-stl $(SOURCES)

target-linux: $(SOURCES) $(HEADERS) $(HEADERS_LINUX) $(HEADERS_STL)
	g++ -std=c++11 -D$(OS) -D$(THREAD_SAFE_MACRO)=$(THREAD_SAFE_VALUE) -o target-linux $(SOURCES)

clean:
	rm target-linux-stl
	rm target-linux
