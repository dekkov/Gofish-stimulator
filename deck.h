#ifndef DECK_H
#define DECK_H 

#include "card.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;

class Deck {
    private:
        Card cards[52]; //A full deck of cards
        int n_cards; // Number of cards remaining in the deck.
    public:
        Deck();
        void set_n(int);
        int get_n();
        Card get_card(int);
        void setup();
        void populate_deck();
        void print_deck(); // testing
        void shuffle();
        Card& remove_card();
};
#endif