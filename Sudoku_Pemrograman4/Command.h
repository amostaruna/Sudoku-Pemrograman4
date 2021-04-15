#pragma once
class Command{

	public:
		virtual void undo() {};
		virtual void execute() {};
};
