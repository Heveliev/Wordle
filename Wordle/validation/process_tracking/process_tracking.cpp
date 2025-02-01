// process_tracking.cpp -- game state tracking function

#include "../../Config.h"

GameState process_tracking(const int& input)
{
	switch (input)
	{
	case Config::EXIT:
		return GameState::End;
	case Config::MODE_DAILY:
	case Config::MODE_RANDOM:
		return GameState::InProgress;
	default:
		return GameState::NotStarted;
	}
}