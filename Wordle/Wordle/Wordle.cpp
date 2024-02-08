#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	srand((unsigned)time(0));
	ifstream fileName("CorrectWords.txt");
	string correctWords[2315];
	for (size_t i = 0; i < 2315; i++)
		fileName >> correctWords[i];
	ifstream fileName2("WordleWords.txt");
	string wordleWords[12972];
	for (size_t i = 0; i < 12972; i++)
		fileName2 >> wordleWords[i];
	string word = correctWords[rand() % 2315 + 1];
	string guess;
	cout << word << endl;
	do
	{
		bool isValid = false;
		do
		{
			cout << "What is your Guess?" << endl;
			isValid = false;
			cin >> guess;
			for (size_t i = 0; i < 12972; i++)
				if (wordleWords[i] == guess)
					isValid = true;
		} while (!isValid);
		int colour[5]; //0=grey, 1== orange, 2==green
		for (size_t i = 0; i < 5; i++)
			colour[i] = 0;
		for (size_t i = 0; i < 5; i++)
			if (word[i] == guess[i])
				colour[i] = 2;
			else for (size_t j = 0; j < 5; j++)
				if (word[i] == guess[j])
				{
					colour[j] = 1;
					break;
				}
		for (size_t i = 0; i < 5; i++)
			cout << colour[i] << " ";
		cout << endl;
	} while (guess != word);
}