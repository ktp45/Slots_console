
class Symbol // each symbol has name, in-game multiplier and can be the universal symbol (wild)
{
	char name;
	float multiplier;
	bool isWild;
	public:
	Symbol();
	Symbol(char, float, bool);
	Symbol(const Symbol&);
	Symbol& operator= (const Symbol&);	
	char get_name();	// getters for encapsulation
	float get_multiplier();
	bool get_isWild();

};
