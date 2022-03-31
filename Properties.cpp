//
// Created by Danindu Fernando on 3/29/2022.
//

#include "Properties.h"


Properties::Properties(int squareType, const string &squareName) : CSquare(squareType, squareName) {

}

Properties::Properties(int squareType, const string &squareName, int cost, int rent, int colorGroup) : CSquare(
        squareType, squareName), Cost(cost), Rent(rent), ColorGroup(colorGroup) {

}

int Properties::getCost() const {
    return Cost;
}

void Properties::setCost(int cost) {
    Cost = cost;
}

int Properties::getRent() const {
    return Rent;
}

void Properties::setRent(int rent) {
    Rent = rent;
}

int Properties::getColorGroup() const {
    return ColorGroup;
}

void Properties::setColorGroup(int colorGroup) {
    ColorGroup = colorGroup;
}

const string &Properties::getOwner() const {
    return Owner;
}

void Properties::setOwner(const string &owner) {
    Owner = owner;
}
