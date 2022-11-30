//
//  SimpleList.h
//

#ifndef Lab9_Simple_List__SimpleList__
#define Lab9_Simple_List__SimpleList__
#include "node.h"


class SimpleList {
private:
    Node *headM;
    int sizeM;
    void destroy();
    void copy(const SimpleList& source);
public:
    
    SimpleList(): headM(0), sizeM(0) {}
    // PROMISES: creates empty list.
    
    SimpleList(const SimpleList& source) { copy(source); }// copy constructor
    
    SimpleList& operator =(const SimpleList& rhs);  // assignment operator
    
    ~SimpleList() { destroy(); }   // destructor
    
    int size() const {return sizeM;}
    
    void push_back(const ListItem& item);
    // PROMISES:
    //    Adds a node with an item to the end of the list, and increments sizeM
    
    void push_front(const ListItem& item);
    // PROMISES:
    //    Adds a node with an item to the beginning of the list, and increments
    //    sizeM
    void pop_back(const ListItem& item);
    // PROMISES:
    //    The last node int list is removed
    
    const ListItem& at(int n)const;
    // PROMISES:
    //    An item is return at the nth position in the list.
    //    if n is less than 0 or greater than or equal sizeM gives the error
    //    message: "Illegal Access" and terminates the program
    
    ListItem& at(int n);
    // PROMISES:
    //    An item is return at the nth position in the list.
    //    if n is less than 0 or greater than or equal sizeM gives the error
    //    message: "Illegal Access" and terminates the program
    
    void insert(const ListItem& theItem, int n);
    // PROMISES:
    //    A node with a copy of theItem is inserted at the nth position, and sizeM
    //    will be incremented if the operation of insert was successfull.
    //    if n == sizeM calles push_back
    //    if n == 0 calls push_front
    //    if n < 0 or n > sizeM returns and does nothing.
    
    void remove(int n);
    //  PROMISES:
    //    Does nothing if n < 0 or n > sizeM-1. Otherwise, if list is not empty
    //    removes the node at the position n.
};

#endif /* defined(Lab9_Simple_List__SimpleList__) */
