#include "templates.h"
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

/*enum creature_statline{
	name,
	horror,
	life,
	strength,
	intelligence,
	natural,
	disquiet,
	traumatism

};*/

template<class E>
E create_creature(E a){
	string name;
	string type;
	int life;
	int strength;
	int intelligence;
	bool unnatural;
	int disquiet;
	int traumatism;
	ifstream creaturelist;
	string filepath;
	creaturelist.open("Characters/Creatures/creatures.txt");
	string creature;
	bool on = true;
	char lines[128];
	bool horror;
	if(a){
		string output;
		cout << "Currently created creatures are the following: " << endl;
		while(!creaturelist.eof()){
			creaturelist >> output;
			cout << output << endl;
		}
		creaturelist.close();
		while(on){
			cout << "What creature would you like to create: ";
			cin >> creature;
			toupper(creature[0]);
			filepath = "Characters/Creatures/templates/";
			filepath += creature;
			filepath += ".txt";
			ifstream creatures(filepath);
			if(creatures){
				cout << "here" << endl;
				int number = 1;
				bool exists = true;
				creatures >> type;
				if(type == "Eldritch_Horror") {
					Eldritch_Horror *new_creature;
					new_creature = new Eldritch_Horror();
					horror = true;
					creatures >> new_creature->name;
					creatures >> new_creature->life;
					creatures >> new_creature->strength;
					creatures >> new_creature->intelligence;
					creatures >> new_creature->creature_type;
					creatures >> new_creature->disquiet;
					creatures >> new_creature->traumatism;
					string path = "Characters/Creatures/";
					add_to_file(new_creature, path);
					on = false;
				}
				else{
					Creature *new_creature;
					new_creature = new Creature();
					creatures >> new_creature->name;
					creatures >> new_creature->life;
					creatures >> new_creature->strength;
					creatures >> new_creature->intelligence;
					creatures >> new_creature->creature_type;
					creatures >> new_creature->disquiet;
					string path = "Characters/Creatures/";
					add_to_file(new_creature, path);
					on = false;
				}
				creatures.close();
				/* while(exists) {
					filepath = "Characters/Creatures/";
					filepath+=name;
					string numstring = std::to_string(number);
					filepath += numstring;
					filepath += +".txt";
					ifstream creatures2(filepath);
					if(creatures2){
						number++;
						string stuff;
						cout << filepath << endl;
						cin >> stuff;
					}
					else{
						//newcreature.open(filepath);

						name+=numstring;
						newcreature << name << endl;
						newcreature << horror << endl;
						newcreature << life << endl;
						newcreature << strength << endl;
						newcreature << intelligence << endl;
						newcreature << unnatural << endl;
						newcreature << disquiet << endl;
						if(horror){
							newcreature << traumatism << endl;
						}
						exists = false;
						on = false;
					}
				} */
			}
			else {
				cout << "Template does not exists." << endl;	
			}
		}
	}
	else {
		while(on){
		bool exists = false;
		cout << "What is the name of the new creature(do not use spaces in the name use a underscore)? ";
		cin >> name;
		while(!creaturelist.eof()){
			string creaturename;
			creaturelist >> creaturename;
			if(name == creaturename){
				cout << "here";
				exists = true;
				break;
			}
			}
		if(exists){
			cout << "Creature already exists." << endl;
		}
		else {
			creaturelist.close();
			ofstream listappend;
			listappend.open("Characters/Creatures/creatures.txt", std::ios_base::app);
			listappend << name << "\n";
			listappend.close();
			char ishor;
			filepath = "Characters/Creatures/templates/";
			filepath += name;
			filepath += ".txt";
			//newcreature.open(filepath);
			cout << "Is creature a eldritch horror y for yes, any other entry will be a no? ";
			cin >> ishor;
			if(std::tolower(ishor) == 'y'){
				horror = true;
				type = "Eldritch_Horror";
			}
			else {
				type = "Creature";
			}
			cout << "The following stats are on a scale of 1 - 10." << endl;
			cout << "How much health does it have? ";
			cin >> life;
			cout << "How strong is it? ";
			cin >> strength;
			cout << "How intelligent is it? ";
			cin >> intelligence;
			cout << "How much feeling of unease does the creature cause on sight? "; 
			cin >> disquiet;
			cout << "Is the creature a supernatural being y for yes, any other entry will be a no? ";
			cin >> ishor;
			if(std::tolower(ishor) == 'y'){
				unnatural = true;
			}
			/*newcreature << name << endl;
			newcreature << horror << endl;
			newcreature << life << endl;
			newcreature << strength << endl;
			newcreature << intelligence << endl;
			newcreature << unnatural << endl;
			newcreature << disquiet << endl;
			if(horror) {
				cout << "on a scale of 1 - 3 how much terror does the being invoke? ";
				cin >> traumatism;
				newcreature << traumatism << endl;
			}*/
			//newcreature.close();
			on = false;
		}	
		}
	}
return 0;
}

template<class I, typename X>
void add_to_file(I type, X path) {
	string name;
	string filepath;
	bool exists = true;
	name = type->name;
	int number = 1;
	while(exists){
		string num_to_str = to_string(number);
		cout << "here2" << endl;
		filepath = path;
		filepath += name;
		filepath += num_to_str;
		filepath += ".txt";
		ifstream check(filepath);
		
		if(check){
			number++;
		}
		else{
			ofstream out(filepath);
			out << type->getTxtString();
			exists = false;
		}
	}

}


bool name_checker(string name){
	ifstream personfile;
	string filepath = "Characters/People/";
	filepath += name;
	filepath += ".txt";
	personfile.open(filepath);
	if(personfile){
	personfile.close();
	cout <<"Name is taken"<<endl;
	return true;}
	else{
		return false;
	}
}

bool job_checker(string job){
	ifstream jobfile;
	string filepath = "Character/People/templates/";
	filepath += job;
	filepath += ".txt";
	jobfile.open(filepath);
	if(jobfile){
		jobfile.close();
		return true;
	}
	else{
		cout <<"Job does not exist"<<endl;
		return false;
	}
}

template<class P>
P create_person(P a,P b){
	int life;
	int strength;
	int intelligence;
	string gender;
	int fear;
	int terror;
	string name = a;
	string job = b;
	string line;
	string output;
	string person;
	bool isTaken = name_checker(name);
	ifstream personlist;
	personlist.open("Characters/People/people.txt");
	while(isTaken){
		cout <<"These names are taken, duplicates are strictly forbidden.  "<<endl;
		while(!personlist.eof()){
		personlist >> output;
		cout << output << endl;
		cout <<"Enter a new name: "<<endl;
		cin >> name;
		isTaken = name_checker(name);
	}
	}
	personlist.close();
	bool doesExist;
	doesExist = job_checker(job);
	while(!doesExist){
		cout << "Enter a registered job title: ";
		cin >> job;
		doesExist = job_checker(job);
	}



	/* ofstream listappend;
	listappend.open("Characters/People/templates/jobs.txt", std::ios_base::app);
	listappend << job << "\n";
	listappend.close(); */

	
	
		
	return 0;}



main() {
	bool on = true;
	char choice;
	//having the limit of player characters be 10, because 10 players is already insanity for a game master
	while(on){
	bool iscreature;
	cout<<"1. create creature\n2. create npc\n3. create investigator\nq. quit " <<endl;
	cin >> choice;
	if(std::tolower(choice) == 'q'){
		on = false;
		break;
	}
	else if(choice == '1'){
		bool creaturechoice = true;
		while(creaturechoice){
		cout << "would you like to create a [n]ew creature or [s]pawn from a existing template? ";
		char isnew;
		cin >> isnew;
		if(std::tolower(isnew) == 'n'){
			// implement createnew();
			creaturechoice = false;
			create_creature(creaturechoice);
		}
		else if(std::tolower(isnew) == 's'){
		iscreature = true;
		create_creature(iscreature);
		creaturechoice = false;
		}
		else{
			cout << "invalid choice" << endl;
		}
		}
	}
	else if(choice == '2'){
		string name = "";
		string job = "";
		string jobs;
		cout << "Enter name: ";
		cin >> name;
		ifstream joblist;
		string outjobs;
		joblist.open("Character/People/templates/jobs.txt");
		cout << "Possible jobs to select from"<<endl;
		while(!joblist.eof()){
			joblist >> outjobs;
			cout << outjobs;
		}
		joblist.close();
		cout << "Enter job title: ";
		cin >> job;
		create_person(name,job);
	}
	else if(choice == '3'){

	}
	else{
		cout << "Invalid choice." << endl;
	}
	}
};