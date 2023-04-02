#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <Windows.h>

#include "Common.h"
#include "Graphic.h"
#include "Game.h"

using namespace std;

struct Menu {
	int* _colorIcon;
	int* _colorSquare;
	int _numberIcon;

	int* _colorTitle;
	int _counter;
	bool _flag;
	int _numberTitle;
	bool _playBackground;
	int _effectSound;
	int _countSound;
	vector<string> listLoad;
	//Game _game;

	Menu();
	~Menu();

	void SetUp();
	void ProcessCounter();
	void RenderMenu();
	void NewGame();
	void LoadGame();
	void Setting();
	void About();
	void Help();
	void Exit();
	void ResetMenu();
	void changeFile(vector<string>& fileName, int& file);
};


#endif // !1
