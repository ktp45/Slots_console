#include "Board.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

Board::Board()
{
	r1 = r2 = r3 = r4 = r5 = CircularLinkedList(); // default const in case
}

Board::Board(const CircularLinkedList& source)
{
	r1 = r2 = r3 = r4 = r5 = source; //all reels are the same
}

Board::~Board()
{
	delete &r1; //destructor
	delete &r2; // & since it expects poiner to list
	delete &r3;
	delete &r4;
	delete &r5;
}

void Board::print() // printing the board
{
	cout << *r1.get_root() << *r2.get_root() << *r3.get_root() << *r4.get_root() << *r5.get_root() << endl;  // * since we want the data not the address
	cout << *r1.get_second() << *r2.get_second() << *r3.get_second() << *r4.get_second() << *r5.get_second() << endl;
	cout << *r1.get_third() << *r2.get_third() << *r3.get_third() << *r4.get_third() << *r5.get_third() << endl;
}

void Board::random_spin_board()
{
	srand (time(NULL)); // taking random seed in time
	r1.spin(rand()%100); // spining each reel by rand number
	r2.spin(rand()%100);
	r3.spin(rand()%100);
	r4.spin(rand()%100);
	r5.spin(rand()%100);
}

float Board::line1() // calculates the winnings of each line
{ 																// line 1 starts from the top symbol of 1st reel and is like V
	float multiplier = min({r1.get_root() -> data.get_multiplier(), r2.get_second() -> data.get_multiplier(),
		r3.get_third() -> data.get_multiplier(), r4.get_second() -> data.get_multiplier(), r5.get_root() -> data.get_multiplier()});
	float m3 = multiplier*3,  m4 =  multiplier*4 ,  m5 =  multiplier*5; //  the min of the multipliers is needed not the wild one which usually is bigger
	if (five_equal(r1.get_root(), r2.get_second(), r3.get_third(), r4.get_second(), r5.get_root()))
		return m5;
	if (four_equal(r1.get_root(), r2.get_second(), r3.get_third(), r4.get_second()))
		return m4;
	if (three_equal(r1.get_root(), r2.get_second(), r3.get_third()))
		return m3;
	return 0;

}
float Board::line2() // line 2 starts from the second symbol of 1st reel and is a straight line
{
	float multiplier  =  min({r1.get_second() -> data.get_multiplier(), r2.get_second() -> data.get_multiplier(),
		r3.get_second() -> data.get_multiplier(), r4.get_second() -> data.get_multiplier(), r5.get_second() -> data.get_multiplier()});
	float m3 = multiplier*3,  m4 =  multiplier*4 ,  m5 =  multiplier*5; //  the min of the multipliers is needed not the wild one which usually is bigger
	if (five_equal(r1.get_second(), r2.get_second(), r3.get_second(), r4.get_second(), r5.get_second()))	
		return m5;
	if (four_equal(r1.get_second(), r2.get_second(), r3.get_second(), r4.get_second()))
		return m4;
	if (three_equal(r1.get_second(), r2.get_second(), r3.get_second()))
		return m3;
	return 0;
}
float Board::line3() // line 3 is line 1 but rotated 180 degrees
{
	float multiplier  =  min({r1.get_third() -> data.get_multiplier(), r2.get_second() -> data.get_multiplier(),
		r3.get_root() -> data.get_multiplier(), r4.get_second() -> data.get_multiplier(), r5.get_third() -> data.get_multiplier()});
	float m3 = multiplier*3,  m4 =  multiplier*4 ,  m5 =  multiplier*5; //  the min of the multipliers is needed not the wild one which usually is bigger
	if (five_equal(r1.get_third(), r2.get_second(), r3.get_root(), r4.get_second(), r5.get_third()))
		return m5;
	if (four_equal(r1.get_third(), r2.get_second(), r3.get_root(), r4.get_second()))
		return m4;
	if (three_equal(r1.get_third(), r2.get_second(), r3.get_root()))
		return m3;
	return 0;
}
