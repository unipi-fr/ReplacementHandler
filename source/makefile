main: main.o ReplacementHandler.o
	g++ -g -o main main.cpp ReplacementHandler.h ReplacementHandler.o ReplacementHandlerExceptions.h

.cpp.o:
	g++ -Wall -c $<

clean:
	rm main *.o
