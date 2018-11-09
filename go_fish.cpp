// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides myfile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int oldmain( )
{
    int numCards = 5;

    Player currentPlayer("Joe");
    Player otherPlayer("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, currentPlayer, numCards);
    dealHand(d, otherPlayer, numCards);

//    myfile << currentPlayer.getName()  << currentPlayer.showHand() << endl;
  //  myfile << otherPlayer.getName()  << otherPlayer.showHand() << endl;

    return EXIT_SUCCESS;
}

int main()
{
    int numCards = 7;
    ofstream myfile;
    myfile.open ("gofish_results.txt");

    Player currentPlayer("Chris");
    Player otherPlayer("Mihir");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, currentPlayer, numCards);
    dealHand(d, otherPlayer, numCards);

    myfile << currentPlayer.getName() << currentPlayer.showHand() << endl;
    myfile << otherPlayer.getName() << otherPlayer.showHand() << endl;

    //Card c1(1, Card::spades);
    //Card c2(2, Card::spades);
    Card c1, c2;

    while(currentPlayer.checkHandForBook(c1, c2))
    {
        currentPlayer.bookCards(c1, c2);
        myfile << currentPlayer.getName() << " books the " << c1 << " and " << c2 << endl;
        myfile << currentPlayer.getName()  << currentPlayer.showHand() << endl;
    }
    myfile << endl;
    while(otherPlayer.checkHandForBook(c1, c2))
    {
        otherPlayer.bookCards(c1, c2);
        myfile << otherPlayer.getName() << " books the " << c1 << " and " << c2 << endl;
        myfile << otherPlayer.getName()  << otherPlayer.showHand() << endl;
    }
    myfile << endl;

    Card guess;
    Card dealtCard;
    bool nextPlayerTurn = false;

    while(currentPlayer.getHandSize() > 0 ||  otherPlayer.getHandSize() > 0)
    {
        nextPlayerTurn = false;
        while(!nextPlayerTurn)
        {
            if(currentPlayer.getHandSize() == 0)
            {
                if(d.size() > 0)
                {
                    dealtCard = d.dealCard();
                    currentPlayer.addCard(dealtCard);
                    myfile << currentPlayer.getName() << " draws a " << dealtCard << endl;
                    myfile << currentPlayer.getName()  << currentPlayer.showHand() << endl;
                }
                else
                {
                    nextPlayerTurn = true;
                }
                myfile << endl;
            }
            else
            {
                guess = currentPlayer.chooseCardFromHand();
                myfile << currentPlayer.getName() << " asks - Have any " << guess.rankString(guess.getRank()) << "'s?";
                myfile << endl;
                if(!otherPlayer.cardInHand(guess))
                {
                    if(d.size() == 0)
                    {
                        myfile << otherPlayer.getName() << " says - I'd say Go Fish, but there's no cards in the deck! Haha";
                        myfile << endl;
                        myfile << currentPlayer.getName() << " says - HAHAHAHAHAHAHAHAHAHAHAHA" << endl;
                        myfile << endl;
                    }
                    else
                    {
                        myfile << otherPlayer.getName() << " says - Go Fish" << endl;
                        dealtCard = d.dealCard();
                        currentPlayer.addCard(dealtCard);
                        myfile << currentPlayer.getName() << " draws a " << dealtCard << endl;
                        myfile << currentPlayer.getName() << currentPlayer.showHand() << endl;
                        if(currentPlayer.checkHandForBook(c1, c2))
                        {
                            currentPlayer.bookCards(c1, c2);
                            myfile << currentPlayer.getName() << " books the " << c1 << " and " << c2 << endl;
                            myfile << currentPlayer.getName() << currentPlayer.showHand() << endl;
                        }
                        myfile << endl;
                    }
                    nextPlayerTurn = true;
                    swap(currentPlayer, otherPlayer);
                }
                else
                {
                    myfile << otherPlayer.getName() << " says - Yes, I do" << endl;
                    guess = otherPlayer.removeCardFromHand(guess);
                    currentPlayer.addCard(guess);
                    if(currentPlayer.checkHandForBook(c1, c2))
                    {
                        currentPlayer.bookCards(c1, c2);
                        myfile << currentPlayer.getName() << " books the " << c1 << " and " << c2 << endl;
                        myfile << currentPlayer.getName() << currentPlayer.showHand() << endl;
                    }
                    myfile << otherPlayer.getName() << otherPlayer.showHand() << endl;
                    myfile << endl;
                }
            }
        }
    }
    myfile << currentPlayer.getName() << currentPlayer.showBooks();
    myfile << " for a total of " << currentPlayer.getBookSize() << " books." << endl << endl;
    myfile << otherPlayer.getName() << otherPlayer.showBooks();
    myfile << " for a total of " << otherPlayer.getBookSize() << " books." << endl << endl;
    if(currentPlayer.getBookSize() > otherPlayer.getBookSize())
        myfile << currentPlayer.getName() << " wins!" << endl;
    else if(otherPlayer.getBookSize() > currentPlayer.getBookSize())
        myfile << otherPlayer.getName() << " wins!" << endl;
    else
        myfile << "The game has ended in a tie!" << endl;
    myfile << endl;

    myfile.close();

    return EXIT_SUCCESS;
}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}


   


