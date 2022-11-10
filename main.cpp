#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"


using namespace std;

int main(){
    srand(time(NULL));
    int option;
    int i = 0;
    do{
        cout << "Welcome to GO FISH!!!" << endl;
        cout << "Choose a mode: 1-normal 2-debug 3-advance: ";
        cin >> i;
        Game game;
        game.start();
        if (i == 2)
            game.deal_card_debug();
        else
            game.deal_card();
        game.play(i);

        cout << "Do you want to play again? 1-yes 2-no: ";
        cin >> option;
        cout << endl << endl << endl;


    }while(option == 1);

}