
all:
	g++ -O3 -DNDEBUG -std=c++11 -framework OpenGL glm.cpp -o glm
	./glm
	g++ -O3 -DNDEBUG -std=c++11 main.cpp -o main
	./main
	node main.js
