include <iostream>


enum Day
{
	Saturday, 
	Sunday=0, 
	Monday, 
	Tuesday, 
	Wednesday, 
	Thursday, 
	Friday};

void Print(Day day) {
	if (day == 0) {
		std::cout << "Weekend" << std::endl;
	}
	else {
		std::cout << "Weekday" << std::endl;
	}
}

int main() {
	enum Fruit 
	{
		apple, 
		pear, 
		orange, 
		banana} frt1;

	typedef Fruit ShuiGuo;

	enum Fruit frt2 = apple;

	ShuiGuo frt3 = pear;

	for (int i = apple; i <= banana; i++) {
		switch (i) {
		case apple:
			std::cout << "apple" << std::endl;
			break;
		case pear:
			std::cout << "pear" << std::endl;
			break;
		case orange:
			std::cout << "orange" << std::endl;
			break;
		case banana:
			std::cout << "banana" << std::endl;
			break;
		default:
			break;
		}

		Print(Monday);
		Print(Tuesday);
		Print(Wednesday);
		Print(Thursday);
		Print(Friday);
		Print(Saturday);
		Print(Sunday);
	}
	system("pause");
	return 0;

}

// other example of using enum

int main() {
	enum weekday 
	{
		sun = 1, 
		mon, 
		tue,
		wed, 
		thu, 
		fri, 
		sat} day;
	int k;
	std::cout << "Please enter what date of today(1--7): ";
	std::cin >> k;

	day = (enum weekday)k;

	switch (day) {
	case mon:
	    std::cout << "Today have to work." << std::endl;
		break;
	case tue:
	    std::cout << "Today have to work." << std::endl;
		break;
	case wed:
	    std::cout << "Today have to work." << std::endl;
		break;
	case thu:
	    std::cout << "Today have to work." << std::endl;
		break;
	case fri:
	    std::cout << "Today have to work." << std::endl;
		break;
	case sat:
		std::cout << "Today have no work." << std::endl;
	    break;
	case sun:
	    std::cout << "Today have no work." << std::endl;
	    break;
	default:
		std::cout << "enter error" << std::endl;
	}
	return 0;
}
