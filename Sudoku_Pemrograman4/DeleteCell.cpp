#include"DeleteCell.h"

DeleteCell::DeleteCell(Board &board, int row, int col, int playerInput)
{
	this->board = &board;
	this->row = row;
	this->col = col;
	this->playerInput = playerInput;
}
void DeleteCell::execute()
{
	board->DeleteBoxCoordinate(row, col);
}

void DeleteCell::undo()
{
	board->DeleteBoxCoordinate(row, col);
}

void DeleteCell::redo()
{
	board->DeleteBoxCoordinate(row, col);
}