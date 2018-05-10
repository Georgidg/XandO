#pragma once
#include "Place.h"
using namespace std;


class Board{

	Place** matrix;
	int size;

public:

Board(int length);
Board(const Board& b);

Place& operator[](const Place& p) ; 
Board& operator=(char index);
Board& operator=(const Board& b);

void create(int newsize);

friend ostream& operator<<(ostream& os, const Board& b);
};

