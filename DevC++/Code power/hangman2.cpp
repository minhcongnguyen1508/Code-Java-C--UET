
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <ctime>
#define MAX_BAD_GUESS (7)
using namespace std;
string chooseWord();\
string setWord(const string word, string &guessedWord);
void renderGame(string guessedWord, int badGuessCount);
char readAGuess();
string update(string &guessedWord, const string word, char guess);
bool contains(const string word, char guess);
string getHanger(int badGuessCount);
string getHanger(int badGuessCount);

int main(){
	srand(time(NULL));
	string word = chooseWord();
	int badGuessCount = 0;
	string guessedWord = "";
	char guess;
	setWord(word, guessedWord);
	renderGame(guessedWord, badGuessCount);
	while(badGuessCount < MAX_BAD_GUESS && guessedWord != word){
			guess = readAGuess();
		if(contains(word, guess)){
			update(guessedWord, word, guess);
			renderGame(guessedWord, badGuessCount);
		}
		else
		{
			badGuessCount++;
			renderGame(guessedWord, badGuessCount);
		}
	}
	if(badGuessCount < MAX_BAD_GUESS)
		cout<< "Congrats!!! You are free"<<endl;
	else
		cout<< "Game Over!!! You are hanged"<<endl;

		
	
	return 0;
}

string chooseWord(){
	string words[] = {"hello", "cat", "dog", "human" };
	int nWords = sizeof(words) / sizeof(string);  
	int randomIndex = rand() % nWords;
	return words[randomIndex]; 
}
string setWord(const string word, string &guessedWord){
	for(int i = 0; i < word.length(); i++){
		guessedWord += "-";
	}
	return guessedWord;
}
void renderGame(string guessedWord, int badGuessCount){
	cout << "Current guess = "<< guessedWord<< endl;
	cout << "You have made "<< badGuessCount<< " bad guess(es)"<<endl;
	cout << getHanger(badGuessCount);
}
char readAGuess(){
    char guess; 
    cout<< "Please enter your next guess: "<<endl;
	cin>> guess;
	return guess;
}
string update(string &guessedWord, const string word, char guess){
    for(int i = 0; i < word.length(); i++){
        if(word[i] == guess)
        guessedWord[i] = guess;
    }
    
    return guessedWord;
}
bool contains(const string word, char guess){
    for(int i = 0; i < word.length(); i++){
        if(word[i] == guess)
        return true;
    }
    return false;
}
string getHanger(int badGuessCount){
	switch(badGuessCount){
		case 0: return "";
		case 1: return 
				" | \n";
		case 2: return 
					   " | \n"
				  	   " O \n";
		case 3: return " | \n"
				   	   " O \n"
				       "/  \n";
		case 4: return 
				   " | \n"
				   " O \n"
				   "/| \n";
		case 5: return
				   " | \n"
				   " O \n"
				   "/|\\\n";
		case 6: return 
				   " | \n"
				   " O \n"
				   "/|\\\n"
				   "/\n";	
		case 7: return 
				   " | \n"
				   " O \n"
				   "/|\\\n"
				   "/ \\\n";
		
	}
}
