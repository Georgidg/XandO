#include "Board.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
static int hodaya=0;

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
  int size = this->size; //size of board
  while(true){
    ifstream kk("board"+to_string(hodaya)+".ppm");
        if(!kk.good())
            break;
        else
          hodaya++;
}
    string name="board"+to_string(hodaya)+".ppm";
   
	ofstream imageFile(name, ios::out | ios::binary);
 	imageFile << "P6" << endl << n <<" " << n << endl << 255 << endl;
  	RGB image[n][n];


	int countX=0, countY=0;
	int i,j;
	for (int k=0; k<size; k++){
		for(int p=0; p<size; p++){
			

			
			if(matrix[k][p] == 'X'){
				for (i =  (n/size)*k; i < n/size*(k+1); i++)  {  // row
					for (j = n/size*p; j < n/size*(p+1); j++) { // column
						image[i][j].red = (250); 
						image[i][j].green = (0);
						image[i][j].blue = (0);
					}
				}
			}
			 if(matrix[k][p] == 'O'){
				for (i =  n/size*k; i < n/size*(k+1); i++)  {  // row
					for (j = n/size*p; j < n/size*(p+1); j++) { // column
						image[i][j].red = (0); 
						image[i][j].green = (0);
						image[i][j].blue = (250);
					}
				}
			}
	

			if(matrix[k][p] == '.'){
				for (i =  n/size*k; i < n/size*(k+1); i++)  {  // row
					for (j = n/size*p; j < n/size*(p+1); j++) { // column
						image[i][j].red = (0); 
						image[i][j].green = (0);
						image[i][j].blue = (0);
					}
				}
			}

		}
	}



	imageFile.write(reinterpret_cast<char*>(&image), 3*n*n);
	imageFile.close();
	





		
  return name;
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
Board::~Board()
{
    for(int i = 0 ; i < size ; i++)
        delete matrix[i];
    delete matrix;
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


