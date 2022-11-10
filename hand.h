#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;

class Hand {
    private:
        Card* cards; // An array of cards in hand
        int n_cards; // Number of cards in the hand.
    public:
        Hand();
        ~Hand();
        Hand(const Hand&);
        Hand& operator=(const Hand &);
        void set_cards();
        void set_num(int);
        int get_num();
        int get_rank_num(int);
        string get_rank(int);
        void draw(Card&);
        void print_card();
        bool search(string);
        void give(int);
        Card& indicate(int);
};

#endif