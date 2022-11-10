#include "hand.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;

/*********************************************************************
** Function: Hand()
** Description: default constructor for Hand()
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: return default object for Hand()
*********************************************************************/
Hand::Hand(){
    
    this->n_cards = 0;
    this->cards = NULL;
}



/*********************************************************************
** Function: ~Hand()
** Description: destructor for class Hand
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
//Destructor
Hand::~Hand(){
    if (this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }
}



/*********************************************************************
** Function: Hand()
** Description: copy constructor for hand
** Parameters: Hand& h
** Pre-Conditions: None
** Post-Conditions: none
** Return: Hand
*********************************************************************/
//Copy Constructor
Hand::Hand(const Hand& h){
    this->n_cards = h.n_cards;
    this->cards = new Card[this->n_cards];

    for (int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }
}


/*********************************************************************
** Function: Hand& Hand::operator=(const Hand& h)()
** Description: Assignment Operator for class Hand
** Parameters: Hand& h
** Pre-Conditions: None
** Post-Conditions: none
** Return: an assigned Object for Hand&
*********************************************************************/

//Assignment Operator
Hand& Hand::operator=(const Hand& h){
    this->n_cards = h.n_cards;

    if(this->cards != NULL){
        delete [] this->cards;
    }

    this->cards = new Card[this->n_cards];

    for (int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }

    return *this;
}

//Getters
/*********************************************************************
** Function: get_num()
** Description: Get the number of cards on the hand
** Parameters: Hand& h
** Pre-Conditions: None
** Post-Conditions: none
** Return: the number of cards
*********************************************************************/

int Hand::get_num(){
    return this->n_cards;
}


/*********************************************************************
** Function: get__rank_num()
** Description: Get the card rank in number format 
** Parameters: Hand& h
** Pre-Conditions: None
** Post-Conditions: none
** Return: an integer of the card rank 
*********************************************************************/
int Hand::get_rank_num(int i){
    return this->cards[i].get_rank();
}


/*********************************************************************
** Function: get_rank(int i)
** Description: get the rank in string format
** Parameters: int i
** Pre-Conditions: None
** Post-Conditions: none
** Return: an string of the card rank 
*********************************************************************/

string Hand::get_rank(int i){
    return this->cards[i].map_rank();
}
//Setters


/*********************************************************************
** Function: set_num(int n)
** Description: setter for the number of cards on hand
** Parameters: int n
** Pre-Conditions: None
** Post-Conditions: none
** Return: NOne
*********************************************************************/
void Hand::set_num(int n){
    this->n_cards = n;
}

//function


/*********************************************************************
** Function: draw(Card& c)
** Description: draw the card C and put it into the hand
** Parameters: int i
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
void Hand::draw(Card& c){
    //allocate for new array with 1 larger size
    Card* new_arr = new Card [this->n_cards+1];

    //Loop throught the array and give values
    for (int i=0; i < this->n_cards; i++){
        new_arr[i] = this->cards[i];
    }

    new_arr[this->n_cards] = c;

    //free memory if not done previously
    if (this->cards != NULL)
        delete [] this->cards;

    //assign temp array to the pointer of the class and increase num card by 1
    this->cards = new_arr;
    this->n_cards++;

} 


/*********************************************************************
** Function: print_card()
** Description: print all the cards on hands
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Hand::print_card(){
    for (int i = 0; i < this->n_cards; i++){
        this->cards[i].print_card();
    }
}


/*********************************************************************
** Function: search(string c)
** Description: search for cards with the rank c
** Parameters: string c
** Pre-Conditions: None
** Post-Conditions: none
** Return: true if found and false otherwise
*********************************************************************/

bool Hand::search(string c){
    int n = 1;
    bool s = false;
    string a;
    for (int i =0; i < this->n_cards; i++){
        a = this->cards[i].map_rank();
        n = a.compare(c); 
        if (n == 0){
            s = true;
        }
    }
    return s;
}


/*********************************************************************
** Function: give(int n)
** Description: remove the card at index n
** Parameters: int n
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Hand::give(int n){
    //allocate for new array with 1 larger size
    
    Card* new_arr = new Card [this->n_cards-1];

    //Loop throught the array and give values
    for (int i = 0; i < this->n_cards; i++){
        if (i < n){
            new_arr[i] = this->cards[i];
        }
        else if (i > n){
            new_arr[i-1] = this->cards[i];
        }

    }

    //free memory if not done previously
    if (this->cards != NULL)
        delete [] this->cards;

    //assign temp array to the pointer of the class and increase num card by 1
    this->cards = new_arr;
    this->n_cards--;

}


/*********************************************************************
** Function: indicate(int i)
** Description: indicate the cadr at index i
** Parameters: int i
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

Card& Hand::indicate(int i){
    return this->cards[i];
}