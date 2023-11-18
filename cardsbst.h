// cardsbst.h
// Author: Margaux Blondel

#ifndef CARDSBST_H
#define CARDSBST_H

#include <string>
#include "cards.h"

class CardsBST {

 public:
    CardsBST();
    ~CardsBST();
    bool insert(Card value);
    void printPreOrder() const;
    void printInOrder() const;
    void printPostOrder() const;
    int count() const;
    bool contains(Card value) const;
    Card getPredecessor(Card value) const;
    Card getSuccessor(Card value) const;
    bool remove(Card value);
    
 private:

    struct Node {
	    Card info;
	    Node *left, *right, * parent;
        Node(Card v) : info(v), left(0), right(0), parent(0){}
    };
    Node *root;

    // recursive utility functions for use by public methods above
    Node* getNodeFor(Card value, Node* n) const;
    void clear(Node *n);
    bool insert(Card value, Node *n);
    void printPreOrder(Node *n) const;
    void printInOrder(Node *n) const;
    void printPostOrder(Node *n) const;
    int count(Node *n) const;

    // these should be used by getPredecessor and getSuccessor
    Node* getSuccessorNode(Card value) const;
    Node* getPredecessorNode(Card value) const;
    bool simpleRemove(Node* n);
};

#endif