#pragma once
#include <iostream>
#include<string>
using namespace std;

class Items {
public:
    int item[4]; // we have 4 types of items and the quantity of each item
    int item_price[4]; // different prices for different items
    Items() {
        for (int i = 0; i < 4; i++) {
            item[i] = 0;
            item_price[i] = 0;
        }
    }
    void Check() { // function to keep track of our items
        cout << "You have " << item[0] << " berries" << endl;
        cout << "You have " << item[1] << " firewood" << endl;
        cout << "You have " << item[2] << " fish" << endl;
        cout << "You have " << item[3] << " animal fur" << endl;
    }
    void SetPrice() { // function to set the prices of the items ( used in the store )
        item_price[0] = 5;
        item_price[1] = 20;
        item_price[2] = 25;
        item_price[3] = 50;
    }
    void Add(int index) { // function to add found items 
        item[index]++;
        cout << " Item added in inventory" << endl;
    }
    int Buy(int index) {
        item[index]++;
        cout << " Item bought for "<<item_price[index] << endl;
        return item_price[index];
    }
    int Sell(int index) {
        if (item[index] > 0) {
            item[index]--;
            cout << "Sold for : "<< item_price[index] << endl;
            return item_price[index];
        }
        else {
            cout << "Nothing to sell" << endl;
            return 0;
        }
    }
    void Gift(int index) {
        if (item[index] > 0) {
            item[index]--;
            cout << "Gift received, items remaining: " << item[index] << endl;
        }
        else {
            cout << "Not enough items to give!!! Try some money instead" << endl;
        }
    }
};

