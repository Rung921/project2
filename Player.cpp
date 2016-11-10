// Player.cpp
// CPSC 131, Fall 2016, Project 2
//
// Class the constructs the player and handles player info
//
// Name: Richard Ung
// Due:  November 11, 2016

#include "Player.hpp"

// Player's assignment operator
Player& Player::operator=(const Player& p) {
	_playerName = p._playerName;
	_position = p._position;
	_die = p._die;
	return *this;
}

// return player's new position after player rolls die
// If the new position is outside of the board, player stays put
// If not, player moves to the new square = player's postion + die's face value
int Player::rollDieAndMove() {
	// Roll die. Check if new position is within range
	// If it is return the new position, else return the old position
	_die.roll(); 
	if (_die.getFaceValue() + _position <= 100) {
		_position += _die.getFaceValue();
	}
	return _position;
}
