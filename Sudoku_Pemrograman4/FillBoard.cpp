#include "FillBoard.h"
#include <iostream>

using namespace std;

FillBoard::FillBoard(){
	setX(0);
	setY(0);
	setValue(0);
}

FillBoard::FillBoard(int X, int Y, int Value){
	setX(X);
	setY(Y);
	setValue(Value);
}

void FillBoard::setX(int X){
	x = X;
}

void FillBoard::setY(int Y) {
	y = Y;
}

void FillBoard::setValue(int Value) {
	value = Value;
}

int FillBoard::getX(){
	return x;
}

int FillBoard::getY() {
	return y;
}

int FillBoard::getValue() {
	return value;
}

void FillBoard::execute(){
	cout << "Call execute function for FillBoard" << endl;
	cout << "Tes " << getX() << " " << getY() << " " << getValue() << " " << endl;
}

void FillBoard::undo() {
	cout << "Call Undo Function for FillBoard" << endl;
}