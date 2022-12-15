#ifndef MINESWEEPERBOARD_MSBOARDTEXTVIEW_H
#define MINESWEEPERBOARD_MSBOARDTEXTVIEW_H


#include "MinesweeperBoard.h"

class MSBoardTextView
{
public:
    MSBoardTextView(MinesweeperBoard &board);
    MinesweeperBoard &plansza;

    void display() const;
    void revealField(int row, int col);
};


#endif //MINESWEEPERBOARD_MSBOARDTEXTVIEW_H
