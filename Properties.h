//
// Created by Danindu Fernando on 3/29/2022.
//

#ifndef SECOND_YEAR_FINAL_ASSIGNMENT_PROPERTIES_H
#define SECOND_YEAR_FINAL_ASSIGNMENT_PROPERTIES_H
#include <string>
#include "CSquare.h"

using namespace std;

class Properties : public CSquare{

private:
    int Cost;
    int Rent;
    int ColorGroup;
    string Owner;
public:
    Properties(int squareType, const string &squareName);

    Properties(int squareType, const string &squareName, int cost, int rent, int colorGroup);

    int getCost() const;

    void setCost(int cost);

    int getRent() const;

    void setRent(int rent);

    int getColorGroup() const;

    void setColorGroup(int colorGroup);

    const string &getOwner() const;

    void setOwner(const string &owner);

};


#endif //SECOND_YEAR_FINAL_ASSIGNMENT_PROPERTIES_H
