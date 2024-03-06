#include <iostream>
#include <random>
using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    cout << "Usage: ./main mode" << endl;
    cout << "Mode = easy, medium, hard" << endl;
    exit(1);
  }

  string mode = argv[1];

  if (mode == "easy") {
    random_device rd;
    uniform_int_distribution<int> gen(1, 100);

    int randNum = gen(rd);
    int userGuess;
    int count = 0;

    cout << "Guess the number I am thinking of between 1 and 100..." << endl;
    cout << "Guess: ";
    cin >> userGuess;

    while (true) {
      if (userGuess > randNum) {
        count++;

        cout << "I am thinking of a smaller number than that..." << endl;
        cout << "Try again: ";
        cin >> userGuess;
      } else if (userGuess < randNum) {
        count++;

        cout << "I am thinking of a larger number than that..." << endl;
        cout << "Try again: ";
        cin >> userGuess;
      } else {
        cout << "Yes, you guessd it right " << userGuess
             << " is the number I was thinking of!" << endl;
        cout << "Total number of tries you took: " << count << endl;
        cout << "Thanks for playing Good Bye..." << endl;
        break;
      }
    }
  } else if (mode == "medium") {
    random_device rd;
    uniform_int_distribution<int> gen(1, 200);

    int randNum = gen(rd);
    int userGuess;
    int count = 0;

    cout << "Guess the number I am thinking of between 1 and 200..." << endl;
    cout << "Guess: ";
    cin >> userGuess;

    while (true) {
      if (userGuess > randNum) {
        count++;

        cout << "I am thinking of a smaller number than that..." << endl;
        cout << "Try again: ";
        cin >> userGuess;
      } else if (userGuess < randNum) {
        count++;

        cout << "I am thinking of a larger number than that..." << endl;
        cout << "Try again: ";
        cin >> userGuess;
      } else {
        cout << "Yes, you guessd it right " << userGuess
             << " is the number I was thinking of!" << endl;
        cout << "Total number of tries you took: " << count << endl;
        cout << "Thanks for playing Good Bye..." << endl;
        break;
      }
    }
  } else if (mode == "hard") {
    random_device rd;
    uniform_int_distribution<int> gen(1, 300);

    int randNum = gen(rd);
    int userGuess;
    int count = 0;

    cout << "Guess the number I am thinking of between 1 and 300..." << endl;
    cout << "Guess: ";
    cin >> userGuess;

    while (true) {
      if (userGuess > randNum) {
        count++;

        cout << "I am thinking of a smaller number than that..." << endl;
        cout << "Try again: ";
        cin >> userGuess;
      } else if (userGuess < randNum) {
        count++;

        cout << "I am thinking of a larger number than that..." << endl;
        cout << "Try again: ";
        cin >> userGuess;
      } else {
        cout << "Yes, you guessd it right " << userGuess
             << " is the number I was thinking of!" << endl;
        cout << "Total number of tries you took: " << count << endl;
        cout << "Thanks for playing Good Bye..." << endl;
        break;
      }
    }
  } else {
    cout << "Not a valid mode input, modes = 'easy, medium, hard'" << endl;
  }

  return 0;
}
