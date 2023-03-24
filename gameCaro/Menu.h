#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <Windows.h>

#include "Common.h"
#include "Graphic.h"
#include "Game.h"

using namespace std;

struct Menu {
	int* _colorTitle;
	int _counter;
	bool _flag;
	int _numberTitle;
	bool _playBackground;
	int _effectSound;
	int _countSound;
	//Game _game;

	Menu();
	~Menu();

	void SetUp();
	void ProcessCounter();
	void RenderMenu();
	void NewGame();
	void LoadGame();
	void HighScores();
	void Help();
	void ResetMenu();
};


#endif // !1
