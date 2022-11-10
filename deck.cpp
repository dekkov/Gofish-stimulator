#include "deck.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;

//Constructor

/*********************************************************************
** Function: Deck()
** Description: default constructor for class Deck
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: an object of Deck()
*********************************************************************/
Deck::Deck(){
    
    Card();
    this->n_cards = 52;
    
}

//setters

/*********************************************************************
** Function: set_n()
** Description: default constructor for class Deck
** Parameters: int n
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
void Deck::set_n(int n){
    this->n_cards = n;
}

//getters
/*********************************************************************
** Function: get_n()
** Description: int
** Parameters: Deck
** Pre-Conditions: None
** Post-Conditions: none
** Return: the number of cards 
*********************************************************************/

int Deck::get_n(){
    return this->n_cards;
}



/*********************************************************************
** Function: get_card(int n)
** Description: get the card at index n
** Parameters: int n
** Pre-Conditions: None
** Post-Conditions: none
** Return: an object of Deck()
*********************************************************************/
Card Deck::get_card(int n){
    return this->cards[n];
}

//function
/*********************************************************************
** Function: populate_deck()
** Description: populate the deck with 52
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
void Deck::populate_deck(){
    int count = 0;
    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 4; j++){
            this->cards[count] = populate_card(i,j);
            count += 1;
        }
    }
}


/*********************************************************************
** Function: shuffle()
** Description: shuffle the deck
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Deck::shuffle(){
    for (int i = 0; i < 2000; i++){
        int n = rand() % 52;
        int m = rand() % 52;
        // while (n == m){
        //     int m = rand() % 53;
        // }
        swap(this->cards[n],this->cards[m]);
    }
}


/*********************************************************************
** Function: remove_card()
** Description: remove the card at last index of the deck.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
Card& Deck::remove_card(){
    this->n_cards --;
    return this->cards[this->n_cards];
}