#include<iostream>
using namespace std;
class Command
{
	virtual void Execute();
	virtual void Undo();
};