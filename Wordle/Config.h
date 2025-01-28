#pragma once

class Config
{
public:
		static constexpr int EXIT = 0;

		static constexpr int MODE_DAILY = 1;
		static constexpr int MODE_RANDOM = 2;



};

enum class GameState
{
	NotStarted,
	InProgress,
	End
};


enum class Complexity
{
	Low,
	Medium,
	High,
	VeryHigh
};