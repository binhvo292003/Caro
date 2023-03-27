#include "Menu.h"

Menu::Menu() {
	_playBackground = true;
	_effectSound = 0;
	SetUp();

	_numberTitle = 5;
	_colorTitle = new int[_numberTitle];
	_colorTitle[0] = RED;
	for (int i = 1; i < _numberTitle; i++) {
		_colorTitle[i] = BLACK;
	}

	_counter = 1;
	_countSound = 1;
	_flag = true;

}

Menu::~Menu() {
	_colorTitle = NULL;
	delete _colorTitle;
}

void Menu::ProcessCounter() {
	if (!_effectSound) {
		if (!_countSound) {
			Common::playBackground(_playBackground);
			_countSound++;
		}
	}
	else {
		if (!_countSound) {
			Common::playBackground(_playBackground);
			_countSound++;
		}
	}


	switch (Common::GetEvent()) {
	case 1:		// UP
		if (_counter > 1) {
			Common::playSound(EFFECT_SOUND, _effectSound);
			_counter--;
			break;
		}
		break;
	case 2:		// LEFT
		if (_counter > 1) {
			Common::playSound(EFFECT_SOUND, _effectSound);
			_counter--;
			break;
		}
		break;
	case 3:		// DOWN
		if (_counter < 5) {
			Common::playSound(EFFECT_SOUND, _effectSound);
			_counter++;
			break;
		}
		break;
	case 4:		// RIGHT
		if (_counter < 5) {
			Common::playSound(EFFECT_SOUND, _effectSound);
			_counter++;
			break;
		}
		break;
	case 5:
		Common::playSound(ENTER_SOUND, _effectSound);
		switch (_counter) {
		case 1:
			NewGame();
			break;
		case 2:
			LoadGame();
			break;
		case 3:
			Help();
			break;
		case 4:
			About();
			break;
		case 5:
			system("cls");
			_flag = false;
			break;
		default:
			break;
		}
		break;
	case 8:	
		if (_playBackground) {
			_playBackground = 0;
			_effectSound = 1;
			_countSound = 0;
		}
		else {
			_playBackground = 1;
			_effectSound = 0;
			_countSound = 0;
		}
		break;
	default:
		break;
	}
}

void Menu::SetUp() {
	system("cls");
	Common::ChangeFont();
	Common::ResizeConsole(1000, 700);
	Common::FixConsoleWindow();
	Common::MoveCenter();
	Common::ShowConsoleCursor(false);
	system("color 70");
	Graphic::DrawTitle();
	Common::playBackground(_playBackground);
}

void Menu::RenderMenu() {
	while (_flag) {
		Common::GotoXY(42, 16);
		Common::Color(_colorTitle[0], WHITE);
		cout << "1. New game";

		Common::GotoXY(42, 17);
		Common::Color(_colorTitle[1], WHITE);
		cout << "2. Load Game";

		Common::GotoXY(42, 18);
		Common::Color(_colorTitle[2], WHITE);
		cout << "3. Help";

		Common::GotoXY(42, 19);
		Common::Color(_colorTitle[3], WHITE);
		cout << "4. About";

		Common::GotoXY(42, 20);
		Common::Color(_colorTitle[4], WHITE);
		cout << "5. Exit";


		for (int i = 0; i < _numberTitle; i++) {
			_colorTitle[i] = BLACK;
		}

		ProcessCounter();

		_colorTitle[_counter - 1] = RED;
	}
}

void Menu::ResetMenu() {
	SetUp();

	_colorTitle[0] = RED;
	for (int i = 1; i < _numberTitle; i++) {
		_colorTitle[i] = BLACK;
	}

	_counter = 1;
	_flag = true;
}

void Menu::NewGame() {
	system("cls");
	Graphic::DrawRectangle(0, 0, 48, 30);
	Graphic::PlayMode();

	bool isTwoPlayer = false;	// false PvP true Play with Bot

	int numberChoice = 2;
	int* colorChoice = new int[numberChoice];
	colorChoice[0] = GREEN;
	for (int i = 1; i < numberChoice; i++) {
		colorChoice[i] = BLACK;
	}

	int counter = 1;
	bool flag = true;

	while (flag) {
		Common::GotoXY(42, 16);
		Common::Color(colorChoice[0], WHITE);
		Graphic::DrawRectangle(42, 18, 6, 2);
		Common::GotoXY(45, 19); cout << "1 Player";

		Common::GotoXY(42, 17);
		Common::Color(colorChoice[1], WHITE);
		Graphic::DrawRectangle(42, 22, 6, 2);
		Common::GotoXY(45, 23); cout << "2 Player";

		for (int i = 0; i < numberChoice; i++) {
			colorChoice[i] = BLACK;
		}

		switch (Common::GetEvent()) {
		case 1: case 2:
			if (counter > 1) {
				counter--;
				break;
			}
			break;
		case 3:	case 4:
			if (counter < 2) {
				counter++;
				break;
			}
			break;
		case 5:
			switch (counter) {
			case 1:
				isTwoPlayer = false;
				flag = false;
				break;
			case 2:
				isTwoPlayer = true;
				flag = false;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

		colorChoice[counter - 1] = GREEN;
	}
	
	Game* game;
	
	game = new Game(isTwoPlayer);
	game->Play();

	ResetMenu();
}

void Menu::LoadGame() {
	system("cls");
	vector<string> fileName;

	ifstream fi;
	fi.open("load.txt");
	if (!fi)
	{
		cout << "Cannot open file List Load" << endl;
	}
	else
	{
		string temp;
		while (!fi.eof())
		{
			getline(fi, temp);
			fileName.push_back(temp);
		}
	}
	fi.close();
	if (!fileName.size())
	{
		Common::GotoXY(42, 15);
		cout << "No game files were found!";
		Sleep(3000);
		return;
	}
	int file = 0;
	changeFile(fileName, file);

	int j = 20;
	int sz;

	if (fileName.size() < 8)
	{
		sz = fileName.size();
	}
	else
	{
		sz = 8;
	}

	bool chosen = 0;
	while (!chosen)
	{
		int key = Common::GetEvent();
		if (key == 5)
		{
			Game* g;
			g = new Game(fileName[file]);
			g->Play();
			chosen = 1;
		}
		else if (key == 1 || key == 2)
		{
			if (file == 0)
			{
				file = sz - 1;
				changeFile(fileName, file);
				Common::playSound(2);
			}
			else
			{
				file--;
				changeFile(fileName, file);
				Common::playSound(2);
			}
		}
		else if (key == 3 || key == 4)
		{
			if (file == sz - 1)
			{
				file = 0;
				changeFile(fileName, file);
				Common::playSound(2);
			}
			else
			{
				file++;
				changeFile(fileName, file);
				Common::playSound(2);
			}
		}
		else if (key == 1)
		{
			chosen = 1;
		}
		else
		{
			Common::playSound(4);
		}
	}

	ResetMenu();
}

void Menu::Help() {
	Graphic::Help();
	system("pause");
	ResetMenu();
}

void Menu::About() {
	Graphic::About();
	system("pause");
	ResetMenu();
}



void Menu::changeFile(vector<string>& fileName, int& file)
{
	system("cls");
	Graphic::LoadGameBackground();

	int j = 15;
	int sz;

	if (fileName.size() < 8)
	{
		sz = fileName.size();
	}
	else
	{
		sz = 8;
	}

	for (int i = 0; i < sz; i++)
	{
		Common::GotoXY(42, j);
		j++;
		if (i == file)
		{
			Common::Color(RED, WHITE);
			cout << fileName[i];
			Common::Color(BLACK, WHITE);
		}
		else
		{
			cout << fileName[i];
		}
	}
}