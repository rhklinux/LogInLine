
HEADERS = log.h \
	  os/common.h \
	   os/mutex.h

HEADERS_LINUX = os/linux/common.h \
		os/linux/mutex.h

SOURCES = log.cpp \
	  main.cpp

OS = OS_LINUX
THREAD_SAFE_VALUE = 1
THREAD_SAFE_MACRO = THREAD_SAFE

target: $(SOURCES) $(HEADERS) $(HEADERS_LINUX)
	g++ -std=c++11 -D$(OS) -D$(THREAD_SAFE_MACRO)=$(THREAD_SAFE_VALUE) -o target $(SOURCES)
clean:
	rm target
