#include "Graphic.h"

void Graphic::DrawTitle() {
	Common::ShowConsoleCursor(false);
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);

	Common::Color(BLUE, AQUA);
	 
	Common::GotoXY(37, 5);  cout << R"(  ████████╗       ██████╗        █████████╗     ████████╗       )";
	Common::GotoXY(37, 6);  cout << R"( ███ ╔════╝      ███╔═███╗       ███╔══╗███    ███╔═══███╗      )";
	Common::GotoXY(37, 7);  cout << R"( ███ ║          ███╔╝ ╚███╗      █████████═╗   ███║   ███║      )";
	Common::GotoXY(37, 8);  cout << R"( ███ ║         ████████████╗     ███╔═══███║   ███║   ███║      )";
	Common::GotoXY(37, 9);  cout << R"(  ████████╗    ███ ╔════███║     ███║   ███║   ╚████████╔╝      )";
	Common::GotoXY(37, 10); cout << R"(  ╚═══════╝     ╚══╝    ╚══╝     ╚══╝   ╚══╝    ╚═══════╝       )";

	SetConsoleOutputCP(cp);
}

void Graphic::HelpBox() {
	Common::ShowConsoleCursor(false);
	Common::Color(BLACK, WHITE);
	DrawRectangle(75, 0, 15, 9);

	Common::GotoXY(86, 1);
	std::cout << "HELP BOX";

	//Common::ChangeFont(L"Consolas", 20, FW_BOLD);
	Common::GotoXY(77, 3);
	//std::cout << "↑,←,↓,→ : For moving";
	std::cout << "UP,RIGHT, : For moving";
	Common::GotoXY(77, 4);
	std::cout << "DOWN,LEFT";
	Common::GotoXY(77, 5);
	std::cout << "W,A,S,D";
	Common::GotoXY(77, 6);
	std::cout << "Enter   : For choosing";

	Common::GotoXY(77, 7);
	std::cout << "L       : Save Game";
	Common::GotoXY(77, 8);
	std::cout << "Esc     : Exit Game";

	Common::GotoXY(76, 2);
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
	Common::ShowConsoleCursor(false);
	Common::GotoXY(84, 11); std::cout << "____    ____   ";
	Common::GotoXY(84, 12); std::cout << "\\   \\  /   / ";
	Common::GotoXY(84, 13); std::cout << " \\   \\/   /  ";
	Common::GotoXY(84, 14); std::cout << "  \\      /    ";
	Common::GotoXY(84, 15); std::cout << "  /      \\    ";
	Common::GotoXY(84, 16); std::cout << " /   /\\   \\  ";
	Common::GotoXY(84, 17); std::cout << "/___/  \\___\\ ";
}

void Graphic::DrawAsciiO() {
	Common::ShowConsoleCursor(false);
	Common::GotoXY(84, 11); std::cout << " ___________";
	Common::GotoXY(84, 12); std::cout << "|    ___    |";
	Common::GotoXY(84, 13); std::cout << "|   |   |   |";
	Common::GotoXY(84, 14); std::cout << "|   |   |   |";
	Common::GotoXY(84, 15); std::cout << "|   |   |   |";
	Common::GotoXY(84, 16); std::cout << "|   |___|   |";
	Common::GotoXY(84, 17); std::cout << "|___________|";
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
	Common::ShowConsoleCursor(false);
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
             |_     _||   _   |    |      _||   _   ||   |_| ||_     _||   | |   |_| ||  | |  ||    ___|
               |   |  |  | |  |    |     |  |  | |  ||       |  |   |  |   | |       ||  |_|  ||   |___ 
               |   |  |  |_|  |    |     |  |  |_|  ||  _    |  |   |  |   | |  _    ||       ||    ___|
               |   |  |       |    |     |_ |       || | |   |  |   |  |   | | | |   ||       ||   |___ 
               |___|  |_______|    |_______||_______||_|  |__|  |___|  |___| |_|  |__||_______||_______|
  

                                                                               
)"""";

	std::cout << continueGameAscii;
}

void Graphic::EndGameAscii() {
	Common::ShowConsoleCursor(false);
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
	Common::ShowConsoleCursor(false);
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
	Common::ShowConsoleCursor(false);
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
	Common::ShowConsoleCursor(false);
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
	Common::Color(BLUE, WHITE);
	Common::ShowConsoleCursor(false);
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
}

void Graphic::PlayMode() {
	Common::ShowConsoleCursor(false);
	Common::GotoXY(20, 5);  std::cout << " _______  ___      _______  __   __    __   __  _______  ______   _______";
	Common::GotoXY(20, 6);  std::cout << "|       ||   |    |   _   ||  | |  |  |  |_|  ||       ||      | |       |";
	Common::GotoXY(20, 7);  std::cout << "|    _  ||   |    |  |_|  ||  |_|  |  |       ||   _   ||  _    ||    ___|";
	Common::GotoXY(20, 8); std::cout << "|   |_| ||   |    |       ||       |  |       ||  | |  || | |   ||   |___";
	Common::GotoXY(20, 9); std::cout << "|    ___||   |___ |       ||_     _|  |       ||  |_|  || |_|   ||    ___|";
	Common::GotoXY(20, 10); std::cout << "|    |   |       ||   _   |  |   |    | ||_|| ||       ||       ||   |___";
	Common::GotoXY(20, 11); std::cout << "|____|   |_______||__| |__|  |___|    |_|   |_||_______||______| |_______|";
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

void Graphic::DrawSettingChar(){
	Common::ShowConsoleCursor(false);
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	Common::Color(YELLOW, WHITE);
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

	Common::Color(BLACK, WHITE);
	const char* music_note = R""""(     

                                                                                                          ▄▄▀█
    ██▄                                                                                               ▄▄▀▀   █
    █  ▀                                                                                            █▀       █
    █                                                                                               █        █
 ▄███                                                                                               █     ▄███
 ▀██▀                                                                                            ▄███     ▀██▀
                                                                                                 ▀██▀                                            
)"""";
	std::cout << music_note;


	SetConsoleOutputCP(cp);
}
void Graphic::Setting(int counter, int counterBackground, int color_counter, int color_counterbg) {
	Common::ShowConsoleCursor(false);
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	//effects
	Common::GotoXY(48, 14);
	Common::Color(WHITE, WHITE);
	cout << R"(██████████████████████████████)";
	for (int i = 0; i < counter; i++)
	{
		Common::GotoXY(48 + 6 * i, 14);
		Common::Color(color_counter, WHITE);
		cout << R"(██████)";
	}

	//background
	Common::GotoXY(48, 15);
	Common::Color(WHITE, WHITE);
	cout << R"(██████████████████████████████)";
	for (int i = 0; i < counterBackground; i++)
	{
		Common::GotoXY(48 + 6 * i, 15);
		Common::Color(color_counterbg, WHITE);
		cout << R"(██████)";
	}

	SetConsoleOutputCP(cp);
	Common::GotoXY(38, 28);

}

void Graphic::About() {
	Common::ShowConsoleCursor(false);
	system("cls");
	SetConsoleOutputCP(CP_UTF8);
	Common::Color(GREEN, WHITE);
	const char* about = R""""(
                                       _______  _______  _______  __   __  _______ 
                                      |   _   ||  _    ||       ||  | |  ||       |
                                      |  |_|  || |_|   ||   _   ||  | |  ||_     _|
                                      |       ||       ||  | |  ||  | |  |  |   |  
                                      |       ||  _   | |  |_|  ||  |_|  |  |   |  
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
	Common::ShowConsoleCursor(false);
	system("cls");
	SetConsoleOutputCP(CP_UTF8);
	Common::Color(PURPLE, WHITE);
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
	                             
	            CÁCH CHƠI                                              LUẬT CHƠI

          ↑,←,↓,→          : Di chuyển                       1. Hai người chơi quyết định quân đi của   
          W,A,S,D                                            mình: một bên là chữ O và chữ X.
                                                             2. Người chơi đầu tiên đánh quân cờ của
          Enter, Space     : Chọn                            mình vào bàn cờ kích thước 15x15.
                                                             3. Tiếp đến là người chơi thứ hai.
          L                : Lưu tiến trình                  4. Người thắng cuộc là người đầu tiên có được
                                                             một chuỗi liên tục các ô gồm 5 quân hàng
          Esc              : Thoát game                      ngang, hoặc dọc, hoặc chéo.
                                      
                                                           Lưu ý: Người chơi không được phép đánh dấu
                                                           vào ô đã có đánh dấu của mình hoặc đối phương.
                                                          
                                                          
)"""";
	std::cout << infor;
	Common::GotoXY(38, 28);
}

void Graphic::DrawPlay(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = AQUA;

	Common::Color(square, bg);
	Common::GotoXY(26, 16); std::cout << R"(█▀          ▀█)";
	Common::GotoXY(26, 21); std::cout << R"(█▄          ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(26, 17); std::cout << R"(     ██▄      )";
	Common::GotoXY(26, 18); std::cout << R"(     ████▄    )";
	Common::GotoXY(26, 19); std::cout << R"(     ████▀    )";
	Common::GotoXY(26, 20); std::cout << R"(     ██▀      )";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawLoad(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = AQUA;

	Common::Color(square, bg);
	Common::GotoXY(60, 16); std::cout << R"(█▀         ▀█)";
	Common::GotoXY(60, 21); std::cout << R"(█▄         ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(60, 17); std::cout << R"(  █▀█▀▀▀█▀▄  )";
	Common::GotoXY(60, 18); std::cout << R"(  █ ▀▄▄▄▀ █  )";
	Common::GotoXY(60, 19); std::cout << R"(  █ ▄▄▄▄▄ █  )";
	Common::GotoXY(60, 20); std::cout << R"(  █▄█▄███▄█  )";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawSetting(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = AQUA;

	Common::Color(square, bg);
	Common::GotoXY(92, 16); cout << R"(█▀          ▀█)";
	Common::GotoXY(92, 21); cout << R"(█▄          ▄█)";

	Common::Color(icon, bg);
	Common::GotoXY(92, 17); std::cout << R"(    ▄█  █▄    )";
	Common::GotoXY(92, 18); std::cout << R"(   █  ▀▀  █   )";
	Common::GotoXY(92, 19); std::cout << R"(    ▀█  █▀    )";
	Common::GotoXY(92, 20); std::cout << R"(     █  █     )";
	Common::GotoXY(98, 21); std::cout << R"(▀▀)";

	SetConsoleOutputCP(cp);
}


void Graphic::DrawHelp(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = AQUA;

	Common::Color(square, bg);
	Common::GotoXY(42, 25); std::cout << R"(█▀           ▀█)";
	Common::GotoXY(42, 31); std::cout << R"(█▄           ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(42, 26); std::cout << R"(    ▄▄▄▄▄▄▄    )";
	Common::GotoXY(42, 27); std::cout << R"(   █ ■■■■■ █   )";
	Common::GotoXY(42, 28); std::cout << R"(   █ ■■■■■ █   )";
	Common::GotoXY(42, 29); std::cout << R"(   █ ■■■■■ █   )";
	Common::GotoXY(42, 30); std::cout << R"(    ▀▀▀▀▀▀▀    )";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawAbout(int icon, int square) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = AQUA;

	Common::Color(square, bg);
	Common::GotoXY(76, 25); std::cout << R"(█▀           ▀█)";
	Common::GotoXY(76, 31); std::cout << R"(█▄           ▄█)";
	Common::Color(icon, bg);
	Common::GotoXY(76, 26); std::cout << R"(     ▄▄▄▄▄     )";
	Common::GotoXY(76, 27); std::cout << R"(   ▄▀  ▄  ▀▄   )";
	Common::GotoXY(76, 28); std::cout << R"(   █   ▄   █   )";
	Common::GotoXY(76, 29); std::cout << R"(   ▀▄  ▀  ▄▀   )";
	Common::GotoXY(76, 30); std::cout << R"(     ▀▀▀▀▀     )";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawExit(int icon) {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	int bg = AQUA;

	Common::Color(icon, bg);
	Common::GotoXY(113, 33); cout << R"( ▄  █  ▄ )";
	Common::GotoXY(113, 34); cout << R"(█   █   █)";
	Common::GotoXY(113, 35); cout << R"(█       █)";
	Common::GotoXY(113, 36); cout << R"( ▀▄▄▄▄▄▀ )";


	SetConsoleOutputCP(cp);
}

void Graphic::DrawOCharacter() {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	//hat
	Common::Color(BLACK, AQUA);
	Common::GotoXY(7, 24); cout << R"(▄        ▄)";
	Common::GotoXY(5, 26); cout << R"(▄▄          ▄▄)";
	Common::Color(BLACK, GRAY);
	Common::GotoXY(8, 24); cout << R"(▀▀▀▀▀▀▀▀)";
	Common::GotoXY(7, 25); cout << R"(█   ██   █)";
	Common::GotoXY(7, 26); cout << R"(█▄▄▄▄▄▄▄▄█)";

	//oIcon
	Common::Color(BLACK, LIGHT_YELLOW);
	Common::GotoXY(11, 24); cout << R"(▀▀)";
	Common::GotoXY(11, 26); cout << R"(▄▄)";
	Common::Color(GRAY, LIGHT_YELLOW);
	Common::GotoXY(9, 25); cout << R"(█ ██ █)";

	//face
	Common::Color(BLACK, LIGHT_GREEN);
	Common::GotoXY(7, 27); cout << R"(█        █)";
	Common::GotoXY(7, 28); cout << R"(█ ██    ██)";
	Common::GotoXY(7, 29); cout << R"(█ ▀▀    ▀█)";
	Common::GotoXY(7, 30); cout << R"(█        █)";
	Common::GotoXY(7, 31); cout << R"(█▄▄▄ ▄ ▄ █)";

	//shadow
	Common::Color(GREEN, YELLOW);
	Common::GotoXY(8, 27); cout << R"(█)";
	Common::GotoXY(8, 28); cout << R"(█)";
	Common::GotoXY(8, 29); cout << R"(█)";
	Common::GotoXY(8, 30); cout << R"(█)";
	Common::Color(YELLOW, GREEN);
	Common::GotoXY(8, 31); cout << R"(▄)";

	//bottomBorder
	Common::Color(BLACK, AQUA);
	Common::GotoXY(7, 32); cout << R"(█        █)";
	Common::GotoXY(7, 33); cout << R"(█ ▄▀▀▀█ ▄▀)";
	Common::GotoXY(7, 34); cout << R"(▀▀    ▀▀)";

	//midBorder
	Common::Color(YELLOW, LIGHT_GREEN);
	Common::GotoXY(9, 31); cout << R"(▄▄ ▄ ▄ )";

	//feet
	Common::Color(YELLOW, BLACK);
	Common::GotoXY(8, 33); cout << R"(█▀)";
	Common::GotoXY(14, 33); cout << R"(█▀)";

	//body
	Common::Color(LIGHT_YELLOW, LIGHT_GREEN);
	Common::GotoXY(8, 32); cout << R"(███▄█ █▄)";


	//shield
	Common::Color(BLACK, AQUA);
	Common::GotoXY(17, 31); cout << R"(▄▀)";

	Common::GotoXY(19, 29); cout << R"(▄       ▄)";
	Common::GotoXY(20, 32); cout << R"(▀     ▀)";
	Common::GotoXY(22, 33); cout << R"(▀▀▀)";

	Common::Color(BLACK, YELLOW);
	Common::GotoXY(20, 29); cout << R"(▀▀▀▀▀▀▀)";
	Common::GotoXY(19, 30); cout << R"(█       █)";
	Common::GotoXY(19, 31); cout << R"(█       █)";
	Common::GotoXY(21, 32); cout << R"(▄   ▄)";


	SetConsoleOutputCP(cp);
}

void Graphic::DrawXCharacter() {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);

	//hat
	Common::Color(BLACK, AQUA);
	Common::GotoXY(108, 3); cout << R"(   ▄██▄████▄)";
	Common::GotoXY(108, 4); cout << R"( ▄██▄▀█▀▄█████▄)";
	Common::GotoXY(108, 5); cout << R"(█████▀▄▀███████)";
	Common::GotoXY(108, 6); cout << R"(████▄███▄██████)";

	//xIcon
	Common::Color(BLACK, BRIGHT_WHITE);
	Common::GotoXY(112, 4); cout << R"(▄▀█▀▄)";
	Common::GotoXY(112, 5); cout << R"(█▀▄▀█)";
	Common::GotoXY(112, 6); cout << R"(▄███▄)";

	//mask
	Common::Color(BLACK, WHITE);
	Common::GotoXY(110, 7); cout << R"(█▄  ▄▄ █▄▄█▄)";
	Common::GotoXY(110, 8); cout << R"(█▀  ▀▀ █▄▄▄█)";
	Common::GotoXY(110, 9); cout << R"(█▄██▄█▀▀  █)";

	//maskString
	Common::Color(BLACK, GRAY);
	Common::GotoXY(117, 8); cout << R"(█▄▄▄█)";

	//skin
	Common::Color(BLACK, LIGHT_YELLOW);
	Common::GotoXY(118, 7); cout << R"(▄▄█▄)";
	Common::GotoXY(116, 9); cout << R"(▀▀  █)";
	Common::Color(BLACK, AQUA);
	Common::GotoXY(121, 7); cout << R"(▄)";

	//body
	Common::Color(BLACK, LIGHT_RED);
	Common::GotoXY(111, 10); cout << R"(█        █)";
	Common::GotoXY(111, 11); cout << R"(█        █)";
	Common::GotoXY(111, 12); cout << R"(█  ▄▄▄▄  █)";

	Common::Color(LIGHT_PURPLE, LIGHT_RED);
	Common::GotoXY(117, 11); cout << R"(█)";

	//top line
	Common::Color(RED, LIGHT_RED);
	Common::GotoXY(112, 10); cout << R"(▀▀▀▀▀▀▀▀)";

	//feet
	Common::Color(BLACK, RED);
	Common::GotoXY(112, 13); cout << R"(▀▄█)";
	Common::GotoXY(118, 13); cout << R"(▀▄█)";
	Common::Color(BLACK, AQUA);
	Common::GotoXY(112, 13); cout << R"(▀)";
	Common::GotoXY(118, 13); cout << R"(▀)";

	//bottom line
	Common::Color(RED, LIGHT_RED);
	Common::GotoXY(112, 12); cout << R"(▄▄)";
	Common::GotoXY(118, 12); cout << R"(▄▄)";

	//bow
	Common::Color(BLACK, AQUA);
	Common::GotoXY(107, 8); cout << R"(▄█)";
	Common::GotoXY(105, 9); cout << R"(▄▀ █)";
	Common::GotoXY(103, 10); cout << R"(■■█■■█■■)";
	Common::GotoXY(105, 11); cout << R"(▀▄ █)";
	Common::GotoXY(107, 12); cout << R"(▀█)";

	//bow string
	Common::Color(WHITE, AQUA);
	Common::GotoXY(108, 9); cout << R"(█)";
	Common::GotoXY(108, 11); cout << R"(█)";
	Common::Color(BLACK, WHITE);
	Common::GotoXY(108, 10); cout << R"(■)";

	SetConsoleOutputCP(cp);
}

void Graphic::DrawCloud() {
	UINT cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);

	//cloud1
	Common::Color(BRIGHT_WHITE, BRIGHT_WHITE);
	Common::GotoXY(13, 4);  cout << R"(▄▀▀▀▀▀▄)";
	Common::GotoXY(9, 5);  cout << R"(▄▀▀▀▀      ▀▀▄)";
	Common::GotoXY(8, 6);  cout << R"(█              █)";
	Common::GotoXY(9, 7);  cout << R"(▀▄           █)";

	//border
	Common::Color(WHITE, AQUA);
	Common::GotoXY(13, 4);  cout << R"(▄)";
	Common::GotoXY(19, 4);  cout << R"(▄)";
	Common::GotoXY(9, 5);  cout << R"(▄)";
	Common::GotoXY(22, 5);  cout << R"(▄)";
	Common::GotoXY(9, 7);  cout << R"(▀)";
	Common::GotoXY(11, 8);  cout << R"(▀▀▀▀▀▀▀▀▀▀▀)";


	//cloud2
	Common::Color(BRIGHT_WHITE, BRIGHT_WHITE);
	Common::GotoXY(110, 25);  cout << R"(▄▀▀▀▀▀▄)";
	Common::GotoXY(106, 26);  cout << R"(▄▀▀▀▀      ▀▀▄)";
	Common::GotoXY(105, 27);  cout << R"(█              █)";
	Common::GotoXY(106, 28);  cout << R"(▀▄           █)";

	//border
	Common::Color(WHITE, AQUA);
	Common::GotoXY(109, 25);  cout << R"(▄)";
	Common::GotoXY(117, 25);  cout << R"(▄)";
	Common::GotoXY(106, 26);  cout << R"(▄)";
	Common::GotoXY(119, 26);  cout << R"(▄)";
	Common::GotoXY(105, 28);  cout << R"(▀)";
	Common::GotoXY(107, 29);  cout << R"(▀▀▀▀▀▀▀▀▀▀▀)";

	SetConsoleOutputCP(cp);
}