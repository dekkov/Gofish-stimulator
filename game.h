#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;

class Game {
    private:
        Deck d;
        Player Players[2];
        bool is_correct;
    public:
        Game();
        void start();
        int get_num_card();
        bool get_condition();
        void deal_card();
        void check();
        void turn();
        void give(string,int);
        void set_condition(int);
        bool valid(int, string);
        void play(int);
        void bot_check();
        void bot_check_debug();
        void bot_check_advance();
        void is_book(int);
        void is_book_debug(int);
        void compare();
        void check_debug();
        void deal_card_debug();
};

void press_enter();
string take_input();

#endif