#include"FillCell.h"

FillCell::FillCell(Board &board, int row, int col, int playerInput)
{
	this->board = &board;
	this->row = row;
	this->col = col;
	this->playerInput = playerInput;
}
void FillCell::execute()
{
	board->SetBoxCoordinate(row, col, playerInput);
}

void FillCell::undo()
{
	board->DeleteBoxCoordinate(row, col);
}

void FillCell::redo()
{
	board->DeleteBoxCoordinate(row, col);
}