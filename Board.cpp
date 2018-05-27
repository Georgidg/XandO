using namespace std;

#include <iostream>
#include "Board.h"
//#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"



Board::Board(int newsize) {
	create(newsize);

}

Board::Board(const Board& other){
	create(other.tsize);
	for (int i = 0; i < other.tsize; i++)
			for (int j = 0; j < other.tsize; j++)
				array2D[i][j] = other.array2D[i][j];
}

Board::~Board() {
	free();
}

void Board::create(int size) {
	this->size = size;
	matrix = new Place*[size];
	for (int i = 0; i < size; ++i)
				matrix[i] = new Place[size];


}

ostream& operator <<(ostream& os, const Board& b){
    for(int i=0, i<size; i++){
            for(int j=0, j<size; j++){
                os << b.matrix[i][j];
            }
    }
    
    return os;
}


// ostream& operator<<(ostream& os, const Board& b) {
// 	for (int i = 0; i < b.size; i++) {
// 		for (int j = 0; j < b.size; j++) {
// 			os << b.matrix[i][j].index;
// 		}
// 		os << "" << endl;
// 	}
// 	return os;
// }

Place& Board::operator[](const Place& p) {
	// if (p.x < 0 || p.x >= size || p.y < 0 || p.y >= size)
	// 	throw IllegalCoordinateException(p.x, p.y);
	return matrix[p.x][p.y];

}

Board& Board::operator=(char index) {
	if (index != '.')
		throw IllegalCharException(index);
	initial();
	return *this;

}

Board& Board::operator=(const Board& b) {
	if(this != &b){
	if (size != b.size) {
			free();
			create(b.size);

	}
			for (int i = 0; i < b.size; i++)
						for (int j = 0; j < b.size; j++)
							matrix[i][j] = b.matrix[i][j];


	}
	return *this;
}

// void Board::free() {
// 	for (int i = 0; i < size; i++)
// 		delete[] matrix[i]; // delete array within matrix
// 	delete[] matrix;  // delete actual matrix

// }

// void Board::initial() {
// 	for (int i = 0; i < size; i++)
// 		for (int j = 0; j < size; j++)
// 			matrix[i][j].index = '.';
// }







 
