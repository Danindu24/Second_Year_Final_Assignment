//
// Created by Danindu Fernando on 3/31/2022.
//

#ifndef SECOND_YEAR_FINAL_ASSIGNMENT_GOTOJAIL_H
#define SECOND_YEAR_FINAL_ASSIGNMENT_GOTOJAIL_H

#include "CSquare.h"

using namespace std;

class GoToJail : public CSquare{
private:
    const int cost = 50;

public:
    GoToJail(int squareType, const string &squareName);

    int getCost() const override;

};


#endif //SECOND_YEAR_FINAL_ASSIGNMENT_GOTOJAIL_H
