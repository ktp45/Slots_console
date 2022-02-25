#include "Node.cpp"

class CircularLinkedList // list of nodes, in which the last one points to the first
{
	Node* root;
	int size;
	public:
	CircularLinkedList();
	CircularLinkedList(const CircularLinkedList&);
	CircularLinkedList& operator=(const CircularLinkedList&);
	~CircularLinkedList(); // it has to allocate memory so these four are must
	Node* get_root();
	Node* get_second();
	Node* get_third();
	Node* get_last(); // bunch of get functions for ease of access
	int get_size();
	void add(Symbol);
	void spin(int);		//function which rotates the list num of times

};
