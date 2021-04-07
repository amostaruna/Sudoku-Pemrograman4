#include"Command.h"
class FillCell:virtual Command
{
private:
	int Row;
	int col;
	int Pinput;
public:
	void Execute();
	void Undo();

};
void FillCell::Execute()
{
	// b.BoxCoordinate[b.row - 1][b.col - 1] = p1.GetPlayerInput();
}

inline void FillCell::Undo()
{
	//kembali ke state sebelumnya
}
