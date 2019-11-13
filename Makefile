QueueDemo: main.o Queue.o Test.o
		g++ -g -std=c++11 -g -Wall main.o Queue.o Test.o -o QueueDemo

Test.o: Test.h Test.cpp
		g++ -g -std=c++11 -g -Wall -c Test.cpp

main.o: main.cpp Test.h Test.cpp Queue.h
		g++ -g -std=c++11 -g -Wall -c main.cpp

clean:
		rm *.o QueueDemo
