#include <stdio.h>
#include <iostream>
#include <boundries.h>
#include <chrono>
using namespace std;

template<class T>
T roll(T a, T b){
    T diff = b - a;
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    random_num = a + rand() % diff;
    return random_num;
};


class Being{
    public:
        int life;
        int strength;
        int intelligence;
};

class Person: public Being {
    public:
    string gender;
    int fear;
};

class Investigator: public Person {
    public: 
    int terror;
};

class Creature: public Being {
    public:
    bool unnatural;
    int disquiet;
};

class Eldritch_Horror: public Creature {
    public:
    int traumatism;
};

