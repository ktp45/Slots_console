#include "CircularLinked.cpp"

class Board //the slots machine display made by 5 columns each an equal list
{
	CircularLinkedList r1, r2, r3, r4, r5;
	public:
	Board();
	Board(const CircularLinkedList&);
	~Board();
	void print();
	void random_spin_board(); //spins all by a random number
	float line1(); //checking winnings on lines
	float line2(); // if there are a lot lines this can be an universal func
	float line3();
};
