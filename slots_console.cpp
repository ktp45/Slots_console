#include "Board.cpp"
#include <limits>
#include <iomanip>

int main()
{
	Symbol ketchup('k', 200, 1),maio ('m', 1.9),vinegar('v', 1.8),gorchica('g', 1.7); // Symbol creation the theme is sauces
	Symbol barbeque('b', 1.6),ranch('r', 1.5),tabasco('t', 1.4),garlic_sauce('s', 1.3),olive_oil('o', 1.2),sour_cream('c', 1.1);  // odd are in players favor by small

	CircularLinkedList reel1; // creating a list with all them
	reel1.add(ketchup);reel1.add(maio);reel1.add(vinegar);reel1.add(gorchica);reel1.add(barbeque);
	reel1.add(ranch);reel1.add(tabasco);reel1.add(garlic_sauce);reel1.add(olive_oil);reel1.add(sour_cream);

	Board display(reel1); // creating a board with all them

	system("color 0a");
	
	cout << fixed;
    cout << setprecision(2);
  //  cout <<  maio.get_multiplier() * 5 ;

	float money = 0,bet = 0;
	cout << "Enter starting amount money:" << endl; // imagine putting money into the game
	cin >> money;
	while (1)
	{
		if (cin.fail() || money<0)
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');	 //validation
		cout << "Enter valid money!" << endl;
		cin >> money;
		}
		if (!cin.fail())
			break;
	}

	while (1)
	{
		cout << "Place your bet to spin the wheel or press 0 to exit:" << endl;
		cin >> bet;
		while (1)
		{
			if (cin.fail() || bet<0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); 	//validation
				cout << "Enter valid bet!" << endl;
				cin >> bet;
			}
			if (!cin.fail())
				break;
		}

		system("cls");
		if (bet ! =  0 && money > 0 && bet <=  money)
		{
			float first, second, third, total;
			display.random_spin_board();  // spin the board
       		first = display.line1();
       		second = display.line2();
   		    third = display.line3();
       		display.print();  // print it
       		total = bet * first + bet * second + bet * third ; // total winnings if  they exist
	        if (total > 0)
			{
			    if (first > 0)
	                cout << "Line 1:" << bet * first << endl;
	            if (second > 0)
	                cout << "Line 2:" << bet * second << endl;  // shows player which line is the lucky one
	            if (third > 0)
	                cout << "Line 3:" << bet * third << endl;
	            cout << "You win:" << total << endl;
	            money + =  total;
	            cout << "Current money: " << money << endl;
	   		}
	        else
	        {
	            cout << "You lose!" << endl;
	            money -=  bet;  // losing money
	        	cout << "Current money: " << money << endl;
	        }
		}
   		else
   		{
       	 	break;  // if  bet is 0 or there are no money stop the machine
		}
	}

	return 0;
}
