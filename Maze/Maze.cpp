#include "Maze.h"

Maze::Maze(int rw, int cl) {
	for (int i = 0; i < rw; i++) {
		vector<char> next;
		maze.push_back(next);
		for (int j = 0; j < cl; j++) {
			maze[i].push_back(' ');
		}
	}
	ph = 100;
	pm = 4;
}

void Maze::createWall(int sr, int sc, int er, int ec) {
	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			maze[i][j] = (char)177;
		}
	}
}

void Maze::print() {
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[i].size(); j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
}

bool Maze::combat(int mh, int ma) {

	while (true) {

		cout << "You have encountered a monster.  Defeat it to continue." << endl;
		cout << "player health: " << ph << endl;
		cout << "player mana: " << pm << endl;
		cout << "monster health: " << mh << endl;
		cout << "monster attack: " << ma << endl;

		cout << "What do you want to do?" << endl;
		cout << "1: physical attack (3 damage)" << endl;
		cout << "2: magic attack (6 mana, 6 damage)" << endl;
		cout << "3: defend (-1 monster attack)" << endl;
		cout << "4: heal (4 mana, 2 health)" << endl;

		int choice;
		cin >> choice;
		if (choice == 1) {
			mh -= 3;
		}
		else if (choice == 2) {
			if (pm >= 6) {
				mh -= 6;
				pm -= 6;
			}
			if (pm < 6) {
				ph -= 4;
				pm -= 2;
			}
		}
		else if (choice == 3) {
			ma -= 1;
			if (ma <= 0) {
				ph -= 1;
				ma += 1;
			}
		}
		else if (choice == 4) {
			if (pm >= 4) {
				ph += 2;
				pm -= 4;
			}
			if (pm < 4) {
				ph -= 2;
				pm -= 2;
			}
		}
		ph -= ma;
		if (mh <= 0) {
			cout << "You beat the monster!" << endl;
			return true;
		}
		if (ph <= 0) {
			cout << "The monster killed you." << endl;
			return false;
		}
		pm += 2;
		cin.ignore();
	}
}

bool Maze::startMovement() {

	srand(time(NULL));

	int pr = 1;
	int pc = 1;
	while (true) {
		char input = getch();
		int pr2 = pr;
		int pc2 = pc;

		if (input == 'w') {
			pr2--;
		}
		else if (input == 'a') {
			pc2--;
		}
		else if (input == 's') {
			pr2++;
		}
		else if(input == 'd') {
			pc2++;
		}
		if (maze[pr2][pc2] == ' ') {
			maze[pr][pc] = ' ';
			pr = pr2;
			pc = pc2;
			maze[pr][pc] = 'p';
		}
		else if (maze[pr2][pc2] == 'm') {
			int mh;
			int ma;
			if (pr2 == 2 && pc2 == 3) {
				mh = 30;
				ma = (rand() % 5) + 4;
			}
			if (pr2 == 4, pc2 == 5) {
				mh = 30;
				ma = (rand() % 5) + 4;
			}
			if (pr2 == 6 && pc2 == 7) {
				mh = 40;
				ma = (rand() % 5) + 6;
			}
			if (pr2 == 12 && pc2 == 9) {
				mh = 60;
				ma = (rand() % 5) + 6;
			}
			if (combat(mh, ma)) {
				maze[pr][pc] = ' ';
				pr = pr2;
				pc = pc2;
				maze[pr][pc] = 'p';
			}
			else {
				cout << "Better luck next time." << endl;
				return false;
			}
		}
		else if (maze[pr2][pc2] == '_') {
			cout << "You have reached a gate.  Find and press the button to unlock it." << endl;
			cin.ignore();
		}
		else if (maze[pr2][pc2] == 'B') {
			maze[11][5] = ' ';
		}
		else if (maze[pr2][pc2] == 'F') {
			cout << "You completed the maze!" << endl;
			return 0;
		}
		system("cls");
		print();
	}
}

void Maze::setChar(char c, int r, int co) {
	maze[r][co] = c;
}