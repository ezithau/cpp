#include <iostream>
#include "being.cpp"
#include "templates.h"
class being;

using namespace std;
class Person:public Being{
    public:
    Person(bool isBeing, string gender, int fear);
    

};