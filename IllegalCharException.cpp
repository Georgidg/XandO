
#include "IllegalCharException.h"




IllegalCharException::IllegalCharException(char undex):index(index)
{};


char IllegalCharException::theChar() const{
return this->index;
}
