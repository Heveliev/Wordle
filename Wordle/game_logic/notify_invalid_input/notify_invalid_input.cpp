// notify_invalid_input.cpp -- output validation error

#include <iostream>

#include "../../Config.h"


void notify_invalid_input(Validation validated)
{
    switch (validated) 
    {
    case Validation::Empty:
        std::cout << "Contents cannot be empty." << std::endl;
        break;
    case Validation::Less:
        std::cout << "Shorter than necessary." << std::endl;
        break;
    case Validation::Digit:
        std::cout << "Cannot be a number." << std::endl;
        break;
    case Validation::SpecialSymbol:
        std::cout << "Cannot be a special character or the character you entered." << std::endl;
        break;
    case Validation::Larger:
    case Validation::ExitSymbol:
    case Validation::Validated:
        break;
    default:
        std::cout << "Unexpected result, contact the developer." << std::endl;
        break;
    }
}