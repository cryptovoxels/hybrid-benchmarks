
all:
	g++ -O3 -DNDEBUG -std=c++11 main.cpp -o main
	./main
	node main.js
