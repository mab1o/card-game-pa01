#include <iostream>
#include <fstream>
#include <string>

#include "cards.h"
#include "utility.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  // Create Alice and Bob BST
  CardsBST alice;
  CardsBST bob;
  
  // Read files
  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Read Alice file
  while (getline (cardFile1, line) && (line.length() > 0)){
      Card a = getCard(line);
      alice.insert(a);
  }
  cardFile1.close();

  // Read Bob file
  while (getline (cardFile2, line) && (line.length() > 0)){
      Card b = getCard(line);
      bob.insert(b);
  }
  cardFile2.close();

  // Create Alice and Bob final BST
  CardsBST bob_final;
  CardsBST alice_final;
  CardsBST matching_card;

  // start of the game
  const int cpt_end_alice = alice.count() + 1; // number of card of each player
  const int cpt_end_bob = bob.count() + 1;
  int cpt_alice = 1;
  int cpt_bob = 1;

  while(cpt_alice < cpt_end_alice || cpt_bob < cpt_end_bob){  // iterate until all card have been seen

    // Alice turn
    bool bob_has_card   = false;
    bool already_found  = true;

    while((!(bob_has_card) || already_found) && cpt_alice < cpt_end_alice){
      Card alice_card = alice.cardInPosition(cpt_alice);      // choose the i card in order of Alice BST
      bob_has_card    = bob.contains(alice_card);             // search if Bob has the card
      already_found   = matching_card.contains(alice_card);

      if (bob_has_card && !already_found){                    // if Bob has the card print message 
        cout << "Alice picked matching card "; 
        alice_card.print();
        cout << endl;
        matching_card.insert(alice_card);
      } else if (!already_found) {                            // else add the card to Alice final BST
        alice_final.insert(alice_card);
      }
      cpt_alice++;
    }

    // Bob turn
    bool alice_has_card = false;
    already_found  = true;

    while((!alice_has_card || already_found) && cpt_bob < cpt_end_bob){
      Card bob_card   = bob.cardInPositionReverse(cpt_bob);   // choose the i card in reverse order of Bob BST
      alice_has_card  = alice.contains(bob_card);             // search if Alice has the card
      already_found   = matching_card.contains(bob_card);

      if (alice_has_card && !already_found){                  // if Alice has the card print message 
        cout << "Bob picked matching card ";
        bob_card.print();
        cout << endl;
        matching_card.insert(bob_card);
      } else if (!already_found){                             // else add the card to Bob final BST
        bob_final.insert(bob_card);
      }
      cpt_bob++;
    }
  }
  // end of the game
  
  // print Alice final card at the end
  cout << endl << "Alice's cards:" << endl;
  const int cpt_alice_final = alice_final.count() + 1;

  for (int i = 1 ; i < cpt_alice_final; i++){
    Card alice_card = alice_final.cardInPosition(i);
    alice_card.print();
    cout << endl;
  }
  
  // print Bob final card at the end
  cout << endl << "Bob's cards:";
  const int cpt_bob_final = bob_final.count() + 1;

  for (int i = 1 ; i < cpt_bob_final ; i++){
    Card bob_card = bob_final.cardInPosition(i);
    cout << endl;
    bob_card.print();
  }

  return 0;
}
