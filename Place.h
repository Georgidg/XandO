#pragma once
#include <iostream>

#pragma once

class Place {
    int x;
    int y;
    Place(int x, int y);
    Place (const Place& otherP);
    int get_X ();
    int get_Y();
};

inline ostream& operator<< (ostream& out, const Coordinate& c) {
	return (out << c.x << "," << c.y);
}
