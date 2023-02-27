#include "Game.h"

Game::Game() {
	_size = 15;
	_pointRow = _size / 2;
	_pointColumn = _size / 2;
	_board = new Board(_size, 4, 1);
	_isGameRunning = true;
	_turnX = true;
	_countX = 0;
	_countO = 0;
	_pointWinX = 0;
	_pointWinO = 0;
	_isEnd = false;
	_pause = false;
	GetXYatPoint(_pointRow, _pointColumn);
	
}

Game::Game(bool isTwoPlayer) {
	_size = 15;
	_pointRow = _size / 2;
	_pointColumn = _size / 2;
	_board = new Board(_size, 4, 1);
	_isGameRunning = true;
	_turnX = true;
	_countX = 0;
	_countO = 0;
	_pointWinX = 0;
	_pointWinO = 0;
	_isEnd = false;
	_isTwoPlayer = isTwoPlayer;
	_pause = false;
	GetXYatPoint(_pointRow, _pointColumn);
}

Game::~Game() {
	delete _board;
}

void Game::Play() {
	while (!_isEnd) {
		_board->DrawBoard();
		DrawInfoOfGame();

		Common::ShowConsoleCursor(true);
		Common::GotoXY(_x, _y);
		MoveUp();

		while (_isGameRunning) {
			if (_isTwoPlayer || _turnX) {
				switch (Common::GetEvent()) {
				case 1: //UP
					MoveUp();
					Common::GotoXY(70, 28);
					cout << "        ";
					Common::GotoXY(70, 29);
					cout << "        ";
					break;
				case 2: //LEFT
					MoveLeft();
					Common::GotoXY(70, 28);
					cout << "        ";
					Common::GotoXY(70, 29);
					cout << "        ";
					break;
				case 3: //DOWN
					MoveDown();
					Common::GotoXY(70, 28);
					cout << "        ";
					Common::GotoXY(70, 29);
					cout << "        ";
					break;
				case 4: //RIGHT
					MoveRight();
					Common::GotoXY(70, 28);
					cout << "        ";
					Common::GotoXY(70, 29);
					cout << "        ";
					break;
				case 5:
					ProcessPoint();
					break;
				case 6:
					SaveGame();
					//_isGameRunning = false;
					//_pause = true;
					break;
				case 7:
					_isGameRunning = false;
					_pause = true;
					break;
				}
				Common::GotoXY(70, 28);
				cout << _x << "/" << _y << endl;
				Common::GotoXY(70, 29);
				cout << _pointColumn << "/" << _pointRow << endl;
			}
			else {
				BotPlay();
				ProcessPoint();

			}
		}

		WinLoseResult();
		

		AskContinue();
		ResetDataForNewGame();
	}
}

void Game::GetXYatPoint(const int& row, const int& column) {
	_x = _board->_arrPoint[row][column].GetX();
	_y = _board->_arrPoint[row][column].GetY();
}

void Game::MoveUp() {
	if (_y <= _board->_edgeTop) {
		return;
	}
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::GotoXY(_x, _y);
		cout << "  ";
	}

	_pointRow--;
	_y -= _board->_stepY;

	Common::GotoXY(_x, _y);
	PrintTempChoice(_turnX);
}

void Game::MoveLeft() {
	if (_x <= _board->_edgeLeft) {
		return;
	}
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::GotoXY(_x, _y);
		cout << "  ";
	}

	_pointColumn--;
	_x -= _board->_stepX;

	Common::GotoXY(_x, _y);
	PrintTempChoice(_turnX);
}

void Game::MoveDown() {
	if (_y >= _board->_edgeBottom) {
		return;
	}
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::GotoXY(_x, _y);
		cout << "  ";
	}

	_pointRow++;
	_y += _board->_stepY;

	Common::GotoXY(_x, _y);
	PrintTempChoice(_turnX);
}

void Game::MoveRight() {
	if (_x >= _board->_edgeRight) {
		return;
	}
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::GotoXY(_x, _y);
		cout << "  ";
	}
	_pointColumn++;
	_x += _board->_stepX;

	Common::GotoXY(_x, _y);
	PrintTempChoice(_turnX);
}

void Game::ProcessPoint() {
	if (!_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		return;
	}

	if (_turnX) {
		_board->ChoosingAtPoint(_pointRow, _pointColumn, 1);
		Common::Color(RED, WHITE);
		Common::GotoXY(_x, _y);
		cout << "X ";
		_countX++;
		_turnX = false;
	}
	else {
		_board->ChoosingAtPoint(_pointRow, _pointColumn, 2);
		Common::Color(BLUE, WHITE);
		Common::GotoXY(_x, _y);
		cout << "O ";
		_countO++;
		_turnX = true;
	}

	//Info of Player(s)
	DrawInfoOfGame();

	// Check end game
	if (IsEndGame()) {
		_isGameRunning = false;
	}

	//MoveDown();
}

void Game::PrintTempChoice(const bool& turnX) {
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::ShowConsoleCursor(false);

		if (turnX) {
			Common::Color(RED, WHITE);
			cout << "x ";
			return;
		}
		Common::Color(BLUE, WHITE);
		cout << "o ";

		return;
	}

	Common::ShowConsoleCursor(true);

}

void Game::DrawInfoX() {
	Graphic::DrawRectangle(65, 10, 15, 10);
	Common::GotoXY(68, 19); cout << "Moves: " << _countX;
	Common::GotoXY(85, 19); cout << "Wins: " << _pointWinX;
	Common::Color(RED, WHITE);
	Graphic::DrawAsciiX();
}

void Game::DrawInfoO() {
	Graphic::DrawRectangle(65, 10, 15, 10);
	Common::GotoXY(68, 19); cout << "Moves: " << _countO;
	Common::GotoXY(85, 19); cout << "Wins: " << _pointWinO;
	Common::Color(BLUE, WHITE);
	Graphic::DrawAsciiO();
}

void Game::ResetDataForNewGame() {
	_size = 15;
	_board->ResetBoard();
	_pointRow = _size / 2;
	_pointColumn = _size / 2;
	_isGameRunning = true;
	_turnX = true;
	_countX = 0;
	_countO = 0;
	_pause = false;
	GetXYatPoint(_pointRow, _pointColumn);
}

bool Game::IsEndGame() {
	return IsEndHorizontal() || IsEndVertical() || IsEndPrimeDiag() || IsEndSecondDiag();
}

bool Game::IsEndHorizontal() {
	int left = 0, right = 0;
	int XO = 0;
	if (!_turnX) {
		XO = 1;
	}
	else {
		XO = 2;
	}

	for (int i = _pointColumn; i >= 0; i--) {
		if (XO == _board->CheckContain(_pointRow, i)) {
			left++;
		}
		else {
			break;
		}
	}

	for (int i = _pointColumn + 1; i < _size; i++) {
		if (XO == _board->CheckContain(_pointRow, i)) {
			right++;
		}
		else {
			break;
		}
	}

	if (right + left >= 5) {
		return true;
	}
	return false;
}

bool Game::IsEndVertical() {
	int top = 0, bottom = 0;
	int XO = 0;
	if (!_turnX) {
		XO = 1;
	}
	else {
		XO = 2;
	}

	for (int i = _pointRow; i >= 0; i--) {
		if (XO == _board->CheckContain(i, _pointColumn)) {
			bottom++;
		}
		else {
			break;
		}
	}

	for (int i = _pointRow + 1; i < _size; i++) {
		if (XO == _board->CheckContain(i, _pointColumn)) {
			top++;
		}
		else {
			break;
		}
	}

	if (bottom + top >= 5) {
		return true;
	}
	return false;
}

bool Game::IsEndPrimeDiag() {
	int topDiag = 0, bottomDiag = 0;
	int XO = 0;
	if (!_turnX) {
		XO = 1;
	}
	else {
		XO = 2;
	}

	for (int i = 0; i <= _pointRow; i++) {
		if (XO == _board->CheckContain(_pointRow - i, _pointColumn - i)) {
			topDiag++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i < _size - _pointRow; i++) {
		if (XO == _board->CheckContain(_pointRow + i, _pointColumn + i)) {
			bottomDiag++;
		}
		else {
			break;
		}
	}

	if (bottomDiag + topDiag >= 5) {
		return true;
	}
	return false;
}

bool Game::IsEndSecondDiag() {
	int topDiag = 0, bottomDiag = 0;
	int XO = 0;
	if (!_turnX) {
		XO = 1;
	}
	else {
		XO = 2;
	}

	for (int i = 0; i <= _pointRow; i++) {
		if (XO == _board->CheckContain(_pointRow - i, _pointColumn + i)) {
			topDiag++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i < _size - _pointRow; i++) {
		if (XO == _board->CheckContain(_pointRow + i, _pointColumn - i)) {
			bottomDiag++;
		}
		else {
			break;
		}
	}

	if (bottomDiag + topDiag >= 5) {
		return true;
	}
	return false;
}

void Game::DrawInfoOfGame() {
	Common::Color(BLACK, WHITE);
	Graphic::HelpBox();
	if (_turnX) {
		DrawInfoX();
		return;
	}
	DrawInfoO();
}

void Game::AskContinue() {
	system("cls");
	Common::Color(BLACK, WHITE);
	Graphic::ContinueAscii();

	int numberChoice = 2;
	int* colorChoice = new int[numberChoice];
	colorChoice[0] = GREEN;
	for (int i = 1; i < numberChoice; i++) {
		colorChoice[i] = BLACK;
	}

	int counter = 1;
	int flag = true;

	while (flag) {
		Common::GotoXY(42, 16);
		Common::Color(colorChoice[0], WHITE);
		Graphic::DrawRectangle(26, 22, 4, 2);
		Common::GotoXY(29, 23); cout << "YES";

		Common::GotoXY(42, 17);
		Common::Color(colorChoice[1], WHITE);
		Graphic::DrawRectangle(62, 22, 4, 2);
		Common::GotoXY(65, 23); cout << "NO";

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
				_isEnd = false;
				flag = false;
				break;
			case 2:
				_isEnd = true;
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

	delete[] colorChoice;
	colorChoice = nullptr;
}

void Game::BotPlay() {
	int i, j;
	do
	{
		i = getRandomInt(0, 14), j = getRandomInt(0, 14);
	} while (_board->_arrPoint[i][j]._isChoosing);
	_pointRow = i;
	_pointColumn = j;
	GetXYatPoint(_pointRow, _pointColumn);
}

void Game::SaveGame() {
	

	
	system("cls");
	Common::Color(BLACK, WHITE);
	Graphic::SaveGameAscii();
	while (true) {
		if (Common::GetEvent() == 5) {
			break;
		}
	}
	DrawBoard();
}

void Game::WinLoseResult() {
	_isGameRunning = false;
	system("cls");
	Common::Color(BLACK, WHITE);
	Common::ShowConsoleCursor(false);

	if (!_turnX) {
		Graphic::XWinGameAscii();
		_pointWinX++;
	}
	else {
		Graphic::OWinGameAscii();
		_pointWinO++;
	}

	Common::Color(YELLOW, WHITE);
	Graphic::DrawRectangle(37, 18, 13, 2);
	Common::GotoXY(39, 19); cout << "PRESS ENTER TO CONTINUE";

	while (Common::GetEvent() != 5) {
	}
}

void Game::DrawBoard() {
	system("cls");
	_board->DrawBoard();
	for (int i = 0; i < this->_size; i++) {
		for (int j = 0; j < this->_size; j++) {
			this->GetXYatPoint(i, j);
			Common::GotoXY(_x, _y);
			if (_board->_arrPoint[j][i].ReturnChoosing() == 1) {		//x 
				Common::Color(RED, WHITE);
				cout << "X ";
			}
			else if (_board->_arrPoint[i][j].ReturnChoosing() == 2) {
				Common::Color(BLUE, WHITE);
				cout << "O ";
			}
		}
	}
	_pointColumn = _size/2;
	_pointRow = _size/2;
	GetXYatPoint(_pointRow, _pointColumn);
	DrawInfoOfGame();
}