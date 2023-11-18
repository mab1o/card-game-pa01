// cards.h
// Author: Margaux Blondel

#ifndef CARDS_H
#define CARDS_H

#include <string>


class Card{
public:
    Card(char character, std::string number);
    Card(Card* c); 
    ~Card();

    //operators
    bool operator==(Card c) const;
    bool operator<(Card c) const;
    bool operator>(Card c) const;
    Card operator=(Card c);

    //print functions
    void printControl() const;
    void print() const;

private:
    // attributes
    int character;
    int number;

    // conversions of the attributes
    int characterToInt(char character) const;
    char intToCharacter(int character) const;
    int numberToInt(std::string number) const;
    std::string intToNumber(int number) const;
};

#endif
