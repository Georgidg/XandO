
#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

int main() {
	Board board;
	cin >> board;
	string filename = board.draw(600);
	cout << filename << endl;
}

