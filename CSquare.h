//
// Created by Danindu Fernando on 3/29/2022.
//

#ifndef SECOND_YEAR_FINAL_ASSIGNMENT_CSQUARE_H
#define SECOND_YEAR_FINAL_ASSIGNMENT_CSQUARE_H
#include <string>

using namespace std;

class CSquare {

private:

    int SquareType;
    string SquareName;

public:
    CSquare(int squareType, const string &squareName);

    int getSquareType() const;

    void setSquareType(int squareType);

    const string &getSquareName() const;

    void setSquareName(const string &squareName);

    virtual int getCost() const;
    virtual int getRent() const;
    virtual int getColorGroup() const;
   virtual const string &getOwner() const;
   virtual void setOwner(const string &owner);


};


#endif //SECOND_YEAR_FINAL_ASSIGNMENT_CSQUARE_H
