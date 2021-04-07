#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Board
{
    friend class Sudoku;
protected:
    int BoxCoordinate[9][9];
    int copyBox[9][9];
    int size; // size x size board
    int row; // currenty row coordinate
    int col; // current column
    int number; // current user entry
    
public:
    void insertBoard();
    void DisplayBox();
    int isBoardFull();
};
