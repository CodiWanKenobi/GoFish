//
// Created by Christopher Acosta on 11/7/18.
//

#include "player.h"
#include "deck.h"
#include "card.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <utility>

void Player::addCard(Card c)
{
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2)
{
    removeCardFromHand(c1);
    removeCardFromHand(c2);
    myBook.push_back(c1);
    myBook.push_back(c2);
}


bool Player::checkHandForBook(Card &c1, Card &c2)
{
    int i, j;
    for(i = 0; i < myHand.size() - 1; i++)
    {
        for (j = i + 1; j < myHand.size(); j++)
        {
            if (myHand[i] == myHand[j])
            {
                //bookCards(myHand[i], myHand[j]);
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}
/*
bool Player::rankInHand(Card c) const{

}
*/

Card Player::chooseCardFromHand() const
{
    if(myHand.size() != 0)
        return myHand[rand() % myHand.size()];
}

bool Player::cardInHand(Card c) const
{
    for(int i = 0; i < myHand.size(); i++)
    {
        if(myHand[i] == c)
            return true;
    }
    return false;
}

Card Player::removeCardFromHand(Card c)
{

    /*vector<Card>::iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++)
    {
        if(*iter == c)
            break;

    }
    myHand.erase(iter);
    return c;*/


    int index = -1;
    for(int i = 0; i < myHand.size(); i++)
    {
        if(myHand[i] == c)
        {
            index = i;
            c = myHand[index];
        }

    }
    if(index >= 0)
    {
        myHand.erase(myHand.begin() + index);
    }
    return c;
}

string Player::showHand() const
{
    string hand = "";
    if(myHand.size() > 0)
    {
        hand += " has : ";
        for(int i = 0; i < myHand.size(); i++)
        {
            hand += myHand[i].toString() + " ";
        }
    }
    else
    {
        hand += " does not have any cards!";
    }
    return hand;
}

string Player::showBooks() const
{
    string books = "";
    int i, j;
    j = 0;
    for(i = 0; i < myBook.size(); i++)
    {
        if((j % 7) == 0)
            books += "\n";
        books += myBook[i].toString() + " ";
        j++;
    }
    return books;
}

int Player::getHandSize() const
{
    return myHand.size();
}

int Player::getBookSize() const
{
    int numBooks = myBook.size();
    numBooks /= 2;
    return numBooks;
}


/*bool Player::checkHandForPair(Card &c1, Card &c2)
{

}


bool Player::sameRankInHand(Card c) const{

}*/
