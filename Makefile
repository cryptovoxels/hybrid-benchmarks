
all:
	clang++ -O3 -g -std=c++11 glm.cpp -o glm
	./glm
	clang++ -O3 -g -std=c++11 main.cpp -o main
	./main
	node main.js
