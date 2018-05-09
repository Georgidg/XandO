#pragma once
#include <string>

using namespace std;


class IllegalCoordinateException{

	private:
		int i;
		int j;

	public:
		IllegalCoordinateException(int i,int j);
		string theCoordinate()const;

};
