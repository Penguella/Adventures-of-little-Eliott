#pragma once
#include <iostream>
#include<string>
#include "Allies.h"
#include "Enemies.h"
using namespace std;
class Player
{
public:
	string name;
	int player_hp;
	int player_damage;
	Player() {
		name = "Eliott";
		player_hp = 1000;
		player_damage = 1000;
	}
	void metAlly(Allies ally) {
		cout << "Met a potential ally" << endl;
	}
	void addAlly(Allies ally) {
		player_hp = player_hp + ally.hp;
		player_damage = player_damage + ally.damage;
		cout << "Now Eliott's hp is " << player_hp << " and damage " << player_damage << endl;
	}
	bool defeatsEnemy(Enemies enemy) {
		if (player_hp/enemy.damage>enemy.hp/player_damage) {
			return true;
		}
		else {
			return false;
		}
	}
};

