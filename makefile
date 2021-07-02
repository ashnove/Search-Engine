CC = g++
default: engine clean
engine: engine.o readInputData.o Map.o trienode.o listnode.o search.o
	$(CC) -o engine engine.o readInputData.o Map.o trienode.o listnode.o search.o
engine.o: engine.cpp engine.h
	$(CC) -c engine.cpp 
readInputData.o: readInputData.cpp readInputData.h
	$(CC) -c readInputData.cpp
Map.o: Map.cpp Map.h
	$(CC) -c Map.cpp
trienode.o: trienode.cpp trienode.h
	$(CC) -c trienode.cpp
listnode.o: listnode.cpp listnode.h
	$(CC) -c listnode.cpp
search.o: search.cpp search.h
	$(CC) -c search.cpp
clean: 
	rm *.o
