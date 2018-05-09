#include "IllegalCoordinateException.h"



IllegalCoordinateException::IllegalCoordinateException(int i,int j):i(i),j(j){};

string IllegalCoordinateException::theCoordinate() const{
	string str  = to_string(this->i)+","+to_string(this->j);
	return str;
}
