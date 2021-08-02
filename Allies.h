#pragma once
#include <iostream>
#include<string>
using namespace std;
class Allies
{
public:
	int type_of_ally;
	int hp;
	int damage;
	Allies() {
		type_of_ally = 0;
		hp = 0;
		damage = 0;
	}
	void GetAlly(int type_of_ally) {
		if (type_of_ally == 1) {
			cout << "Sorceress" << endl;
			hp = 150;
			damage = 250;
			cout << "HP of ally: " << hp << " and damage :" << damage << endl;
		}
		if (type_of_ally == 2) {
			cout << "Elena of Litheen" << endl;
			hp = 250;
			damage = 850;
			cout << "HP of ally: " << hp << " and damage :" << damage << endl;
		}
		if (type_of_ally == 3){
			cout << "Lucas King" << endl;
			hp = 800;
			damage = 1250;
			cout << "HP of ally: " << hp << " and damage :" << damage << endl;
		}
	
	}
};
