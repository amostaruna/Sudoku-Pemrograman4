#include "Invoker.h"
#include <iostream>
#include

using namespace std;

/*Invoker::Invoker() 
{
	cout << "Initialization is successfull" << endl;
}
*/
Command* Invoker::GetCommand()
{
	return Commands.top();
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