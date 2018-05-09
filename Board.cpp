using namespace std;

#include <iostream>
#include <Board.h>




ostream& Board operator <<(ostream& os, const Board& b){
    for(int i=0, i<size; i++){
            for(int j=0, j<size; j++){
                os << matrix[i][j]; 
            }
    }
    
    return os;
}


 
