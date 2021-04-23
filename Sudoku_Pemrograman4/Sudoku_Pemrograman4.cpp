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
        Board  *board;
        Player *player;
        Invoker *UndoInvoker;
        Invoker *RedoInvoker;
    public:
        Sudoku();
        void getMove();
        void gameUndo();
        void gameRedo();
        int coordinateCheck();
        void input();
        void play();
};
Sudoku sudoku;

Sudoku::Sudoku()
{
    board = new Board();
    player = new Player();
    UndoInvoker = new Invoker();
    RedoInvoker = new Invoker();
}

int main()
{
    sudoku.play();
    return 0;
}

void Sudoku::play()
{
    cout << "\t\t**Sudoku**\n\n";

    board->insertBoard();

    while (!board->isBoardFull()) // while the board still has empty spaces
    {
        system("cls");
        board->DisplayBox();
        getMove();

        while (!board->isValidEntry())
        {
            cout << "Invalid entry. Check your numbers. " << endl;
            input();
        }
    }
    system("cls");
    board->DisplayBox();
    cout << endl << "Congratulations, you have won!" << endl; // board is full
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
            input();
            break;
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

void Sudoku::input()
{
    string entry;
    cout << endl;
    cout << "Row and column of entry (separated by a comma): ";
    cin >> entry;

    stringstream ss(entry); // parse entry to ignore comma separator

    ss >> board->row;
    ss.ignore();
    ss >> board->col;

    while (!coordinateCheck()) // calls function to check if move is on the board - if not, asks for another set of coordinates
    {
            cout << "Please enter two integers between 1 and " << board->getSize() << ": ";
        cin >> entry;

        stringstream ss(entry);

        ss >> board->row;
        ss.ignore();
        ss >> board->col;

        cout << "Entry number (1-9): ";
        player->SetPlayerInput();
        board->setNumber(player->GetPlayerInput());

        FillCell* Command = new FillCell(*board, board->getRow(), board->getCol(), board->getNumber());
        Command->execute();
        UndoInvoker->pushCommand(*Command);
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
    if (board->getRow() > board->getSize() || board->getCol() > board->getSize() || board->getRow() < 1 || board->getCol() < 1) // on board
    {
        return 0;
    }
    else if (board->copyBox[board->getRow() - 1][board->getCol() - 1] != 0) // space taken already
    {
        cout << "Cannot override previous value" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}