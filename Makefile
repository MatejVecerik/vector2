all: main 

main: main.cpp vector2.o 
	g++ $^ -o main  -std=c++11

vector2.o: vector2.h vector2.cpp 
	g++ -c vector2.cpp -o vector2.o  -std=c++11

gen: gen.cpp 
	g++ $^ -o gen  -std=c++11

clean:
	 rm -f main gen vector2.o 

