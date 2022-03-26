#include <string>
#include <iostream>
#include <random>
#include <vector>
#include "Game.h"

using namespace std;


void Game::createAvailable() {
    for (const auto& i: this->commands) {
        this->available.push_back(i);
    }
    for (const auto& i: this->options) {
        this->available.push_back(i);
    }


}

string Game::choseResult() const {
//    generates random number between 0 and index of last element of options array
    random_device generator;
    uniform_int_distribution<int> distribution(0, this->options.size() - 1);
    return this->options[distribution(generator)];
}

void Game::addResult(int result) {
    if (this->score + result < 0) {
        this->score = 0;
        return;
    }
    this->score += result;
}

int Game::getResult(const string &userChose, const string &gameResults) {
    if (userChose == "rock") {
        if (gameResults == "scissors") {
            return this->results[1];
        }
        if (gameResults == "paper") {
            return this->results[3];
        }
    }
    if (userChose == "paper") {
        if (gameResults == "rock") {
            return this->results[1];
        }
        if (gameResults == "scissors") {
            return this->results[3];
        }
    }
    if (userChose == "scissors") {
        if (gameResults == "paper") {
            return this->results[1];
        }
        if (gameResults == "rock") {
            return this->results[3];
        }
    }
    return this->results[2];
}

string Game::getValidInput() {
    cout << "Input value:> ";
    string userInput;
    cin >> userInput;
//    transform user input to lowercase
    transform(userInput.begin(), userInput.end(), userInput.begin(),
                   [](unsigned char c) { return tolower(c); });
//    looks for user input in available array
    if (find(begin(this->available), end(this->available), userInput)
         != end(this->available)) {
        return userInput;
    }
    cout << "Wrong input" << endl;
    this->printAvailable();
    this->getValidInput();
    return userInput;
}

void Game::printAvailable() const {
    cout << "Available options:" << endl;
    for (auto const &i: this->options) {
        cout << "   " << i << endl;
    }
    cout << "Available commands:" << endl;
    for (auto const &i: this->commands) {
        cout << "   " << i << endl;
    }
}

void Game::printResultMessage(int result) {
    if (result == this->results[1]) {
        cout << "You have won!" << endl;
    }
    if (result == this->results[2]) {
        cout << "Draw!" << endl;
    }
    if (result == this->results[3]) {
        cout << "You have lost!" << endl;
    }
}

void Game::printGameMessage(const string &gameChose, int result) const {
    cout << "The Random has chosen: " << gameChose << endl
         << "You have got: " << result << " points" << endl
         << "Your score is: " << this->score << " points" << endl;
}

Game::Game() {
    this->createAvailable();
}

void Game::game() {
    cout << "Welcome to Rock Paper Scissors implemented on c++" << endl
         << "Here is a list of available inputs:" << endl;
    this->printAvailable();
    while (true) {
        string userInput = this->getValidInput();
        if (userInput == "!exit") {
            cout << "Goodbye!" << endl;
            break;
        }
        string gameChose = this->choseResult();
        int result = this->getResult(userInput, gameChose);
        this->printResultMessage(result);
        this->addResult(result);
        this->printGameMessage(gameChose, result);
    }
}