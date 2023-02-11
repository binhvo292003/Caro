#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <locale>
#include <codecvt>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

#define BW_BACKGROUND 240

#define LEFT 75
#define UP 72
#define RIGHT 77
#define DOWN 80

using namespace std;

struct Common {
	Common();
	~Common() {};
	static int GetEvent();
	static void GotoXY(const int& x, const int& y);
	static void Color(const int& colorText, const int& colorBackGround);
	static void FixConsoleWindow();
	static void MoveCenter();
	static void ResizeConsole(const int& width, const int& height);
	static void ChangeFont();
	static void ShowConsoleCursor(const bool& showFlag);
};

#endif // !COMMON
