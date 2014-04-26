target: ./log.cpp ./log.h
	g++ -std=c++11 -o target ./log.cpp
clean:
	rm target
