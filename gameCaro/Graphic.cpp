#include "Graphic.h"

void Graphic::DrawTitle() {
	Common::Color(BLACK, WHITE);
	const char* title = R""""(
                          _____          _____         _____            _____    
                      ___|\    \     ___|\    \    ___|\    \      ____|\    \   
                     /    /\    \   /    /\    \  |    |\    \    /     /\    \  
                    |    |  |    | |    |  |    | |    | |    |  /     /  \    \ 
                    |    |  |____| |    |__|    | |    |/____/  |     |    |    |
                    |    |   ____  |    .--.    | |    |\    \  |     |    |    |
                    |    |  |    | |    |  |    | |    | |    | |\     \  /    /|
                    |\ ___\/    /| |____|  |____| |____| |____| | \_____\/____/ |
                    | |   /____/ | |    |  |    | |    | |    |  \ |    ||    | /
                     \|___|    | / |____|  |____| |____| |____|   \|____||____|/ 
                          |____|/                                              
                                                                                                                 
)"""";

	std::cout << title;
}

void Graphic::HelpBox() {
	Common::Color(BLACK, WHITE);
	DrawRectangle(65, 0, 15, 9);

	Common::GotoXY(76, 1);
	std::cout << "HELP BOX";

	//Common::ChangeFont(L"Consolas", 20, FW_BOLD);
	Common::GotoXY(67, 3);
	//std::cout << "↑,←,↓,→ : For moving";
	std::cout << "UP,RIGHT, : For moving";
	Common::GotoXY(67, 4);
	std::cout << "DOWN,LEFT";
	Common::GotoXY(67, 5);
	std::cout << "W,A,S,D";
	Common::GotoXY(67, 6);
	std::cout << "Enter   : For choosing";

	Common::GotoXY(67, 7);
	std::cout << "L       : Save Game";
	Common::GotoXY(67, 8);
	std::cout << "Esc     : Exit Game";

	Common::GotoXY(66, 2);
	for (int i = 0; i < 29; i++) {
		//std::cout << "─";
		std::cout << "-";
	}

	/*Graphic::DrawRectangle(65, 21, 15, 2);
	Common::GotoXY(66, 22);
	std::cout << "L: Save Game";
	Graphic::DrawRectangle(65, 25, 15, 2);
	Common::GotoXY(66, 26);
	std::cout << "Esc: Exit Game";*/

}

void Graphic::DrawAsciiX() {
	Common::GotoXY(74, 11); std::cout << "____    ____   ";
	Common::GotoXY(74, 12); std::cout << "\\   \\  /   / ";
	Common::GotoXY(74, 13); std::cout << " \\   \\/   /  ";
	Common::GotoXY(74, 14); std::cout << "  \\      /    ";
	Common::GotoXY(74, 15); std::cout << "  /      \\    ";
	Common::GotoXY(74, 16); std::cout << " /   /\\   \\  ";
	Common::GotoXY(74, 17); std::cout << "/___/  \\___\\ ";
}

void Graphic::DrawAsciiO() {
	Common::GotoXY(74, 11); std::cout << " ___________";
	Common::GotoXY(74, 12); std::cout << "|    ___    |";
	Common::GotoXY(74, 13); std::cout << "|   |   |   |";
	Common::GotoXY(74, 14); std::cout << "|   |   |   |";
	Common::GotoXY(74, 15); std::cout << "|   |   |   |";
	Common::GotoXY(74, 16); std::cout << "|   |___|   |";
	Common::GotoXY(74, 17); std::cout << "|___________|";
}

void Graphic::TurnBox() {
	DrawRectangle(65, 10, 15, 11);
	DrawAsciiX();
}

void Graphic::DrawRectangle(const int& posX, const int& posY, const int& width, const int& height) {
	int realWidth = width * 2;
	//Common::Color(BLACK, WHITE);

	//Ve canh tren
	for (int i = 1; i < realWidth; i++) {
		Common::GotoXY(posX + i, posY);
		//std::cout << "═";
		std::cout << "-";
	}

	//Ve canh ngoai phai
	for (int i = 1; i < height; i++) {
		Common::GotoXY(posX + realWidth, posY + i);
		//std::cout << "║";
		std::cout << "|";
	}


	//Ve canh duoi
	for (int i = 1; i < realWidth; i++) {
		Common::GotoXY(posX + i, posY + height);
		//std::cout << "═";
		std::cout << "-";
	}

	//Ve canh ngoai trai
	for (int i = 1; i < height; i++) {
		Common::GotoXY(posX, posY + i);
		//std::cout << "║";
		std::cout << "|";
	}

	Common::GotoXY(posX, posY);
	//std::cout << "╔";
	std::cout << "+";

	Common::GotoXY(posX + realWidth, posY);
	//std::cout << "╗";
	std::cout << "+";

	Common::GotoXY(posX + realWidth, posY + height);
	//std::cout << "╝";
	std::cout << "+";

	Common::GotoXY(posX, posY + height);
	//std::cout << "╚";
	std::cout << "+";
}

void Graphic::ContinueAscii() {
	const char* continueGameAscii = R""""(          
                     



     ______   _______      __   __  _______  __   __      _     _  _______  __    _  _______     
    |      | |       |    |  | |  ||       ||  | |  |    | | _ | ||   _   ||  |  | ||       |    
    |  _    ||   _   |    |  |_|  ||   _   ||  | |  |    | || || ||  |_|  ||   |_| ||_     _|    
    | | |   ||  | |  |    |       ||  | |  ||  |_|  |    |       ||       ||       |  |   |      
    | |_|   ||  |_|  |    |_     _||  |_|  ||       |    |       ||       ||  _    |  |   |      
    |       ||       |      |   |  |       ||       |    |   _   ||   _   || | |   |  |   |      
    |______| |_______|      |___|  |_______||_______|    |__| |__||__| |__||_|  |__|  |___|      
	
    _______  _______      _______  _______  __    _  _______  ___   __    _  __   __  _______ 
   |       ||       |    |       ||       ||  |  | ||       ||   | |  |  | ||  | |  ||       |
   |_     _||   _   |    |       ||   _   ||   |_| ||_     _||   | |   |_| ||  | |  ||    ___|
     |   |  |  | |  |    |       ||  | |  ||       |  |   |  |   | |       ||  |_|  ||   |___ 
     |   |  |  |_|  |    |      _||  |_|  ||  _    |  |   |  |   | |  _    ||       ||    ___|
     |   |  |       |    |     |_ |       || | |   |  |   |  |   | | | |   ||       ||   |___ 
     |___|  |_______|    |_______||_______||_|  |__|  |___|  |___| |_|  |__||_______||_______|
  

                                                                               
)"""";

	std::cout << continueGameAscii;
}

void Graphic::EndGameAscii() {
	const char* endGameAscii = R""""(          










		   _______  __    _  ______      _______  _______  __   __  _______ 
		  |       ||  |  | ||      |    |       ||   _   ||  |_|  ||       |
		  |    ___||   |_| ||  _    |   |    ___||  |_|  ||       ||    ___|
		  |   |___ |       || | |   |   |   | __ |       ||       ||   |___ 
		  |    ___||  _    || |_|   |   |   ||  ||       ||       ||    ___|
		  |   |___ | | |   ||       |   |   |_| ||   _   || ||_|| ||   |___ 
		  |_______||_|  |__||______|    |_______||__| |__||_|   |_||_______|                                                                       




)"""";
	std::cout << endGameAscii;
}

void Graphic::XWinGameAscii() {
	const char* XWin = R""""(








				 __   __    _     _  ___   __    _ 
				|  |_|  |  | | _ | ||   | |  |  | |
				|       |  | || || ||   | |   |_| |
				|       |  |       ||   | |       |
				 |     |   |       ||   | |  _    |
				|   _   |  |   _   ||   | | | |   |
				|__| |__|  |__| |__||___| |_|  |__|


)"""";
	std::cout << XWin;
}

void Graphic::OWinGameAscii() {
	const char* OWin = R""""(








				 _______    _     _  ___   __    _ 
				|       |  | | _ | ||   | |  |  | |
				|   _   |  | || || ||   | |   |_| |
				|  | |  |  |       ||   | |       |
				|  |_|  |  |       ||   | |  _    |
				|       |  |   _   ||   | | | |   |
				|_______|  |__| |__||___| |_|  |__|


)"""";
	std::cout << OWin;
}

void Graphic::DrawGameAscii() {
	const char* OWin = R""""(








				 ______    ______     _______   _     _ 
				|      |  |    _ |   |   _   | | | _ | |
				|  _    | |   | ||   |  |_|  | | || || |
				| | |   | |   |_||_  |       | |       |
				| |_|   | |    __  | |       | |       |
				|       | |   |  | | |   _   | |   _   |
				|______|  |___|  |_| |__| |__| |__| |__|


)"""";
	std::cout << OWin;
}

void Graphic::DrawEnterToContinue() {

}

void Graphic::LoadGameBackground() {
	system("cls");
	const char* loadGameAscii = R""""(          




                     
              ___      _______  _______  ______     _______  _______  __   __  _______ 
             |   |    |       ||   _   ||      |   |       ||   _   ||  |_|  ||       |
             |   |    |   _   ||  |_|  ||  _    |  |    ___||  |_|  ||       ||    ___|
             |   |    |  | |  ||       || | |   |  |   | __ |       ||       ||   |___ 
             |   |___ |  |_|  ||       || |_|   |  |   ||  ||       ||       ||    ___|
             |       ||       ||   _   ||       |  |   |_| ||   _   || ||_|| ||   |___ 
             |_______||_______||__| |__||______|   |_______||__| |__||_|   |_||_______|

                                                                               
)"""";
	std::cout << loadGameAscii;
	DrawRectangle(0, 0, 48, 30);
}

void Graphic::PlayMode() {
	Common::GotoXY(14, 7);  std::cout << " _______  ___      _______  __   __    __   __  _______  ______   _______";
	Common::GotoXY(14, 8);  std::cout << "|       ||   |    |   _   ||  | |  |  |  |_|  ||       ||      | |       |";
	Common::GotoXY(14, 9);  std::cout << "|    _  ||   |    |  |_|  ||  |_|  |  |       ||   _   ||  _    ||    ___|";
	Common::GotoXY(14, 10); std::cout << "|   |_| ||   |    |       ||       |  |       ||  | |  || | |   ||   |___";
	Common::GotoXY(14, 11); std::cout << "|    ___||   |___ |       ||_     _|  |       ||  |_|  || |_|   ||    ___|";
	Common::GotoXY(14, 12); std::cout << "|    |   |       ||   _   |  |   |    | ||_|| ||       ||       ||   |___";
	Common::GotoXY(14, 13); std::cout << "|____|   |_______||__| |__|  |___|    |_|   |_||_______||______| |_______|";
}

void Graphic::SaveGameAscii() {
	const char* saveGameAscii = R""""(          
                     



		 _______  _______  __   __  _______    _______  _______  __   __  _______ 
		|       ||   _   ||  | |  ||       |  |       ||   _   ||  |_|  ||       |
		|  _____||  |_|  ||  |_|  ||    ___|  |    ___||  |_|  ||       ||    ___|
		| |_____ |       ||       ||   |___   |   | __ |       ||       ||   |___ 
		|_____  ||       ||       ||    ___|  |   ||  ||       ||       ||    ___|
		 _____| ||   _   | |     | |   |___   |   |_| ||   _   || ||_|| ||   |___ 
		|_______||__| |__|  |___|  |_______|  |_______||__| |__||_|   |_||_______|
                                                                               
)"""";

	std::cout << saveGameAscii;
}

void Graphic::Common4Corners(int x, int y) {
	Common::Color(BLACK, WHITE);
	Common::GotoXY(x - 2, y - 1); std::cout << "+";
	Common::GotoXY(x + 2, y - 1); std::cout << "+";
	Common::GotoXY(x - 2, y + 1); std::cout << "+";
	Common::GotoXY(x + 2, y + 1); std::cout << "+";
}

void Graphic::Highlight4Corners(int x, int y) {
	SetConsoleOutputCP(CP_UTF8);
	Common::Color(BLACK, WHITE);
	Common::GotoXY(x - 2, y - 1); std::cout << "╔";
	Common::GotoXY(x + 2, y - 1); std::cout << "╗";
	Common::GotoXY(x - 2, y + 1); std::cout << "╚";
	Common::GotoXY(x + 2, y + 1); std::cout << "╝";
}

void Graphic::Normal4Corners(int x, int y) {
	Common::Color(BLACK, WHITE);
	Common::GotoXY(x - 2, y - 1); std::cout << "+";
	Common::GotoXY(x + 2, y - 1); std::cout << "+";
	Common::GotoXY(x - 2, y + 1); std::cout << "+";
	Common::GotoXY(x + 2, y + 1); std::cout << "+";
}

void Graphic::Setting() {
	system("cls");
	const char* setting = R""""(
			 _______  _______  _______  _______  ___   __    _  _______ 
			|       ||       ||       ||       ||   | |  |  | ||       |
			|  _____||    ___||_     _||_     _||   | |   |_| ||    ___|
			| |_____ |   |___   |   |    |   |  |   | |       ||   | __ 
			|_____  ||    ___|  |   |    |   |  |   | |  _    ||   ||  |
			 _____| ||   |___   |   |    |   |  |   | | | |   ||   |_| |
			|_______||_______|  |___|    |___|  |___| |_|  |__||_______|                                                            
)"""";
	std::cout << setting;
	Common::GotoXY(0, 12);
	Common::Color(BLACK, WHITE);
	const char* infor = R""""(
			M: TO TURN ON/OFF BACKGROUND SOUND
)"""";
	std::cout << infor;
	Common::GotoXY(38, 28);
}

void Graphic::About() {
	system("cls");
	SetConsoleOutputCP(CP_UTF8);
	const char* about = R""""(
			 _______  _______  _______  __   __  _______ 
			|   _   ||  _    ||       ||  | |  ||       |
			|  |_|  || |_|   ||   _   ||  | |  ||_     _|
			|       ||       ||  | |  ||  |_|  |  |   |  
			|       ||  _   | |  |_|  ||       |  |   |  
			|   _   || |_|   ||       ||       |  |   |  
			|__| |__||_______||_______||_______|  |___|                                                                   
)"""";
	std::cout << about;
	Common::GotoXY(0, 12);
	Common::Color(BLACK, WHITE);
	const char* infor = R""""(
	                              Thành viên:
                           Võ Quốc Bình            - 21127233
                           Hồ Đăng Phúc            - 22127492
                           Vũ Thái Thiện           - 22127399
                           Hồ Trương Viết Long     - 22127241
		
                                  Giáo viên hướng dẫn:
                           Trương Toàn Thịnh
)"""";
	std::cout << infor;
	Common::GotoXY(38, 28);
}

void Graphic::Help() {
	system("cls");
	SetConsoleOutputCP(CP_UTF8);
	const char* about = R""""(
			 __   __  _______  ___      _______ 
			|  | |  ||       ||   |    |       |
			|  |_|  ||    ___||   |    |    _  |
			|       ||   |___ |   |    |   |_| |
			|       ||    ___||   |___ |    ___|
			|   _   ||   |___ |       ||   |    
			|__| |__||_______||_______||___|                                                                     
)"""";
	std::cout << about;
	Common::GotoXY(0, 10);
	Common::Color(BLACK, WHITE);
	const char* infor = R""""(
	                             
	               HOW TO PLAY

                 ↑,←,↓,→          : For moving
                 W,A,S,D

                 Enter            : For choosing

                 L                : Save Game

                 M                : To mute/unmute sound background
 
                 Esc              : Exit Game 

)"""";
	std::cout << infor;
	Common::GotoXY(38, 28);
}

void Graphic::DrawPlay(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = WHITE;

	Common::Color(square, bg);
	Common::GotoXY(15, 16 - 3); std::cout << R"(█▀          ▀█)";
	Common::GotoXY(15, 21 - 3); std::cout << R"(█▄          ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(15, 17 - 3); std::cout << R"(     ██▄      )";
	Common::GotoXY(15, 18 - 3); std::cout << R"(     ████▄    )";
	Common::GotoXY(15, 19 - 3); std::cout << R"(     ████▀    )";
	Common::GotoXY(15, 20 - 3); std::cout << R"(     ██▀      )";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawLoad(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = WHITE;

	Common::Color(square, bg);
	Common::GotoXY(45, 16 - 3); std::cout << R"(█▀         ▀█)";
	Common::GotoXY(45, 21 - 3); std::cout << R"(█▄         ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(45, 17 - 3); std::cout << R"(  █▀█▀▀▀█▀▄  )";
	Common::GotoXY(45, 18 - 3); std::cout << R"(  █ ▀▄▄▄▀ █  )";
	Common::GotoXY(45, 19 - 3); std::cout << R"(  █ ▄▄▄▄▄ █  )";
	Common::GotoXY(45, 20 - 3); std::cout << R"(  █▄█▄███▄█  )";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawSetting(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = WHITE;

	Common::Color(icon, bg);
	Common::GotoXY(70, 17 - 3); std::cout << R"(    ▄█  █▄    )";
	Common::GotoXY(70, 18 - 3); std::cout << R"(   █  ▀▀  █   )";
	Common::GotoXY(70, 19 - 3); std::cout << R"(    ▀█  █▀    )";
	Common::GotoXY(70, 20 - 3); std::cout << R"(     █  █     )";
	Common::GotoXY(70, 21 - 3); std::cout << R"(      ▀▀      )";

	Common::Color(square, bg);
	Common::GotoXY(70, 16 - 3); std::cout << R"(█▀          ▀█)";
	Common::GotoXY(70, 21 - 3); std::cout << R"(█▄)";
	Common::GotoXY(82, 21 - 3); std::cout << R"(▄█)";

	SetConsoleOutputCP(cp);
}


void Graphic::DrawHelp(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = WHITE;

	Common::Color(square, bg);
	Common::GotoXY(28, 25 - 6); std::cout << R"(█▀           ▀█)";
	Common::GotoXY(28, 31 - 6); std::cout << R"(█▄           ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(28, 26 - 6); std::cout << R"(    ▄▄▄▄▄▄▄    )";
	Common::GotoXY(28, 27 - 6); std::cout << R"(   █ ■■■■■ █   )";
	Common::GotoXY(28, 28 - 6); std::cout << R"(   █ ■■■■■ █   )";
	Common::GotoXY(28, 29 - 6); std::cout << R"(   █ ■■■■■ █   )";
	Common::GotoXY(28, 30 - 6); std::cout << R"(    ▀▀▀▀▀▀▀    )";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawAbout(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = WHITE;

	Common::Color(square, bg);
	Common::GotoXY(58, 25 - 6); std::cout << R"(█▀           ▀█)";
	Common::GotoXY(58, 31 - 6); std::cout << R"(█▄           ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(58, 26 - 6); std::cout << R"(     ▄▄▄▄▄     )";
	Common::GotoXY(58, 27 - 6); std::cout << R"(   ▄▀  ▄  ▀▄   )";
	Common::GotoXY(58, 28 - 6); std::cout << R"(   █   ▄   █   )";
	Common::GotoXY(58, 29 - 6); std::cout << R"(   ▀▄  ▀  ▄▀   )";
	Common::GotoXY(58, 30 - 6); std::cout << R"(     ▀▀▀▀▀     )";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawExit(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = WHITE;

	Common::Color(square, bg);
	//Common::GotoXY(70, 25 - 5); std::cout << R"(█▀         ▀█)";
	//Common::GotoXY(70, 31 - 5); std::cout << R"(█▄         ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(80, 21 + 4); std::cout << R"(    █       )";
	Common::GotoXY(80, 22 + 4); std::cout << R"(▄▀  █  ▀▄   )";
	Common::GotoXY(80, 23 + 4); std::cout << R"(█   ▀   █   )";
	Common::GotoXY(80, 24 + 4); std::cout << R"(▀▄     ▄▀   )";
	Common::GotoXY(80, 25 + 4); std::cout << R"(  ▀▀▀▀▀     )";


	SetConsoleOutputCP(cp);
}
