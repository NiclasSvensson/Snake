app: main.o resource.o board.o snake.o
	g++ main.o resource.o board.o snake.o -o app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp constants.h resource.o
	g++ -c main.cpp

resource.o: resource.cpp resource.h
	g++ -c resource.cpp

board.o: board.cpp board.h constants.h
	g++ -c board.cpp

snake.o: snake.cpp snake.h constants.h
	g++ -c snake.cpp

clean:
	rm *.o app