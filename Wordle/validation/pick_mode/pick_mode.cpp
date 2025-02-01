// pick_mode.cpp -- select game mode

#include "../../Config.h"

GameMode pick_mode(const int& input)
{
	switch (input)
	{
	case Config::MODE_DAILY:
		return GameMode::Daily;
	case Config::MODE_RANDOM:
		return GameMode::Random;
	default:
		return GameMode::Unknown;
	}
}