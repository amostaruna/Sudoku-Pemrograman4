#pragma once
#include "Command.h"
class FillBoard : public Command{

	private : 
		int x, y, value;
	public :
		FillBoard();
		FillBoard(int X, int Y, int Value);

		void setX(int X);
		void setY(int Y);
		void setValue(int Value);

		int getX();
		int getY();
		int getValue();

		void execute();
		void undo();
};