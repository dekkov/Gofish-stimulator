#include "card.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;


//constructors
/*********************************************************************
** Function: Card()
** Description: Constructor for class Card()
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
Card::Card(){
    // cout << "inside card default constructor..." << endl;
    this -> rank = 0;
    this -> suit = 0;
}


//Destructors
/*********************************************************************
** Function: ~Card()
** Description: Destructor for class Card()
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
Card::~Card(){

}

//getters
/*********************************************************************
** Function: Card::get_rank()
** Description: Getter to get the rank of the Card
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the number of the card rank
*********************************************************************/
int Card::get_rank(){
    return this->rank;
}

/*********************************************************************
** Function: Card::get_rank()
** Description: Getter to get the suit of the Card
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: card's suit
*********************************************************************/
int Card::get_suit(){
    return this->suit;
}

//setters

/*********************************************************************
** Function: Card::set_rank(int num)
** Description: Setter to get the rank of the Card
** Parameters: int num 
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
void Card::set_rank(int num){
    this->rank = num;
}

/*********************************************************************
** Function: Card::set_suit()
** Description: setter to set the suit of the Card
** Parameters: int num 
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
void Card::set_suit(int num){
    this->suit = num;
}

//functions


/*********************************************************************
** Function: Card::map_suit()
** Description: convert the suit from int to string
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: string suit
*********************************************************************/
string Card::map_suit(){

    //map each rank with the approriate suit.
    string suit;
    if (this->suit == 0){
        suit = "♠️";
    }
    else if (this->suit == 1){
        suit = "♣️";
    }
    else if (this->suit == 2){
        suit = "♦";
    }
    else if (this-> suit == 3){
        suit = "♥";
    }
    return suit;
}

/*********************************************************************
** Function: Card::map_rank()
** Description: convert the rank from int to string
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: string rank
*********************************************************************/
string Card::map_rank(){
    string some_array [13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    return some_array[this->rank];
}

/*********************************************************************
** Function: Card::print_card()
** Description: print out the card suit and rank
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: rank and suit of the card
*********************************************************************/
void Card::print_card(){
    // cout << "Print card" << endl;
    cout << map_suit();
    cout << map_rank(); 
    cout << " ";
}


/*********************************************************************
** Function: populate_card(int rank, int suit)
** Description: set rank and suit for the card
** Parameters: int rank, int suit
** Pre-Conditions: None
** Post-Conditions: none
** Return: return a card
*********************************************************************/
Card populate_card(int rank, int suit){
    Card c;
    c.set_rank(rank);
    c.set_suit(suit);
    return c;
}

