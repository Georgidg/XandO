


// int main() {
//   const int dimx = 800, dimy =800; // numbers of pixels
//   int size = 7; //size of board
//   int countY = 0,countX = 0;
//   int i, j;
//   Board board1{4};
//   board1[{1,1}]='X';
//   board1[{1,2}]='O';
//   board1[{3,3}]='X';
//   ofstream imageFile("cpp.ppm", ios::out | ios::binary);
//   imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
//   RGB image[dimx][dimy];

// for (int k=0; k<board1.size; k++){
// 	for(int p=0; p<board1.size; p++){

// 		if(board1[{countX, countY}] == 'X'){
// 			for (j =  dimy/size*countY; j < dimy/size*(countY+1); j++)  {  // row
//     			for (i = dimx/size*countX; i < dimx/size*(countX+1); i++) { // column
// 					image[i][j].red = (250); 
//       				image[i][j].green = (0);
//      	 			image[i][j].blue = (0);
// 				}
// 			}
// 		}
// 		else if(board1[{countX,countY}] == 'O'){
// 			for (j =  dimy/size*countY; j < dimy/size*(countY+1); j++)  {  // row
//     			for (i = dimx/size*countX; i < dimx/size*(countX+1); i++) { // column
// 					image[i][j].red = (0); 
//       				image[i][j].green = (0);
//      	 			image[i][j].blue = (250);
// 				}
// 			}
// 		}
	
// 		if(j==dimy/size*(countY+1)){
// 			countY++;
// 		}else if(countY == size){
// 			countY = 0;
// 		}
// 		if(i==dimx/size*(countX+1)){
// 			countX++;
// 		}else if(countX == size){
// 			countX = 0;
// 		}
// 		// if(( j< dimy/size*(countY+1) && j > dimy/size*countY) && (i< dimx/size*(countX+1) && i > dimx/size*countX)){
//       	// 	image[i][j].red = (100); 
//       	// 	image[i][j].green = (0);
//      	//  	image[i][j].blue = (50);	
// 		// }
		
// 		if(board1[{countX,countY}] == '.'){
// 			for (j =  dimy/size*countY; j < dimy/size*(countY+1); j++)  {  // row
//     			for (i = dimx/size*countX; i < dimx/size*(countX+1); i++) { // column
// 					image[i][j].red = (0); 
//       				image[i][j].green = (0);
//      	 			image[i][j].blue = (0);
// 				}
// 			}
// 		}
//     }
// }
  
// //   image[0].red = 255;
// //   image[0].blue = 0;
// //   image[0].green = 0;
//   ///
//   ///image processing
//   ///
//   imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
//   imageFile.close();
//   return 0;
// }


#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

int main() {
	Board board;
	
	cin >> board;
	string filename = board.draw(700);
	cout << filename << endl;
}

