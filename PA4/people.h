#include<templates.h>
#include<boundries.h>
//enum class Stats;

Investigator:: Investigator(int life, int strength, int intelligence, string gender, int fear, int terror) {
	this->life = roll(MIN_STAT, MAX_STAT);
	this->strength = roll(MIN_STAT, MAX_STAT);
	this->intelligence = roll(MIN_STAT, MAX_STAT);
	this->gender = gender;
	this->fear = roll(MIN_STAT, MAX_STAT);
	this->terror = roll(MIN_STAT, ELDRICTH_MAX);
}

Nurse::Nurse() {
	this->life = roll(5,8);
	this->strength = roll(3,8);
	this->intelligence = roll(7,10);
}

Reporter::Reporter() {
	this->life = roll(5,8);
	this->strength = roll(2,7);
	this->intelligence = roll(6,9);
}
Proffessor::Proffessor() {
	this->life = roll(4,7);
	this->strength = roll(1,6);
	this->intelligence = roll(8,11);
}


