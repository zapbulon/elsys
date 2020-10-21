#include <iostream>
#include <stack>
#include <array>
#include <list>
#include <map>

using namespace std;

class Card {
    // Statics come first
    static map<int, string> names;

    // Non-statics afterwards
    int number;
    string suit;

public:
    Card(string suit, int number) {
        this->suit = suit;
        this->number = number;
    }

    void print() {
        this->number < 11 
            ? cout << this->number
            : cout << this->names[this->number];

        cout << " of " << this->suit << endl;
    }
};

// We init the static var outside
map<int, string> Card::names = {
    {11, "Ace"},
    {12, "Jack"},
    {13, "Queen"},
    {14, "King"}
};

int main() {
    stack<Card> deck;
    
    deck.push(Card("diamonds", 13));
    deck.push(Card("spades", 12));
    deck.push(Card("hearts", 4));
    // deck.push(Card("diamonds", 2));

    list<Card> player1;
    list<Card> player2;

    // Let's have an array of pointers to our players
    array<list<Card>*, 2> players = {&player1, &player2};

    try {
        while (!deck.empty()) {
            // We can use `auto` when the type is obvious to the compiler 
            for (auto player: players) {
                if (deck.empty()) {
                    throw string("Deck is empty, you moron!");
                }

                (*player).push_back(deck.top());

                deck.pop();
            }
        }
    } catch (string e) {
        cout << e << endl;
    }
    
    for (int i=0; i < players.size(); i++) {
        cout << endl << endl << "Player " << i << " has: " << endl;

        for (list<Card>::iterator it = (*players[i]).begin(); it != (*players[i]).end(); it++) {
            (*it).print();
        }
    }

    return 0;
}