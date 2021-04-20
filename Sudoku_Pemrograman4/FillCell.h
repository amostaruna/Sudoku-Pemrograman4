#pragma once
#include"Command.h"
#include"Board.h"
class FillCell:public Command
{
private:
	int row;
	int col;
	int playerInput;
	Board *board;
public:
	FillCell() = default;
	FillCell(Board &board, int row, int col, int playerInput);

	void execute();
	void undo();
	void redo();

};
