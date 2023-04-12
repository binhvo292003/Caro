#pragma once
#include "Common.h"

using namespace std;

struct Sound
{
	static void playX(wstring command);
	static void playO(wstring command);
	static void playWin(wstring command);
	static void playSelect(wstring command);
	static void playOption(wstring command);
	static void playXMoveSound(int counterVolume);
	static void playOMoveSound(int counterVolume);
	static void playWinSound(int counterVolume);
	static void playSelectSound(int counterVolume);
	static void playOptionSound(int counterVolumne);
	static void playSound(int i);
	static void playBackground();
	static void stopBackground();
};