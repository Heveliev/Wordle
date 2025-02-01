// conclusion.cpp -- output of successful outcome and number of attempts

#include <iostream>

void conclusion(const int& quantity_attempts)
{
	std::cout << "Congratulations you guessed the word!" << std::endl;
	std::cout << "You made" << ' ' << quantity_attempts << ' ' << "tries!" << std::endl;
}