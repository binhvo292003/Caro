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
	static void DrawEnterToContinue();
};

#endif // !GRAPHIC
