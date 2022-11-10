#include "game.h"

#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 


using namespace std;


/*********************************************************************
** Function: press_enter()
** Description: pause the screen until user hit enter
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/
void press_enter() {
   cout << "Press enter to continue!" << endl; 
   cin.get();
}


//constructors
/*********************************************************************
** Function: constructors()
** Description: default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the object of Game class
*********************************************************************/
Game::Game(){
    Deck();
    Player();
    this->is_correct = false;
}


//setters

/*********************************************************************
** Function: set_condition(int i)
** Description: set the condition of is_correct variable
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::set_condition(int i){
    if (i == 1)
        this->is_correct = true;
    else 
        this->is_correct = false;

}
//getters

/*********************************************************************
** Function: get_n()
** Description: get the is_correct value
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the boolean value of is_correct variable
*********************************************************************/

bool Game::get_condition(){
    return this->is_correct;
}

//function


/*********************************************************************
** Function: get_num_card()
** Description: get the number of card left on the deck
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the number of card left on the deck
*********************************************************************/
int Game::get_num_card(){
    return this->d.get_n();
}


/*********************************************************************
** Function: start()
** Description: start the game by populating deck and shuffle it
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::start(){
    d.populate_deck();
    d.shuffle();
}


/*********************************************************************
** Function: deal_card_debug()
** Description: deal cards to each players
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::deal_card_debug(){
    //deal each players 7 cards
    for (int i = 0; i < 14; i++){
        Card c = this->d.remove_card();

        this->Players[i%2].draw(c);
    }

    //print hands of players
    cout << "Player's hand: " << endl;
    this->Players[0].print_hand();
    cout << endl;
    cout << endl;
    cout << "Bot's hand: " << endl;
    this->Players[1].print_hand();
    cout << endl;
    cout << endl;

}

/*********************************************************************
** Function: deal_card_debug()
** Description: deal cards to each players
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::deal_card(){
    //deal each players 7 cards
    for (int i = 0; i < 14; i++){
        Card c = this->d.remove_card();

        this->Players[i%2].draw(c);
    }

    //print out hands
    cout << "Player's hand: " << endl;
    this->Players[0].print_hand();
    cout << endl;
    

}

/*********************************************************************
** Function: take_input())
** Description: take input of the player guess
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: the rank that the number guess
*********************************************************************/

string take_input(){
    string n;
    cout << "Guess a rank (2-A): ";
    cin >> n;

    
    cout << endl;
    return n;
}


/*********************************************************************
** Function: give()
** Description: give the card from a player to the the other one
** Parameters: string c, int p
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::give(string c, int p){ //p is the player have to give
    int n = 1;
    string a;
    int count = 0;
    int arr[4];
    int dem;

    //find indexes that have the same rank value of desired card then put it in to the array arr
    for (int i = 0; i < this->Players[p].get_n(); i++){
        a = this->Players[p].get_rank(i);
        n = a.compare(c);
        dem = i;
        if (n == 0){

            //give card to the other player
            if (p == 0){
                this->Players[1].draw(this->Players[0].indicate(i));
                arr[count] = dem;
                count += 1;
                
            }
            else{
                this->Players[0].draw(this->Players[1].indicate(i));
                arr[count] = dem;
                count += 1;
            
            }
        }
    }

    //remove card from the players being guessed
    for (int i = 0; i < count; i++){
        if(i == 0){
            this->Players[p].give(arr[i]);
        }
        else{
            this->Players[p].give(arr[i]-i*1);    
        }
    }
}


/*********************************************************************
** Function: valid(int i, string c)
** Description: check if the player guess a rank that is on their hand
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: true if they have the rank or false otherwise
*********************************************************************/

bool Game::valid(int i, string c){
    string a;
    int n = 1;
    bool b = false;
    if (i == 0){
        // check if the player have the card rank that they guess?
        for (int j = 0; j < this->Players[1].get_n(); j++){
            a = this->Players[1].get_rank(j);
            n = a.compare(c);
            if (n == 0){
                b = true;
            }
        }
    }

    if (i == 1){
        // check if the player have the card rank that they guess?
        for (int j = 0; j < this->Players[0].get_n(); j++){
            a = this->Players[0].get_rank(j);
            n = a.compare(c);
            if (n == 0){
                b = true;
            }
        }
    }

    //instructions
    if (b == false){
        cout << "Please enter a rank that you have on your hand! " << endl;
    }

    return b;
}

/*********************************************************************
** Function: bot_check()
** Description: play the player turn
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::bot_check(){
    srand(time(NULL));
    cout << endl;
    string c;
    Card card;
    int n;

    //if the other player have no cards, they draw from the deck and then ask for that rank
    

    if(this->Players[1].get_n() == 0){
        Card l = this->d.remove_card();
        this->Players[1].draw(l);
        cout << "Bot just drawed ";
        l.print_card();
        cout << "from the deck!" << endl;

        cout << "Player's hand: " << endl;
        this->Players[0].print_hand();
        cout << endl;
        
    }

    int a;

    //if player have cards, they guess a rank on their hand
    cout << "Bot's turn to guess!!! " << endl;
    cout << "Num card left: " << get_num_card() << endl;
    a = rand() % (this->Players[1].get_n());
    cout << "Bot guessed: " << this->Players[1].get_rank(a) << endl;
    press_enter();

    //use search function to find all the cards the other player have of that rank if other player has cards
    if(this->Players[0].get_n()!=0){
        if(this->Players[0].search(this->Players[1].get_rank(a))){
            cout << "Found!!!" << endl;
            this->give(this->Players[1].get_rank(a),0);
            cout << endl;
            set_condition(1);
            
        }

        else{
            //if there is no card left on the deck
            if(this->d.get_n() == 0){
                set_condition(0);
                cout << "The deck ran out of cards" << endl;
                return;
            }

            //if there cards left on the deck
            else{
                cout << "----------" << endl;
                cout << "GO FISH!!!" << endl;
                cout << "----------" << endl;
                cout << endl;
                Card c = this->d.remove_card();
                cout << endl;
                this->Players[1].draw(c);
                cout << "Bot just drawed from the deck" << endl;

                set_condition(0);
            }
            
        }
    }
    // if the other player has run out of cards.
    else{
        // cout << "Your opponent has run out of card. Let's draw from the deck: " << endl;
        card = this->d.remove_card(); 
        n = c.compare(card.map_rank());
        this->Players[1].draw(card);
        cout << "Bot drawed: ";
        card.print_card();
        cout << endl;
        if (n != 0){
            set_condition(0);
        }
        else{
            set_condition(1);
        }
    }

    cout << "Player's hand: " << endl;
    this->Players[0].print_hand();
    cout << endl;

    
}


/*********************************************************************
** Function: bot_check_advance()
** Description: play the player turn
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::bot_check_advance(){
    srand(time(NULL));
    cout << endl;
    string c;
    Card card;
    int n;
    int count = 0;

    //if they player have no cards, they draw from the deck and then ask for that rank

    if(this->Players[1].get_n() == 0){
        Card l = this->d.remove_card();
        this->Players[1].draw(l);
        cout << "Bot just drawed ";
        l.print_card();
        cout << "from the deck!" << endl;

        cout << "Player's hand: " << endl;
        this->Players[0].print_hand();
        cout << endl;
        
    }
    int a;

    //if player have cards, they guess a rank on their hand
    cout << "Bot's turn to guess!!! " << endl;
    cout << "Num card left: " << get_num_card() << endl;

    for (int i = 0; i < this->Players[1].get_n(); i++){
        for (int j = 0; j < this->Players[0].get_n(); j++){
            if (this->Players[1].get_rank_num(i) == this->Players[0].get_rank_num(j)){
                count += 1;
                n = rand() % 2;
                if (n == 0){
                    a = i;
                }
                else{
                    a = rand() % (this->Players[1].get_n());
                }
            }

            if (count == 0){
                a = rand() % (this->Players[1].get_n());
            }
        }
    }

    // a = rand() % (this->Players[1].get_n());
    cout << "Bot guessed: " << this->Players[1].get_rank(a) << endl;
    press_enter();


    //use search function to find all the cards the other player have of that rank if other player has cards
    if(this->Players[0].get_n()!=0){
        if(this->Players[0].search(this->Players[1].get_rank(a))){
            cout << "Found!!!" << endl;
            this->give(this->Players[1].get_rank(a),0);
            cout << endl;
            set_condition(1);
            
        }
        else{
            //if there is no card left on the deck
            if(this->d.get_n() == 0){
                set_condition(0);
                cout << "The deck ran out of cards" << endl;
                return;
            }

            //if there cards left on the deck
            else{
                cout << "----------" << endl;
                cout << "GO FISH!!!" << endl;
                cout << "----------" << endl;
                cout << endl;
                Card c = this->d.remove_card();
                cout << endl;
                this->Players[1].draw(c);
               

                set_condition(0);
            }
            
        }
    }


    // if the other player has run out of cards.
    else{

        card = this->d.remove_card(); 
        n = c.compare(card.map_rank());
        this->Players[1].draw(card);
        cout << "Bot drawed: ";
        card.print_card();
        cout << endl;
        if (n != 0){
            set_condition(0);
        }
        else{
            set_condition(1);
        }
    }

    cout << "Player's hand: " << endl;
    this->Players[0].print_hand();
    cout << endl;
    
    
}

/*********************************************************************
** Function: bot_check_debug()
** Description: play the player turn
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/


void Game::bot_check_debug(){
    srand(time(NULL));
    cout << endl;
    string c;
    Card card;
    int n;

    //if they player have no cards, they draw from the deck and then ask for that rank
    if(this->Players[1].get_n() == 0){
        Card l = this->d.remove_card();
        this->Players[1].draw(l);
        cout << "Bot just drawed ";
        l.print_card();
        cout << "from the deck!" << endl;

        cout << "Player's hand: " << endl;
        this->Players[0].print_hand();
        cout << endl;
        cout << endl;
        cout << "Bot's hand: " << endl;
        this->Players[1].print_hand();
        cout << endl;
    }
    int a;


    //if player have cards, they guess a rank on their hand
    cout << "Bot's turn to guess!!! " << endl;
    cout << "Num card left: " << get_num_card() << endl;
    a = rand() % (this->Players[1].get_n());
    cout << "Bot guessed: " << this->Players[1].get_rank(a) << endl;
    press_enter();


    //use search function to find all the cards the other player have of that rank if other player has cards
    if(this->Players[0].get_n()!=0){
        if(this->Players[0].search(this->Players[1].get_rank(a))){
            cout << "Found!!!" << endl;
            this->give(this->Players[1].get_rank(a),0);
            cout << endl;
            set_condition(1);
            
        }
        else{
            //if there is no card left on the deck
            if(this->d.get_n() == 0){
                set_condition(0);
                cout << "The deck ran out of cards" << endl;
                return;
            }

            //if there cards left on the deck
            else{
                cout << "----------" << endl;
                cout << "GO FISH!!!" << endl;
                cout << "----------" << endl;
                cout << endl;
                Card c = this->d.remove_card();
                cout << endl;
                this->Players[1].draw(c);
                cout << "Bot just drawed ";
                c.print_card();
                cout << "from the deck!" << endl;
                set_condition(0);
            }
            
        }
    }


    // if the other player has run out of cards.
    else{
        // cout << "Your opponent has run out of card. Let's draw from the deck: " << endl;
        card = this->d.remove_card(); 
        n = c.compare(card.map_rank());
        this->Players[1].draw(card);
        cout << "Bot drawed: ";
        card.print_card();
        cout << endl;
        if (n != 0){
            set_condition(0);
        }
        else{
            set_condition(1);
        }
    }

    cout << "Player's hand: " << endl;
    this->Players[0].print_hand();
    cout << endl;
    cout << endl;
    cout << "Bot's hand: " << endl;
    this->Players[1].print_hand();
    cout << endl;
    
}

/*********************************************************************
** Function: bot_check()
** Description: play the player turn
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::check(){ 
    cout << endl;
    cout << "Player's turn to guess!!! " << endl;
    cout << "Num card left: " << get_num_card() << endl;
    cout << endl;
    string c;
    Card card;
    int n;

    
    //if the other player have no cards, they draw from the deck and then ask for that rank

    if(this->Players[0].get_n() == 0){
        Card l = this->d.remove_card();
        this->Players[0].draw(l);
        cout << "You just drawed ";
        l.print_card();
        cout << "from the deck!" << endl;
        press_enter();

        cout << "Player's card: " << this->Players[0].get_n() << endl;
        cout << "Player's hand: " << endl;
        this->Players[0].print_hand();
        cout << endl;
        cout << endl;
        cout << "Bot's card: " << this->Players[1].get_n() << endl;
        // cout << "Bot's hand: " << endl;
        // this->Players[1].print_hand();
        cout << endl;
        press_enter();
    }

    
    //if player have cards, they guess a rank on their hand
    //take user input of the card rank wanted to guess and check if it is valid
    do{
        c = take_input();

    }while (!valid(1,c));
    
    
    //use search function to find all the cards the other player have of that rank if other player has cards
    if(this->Players[1].get_n()!=0){
        if(this->Players[1].search(c)){
            cout << "Found!!!" << endl;
            this->give(c,1);
            cout << endl;
            set_condition(1);
            
        }
        else{
            //if there is no card left on the deck
            if(this->d.get_n() == 0){
                set_condition(0);
                cout << "The deck ran out of cards" << endl;
                return;
            }
            //if there cards left on the deck
            else{
                cout << "----------" << endl;
                cout << "GO FISH!!!" << endl;
                cout << "----------" << endl;
                cout << endl;
                Card c = this->d.remove_card();
                
                cout << endl;
                this->Players[0].draw(c);

                cout << "You just drawed ";
                c.print_card();
                cout << "from the deck!" << endl;
                set_condition(0);
            }
            
        }
    }

    // if the other player has run out of cards.
    else{
        cout << "Your opponent has run out of card. Let's draw from the deck: " << endl;
        card = this->d.remove_card(); 
        n = c.compare(card.map_rank());
        this->Players[0].draw(card);
        cout << "You drawed: ";
        card.print_card();
        cout << endl;
        if (n != 0){
            set_condition(0);
        }
        else{
            set_condition(1);
        }
           
    }


    cout << "Player's card: " << this->Players[0].get_n() << endl;
    cout << "Player's hand: " << endl;
    this->Players[0].print_hand();
    cout << endl;
    cout << endl;
    cout << "Bot's card: " << this->Players[1].get_n() << endl;
    // cout << "Bot's hand: " << endl;
    // this->Players[1].print_hand();
    cout << endl;

    
    
}

void Game::check_debug(){ 
    cout << endl;
    cout << "Player's turn to guess!!! " << endl;
    cout << "Num card left: " << get_num_card() << endl;
    cout << endl;
    string c;
    Card card;
    int n;

    
    //if the other player have no cards, they draw from the deck and then ask for that rank
    if(this->Players[0].get_n() == 0){
        Card l = this->d.remove_card();
        this->Players[0].draw(l);
        cout << "You just drawed ";
        l.print_card();
        cout << "from the deck!" << endl;
        press_enter();

        cout << "Player's card: " << this->Players[0].get_n() << endl;
        cout << "Player's hand: " << endl;
        this->Players[0].print_hand();
        cout << endl;
        cout << endl;
        cout << "Bot's card: " << this->Players[1].get_n() << endl;
        cout << "Bot's hand: " << endl;
        this->Players[1].print_hand();
        cout << endl;
        press_enter();
    }

    

    //if player have cards, they guess a rank on their hand
    //take user input of the card rank wanted to guess and check if it is valid
    do{
        c = take_input();

    }while (!valid(1,c));
    
    
    //use search function to find all the cards the other player have of that rank if other player has cards
    if(this->Players[1].get_n()!=0){
        if(this->Players[1].search(c)){
            cout << "Found!!!" << endl;
            this->give(c,1);
            cout << endl;
            set_condition(1);
            
        }
        else{
            //if there is no card left on the deck
            if(this->d.get_n() == 0){
                set_condition(0);
                cout << "The deck ran out of cards" << endl;
                return;
            }
            //if there cards left on the deck
            else{
                cout << "----------" << endl;
                cout << "GO FISH!!!" << endl;
                cout << "----------" << endl;
                cout << endl;
                Card c = this->d.remove_card();
                
                cout << endl;
                this->Players[0].draw(c);

                cout << "You just drawed ";
                c.print_card();
                cout << "from the deck!" << endl;
                set_condition(0);
            }
            
        }
    }

    // if the other player has run out of cards.
    else{
        cout << "Your opponent has run out of card. Let's draw from the deck: " << endl;
        card = this->d.remove_card(); 
        n = c.compare(card.map_rank());
        this->Players[0].draw(card);
        cout << "You drawed: ";
        card.print_card();
        cout << endl;
        if (n != 0){
            set_condition(0);
        }
        else{
            set_condition(1);
        }
           
    }


    cout << "Player's card: " << this->Players[0].get_n() << endl;
    cout << "Player's hand: " << endl;
    this->Players[0].print_hand();
    cout << endl;
    cout << endl;
    cout << "Bot's card: " << this->Players[1].get_n() << endl;
    // cout << "Bot's hand: " << endl;
    // this->Players[1].print_hand();
    cout << endl;

    
    
}

/*********************************************************************
** Function: is_book_debug(int p)
** Description: check book of the player p
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/


void Game::is_book_debug(int p){ // i for which player
    bool n;
    bool m;
    int arr[4];
    int b_count = 0;
    int count = 0;

    //count the number of card that have the same rank
    for (int i = 0; i < this->Players[p].get_n(); i++){
        count = 0;
        
        for (int j = 0; j < this->Players[p].get_n(); j++){
            n = this->Players[p].get_rank(i).compare(this->Players[p].get_rank(j));
            if (n == 0){
                count += 1;
                
            }
        }

        
        //if there is a book then increase the number of book by 1 and lay down the cards
        if (count == 4){
            b_count = 0;
            cout << "Found a book of " << this->Players[p].get_rank(i) << endl;
            this->Players[p].set_books(this->Players[p].get_rank_num(i));
            for (int l = 0; l < this->Players[p].get_n(); l++){
                m = this->Players[p].get_rank(l).compare(this->Players[p].get_rank(i));
                if(m == 0){
                    arr[b_count] = l;
                    b_count += 1;
                }
            }
        
            for (int f = 0; f < b_count; f++){
                this->Players[p].give(arr[f]-1*f);
            }       
            
        }

        for (int i = 0; i < 4; i++){
            arr[i] = 0;
        }
    }

 

    //print the books and number of books for each player
    if (p == 0){
        cout << "Player's book: " << this->Players[0].get_num_book() << endl;
        cout << "Books: ";
        this->Players[0].print_book();
        
        cout << endl;
    }
    else{
        cout << "Bot's book: " << this->Players[1].get_num_book() << endl;
        cout << "Books: ";
        
        this->Players[1].print_book();
        
        cout << endl;
    }
}

/*********************************************************************
** Function: is_book(int p)
** Description: check book of the player p
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/


void Game::is_book(int p){
    bool n;
    bool m;
    int arr[4];
    int b_count = 0;
    int count = 0;

    //count the number of card that have the same rank
    for (int i = 0; i < this->Players[p].get_n(); i++){
        count = 0;
        
        for (int j = 0; j < this->Players[p].get_n(); j++){
            n = this->Players[p].get_rank(i).compare(this->Players[p].get_rank(j));
            if (n == 0){
                count += 1;
                // cout << "C#" << endl;
            }
        }

        
        //if there is a book then increase the number of book by 1 and lay down the cards
        if (count == 4){
            b_count = 0;
            cout << "Found a book" << endl;  /*of  << this->Players[p].get_rank(i) << endl; */
            this->Players[p].set_books(this->Players[p].get_rank_num(i));
            for (int l = 0; l < this->Players[p].get_n(); l++){
                m = this->Players[p].get_rank(l).compare(this->Players[p].get_rank(i));
                if(m == 0){
                    arr[b_count] = l;
                    b_count += 1;
                }
            }
        
            for (int f = 0; f < b_count; f++){
                this->Players[p].give(arr[f]-1*f);
            }       
            
        }

        for (int i = 0; i < 4; i++){
            arr[i] = 0;
        }
    }


    //print the books and number of books for each player
    if (p == 0){
        cout << "Player's book: " << this->Players[0].get_num_book() << endl;
        cout << "Books: ";
        this->Players[0].print_book();
        
        cout << endl;
    }
    else{
        cout << "Bot's book: " << this->Players[1].get_num_book() << endl;
    }
}


/*********************************************************************
** Function: compare()
** Description: compare the total books of players.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::compare(){

    //determine which player win or tie
    if (this->Players[0].get_num_book() > this->Players[1].get_num_book()){
        cout << "Player wins with " << this->Players[0].get_num_book() << " books" << endl;
    }
    else if (this->Players[0].get_num_book() < this->Players[1].get_num_book()){
        cout << "Bot wins with " << this->Players[1].get_num_book() << " books" << endl;
    }
    else{
        cout << "TIE!!!" << endl;
        cout << "Both players got " << this->Players[0].get_num_book() << " books" << endl;
    }
}

/*********************************************************************
** Function: play(int i)
** Description: Run the game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: none
** Return: None
*********************************************************************/

void Game::play(int i){

    // normal mode
    if (i == 1){
        while(get_num_card() != 0){
            do{
                check();
                is_book(0);
            }while(this->is_correct);
            
            press_enter();
            cout << "Turn changes" << endl;
            
            do{
                bot_check();
                is_book(1);    
            }while(this->is_correct);
            
        }
        cout << "The game has end! " << endl;
        compare();
    }


    //debug mode
    else if(i == 2){
        while(get_num_card() != 0){
            do{
                check_debug();
                is_book_debug(0);
            }while(this->is_correct);
            
            press_enter();
            cout << "Turn changes!!!!!!" << endl;
            
            do{
                bot_check_debug();
                is_book_debug(1);    
            }while(this->is_correct);
            
        }
        cout << "The game has end! " << endl;
        compare();
    }

    //advance bot mode
    else if(i == 3){
        while(get_num_card() != 0){
            do{
                check();
                is_book(0);
            }while(this->is_correct);
            
            press_enter();
            cout << "Turn changes" << endl;
            
            do{
                bot_check_advance();
                is_book(1);    
            }while(this->is_correct);
            
        }
        cout << "The game has end! " << endl;
        compare();
    }
}