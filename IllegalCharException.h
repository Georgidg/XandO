
using namespace std;
#pragma once
#include <iostream>
#include "Board.h"
#include "IllegalCoordinateException.h"
#include "Place.h"
#include "Character.h"


char IllegalCharException::theChar() const{
  return c;
}