#include "Board.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

Board::Board() {
}

Board::Board(int newsize) {
	create(newsize);

}

Board::Board(const Board& b){
	create(b.size);
	for (int i = 0; i < b.size; i++)
			for (int j = 0; j < b.size; j++)
				matrix[i][j] = b.matrix[i][j];
}


void Board::create(int newsize) {
	size = newsize;
	matrix = new Place*[size];
	for (int i = 0; i < size; ++i)
		matrix[i] = new Place[size];
}

string Board::draw(int n){
cout<<"   in draw"<< endl;
  int size = this->size; //size of board
  Board board1{size};
//   int countY = 0,countX = 0;

//   ofstream imageFile("cpp.ppm", ios::out | ios::binary);
//   imageFile << "P6" << endl << n <<" " << n << endl << 255 << endl;
//   RGB image[n][n];

//   for (int j = 0; j < n; j++)  {  // row
//     for (int i = 0; i < n; i++) { // column
// 		if(j==n/size*(countY+1)){
// 			countY++;
// 		}else if(countY == size){
// 			countY = 0;
// 		}
// 		if(i==n/size*(countX+1)){
// 			countX++;
// 		}else if(countX == size){
// 			countX = 0;
// 		}
// 		if(( j< n/size*(countY+1) && j > n/size*countY) && (i< n/size*(countX+1) && i > n/size*countX)){
//       		image[i][j].red = (100); 
//       		image[i][j].green = (0);
//      	 	image[i][j].blue = (50);	
// 		}
		
// 		else{ //black
// 			image[i][j].red = (0); 
//       		image[i][j].green = (0);
//      		image[i][j].blue = (0);
// 		}

//     }
//   }

  int countY = 0,countX = 0;
  int i, j;
 
  ofstream imageFile("cpp.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << n <<" " << n << endl << 255 << endl;
  RGB image[n][n];

for (int k=0; k<size; k++){
	for(int p=0; p<size; p++){

		if(board1[{countX, countY}] == 'X'){
			for (j =  n/size*countY; j < n/size*(countY+1); j++)  {  // row
    			for (i = n/size*countX; i < n/size*(countX+1); i++) { // column
					image[i][j].red = (250); 
      				image[i][j].green = (0);
     	 			image[i][j].blue = (0);
				}
			}
		}
		else if(board1[{countX,countY}] == 'O'){
			for (j =  n/size*countY; j < n/size*(countY+1); j++)  {  // row
    			for (i = n/size*countX; i < n/size*(countX+1); i++) { // column
					image[i][j].red = (0); 
      				image[i][j].green = (0);
     	 			image[i][j].blue = (250);
				}
			}
		}
	
		if(j==n/size*(countY+1)){
			countY++;
		}else if(countY == size){
			countY = 0;
		}
		if(i==n/size*(countX+1)){
			countX++;
		}else if(countX == size){
			countX = 0;
		}
		// if(( j< dimy/size*(countY+1) && j > dimy/size*countY) && (i< dimx/size*(countX+1) && i > dimx/size*countX)){
      	// 	image[i][j].red = (100); 
      	// 	image[i][j].green = (0);
     	//  	image[i][j].blue = (50);	
		// }
		
		if(board1[{countX,countY}] == '.'){
			for (j =  n/size*countY; j < n/size*(countY+1); j++)  {  // row
    			for (i = n/size*countX; i < n/size*(countX+1); i++) { // column
					image[i][j].red = (0); 
      				image[i][j].green = (0);
     	 			image[i][j].blue = (0);
				}
			}
		}
    }
}
  return "board"+to_string(size)+".ppm";
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
	
	return *this;

}

Board& Board::operator=(const Board& b) {
	if(this != &b){
	if (size != b.size) {
			
			create(b.size);

	}
			for (int i = 0; i < b.size; i++)
						for (int j = 0; j < b.size; j++)
							matrix[i][j] = b.matrix[i][j];


	}
	return *this;
}

istream& operator >>(istream& is,  Board& b){
 
	bool firstLine = false;
	string line;
	cin >> line;
	b.create(line.length());
	for (unsigned int i = 0; i < line.length(); ++i) {
			b[{int(0),int(i)}] = line[i];
	}


	for (unsigned int i = 1; i < line.length(); ++i) {
		cin >> line;
		for (unsigned int j = 0; j < line.length(); ++j){
			b[{int(i),int(j)}] = line[j];
		}
	}
	

    return is;

 }


