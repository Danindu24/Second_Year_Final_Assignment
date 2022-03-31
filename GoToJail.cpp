//
// Created by Danindu Fernando on 3/31/2022.
//

#include "GoToJail.h"

int GoToJail::getCost() const {
    return cost;
}

GoToJail::GoToJail(int squareType, const string &squareName) : CSquare(squareType, squareName) {

}
