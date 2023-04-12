#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <fstream>

#include "Common.h"
#include "Board.h"
#include "Graphic.h"
#include "Sound.h"


using namespace std;

struct Game {
	Board* _board;
	int _size;
	int _x;
	int _y;
	bool _isGameRunning;
	bool _isEnd;
	bool _turnX;
	bool _isTwoPlayer;
	int _pointRow;
	int _pointColumn;
	int _countX;
	int _countO;
	int _pointWinX;
	int _pointWinO;
	bool _pause;
	string filename;
	Point winPos[5];

	Game();
	Game(bool isTwoPlayer);
	Game(string txtFile);
	~Game();

	void Play();
	void GetXYatPoint(const int& row, const int& column);
	void MoveUp();
	void MoveLeft();
	void MoveDown();
	void MoveRight();
	void ProcessPoint();
	void PrintTempChoice(const bool& turnX);
	void DrawInfoOfGame();
	void DrawInfoX();
	void DrawInfoO();
	void ResetDataForNewGame();
	void AskContinue();
	void BotPlay();
	void SaveGame();
	void PauseGame();
	void LoadGame();
	void WinLoseResult();
	void DrawBoard();
	void PrintWinPos();

	bool IsEndGame();
	bool IsEndHorizontal();
	bool IsEndVertical();
	bool IsEndPrimeDiag();
	bool IsEndSecondDiag();



};
int getRandomInt(int begin, int end);
#endif // !GAME
