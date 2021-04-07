#include"Command.h"
class DeleteCell :virtual Command
{
private:
	int Row;
	int col;
	int Pinput;
public:
	void Execute();
	void Undo();
};
void DeleteCell::Execute()
{
	// menghapus cell
}

inline void DeleteCell::Undo()
{
	//kembali ke state sebelumnya
}