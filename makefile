a.o: Board.o IllegalCharException.o IllegalCoordinateException.o Place.o
	g++ main.cpp Board.cpp Place.cpp IllegalCoordinateException.cpp IllegalCharException.cpp -o a
Place.o: Place.cpp Place.h
	g++ Place.cpp Place.h -c Place.cpp
Board.o: Board.cpp Board.h
	g++ Board.cpp Board.h -c Board.cpp
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	g++ IllegalCharException.cpp IllegalCharException.h -c IllegalCharException.cpp
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	g++ IllegalCoordinateException.cpp IllegalCoordinateException.h -c IllegalCoordinateException.cpp
clean:
	rm *.o a.out
