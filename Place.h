#pragma once

struct Place {
	int x,y;
	Place(int x, int y): x(x), y(y) {}
};

inline ostream& operator << (ostream& os, const Place& p) {
	return (os << p.x << "," << p.y);
}