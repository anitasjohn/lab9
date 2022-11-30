// SimpleList.cpp

#include <iostream>
using namespace std;
#include <stdlib.h>
#include "SimpleList.h"

SimpleList& SimpleList::operator =(const SimpleList& rhs){
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    sizeM = rhs.sizeM;
    return *this;
}

ListItem& SimpleList::at(int n){
    if(n < 0 || n >= sizeM){
        cout << "\n Illigal Access. program Terminates...";
        exit(1);
    }
    Node * p = headM;
    for(int i= 0; i < n; i++)
         p = p->get_next();
    // POINT N - WHEN REACHED FOR THE FIRST TIME
    return p ->get_item();
}

const ListItem& SimpleList::at(int n)const{
    if(n < 0 || n >= sizeM){
        cout << "\n Illigal Access. Program Terminates...";
        exit(1);
    }
    
    const Node * ptr = headM;
    for(int i= 0; i < n; i++)
         ptr = ptr->get_next();
    cout << "reached for the first time\n" << endl;
    // POINT N - WHEN REACHED FOR THE FIRST TIME
    return ptr -> get_item();
}

void SimpleList::push_back(const ListItem& item){
    Node *new_node = new Node(item);
    if(new_node == NULL){
        cout << "\nNo memory available to create a node" << endl;
        exit(1);
    }
    if (headM == 0) {
        new_node->set_next(headM);
        headM = new_node;
    }
    else{
        Node* p = headM;
        while (p ->get_next()  != NULL)
            p = p ->get_next();
        
        p ->set_next(new_node);
    }
    sizeM++;
}


void SimpleList::push_front(const ListItem& item){
    Node *new_node = new Node(item);
    if(new_node == NULL){
        cout << "\nNo memory available to create a node" << endl;
        exit(1);
    }
    new_node->set_next(headM);
    headM = new_node;
    
    // POINT N - WHEN REACHED FOR THE FIRST TIME
    sizeM++;

}

void SimpleList::insert(const ListItem& itemA, int n){
    if(n < 0 || n > sizeM)
        return;
    else if(n == 0)
        push_front(itemA);
    else if(n == sizeM) 
        push_back(itemA);
    else{
        Node *new_node = new Node(itemA);
        if (new_node == NULL) {
            cout << "Sorry memory is unavailable to create an new node.\n";
            return;
        }
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->get_next(); // will be 0 or point to node after new node
        int i = 1;
        while(i < n){
            before = after;
            after = after->get_next();
            i++;
        }
        new_node->set_next(after);
        before->set_next (new_node);
        sizeM++;
    }
}

void SimpleList::destroy(){
    Node* to_delete = headM;
    while(headM != NULL)
    {
        to_delete = headM -> get_next();
        delete headM;
        headM = to_delete;
    }
    headM = 0;
}

void SimpleList::remove(int n){
    if (headM == 0 || n < 0 || n >= sizeM)
        return;
    Node * be_deleted;
    Node* before;
    if(n == 0){
        be_deleted = headM;
        headM = headM ->get_next();
    }
    else{
        before = headM;
        be_deleted = before -> get_next();
        
        int i = 1;
        while (i < n){
            before = be_deleted;
            be_deleted = before -> get_next();
            i++;
        }
        before -> set_next (be_deleted -> get_next());
    }
    delete be_deleted;
    sizeM--;
}

void SimpleList::copy(const SimpleList& source){
    Node* psrc = source.headM;
    if(psrc == NULL)
        return;
    
    Node* pthis = headM;
    while (psrc != NULL){
        Node* copy = new Node(psrc -> get_item());
        if(psrc == source.headM){
            headM = copy;
            pthis = headM;
        }
        else{
            pthis ->set_next (copy);
            // AT THIS POINT WHEN REACHED FOR THE FIRST TIME
            pthis = pthis ->get_next();

        }
        psrc = psrc -> get_next();
    }
   
    sizeM = source.sizeM;

}


