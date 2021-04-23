#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Board
{
    friend class Sudoku;
protected:
    vector<vector<int>> BoxCoordinate;
    vector<vector<int>> copyBox;
    string file = "easy.txt";
    int size; // size x size board
    int row; // currenty row coordinate
    int col; // current column
    int number; // current user entry
    int tempNumber;
    
public:
    void insertBoard();
    void DisplayBox();
    int isValidEntry();
    int isBoardFull();
    int getBoxCoordinate(int row, int col);
    void SetBoxCoordinate(int row , int col, int Pinput);
    void DeleteBoxCoordinate(int row, int col);
    void setTempNumber(int);
    int getTempNumber();

    int getSize();
    int getRow();
    int getCol();
    int getNumber();
    void setNumber(int);
};
