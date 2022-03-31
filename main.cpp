#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#include "CSquare.h"
#include "Properties.h"
#include "Player.h"
#include "Station.h"
#include "Jail.h"
#include "GoToJail.h"
#include "FreeParking.h"

using namespace std;

typedef vector<CSquare *> squareVector;

string line [26];
int i = 0;

string strings[6];

void split(string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= (str.length()))
    {
        if (str[i] == seperator || i == (str.length()))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

vector<string> getvalues(string text)
{
    vector <string> temp;

    split(text, ' ');
    if (strings[0] == "1")
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == 1)
            {
                temp.push_back(strings[i] +" "+ strings[i + 1]);

                i = 2;
            }
            else
            {
                temp.push_back(strings[i]);
            }

        }
    } else if (strings[0] == "3" || strings[0] == "8") {
        for (int i = 0; i < 3; i++)
        {
            if (i == 1)
            {
                temp.push_back(strings[i] +" "+ strings[i + 1]);

                i = 2;
            }
            else
            {
                temp.push_back(strings[i]);
            }

        }
    } else if (strings[0] == "7") {
        for (int i = 0; i < 4; i++)
        {
            if (i == 1)
            {
                temp.push_back(strings[i] +" "+ strings[i + 1] + " " + strings[i + 2]);

                i = 3;
            }
            else
            {
                temp.push_back(strings[i]);
            }

        }
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            temp.push_back(strings[i]);

        }
    }
    return temp;
}

int Random()
{
    return static_cast<int>( static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1 );
}

int main()
{
    ifstream myfile;
    myfile.open("monopoly.txt");
    if (myfile.is_open()) {

        while (!myfile.eof()) {
            getline(myfile, line[i], '\n');
            i++;
        }
        myfile.close();

    };
    squareVector squares;
    for (int i = 0; i < 26; i++)
    {
        if (line[i][0] == '1')
        {
            //cout << getvalues(line[i])[0] + "-" + getvalues(line[i])[1] + "-" + getvalues(line[i])[2] + "-" + getvalues(line[i])[3] + "-" + getvalues(line[i])[4] << endl;
            squares.push_back(new Properties(stoi(getvalues(line[i])[0]),getvalues(line[i])[1], stoi(getvalues(line[i])[2]),
                                             stoi(getvalues(line[i])[3]), stoi(getvalues(line[i])[4])));
            //cout << "property done!!" << endl;
        } else if (line[i][0] == '3') {
            squares.push_back(new Station(stoi(getvalues(line[i])[0]), getvalues(line[i])[1]));

        } else if (line[i][0] == '6') {
            squares.push_back(new Jail(stoi(getvalues(line[i])[0]), getvalues(line[i])[1]));

        } else if (line[i][0] == '7') {
            squares.push_back(new GoToJail(stoi(getvalues(line[i])[0]), getvalues(line[i])[1]));

        }else if (line[i][0] == '8') {
            squares.push_back(new FreeParking(stoi(getvalues(line[i])[0]), getvalues(line[i])[1]));

        }
        else {
            squares.push_back(new CSquare(stoi(getvalues(line[i])[0]), getvalues(line[i])[1]));
            //cout << "square done!!" << endl;
        }

    }

    //Player * playerone = new Player("dog",1500,1);
    //Player * playertwo = new Player("cat", 1500,1);

    unique_ptr<Player> playerone(make_unique<Player>("dog",1500,1));
    unique_ptr<Player> playertwo(make_unique<Player>("cat", 1500,1));


    int randomnumber;
    bool player1 = true;
    bool player2 = false;
    const char pound = 156;
    srand(5);
    for (int j = 0; j < 20; ++j)
    {
        cout << "====== Round " + to_string( j+1) + " =======" << endl;
        for (int k = 0; k < 2; ++k) {
            if(player1)
            {
                cout << "Chance of Player 01 " << endl;
                randomnumber = Random();
                //cout << randomnumber << endl;
                if (playerone->getPlayerPosition()+randomnumber>26)
                {
                    playerone->setPlayerPosition(playerone->getPlayerPosition() + randomnumber-26);
                    playerone->setPLayerMoney(playerone->getPLayerMoney()+200);

                    cout<<playerone->getPlayerName()<<" rolls "<<randomnumber<<endl;
                    cout<<playerone->getPlayerName()<<" lands on "<<squares[playerone->getPlayerPosition()-1]->getSquareName()<<endl;
                    cout<<playerone->getPlayerName()<<" passes GO and collects "<<pound<<"200"<<endl;

                    if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 1 || squares[playerone->getPlayerPosition() - 1]->getSquareType() == 3) {

                        if (squares[playerone->getPlayerPosition() - 1]->getOwner().empty()) {
                            squares[playerone->getPlayerPosition() - 1]->setOwner(playerone->getPlayerName());
                            playerone->setPLayerMoney(playerone->getPLayerMoney() -
                                                      squares[playerone->getPlayerPosition() - 1]->getCost());
                            cout << playerone->getPlayerName() << " buys "
                                 << squares[playerone->getPlayerPosition() - 1]->getSquareName() << " for " << pound
                                 << squares[playerone->getPlayerPosition() - 1]->getCost() << endl;
                        } else if (squares[playerone->getPlayerPosition() - 1]->getOwner() ==
                                   playerone->getPlayerName()) {
                            cout << playerone->getPlayerName() << " owns "
                                 << squares[playerone->getPlayerPosition() - 1]->getSquareName() << endl;
                        } else if (squares[playerone->getPlayerPosition() - 1]->getOwner() ==
                                   playertwo->getPlayerName()) {
                            playerone->setPLayerMoney(playerone->getPLayerMoney() -
                                                      squares[playerone->getPlayerPosition() - 1]->getRent());
                            if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 1) {
                                cout << playerone->getPlayerName() << " pays rent "
                                     << squares[playerone->getPlayerPosition() - 1]->getSquareName() << " for " << pound
                                     << squares[playerone->getPlayerPosition() - 1]->getRent() << endl;
                            } else if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 3) {
                                cout << playerone->getPlayerName() << " pay " << pound
                                     << squares[playerone->getPlayerPosition() - 1]->getRent() << " for ticket" << endl;
                            }
                            playertwo->setPLayerMoney(playertwo->getPLayerMoney() +
                                                      squares[playerone->getPlayerPosition() - 1]->getRent());
                        }
                    } else if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 6) {
                        cout << playerone->getPlayerName() << " is just visiting" << endl;
                    } else if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 7) {
                        playerone->setPlayerPosition(7);
                        cout << playerone->getPlayerName() << " goes to jail" << endl;
                        cout << playerone->getPlayerName() << " pays " << pound << "50" << endl;
                    } else if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 8) {
                        cout << playerone->getPlayerName() << " is resting" << endl;
                    }


                    cout<<playerone->getPlayerName()<<" has "<<pound<<playerone->getPLayerMoney()<<endl;
                    player1 = false;
                    player2 = true;

                }
                else
                {
                    playerone->setPlayerPosition(playerone->getPlayerPosition() + randomnumber);
                    cout<<playerone->getPlayerName()<<" rolls "<<randomnumber<<endl;
                    cout<<playerone->getPlayerName()<<" lands on "<<squares[playerone->getPlayerPosition()-1]->getSquareName()<<endl;

                    if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 1 || squares[playerone->getPlayerPosition() - 1]->getSquareType() == 3) {

                        if (squares[playerone->getPlayerPosition() - 1]->getOwner().empty()) {
                            squares[playerone->getPlayerPosition() - 1]->setOwner(playerone->getPlayerName());
                            playerone->setPLayerMoney(playerone->getPLayerMoney() -
                                                      squares[playerone->getPlayerPosition() - 1]->getCost());
                            cout << playerone->getPlayerName() << " buys "
                                 << squares[playerone->getPlayerPosition() - 1]->getSquareName() << " for " << pound
                                 << squares[playerone->getPlayerPosition() - 1]->getCost() << endl;
                        } else if (squares[playerone->getPlayerPosition() - 1]->getOwner() ==
                                   playerone->getPlayerName()) {
                            cout << playerone->getPlayerName() << " owns "
                                 << squares[playerone->getPlayerPosition() - 1]->getSquareName() << endl;
                        } else if (squares[playerone->getPlayerPosition() - 1]->getOwner() ==
                                   playertwo->getPlayerName()) {
                            playerone->setPLayerMoney(playerone->getPLayerMoney() -
                                                      squares[playerone->getPlayerPosition() - 1]->getRent());
                            if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 1) {
                                cout << playerone->getPlayerName() << " pays rent "
                                     << squares[playerone->getPlayerPosition() - 1]->getSquareName() << " for " << pound
                                     << squares[playerone->getPlayerPosition() - 1]->getRent() << endl;
                            } else if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 3) {
                                cout << playerone->getPlayerName() << " pay " << pound
                                     << squares[playerone->getPlayerPosition() - 1]->getRent() << " for ticket" << endl;
                            }
                            playertwo->setPLayerMoney(playertwo->getPLayerMoney() +
                                                      squares[playerone->getPlayerPosition() - 1]->getRent());
                        }
                    } else if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 6) {
                        cout << playerone->getPlayerName() << " is just visiting" << endl;
                    } else if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 7) {
                        playerone->setPlayerPosition(7);
                        cout << playerone->getPlayerName() << " goes to jail" << endl;
                        cout << playerone->getPlayerName() << " pays " << pound << "50" << endl;
                    } else if (squares[playerone->getPlayerPosition() - 1]->getSquareType() == 8) {
                        cout << playerone->getPlayerName() << " is resting" << endl;
                    }

                    cout<<playerone->getPlayerName()<<" has "<<pound<<playerone->getPLayerMoney()<<endl;
                    player1 = false;
                    player2 = true;
                }

            } else if (player2) {
                cout << "Chance of Player 02 " << endl;
                randomnumber = Random();
                //cout << randomnumber << endl;
                if (playertwo->getPlayerPosition()+randomnumber>26)
                {
                    playertwo->setPlayerPosition(playertwo->getPlayerPosition() + randomnumber-26);
                    playertwo->setPLayerMoney(playertwo->getPLayerMoney()+200);
                    cout<<playertwo->getPlayerName()<<" rolls "<<randomnumber<<endl;
                    cout<<playertwo->getPlayerName()<<" lands on "<<squares[playertwo->getPlayerPosition()-1]->getSquareName()<<endl;
                    cout<<playertwo->getPlayerName()<<" passes GO and collects "<<pound<<"200"<<endl;

                    if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 1 || squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 3) {
                        if (squares[playertwo->getPlayerPosition() - 1]->getOwner().empty()) {
                            squares[playertwo->getPlayerPosition() - 1]->setOwner(playertwo->getPlayerName());
                            playertwo->setPLayerMoney(playertwo->getPLayerMoney() -
                                                      squares[playertwo->getPlayerPosition() - 1]->getCost());
                            cout << playertwo->getPlayerName() << " buys "
                                 << squares[playertwo->getPlayerPosition() - 1]->getSquareName() << " for " << pound
                                 << squares[playertwo->getPlayerPosition() - 1]->getCost() << endl;
                        } else if (squares[playertwo->getPlayerPosition() - 1]->getOwner() ==
                                   playertwo->getPlayerName()) {
                            cout << playertwo->getPlayerName() << " owns "
                                 << squares[playertwo->getPlayerPosition() - 1]->getSquareName() << endl;
                        } else if (squares[playertwo->getPlayerPosition() - 1]->getOwner() ==
                                   playerone->getPlayerName()) {
                            playertwo->setPLayerMoney(playertwo->getPLayerMoney() -
                                                      squares[playertwo->getPlayerPosition() - 1]->getRent());
                            if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 1) {
                                cout << playertwo->getPlayerName() << " pays rent "
                                     << squares[playertwo->getPlayerPosition() - 1]->getSquareName() << " for " << pound
                                     << squares[playertwo->getPlayerPosition() - 1]->getRent() << endl;
                            } else if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 3) {
                                cout << playertwo->getPlayerName() << " pay " << pound
                                     << squares[playertwo->getPlayerPosition() - 1]->getRent() << " for ticket" << endl;
                            }
                            playerone->setPLayerMoney(playertwo->getPLayerMoney() +
                                                      squares[playertwo->getPlayerPosition() - 1]->getRent());
                        }
                    } else if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 6) {
                        cout << playertwo->getPlayerName() << " is just visiting" << endl;
                    } else if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 7) {
                        playertwo->setPlayerPosition(7);
                        cout << playertwo->getPlayerName() << " goes to jail" << endl;
                        cout << playertwo->getPlayerName() << " pays " << pound << "50" << endl;
                    } else if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 8) {
                        cout << playertwo->getPlayerName() << " is resting" << endl;
                    }

                    cout<<playertwo->getPlayerName()<<" has "<<pound<<playertwo->getPLayerMoney()<<endl;
                    player2 = false;
                    player1 = true;

                }
                else
                {
                    playertwo->setPlayerPosition(playertwo->getPlayerPosition() + randomnumber);
                    cout<<playertwo->getPlayerName()<<" rolls "<<randomnumber<<endl;
                    cout<<playertwo->getPlayerName()<<" lands on "<<squares[playertwo->getPlayerPosition()-1]->getSquareName()<<endl;

                    if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 1 || squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 3) {

                        if (squares[playertwo->getPlayerPosition() - 1]->getOwner().empty()) {
                            squares[playertwo->getPlayerPosition() - 1]->setOwner(playertwo->getPlayerName());
                            playertwo->setPLayerMoney(playertwo->getPLayerMoney() -
                                                      squares[playertwo->getPlayerPosition() - 1]->getCost());
                            cout << playertwo->getPlayerName() << " buys "
                                 << squares[playertwo->getPlayerPosition() - 1]->getSquareName() << " for " << pound
                                 << squares[playertwo->getPlayerPosition() - 1]->getCost() << endl;
                        } else if (squares[playertwo->getPlayerPosition() - 1]->getOwner() ==
                                   playertwo->getPlayerName()) {
                            cout << playertwo->getPlayerName() << " owns "
                                 << squares[playertwo->getPlayerPosition() - 1]->getSquareName() << endl;
                        } else if (squares[playertwo->getPlayerPosition() - 1]->getOwner() ==
                                   playerone->getPlayerName()) {
                            playertwo->setPLayerMoney(playertwo->getPLayerMoney() -
                                                      squares[playertwo->getPlayerPosition() - 1]->getRent());
                            if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 1) {
                                cout << playertwo->getPlayerName() << " pays rent "
                                     << squares[playertwo->getPlayerPosition() - 1]->getSquareName() << " for " << pound
                                     << squares[playertwo->getPlayerPosition() - 1]->getRent() << endl;
                            } else if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 3) {
                                cout << playertwo->getPlayerName() << " pay " << pound
                                     << squares[playertwo->getPlayerPosition() - 1]->getRent() << " for ticket" << endl;
                            }
                            playerone->setPLayerMoney(playertwo->getPLayerMoney() +
                                                      squares[playertwo->getPlayerPosition() - 1]->getRent());
                        }
                    } else if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 6) {
                        cout << playertwo->getPlayerName() << " is just visiting" << endl;
                    } else if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 7) {
                        playertwo->setPlayerPosition(7);
                        cout << playertwo->getPlayerName() << " goes to jail" << endl;
                        cout << playertwo->getPlayerName() << " pays " << pound << "50" << endl;
                    } else if (squares[playertwo->getPlayerPosition() - 1]->getSquareType() == 8) {
                        cout << playertwo->getPlayerName() << " is resting" << endl;
                    }


                    cout<<playertwo->getPlayerName()<<" has "<<pound<<playertwo->getPLayerMoney()<<endl;
                    player2 = false;
                    player1 = true;
                }
            }
        }
    }

    cout << "\n\nGame Over !!!" << endl;
    cout <<  playerone->getPlayerName() << " has " << playerone->getPLayerMoney() <<  endl;
    cout <<  playertwo->getPlayerName() << " has " << playertwo->getPLayerMoney() << endl;
    if (playerone->getPLayerMoney() > playertwo->getPLayerMoney()) {
        cout << "\n" << playerone->getPlayerName() << " has WON!!!" << endl;
    } else if (playerone->getPLayerMoney() < playertwo->getPLayerMoney()) {
        cout << "\n" << playertwo->getPlayerName() << " has WON!!!" << endl;
    } else {
        cout << "\n" << "ERROR!!!" << endl;
    }
//    cout << squares.size() << endl;
//    for (int j = 0; j < squares.size(); ++j) {
//        if (squares[j]->getSquareType() == 1) {
//        cout << squares[j]->getSquareType() << " - " << squares[j]->getSquareName() << " - " << squares[j]->getCost() << " - " << squares[j]->getRent() << " - " << squares[j]->getColorGroup() << endl;
//        } else {
//            cout << squares[j]->getSquareType() << " - " << squares[j]->getSquareName() << endl;
//        }
//    }


}



