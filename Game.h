//
// Created by Sergey Kokoulin on 11.03.2022.
//
#include <map>
#include <array>
#include <string>
#include <vector>
#ifndef ROCKPAPERSCISSORS_GAME_H
#define ROCKPAPERSCISSORS_GAME_H

class Game {

private:

    int score = 0;
    std::array<std::string,3> const options = {"rock", "paper", "scissors"};
    std::array<std::string, 1> const commands = {"!exit"};

    std::vector<std::string> available;

    std::map<int, int> results{
            {1, 150},
            {2, 50},
            {3, -100}
    };

    std::string getValidInput();

    std::string choseResult() const;

    void printAvailable() const;

    void createAvailable();

    void addResult(int result);

    void printGameMessage(std::string const &gameChose, int result) const;

    void printResultMessage(int result);

    int getResult(const std::string &userChose, const std::string &gameResults);

public:

    Game();

    void game();

};

#endif //ROCKPAPERSCISSORS_GAME_H
