using namespace std;
#pragma once
#include <iostream>
//#include "IllegalCharException.h"

class Place{
    int x;
    int y;
   char index;

public:

    Place(){
        this->index='.';
    }

    Place(int a,int b){
        this->x=a;
        this->y=b;
    }

    
    
    Place(const Place& p){
        this->x=p.x;
        this->y=p.y;
    }

     bool operator==(char c)const{
         return(this->index==c);
    //      if(chr==other)
	//     return true;
	//   return false;

         
     }


    operator char() const{
        return this->index;
    }



    Place& operator = (char c){
        // if (index != 'X' && index != 'O' && index != '.')
		// throw IllegalCharException(this->index);
	this->index = index;

	return *this;
    }

    // char operator = (Place p){
    //     this->x=p.x;
    //     this->y=p.y;
                //return matrix[this->x][this->y];
                // char c;
                // c = matrix[this->x][this->y];
                // return c;
    // }
    
friend  ostream& operator <<(ostream& os, const char& c);

    // Place& operator [] (int a, int b){
    //     return index;
    // }

};

ostream& operator <<(ostream& os, const char& c){
        os << c;
        return os;
    }