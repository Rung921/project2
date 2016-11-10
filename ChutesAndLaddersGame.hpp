// ChutesAndLaddersGame.hpp
// CPSC 131, Fall 2016, Project 2
//
// Main class for the chutes and ladders game
//
// Name: Richard Ung
// Due:  November 11, 2016

#ifndef CHUTESANDLADDERSGAME_HPP
#define CHUTESANDLADDERSGAME_HPP

#include <stdio.h>
#include <string>

#include "ArrayQueue.h"
#include "Player.hpp"
#include "GameBoard.hpp"

using namespace std;

// Default number of players - Number of team mates: 1
const int MIN_NUMBER_OF_PLAYERS = 3;

class ChutesAndLaddersGame {
public:
	// constructor with the default value of 1 minimim player(s)
	ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS);

	// destructor
	~ChutesAndLaddersGame();

	// accessors
	long getNumberOfPlayers() { return _playerList.size(); }
	string getWinner() { return _winner; }

	// reset the game - (1) this will reset the position of each player to zero
	void resetGame();

	// play the Chutes and Ladders game
	void playGame();
private:
	const int WINNING_POSITION = 100;

	string _winner;       // the winner
	GameBoard _gameBoard; // the game board

	// TO DO: use ArrayQueue to store the players
	ArrayQueue<Player*> _playerList;
};

#endif
