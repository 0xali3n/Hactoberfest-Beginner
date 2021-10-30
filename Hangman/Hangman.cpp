//Import libraries that we are going to use
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

bool win = false;

//Define functions
string RandomWord(int);
int RandomNumber(int);
void Design(int);
int PrintWord(string word, string letter);

int main() {
	int live = 7;
	int choice;
	int num;
	string letter;
	string word;
	string guessedLetters = "";

	cout << "choose your level: \n1)Easy\n2)Medium\n3)Hard\n-->";
	cin >> choice;

	//Validate input
	while (choice < 1 || choice>3) {
		system("cls");
		cout << "You have enered a wrong number, renter your level..\n";
		cout << "choose your level: \n1)Easy\n2)Medium\n3)Hard\n-->";
		cin >> choice;
	}

	word = RandomWord(choice);
	system("cls"); // Clear the screen

	bool help = false;
	
	while (live > 0)
	{
		win = true;
		Design(live);
		PrintWord(word, guessedLetters);
		if (help)
		{
			win = false;
			help = false;
		}

		if (win == true)
			break;
		cout << "\n\nIf you want to know the first letter write 'help' [Your lives will decrease!]" << endl;
		cout << "\n\nLetters guesses: " << guessedLetters << endl;
		cout << "\n\nEnter a letter: ";
		cin >> letter;

		int b = 0;

		while (letter[b] != '\0')
			b++;

		//To catch those cheatty persons who write more than a letter
		if (b > 2)
		{
			if (letter == "help") // If you need a help to know the first letter
			{
				help = true;
				live--;
				cout << "-->\"" << word[0] << "\"<--" << endl;
				letter = word[0];
				system("pause");
			}
			else
			{
				system("cls");
				for (;;) //Infinity loop (like: while(true){} ..)
				{
					cout << "You are CHEATING!" << endl;
				}
			}
		}

		guessedLetters += letter[0];

		if (word.find(letter) != -1 || help)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			live--;
		}
	}

	if (live == 0) //If we have finished our lives
	{
		cout << "\n\n\n\t\t\t >>>You Lose!<<<\n\n";
		cout << "The word was: " << word << endl;
	}
	if (live > 0) //If we complete the word correctly
	{
		cout << "\n\n\n\t\t\t >>>You WIN!<<<\n\n";
		cout << "The word was: " << word << endl;
	}
	return 0;
}

// Get a random word from the wordlist depending on the level chosen
string RandomWord(int choice) {
	int random_number = RandomNumber(choice);
	int counter = 1;
	string line;
	string word;
	ifstream file("wordlist.txt");
	while (getline(file, line))
	{
		if (random_number == counter)
		{
			word = line;
			break;
		}
		counter++;
	}
	return word;
}


//Get a random number to get the word, it depends on the chosen level
int RandomNumber(int choice) {
	//I have already prepared a list of words
	/*
		There are 669 words
		There are 158 words with number of letters between 3 and 5
		There are 288 words with number of letters between 6 and 7
		There are 134 words with number of letters more than 9
	*/
	srand(time(NULL));
	int random;
	if (choice == 1)
		random = (rand() % (158 + 1 - 1)) + 1;

	if (choice == 2)
		random = (rand() % (456 + 1 - 159)) + 159;

	if (choice == 3)
		random = (rand() % (669 + 1 - 457)) + 457;

	return random;
}


//Design the hangman depending on lives
void Design(int live){
	switch (live)
	{
	case 0:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|       / \\" << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;

	case 1:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|         \\" << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 2:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 3:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 4:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|        |\\" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 5:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|        |  " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 6:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 7:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	default:
		break;
	}
}

//Print chosen right letters or '-'
int PrintWord(string word, string letter){
	for (int x = 0; x < word.size(); x++)
	{
		if (letter.find(word.at(x)) != -1)
			cout << word.at(x) << " ";
		else
		{
			cout << "_ ";
			win = false;
		}
	}
	return 0;
}