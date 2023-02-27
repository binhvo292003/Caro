#ifndef POINT_H
#define POINT_H

struct Point {
	int _x;
	int _y;
	int _isChoosing; // 0: available, 1: X, 2: O  

	Point();
	Point(const int& x, const int& y);
	int GetX();
	int GetY();
	void SetXY(const int& x, const int& y);
	void SetX(const int&);
	void SetY(const int&);
	void SetChoosing(const int& XO);
	void ResetPoint();
	int ReturnChoosing();
};

#endif // !1
