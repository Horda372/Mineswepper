#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef MINESWEEPERBOARD_MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
    Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field
    int width;                // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy
    GameState state;
    void clear_board();

public:
    MinesweeperBoard(int height, int wight, GameMode mode);
    void debug_display() const;
    bool hasMine(int row,int col) const;
    bool hasFlag (int row, int col) const;
    bool isRevealed(int row, int col) const;
    bool CzyWin();


    int getBoardWidth()const;
    int getBoardHeight()const;
    int getMineCount();
    int countMines(int row, int col) const;
    bool Firstmove();

    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    char getFieldInfo(int row, int col)const;
    GameState getGameState();
    void displej()const;
    bool MaSens(int row, int col)const ;

};

#endif //MINESWEEPERBOARD_MINESWEEPERBOARD_H