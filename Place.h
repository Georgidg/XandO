#pragma once

#include<iostream>
using namespace std;


class Place {
	int x;
	int y;
	char index;

public:

	Place();
	Place(int x, int y); 
	Place& operator=(char index);
	bool operator==(char b) const;
	operator char() const;
	int getX() const;
	int getY() const;
	char getChar() const;
	void setChar(const char index) ;

};

