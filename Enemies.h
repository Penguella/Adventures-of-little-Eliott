#pragma once
#include <iostream>
#include<string>
using namespace std;
class Enemies
{
public:
	int type_of_enemy;
	int hp;
	int damage;
	Enemies() {
		type_of_enemy = 0;
		hp = 0;
		damage = 0;
	}
	void GetEnemy(int type_of_enemy) {
		if (type_of_enemy == 1) {
			cout << "Goblin bandit" << endl;
			hp = 1000;
			damage = 35;
			cout << "HP of enemy: " << hp << " and damage :" << damage << endl;
		}
		if (type_of_enemy == 2) {
			cout << "Orc Warrior" << endl;
			hp = 5500;
			damage = 250;
			cout << "HP of enemy: " << hp << " and damage :" << damage << endl;
		}
		if (type_of_enemy == 3) {
			cout << "Devil General" << endl;
			hp = 10000;
			damage = 2000;
			cout << "HP of enemy: " << hp << " and damage :" << damage << endl;
		}
	}
};

