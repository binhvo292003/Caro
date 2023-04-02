#include <iostream>

#include "Menu.h"

using namespace std;

int main() {
	//sndPlaySound();
	SetConsoleOutputCP(CP_UTF8);

	Menu menu;
	menu.RenderMenu();

	return 0;
}