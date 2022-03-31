//
// Created by Danindu Fernando on 3/29/2022.
//

#include "CSquare.h"

CSquare::CSquare(int squareType, const string &squareName) : SquareType(squareType), SquareName(squareName) {

}

int CSquare::getSquareType() const {
    return SquareType;
}

void CSquare::setSquareType(int squareType) {
    SquareType = squareType;
}

const string &CSquare::getSquareName() const {
    return SquareName;
}

void CSquare::setSquareName(const string &squareName) {
    SquareName = squareName;
}

int CSquare::getCost() const {
    return 0;
}

int CSquare::getRent() const {
    return 0;
}

int CSquare::getColorGroup() const {
    return 0;
}

const string &CSquare::getOwner() const {
    return {};
}

void CSquare::setOwner(const string &owner) {

}
