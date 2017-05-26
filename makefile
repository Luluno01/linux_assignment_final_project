main:main.o dsque.o dsstk.o dstree.o
	g++ $^ -o main
main.o:main.cpp
	g++ -c $^
dsque.o:dsque.cpp
	g++ -c $^
dsstk.o:dsstk.cpp
	g++ -c $^
dstree.o:dstree.cpp
	g++ -c $^
.PHONY: clean
clean:
	rm -f main *.o
