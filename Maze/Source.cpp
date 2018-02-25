#include <iostream>
#include <string>
#include "Maze.h"

using namespace std;

int main() {

	Maze m(14, 14);
	m.createWall(0, 0, 0, 13);
	m.createWall(0, 0, 13, 0);
	m.createWall(0, 13, 13, 13);
	m.createWall(13, 0, 13, 13);
	m.createWall(0, 2, 9, 2);
	m.createWall(11, 1, 11, 4);
	m.createWall(4, 4, 11, 4);
	m.createWall(2, 4, 2, 10);
	m.createWall(2, 10, 4, 10);
	m.createWall(4, 6, 4, 10);
	m.createWall(6, 6, 11, 6);
	m.createWall(11, 6, 11, 13);
	m.createWall(6, 8, 6, 13);
	m.createWall(6, 8, 8, 8);
	m.createWall(8, 8, 8, 10);

	m.setChar('p', 1, 1);

	m.setChar('m', 2, 3);
	m.setChar('m', 4, 5);
	m.setChar('m', 6, 7);
	m.setChar('m', 12, 9);

	m.setChar('B', 10, 12);
	m.setChar('_', 11, 5);

	m.setChar('F', 12, 12);

	cout << "Press any key to begin the maze! p = player, m = monster, B = button, F = end. Use W, A, S, and D to move." << endl;

	m.startMovement();

	m.print();
}