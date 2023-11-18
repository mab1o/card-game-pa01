// cards.cpp
// Author: Margaux Blondel
// Implementation of the classes defined in cards.h

//clubs, diamonds, spades, hearts - -> +
// a 2 3 4 5 6 7 8 9 10 j q k

#include "cards.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

Card::Card(char character, string number) : 
    number(numberToInt(number)), character(characterToInt(character)) {
}

Card::Card(Card* c) : 
    number(c->number), character(c->character) {
}

Card::~Card(){
}

// operators
bool Card::operator==(Card c) const{
    return (number == c.number && character == c.character);
}

bool Card::operator<(Card c) const{
    if (number == c.number){
        return (character < c.character);
    }
    return number < c.number;
}

bool Card::operator>(Card c) const{
    if (number == c.number){
        return (character > c.character);
    }
    return number > c.number;
}

// conversions of the attributes
int Card::characterToInt(char character) const{
    map<char,int> charToInt = {{'c',1}, {'d',2}, {'s',3}, {'h',4}, {'0',0}};
    return charToInt[character];
}

int Card::numberToInt(string number) const{
    map<string,int> stringToInt = {{"a", 1},{"2", 2},{"3", 3},{"4", 4},{"5", 5},{"6", 6},
                    {"7", 7},{"8", 8},{"9", 9},{"10", 10},{"j", 11},{"q", 12},{"k", 13},{"0",0}};
    return stringToInt[number];
}

char Card::intToCharacter(int character) const{
    map<int,char> intToChar = {{1,'c'}, {2, 'd'}, {3, 's'}, {4, 'h'},{0,'0'}};
    return intToChar[character];
}

string Card::intToNumber(int number) const{
    map<int,string> stringToInt = {{1,"a"},{2, "2"},{3, "3"},{4, "4"},{5, "5"},{6, "6"},
                    {7, "7"},{8, "8"},{9, "9"},{10, "10"},{ 11,"j"},{12,"q"},{13,"k"},{0,"0"}};
    return stringToInt[number];
}

// print functions
void Card::printControl() const{
    char strCharatere = intToCharacter(this->character);
    string strNumber = intToNumber(this->number);

    cout << endl << "Card : " << strCharatere;
    cout << " " << strNumber;
    cout << " (" << this->character;
    cout << " " << this->number;
    cout << ")";
}

void Card::print() const{
    char strCharatere = intToCharacter(this->character);
    string strNumber = intToNumber(this->number);
    cout << strCharatere << " " << strNumber;
}
