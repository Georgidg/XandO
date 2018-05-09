using namespace std;
#pragma once
#include <iostream>
#include <IllegalCoordinateException.h>

string IllegalCoordinateException::theCoordinate() const {
  string ans = "{"+to_string(p.getX())+","+to_string(p.getY())+"}";
  return ans;
}