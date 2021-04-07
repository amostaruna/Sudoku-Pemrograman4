#include <iostream>
#include "Board.cpp"
#include "Player.cpp"
using namespace std;

class Sudoku
{
protected:
    int choice;

public:
    void getMove();
    int areCoordinatesValid();
    void updateBoard();
    int isValidEntry();
    void play();
};

Board b;
Player p1;
Sudoku sudoku;

int main()
{
    sudoku.play();
    return 0;
}

void Sudoku::getMove()
{
    string entry;
    cout << endl
         << "Row and column of entry (separated by a comma): ";
    cin >> entry;

    stringstream ss(entry); // parse entry to ignore comma separator

    ss >> b.row;
    ss.ignore();
    ss >> b.col;

    while (!areCoordinatesValid()) // calls function to check if move is on the board - if not, asks for another set of coordinates
    {
        cout << "Please enter two integers between 1 and " << b.size << ": ";
        cin >> entry;

        stringstream ss(entry);

        ss >> b.row;
        ss.ignore();
        ss >> b.col;
    }

    // entry number
    cout << "Entry number (1-9): ";
    p1.SetPlayerInput();
}

int Sudoku::areCoordinatesValid()
{
    if (b.row > b.size | b.col > b.size | b.row < 1 | b.col < 1) // on board
    {
        return 0;
    }
    else if (b.copyBox[b.row - 1][b.col - 1] != 0) // space taken already
    {
        cout << "Cannot override previous value" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}

void Sudoku::updateBoard()
{
    b.BoxCoordinate[b.row - 1][b.col - 1] = p1.GetPlayerInput();
}

int Sudoku::isValidEntry()
{
    //check for repeat in row
    for (int j = 0; j < b.size; j++)
    {
        if (b.BoxCoordinate[b.row - 1][j] == p1.GetPlayerInput())
        {
            cout << "Repeat in row." << endl;
            return 0;
        }
    }

    //check for repeat in column
    for (int i = 0; i < b.size; i++)
    {
        if (b.BoxCoordinate[i][b.col - 1] == p1.GetPlayerInput())
        {
            cout << "Repeat in column." << endl;
            return 0;
        }
    }

    //check for repeat in mini-grid
    int searchRow, searchCol; // first row and column of mini-grid

    if (b.row > 6)
        searchRow = 6;
    else if (b.row > 3)
        searchRow = 3;
    else
        searchRow = 0;

    if (b.col > 6)
        searchCol = 6;
    else if (b.col > 3)
        searchCol = 3;
    else
        searchCol = 0;

    for (int miniRow = searchRow; miniRow < searchRow + 3; miniRow++)
    {
        for (int miniCol = searchCol; miniCol < searchCol + 3; miniCol++)
        {
            if (b.BoxCoordinate[miniRow][miniCol] == p1.GetPlayerInput())
            {
                cout << "Repeat in mini-grid" << endl;
                return 0;
            }
        }
    }
    //cout << "Your input has entered" << endl;
    return 1;
}

void Sudoku::play()
{
    cout << "\t\t**Sudoku**\n\n";

    b.insertBoard();

    while (! b.isBoardFull()) // while the board still has empty spaces
    {
        system("cls");
        b.DisplayBox();
        getMove();
        while (!isValidEntry())
        {
            cout << "Invalid entry. Check your numbers. " << endl;
            getMove();
        }
        updateBoard();
   }
   system("cls");
   b.DisplayBox();
   cout << endl << "Congratulations, you have won!" << endl; // board is full
}