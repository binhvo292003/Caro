#include "Player.h"

Player::Player() {
	_scores = 0;
	_currentMoves = 0;
	_team = '0';
}

Player::~Player() {

}

int Player::getScores() {
	return _scores;
}

int Player::getCurrentMoves() {
	return _currentMoves;
}

char Player::getTeam() {
	return _team;
}

void Player::setScores(const int& scores) {
	if (scores >= 0) {
		_scores = scores;
	}
}

void Player::setCurrentMoves(const int& currentMoves) {
	if (currentMoves >= 0) {
		_currentMoves = currentMoves;
	}
}

void Player::setTeam(const char& team) {
	if (team == 'x' || team == 'X') {
		_team = 'x';
	}
	else if (team == 'o' || team == 'O') {
		_team = 'o';
	}
	else {
		_team = 'b';
	}
}