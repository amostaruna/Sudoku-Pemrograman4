#include "Invoker.h"
#include <iostream>

using namespace std;

Invoker::Invoker(){
	cout << "Initialization is successfull" << endl;
}

void Invoker::pushCommand(Command* command) {
	Commands.push(command);
	cout << "Command is added" << endl;
}

void Invoker::popCommand() {

	if (Commands.empty() == true) {
		cout << "The stack is empty" << endl;
	}
	else {
		cout << "command popped" << endl;
		Commands.top()->execute();
		Commands.pop();
	}
}