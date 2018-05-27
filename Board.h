using namespace std;
#pragma once
#include <iostream>
#include "Place.h"
//#include "IllegalCharException.h"
//#include "IllegalCoordinateException.h"

class Board{

    int size;
   // Place matrix[][]=new Place[size][size];
    Place** matrix;


  public: 

    //  Board(int size);//{ 
    //     Character matrix[][]=new Character[size][size];
    //     for(int i=0, i<size; i++){
    //         for(int j=0, j<size; j++){
    //             this->matrix[i][j]=Character();
    //         }
    //     }
    // }

    Board(int newsize);
    Board(const Board& other);
    ~Board();
    Place& operator[](const place& p) ; //const std::pair<int,int>& Index
    Board& operator=(char index);
    Board& operator=(const Board& b);
    // void initial();
    void create(int size);
    // void free();

    Board&  operator [] (Place p){
        char c;
        c = this->matrix[p.x][p.y];
        return c;
    }
    // Board& operator = (Character c){
    //     for(int i=0, i<size; i++){
    //         for(int j=0, j<size; j++){
    //             matrix[i][j]=Place(c);
    //         }
    //     }
    // }

 friend   ostream& operator <<(ostream& os, const Board& b);
  
   // Place& operator [] (int a, int b);



    //board()
};
ostream& operator <<(ostream& os, const Board& b);


//  ostream& operator <<(ostream& os, const Board& b){
//         for(int i=0, i<size; i++){
//                 for(int j=0, j<size; j++){
//                     os << b.matrix[i][j];
//                 }
//         }
        
//         return os;
//     }









   


class Board{

	Pair** array2D;
	int tsize;

public:

Board(int length);
Board(const Board& other);
~Board();
Pair& operator[](const Pair& pt) ; //const std::pair<int,int>& Index
Board& operator=(char chr);
Board& operator=(const Board& other);
void initial();
void create(int size);
void free();
friend ostream& operator<<(ostream& os, const Board& br);
};