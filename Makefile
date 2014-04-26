
HEADERS = log.h \
	  os/common.h

SOURCES = log.cpp

target: $(SOURCES) $(HEADERS)
	g++ -std=c++11 -I/os/ -o target $(SOURCES)
clean:
	rm target
