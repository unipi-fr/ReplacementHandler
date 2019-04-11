main: main.o ReplacementHandler.o
	g++ -o main main.cpp ReplacementHandler.h ReplacementHandler.o

.cpp.o:
	g++ -Wall -c $<

clean:
	rm main *.o
