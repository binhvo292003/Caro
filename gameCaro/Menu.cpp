#include "Menu.h"

Menu::Menu() {
	SetUp();

	_numberTitle = 5;
	_colorTitle = new int[_numberTitle];
	_colorTitle[0] = RED;
	for (int i = 1; i < _numberTitle; i++) {
		_colorTitle[i] = BLACK;
	}

	_counter = 1;
	_flag = true;
}

Menu::~Menu() {
	_colorTitle = NULL;
	delete _colorTitle;
}

void Menu::ProcessCounter() {
	switch (Common::GetEvent()) {
		
	case 1:		// UP
		if (_counter > 1) {
			Common::playSound(EFFECT_SOUND);
			_counter--;
			break;
		}
		break;
	case 2:		// LEFT
		if (_counter > 1) {
			Common::playSound(EFFECT_SOUND);
			_counter--;
			break;
		}
		break;
	case 3:		// DOWN
		if (_counter < 5) {
			Common::playSound(EFFECT_SOUND);
			_counter++;
			break;
		}
		break;
	case 4:		// RIGHT
		if (_counter < 5) {
			Common::playSound(EFFECT_SOUND);
			_counter++;
			break;
		}
		break;
	case 5:
		Common::playSound(ENTER_SOUND);
		switch (_counter) {
		case 1:
			NewGame();
			break;
		case 2:
			LoadGame();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			system("cls");
			_flag = false;
			break;
		default:
			break;
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
		cout << "3. High Scores";

		Common::GotoXY(42, 19);
		Common::Color(_colorTitle[3], WHITE);
		cout << "4. Help";

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
	Graphic::LoadGameBackground();
	while (true) {
		if (Common::GetEvent() == 5) {
			break;
		}
	}
}

void Menu::HighScores() {

}

void Menu::Help() {

}