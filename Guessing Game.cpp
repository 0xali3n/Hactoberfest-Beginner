#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

//Guessing Game!

/*On the first line, enter range.

  On the second line, first guess.

  On the third, second guess.

  On the fourth, third guess*/

int main(){

    int x , num;

    int counter = 0;

    srand(time(0));

    cout << "Guessing game. You got 3 tries to guess the number." << endl;

    cout << "Enter range (1 to x): " << endl;

    cin >> x;

    num = rand() % x + 1;

    do {

        cout << "Guess #" << counter + 1 << ": ";

        cin >> x;

        if(x == num){

           cout << "Well done! " << x << " is the number!" << endl;

           return 0;

        }

        cout << "So sad, "<< x << " is a wrong number." << endl;

        counter ++; 

    }while (counter < 3);

    cout << "Game over, the number is: " << num << ", better luck next time!" << endl;

    return 0;

}
