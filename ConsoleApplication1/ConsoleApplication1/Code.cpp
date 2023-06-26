#include <iostream>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;

void Setup() {
	gameOver = false;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < width + 1; i++) cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) cout << "#";
			cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++) cout << "#";
	cout << endl;
}

void Input() {

}

void Logic() {

}

int main() {
	Setup();
	Draw();
	Input();
	Logic();
	return 0;
}