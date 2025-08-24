#include "Header.h"

// Constructor that initializes a ProduceItem with a name and sets default quantity to 1.
ProduceItem::ProduceItem(const std::string& name)
	: name(name), quantity(1) {
}

// Constructor that initializes a ProduceItem with both name and a specific quantity.
ProduceItem::ProduceItem(const std::string& name, int quantity)
	: name(name), quantity(quantity) {
}

//Getter method for the items name.
std::string ProduceItem::getName() const {
	return name;
}
//Getter method for items quanity.
int ProduceItem::getQuantity() const {
	return quantity;
}

// Generates a timestamp string formatted as "_MM_DD_YYYY_HH_MM_SS".
string timeStamp() {

	// Get the current time in seconds using nullptr
	time_t currentTime = time(nullptr);

	// declare and zero-initialize a tm structure to hold local computer time
	tm nowTimeStructure = {};

	localtime_s(&nowTimeStructure, &currentTime);

	// allocate a buffer to hold timestamp string
	char buffer[32];

	// set the month-day-year & hours:minutes:seconds
	strftime(buffer, sizeof(buffer), "_%m_%d_%Y_%H_%M_%S", &nowTimeStructure);

	// return the string
	return std::string(buffer);
}

string outputFileName()
{
	// Define base name file
	string fileName = "frequency";

	// Define file extension
	string fileType = ".dat";
	
	// Declare constants for base name and extension used in final output
	const std::string baseName = "frequency";
	const std::string extension = ".dat";
	
	// returns base name and time stamp with .dat
	return baseName + timeStamp() + extension;;
}

string repeatCharacter(int length, char characterToRepeat) {
	// create and return a string consisting of length repetitions of characters
	return string(length, characterToRepeat);
}

void optionOne(GroceryItemMap& groceryItems) {
	
	// prompt user to enter an item name to search for
	string searchItem;
	cout << "\nPlease enter an item to search for: ";
	getline(cin >> ws, searchItem);
	
	// converts all characters to lowercase for normalization
	for (char& ch : searchItem) ch = tolower(ch);
	
	// capitalize the first character to match stored item format
	if (!searchItem.empty()) searchItem[0] = toupper(searchItem[0]);
	
	// attempt to find the item
	auto groceryIterator = groceryItems.find(searchItem);
	
	// clear the console screen for a clean output
	system("CLS");
	
	// print a border
	cout << repeatCharacter(51, '*') << "\n\n";
	
	// if item is found, display item and quantity
	if (groceryIterator != groceryItems.end()) {
		cout << " " << groceryIterator->first << ": "
			<< groceryIterator->second->getQuantity() << "\n";
	}
	
	// if item is not found display error message
	else {
		cout << searchItem << " does not exist in the system, try again.\n";
	}
}



void optionTwo(GroceryItemMap& groceryItems)
{
	// clear the console for clean screen display
	system("CLS");
	
	// call a function to print all grocey items with their quanitites
	printWithInt(groceryItems);
}

void optionThree(GroceryItemMap& groceryItems)
{
	// clear the console for clean screen display
	system("CLS");
	
	// print item and histograms of quanitity
	printWithHistogram(groceryItems);
}

// close program with input 4 selected
void optionFour(GroceryItemMap& groceryItems, int& programDriver) {
	groceryItems.clear();
	programDriver = 4;
	cout << "\nTally Completed!\n";
}

void writeOutput(GroceryItemMap& groceryItems)
{
	// creat an output file stream object
	ofstream outFS;
	
	// generate a output file name using timestamp
	string outputFile = outputFileName();
	
	// Inform user file is being opened
	cout << " Opening file " << outputFileName << endl;
	
	// attempt to open the file for writting
	outFS.open(outputFile);
	
	//check to see if the file fails to open
	if (!outFS.is_open()) {
		cout << " Could not open file " << outputFileName << endl;
		system("pause");
		exit(-1);

	}
	
	// confirm file is being written
	cout << " Writing File: " << outputFileName << endl;
	
	// write each grocery item and its quantities to file
	for (const auto& pair : groceryItems) {
		outFS << pair.first << " " << pair.second->getQuantity() << endl;
	}
	
	// notify the file is closing and close file
	cout << " Closing: " << outputFileName << endl << endl;
	outFS.close();
	
	// clear screen for output
	system("CLS");
}

void readToMap(GroceryItemMap& groceryItems)
{
	// create an input file stream object
	ifstream inFS;
	
	// Define the name of the input file to read from
	std::string name;
	string inputFileName = "ProduceList.txt";
	
	// notify user of the file being opened
	cout << " Opening file " << inputFileName << endl;
	
	// open file
	inFS.open(inputFileName);
	
	// check if the file failed to open and notify user
	if (!inFS.is_open()) {
		cout << " Could not open file " << inputFileName << endl;
		system("pause");
		exit(-1);

	}
	// writing file is being read
	cout << " Writing File: " << inputFileName << endl;

	while (!inFS.eof()) {
		while (inFS >> name) {
			// to find GroceryItem in map
			auto groceryIterator = groceryItems.find(name);

			if (groceryIterator != groceryItems.end()) {
				// retrieve the quantity of current GroceryItem in iteration
				int quantity = groceryIterator->second->getQuantity();

				quantity += 1;
		
				// create unique GroceryItem pointer to store in map value
				auto newGroceryItem = std::make_unique<ProduceItem>(name, quantity);
				
				// erase existing GroceryItem from map
				groceryItems.erase(groceryIterator);
				
				// insert new GroceryItem into map using the name as the key, and the object as the value
				groceryItems.insert({ name, std::move(newGroceryItem) }); 

			}
			else {
				// create unique GroceryItem pointer to store in map value
				auto newGroceryItem = std::make_unique<ProduceItem>(name);
				
				// insert new GroceryItem into map using the name as the key, and the object as the value
				groceryItems.insert({ name, std::move(newGroceryItem) });
			}
		}
	}
	cout << "Closing " << inputFileName << endl << endl;
	inFS.close();
	system("CLS");
}

int readUserInput(GroceryItemMap& groceryItems) {
	// Initialize control variable for main loop
	int programDriver = 0;
	
	// continue looping until user input = 4
	while (programDriver != 4) {
		// display the main menu to user
		printMenu();
		
		// prompt user for menu selection
		int choice;
		cout << " Enter your choice: ";
		cin >> choice;
		
		// handle user input based on selected option
		switch (choice) {
		case 1:
			// search for a grocery item
			optionOne(groceryItems);
			break;
		
		case 2:
			// display all grocery items and quantities
			optionTwo(groceryItems);
			break;
		
		case 3:
			// write grocery items to output file
			optionThree(groceryItems);
			break;
		
		case 4:
			// exit program and update variable
			optionFour(groceryItems, programDriver);
			break;
		
		default:
			// handle invalid inputs
			cout << "\n Incorrect input. Please try again.\n";
			system("pause");
			// clear input stream and discard invalid input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}

	return 0;
}

void printMenu() {
	// define the width of the border
	int length = 51;

	// generate a line of * for visual separation
	string asterisks = repeatCharacter(length, '*');

	// define menu options as strings
	string optionOne = " 1 - Search Item Purchased and Display Quantity";
	string optionTwo = " 2 - Daily Purchases with Quantity";
	string optionThree = " 3 - Daily Purchases with Histogram Quantity";
	string optionFour = " 4 - Exit Program";

	// display the menu with decorative borders
	cout << endl << asterisks << endl;
	cout << optionOne << endl;
	cout << optionTwo << endl;
	cout << optionThree << endl;
	cout << optionFour << endl;
	cout << asterisks << endl << endl;
}

void printWithInt(GroceryItemMap& groceryItems)
{
	// print a decorative border
	cout << repeatCharacter(51, '*') << endl;

	// iterate through each grocery item in the map
	for (const auto& pair : groceryItems) {
		const std::string& name = pair.first;
		const int& quantity = pair.second->getQuantity();
		// display the item name and quantity
		std::cout << " " << name << ": " << quantity << std::endl;
		continue;
	}
}

void printWithHistogram(GroceryItemMap& groceryItems)
{
	// print a decorative border
	cout << repeatCharacter(51, '*') << endl;

	// iterate through each grocery item in the map
	for (const auto& pair : groceryItems) {
		const std::string& name = pair.first;
		const int& quantity = pair.second->getQuantity();
		// generate histogram using $
		string asterisks;
		int i;

		for (i = 0; i < quantity; ++i) {
			asterisks += repeatCharacter(1, '$');
		}
		// display the histogram and item name
		cout << " " << name << ": " << asterisks << std::endl;
		continue;
	}
}

// run main program
int main()
{
	GroceryItemMap groceryItems;

	readToMap(groceryItems);

	writeOutput(groceryItems);

	readUserInput(groceryItems);

	return 0;
}
