// GameBoard.hpp
// CPSC 131, Fall 2016, Project 2
//
// Class that constructs the gameboard for chutes and ladders
//
// Name: Richard Ung
// Due:  November 11, 2016

#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <stdexcept>

#include "ExtendableVector.h"

const int OUTSIDE_BOARD = -1;
const int BOARD_SIZE = 101;

class GameBoard {
public:
	enum Ladders { ONE = 1, FOUR = 4, NINE = 9, TWENTY_ONE = 21, TWENTY_EIGHT = 28, THIRTY_SIX = 36, FIFTY_ONE = 51, SEVENTY_ONE = 71, EIGHTY = 80 };

	enum Chutes { SIXTEEN = 16, FORTY_SEVEN = 47, FORTY_NINE = 49, FIFTY_SIX = 56, SIXTY_TWO = 62, SIXTY_FOUR = 64, EIGHTY_SEVEN = 87, NINETY_THREE = 93, NINETY_FIVE = 95, NINETY_EIGHT = 98 };

	// Build the gameboard
	void buildBoard();

	GameBoard() { buildBoard(); }

	// If player lands on chutes or ladders, returns the new position.
	// Otherwise, returns the player's current position.
	// If the player's position is outside of the gameboard, throws index out of bounds exception
	int checkChutesLadders(int position) {
		if ((position < 0) || (position >= BOARD_SIZE)) {
			throw range_error("index out of bounds");
		}
		return _posList[position];
	}

private:
	ExtendableVector<int> _posList;
};

#endif
