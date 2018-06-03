#pragma once
#include "Place.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Board{


public:

	Place** matrix;
	int size;
Board();
Board(int newsize);
Board(const Board& b);

Place& operator[](const Place& p) ; 
Board& operator=(char index);
Board& operator=(const Board& b);
~Board();
void create(int newsize);
string draw(int n);

friend ostream& operator<<(ostream& os,  const Board& b);
friend istream& operator>>(istream& is,   Board& b);
};

