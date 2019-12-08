HelloWorld: main.o Edge.o Node_set.o Disjoint.o Graph.o Minheap.o Executive.o
	g++ -std=c++11 -g -Wall main.o Edge.o Node_set.o Disjoint.o Minheap.o Graph.o Executive.o -o HelloWorld

main.o: main.cpp Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Edge.o: Edge.h Edge.cpp
	g++ -std=c++11 -g -Wall -c Edge.cpp

Graph.o: Graph.h Graph.cpp LinkedList.h LinkedList.cpp Queue.h Queue.cpp ListInterface.h QueueInterface.h
	g++ -std=c++11 -g -Wall -c Graph.cpp

Node_set.o: Node_set.h Node_set.cpp
	g++ -std=c++11 -g -Wall -c Node_set.cpp

Disjoint.o: Disjoint.h Disjoint.cpp
	g++ -std=c++11 -g -Wall -c Disjoint.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Minheap.o: Minheap.h Minheap.cpp
	g++ -std=c++11 -g -Wall -c Minheap.cpp

clean:
	rm *.o HelloWorld
