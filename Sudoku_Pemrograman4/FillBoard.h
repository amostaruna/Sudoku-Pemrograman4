#pragma once
#include "Command.h"
#include "Board.h"
class FillBoard : public Command
{
	private : 
		int row, col, number;
	public :
		FillBoard() = default;
		FillBoard(Board &board, int, int, int);

		void execute();
		void undo();
};