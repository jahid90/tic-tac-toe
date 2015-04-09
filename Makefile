TicTacToe: *.cpp *.h
	g++ $(CFLAGS) -o TicTacToe *.cpp
	
clean:
	rm -f *.o *.exe