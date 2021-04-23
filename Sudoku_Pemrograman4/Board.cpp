#include "Board.h"

int Board::getBoxCoordinate(int row, int col)
{
    return BoxCoordinate[row-1][col-1];
}

void Board::SetBoxCoordinate(int row, int col, int number)
{
    BoxCoordinate[row - 1][col - 1] = number;
}
void Board::DeleteBoxCoordinate(int row, int col)
{
    BoxCoordinate[row-1][col-1] = 0;
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
            if (((j % 3) == 0) && j != 0) // vertical dividers
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

int Board::isValidEntry()
{
    //check for repeat in row
   /* for (int j = 0; j < size; j++)
    {
        if (BoxCoordinate[row - 1][j] == number)
        {
            cout << "Repeat in row." << endl;
            cout << number << "|  row: " << row << "|  col: " << col << endl;
            return 0;
        }
    }

    //check for repeat in column
    for (int i = 0; i < size; i++)
    {
        if (BoxCoordinate[i][col - 1] == number)
        {
            cout << "Repeat in column." << endl;
            cout << number << "|  row: " << row << "|  col: " << col << endl;
            return 0;
        }
    }

    //check for repeat in mini-grid
    int searchRow, searchCol; // first row and column of mini-grid

    if (row > 6)
        searchRow = 6;
    else if (row > 3)
        searchRow = 3;
    else
        searchRow = 0;

    if (col > 6)
        searchCol = 6;
    else if (col > 3)
        searchCol = 3;
    else
        searchCol = 0;

    for (int miniRow = searchRow; miniRow < searchRow + 3; miniRow++)
    {
        for (int miniCol = searchCol; miniCol < searchCol + 3; miniCol++)
        {
            if (BoxCoordinate[miniRow][miniCol] == number)
            {
                cout << "Repeat in mini-grid" << endl;
                cout << number << "|  row: " << row << "|  col: " << col << endl;
                return 0;
            }
        }
    } */
    //cout << "Your input has entered" << endl;
    return 1;
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

int Board::getSize()
{
    return size;
}

int Board::getRow()
{
    return row;
}

int Board::getCol()
{
    return col;
}

int Board::getNumber()
{
    return number;
}

void Board::setNumber(int playerInput)
{
    number = playerInput;
}
