#include "FillBoard.h"
#include <iostream>

using namespace std;

FillBoard::FillBoard(Board &board, int row, int col, int number)
{
	this->board = &board;
	this->row = row;
	this->col = col;
	this->number = number;
}

void FillBoard::execute()
{
	cout << "Call execute function for FillBoard" << endl;
	board->setBoxCoordinate(row, col, number);
}

void FillBoard::undo()
{
	cout << "Call Undo Function for FillBoard" << endl;
}