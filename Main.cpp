#include"Ending.h"
#include<math.h>
#include"Player.h"
#include"Allies.h"
#include"Enemies.h"
#include "Items.h"
#include <iostream>
#include <fstream>
#include<string>

using namespace std;

int main() {
	int option = 0; // this variable is used to choose from different options the one we like the most to advance the story 
	cout << "		****		Adventures of Little Eliott		****" << endl;
	cout << endl;
	Player eliott;
	Allies ally;
	Enemies enemy;
	Ending end;
	Items item;
	item.SetPrice();
	srand(time(0));
	ifstream i("scene_one.txt");
	if (i.is_open()) {
		char mychar;
		while (i) {
			mychar = i.get();
			cout << mychar;
		}
	}
	cout << endl;
	int chance = rand() % 100 + 1; // chance to meet the Evil Witch at the beginning of the game
	cin >> option;
	if (option == 1) {
		end.EndingAchieved(1);
	}
	else if (option == 2) {
		cout << "The Elders give you their blessing. You leave the village slightly more confident" << endl;
		cout << " Chance to run into The Evil Witch on your way to town is decreased by 30%" << endl;
		chance = abs((chance - 30));
		cout << "Now the chance to meet her is: " << chance << " %" << endl;

	}
	else if (option == 3) {
		cout << "You head to the town" << endl;
		cout << "The chance to meet the witch is: " << chance << " %" << endl;
	}
	ifstream t("scene_two.txt");
	if (t.is_open()) {
		char mychar;
		while (t) {
			mychar = t.get();
			cout << mychar;
		}
	}
	cout << endl;
	bool met_fairy = false;
	bool can_meet_goblins = false; //once Eliott is a lvl 5 hero and leaves the town, the variable becomes true
	bool can_meet_orcs = false; //once Eliott is a lvl 10 hero and leaves the town, the variable becomes true
	bool will_meet_general = false;//once Eliott is a lvl 21 hero or reaches the end of his adventure, the variable becomes true. 
	bool met_witch = false;
	bool can_meet_elena = false; //once Eliott is a lvl 5 hero and leaves the town, the variable becomes true
	bool can_meet_lucas = false; //once Eliott is a lvl 15 hero and enters the city, the variable becomes true
	cin >> option;
	cout << endl;
	if (chance > 50) {
		 met_witch = true;}
	if (chance <= 50) {
		met_fairy = true;
	}
	if (option == 1) {
		if (met_witch == true) {
			end.EndingAchieved(2);
		}// we met the witch
		if (met_fairy == true) {
			eliott.metAlly(ally);
			ally.GetAlly(1);
			cout << "Do you want this ally? 1 for yes and 2 for no" << endl;
			int opt;
			cin >> opt;
			if (opt == 1) {
				eliott.addAlly(ally);
			}
			if (opt == 2) {
				cout << "The sorceress left, visibly upset. " << endl;
			}
		}
	}
	if (option == 2) {
			int pois_chance = rand() % 100 + 1;// chance to get poisoned by berries
			if (pois_chance > 50) {
				end.EndingAchieved(5);
			}
			if (pois_chance <= 50) {
				cout << "They were not ripe yet, but still better than nothing" << endl;
			}
	}
	if (option == 3) {
		end.EndingAchieved(6);
	}
	int money = 1000;// for demo it will be 1000, so he can recruit Elena asap
	int exp=7500; // for demo it will be 7500, so the level will become 15
	int level = 15;
	//We arrive in town, with or without an ally.
	cout << "A nice small town. What should we do next?" << endl;
	cout << "1) Do chores around the town for some quick cash" << endl;
	cout << "2) Go on an adventure" << endl;
	cout << "3) Sell an item" << endl;
	cout << "4) Take some combat classes(-100 gold per class)" << endl;
	cout << "5) Advance(Recommended before leaving : at least lvl 5 and 2000 gold)" << endl;
	cout << endl;
	cin >> option;
	while (option != 5) {
		if (level == 21) {
			will_meet_general = true;
			enemy.GetEnemy(3);
			bool win = eliott.defeatsEnemy(enemy);
			if (win == true) {
				end.EndingAchieved(4);
			}
			else {
				end.EndingAchieved(3);
			}

		}
		if (exp >= 100 && exp < 5000) {
			level = 5;
			cout << "You are a level " << level << " hero"<< endl;
		}
		if (exp >= 5000 && exp < 7500) {
			level = 10;
			cout << "You are a level " << level << " hero " << endl;
		}
		if (exp >= 7500 && exp < 10000) {
			level = 15;
			cout << "You are a level " << level << " hero " << endl;
		}
		if (exp >= 25000) {
			level = 21;
			cout << "You are now a max level " << level << " hero, prepare to be attacked by the Devil General! "<< endl;
			will_meet_general = true;
			enemy.GetEnemy(3);
			bool win = eliott.defeatsEnemy(enemy);
			if (win == true) {
				end.EndingAchieved(4);
			}
			else {
				end.EndingAchieved(3);
			}

		}
		if (option == 1) {
			int money_from_job = rand() % 500 + 101;
			cout << "You received "<< money_from_job <<" coins" << endl;
			money = money + money_from_job;
			cout << "Now you have  " << money << " coins" << endl;
			cout << "What should we do next?" << endl;
			cin >> option;
		}
		if (option == 2) {
			//adv time
			int money_from_adv = rand() % 30 + 10;
			cout << "You received " << money_from_adv << " coins" << endl;
			money = money + money_from_adv;
			cout << "Now you have  " << money << " coins" << endl;
			int exp_from_adv = rand() % 3000 + 1000;
			exp = exp + exp_from_adv;
			cout << " You received "<<exp_from_adv<<" experience points; in total you have "<<exp << endl;
			int item_index= rand() % 4;
			if (item_index == 0) {
             cout<<"Found berries!"<<endl;
			}
			if (item_index == 1) {
				cout << "Found firewood!" << endl;
			}
			if (item_index == 2) {
				cout << "Catched a fish!" << endl;
			}
			if (item_index == 3) {
				cout << "Hunted an animal" << endl;
			}
			item.Add(item_index);
			item.Check();
			cout << "What should we do next?" << endl;
			cin >> option;
		}
		if (option == 3) {
			//shopping
			cout << "The merchants are only interested in buying things from you. " << endl;
			item.Check();
			cout << endl;
			int item_index;
			cout << "Which item do you wish to sell? ( from 0 to 3) " << endl;
			cin >> item_index;
			cout << endl;
			money=money+ item.Sell(item_index);
			cout << "Gold: " << money<< endl;
			cout << "What should we do next?" << endl;
			cin >> option;
		}
		if (option == 4) {
			//classes
			if (money >= 100) {
				cout << "Class completed" << endl;
				money = money - 100;
				cout << "Coins left: " <<money << endl;
				eliott.player_hp = eliott.player_hp + 50;
				eliott.player_damage = eliott.player_damage + 100;
				cout << "New stats: hp= "<< eliott.player_hp <<" damage: "<< eliott.player_damage << endl;
			}
			else {
				cout << "You need "<< 100-money<<" more coins to access the clases!" << endl;
			}
			cin >> option;
		}
		if (option > 5 || option <=0) {
			cout << "This option does not exist. Try again" << endl;
			cin >> option;
		}
	}
	//now that option is 5, it means we leave the town. 
	if (level >= 5) {
		can_meet_elena = true;
		can_meet_goblins = true;
	}
	if (level >= 10) {
		can_meet_orcs = true;
	}
	cout << "You must now cross the Timeless Desert. If you have level 5, you can meet Elena and also be attacked by goblins. If you are a level 10, orcs can also attack you in the desert. Survive 10 turns in the dessert and you'll be able to advance " << endl;
	cout << endl;
	bool recruited_elena = false; 
	for (int turn = 1; turn <= 10;turn++) {
		cout << "	****Turn "<<turn <<"	****	"<< endl;
		int events = 0;
		if (can_meet_elena == true && recruited_elena == false) {
			int will_meet = rand() % 100 + 1;
			if (will_meet >= 50) {
				events++;
				eliott.metAlly(ally);
				ally.GetAlly(2);
				cout << "If you have 1000 g, you can recruit this hero. You currently have "<<money<<" gold" << endl;
				if (money >= 1000) {
					cout << "You have enough money. Do you want this ally? ( 1 for yes, 2 for no)" << endl;
					cin >> option;
					if (option == 1) {
						eliott.addAlly(ally);
						money = money - 1000;
						cout << "Gold left: "<<money << endl;
						recruited_elena = true;
					}
					else {
						cout << "Elena wishes you luck with your adventure and returns to her tent." << endl;
					}
				}
				else {
					cout << "Not enough gold. Maybe next time" << endl;
				}
			}
		}
		if (can_meet_goblins == true) {
			int will_meet = rand() % 100 + 1;
			if (will_meet >= 50) {
				events++;
				cout << "Goblins attack!" << endl;
				enemy.GetEnemy(1);
				bool win = eliott.defeatsEnemy(enemy);
				if (win == true) {
					cout<<"Enemy defeated. You received 50 gold"<<endl;
					money = money + 500;
				}
				else {
					cout << "The goblins steal all your money but leave you alone" << endl;
					money = 0;
				}
			}
		}
		if (can_meet_orcs == true) {
			int will_meet = rand() % 100 + 1;
			if (will_meet >= 50) {
				events++;
				cout << "Orcs attack!" << endl;
				enemy.GetEnemy(2);
				bool win = eliott.defeatsEnemy(enemy);
				if (win == true) {
					cout << "Enemy defeated. You received 100 gold" << endl;
					money = money + 1000;
				}
				else {
					cout << "Not only the orcs take all your money, but restart your stats!" << endl;
					eliott.player_hp = 100;
					money = 0;
					eliott.player_damage = 100;
					cout << "New hp: " << eliott.player_hp << "	 new damage: " << eliott.player_damage << endl;
				}
			}
		}
		if (events == 0) {
			cout << "Nothing happened today. Phew!" << endl;
		}
		if (level == 21) {
			will_meet_general = true;
			enemy.GetEnemy(3);
			bool win = eliott.defeatsEnemy(enemy);
			if (win == true) {
				end.EndingAchieved(4);
			}
			else {
				end.EndingAchieved(3);
			}
		}
		char one;
		cout << "////End of turn////" << endl;
		cout << "Press any key to advance" << endl;
		cin >> one;
	}
	cout << "Somehow, Eliott managed to survive the desert. Now he enters Restless City" << endl;
	//player can only meet Lucas at the Restless City, even if he is lvl 15 
	if (level >= 15) {
		can_meet_lucas = true;
	}
	cout << "This place is huge! What would you like to de next?"<<endl;
	cout << "1. Take a job"<<endl;
	cout << "2. Buy items" << endl;
	cout << "3. Sell items" << endl;
	cout << "4. Visit the magic store" << endl;
	cout << "5. Advance" << endl;
	cin >> option;
	while (option != 5) {
		if (option > 5 || option <= 0) {
			cout << "This option does not exist. Try again" << endl;
			cin >> option;
		}
		if (option == 1) {
			int money_from_job = rand() % 1050 + 201;
			cout << "You received " << money_from_job << " coins" << endl;
			money = money + money_from_job;
			cout << "Now you have  " << money << " coins" << endl;
			cout << "What should we do next?" << endl;
			cin >> option;
		}
		if (option == 2) {
			//buy
			item.Check();
			cout << endl;
			int item_index;
			cout << "Which item do you wish to buy? ( from 0 to 3) " << endl;
			cin >> item_index;
			cout << endl;
			money = money - item.Buy(item_index);
			cout << "Gold: " << money << endl;
			item.Check();
			cout << "What should we do next?" << endl;
			cin >> option;
		}
		if (option == 3) {
			item.Check();
			cout << endl;
			int item_index;
			cout << "Which item do you wish to sell? ( from 0 to 3) " << endl;
			cin >> item_index;
			cout << endl;
			money = money + item.Sell(item_index);
			cout << "Gold: " << money << endl;
			item.Check();
			cout << "What should we do next?" << endl;
			cin >> option;
		}
		if (option == 4) {
			cout << "What would interest you? " << endl;
			cout << "1) Small health potion ( 100g); adds 400 hp"<< endl;
			cout << "2) Medium health potion (150g); adds 600 hp" << endl;
			cout << "3) Large health potion (300g); adds 800 hp" << endl;
			cout << "4)	Small attack potion (100g); adds 100 dam" << endl;
			cout << "5) Medium attackpotion (150g); adds 150 dam" << endl;
			cout << "6) Large attack potion (300g); adds 200 dam" << endl;
			cout << "7)	Nothing" << endl;
			int opt = 0;
			cin >> opt;
			while (opt != 7) {
				if (opt == 1) {
					if (money >= 100) {
						money = money - 100;
						eliott.player_hp = eliott.player_hp + 400;
						cout << "Now Eliott's hp is " << eliott.player_hp << " and damage " << eliott.player_damage << endl;
					}
					else {
						cout << "Not enough money!" << endl;
					}
					cout << "Anything else?" << endl;
					cin >> opt;
				}

				if (opt == 2) {
					if (money >= 150) {
						money = money - 150;
						eliott.player_hp = eliott.player_hp + 600;
						cout << "Now Eliott's hp is " << eliott.player_hp << " and damage " << eliott.player_damage << endl;
					}
					else {
						cout << "Not enough money!" << endl;
					}
					cout << "Anything else?" << endl;
					cin >> opt;
				}

				if (opt == 3) {
					if (money >= 300) {
						money = money - 300;
						eliott.player_hp = eliott.player_hp + 800;
						cout << "Now Eliott's hp is " << eliott.player_hp << " and damage " << eliott.player_damage << endl;
					}
					else {
						cout << "Not enough money!" << endl;
					}
					cout << "Anything else?" << endl;
					cin >> opt;
				}
				if (opt == 4) {
					if (money >= 100) {
						money = money - 100;
						eliott.player_damage = eliott.player_damage + 100;
						cout << "Now Eliott's hp is " << eliott.player_hp << " and damage " << eliott.player_damage << endl;
					}
					else {
						cout << "Not enough money!" << endl;
					}
					cout << "Anything else?" << endl;
					cin >> opt;
				}
				if (opt == 5) {
					if (money >= 150) {
						money = money - 150;
						eliott.player_damage = eliott.player_damage + 150;
						cout << "Now Eliott's hp is " << eliott.player_hp << " and damage " << eliott.player_damage << endl;
					}
					else {
						cout << "Not enough money!" << endl;
					}
					cout << "Anything else?" << endl;
					cin >> opt;
				}
				if (opt == 6) {
					if (money >= 300) {
						money = money - 300;
						eliott.player_damage = eliott.player_damage + 200;
						cout << "Now Eliott's hp is " << eliott.player_hp << " and damage " << eliott.player_damage << endl;
					}
					else {
						cout << "Not enough money!" << endl;
					}
					cout << "Anything else?" << endl;
					cin >> opt;
				}
			}
				cout << "Left the store" << endl;
				cin >> option;
		}
		cout << endl;
	}
//leaving the city
	ifstream luc("lucas.txt");
	if (luc.is_open()) {
		char mychar;
		while (luc) {
			mychar = luc.get();
			cout << mychar;
		}
	}
	cout << endl;
	bool good_choice = 0;
	cin >> option;
	if (option==1) {
		good_choice = 1;
		money = money - money % 10;
		cout << "You gave the beggar some money" << endl;
	}
	if (option == 2) {
		good_choice = 1;
		item.Gift(2);
		cout << "The beggar thanks you for your good intentions" << endl;
	}
	if (option == 3) {
		cout << "You couldn't be bothered with the beggar and moved forward." << endl;
	}
	if (good_choice == 1) {
		cout << "Thanks to Eliott's kindness, the begger reveals himself to be another adventurer named Lucas King. Eliott has no choice but to let him join him." << endl;
		ally.GetAlly(3);
		eliott.metAlly(ally);
		eliott.addAlly(ally);
	}
	cout << endl;
	cout << "Eliott leaves Restless City with one idea in mind: to go to the capital city to prove his worth. There is a contest every year at Adventurer's Nest and, should he win it, he'll have the chance to impress the king." << endl;
	cout << "The first task of the contest is relatively easy. All you have to do is to survive a week in the Dark Forest" << endl;
	//As Eliott comes closer to the end of his adventure, his level is less and less important. Even if he chooses to stay a lvl 5, 10 or 15, the fight with the general is inevitable 
	for (int day = 1; day <= 7; day++) {
		cout << "	****Day " << day << " in wildness	****	" << endl;
		int events = 0;
		int one;
		if (can_meet_goblins == true) {
			int will_meet = rand() % 100 + 1;
			if (will_meet >= 50) {
				events++;
				cout << "Goblins attack!" << endl;
				enemy.GetEnemy(1);
				bool win = eliott.defeatsEnemy(enemy);
				if (win == true) {
					cout << "They leave you alone for the day" << endl;
					money = money + 50;
				}
				else {
					end.EndingAchieved(3);
				}
			}
		}
		if (can_meet_orcs == true) {
			int will_meet = rand() % 100 + 1;
			if (will_meet >= 50) {
				events++;
				cout << "Orcs attack!" << endl;
				enemy.GetEnemy(2);
				bool win = eliott.defeatsEnemy(enemy);
				if (win == true) {
					cout << "Enemy defeated. They leave you alone for the day" << endl;
					money = money + 100;
				}
				else {
					end.EndingAchieved(3);
				}
			}
		}
		if (events == 0) {
			cout << "You spend a lovely day admiring the scene and listening to the birds song" << endl;
		}
		cout << "Press 1 for the next day" << endl;
		cin >> one;
	}
	cout << "////First task completed sucessfully///" << endl;
	cout << endl;
	cout << "	You are given three days off to prepare for the second task, but no one tells you what exactly you should do. So, as any adventurer after an exhausting job, you decide to eat and sleep well."<< endl;
	cout << "	Now that you're well fed and rested, the second task is just around the corner. " << endl;
	cout << endl;
	cout << "	////	Task 2	////" << endl;
	cout << "	In front of you, there are 2 identical cups of wine. One of them is poisoned, while the other is said to contain the most expensive wine in the kingdom." << endl;
	cout << "You have no way to tell which is which, but you have to pick one to complete the task successfully ( obviously not the poisoned one). Many people letf the contest after hearing the task and you're thinking if you should leave too. " << endl;
	option = 0;
	cout << "	What should you do?" << endl;
	cout << "	1. Drink from the first cup" << endl;
	cout << "	2. Drink from the second cup" << endl;
	cout << "	3. Just leave, like any sane person would" << endl;
	cin >> option;
	if (option == 1 || option == 2) {
		cout << "	In the end it was revealed none of the cups were poisoned and they were testing our courage. As for the wine... of course it was the cheapest possible." << endl;
		cout << "	////	Task completed	////	" << endl;
	}
	if (option == 3) {
		end.EndingAchieved(1);
	}
	int fin;
	cout << endl;
	ifstream f("final.txt");
	if (f.is_open()) {
		char mychar;
		while (f) {
			mychar = f.get();
			cout << mychar;
		}
	}
	cout << "Press 1 to start the battle" << endl;
	cin >> fin;
	will_meet_general = true;
	enemy.GetEnemy(3);
	bool win = eliott.defeatsEnemy(enemy);
	if (win == true) {
		end.EndingAchieved(4);
	}
	else {
		end.EndingAchieved(3);
	}
	//End of game
	return 0;
	}