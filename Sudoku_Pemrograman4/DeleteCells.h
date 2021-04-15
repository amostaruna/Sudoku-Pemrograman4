#pragma once
#include "Command.h"
class DeleteCells : public Command{
	private:
		int x, y;
	public:
		DeleteCells();
		DeleteCells(int X, int Y);

		void setX(int X);
		void setY(int Y);

		int getX();
		int getY();

		void execute();
		void undo();
};