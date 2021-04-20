#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Board
{
    friend class Sudoku;
protected:
    vector<vector<int>> BoxCoordinate;
    vector<vector<int>> copyBox;
    int size; // size x size board
    int row; // currenty row coordinate
    int col; // current column
    int number; // current user entry
    int tempNumber;
    
public:
    void insertBoard();
    void DisplayBox();
    int isBoardFull();
    int getBoxCoordinate(int row, int col);
    void SetBoxCoordinate(int row , int col, int Pinput);
    void DeleteBoxCoordinate(int row, int col);
    void setTempNumber(int);
    int getTempNumber();
};
