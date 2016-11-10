// Player.hpp
// CPSC 131, Fall 2016, Project 2
//
// Class the constructs the player and handles player info
//
// Name: Richard Ung
// Due:  November 11, 2016

#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string>

#include "Die.hpp"
#include "GameBoard.hpp"

using namespace std;

class Player {
public:
	// default constructor with no name
	Player() : _playerName("no name"), _position(0), _die() {}

	// parametrized constructor with name
	// player's initial position is at the figurative square 0
	Player(string name) : _playerName(name), _position(0), _die() {}

	// copy constructor
	// Player should make player's own copy of the die
	Player(const Player &p) : 
		_playerName(p._playerName),
		_position(p._position)
	{
		_die = p._die;
	}

	// assignment constructor
	// Player should make player's own copy of the die
	Player& operator=(const Player& p);

	// destructor
	~Player() {}

	// getters and setters
	void setName(string name) { _playerName = name; }
	void setPosition(int location) { _position = location; }
	string getName() const { return _playerName; }
	int getPostion() const { return _position; }
	Die getDie() { return _die; }

	// return player's new position after player rolls die
	// If the new position is outside of the board, player stays put
	// If not, player moves to the new square = player's postion + die's face value
	int rollDieAndMove();
private:
	string _playerName;
	int _position;
	Die _die;
};

#endif
