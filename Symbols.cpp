#include <iostream>
#include "Symbols.h"
using namespace std;
Symbol::Symbol()
{
	name = 0;
	multiplier = 0; //defaults just in case
	isWild = 0;
}

Symbol::Symbol(char nam,float multi,bool isw = 0)
{
	name = nam;
	multiplier = multi; // the usual type of constructor used in the project
	isWild = isw;
}

Symbol::Symbol(const Symbol& other)
{
	name = other.name;
	multiplier = other.multiplier; //copy just in case
	isWild = other.isWild;
}

Symbol& Symbol::operator=(const Symbol& other)
{
	 if (this  =  =  &other)
        return *this;

    this -> name = other.name;
    this -> multiplier = other.multiplier; // operator  =  same as above
    this -> isWild = other.isWild;
    return *this;
}

char Symbol::get_name()
{
	return name;
}

float Symbol::get_multiplier()
{
	return multiplier;
}

bool Symbol::get_isWild()
{
	return isWild;
}
