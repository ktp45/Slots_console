#include "Node.h"

Node::Node()
{
	data = Symbol(); //defaults just in case
	next = NULL;
}
Node::Node(const Symbol& a, Node *n) //constructor by data and next node the mainly used one
{
	data = a;
	next = n;
}
Node::Node(const Node& other) // copy const just in case
{
	data = other.data;
	next = other.next;
}

bool operator==(Node th,Node other) // comparison between two nodes, since the universal node should be equal to all others
{
	if (th.data.get_name() == other.data.get_name())
		return 1;
	else if (th.data.get_isWild() || other.data.get_isWild())
		return 1;

  return 0;
}

bool three_equal(const Node* first, const Node* second, const Node* third) //comparison between three nodes
{
	if(*first == *second && *second == *third && *third == *first)
		return 1;
	return 0;
}

bool four_equal(const Node* first,c onst Node* second, const Node* third, const Node* fourth) //comparison between four nodes
{
	if(three_equal(first, second, third)& *fourth == *first && *fourth == *second && *fourth == *third)
		return 1;

	return 0;
}

bool five_equal(const Node* first,const Node* second,const Node* third,const Node* fourth,const Node* fifth) //comparison between five nodes
{
	if(four_equal(first,second,third,fourth)& *fifth == *first && *fifth == *second && *fifth == *third && *fifth == *fourth)
		return 1;
	return 0;
}

std::ostream& operator<<(ostream &out,const Node& c) //the nodes is printed as (' node name')
{
	Symbol temp = c.data;
	out << "(" << temp.get_name() << ")";
  return out;
}
