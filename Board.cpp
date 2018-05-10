#include <iostream>
#include "Board.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;

Board::Board(int newsize) {
	create(newsize);

}

Board::Board(const Board& b){
	create(b.size);
	for (int i = 0; i < b.size; i++)
			for (int j = 0; j < b.size; j++)
				matrix[i][j] = b.matrix[i][j];
}

// Board::~Board() {
// 	free();
// }

void Board::create(int newsize) {
	size = newsize;
	matrix = new Place*[size];
	for (int i = 0; i < size; ++i)
				matrix[i] = new Place[size];


}

ostream& operator<<(ostream& os, const Board& b) {
	for (int i = 0; i < b.size; i++) {
		for (int j = 0; j < b.size; j++) {
			os << b.matrix[i][j].getChar();
		}
		os << "" << endl;
	}
	return os;
}

Place& Board::operator[](const Place& p) {
	if (p.getX() < 0 || p.getX() >= size || p.getY() < 0 || p.getY() >= size)
		throw IllegalCoordinateException(p.getX(), p.getY());
	return matrix[p.getX()][p.getY()];

}

Board& Board::operator=(char index) {
	if (index != '.')
		throw IllegalCharException(index);
	//initial();
	return *this;

}

Board& Board::operator=(const Board& b) {
	if(this != &b){
	if (size != b.size) {
			//free();
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
// 		delete[] matrix[i]; 
// 	delete[] matrix;  

// }

// void Board::initial() {
// 	for (int i = 0; i < size; i++)
// 		for (int j = 0; j < size; j++)
// 			matrix[i][j].setChar('.');
// }

