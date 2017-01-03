equipo: main.o principal.o index.o
	g++ main.o principal.o index.o -o equipo

main.o : main.cpp
	g++ -c main.cpp

principal.o : principal.cpp principal.h
	g++ -c principal.cpp

index.o : index.cpp index.h
	g++ -c index.cpp

clean:
	rm *.o equipo
