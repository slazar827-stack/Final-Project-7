#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

class ProduceItem {

public:
	ProduceItem(const std::string& name);
	ProduceItem(const std::string& name, int quantity);

	std::string getName() const;

	int getQuantity() const;

private:
	std::string name;
	int quantity;
};

string timeStamp();

string outputFileName();

string repeatCharacter(int, char);


using GroceryItemMap = std::map<std::string, std::unique_ptr<ProduceItem>>;

void optionOne(GroceryItemMap& groceryItems);

void optionTwo(GroceryItemMap& groceryItems);

void optionThree(GroceryItemMap& groceryItems);

void optionFour(GroceryItemMap& groceryItems, int& programDriver);

void printMenu();

void writeOutput(GroceryItemMap& groceryItems);

void readToMap(GroceryItemMap& groceryItems);

int readUserInput(GroceryItemMap& groceryItems);

void printWithInt(GroceryItemMap& groceryItems);

void printWithHistogram(GroceryItemMap& groceryItems);
