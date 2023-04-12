#include "Sound.h"

void Sound::playSound(int i)
{
	int counterVolume;
	int counterBackground;
	ifstream sound("volume.txt");
	sound >> counterVolume;
	sound >> counterBackground;

	if (counterVolume < 0 || counterVolume > 5) {
		counterVolume = 1;
	}

	switch (i)
	{
	case 0:
		playWinSound(counterVolume);
		break;
	case 1:
		playXMoveSound(counterVolume);
		break;
	case 2:
		playOMoveSound(counterVolume);
		break;
	case 3:
		playSelectSound(counterVolume);
		break;
	case 4:
		playOptionSound(counterVolume);
		break;
	}
	sound.close();
}

void Sound::playBackground()
{
	int counterVolume;
	int counterBackground;
	ifstream sound("volume.txt");
	sound >> counterVolume;
	sound >> counterBackground;

	if (counterBackground < 0 || counterBackground > 5) {
		counterBackground = 1;
	}

	wstring bgsound;
	wstring command;
	switch (counterBackground)
	{
	case 0:
		break;
	case 1:
		bgsound = L"sound\\backgroundsound_1.wav";
		command = L"open \"" + bgsound + L"\" type waveaudio alias bgsound";
		mciSendString(command.c_str(), NULL, 0, NULL);
		mciSendString(L"play bgsound", NULL, 0, NULL);
		break;
	case 2:
		bgsound = L"sound\\backgroundsound_2.wav";
		command = L"open \"" + bgsound + L"\" type waveaudio alias bgsound";
		mciSendString(command.c_str(), NULL, 0, NULL);
		mciSendString(L"play bgsound", NULL, 0, NULL);
		break;
	case 3:
		bgsound = L"sound\\backgroundsound_3.wav";
		command = L"open \"" + bgsound + L"\" type waveaudio alias bgsound";
		mciSendString(command.c_str(), NULL, 0, NULL);
		mciSendString(L"play bgsound", NULL, 0, NULL);
		break;
	case 4:
		bgsound = L"sound\\backgroundsound_4.wav";
		command = L"open \"" + bgsound + L"\" type waveaudio alias bgsound";
		mciSendString(command.c_str(), NULL, 0, NULL);
		mciSendString(L"play bgsound", NULL, 0, NULL);
		break;
	case 5:
		bgsound = L"sound\\backgroundsound_5.wav";
		command = L"open \"" + bgsound + L"\" type waveaudio alias bgsound";
		mciSendString(command.c_str(), NULL, 0, NULL);
		mciSendString(L"play bgsound", NULL, 0, NULL);
		break;
	}
	sound.close();
}

void Sound::stopBackground() {
	mciSendString(L"close bgsound", NULL, 0, NULL);
}

void Sound::playX(wstring command) {
	mciSendString(command.c_str(), NULL, 0, NULL);
	mciSendString(L"play X from 0", NULL, 0, NULL);
}

void Sound::playO(wstring command) {
	mciSendString(command.c_str(), NULL, 0, NULL);
	mciSendString(L"play O from 0", NULL, 0, NULL);
}

void Sound::playWin(wstring command) {
	mciSendString(command.c_str(), NULL, 0, NULL);
	mciSendString(L"play win from 0", NULL, 0, NULL);
}

void Sound::playSelect(wstring command) {
	mciSendString(command.c_str(), NULL, 0, NULL);
	mciSendString(L"play select from 0", NULL, 0, NULL);
}

void Sound::playOption(wstring command) {
	mciSendString(command.c_str(), NULL, 0, NULL);
	mciSendString(L"play option from 0", NULL, 0, NULL);
}

void Sound::playXMoveSound(int counterVolume)
{
	wstring XMove;
	wstring command;
	switch (counterVolume)
	{
	case 0:
		break;
	case 1:
		XMove = L"sound\\X move_1.wav";
		command = L"open \"" + XMove + L"\" type waveaudio alias X";
		playX(command);
		break;
	case 2:
		XMove = L"sound\\X move_2.wav";
		command = L"open \"" + XMove + L"\" type waveaudio alias X";
		playX(command);
		break;
	case 3:
		XMove = L"sound\\X move_3.wav";
		command = L"open \"" + XMove + L"\" type waveaudio alias X";
		playX(command);
		break;
	case 4:
		XMove = L"sound\\X move_4.wav";
		command = L"open \"" + XMove + L"\" type waveaudio alias X";
		playX(command);
		break;
	case 5:
		XMove = L"sound\\X move_5.wav";
		command = L"open \"" + XMove + L"\" type waveaudio alias X";
		playX(command);
		break;
	}
}

void Sound::playOMoveSound(int counterVolume)
{
	wstring OMove;
	wstring command;
	switch (counterVolume)
	{
	case 0:
		break;
	case 1:
		OMove = L"sound\\O move_1.wav";
		command = L"open \"" + OMove + L"\" type waveaudio alias O";
		playO(command);
		break;
	case 2:
		OMove = L"sound\\O move_2.wav";
		command = L"open \"" + OMove + L"\" type waveaudio alias O";
		playO(command);
		break;
	case 3:
		OMove = L"sound\\O move_3.wav";
		command = L"open \"" + OMove + L"\" type waveaudio alias O";
		playO(command);
		break;
	case 4:
		OMove = L"sound\\O move_4.wav";
		command = L"open \"" + OMove + L"\" type waveaudio alias O";
		playO(command);
		break;
	case 5:
		OMove = L"sound\\O move_5.wav";
		command = L"open \"" + OMove + L"\" type waveaudio alias O";
		playO(command);
		break;
	}
}

void Sound::playWinSound(int counterVolume)
{
	wstring Win;
	wstring command;
	switch (counterVolume)
	{
	case 0:
		break;
	case 1:
		Win = L"sound\\Win sound_1.wav";
		command = L"open \"" + Win + L"\" type waveaudio alias win";
		playWin(command);
		break;
	case 2:
		Win = L"sound\\Win sound_2.wav";
		command = L"open \"" + Win + L"\" type waveaudio alias win";
		playWin(command);
		break;
	case 3:
		Win = L"sound\\Win sound_3.wav";
		command = L"open \"" + Win + L"\" type waveaudio alias win";
		playWin(command);
		break;
	case 4:
		Win = L"sound\\Win sound_4.wav";
		command = L"open \"" + Win + L"\" type waveaudio alias win";
		playWin(command);
		break;
	case 5:
		Win = L"sound\\Win sound_5.wav";
		command = L"open \"" + Win + L"\" type waveaudio alias win";
		playWin(command);
		break;
	}
}

void Sound::playSelectSound(int counterVolume)
{
	wstring Select;
	wstring command;
	switch (counterVolume)
	{
	case 0:
		break;
	case 1:
		Select = L"sound\\SELECT Button_1.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias select";
		playSelect(command);
		break;
	case 2:
		Select = L"sound\\SELECT Button_2.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias select";
		playSelect(command);
		break;
	case 3:
		Select = L"sound\\SELECT Button_3.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias select";
		playSelect(command);
		break;
	case 4:
		Select = L"sound\\SELECT Button_4.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias select";
		playSelect(command);
		break;
	case 5:
		Select = L"sound\\SELECT Button_5.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias select";
		playSelect(command);
		break;
	}
}

void Sound::playOptionSound(int counterVolume)
{
	wstring Select;
	wstring command;
	switch (counterVolume)
	{
	case 0:
		break;
	case 1:
		Select = L"sound\\change option sound_1.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias option";
		playOption(command);
		break;
	case 2:
		Select = L"sound\\change option sound_2.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias option";
		playOption(command);
		break;
	case 3:
		Select = L"sound\\change option sound_3.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias option";
		playOption(command);
		break;
	case 4:
		Select = L"sound\\change option sound_4.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias option";
		playOption(command);
		break;
	case 5:
		Select = L"sound\\change option sound_5.wav";
		command = L"open \"" + Select + L"\" type waveaudio alias option";
		playOption(command);
		break;
	}
}