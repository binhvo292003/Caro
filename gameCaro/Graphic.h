#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "Common.h"
#include <cstdio>
#pragma execution_character_set("utf-16")

using namespace std;

struct Graphic {
	static void DrawTitle();
	static void DrawTable();
	static void DrawRectangle(const int& posX, const int& posY,
		const int& width, const int& height);
	static void HelpBox();
	static void DrawAsciiX();
	static void DrawAsciiO();
	static void EndGameAscii();
	static void ContinueAscii();
	static void XWinGameAscii();
	static void OWinGameAscii();
	static void DrawGameAscii();
	static void DrawEnterToContinue();
	static void LoadGameBackground();
	static void PlayMode();
	static void SaveGameAscii();
	static void Common4Corners(int x, int y);
	static void Highlight4Corners(int x, int y);
	static void Normal4Corners(int x, int y);

	static void DrawSettingChar();
	static void Setting(int counter, int counterBackground, int color_counter, int color_counterbg);
	static void About();
	static void Help();
	static void PauseGame();

	static void DrawPlay(int icon, int square);
	static void DrawLoad(int icon, int square);
	static void DrawSetting(int icon, int square);
	static void DrawHelp(int icon, int square);
	static void DrawAbout(int icon, int square);
	static void DrawExit(int icon);
	static void DrawOCharacter();
	static void DrawXCharacter();
	static void DrawCloud();
};

#endif // !GRAPHIC
