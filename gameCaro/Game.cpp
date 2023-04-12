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

Game::Game(string txtFile) {
	fstream fi;
	fi.open(txtFile);
	if (!fi)
	{
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
	else
	{
		string temp;
		while (!fi.eof())
		{
			getline(fi, temp, ' ');
			_size = stoi(temp);
			getline(fi, temp);

			getline(fi, temp, ' ');
			_turnX = stoi(temp);
			getline(fi, temp);

			getline(fi, temp, ' ');
			_countX = stoi(temp);
			getline(fi, temp);

			getline(fi, temp, ' ');
			_countO = stoi(temp);
			getline(fi, temp);

			getline(fi, temp, ' ');
			_pointWinX = stoi(temp);
			getline(fi, temp);

			getline(fi, temp, ' ');
			_pointWinO = stoi(temp);
			getline(fi, temp);

			getline(fi, temp, ' ');
			_isTwoPlayer = stoi(temp);
			getline(fi, temp);

			int tmpInt;

			_board = new Board(_size, 4, 1);
			for (int i = 0; i < _size; i++) {
				for (int j = 0; j < _size; j++) {

					if (j == _size - 1) {
						getline(fi, temp);
						tmpInt = stoi(temp);
						//std::cout << tmpInt << " ";
						if (tmpInt != 0) {
							this->_board->_arrPoint[j][i].SetChoosing(tmpInt);
						}
						continue;
					}
					getline(fi, temp, ' ');
					tmpInt = stoi(temp);
					//std::cout << tmpInt << " ";
					if (tmpInt != 0) {
						this->_board->_arrPoint[j][i].SetChoosing(tmpInt);
					}
				}
				std::cout << endl;
			}

			//system("pause");
			_pointRow = _size / 2;
			_pointColumn = _size / 2;
			_isGameRunning = true;
			_isEnd = false;
			_pause = false;
			GetXYatPoint(_pointRow, _pointColumn);
			getline(fi, temp);
		}
	}
	fi.close();
}

Game::~Game() {
	delete _board;
}

void Game::Play() {
	while (!_isEnd) {
		DrawBoard();
		DrawInfoOfGame();

		Common::ShowConsoleCursor(false);
		Common::GotoXY(_x, _y);
		MoveUp();

		while (_isGameRunning) {
			if (_isTwoPlayer || _turnX) {
				switch (Common::GetEvent()) {
				case 1: //UP
					MoveUp();
					Common::GotoXY(70, 28);
					std::cout << "        ";
					Common::GotoXY(70, 29);
					std::cout << "        ";
					break;
				case 2: //LEFT
					MoveLeft();
					Common::GotoXY(70, 28);
					std::cout << "        ";
					Common::GotoXY(70, 29);
					std::cout << "        ";
					break;
				case 3: //DOWN
					MoveDown();
					Common::GotoXY(70, 28);
					std::cout << "        ";
					Common::GotoXY(70, 29);
					std::cout << "        ";
					break;
				case 4: //RIGHT
					MoveRight();
					Common::GotoXY(70, 28);
					std::cout << "        ";
					Common::GotoXY(70, 29);
					std::cout << "        ";
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
			}
			else {
				BotPlay();
				ProcessPoint();
			}
			DrawInfoOfGame();
			/*Common::GotoXY(70, 28);
			std::cout << _y << "/" << _x << endl;
			Common::GotoXY(70, 29);
			std::cout << _pointRow << "/" << _pointColumn << endl;
			Common::GotoXY(70, 30);
			std::cout << _board->_arrPoint[_pointRow][_pointColumn].ReturnChoosing();*/
		}

		WinLoseResult();


		AskContinue();
		ResetDataForNewGame();
	}
}

void Game::BotPlay() {
	int i, j;
	do
	{
		i = getRandomInt(0, _size - 1);
		j = getRandomInt(0, _size - 1);
	} while (_board->_arrPoint[i][j]._isChoosing);
	//Common::GotoXY(70, 10); std::cout << i;
	//Common::GotoXY(70, 11); std::cout << j;
	_pointRow = i;
	_pointColumn = j;
	GetXYatPoint(_pointColumn, _pointRow);
}

void Game::GetXYatPoint(const int& row, const int& column) {
	_x = _board->_arrPoint[row][column].GetX();
	_y = _board->_arrPoint[row][column].GetY();
}

void Game::MoveUp() {
	Sound::playSound(OPTION_SOUND);
	Graphic::Common4Corners(_x, _y);
	if (_y <= _board->_edgeTop) {
		return;
	}
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::GotoXY(_x, _y);
		std::cout << "  ";
	}

	_pointRow--;
	_y -= _board->_stepY;

	PrintTempChoice(_turnX);

}

void Game::MoveLeft() {
	Sound::playSound(OPTION_SOUND);
	Graphic::Common4Corners(_x, _y);
	if (_x <= _board->_edgeLeft) {
		return;
	}
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::GotoXY(_x, _y);
		std::cout << "  ";
	}

	_pointColumn--;
	_x -= _board->_stepX;

	Common::GotoXY(_x, _y);
	PrintTempChoice(_turnX);
}

void Game::MoveDown() {
	Sound::playSound(OPTION_SOUND);
	Graphic::Common4Corners(_x, _y);
	if (_y >= _board->_edgeBottom) {
		return;
	}
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::GotoXY(_x, _y);
		std::cout << "  ";
	}

	_pointRow++;
	_y += _board->_stepY;

	Common::GotoXY(_x, _y);
	PrintTempChoice(_turnX);
}

void Game::MoveRight() {
	Sound::playSound(OPTION_SOUND);
	Graphic::Common4Corners(_x, _y);
	if (_x >= _board->_edgeRight) {
		return;
	}
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::GotoXY(_x, _y);
		std::cout << "  ";
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
		Sound::playSound(X_MOVE_SOUND);
		_board->ChoosingAtPoint(_pointRow, _pointColumn, 1);
		Common::Color(RED, WHITE);
		Common::GotoXY(_x, _y);
		std::cout << "X ";
		_countX++;
		_turnX = false;
	}
	else {
		Sound::playSound(O_MOVE_SOUND);
		_board->ChoosingAtPoint(_pointRow, _pointColumn, 2);
		Common::Color(BLUE, WHITE);
		Common::GotoXY(_x, _y);
		std::cout << "O ";
		_countO++;
		_turnX = true;
	}
	Graphic::Normal4Corners(_x, _y);

	//Info of Player(s)
	//DrawInfoOfGame();

	// Check end game
	if (IsEndGame()) {
		_isGameRunning = false;
		PrintWinPos();
	}

	if (_isTwoPlayer) {
		MoveDown();
	}
}

void Game::PrintTempChoice(const bool& turnX) {
	Graphic::Highlight4Corners(_x, _y);
	if (_board->CheckPointAvailable(_pointRow, _pointColumn)) {
		Common::ShowConsoleCursor(false);
		Common::GotoXY(_x, _y);
		if (turnX) {
			Common::Color(RED, WHITE);
			std::cout << "x ";
			return;
		}
		Common::Color(BLUE, WHITE);
		std::cout << "o ";

		return;
	}
	//Graphic::Highlight4Corners(_x, _y);
}

void Game::DrawInfoX() {
	Graphic::DrawRectangle(75, 10, 15, 10);
	Common::GotoXY(78, 19); std::cout << "Moves: " << _countX;
	Common::GotoXY(95, 19); std::cout << "Wins: " << _pointWinX;
	Common::Color(RED, WHITE);
	Graphic::DrawAsciiX();
}

void Game::DrawInfoO() {
	Graphic::DrawRectangle(75, 10, 15, 10);
	Common::GotoXY(78, 19); std::cout << "Moves: " << _countO;
	Common::GotoXY(95, 19); std::cout << "Wins: " << _pointWinO;
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
	return IsEndHorizontal() ||
		IsEndVertical() ||
		IsEndPrimeDiag() ||
		IsEndSecondDiag() ||
		(_size * _size == _countO + _countX);
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
		int count = 0;
		for (int i = _pointColumn; i >= 0; i--) {
			if (XO == _board->CheckContain(_pointRow, i)) {
				winPos[count] = _board->_arrPoint[i][_pointRow];
				count++;
			}
			else {
				break;
			}
		}

		for (int i = _pointColumn + 1; i < _size; i++) {
			if (XO == _board->CheckContain(_pointRow, i)) {
				winPos[count] = _board->_arrPoint[i][_pointRow];
				count++;
			}
			else {
				break;
			}
		}
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
		int count = 0;
		for (int i = _pointRow; i >= 0; i--) {
			if (XO == _board->CheckContain(i, _pointColumn)) {
				winPos[count] = _board->_arrPoint[_pointColumn][i];
				count++;
			}
			else {
				break;
			}
		}

		for (int i = _pointRow + 1; i < _size; i++) {
			if (XO == _board->CheckContain(i, _pointColumn)) {
				winPos[count] = _board->_arrPoint[_pointColumn][i];
				count++;
			}
			else {
				break;
			}
		}

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

		int count = 0;
		for (int i = 0; i <= _pointRow; i++) {
			if (XO == _board->CheckContain(_pointRow - i, _pointColumn - i)) {
				winPos[count] = _board->_arrPoint[_pointColumn - i][_pointRow - i];
				count++;
			}
			else {
				break;
			}
		}

		for (int i = 1; i < _size - _pointRow; i++) {
			if (XO == _board->CheckContain(_pointRow + i, _pointColumn + i)) {
				winPos[count] = _board->_arrPoint[_pointColumn - i][_pointRow + i];
				count++;
			}
			else {
				break;
			}
		}

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
		int count = 0;
		for (int i = 0; i <= _pointRow; i++) {
			if (XO == _board->CheckContain(_pointRow - i, _pointColumn + i)) {
				winPos[count] = _board->_arrPoint[_pointColumn + i][_pointRow - i];
				count++;
			}
			else {
				break;
			}
		}

		for (int i = 1; i < _size - _pointRow; i++) {
			if (XO == _board->CheckContain(_pointColumn - i, _pointColumn - i)) {
				winPos[count] = _board->_arrPoint[_pointColumn - i][_pointColumn - i];
				count++;
			}
			else {
				break;
			}
		}

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
		Graphic::DrawRectangle(36, 22, 4, 2);
		Common::GotoXY(39, 23); std::cout << "YES";

		Common::GotoXY(42, 17);
		Common::Color(colorChoice[1], WHITE);
		Graphic::DrawRectangle(72, 22, 4, 2);
		Common::GotoXY(75, 23); std::cout << "NO";

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

void Game::SaveGame() {
	system("cls");
	Common::Color(BLACK, WHITE);
	Graphic::SaveGameAscii();

	int flag = 0;
	do {
		flag = 0;
		Common::GotoXY(25, 15);
		Common::ShowConsoleCursor(true);
		std::cout << string(200, ' ');
		Common::GotoXY(25, 15);
		std::cout << "Enter your file name (.txt file): ";
		getline(cin, filename);
		Common::ShowConsoleCursor(false);
		//check space in file name
		int length = filename.length();
		for (int i = 0; i < length; i++) {
			int c = filename[i];
			if (isspace(c)) {
				flag++;
				break;
			}
		}
	} while (flag);



	//		check user input with .txt or not if not append ".txt"
	if (!(filename.find(".txt") != string::npos)) {
		filename.append(".txt");
	}

	system("cls");
	Common::Color(BLACK, WHITE);
	Graphic::SaveGameAscii();
	Common::GotoXY(35, 15);
	std::cout << "Save sucessfully";

	string path = "data\\" + filename;
	ifstream fi;
	ofstream fo;

	int tmpInt = 0;
	string tmp;
	fi.open("load.txt");
	if (!fi)
	{
		std::cout << "cannot open file" << endl;
	}
	else
	{
		while (!fi.eof()) {
			getline(fi, tmp);
			if (tmp.compare(path) == 0) {
				tmpInt = 1;
			}
		}

		if (tmpInt == 0) {
			fo.open("load.txt", ios::app);
			fo << path << endl;
			fo.close();
		}
	}
	fi.close();


	//		write to file filename 

	ofstream ofs;
	ofs.open(path);

	ofs << _size << " _size" << endl;
	ofs << _turnX << " _turnX" << endl;
	ofs << _countX << " _countX" << endl;
	ofs << _countO << " _countO" << endl;
	ofs << _pointWinX << " _pointWinX" << endl;
	ofs << _pointWinO << " _pointWinO" << endl;
	ofs << _isTwoPlayer << " _isTwoPlayer" << endl;

	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			ofs << _board->_arrPoint[j][i].ReturnChoosing() << " ";
		}
		ofs << endl;
	}

	ofs.close();


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

	if (_size * _size == _countO + _countX) {
		Graphic::DrawGameAscii();
	}
	else {
		if (!_turnX) {
			Graphic::XWinGameAscii();
			_pointWinX++;
		}
		else {
			Graphic::OWinGameAscii();
			_pointWinO++;
		}
	}
	Common::Color(YELLOW, WHITE);
	Graphic::DrawRectangle(43, 18, 13, 2);
	Common::GotoXY(45, 19); std::cout << "PRESS ENTER TO CONTINUE";

	while (Common::GetEvent() != 5) {
	}
}

void Game::DrawBoard() {
	int count = 0;
	system("cls");
	_board->DrawBoard();
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			this->GetXYatPoint(i, j);
			Common::GotoXY(_x, _y);
			if (_board->_arrPoint[j][i].ReturnChoosing() == 1) {		//x 
				Common::Color(RED, WHITE);
				std::cout << "X ";
			}
			else if (_board->_arrPoint[j][i].ReturnChoosing() == 2) {
				Common::Color(BLUE, WHITE);
				std::cout << "O ";
			}
			//std::cout << count++;
		}
	}
	_pointColumn = _size / 2;
	_pointRow = _size / 2;
	GetXYatPoint(_pointRow, _pointColumn);
	DrawInfoOfGame();
}

void Game::PrintWinPos()
{
	Sound::playSound(WIN_SOUND);
	int loop = 15;
	while (loop)
	{
		Common::Color(loop, WHITE);
		for (int i = 0; i < 5; i++)
		{
			Common::GotoXY(winPos[i].GetX(), winPos[i].GetY());
			if (!_turnX) {
				std::cout << "X ";
			}
			else {
				std::cout << "O ";
			}
		}
		Sleep(100);
		for (int i = 0; i < 5; i++)
		{
			Common::GotoXY(winPos[i].GetX(), winPos[i].GetY());
			if (!_turnX) {
				std::cout << "x ";
			}
			else {
				std::cout << "o ";
			}
		}
		Sleep(300);
		loop--;
	}

}

int getRandomInt(int begin, int end) {
	int n = rand() % (end - begin + 1) + begin;
	return n;
}
