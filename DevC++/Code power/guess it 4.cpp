//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <cstdlib>
# include <ctime>
using namespace std;
#define failMax 20
int getPlayerGuess(){
    int number;
    cin>> number;
    cout<< "Enter your guess: ";
    return number;
}
int generateRandomNumber(){
    
    return rand()%100 + 1;
}
void printAnswer(int guestNumber, int hostNumber){
    if(guestNumber < hostNumber)
        cout<< "Your number is too small."<<endl;
    else if(guestNumber > hostNumber)
        cout<< "Your number is too big."<<endl;
    else cout<< "Congratulations !!!";
}
int main(){
	srand(time(NULL));
	int hostNumber = generateRandomNumber();
	int guestNumber;
	int fail = 0;
	while(fail <= failMax){
		guestNumber = getPlayerGuess();
		printAnswer(guestNumber, hostNumber);
		if(guestNumber == hostNumber)
			break;
	}
	return 0;
}

