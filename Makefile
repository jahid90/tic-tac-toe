TicTacToe: TicTacToe.o Main.o
	g++ $(CFLAGS) -o TicTacToe *.o

TicTacToe.o: TicTacToe.cpp TicTacToe.hpp
	g++ $(CFLAGS) -c TicTacToe.cpp

Main.o: Main.cpp
	g++ $(CFLAGS) -c Main.cpp

clean:
	rm -f *.o *.exe