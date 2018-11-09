//
// Created by Christopher Acosta on 11/7/18.
//

#include "card.h"
#include <cstdlib>
#include <string>

using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{
    return (rankString(myRank) + suitString(mySuit));
}

bool Card::sameSuitAs(const Card& c) const{
    return (mySuit == c.mySuit);
}

int Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s) const{
    if(s == spades)
        return "s";
    if(s == hearts)
        return "h";
    if(s == clubs)
        return "c";
    if(s == diamonds)
        return "d";
}

string Card::rankString(int r) const{

    if(r == 1)
        return "A";
    else if(r == 2)
        return "2";
    else if(r == 3)
        return "3";
    else if(r == 4)
        return "4";
    else if(r == 5)
        return "5";
    else if(r == 6)
        return "6";
    else if(r == 7)
        return "7";
    else if(r == 8)
        return "8";
    else if(r == 9)
        return "9";
    else if(r == 10)
        return "10";
    else if(r == 11)
        return "J";
    else if(r == 12)
        return "Q";
    else if (r == 13)
        return "K";

}

bool Card::operator == (const Card& rhs) const
{
    return (myRank == rhs.myRank);
}

bool Card::operator != (const Card& rhs) const
{
    return (myRank != rhs.myRank);

}

ostream& operator << (ostream& out, const Card& c)
{
    return out << c.toString();
}
