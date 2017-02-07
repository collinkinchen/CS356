PA1: Cipher.o main.o
	g++ -Wall -I. -std=c++11 Cipher.o main.o -o PA1
Cipher.o: Cipher.cpp Cipher.h
	g++ -Wall -I. -std=c++11 -c Cipher.cpp
main.o: main.cpp Cipher.h
	g++ -Wall -I. -std=c++11 -c main.cpp

clean:
	rm *.o PA1
	
tar:
	tar -cvf PA1.tar *.cpp *.h Makefile