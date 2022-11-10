#ifndef PLAYER_H
#define PLAYER_H 

#include "hand.h"
#include "card.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;

class Player {
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books.
        int n_books;
    public:
        Player();
        Player (int);
        ~Player(); //destructor 
        Player (const Player &); //copy constructor
        Player& operator=(const Player &); //assignment operator overload
        int get_num_book();
        int get_n();
        int get_rank_num(int);
        void set_books(int);
        void set_num_book(int);
        void draw(Card&);
        void print_hand();
        bool search(string);
        void give(int);
        string get_rank(int);
        Card& indicate(int);
        void remove_card(int);
        void print_book();

};
#endif