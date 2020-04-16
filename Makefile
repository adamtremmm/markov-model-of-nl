all: test

test: test.o
	g++ -o test test.o MModel.o -std=c++11 -l boost_unit_test_framework
test.o: test.cpp MModel.o
	g++ -c test.cpp -o test.o -std=c++11
MModel.o: MModel.cpp
	g++ -c MModel.cpp -o MModel.o -std=c++11
clean:
	rm *.o test