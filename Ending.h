#pragma once
#include<string>
#include <iostream>
using namespace std;
class Ending
{
public:
	int ending;
	Ending() {
		ending = 0;
	}
	void EndingAchieved(int ending) {
		switch (ending) {
		case 1:// Never leaving the village
			cout << " Eliott was a coward. He gives up on his dream and spends the rest of his life as a farmer" << endl;
			cout << endl;
			cout << "	****	End of journey	****" << endl;
			exit(1);
			break;
		case 2:
			// Cats eat mice 
			cout << " Eliott was turned into a mouse by the Evil Witch and fed to her cat" << endl;
			cout << endl;
			cout << "	****	End of journey	****" << endl;
			exit(1);
			break;
		case 3:
			//Dead in battle 
			cout << " Despite his effort, the enemy was too strong for Eliott to handle" << endl;
			cout << endl;
			cout << "	****	End of journey	****" << endl;
			exit(1);
			break;
		case 4:
			//Good ending
			cout << " Eliott is now the greatest hero of all times!" << endl;
			cout << endl;
			cout << "	****	End of journey	****" << endl;
			exit(-1);
			break;
		case 5: // The berries were not edible 
			cout << "  You died because of poisoning " << endl;
			cout << endl;
			cout << "	****	End of journey	****" << endl;
			exit(-1);
		case 6:// The pray not to starve ending
			cout << " You starved to death! " << endl;
			cout << endl;
			cout << "	****	End of journey	****" << endl;
			exit(-1);

		}
	}
};

