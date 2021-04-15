#include<iostream>
#include "Command.h"
#include "Invoker.cpp"
#include "DeleteCells.cpp"
#include "FillBoard.cpp"

using namespace std;

int main() {

	Invoker Perintah;

	DeleteCells a(1, 2);
	FillBoard b(1, 2, 3);

	Command* c = &a;
	Command* d = &b;

	Perintah.pushCommand(c);
	Perintah.pushCommand(d);
	
	Perintah.popCommand();
}