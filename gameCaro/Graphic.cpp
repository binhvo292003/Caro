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

	cout << title;
}

void Graphic::HelpBox() {
	Common::Color(BLACK, WHITE);
	DrawRectangle(65, 0, 15, 9);
	
	Common::GotoXY(76 , 1);
	cout  << "HELP BOX";

	//Common::ChangeFont(L"Consolas", 20, FW_BOLD);
	Common::GotoXY(67, 3);
	//cout << "↑,←,↓,→ : For moving";
	cout << "UP,RIGHT, : For moving";
	Common::GotoXY(67, 4);
	cout << "DOWN,LEFT";
	Common::GotoXY(67, 5);
	cout << "W,A,S,D";
	Common::GotoXY(67, 6);
	cout << "Enter   : For choosing";

	Common::GotoXY(67, 7);
	cout << "L       : Save Game";
	Common::GotoXY(67, 8);
	cout << "Esc     : Exit Game";

	Common::GotoXY(66, 2);
	for (int i = 0; i < 29; i++) {
		//cout << "─";
		cout << "-";
	}

	Graphic::DrawRectangle(65, 22, 15, 2);
	Common::GotoXY(66, 23);
	cout << "L: Save Game";
	Graphic::DrawRectangle(65, 26, 15, 2);
	Common::GotoXY(66, 27);
	cout << "Esc: Exit Game";

}

void Graphic::DrawAsciiX() {
	Common::GotoXY(74, 11); cout << "____    ____   ";
	Common::GotoXY(74, 12); cout << "\\   \\  /   / ";
	Common::GotoXY(74, 13); cout << " \\   \\/   /  ";
	Common::GotoXY(74, 14); cout << "  \\      /    ";
	Common::GotoXY(74, 15); cout << "  /      \\    ";
	Common::GotoXY(74, 16); cout << " /   /\\   \\  ";
	Common::GotoXY(74, 17); cout << "/___/  \\___\\ ";
}

void Graphic::DrawAsciiO() {
	Common::GotoXY(74, 11); cout << " ___________";
	Common::GotoXY(74, 12); cout << "|    ___    |";
	Common::GotoXY(74, 13); cout << "|   |   |   |";
	Common::GotoXY(74, 14); cout << "|   |   |   |";
	Common::GotoXY(74, 15); cout << "|   |   |   |";
	Common::GotoXY(74, 16); cout << "|   |___|   |";
	Common::GotoXY(74, 17); cout << "|___________|";
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
		//cout << "═";
		cout << "-";
	}

	//Ve canh ngoai phai
	for (int i = 1; i < height; i++) {
		Common::GotoXY(posX + realWidth, posY + i);
		//cout << "║";
		cout << "|";
	}


	//Ve canh duoi
	for (int i = 1; i < realWidth; i++) {
		Common::GotoXY(posX + i, posY + height);
		//cout << "═";
		cout << "-";
	}

	//Ve canh ngoai trai
	for (int i = 1; i < height; i++) {
		Common::GotoXY(posX, posY + i);
		//cout << "║";
		cout << "|";
	}

	Common::GotoXY(posX, posY);
	//cout << "╔";
	cout << "+";

	Common::GotoXY(posX + realWidth, posY);
	//cout << "╗";
	cout << "+";

	Common::GotoXY(posX + realWidth, posY + height);
	//cout << "╝";
	cout << "+";

	Common::GotoXY(posX, posY + height);
	//cout << "╚";
	cout << "+";
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

	cout << continueGameAscii;
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
	cout << endGameAscii;
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
	cout << XWin;
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
	cout << OWin;
}

void Graphic::DrawEnterToContinue() {
	
}

void Graphic::LoadGameBackground() {
	system("cls");
	DrawRectangle(0, 0, 48, 30);
	DrawRectangle(1, 1, 47, 28);
}

void Graphic::PlayMode() {
	Common::GotoXY(14, 7); cout << " _______  ___      _______  __   __    __   __  _______  ______   _______";
	Common::GotoXY(14, 8); cout << "|       ||   |    |   _   ||  | |  |  |  |_|  ||       ||      | |       |";
	Common::GotoXY(14, 9); cout << "|    _  ||   |    |  |_|  ||  |_|  |  |       ||   _   ||  _    ||    ___|";
	Common::GotoXY(14, 10); cout << "|   |_| ||   |    |       ||       |  |       ||  | |  || | |   ||   |___";
	Common::GotoXY(14, 11); cout << "|    ___||   |___ |       ||_     _|  |       ||  |_|  || |_|   ||    ___|";
	Common::GotoXY(14, 12); cout << "|    |   |       ||   _   |  |   |    | ||_|| ||       ||       ||   |___";
	Common::GotoXY(14, 13); cout << "|____|   |_______||__| |__|  |___|    |_|   |_||_______||______| |_______|";
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

	cout << saveGameAscii;
}