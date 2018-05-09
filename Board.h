#pragma once
#include "Place.h"
using namespace std;


class Board{

	Place** matrix;
	int size;

public:

Board(int length);
Board(const Board& b);
~Board();
Place& operator[](const Place& p) ; //const std::pair<int,int>& Index
Board& operator=(char index);
Board& operator=(const Board& b);
void initial();
void create(int newsize);
void free();
friend ostream& operator<<(ostream& os, const Board& b);
};

