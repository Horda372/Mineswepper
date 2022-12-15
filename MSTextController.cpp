#include "MSTextController.h"
#include <iostream>
#include <ctime>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

using namespace std;


MSTextController::MSTextController (MinesweeperBoard &board , MSBoardTextView &view) : plansza (board),  widok(view)
{

}



void MSTextController::play() {
    plansza.debug_display();
    widok.display();
    while (plansza.getGameState() == RUNNING) {
        int row, col;
        cout << "Wybierz rzad pola" << endl;
        cin >> row;
        row-=1;
        cout << endl;

        cout << "Wybierz kolumne pola" << endl;
        cin >> col;
        col-=1;
        cout << endl;
        if (!plansza.MaSens(row, col)) {
            cout << "Poza plansza" << endl;
            cin.clear();
            cin.ignore();

        }
        cout << "Odkryj Pole = 1" << endl;
        cout << "Postaw Flage = 2" << endl;
        int a;
        cin >> a;
        switch (a) {
            case 1:
                plansza.revealField(row, col);

          break;
            case 2:
                plansza.toggleFlag(row,col);
                break;
        }

      //  plansza.debug_display();
        widok.display();
        if (plansza.getGameState() == FINISHED_WIN) { cout << "Wygrana" << endl; }
        if (plansza.getGameState() == FINISHED_LOSS) { cout << "Mina, sprobuj jeszcze raz" << endl; }

      //  cout << plansza.getMineCount(row,col, HARD) << endl;

    }
}