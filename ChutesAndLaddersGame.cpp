// ChutesAndLaddersGame.cpp
// CPSC 131, Fall 2016, Project 2
//
// Main class for the chutes and ladders game
//
// Name: Richard Ung
// Due:  November 11, 2016

#include <iostream>
#include <string>
#include <sstream>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : _winner("no winner") {
	for (int i = 0; i < nPlayers; i++) {
		// Construct "default" player names Ex.) Player 1, Player 2, etc.
		// Names for testing purposes with PlayChutesAndLaddersGame.cpp
		std::stringstream ss;
		ss << "Player " << i + 1;
		_playerList.enqueue(new Player(ss.str()));
	}
}

// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
	while (!_playerList.empty()) {
		_playerList.dequeue();
	}
}

// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
	// Resets position of player in the front, then place them in the back
	for (int i = 0; i < _playerList.size(); i++) {
		_playerList.front()->setPosition(0);
		_playerList.enqueue(_playerList.front());
		_playerList.dequeue();
	}
	_winner = "no winner";
}

// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {
	while (true) {
		// Roll die and move player to new position 
		int pos = _playerList.front()->rollDieAndMove();
		_playerList.front()->setPosition(_gameBoard.checkChutesLadders(pos));

		// Check if player won (Landed on 100). If there is a winner, end game.
		if (_playerList.front()->getPostion() == WINNING_POSITION) {
			_winner = _playerList.front()->getName();
			cout << "Congratulations " << _winner << ", you won!" << endl;
			return;
		}

		// Move the player from the front to the back of the queue 
		_playerList.enqueue(_playerList.front());
		_playerList.dequeue();
	}
}
