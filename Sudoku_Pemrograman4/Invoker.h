#pragma once
#include "Command.h"
#include "DeleteCells.h"
#include "FillBoard.h"
#include <vector>

using namespace std;
class Invoker
{
private:
	vector<Command*> Commands;

public:
	Invoker() = default;
	Command* GetCommand();
	void pushCommand(Command &command);
	void popCommand();
	bool IsEmpty();
}; 
