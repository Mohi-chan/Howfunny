#include <iostream>
#include <string>
using namespace std;
void BeforeGame(char (&player1)[11][11], char (&player2)[11][11]) { // ������� ���� �� ������������ ��������. ���� ���������
	char k = 'a';
	for (int i = 1; i < 11; i++) {
		player1[i][0] = k;
		player2[i][0] = k;
		player1[0][i] = k;
		player2[0][i] = k;
		k++;
	}	
}
void ShowBoard(char(&player1)[11][11], char(&player2)[11][11]) { //  ���������� ��� ����� �� ������
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << player1[i][j] << ' ';
		}
		cout << "    ";
		for (int j = 0; j < 11; j++) {
			cout << player2[i][j] << ' ';
		}
		cout << endl;
	}

}
bool Four(char(&sometable)[11][11], char a, char b, char c) {
	bool flag = true;
	switch (c) {
	case 'r': {
		for (int j = 0; j <4; j++) {
			if (sometable[a - 'a' + 1][b - 'a' + 1 + j] == '.' || sometable[a - 'a' + 1][b - 'a' + 1 + j] == '*') { flag = false; }
			if (flag != false) {
				sometable[a - 'a' + 1][b - 'a' + 1 + j] = '*';
			}
		}
		if (flag != false) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 6; j++) {
					if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0) && (b - 'a' + j<11) && (a - 'a' + i<11)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
				}
			}
		}
		break;
	}
	case 'd': {
		for (int i = 0; i <4; i++) {
			if (sometable[a - 'a' + 1 + i][b - 'a' + 1] == '.' || sometable[a - 'a' + 1 + i][b - 'a' + 1] == '*') { flag = false; }
			if (flag != false) {
				sometable[a - 'a' + 1 + i][b - 'a' + 1] = '*';
			}
		}
		if (flag != false) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0) && (b - 'a' + j<11) && (a - 'a' + i<11)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
				}
			}
		}
		break;
	}
	}
	return flag;
}
bool Three(char(&sometable)[11][11], char a, char b, char c) {
	bool flag = true;
	switch (c) {
	case 'r': {
		for (int j = 0; j <3; j++) {
			if (sometable[a - 'a' + 1][b - 'a' + 1 + j] == '.' || sometable[a - 'a' + 1][b - 'a' + 1 + j] == '*') { flag = false; }
			if (flag != false) { sometable[a - 'a' + 1][b - 'a' + 1 + j] = '*'; }
		}
		if (flag != false) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 5; j++) {
					if ((sometable[a - 'a' + i][b - 'a' + j] != '*') && (a - 'a' + i != 0) && (b - 'a' + j != 0) && (b - 'a' + j<11) && (a - 'a' + i<11)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
				}
			}
		}
		break;
	}
	case 'd': {
		for (int i = 0; i <3; i++) {
			if (sometable[a - 'a' + 1 + i][b - 'a' + 1] == '.' || sometable[a - 'a' + 1 + i][b - 'a' + 1] == '*') { flag = false; }
			if (flag != false) {
				sometable[a - 'a' + 1 + i][b - 'a' + 1] = '*';
			}
		}
		if (flag != false) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if ((sometable[a - 'a' + i][b - 'a' + j] != '*') && (a - 'a' + i != 0) && (b - 'a' + j != 0) && (b - 'a' + j<11) && (a - 'a' + i<11)) {
						sometable[a - 'a' + i][b - 'a' + j] = '.'; 
					}
					
				}
			}
		}
		break;
	}
	}
	return flag;
}
bool Two(char(&sometable)[11][11], char a, char b, char c) {
	bool flag = true;
	switch (c) {
	case 'r': {
		for (int j = 0; j <2; j++) {
			if (sometable[a - 'a' + 1][b - 'a' + 1 + j] == '.' || sometable[a - 'a' + 1][b - 'a' + 1 + j] == '*') { flag = false; }
			if (flag != false) { sometable[a - 'a' + 1][b - 'a' + 1 + j] = '*'; }
		}
		if (flag != false) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 4; j++) {
					if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0) && (b - 'a' + j<11) && (a - 'a' + i<11)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
				}
			}
		}
		break;
	}
	case 'd': {
		for (int i = 0; i <2; i++) {
			if (sometable[a - 'a' + 1+i][b - 'a' + 1] == '.' || sometable[a - 'a' + 1+i][b - 'a' + 1] == '*') { flag = false; }
			if (flag != false) {
				sometable[a - 'a' + 1 + i][b - 'a' + 1] = '*';
			}
		}
		if (flag != false) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 3; j++) {
					if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0) && (b - 'a' + j<11) && (a - 'a' + i<11)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
				}
			}
		}
		break;
	}
	}
	return flag;
}
bool One(char(&sometable)[11][11], char a, char b, char c) {
	bool flag = true;
	switch (c) {
	case 'r': {
		for (int j = 0; j <1; j++) {
			if (sometable[a - 'a' + 1][b - 'a' + 1 + j] == '.' || sometable[a - 'a' + 1][b - 'a' + 1 + j] == '*') { flag = false; }
			if (flag != false) { sometable[a - 'a' + 1][b - 'a' + 1 + j] = '*'; }
		}
		break;
	}
	case 'd': {
		for (int i = 0; i <1; i++) {
			if (sometable[a - 'a' + 1+ i][b - 'a' + 1] == '.' || sometable[a - 'a' +1 + i][b - 'a' + 1] == '*') { flag = false; }
			if (flag != false) {
				sometable[a - 'a' + 1 + i][b - 'a' + 1] = '*';
			}
		}
		break;
	}
	}
	if (flag != false) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0) && (b - 'a' + j<11) && (a - 'a' + i<11)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
			}
		}
	}
	return flag;
}
void Filling(char(&player1)[11][11], char(&player2)[11][11]) {
	// ������ ���������� - ����. ���� ������������ ����� �������� �� ������������ ������� ��� ��������� ������, �� ���� ����������� ����� � ��� ���������� ����������� �����
	bool flag;
	string str="abcdefhgij", str2="rd";
	char a, b, c;
	while (1) {
		ShowBoard(player1, player2);
		cout << "Enter coordinates and directons for 4 size(r for right and d for down)" << endl;
		cin >> a >> b >> c;
		if ((str.find(a)==-1 )|| (str.find(b) == -1) || (str2.find(c) == -1)){
			cout << "Wrong coordinates" << endl;
			system("pause");

			system("cls");
			continue;
		}
flag = Four(player1, a, b, c);
if (flag == false) {
	cout << "You can't place your ship here" << endl;
	system("pause");

	system("cls");
	continue;
}
else

break;
	}
	for (int i = 1; i < 3; i++) {
		system("cls");
		while (1) {
			ShowBoard(player1, player2);
			cout << "Enter coordinates and directons for 3 size(r for right and d for down)" << endl;
			cin >> a >> b >> c;
			if ((str.find(a) == -1) || (str.find(b) == -1) || (str2.find(c) == -1)) {
				cout << "Wrong coordinates" << endl;
				system("pause");

				system("cls");
				continue;
			}
			flag = Three(player1, a, b, c);
			if (flag == false) {
				cout << "You can't place your ship here" << endl;
				system("pause");

				system("cls");
				continue;
			}
			else

				break;
		}
	}
	for (int i = 1; i < 4; i++) {
		system("cls");
		while (1) {
			ShowBoard(player1, player2);
			cout << "Enter coordinates and directons for 2 size(r for right and d for down)" << endl;
			cin >> a >> b >> c;
			if ((str.find(a) == -1) || (str.find(b) == -1) || (str2.find(c) == -1)) {
				cout << "Wrong coordinates" << endl;
				system("pause");

				system("cls");
				continue;
			}
			flag = Two(player1, a, b, c);
			if (flag == false) {
				cout << "You can't place your ship here" << endl;
				system("pause");

				system("cls");
				continue;
			}
			else

				break;
		}
	}
	for (int i = 1; i < 5; i++) {
		system("cls");
		

		while (1) {
			ShowBoard(player1, player2);
			cout << "Enter coordinates and directons for 1 size(r for right and d for down)" << endl;
			cin >> a >> b >> c;
			if ((str.find(a) == -1) || (str.find(b) == -1) || (str2.find(c) == -1)) {
				cout << "Wrong coordinates" << endl;
				system("pause");

				system("cls");
				continue;
			}
			flag = One(player1, a, b, c);
			if (flag == false) {
				cout << "You can't place your ship here" << endl;
				system("pause");

				system("cls");
				continue;
			}
			else

				break;
		}
	}
	system("cls");
	ShowBoard(player1, player2);
	cout << "Change places with another player" << endl;
	system("pause");
		}
void Move_One(char(&player1)[11][11], char(&player2)[11][11], char(&player2_mirr)[11][11], int &shipsp) {
			bool flag = true;
			string str = "abcdefgihj";
			while (1) {
				char a, b;
   				while (1) {
					system("cls");
					ShowBoard(player1, player2_mirr);
					cout<<"Your board on the left and your apponent's on the right"<< endl << "Make your move. Another player has " << shipsp << " lives left" << endl;
					cin >> a >> b;
					if ((str.find(a) == -1) || (str.find(b) == -1)) {
						cout << "Wrong coordinates" << endl;
						system("pause");

						system("cls");
						continue;
					}
					if (player2_mirr[a - 'a' + 1][b - 'a' + 1] == 'X' || player2_mirr[a - 'a' + 1][b - 'a' + 1] == '0') {
						cout << "You have already been here" << endl;
						system("pause");
						continue;
					}
					if (player2[a - 'a' + 1][b - 'a' + 1] == '*') {
						player2_mirr[a - 'a' + 1][b - 'a' + 1] = 'X';
						player2[a - 'a' + 1][b - 'a' + 1] = 'X';
						shipsp = shipsp - 1;
						break;
					}
					else {
						flag = false;
						player2_mirr[a - 'a' + 1][b - 'a' + 1] = '0';
						player2[a - 'a' + 1][b - 'a' + 1] = '0';
						system("cls");
						ShowBoard(player1, player2_mirr);
						cout << "You've missed :( Please change place with another player." << endl;
						system("pause");
						system("cls");
						break;

					}
				}
				if (shipsp == 0) { flag = false; }
				if (flag == false) { break; }

				system("cls");
				ShowBoard(player1, player2_mirr);
			}
		}
bool Movement(char(&player1)[11][11], char(&player1_mirr)[11][11], char(&player2)[11][11], char(&player2_mirr)[11][11], int &shipsp1, int &shipsp2){
	bool turn=false; // false - ����� 1, true - ����� 2
	bool game=true; // ����������� ����. ��������� �� ������� ���������� ������ � ���������� ������. 1 - ������� 1, 0 -������� 2
	while (1) {
		if (shipsp1 == 0) {
			game = false;
			break;
		}
		if (shipsp2 == 0) {
			game = true;
			break;
		}
		if (turn == false) {
			cout << "Player1, please take your place" << endl;
			system("pause");
			Move_One(player1, player2, player2_mirr, shipsp2); 
		    turn = true;
			continue;
		}
		if (turn == true) {
			cout << "Player2, please take your place" << endl;
			system("pause");
			Move_One(player2, player1, player1_mirr, shipsp1);
			turn = false;
			continue;
		}
	}
	return game;
}

int main() {
	// ����������
	char player1[11][11] = {' '}, player2[11][11] = { ' ' }, player1_mirr[11][11] = { ' ' }, player2_mirr[11][11] = { ' ' };
	char answ;
	int shipsp1 = 20; // ���������� ������ - �������� ��������.
	int shipsp2 = 20;
	bool game;
	cout << "Hello. Here some rules" << endl;
	cout << "'*' - part of your ship" << endl;
	cout << "When part of the ship destroyed it will become 'X'" << endl;
	cout << "When you will fire on water '0' will be shown" << endl;
	cout << "Enjoy!" << endl;
	system("pause");
		while (1) {
		system("cls");
		BeforeGame(player1, player2);// ���������� �����
		BeforeGame(player1_mirr, player2_mirr); // ���������� ����������� �����
		cout << "Player 1, please, put your ships on board" << endl;
		system("pause");
		system("cls");
		Filling(player1, player2_mirr); // ����������� �������� 1 �������
		system("cls");
		cout << "Player 2." << endl;
		system("pause");
		system("cls");
		Filling(player2, player1_mirr); // ����������� �������� 2 �������
		system("cls");
		ShowBoard(player1, player2);
		system("cls");
		game = Movement(player1, player1_mirr, player2, player2_mirr, shipsp1, shipsp2);
		system("cls");
		ShowBoard(player1, player2);
		if (game == true) { cout << "Player 1 win" << endl; }
		else cout << "Player 2 win" << endl;
		cout << "One more time? Y or y for 'Yes' and any other key for 'No'" << endl;
		cin >> answ;
		if (answ == 'y' || answ == 'Y') { continue; }
		else break;
	}
	


	return 0;
}