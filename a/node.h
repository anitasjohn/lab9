#ifndef NODE_H_
#define NODE_H_

typedef int ListItem;

class Node {
private:
    ListItem item;
    Node *next;
public:
    Node(const ListItem& itemA): item(itemA), next(nullptr){}
    const ListItem& get_item()const {return item;}
    ListItem& get_item() {return item;}
    Node* get_next()const {return next;}
    void set_item(const ListItem& value){item = value;}
    void set_next(Node* n);
};
#endif
