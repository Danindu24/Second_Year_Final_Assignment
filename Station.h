//
// Created by Danindu Fernando on 3/31/2022.
//

#ifndef SECOND_YEAR_FINAL_ASSIGNMENT_STATION_H
#define SECOND_YEAR_FINAL_ASSIGNMENT_STATION_H
#include "CSquare.h"

using namespace std;

class Station : public CSquare{
private:
    const int cost = 200;
    const int ticketPrice = 10;

public:
    Station(int squareType, const string &squareName);

    int getCost() const override;

    int getRent() const override;
};


#endif //SECOND_YEAR_FINAL_ASSIGNMENT_STATION_H
