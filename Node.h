#include "Symbols.cpp"

struct Node
{    // nodes part of the linked list
	Symbol data;
    Node *next;
    Node();
    Node(const Symbol&,Node*);
    Node(const Node&);
};
