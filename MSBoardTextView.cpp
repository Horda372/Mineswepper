#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>
using namespace std;

MSBoardTextView::MSBoardTextView (MinesweeperBoard & board) : plansza (board)
{

}

void MSBoardTextView::display() const {



        for(int row = 0;row < plansza.getBoardHeight();row++)
        {
            for(int col = 0;col < plansza.getBoardWidth(); col++)
            {
                cout << "[" << plansza.getFieldInfo(row, col) << "]";
            }
                cout << endl;
            } cout <<endl;
}


