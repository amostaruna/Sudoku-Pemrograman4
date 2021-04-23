#include "Invoker.h"
#include <iostream>

using namespace std;

Command* Invoker::GetCommand()
{
	return Commands.back();
}

void Invoker::pushCommand(Command &command)
{
	Commands.push_back(&command);
}

void Invoker::popCommand() {

	if (Commands.empty() == true) 
	{
		cout << "The stack is empty" << endl;
	}
	// cout << "command popped" << endl;
	// Commands.top()->execute();
	Commands.pop_back();
}
bool Invoker::IsEmpty() {
	return Commands.empty();
}