#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

struct Player {
	int _scores;
	int _currentMoves;
	char _team;
	
	string name = "Unknown";

	Player();
	~Player();

	int getScores();
	int getCurrentMoves();
	char getTeam();

	void setScores(const int& scores);
	void setCurrentMoves(const int& currentMoves);
	void setTeam(const char& team);
};


#endif // !HEADER_H
