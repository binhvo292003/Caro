#ifndef BOARD_H
#define BOARD_H

#include "Point.h"
#include "Common.h"

struct Board {
	int _x; //x Point 00
	int _y; //y Point 00
	int _stepX;
	int _stepY;
	int _size;
	int _edgeTop;
	int _edgeLeft;
	int _edgeBottom;
	int _edgeRight;
	Point** _arrPoint;

	Board(const int& size, const int& x, const int& y);
	~Board();

	void DrawBoard();
	int	GetXAtPoint(const int& row, const int& column);
	int GetYAtPoint(const int& row, const int& column);
	bool CheckPointAvailable(const int& row, const int& column);
	void ChoosingAtPoint(const int& row, const int& column, const int& XO);
	int CheckContain(const int& row, const int& column);
	void ResetBoard();
};



#endif // !BOARD
