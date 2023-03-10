#include <stdio.h>
#include <iostream>
#include "boundries.h"
#include <chrono>
#include <string.h>
#include <string>
using namespace std;

template<class T>
T roll(T a, T b){
    T diff = b - a;
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int random_num = a + rand() % diff;
    return random_num;
};

enum Origin {
	Natural,
	Unnatural
};
static const char* UnnaturalStrings[] = {"Natural", "Unnatural"};

const char * getOriginString(int value){
	return UnnaturalStrings[value];
}

class Being{
    public:
	//Being(int life, int strength, int intelligence);
	friend ostream& operator<<(ostream out, const Being *bg);
		string name;
        int life;
        int strength;
        int intelligence;
		virtual void print();
		virtual string getTxtString();
	
};

string Being::getTxtString(){
	string txtString = "";
	txtString += this->name;
	txtString += "\n" + to_string(this->life);
	txtString += "\n" + to_string(this->strength);
	txtString += "\n" + to_string(this->intelligence);
	return txtString;
}

void Being::print(){
	cout << "Name: " << this->name <<endl;
	cout << "Life: " << this->life <<endl;
	cout << "strength: " << this->strength <<endl;
	cout << "intelligence: " << this->intelligence <<endl;
}

/*Being::Being(){
	this->name = name;
	this->life = life;
	this->strength = strength;
	this->intelligence = intelligence;
}*/

class Person: public Being {
    public:
	Person(string name = "", string job = "", string gender = "", int life = roll(MIN_STAT, MAX_STAT), int strength = roll(MIN_STAT, MAX_STAT), int intelligence= roll(MIN_STAT, MAX_STAT), int fear= roll(MIN_STAT, MAX_STAT));
	string job;
    string gender;
    int fear;
	virtual void print();
	virtual string getTxtString();

};

string Person::getTxtString(){
	
	string txtString = Being::getTxtString();
	txtString += "\n" + to_string(this->fear);
	return txtString;
}
void Person::print(){
	cout << "fear: " << this->fear <<endl;

}

class Investigator: public Person {
    public: 
	Investigator(string name = "", string job = "", string gender = "", int life = roll(MIN_STAT, MAX_STAT), int strength = roll(MIN_STAT, MAX_STAT), int intelligence= roll(MIN_STAT, MAX_STAT), int fear= roll(MIN_STAT, MAX_STAT), int terror= 0);
    int terror;
	virtual void print();
	virtual string getTxtString();
};

string Investigator::getTxtString(){
	string txtString = Person::getTxtString();
	txtString += "\n" + to_string(this->terror);
	return txtString;
}
void Investigator::print(){
	cout << "terror: " << this->terror <<endl;
}

class Creature: public Being {
    public:
	Creature(string name = "", int life = roll(MIN_STAT, MAX_STAT), int strength = roll(MIN_STAT, MAX_STAT), int intelligence= roll(MIN_STAT, MAX_STAT), Origin creature_type = Natural, int disquiet = roll(MIN_STAT, MAX_STAT));
    Origin creature_type;
    int disquiet;
	virtual void print();
	virtual string getTxtString();
	friend ostream& operator <<(ostream& out, const Creature *horror);
};
Creature::Creature(string name, int life, int strength, int intelligence, Origin creature_type, int disquiet) {

}
string Creature::getTxtString(){
	string txtString = Being::getTxtString();
	txtString += "\n" + to_string(this->creature_type);
	txtString += "\n" + to_string(this->disquiet);
	return txtString;
}

void Creature::print(){
	cout << "Unnatural: " << this->creature_type <<endl;
	cout << "Disquiet: " << this->disquiet <<endl;
}

class Eldritch_Horror: public Creature {
    public:
	Eldritch_Horror(string name = "", int life = roll(MIN_STAT, MAX_STAT), int strength = roll(MIN_STAT, MAX_STAT), int intelligence= roll(MIN_STAT, MAX_STAT), int traumatism = roll(MIN_STAT, ELDRICTH_MAX), Origin creature_type = Unnatural, int disquiet = roll(MIN_STAT, MAX_STAT));
    int traumatism;
	virtual void print();
	virtual string getTxtString();
	friend ostream& operator <<(ostream& out, const Eldritch_Horror *horror);
};
Eldritch_Horror::Eldritch_Horror(string name, int life, int strength, int intelligence, int traumatism, Origin creature_type, int disquiet) {
	this->name = name;
}

string Eldritch_Horror::getTxtString(){
	string txtString = Creature::getTxtString();
	txtString += "\n" + to_string(this->traumatism);
	return txtString;
}

void Eldritch_Horror::print(){
	cout << "traumatism: " << this->traumatism <<endl;
}

ostream& operator<<(ostream& out, const Eldritch_Horror *horror){
	out << "Name: " << horror->name << endl;
	out << "Life: " << horror->life << endl;
	out << "Strength: " << horror->strength << endl;
	out << "Intelligence: " << horror->intelligence << endl;
	out << "Origin: " << getOriginString(horror->creature_type) << endl;
	out << "Disquet: " << horror->disquiet << endl;
	out << "Traumatism: " << horror->traumatism << endl;
	return out;
}
ostream& operator<<(ostream& out, const Creature *horror){
	out << "Name: " << horror->name << endl;
	out << "Life: " << horror->life << endl;
	out << "Strength: " << horror->strength << endl;
	out << "Intelligence: " << horror->intelligence << endl;
	out << "Origin: " << getOriginString(horror->creature_type) << endl;
	out << "Disquet: " << horror->disquiet << endl;
	return out;
}

/*class Nurse: public Person {
	public:
	Nurse(string name = "Ratchett", string job = "Nurse", string gender = "Female", int life = roll(5,8), int strenght = roll(3,8), int intelligence = roll(7,10));
};

class Reporter: public Person {
	public:
	Reporter(string name = "Ron_Burgundy", string job = "Reporter", string gender = "Male", int life = roll(5,8), int strenght = roll(2,7), int intelligence = roll(6,9));
};

class Professor: public Person {
	public:
	Professor(string name = "Hubert_Farnsworth", string job = "Professor", string gender = "Male", int life = roll(4,7), int strenght = roll(1,6), int intelligence = roll(8,11));
};

class Ghoul: public Creature {
	public: 
	Ghoul(string name = "Ghoul", int life = 4, int strength = 4, int intelligence= 2, int fear= roll(MIN_STAT, MAX_STAT), int terror= roll(MIN_STAT, MAX_STAT), bool unnatural = false, int disquiet = roll(MIN_STAT, MAX_STAT));
	string name = "Ghoul"; //or possibly a Ghast
};

class Wolf: public Creature {
	public:
	int number = 0;
	string name = "Wolf";
};

class Chthonian: public Eldritch_Horror {
	public:
	int number = 0;
	string name = "Chthoninan";
};
class Shoggoth: public Eldritch_Horror {
	public:
	int number = 0;
	string name = "Shoggoth";
};*/