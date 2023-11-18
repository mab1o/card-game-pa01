// tests.cpp
// Author: Margaux Blondel
// These files should contain test code for all the classes and methods you used in your game. We recommend at least 5 test cases for each public member function.

#include <iostream>
#include <fstream>
#include <cstring>
#include "cards.h"
#include "cardsbst.h"

using namespace std;

/*
c, d, s, h
a, 2,3, 4, 5, 6, 7, 8, 9, 10, j, q, k
*/

int main(int argv, char** argc){
    
    cout << endl << "---------------TESTS----------------" << endl;

    // cards tests
    cout << endl << "---------------CARDS----------------";
    
    // create cards
    cout << endl << "Create card : c a";
    Card a('c',"a");
    a.printControl();

    cout << endl << "Create card : h 10";
    Card b('h',"10");
    b.printControl();

    cout << endl << "Create card : c 10";
    Card c('c',"10");
    c.printControl();

    cout << endl << "Create card : d q";
    Card d('d',"q");
    d.printControl();

    //Copy constructor
    cout << endl << "Create card : h q";
    Card e('h',"q");
    e.printControl();
    cout << endl << "Create a copie : ";
    Card f(e);
    f.printControl();
    
    // operators cards
    
    // <
    cout << endl << "c 10 < c a ?   : " ;
    cout << (c < a) << " (except false)";

    cout << endl << "c 10 < h 10 ?  : " ;
    cout << (c < b) << " (except true)";
    
    cout << endl << "c a < c a ?    : " ;
    cout << (a < a) << " (except false)";
    
    // >
    cout << endl << "c 10 > c a ?   : " ;
    cout << (c > a) << " (except true)";

    cout << endl << "c 10 > h 10 ?  : " ;
    cout << (c > b) << " (except false)";
    
    cout << endl << "c a > c a ?    : " ;
    cout << (a > a) << " (except false)";
    
    // =
    cout << endl << "c 10 == c a ?  : " ;
    cout << (c == a) << " (except false)";

    cout << endl << "c 10 == h 10 ? : " ;
    cout << (c == b) << " (except false)";

    cout << endl << "c a == c a ?   : " ;
    cout << (a == a) << " (except true)";

    cout << endl << "-------------END-CARDS--------------" << endl;

    // BST tests
    cout << endl << "---------------CARDBST--------------";

    cout << endl << "Create BST : c a , h 10, c 10" ;
    
    // create a tree
    CardsBST tree;
    tree.insert(a);
    tree.insert(b);
    tree.insert(c);
    cout << endl << "PreOrder   : ";
    tree.printPreOrder();
    cout << endl << "InOrder    : ";
    tree.printInOrder();

    // number of Node in the tree
    cout << endl << "Number of Node : " << tree.count();

    //Predecessor and sucessor
    cout << endl << "Values      : " ;
    Card listCards[3]={a, b, c};
    for (Card ca : listCards){
        ca.print();
        cout << " | ";
    }

    cout << endl << "Predecessor : ";
    for (Card ca : listCards){
        tree.getPredecessor(ca).print();
        cout << " | ";
    }

    cout << endl << "Successor   : ";
    for (Card ca : listCards){
        tree.getSuccessor(ca).print();
        cout << " | ";
    }

    cout << endl << "-------------END-CARDBST------------" << endl;

    cout << endl << "-------------END-TESTS--------------" << endl;

    return 0;
}