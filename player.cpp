#include "player.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;

//Constructors

/*********************************************************************
** Function: Player()
** Description: default constructor for class Player
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
Player::Player(){
    Hand();
    this->books = NULL;
    this->n_books = 0;
}

/*********************************************************************
** Function: Player(int size)
** Description: non-default constructor for class Player
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: an object of the Player with the number of books
*********************************************************************/

Player::Player (int size) {
    this->n_books = size;
    this->books = new int [size];
}
//Destructors

/*********************************************************************
** Function: ~Player()
** Description: Destructor for class Player
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

Player::~Player(){
    if (this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }
    // ~Hand();
}
//Copy Constructor

/*********************************************************************
** Function: Player(const Player& p)
** Description: Copy Constructor for Player class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: a copied object for class Player
*********************************************************************/

Player::Player(const Player& p){
    cout << "CC called" << endl;
    // this->hand = p.hand;
    this->n_books = p.n_books;
    this->books = new int[this->n_books];

    for (int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }
}





//Assignmnet Operator

/*********************************************************************
** Function: Player::operator=(const Player& p)
** Description: Destructor for class Player
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: an assigned object of Player class
*********************************************************************/

Player& Player::operator=(const Player& p){
    //assign value of num books
    this->n_books = p.n_books;


    //free memory if not done previously
    if (this->books != NULL){
        delete [] this->books;
    }

    //create new pointer
    this->books = new int[this->n_books];

    //loop through and give values
    for (int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }   

    return *this;
}

//Getters

/*********************************************************************
** Function: get_num_book()
** Description: get the number of books on the hand
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the number books on the hand
*********************************************************************/

int Player::get_num_book(){
    return this->n_books;
}

/*********************************************************************
** Function: get_rank_num(int i)
** Description: get the rank of card at index i
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the integer of the rank of card at index i
*********************************************************************/

int Player::get_rank_num(int i){
    return this->hand.get_rank_num(i);
}

//Setters

/*********************************************************************
** Function: set_num_book(int n)
** Description: setter for the number of books 
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
void Player::set_num_book(int n){
    this->n_books = n;
}

/*********************************************************************
** Function: set_books(int n)
** Description: setter for the number of the number of book the player have.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
void Player::set_books(int n){
    int* new_arr = new int [this->n_books+1];

    for (int i = 0; i < this->n_books; i++){
        new_arr[i] = this->books[i];
    }   

    new_arr[this->n_books] = n;

    if (this->books != NULL){
        delete [] this->books;
    }
    
    this->books = new_arr;
    this->n_books++;

       
}

//Function 

/*********************************************************************
** Function: draw(Card& c)
** Description: draw the card c
** Parameters: Card& c
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Player::draw(Card& c){
    this->hand.draw(c);
}

/*********************************************************************
** Function: print_hand()
** Description: print all the hand on the cards
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/


void Player::print_hand(){
    this->hand.print_card();
}

/*********************************************************************
** Function: search(string c)
** Description: search for cards with rank c
** Parameters: string c
** Pre-Conditions: None
** Post-Conditions: none
** Return: true if found and false otherwise
*********************************************************************/

bool Player::search(string c){
    return this->hand.search(c);
}

/*********************************************************************
** Function: give(int n)
** Description: remove the card at index n
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Player::give(int n){
    return this->hand.give(n);   
}

/*********************************************************************
** Function: get_n()
** Description: get the number of card on the hand
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the integer of the number of card on the hand
*********************************************************************/

int Player::get_n(){
    return this->hand.get_num();
}

/*********************************************************************
** Function: get_rank(int i)
** Description: get the number of the rank of the card at index i
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the string rank of the card at index i
*********************************************************************/

string Player::get_rank(int i){
    return this->hand.get_rank(i);
}

/*********************************************************************
** Function: indicate(int i)
** Description: get the card at index i
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: a card Object
*********************************************************************/

Card& Player::indicate(int i){
    return this->hand.indicate(i);
}

/*********************************************************************
** Function: print_book()
** Description: print all the book that player have
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Player::print_book(){
    //print the books with approriate maps
    for (int i = 0; i < this->n_books; i++){
        if (this->books[i] == 10){
            cout << "J ";
        }
        else if (this->books[i] == 11){
            cout << "Q ";
        }
        else if (this->books[i] == 12){
            cout << "K ";
        }
        else if (this->books[i] == 0){
            cout << "A ";
        }
        else{
            cout << this->books[i]+1 << " ";
        }
    }
}