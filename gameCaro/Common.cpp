#include "Common.h"

int Common::GetEvent() {
	int ch = _getch();
	if (ch == 0 || ch == 224){
		switch (_getch()) {
		case 72:	//UP
			return 1;
		case 75:	//LEFT
			return 2;
		case 80:	//DOWN
			return 3;
		case 77:	//RIGHT
			return 4;
		default:
			return 0;
		}
	}
	else {
		if (ch == 'W' || ch == 'w')
			return 1;
		else if (ch == 'A' || ch == 'a') 
			return 2;
		else if (ch == 'S' || ch == 's')
			return 3;
		else if (ch == 'D' || ch == 'd')
			return 4;
		else if (ch == '\r' || ch == ' ')             //Enter
			return 5;
		else if (ch == 'L' || ch == 'l')			  //Load
			return 6;
		else if (ch == 27)							  //ESC
			return 7;
		else
			return 0;
	}

}

void Common::GotoXY(const int& x, const int& y) {
	COORD cursor;
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Common::Color(const int& colorText, const int& colorBackGround) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorText + 16 * colorBackGround);

}

void Common::FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Common::MoveCenter() {
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	int posx, posy;
	posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
		posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,

		MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void Common::ResizeConsole(const int& width, const int& height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Common::ChangeFont() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	GetCurrentConsoleFontEx(GetConsoleWindow(), FALSE, &cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 20;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_BOLD;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Common::ShowConsoleCursor(const bool& showFlag){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int getRandomInt(int begin, int end){
	//srand(time(NULL));
	int n = rand() % (end - begin + 1) + begin;
	return n;
}

void Common::playSound(int i)
{
	static vector<const wchar_t*> soundFile{ L"sounds\\win.wav", L"sounds\\X_Move.wav",
		L"sounds\\O_Move.wav", L"sounds\\enter.wav", L"sounds\\background.wav",  L"sounds\\effect.wav" };
	PlaySound(soundFile[i], NULL, SND_FILENAME | SND_ASYNC);
}