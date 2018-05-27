#include <iostream>
#include <stdbool.h>
#include "Place.h"
#include "IllegalCharException.h"



Place::Place(){
	index = '.';
}



Place::Place(int x,int y) : x(x),y(y){}


Place& Place::operator=(char index){
	if (index != 'X' && index != 'O' && index != '.')
		throw IllegalCharException(index);
	this->index = index;

	return *this;
}

bool Place::operator==(char b)const{
	 return(index==b);
	

}

Place::operator char() const{
	return this->index;
}

int Place::getX() const{
	return x;
}

int Place::getY() const{
	return y;

}

char Place::getChar() const{
	return index;
}

void Place::setChar(const char index){
	this->index = index;
}
