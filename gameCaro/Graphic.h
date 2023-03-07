#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "Common.h"

struct Graphic {
	static void DrawTitle();
	static void DrawTable();
	static void DrawRectangle(const int& posX, const int& posY, 
							const int& width, const int& height);
	static void HelpBox();
	static void TurnBox();
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
};

#endif // !GRAPHIC
