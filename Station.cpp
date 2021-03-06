//
// Created by Danindu Fernando on 3/31/2022.
//

#include "Station.h"

int Station::getCost() const {
    return cost;
}

int Station::getRent() const {
    return ticketPrice;
}

Station::Station(int squareType, const string &squareName) : CSquare(squareType, squareName) {

}

const string &Station::getOwner() const {
    return owner;
}

void Station::setOwner(const string &owner) {
    this->owner = owner;
}
