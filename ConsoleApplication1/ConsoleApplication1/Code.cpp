#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

bool gameOver;
const int field_size = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void initField(char** field) {
	for (int i = 1; i < field_size - 1; i++) for (int j = 1; j < field_size - 1; j++) field[i][j] = ' ';

	for (int i = 0; i < field_size; i++) field[0][i] = '#';
	for (int i = 0; i < field_size; i++) field[field_size - 1][i] = '#';
	for (int i = 0; i < field_size; i++) field[i][field_size - 1] = '#';
	for (int i = 0; i < field_size; i++) field[i][0] = '#';
}

void showArray(char** array) {
	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << array[i][j] << "";
		}
		cout << endl;
	}
	cout << endl;
}

void Setup() {
	gameOver = false;
	dir = STOP;
	x = field_size / 2 - 1;
	y = field_size / 2 - 1;
	fruitX = rand() % field_size;
	fruitY = rand() % field_size;
	score = 0;
}

void Render(char** field) {
	system("cls");
	initField(field);
	showArray(field);
	for (int i = 0; i < field_size; i++) {
		for (int j = 0; j < field_size; j++) {
			if (i == y && j == x) field[i][j] = '0';
			else if (i == fruitY && j == fruitX) field[i][j] = 'F';
			else field[i][j] = ' ';
		}
	}
	cout << endl;
	cout << "Score: " << score << endl;
}

void Keyboard() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic(char** field) {
	switch (dir) {
	case LEFT:
		field[y][x--];
		break;
	case RIGHT:
		field[y][x++];
		break;
	case UP:
		field[y--][x];
		break;
	case DOWN:
		field[y++][x];
		break;
	}

	if (x > field_size || x < 0 || y > field_size || y < 0) gameOver = true;
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % field_size;
		fruitY = rand() % field_size;
	}
}

int main() {
	char** field = new char* [field_size];
	for (int i = 0; i < field_size; i++) field[i] = new char[field_size] {};
	Setup();
	while (!gameOver) {
		Render(field);
		Keyboard();
		Logic(field);
		Sleep(200);
	}
	return 0;
}