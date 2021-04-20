#include "Board.h"

int Board::getBoxCoordinate(int row, int col)
{
    return BoxCoordinate[row][col];
}

void Board::SetBoxCoordinate(int row, int col, int number)
{
    BoxCoordinate[row][col] = number;
}
void Board::DeleteBoxCoordinate(int row, int col)
{
    BoxCoordinate[row][col] = ' ';
}

void Board::insertBoard()
{
    cout << "Enter the size of the board: ";
    cin >> size;

    string nameFile, file;
    cout << "Enter name of input file: ";
    cin >> nameFile;
    file = nameFile + ".txt";
    cout << endl;

    // sets of file reader
    ifstream inputFile(file.c_str());

    int tmp; // temporary templated variable

    // allocates and pushes entries into vector
    for (int i = 0; i < size; i++)
    {
        vector<int> row;
        for (int j = 0; j < size; j++)
        {
            inputFile >> tmp;
            row.push_back(tmp);
        }
        BoxCoordinate.push_back(row);
    }
    copyBox = BoxCoordinate;
}

void Board::DisplayBox()
{
    cout << "SUDOKU" << endl;
    cout << "======" << endl
        << endl;
    for (int i = 0; i < size; i++)
    {
        if (((i % 3) == 0) && i != 0) // horizontal dividers
        {
            for (int k = 0; k < 18; k++)
            {
                cout << "-";
            }
            cout << endl;
        }
        for (int j = 0; j < size; j++)
        {
            if (((j % 3) == 0) & j != 0) // vertical dividers
            {
                cout << "|";
                cout << BoxCoordinate[i][j];
            }
            else
                cout << " " << BoxCoordinate[i][j];
        }
        cout << endl;
    }
}

int Board::isBoardFull()
{
    //check if board is full
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (BoxCoordinate[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

//BoxCoordinate[1][2];

void Board::setTempNumber(int temp)
{
    tempNumber = temp;
}
int Board::getTempNumber()
{
    return tempNumber;
}