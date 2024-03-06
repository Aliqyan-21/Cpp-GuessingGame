#include <iostream>
#include <random>

auto easy = []() {
  std::random_device rd;
  std::uniform_int_distribution<int> gen(1, 100);

  int randNum = gen(rd);
  int userGuess;
  int count = 1;

  std::cout << "Guess the number I am thinking of between 1 and 100..."
            << std::endl;
  std::cout << "Guess: ";
  std::cin >> userGuess;

  while (true) {
    if (userGuess > randNum) {
      count++;

      std::cout << "I am thinking of a smaller number than that..."
                << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else if (userGuess < randNum) {
      count++;

      std::cout << "I am thinking of a larger number than that..." << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else {
      std::cout << "Yes, you guessd it right " << userGuess
                << " is the number I was thinking of!" << std::endl;
      std::cout << "Total number of tries you took: " << count << std::endl;
      break;
    }
  }
};

auto medium = []() {
  std::random_device rd;
  std::uniform_int_distribution<int> gen(1, 200);

  int randNum = gen(rd);
  int userGuess;
  int count = 0;

  std::cout << "Guess the number I am thinking of between 1 and 200..."
            << std::endl;
  std::cout << "Guess: ";
  std::cin >> userGuess;

  while (true) {
    if (userGuess > randNum) {
      count++;

      std::cout << "I am thinking of a smaller number than that..."
                << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else if (userGuess < randNum) {
      count++;

      std::cout << "I am thinking of a larger number than that..." << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else {
      std::cout << "Yes, you guessd it right " << userGuess
                << " is the number I was thinking of!" << std::endl;
      std::cout << "Total number of tries you took: " << count << std::endl;
      break;
    }
  }
};

auto hard = []() {
  std::random_device rd;
  std::uniform_int_distribution<int> gen(1, 300);

  int randNum = gen(rd);
  int userGuess;
  int count = 0;

  std::cout << "Guess the number I am thinking of between 1 and 300..."
            << std::endl;
  std::cout << "Guess: ";
  std::cin >> userGuess;

  while (true) {
    if (userGuess > randNum) {
      count++;

      std::cout << "I am thinking of a smaller number than that..."
                << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else if (userGuess < randNum) {
      count++;

      std::cout << "I am thinking of a larger number than that..." << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else {
      std::cout << "Yes, you guessd it right " << userGuess
                << " is the number I was thinking of!" << std::endl;
      std::cout << "Total number of tries you took: " << count << std::endl;
      break;
    }
  }
};

void GameLoop(std::string &mode) {
  char playagain;
  while (true) {
    if (mode == "easy") {
      easy();
    } else if (mode == "medium") {
      medium();
    } else if (mode == "hard") {
      hard();
    } else {
      std::cout << "Not a valid mode input, modes = 'easy, medium, hard'"
                << std::endl;
    }
    while (true) {
      std::cout << "Do you want to play again[y/n]: ";
      std::cin >> playagain;
      if (playagain == 'y' || playagain == 'n')
        break;
    }
    if (playagain == 'n')
      break;
    else {
      while (true) {
        std::cout << "Which difficulty[easy, medium, hard]: ";
        std::cin >> mode;
        if (mode == "easy" || mode == "medium" || mode == "hard") {
          break;
        }
      }
      continue;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "Usage: ./main mode" << std::endl;
    std::cout << "Mode = easy, medium, hard" << std::endl;
    exit(1);
  }

  std::string mode = argv[1];

  GameLoop(mode);

  return 0;
}
