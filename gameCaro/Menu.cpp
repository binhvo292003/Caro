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
			_counter--;
			break;
		}
		break;
	case 2:		// LEFT
		if (_counter > 1) {
			_counter--;
			break;
		}
		break;
	case 3:		// DOWN
		if (_counter < 5) {
			_counter++;
			break;
		}
		break;
	case 4:		// RIGHT
		if (_counter < 5) {
			_counter++;
			break;
		}
		break;
	case 5:
		switch (_counter) {
		case 1:
			NewGame();
			break;
		case 2:
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
		cout << "2. Continue";

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
	Game* game;
	game = new Game();
	game->Play();

	ResetMenu();
}

void Menu::Continue() {

}

void Menu::HighScores() {

}

void Menu::Help() {

}