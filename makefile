a.o: Board.o IllegalCharException.o IllegalCoordinateException.o Place.o
	
Place.o: Place.cpp Place.h
	clang++-5.0 -std=c++17 -c Place.cpp
Board.o: Board.cpp Board.h
	clang++-5.0 -std=c++17 -c Board.cpp
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	clang++-5.0 -std=c++17 -c IllegalCharException.cpp
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	clang++-5.0 -std=c++17 -c IllegalCoordinateException.cpp
clean:
	rm *.o a.out
