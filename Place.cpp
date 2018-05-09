using namespace std;
#pragma once
#include <iostream>
#include "Board.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#include "Character.h"

class Place{
    int x;
    int y;

public:
    
    Place(int a,int b){
        this->x = a;
        this->y = b;
    }
    Place (const Place& otherP){
        x = otherP.x;
        y = otherP.y;
    }
    int get_X (){
        return x;
    }
    int get_Y(){
        return y;
    }

};

void isLegal(char c) {
	if (c!='.' && c!='X' && c!='O')
		throw IllegalCharException{c};
}


// board1[{1,2}]='O';
Place& operator = (char c){
    isLegal(c);
    matrix[this->x][this->y] = c;
}

// char c = board1[{1,2}];
char operator = (Place p){
    this->x=p.x;
    this->y=p.y;
    return matrix[this->x][this->y];
    // char c;
    // c = matrix[this->x][this->y];
    // return c;
}

// cout << c << endl;
ostream& char operator << (ostream& os, const char& c){
    os << c;
    return os;
}

// Printing object Place
inline ostream& operator << (ostream& os, const Place& p){
    return (os << "{" << p.x << "," << p.y << "}");
}



Place& operator = (char c){
    if (c == '.' || c == 'X' || c == 'O')
        this->index = c;
    else theChar(const char c); 
}

