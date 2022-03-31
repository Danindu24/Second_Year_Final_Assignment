//
// Created by Danindu Fernando on 3/31/2022.
//

#ifndef SECOND_YEAR_FINAL_ASSIGNMENT_PLAYER_H
#define SECOND_YEAR_FINAL_ASSIGNMENT_PLAYER_H

#include <string>

using namespace std;
class Player {
private:
    string PlayerName;
    int PLayerMoney;
    int PlayerPosition;

public:
    Player(const string &playerName, int pLayerMoney, int playerPosition);

    const string &getPlayerName() const;

    void setPlayerName(const string &playerName);

    int getPLayerMoney() const;

    void setPLayerMoney(int pLayerMoney);

    int getPlayerPosition() const;

    void setPlayerPosition(int playerPosition);
};


#endif //SECOND_YEAR_FINAL_ASSIGNMENT_PLAYER_H
