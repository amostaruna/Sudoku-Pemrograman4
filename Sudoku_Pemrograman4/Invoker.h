#pragma once
#include "Command.h"
#include "DeleteCells.h"
#include "FillBoard.h"
#include <stack>

using namespace std;
class Invoker
{
private:
	stack<Command*> Commands;

public:
	Invoker();
	Command* GetCommand();
	void pushCommand(Command &command);
	void popCommand();
	bool IsEmpty();
}; 
