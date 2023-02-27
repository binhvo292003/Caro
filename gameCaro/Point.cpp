#include "Point.h"

Point::Point() {
	_x = 0;
	_y = 0;
	_isChoosing = 0;
}

Point::Point(const int& x, const int& y) {
	_x = x;
	_y = y;
	_isChoosing = 0;
}

int Point::GetX() {
	return _x;
}

int Point::GetY() {
	return _y;
}

void Point::SetXY(const int& x, const int& y) {
	_x = x;
	_y = y;
}

void Point::SetX(const int& x) {
	_x = x;
}

void Point::SetY(const int& y) {
	_y = y;
}

void Point::SetChoosing(const int& XO){
	if (_isChoosing != 0) {
		return;
	}
	if (XO == 1) {
		_isChoosing = 1;
		return;
	}
	_isChoosing = 2;
}

void Point::ResetPoint() {
	_isChoosing = 0;
}

int Point::ReturnChoosing() {
	return _isChoosing;
}