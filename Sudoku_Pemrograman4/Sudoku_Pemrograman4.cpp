#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Invoker.h"
#include "FillCell.h"
#include "DeleteCell.h"
using namespace std;

class Sudoku
{
protected:
    int choice;
    Invoker *UndoInvoker;
    Invoker *RedoInvoker;
public:
    void fillCell();
    void getMove();
    void gameUndo();
    void gameRedo();
    int coordinateCheck();
    void updateBoard();
    int isValidEntry();
    void play();
};


Board  board;
Player p1;
Sudoku sudoku;


int main()
{
    sudoku.play();
    return 0;
}

void Sudoku::fillCell()
{
    cout << "Entry number (1-9): ";
    p1.SetPlayerInput();


    FillCell *Command = new FillCell(board, board.col, board.row, p1.playerinput);
    Command->execute();
    UndoInvoker->pushCommand(*Command);
}

void Sudoku::getMove()
{
    char pilih;
    cout << "Pilih Aksi : " << endl;
    cout << "a.Input Number; b.Undo; c.Redo " << endl;
    cin >> pilih;
    switch (pilih)
    {
        case 'a':
        {
            string entry;
            cout << endl;
            cout << "Row and column of entry (separated by a comma): ";
            cin >> entry;

            stringstream ss(entry); // parse entry to ignore comma separator

            ss >> board.row;
            ss.ignore();
            ss >> board.col;

            while (!coordinateCheck()) // calls function to check if move is on the board - if not, asks for another set of coordinates
            {
                cout << "Please enter two integers between 1 and " << board.size << ": ";
                cin >> entry;

                stringstream ss(entry);

                ss >> board.row;
                ss.ignore();
                ss >> board.col;
            }
            fillCell();

            break;

            // entry number
            // cout << "Entry number (1-9): ";
            // p1.SetPlayerInput();
        }

        case 'b':
        {
            gameUndo();
            break;
        }

        case 'c':
        {
            gameRedo();
            break;
        }
        default:
            break;
    }
}

void Sudoku::gameUndo()
{
        if (!UndoInvoker->IsEmpty())
        {
            Command* command = UndoInvoker->GetCommand();
            command->undo();
            RedoInvoker->pushCommand(*command);
            UndoInvoker->popCommand();
        }
}

void Sudoku::gameRedo()
{
    if (!UndoInvoker->IsEmpty())
    {
        Command* command = UndoInvoker->GetCommand();
        command->redo();
        RedoInvoker->popCommand();
        UndoInvoker->pushCommand(*command);
    }
}

int Sudoku::coordinateCheck()
{
    if (board.row > board.size | board.col > board.size | board.row < 1 | board.col < 1) // on board
    {
        return 0;
    }
    else if (board.copyBox[board.row - 1][board.col - 1] != 0) // space taken already
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
    board.BoxCoordinate[board.row - 1][board.col - 1] = p1.GetPlayerInput();
}

int Sudoku::isValidEntry()
{
    //check for repeat in row
    for (int j = 0; j < board.size; j++)
    {
        if (board.BoxCoordinate[board.row - 1][j] == p1.GetPlayerInput())
        {
            cout << "Repeat in row." << endl;
            return 0;
        }
    }

    //check for repeat in column
    for (int i = 0; i < board.size; i++)
    {
        if (board.BoxCoordinate[i][board.col - 1] == p1.GetPlayerInput())
        {
            cout << "Repeat in column." << endl;
            return 0;
        }
    }

    //check for repeat in mini-grid
    int searchRow, searchCol; // first row and column of mini-grid

    if (board.row > 6)
        searchRow = 6;
    else if (board.row > 3)
        searchRow = 3;
    else
        searchRow = 0;

    if (board.col > 6)
        searchCol = 6;
    else if (board.col > 3)
        searchCol = 3;
    else
        searchCol = 0;

    for (int miniRow = searchRow; miniRow < searchRow + 3; miniRow++)
    {
        for (int miniCol = searchCol; miniCol < searchCol + 3; miniCol++)
        {
            if (board.BoxCoordinate[miniRow][miniCol] == p1.GetPlayerInput())
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

    board.insertBoard();

    while (! board.isBoardFull()) // while the board still has empty spaces
    {
        system("cls");
        board.DisplayBox();
        getMove();
        board.setTempNumber(p1.GetPlayerInput());
        while (!isValidEntry())
        {
            cout << "Invalid entry. Check your numbers. " << endl;
            getMove();
            board.setTempNumber(p1.GetPlayerInput());
        }
        updateBoard();
   }
   system("cls");
   board.DisplayBox();
   cout << endl << "Congratulations, you have won!" << endl; // board is full
}