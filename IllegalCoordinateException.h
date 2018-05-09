using namespace std;
#pragma once
#include <iostream>
#include "Board.h"
#include "Place.h"
#include "IllegalCharException.h"
#include "Character.h"


class IllegalCoordinateException {
	Place c;
public:
	IllegalCoordinateException(Place p): c(p) {}
	Place theCoordinate() const { return c; }
};