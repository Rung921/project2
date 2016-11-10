// GameBoard.cpp
// CPSC 131, Fall 2016, Project 2
//
// Class that constructs the gameboard for chutes and ladders
//
// Name: Richard Ung
// Due:  November 11, 2016

#include "GameBoard.hpp"

// Build the gameboard
// If the landing square is a chute, set the position to the corresponding lower square
// I.e., player slides down to the lower square
// If the landing square is a ladder, set the position to the corresponding higher square
// Player climbs up to the higher square
// Otherwise, player stays put at the landing square
void GameBoard::buildBoard() {
	// Reserve space and store all default positions
	_posList.reserve(BOARD_SIZE);
	for (int i = 0; i < BOARD_SIZE; i++) {
		_posList.at(i) = i;
	}

	// Store ladder positions
	_posList.at(Ladders::ONE) = 38;
	_posList.at(Ladders::FOUR) = 14;
	_posList.at(Ladders::NINE) = 31;
	_posList.at(Ladders::TWENTY_ONE) = 42;
	_posList.at(Ladders::TWENTY_EIGHT) = 84;
	_posList.at(Ladders::THIRTY_SIX) = 44;
	_posList.at(Ladders::FIFTY_ONE) = 67;
	_posList.at(Ladders::SEVENTY_ONE) = 91;
	_posList.at(Ladders::EIGHTY) = 100;

	// Store chute positions
	_posList.at(Chutes::SIXTEEN) = 6;
	_posList.at(Chutes::FORTY_SEVEN) = 26;
	_posList.at(Chutes::FORTY_NINE) = 11;
	_posList.at(Chutes::FIFTY_SIX) = 53;
	_posList.at(Chutes::SIXTY_TWO) = 19;
	_posList.at(Chutes::SIXTY_FOUR) = 60;
	_posList.at(Chutes::EIGHTY_SEVEN) = 24;
	_posList.at(Chutes::NINETY_THREE) = 73;
	_posList.at(Chutes::NINETY_FIVE) = 75;
	_posList.at(Chutes::NINETY_EIGHT) = 78;
}
