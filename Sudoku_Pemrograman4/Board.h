#include <iostream>

using namespace std;

class Board
{
private:
    int BoxCoordinate[9][9];
    
public:
    void DisplayBox(int i, int j);

};

void Board::DisplayBox(int i, int j)
{
    cout << "|| " << BoxCoordinate[i][j] << " ||" << endl;
    cout << "______________";
}