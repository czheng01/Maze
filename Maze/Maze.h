#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Maze {
public:
	//contructor, called when class is created
	Maze(int rw, int cl);
	void createWall(int sr, int sc, int er, int ec); //starting row, starting column, ending row, ending column
	void print();
	bool startMovement();
	void setChar(char c, int r, int co);
	bool combat(int mh, int ma);

private:
	vector<vector<char>>maze; //list of char lists
	int ph;
	int pm;

};