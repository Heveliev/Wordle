// get_random_index.cpp -- choosing a random index depending on the size of the array of words

#include <cstdlib>

int get_random_index(const int& size)
{
	return rand() % size;
}