#ifndef MINESWEEPERBOARD_MSTEXTCONTROLLER_H
#define MINESWEEPERBOARD_MSTEXTCONTROLLER_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MinesweeperBoard;
class MSBoardTextView;


class MSTextController
        {
    MinesweeperBoard &plansza;
    MSBoardTextView &widok;
public:

    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
    void play();



};


#endif //MINESWEEPERBOARD_MSTEXTCONTROLLER_H
