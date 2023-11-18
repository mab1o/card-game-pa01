// intbst.cpp
// Margaux Blondel, 26/10/2023

#include <iostream>
#include "cardsbst.h"
#include "cards.h"

using namespace std;


ostream& operator<<(ostream& out, Card x){
       x.print();
       return out;
}

// constructor sets up empty tree
CardsBST::CardsBST() { 
    root = nullptr;
}

// destructor deletes all nodes
CardsBST::~CardsBST() {
    clear(root);
    root = nullptr;
}

// recursive helper for destructor
void CardsBST::clear(Node *n) {
    if (!n){return;}

    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool CardsBST::insert(Card value) {
    if (!root){
        root = new Node(value);
        return true;
    }
    bool notDuplicate = insert(value, root);
    return notDuplicate ;
}

// recursive helper for insert (assumes n is never 0)
bool CardsBST::insert(Card value, Node *n) {
    // egal value
    if (n->info == value){
        return false;
    }

    // value inferior
    else if (n->info > value){
        if (n->left) {
            return insert(value, n->left);
        }
        else{
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    }

    // value superior
    else{
        if (n->right) {
            return insert(value, n->right);
        }
        else{
            n->right= new Node(value);
            n->right->parent = n;
            return true;
        }
    }
}

// print tree data pre-order
void CardsBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void CardsBST::printPreOrder(Node *n) const {
    if (!n) {return;}
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void CardsBST::printInOrder() const {
    printInOrder(root);
}

void CardsBST::printInOrder(Node *n) const {
    if (!n) {return;}
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void CardsBST::printPostOrder() const {
    printPostOrder(root);
}

void CardsBST::printPostOrder(Node *n) const {
    if (!n) {return;}
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

// return count of values
int CardsBST::count() const {
    return count(root);
}

// recursive helper for count
int CardsBST::count(Node *n) const {
    if (!n) {return 0;}
    return 1 + count(n->left) + count(n->right);
}

CardsBST::Node* CardsBST::getNodeFor(Card value, Node* n) const{
    if (!n) {return nullptr;}
    
    // egal value
    if (n->info == value){
        return n;
    }
    // value inferior
    else if (n->info > value){
        return getNodeFor(value, n->left);
    }
    // value superior
    else{
        return getNodeFor(value, n->right);
    }
}

// returns true if value is in the tree; false if not
bool CardsBST::contains(Card value) const {
    return getNodeFor(value, root);
}

// returns the Node containing the predecessor of the given value
CardsBST::Node* CardsBST::getPredecessorNode(Card value) const{
    Node* n = root;
    Node* pre = nullptr;
    
    while(n){
        if (n->info < value){
            pre = n;
            n = n->right;
        }
        else {
            n = n->left;
        }
    }

    return pre;
}

// returns the predecessor value of the given value or 0 if there is none
Card CardsBST::getPredecessor(Card value) const{
    Node* n = getPredecessorNode(value);
    if (!n){
        return Card('0',"0");
    } else {
        return n->info;
    }
}

// returns the Node containing the successor of the given value
CardsBST::Node* CardsBST::getSuccessorNode(Card value) const{
    Node* n = root;
    Node* suc = nullptr;
    
    while(n){
        if (n->info > value){
            suc = n;
            n = n->left;
        }
        else {
            n = n->right;
        }
    }

    return suc;
}

// returns the successor value of the given value or 0 if there is none
Card CardsBST::getSuccessor(Card value) const{
    Node* n = getSuccessorNode(value);
    if (!n){
        return Card('0',"0");
    } else {
        return n->info;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool CardsBST::remove(Card value){
    Node* n = getNodeFor(value, root);
    if (!n){return false;}

    if (!n->left || !n->right){             //case 1 and 2
        return (simpleRemove(n));

    } else {                                      // case 3
        Node* suc = getSuccessorNode(value);
        Card c('s',"2");
        Node* temp = new Node(c);

        // UPDATE TEMP : copie of n
        temp->parent = n->parent;
        temp->right = n->right;
        temp->left = n->left;

        if (temp->parent){
            if (temp->parent->left == n){
                temp->parent->left = temp;
            }else{
                temp->parent->right = temp;
            }
        }
        
        // UPDATE N
        // update of n : suc left, right
        n->left = suc->left;
        if (n->left){
            n->left->parent = n;
        }
        n->right = suc->right;
        if (n->right){
            n->right->parent = n;
        }

        // update of n : suc parent
        if (suc->parent != n){
            n->parent = suc->parent;
            if (n->parent->left == suc){
                n->parent->left = n;
            }else{
                n->parent->right = n;
            }
        }else{
            n->parent = suc; 
            suc->right = n;
        }

        // UPDATE SUC
        // update suc : suc left, right
        if (suc->right != n){
            suc->right = temp->right;
        }
        suc->right->parent = suc;
        suc->left = temp->left;
        suc->left->parent = suc;

        // update suc : suc parent
        suc->parent = temp->parent;
        if (temp->parent){
            if (suc->parent->left == temp){
                suc->parent->left = suc;
            }else{
                suc->parent->right = suc;
            }
        }else {
            root = suc;
        }

        delete temp;
        return (simpleRemove(n));
    }
}

//remove a node when case 1 or 2
bool CardsBST::simpleRemove(Node* n){
    if (n->left){ // case 2 : n has a left child
        //update n->left
        n->left->parent = n->parent;

        // update n->parent if parent exist
        if (n->parent){
            if (n->parent->left == n){
                n->parent->left = n->left;
            }else{
                n->parent->right = n->left;
            }
        } else {
            root = n->left;
        }

    } else if (n->right){ // case 2 : n has a right child
        
        //update n->right
        n->right->parent = n->parent;

        // update n->parent if parent exist
        if (n->parent){
            if (n->parent->left == n){
                n->parent->left = n->right;
            }else{
                n->parent->right = n->right;
            }            
        } else {
            root = n->right;
        }

    } else { // Case 1 : n is a leaf
        if (n->parent){
            if (n->parent->left == n){
                n->parent->left = nullptr;
            }else{
                n->parent->right = nullptr;
            }
        } else {
            root = nullptr;
        }
    }

    delete n;
    return true;
}
