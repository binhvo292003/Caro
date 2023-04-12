#include "Menu.h"

Menu::Menu() {
	SetUp();

	_numberIcon = 6;
	_colorIcon = new int[_numberIcon];
	_colorSquare = new int[_numberIcon];

	_numberTitle = 6;
	_colorTitle = new int[_numberTitle];
	_colorTitle[0] = RED;

	_colorIcon[0] = LIGHT_RED;
	_colorSquare[0] = BLACK;
	for (int i = 1; i < _numberTitle; i++) {
		_colorTitle[i] = BLACK;
		_colorIcon[i] = BLACK;
		_colorSquare[i] = AQUA;
	}

	_counter = 1;
	_countSound = 1;
	_flag = true;

}

Menu::~Menu() {
	_colorIcon = NULL;
	_colorSquare = NULL;
	delete _colorIcon;
	delete _colorSquare;

	_colorTitle = NULL;
	delete _colorTitle;
}

void Menu::ProcessCounter() {
	Sound::playBackground();

	switch (Common::GetEvent()) {
	case 1:		// UP
		if (_counter > 3) {
			Sound::playSound(OPTION_SOUND);
			_counter -= 3;
			break;
		}
		mciSendString(L"close option", NULL, 0, NULL);
		break;
	case 2:		// LEFT
		if (_counter > 1) {
			Sound::playSound(OPTION_SOUND);
			_counter--;
			break;
		}
		mciSendString(L"close option", NULL, 0, NULL);
		break;
	case 3:		// DOWN
		if (_counter < 4) {
			Sound::playSound(OPTION_SOUND);
			_counter += 3;
			break;
		}
		mciSendString(L"close option", NULL, 0, NULL);
		break;
	case 4:		// RIGHT
		if (_counter < 6) {
			Sound::playSound(OPTION_SOUND);
			_counter++;
			break;
		}
		mciSendString(L"close option", NULL, 0, NULL);
		break;
	case 5:
		Sound::playSound(SELECT_SOUND);
		SetUp2();
		switch (_counter) {
		case 1:
			NewGame();
			break;
		case 2:
			LoadGame();
			break;
		case 3:
			Setting();
			break;
		case 4:
			Help();
			break;
		case 5:
			About();
			break;
		case 6:
			Exit();
			_flag = false;
			break;
		default:
			break;
		}
		break;
		mciSendString(L"close option", NULL, 0, NULL);
	case 8:
		break;
	default:
		break;
	}
}

void Menu::SetUp() {
	Common::Color(BLACK, AQUA);
	system("cls");
	Common::SetConsole(16);
	Common::FixConsoleWindow();
	Common::ShowConsoleCursor(false);

	Graphic::DrawTitle();
	Graphic::DrawOCharacter();
	Graphic::DrawXCharacter();
	Graphic::DrawCloud();

	Sound::playBackground();
}

void Menu::SetUp2() {
	system("cls");
	Common::SetConsole(16);
	Common::FixConsoleWindow();
	Common::ShowConsoleCursor(false);
}

void Menu::RenderMenu() {
	while (_flag) {
		Graphic::DrawPlay(_colorIcon[0], _colorSquare[0]);

		Graphic::DrawLoad(_colorIcon[1], _colorSquare[1]);

		Graphic::DrawSetting(_colorIcon[2], _colorSquare[2]);

		Graphic::DrawHelp(_colorIcon[3], _colorSquare[3]);

		Graphic::DrawAbout(_colorIcon[4], _colorSquare[4]);

		Graphic::DrawExit(_colorIcon[5]);



		for (int i = 0; i < _numberIcon; i++) {
			_colorIcon[i] = BLACK;
			_colorSquare[i] = AQUA;
		}

		ProcessCounter();

		_colorSquare[_counter - 1] = BLACK;
		switch (_counter) {
		case 1:
			_colorIcon[_counter - 1] = LIGHT_RED;
			break;

		case 2:
			_colorIcon[_counter - 1] = BLUE;
			break;

		case 3:
			_colorIcon[_counter - 1] = YELLOW;
			break;

		case 4:
			_colorIcon[_counter - 1] = PURPLE;
			break;

		case 5:
			_colorIcon[_counter - 1] = LIGHT_AQUA;
			break;

		case 6:
			_colorIcon[_counter - 1] = RED;
			break;

		}
	}
}

void Menu::ResetMenu() {
	Common::Color(BLACK, AQUA);
	system("cls");
	Common::SetConsole(16);
	Common::FixConsoleWindow();
	Common::ShowConsoleCursor(false);
	Graphic::DrawTitle();
	Graphic::DrawOCharacter();
	Graphic::DrawXCharacter();
	Graphic::DrawCloud();

	_colorTitle[0] = RED;
	for (int i = 1; i < _numberTitle; i++) {
		_colorTitle[i] = BLACK;
	}

	_counter = 1;
	_flag = true;
}

void Menu::NewGame() {
	Common::Color(BLACK, WHITE);
	system("cls");
	Common::SetConsole(20);
	Graphic::PlayMode();

	bool isTwoPlayer = false;	// false PvP true Play with Bot

	int numberChoice = 2;
	int* colorChoice = new int[numberChoice];
	colorChoice[0] = GREEN;
	for (int i = 1; i < numberChoice; i++) {
		colorChoice[i] = BLACK;
	}

	int counter = 1;
	bool flag = true;
	bool flagBreak = true;

	while (flag) {
		Common::Color(colorChoice[0], WHITE);
		Graphic::DrawRectangle(52, 17, 6, 2);
		Common::GotoXY(55, 18); std::cout << "1 Player";

		Common::Color(colorChoice[1], WHITE);
		Graphic::DrawRectangle(52, 22, 6, 2);
		Common::GotoXY(55, 23); std::cout << "2 Player";

		for (int i = 0; i < numberChoice; i++) {
			colorChoice[i] = BLACK;
		}

		switch (Common::GetEvent()) {
		case 1: case 2:
			if (counter > 1) {
				Sound::playSound(4);
				counter--;
				break;
			}
			mciSendString(L"close option", NULL, 0, NULL);
			break;
		case 3:	case 4:
			if (counter < 2) {
				Sound::playSound(4);
				counter++;
				break;

			}
			mciSendString(L"close option", NULL, 0, NULL);
			break;
		case 5:
			switch (counter) {
			case 1:
				isTwoPlayer = false;
				flag = false;
				Sound::playSound(3);
				break;
				mciSendString(L"close select", NULL, 0, NULL);
			case 2:
				isTwoPlayer = true;
				flag = false;
				Sound::playSound(3);
				break;
				mciSendString(L"close select", NULL, 0, NULL);
			default:
				break;
			}
			break;
		case 7:						//esc
			flagBreak = false;
			flag = false;
			break;
		default:
			break;
		}

		colorChoice[counter - 1] = GREEN;
	}

	if (flagBreak) {
		Game* game;

		game = new Game(isTwoPlayer);
		game->Play();
	}

	ResetMenu();
}

void Menu::LoadGame() {
	Common::Color(BLACK, WHITE);
	system("cls");
	Common::SetConsole(20);
	vector<string> fileName;
	Graphic::LoadGameBackground();
	ifstream fi;
	fi.open("load.txt");
	if (!fi)
	{
		std::cout << "Cannot open file List Load" << endl;
	}
	else
	{
		string temp;
		while (!fi.eof())
		{
			getline(fi, temp);
			fileName.push_back(temp);
		}
	}
	fi.close();
	if (!fileName.size())
	{
		Common::GotoXY(42, 15);
		std::cout << "No game files were found!";
		Sleep(3000);
		return;
	}
	int file = 0;
	changeFile(fileName, file);

	int j = 20;
	int sz;

	if (fileName.size() < 8)
	{
		sz = fileName.size();
	}
	else
	{
		sz = 8;
	}

	bool chosen = 0;
	while (!chosen)
	{
		int key = Common::GetEvent();
		if (key == 7)
		{
			chosen = 1;
		}
		if (key == 5)
		{
			Game* g;
			g = new Game(fileName[file]);
			Sound::playSound(3);
			g->Play();
			chosen = 1;
			mciSendString(L"close select", NULL, 0, NULL);
		}
		else if (key == 1 || key == 2)
		{
			if (file == 0)
			{
				file = sz - 2;
				changeFile(fileName, file);
				Sound::playSound(4);
			}
			else
			{
				file--;
				changeFile(fileName, file);
				Sound::playSound(4);
			}
		}
		else if (key == 3 || key == 4)
		{
			if (file == sz - 2)
			{
				file = 0;
				changeFile(fileName, file);
				Sound::playSound(4);
			}
			else
			{
				file++;
				changeFile(fileName, file);
				Sound::playSound(4);
			}
		}
		else if (key == 1)
		{
			chosen = 1;
		}
		else
		{
			Sound::playSound(4);
		}
	}

	ResetMenu();
}

void Menu::Setting() {
	Common::Color(BLACK, WHITE);
	system("cls");
	Common::SetConsole(20);
	int counterVolume;
	int counterBackground;
	int counterPos = 1;


	ifstream volume("volume.txt");
	if (!volume.is_open())
	{
		cout << "loi doc file setting am thanh!" << endl;
	}

	volume >> counterVolume;
	volume >> counterBackground;
	if (counterVolume < 0 || counterVolume >5)
	{
		counterVolume = 1; //tra ve mac dinh
	}

	if (counterBackground < 0 || counterBackground >5)
	{
		counterBackground = 1; //tra ve mac dinh
	}
	volume.close();

	ofstream volumeout("volume.txt");
	if (!volumeout.is_open())
	{
		cout << "loi mo file setting am thanh!" << endl;
	}

	Graphic::DrawSettingChar();
	Common::GotoXY(48, 28);
	std::cout << "Press Esc to Continue";

	Graphic::Setting(counterVolume, counterBackground, BLACK, BLACK);
	bool flag = true;
	bool firstTime = true;
	while (flag) {

		if (counterPos == 1)
		{
			if (!firstTime) {
				Sound::playSound(OPTION_SOUND);
			}
			firstTime = false;
			Common::GotoXY(29, 14);
			Common::Color(RED, WHITE);
			cout << "Volume effects   : ";
			Common::GotoXY(29, 15);
			Common::Color(BLACK, WHITE);
			cout << "Volume background: ";
		}
		if (counterPos == 2)
		{
			Sound::playSound(OPTION_SOUND);
			Common::GotoXY(29, 14);
			Common::Color(BLACK, WHITE);
			cout << "Volume effects   : ";
			Common::GotoXY(29, 15);
			Common::Color(RED, WHITE);
			cout << "Volume background: ";
		}
		mciSendString(L"close option", NULL, 0, NULL);
		int count1 = Common::GetEvent();

		if (count1 == 1) {
			if (counterPos == 2)
			{
				counterPos = 1;
				Sound::playSound(4);
			}
			else if (counterPos == 1)
			{
				counterPos = 2;
				Sound::playSound(4);
			}
		}
		mciSendString(L"close option", NULL, 0, NULL);
		if (count1 == 3) {
			if (counterPos == 1)
			{
				counterPos = 2;
				Sound::playSound(4);
			}
			else if (counterPos == 2)
			{
				counterPos = 1;
				Sound::playSound(4);
			}
		}
		mciSendString(L"close option", NULL, 0, NULL);



		if (count1 == 5) {
			int colorEff = BLACK;
			int colorBg = BLACK;
			if (counterPos == 1) {
				Sound::playSound(3);
				colorEff = LIGHT_RED;
			}
			else {
				Sound::playSound(3);
				colorBg = LIGHT_RED;
			}
			Graphic::Setting(counterVolume, counterBackground, colorEff, colorBg);
			bool flag2 = true;
			while (flag2) {
				if (counterPos == 1)
				{
					switch (int count2 = Common::GetEvent()) {
					case 2:
						Sound::playSound(4);
						if (counterVolume > 0 && counterVolume <= 5)
						{
							counterVolume--;
							volumeout.seekp(0);
							volumeout << counterVolume << " " << counterBackground;
							Graphic::Setting(counterVolume, counterBackground, colorEff, colorBg);
						}
						break;
					case 4:
						Sound::playSound(4);
						if (counterVolume < 5 && counterVolume >= 0)
						{
							counterVolume++;
							volumeout.seekp(0);
							volumeout << counterVolume << " " << counterBackground;
							Graphic::Setting(counterVolume, counterBackground, colorEff, colorBg);

						}
						break;
					case 5:
					{
						colorEff = BLACK;
						colorBg = BLACK;
						Graphic::Setting(counterVolume, counterBackground, colorEff, colorBg);
						flag2 = false;
						Sound::playSound(3);
						break;
					}
					case 7:
					{
						volumeout.seekp(0);
						volumeout << counterVolume << " " << counterBackground;
						flag2 = false;
						flag = false;
						break;
					}
					}
				}

				if (counterPos == 2)
				{
					switch (int count2 = Common::GetEvent()) {
					case 2:
						Sound::playSound(4);
						if (counterBackground > 0 && counterBackground <= 5)
						{
							counterBackground--;
							volumeout.seekp(0);
							volumeout << counterVolume << " " << counterBackground;
							Graphic::Setting(counterVolume, counterBackground, colorEff, colorBg);
						}
						break;

					case 4:
						Sound::playSound(4);
						if (counterBackground < 5 && counterBackground >= 0)
						{
							counterBackground++;
							volumeout.seekp(0);
							volumeout << counterVolume << " " << counterBackground;
							Graphic::Setting(counterVolume, counterBackground, colorEff, colorBg);
						}
						break;

					case 5:
						colorEff = BLACK;
						colorBg = BLACK;
						Graphic::Setting(counterVolume, counterBackground, colorEff, colorBg);
						flag2 = false;
						Sound::playSound(3);
						break;


					case 7:
					{
						volumeout.seekp(0);
						volumeout << counterVolume << " " << counterBackground;
						flag2 = false;
						flag = false;
						break;
					}
					}
				}
			}
		}
		mciSendString(L"close option", NULL, 0, NULL);
		mciSendString(L"close select", NULL, 0, NULL);
		if (count1 == 7) {
			volumeout.seekp(0);
			volumeout << counterVolume << " " << counterBackground;
			flag = false;
		}
	}
	volumeout.close();
	Sound::stopBackground();
	Sound::playBackground();
	ResetMenu();
}

void Menu::Help() {
	Common::Color(BLACK, BLUE);
	system("cls");
	system("color 30");
	Common::SetConsole(20);
	Graphic::Help();
	system("pause");
	ResetMenu();
}

void Menu::About() {
	Common::Color(BLACK, WHITE);
	system("cls");
	Common::SetConsole(20);
	Graphic::About();
	system("pause");
	ResetMenu();
}

void Menu::Exit() {
	Common::Color(BLACK, WHITE);
	system("cls");
	Common::SetConsole(20);
	Common::GotoXY(35, 14);
	std::cout << "Press any key to close Caro game";
	Sleep(200);
	Common::ShowConsoleCursor(false);
	Common::Color(WHITE, WHITE);
	exit(0);
}

void Menu::changeFile(vector<string>& fileName, int& file)
{
	int j = 15;
	int sz;

	if (fileName.size() < 8)
	{
		sz = fileName.size();
	}
	else
	{
		sz = 8;
	}

	for (int i = 0; i < sz; i++)
	{
		Common::GotoXY(51, j);
		j++;
		if (i == file)
		{
			Common::Color(RED, WHITE);
			std::cout << fileName[i];
			Common::Color(BLACK, WHITE);
		}
		else
		{
			std::cout << fileName[i];
		}
	}
}
