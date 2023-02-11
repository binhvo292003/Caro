#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Common.h"
#include "Board.h"
#include "Graphic.h"

using namespace std;

struct Game {
	Board* _board;
	int _size;
	int _x;
	int _y;
	bool _isGameRunning;
	bool _isEnd;
	bool _turnX;
	int _pointRow;
	int _pointColumn;
	int _countX;
	int _countO;
	int _pointWinX;
	int _pointWinO;


	Game();
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
	void EndConsole();
	void AskContinue();

	bool IsEndGame();
	bool IsEndHorizontal();
	bool IsEndVertical();
	bool IsEndPrimeDiag();
	bool IsEndSecondDiag();

};

#endif // !GAME
