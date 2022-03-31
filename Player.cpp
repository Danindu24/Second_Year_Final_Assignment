//
// Created by Danindu Fernando on 3/31/2022.
//

#include "Player.h"

Player::Player(const string &playerName, int pLayerMoney, int playerPosition) : PlayerName(playerName),
                                                                                PLayerMoney(pLayerMoney),
                                                                                PlayerPosition(playerPosition) {}

const string &Player::getPlayerName() const {
    return PlayerName;
}

void Player::setPlayerName(const string &playerName) {
    PlayerName = playerName;
}

int Player::getPLayerMoney() const {
    return PLayerMoney;
}

void Player::setPLayerMoney(int pLayerMoney) {
    PLayerMoney = pLayerMoney;
}

int Player::getPlayerPosition() const {
    return PlayerPosition;
}

void Player::setPlayerPosition(int playerPosition) {
    PlayerPosition = playerPosition;
}
