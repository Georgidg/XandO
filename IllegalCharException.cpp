
#include "IllegalCharException.h"




IllegalCharException::IllegalCharException(char undex):index(undex)
{};


char IllegalCharException::theChar() const{
return this->index;
}
