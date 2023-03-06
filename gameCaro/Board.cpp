#include "Board.h"

Board::Board(const int& size, const int& x, const int& y) {
	_x = x;
	_y = y;
	_stepX = 4;
	_stepY = 2;
	_size = size;
	_edgeTop = _y;
	_edgeLeft = _x;
	_edgeBottom = _y + _stepY * (size - 1);
	_edgeRight = _x + _stepX * (size - 1);

	_arrPoint = new Point*[_size];
	for (int i = 0; i < _size; i++) {
		_arrPoint[i] = new Point[_size];
	}
	int count = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_arrPoint[i][j].SetXY(_x + _stepX * i, _y + _stepY * j);
		}
	}
}

Board::~Board(){
	for (int i = 0; i < _size; i++) {
		delete[] _arrPoint[_size];
	}
	delete[] _arrPoint;
	_arrPoint = nullptr;
}

void Board::DrawBoard() {
	system("cls");
	Common::ChangeFont();
	Common::Color(BLACK, WHITE);

	for (int j = 1; j < _size * 2; j += 2) {
		for (int i = 0; i < _size * 4 + 1; i += 4) {

			Common::GotoXY(2 + i, j);
			//cout << "║";
			cout << "|";
		}
		Sleep(50);
	}

	for (int j = 0; j < _size * 2 + 1; j += 2) {
		for (int i = 0; i < _size * 4; i += 4) {
			Common::GotoXY(3 + i, j);
			//cout << "═══";
			cout << "---";
		}
		Sleep(50);
	}

	for (int j = 2; j < _size * 2; j += 2) {
		for (int i = 0; i < _size * 4 - 4; i += 4) {
			Common::GotoXY(6 + i, j);
			//cout << "╬";
			cout << "+";
		}
		Sleep(50);
	}

	//Ve canh tren
	for (int i = 0; i < _size * 4; i += 4) {
		Common::GotoXY(6 + i, 0);
		//cout << "╦";
		//cout << "-";
		cout << "+";
		Sleep(20);
	}

	Common::GotoXY(_size * 4 + 2, 0);
	//cout << "╗";
	//cout << ".";
	cout << "+";
	Sleep(20);

	//Ve canh ngoai phai
	for (int i = 0; i < _size * 2; i += 2) {
		Common::GotoXY(_size * 4 + 2, 2 + i);
		//cout << "╣";
		//cout << "|";
		cout << "+";
		Sleep(20);
	}

	Common::GotoXY(_size * 4 + 2, _size * 2);
	//cout << "╝";
	//cout << "*";
	cout << "+";
	Sleep(20);

	//Ve canh duoi
	for (int i = _size * 4 - 8; i >= 0; i -= 4) {
		Common::GotoXY(6 + i, _size * 2);
		//cout << "╩";
		//cout << "-";
		cout << "+";
		Sleep(20);
	}

	Common::GotoXY(2, _size * 2);
	//cout << "╚";
	//cout << "*";
	cout << "+";
	Sleep(20);

	//Ve canh ngoai trai

	for (int i = _size * 2 - 2; i >= 0; i -= 2) {
		Common::GotoXY(2, i);
		//cout << "╠";
		//cout << "|";
		cout << "+";
		Sleep(20);
	}

	Common::GotoXY(2, 0);
	//cout << "╔";
	//cout << ".";
	cout << "+";
	Sleep(20);

}

int	Board::GetXAtPoint(const int& row, const int& column) {
	return _arrPoint[row][column].GetX();
}

int Board::GetYAtPoint(const int& row, const int& column) {
	return _arrPoint[row][column].GetY();
}

bool Board::CheckPointAvailable(const int& row, const int& column) {
	if (_arrPoint[row][column]._isChoosing == 0) {
		return true;
	}
	return false;
}

void Board::ChoosingAtPoint(const int& row, const int& column, const int& XO) {
	_arrPoint[row][column].SetChoosing(XO);
}

int Board::CheckContain(const int& row, const int& column) {
	return _arrPoint[row][column]._isChoosing;
}

void Board::ResetBoard() {
	int i, j;
	for (i = 0; i < _size; i++) {
		for (j = 0; j < _size; j++) {
			_arrPoint[i][j].ResetPoint();
		}
	}
}

