//
// Created by Christopher Acosta on 11/7/18.
//
#include "deck.h"
#include "card.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;

//spades, diamonds, clubs, hearts
Deck::Deck()
{

    Card::Suit currentSuit = Card::spades;
    int currentRank = 1;
    myIndex = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(currentRank < 14)
        {
            myCards[i] = Card(currentRank, currentSuit);
            currentRank++;
        }
        else
        {
            i--;
            currentRank = 1;
            if(currentSuit == Card::spades)
                currentSuit = Card::hearts;
            else if(currentSuit == Card::hearts)
                currentSuit = Card::diamonds;
            else if(currentSuit == Card::diamonds)
                currentSuit = Card::clubs;
        }

    }
}


void Deck::shuffle()
{
    int i;
    srand(time(0));
    for (i = 0; i < rand(); i++)
    {
        swap(myCards[rand() % SIZE], myCards[rand() % SIZE]);
    }
}

Card Deck::dealCard()
{
    if(myIndex < SIZE)
    {
        Card deal = myCards[myIndex];
        myIndex++;
        return deal;
    }
}

int  Deck::size() const
{
    return (SIZE - myIndex);
}