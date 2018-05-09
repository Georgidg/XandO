#include <exception>
using namespace std;
#pragma once
#include <iostream>
#include <IllegalCharException.h>

class IllegalCharException{
    char c;
public:
    IllegalCharException(char chr) : c(chr) {}
    char theChar() const;
};