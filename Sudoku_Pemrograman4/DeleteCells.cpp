#include "DeleteCells.h"
#include <iostream>

using namespace std;

DeleteCells::DeleteCells() {
	setX(0);
	setY(0);
}

DeleteCells::DeleteCells(int X, int Y) {
	setX(X);
	setY(Y);
}

void DeleteCells::setX(int X) {
	x = X;
}

void DeleteCells::setY(int Y) {
	y = Y;
}

int DeleteCells::getX() {
	return x;
}

int DeleteCells::getY() {
	return y;
}

void DeleteCells::execute() {
	cout << "Call execute function for DeleteCells" << endl;
	cout << "Tes " << getX() << " " << getY() << endl;
}

void DeleteCells::undo() {
	cout << "Call Undo Function for DeleteCells" << endl;
}