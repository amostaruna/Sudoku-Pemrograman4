#pragma once
#include"Command.h"
#include"Board.h"
class DeleteCell :public Command
{
private:
	int row;
	int col;
	int playerInput;
	Board *board;
public:
	DeleteCell() = default;
	DeleteCell(Board &board, int row, int col, int playerInput);
	void execute();
	void undo();
	void redo();
};