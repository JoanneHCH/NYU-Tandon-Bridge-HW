#include <iostream>
#include <cstdlib> // C standard library -> contains rand(), srand()
#include <ctime> // C time library -> time()

using namespace std;

int main () {
    int random, init, guess;
    const int given_times = 5;

    srand(time(0)); // seed of random = time now
    random = (rand() % 100) + 1;
    cout << "I thought of a number between 1 and 100! Try to guess it.\n";

    int lower = 1, upper = 100;
    for (int times = given_times; (times > 0) && (guess != random); --times){

        cout << "Range: [" << lower << "," << upper << "], Number of guesses left: " << times << endl;
        cout << "Your guess: ";
        cin >> guess;

        if (guess >= random)
            upper = guess;
        else if (guess <= random)
            lower = guess;

        if (guess == random) {
            cout << "Congrats! You guessed my number in " << (given_times - times + 1) << " guesses.\n";
        } else if (times == 1) {
            cout << "Out of guesses! My number is " << random << endl;
        } else if (guess < random) {
            cout << "Wrong! My number is bigger.\n";
        } else if (guess > random) {
            cout << "Wrong! My number is smaller.\n";
        }

        // if (guess < random && times > 1)
        //     cout << "Wrong! My number is bigger.\n";
        // else if (guess > random && times > 1)
        //     cout << "Wrong! My number is smaller.\n";
        // else if (guess == random && times > 1)
        //     cout << "Congrats! You guessed my number in " << (given_times - times + 1) << " guesses.\n";
        
        // if (times == 1 && guess != random)
        //     cout << "Out of guesses! My number is " << random << endl;
    }
    return 0;
}