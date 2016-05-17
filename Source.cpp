#include <iostream>
#include <string>
using namespace std;
void BeforeGame(char (&player1)[11][11], char (&player2)[11][11]) { // готовит поля до расставления кораблей.
	char k = 'a';
	for (int i = 1; i < 11; i++) {
		player1[i][0] = k;
		player2[i][0] = k;
		player1[0][i] = k;
		player2[0][i] = k;
		k++;
	}	
}
void ShowBoard(char(&player1)[11][11], char(&player2)[11][11]) {
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
void Four(char(&sometable)[11][11], char a, char b, char c) {
	switch (c) {
	case 'r': {
		for (int j = 0; j <4; j++) {
			sometable[a - 'a' + 1][b - 'a' + 1 + j] = '*';
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
			}
		}
		break;
	}
	case 'd': {
		for (int i = 0; i <4; i++) {
			sometable[a - 'a' + 1 + i][b - 'a' + 1] = '*';
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
			}
		}
		break;
	}
	}
}
void Three(char(&sometable)[11][11], char a, char b, char c) {
	switch (c) {
	case 'r': {
		for (int j = 0; j <3; j++) {
			sometable[a - 'a' + 1][b - 'a' + 1 + j] = '*';
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
			}
		}
		break;
	}
	case 'd': {
		for (int i = 0; i <3; i++) {
			sometable[a - 'a' + 1 + i][b - 'a' + 1] = '*';
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
			}
		}
		break;
	}
	}
}
void Two(char(&sometable)[11][11], char a, char b, char c) {
	switch (c) {
	case 'r': {
		for (int j = 0; j <2; j++) {
			sometable[a - 'a' + 1][b - 'a' + 1 + j] = '*';
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
			}
		}
		break;
	}
	case 'd': {
		for (int i = 0; i <2; i++) {
			sometable[a - 'a' + 1 + i][b - 'a' + 1] = '*';
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0)) { sometable[a - 'a' + i][b - 'a' + j] = '.'; }
			}
		}
		break;
	}
	}

}
bool One(char(&sometable)[11][11], char a, char b, char c) {
	bool flag = true;
	switch (c) {
	case 'r': {
		for (int j = 0; j <1; j++) {
			if (sometable[a - 'a' + 1][b - 'a' + 1 + j] == '.' || sometable[a - 'a' + 1][b - 'a' + 1 + j] == '*') { flag = false; }
			sometable[a - 'a' + 1][b - 'a' + 1 + j] = '*';
		}
		break;
	}
	case 'd': {
		for (int i = 0; i <1; i++) {
			if (sometable[a - 'a' + 1+ i][b - 'a' + 1] == '.' || sometable[a - 'a' +1 + i][b - 'a' + 1] == '*') { flag = false; }
			sometable[a - 'a' + 1 + i][b - 'a' + 1] = '*';
		}
		break;
	}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sometable[a - 'a' + i][b - 'a' + j] != '*' && (a - 'a' + i != 0) && (b - 'a' + j != 0)) { sometable[a - 'a'+i][b - 'a'+j] = '.'; }
		}
	}
	return flag;
}
void Filling(char(&player1)[11][11], char(&player2)[11][11]) {
	bool flag;
	char a, b, c;
	ShowBoard(player1, player2);
	/*cout << "Enter coordinates and directons for 4 size(r for right and d for down)"<< endl;
	cin >> a >> b >> c;
	Four(player1,a,b,c);
	for (int i = 1; i < 3; i++) {
		system("cls");
		ShowBoard(player1, player2);
		cout << "Enter coordinates and directons for 3 size(r for right and d for down)" << endl;
		cin >> a >> b >> c;
		Three(player1, a, b, c);
	}
	for (int i = 1; i < 4; i++) {
		system("cls");
		ShowBoard(player1, player2);
		cout << "Enter coordinates and directons for 2 size(r for right and d for down)" << endl;
		cin >> a >> b >> c;
		Two(player1, a, b, c);
	}*/
	for (int i = 1; i < 5; i++) {
		system("cls");
		ShowBoard(player1, player2);
		cout << "Enter coordinates and directons for 1 size(r for right and d for down)" << endl;
		
			cin >> a >> b >> c;
			flag = One(player1, a, b, c);
			if (flag == false) { continue; }
			else break;
			
			
		
	}
	system("cls");
	ShowBoard(player1, player2);
	cout << "Change places with another player" << endl;
		}
void Move(char(&player1)[11][11], char(&player2)[11][11], char(&player1_mirr)[11][11] ) {
	char a, b;
	ShowBoard(player1, player2);
	cout << "Make your move" << endl;
	cin >> a >> b;
	if (player2[a - 'a' + 1][b - 'a' + 1] == '*') {
		player1_mirr[a - 'a' + 1][b - 'a' + 1] = 'X';
	}
	else player1_mirr[a - 'a' + 1][b - 'a' + 1] = '0';
	system("cls");
	ShowBoard(player1, player1_mirr);
}

int main() {
	// заполнение
	char player1[11][11] = {' '}, player2[11][11] = { ' ' }, player1_mirr[11][11] = { ' ' }, player2_mirr[11][11] = { ' ' };
	BeforeGame(player1,player2);
	BeforeGame(player1_mirr, player2_mirr);
	Filling(player1, player2_mirr);
	system("cls");
	Filling(player2, player1_mirr);
	system("cls");
	ShowBoard(player1, player2);
	system("cls");
	Move(player1, player2, player2_mirr);
	cout << "test";
	
	
	


	return 0;
}