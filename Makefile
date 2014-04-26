target: ./log.cpp ./log.h
	g++ -std=c++11 -o ./bin/target ./log.cpp
clean:
	rm target
