#include "CircularLinked.h"

CircularLinkedList::CircularLinkedList() //default just in case
{
	root = new Node();
	root -> next = root;
	size = 0;
}

CircularLinkedList::CircularLinkedList(const CircularLinkedList& other) // copy const
{
	if (other.size == 0)
	{
		CircularLinkedList(); // check if other is empty
	}
	else
	{
		root = new Node();
		size = 0;

		Node* temp  =  new Node(); //creation of new one using temporary to move through the other one
		temp = other.root;
		temp -> next = other.root -> next;
		add(temp -> data);

		while(temp -> next! = other.root)
		{
			temp = temp -> next;
			add(temp -> data);
		}

		delete[]temp;
	}

	get_last() -> next = root;
}

CircularLinkedList& CircularLinkedList::operator = (const CircularLinkedList& other) // operator  =
{
	if (&other != this)
	{
	  delete this;
		if (other.size == 0) // same as above but deleting the old list and checking also if they are already the same
		{
			CircularLinkedList();
		}
		else
		{
		root = new Node();
		size = 0;

		Node* temp  =  new Node();
		temp  =  other.root;
		temp -> next = other.root -> next;
		add(temp -> data);
		while(temp -> next! = other.root)
			{
				temp = temp -> next;
				add(temp -> data);
			}
		delete[]temp;
		}
		get_last() -> next = root;
	}


	return *this;
}

CircularLinkedList::~CircularLinkedList() //destructor
{
	Node* temp = get_root() -> next;
	Node* temp2;
	delete[]root;
	size--;
	while (size > 0)
	{
		temp2 = temp -> next;
		delete[]temp;
		temp = temp2;
		size--;
	}
}

Node* CircularLinkedList::get_root()
{
	return root;
}

Node* CircularLinkedList::get_second()
{
	return root -> next;
}

Node* CircularLinkedList::get_third()
{
	Node* second = root -> next;
	return second -> next;
}

Node* CircularLinkedList::get_last() //ease of access
{
	Node* last  =  get_root();
	int br = 1;
	while(br<size)
	{
		last = last -> next;
		br++;
	}
	return last;
}

int CircularLinkedList::get_size()
{
	return size;
}

void CircularLinkedList::add(Symbol x) // adding a new node at the end of the list
{
	if(size == 0) // check if the list is empty
	{
		delete[]root;
		root = new Node(x, root);
		size++;
	}
	else
	{
		Node* temp = new Node(x, root);
		get_last() -> next = temp;
		size++;
	}
}

void CircularLinkedList::spin(int times)
{
	while(times !=  0) //rotatin by moving the root pointer
	{
	 	root = root -> next;
		times--;
	}
}
