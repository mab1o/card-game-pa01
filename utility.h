// utility.h
// Author: Margaux Blondel

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iostream>
#include "cards.h"

Card getCard(std::string st);                       // create a card with information provided by a string
std::ostream& operator<<(std::ostream& out, Card x);// helper to print Card

class CardsBST {

public:
   CardsBST();                                      // constructor
   ~CardsBST();                                     // destructor
   bool insert(Card value);                         // insert a Node in the tree
   void printPreOrder() const;                      // print the tree in PreOrder
   void printInOrder() const;                       // print the tree in InOrder
   void printPostOrder() const;                     // print the tree in PostOrder
   int count() const;                               // count the number of Node in the tree
   bool contains(Card value) const;                 // search in the tree if it is containt the card
   Card getPredecessor(Card value) const;           // give the predecessor of a chosen card
   Card getSuccessor(Card value) const;             // give the successor of a choosen card
   bool remove(Card value);                         // remove a choosen Node of the tree
   Card cardInPosition(int value) const;            // give a the card in position value for a tree in order
   Card cardInPositionReverse(int value) const;     // give a the card in position value for a tree in reverse order

private:

   // attributes
   struct Node {
      Card info;
      Node *left, *right, * parent;
      Node(Card v) : info(v), left(0), right(0), parent(0){}
   };
   Node *root;

   // functions
   Node* getNodeFor(Card value, Node* n) const;     // search a Node and return its reference
   bool simpleRemove(Node* n);                      // remove Node in simple case
   Node* bstmax() const;                            // give the max value in the tree
   Node* bstmin() const;                            // give the min value in the tree

   // helper functions of public functions above
   void clear(Node *n);
   bool insert(Card value, Node *n);
   void printPreOrder(Node *n) const;
   void printInOrder(Node *n) const;
   void printPostOrder(Node *n) const;
   int count(Node *n) const;
   Node* getSuccessorNode(Card value) const;
   Node* getPredecessorNode(Card value) const;
};

#endif
