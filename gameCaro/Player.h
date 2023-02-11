#ifndef PLAYER_H
#define PLAYER_H

struct Player {
	int _scores;
	int _currentMoves;
	char _team;

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
