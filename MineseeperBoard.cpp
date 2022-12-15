#include "MinesweeperBoard.h"
#include <iostream>
#include <cstdlib>


#include "MinesweeperBoard.h"
#include "Myszka.h"
using namespace std;


MinesweeperBoard::MinesweeperBoard(int height, int width, GameMode mode) {
    this -> width =width;
    this ->  height =height;
    clear_board();
    int Liczba_min=0;
//    cout << "Wybierz tryb gry:" <<endl;
//    cout <<     "1=EASY" <<endl;
//    cout <<  "2=NORMAL" << endl;
//    cout <<    "3=HARD" << endl;
//    cin >> WyborGry;
    clear_board();
    if(mode == DEBUG) {
        board[0][0].hasMine = true;
        board[1][1].isRevealed = true;
        board[0][2] = {true, true, false};
        //      cout <<"Liczba min: " <<Liczba_min << endl;
    }
    if(mode == EASY)
    {
        Liczba_min = (height*width) * 10/100;
        if (Liczba_min<=0)
        Liczba_min++;
    }
    if(mode == NORMAL)
    {
        Liczba_min = (height*width) * 20/100;

        if (Liczba_min<=0)
            Liczba_min++;
    }
    if(mode == HARD)
    {
        Liczba_min = (height*width) * 30/100;

        if (Liczba_min<=0)
            Liczba_min++;
    }
    for (int IloscBomb = 0; IloscBomb <= Liczba_min-1; IloscBomb++) {
        int RandomHeight = rand() % height;
        int RandomWidth = rand() % width;
        if(board[RandomHeight][RandomWidth].hasMine)
        {
            IloscBomb -= 1;
        }
        board[RandomHeight][RandomWidth].hasMine = true;
    }

}
int MinesweeperBoard::getMineCount ()
{


        int Miny = 0;
        for (int  row= 0;  row<height;  row++)
        {
            for (int col = 0; col<width; col ++)
            {
                if(board[row][col].hasMine==true)
                    Miny++;
            }
        }
    return Miny;
}


void MinesweeperBoard::clear_board(){
    for(int row=0;row<width;row++){
        for(int col=0;col<height;col++){
            board[row][col].hasMine = false;
            board[row][col].hasFlag = false;
            board[row][col].isRevealed = false;
        }
    }
}

void MinesweeperBoard::debug_display() const
{

    for(int row=0;row<height;row++) {
        for (int col = 0; col < width; col++) {
            cout << "[";
            if (board[row][col].hasMine)
                cout << "M";
            else
                cout << ".";
            if (board[row][col].isRevealed)
                cout << "o";
            else
                cout << ".";
            if (board[row][col].hasFlag)
                cout << "f";
            else
                cout << ".";
            cout << "]";
        }
        cout << endl;
    }
}

bool MinesweeperBoard::hasMine(int row, int col) const
{
    if (board[row][col].hasMine == true)
    {
        return true;
    }
    else return false;
}


bool MinesweeperBoard::isRevealed(int row, int col) const{
    if (board[row][col].isRevealed)
        return true;
    return false;
}

int MinesweeperBoard::getBoardHeight() const {
    return height;
}
int MinesweeperBoard::getBoardWidth() const {
    return width;
}

bool MinesweeperBoard::MaSens(int row, int col) const{
    if(col >width or row>height or row <0 or col <0)
        return false;
    return true;
}

int MinesweeperBoard::countMines(int row, int col)  const
{
    int licznik_min=0;
    if(!MaSens(row,col))
        return -1;
    if(MaSens(row+1,col+1) && board[row+1][col+1].hasMine)
        licznik_min++;
    if(MaSens(row+1,col)&& board[row+1][col].hasMine )
        licznik_min++;
    if(MaSens(row+1,col-1)&& board[row+1][col-1].hasMine )
        licznik_min++;
    if(MaSens(row,col+1)&& board[row][col+1].hasMine )
        licznik_min++;
    if(MaSens(row,col-1)&& board[row][col-1].hasMine )
        licznik_min++;
    if(MaSens(row-1,col+1)&& board[row-1][col+1].hasMine )
        licznik_min++;
    if(MaSens(row-1,col)&& board[row-1][col].hasMine )
        licznik_min++;
    if(MaSens(row-1,col-1)&& board[row-1][col-1].hasMine )
        licznik_min++;
    return licznik_min;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(board[row][col].isRevealed)
        return false;
    if(!board[row][col].hasFlag)
        return false;
    if(board[row][col].hasFlag)
        return true;
    if(!MaSens(row,col))
        return false;
    return false;
}
void MinesweeperBoard :: toggleFlag (int row, int col)
{
    if (!MaSens(row,col))
    {
        return;
    }
    if (board[row][col].isRevealed == true){
        return;
    }
    if (getGameState() == FINISHED_WIN or getGameState() ==FINISHED_LOSS){
        return;
    }
    if(board[row][col].hasFlag == true)
    {
        board[row][col].hasFlag = false;
        return;
    }
    if(board[row][col].isRevealed == false)
    {
        board[row][col].hasFlag = true;
    }

};
void MinesweeperBoard::revealField(int row, int col) {
    if (MaSens(row, col)) {
        if (isRevealed(row, col) or !MaSens(row, col) or !getGameState() == 0 or hasFlag(row, col)) {
            return;
        }

        if (!isRevealed(row, col) and board[row][col].hasMine)
        {
                    board[row][col].isRevealed = true;
            if (Firstmove()==true)
            {

                if (board[row][col].hasMine == true)
                {
                    board[row][col].hasMine = false;
                    if(MaSens(row,col-1) and board[row][col].hasMine == false)
                    board[row][col-1].hasMine = true;

                    else if(MaSens(row,col+1) and board[row][col].hasMine == false)
                        board[row][col+1].hasMine = true;

                    else if(MaSens(row+1,col) and board[row][col].hasMine == false)
                        board[row+1][col].hasMine = true;

                    else if(MaSens(row-1,col) and board[row][col].hasMine == false)
                        board[row-1][col].hasMine = true;
                }
            }
            if(Firstmove()==false)
            {
                debug_display();
                cout << "Porazka" << endl;
                cout << "Trafiles na mine! Koniec gry." << endl;
                
                state=FINISHED_LOSS;
                exit(1);
                system("Pause");

            }
        }
        if (!isRevealed(row, col) and !board[row][col].hasMine)
        {
            board[row][col].isRevealed = true;
        }
        if (CzyWin() == true)
        {
            state=FINISHED_WIN;
            debug_display();
            cout << "Gra zakonczona. Wygrales! :)" << endl;
            
            exit(1);
            system("Pause");
        }
        if (countMines(row, col) != 0) return;

        revealField(row + 1, col + 1);
        revealField(row + 1, col);
        revealField(row + 1, col - 1);
        revealField(row, col + 1);
        revealField(row, col - 1);
        revealField(row - 1, col + 1);
        revealField(row - 1, col);
        revealField(row - 1, col - 1);

        if (CzyWin() == true)
        {
            state=FINISHED_WIN;
            debug_display();
            cout << "Gra zakonczona. Wygrales! :)" << endl;
            
            exit(1);
            system("Pause");
        }
}
}

bool MinesweeperBoard::Firstmove()

{
    int wszystko = 0;
    for (int  row= 0;  row<height;  row++)
    {
        for (int col = 0; col<width; col ++)
        {
            if(board[row][col].isRevealed==true)
                wszystko++;
        }
    }
    if (  wszystko==1)
    {

        return true;
    }
    return false;
}

bool MinesweeperBoard::CzyWin()

{
    int wszystko = 0;
    for (int  row= 0;  row<height;  row++)
    {
        for (int col = 0; col<width; col ++)
        {
            if(board[row][col].isRevealed==false)
                wszystko++;
        }
    }
 if (  wszystko== getMineCount())
 {
     state=FINISHED_WIN;
     return true;
 }
 return false;
}

char MinesweeperBoard::getFieldInfo(int row, int col)const
{
    if (!MaSens(row,col))
        return '#';
  else  if  (!isRevealed(row,col) and hasFlag(row,col))
        return 'F';
   else if (isRevealed(row,col) and board[row][col].hasMine)
        return 'x';
   else if (!isRevealed(row, col) and !hasFlag(row,col))
        return '_';
   else if (isRevealed(row,col) and countMines(row,col) !=0)
        return char(countMines(row,col)+48);
    else (isRevealed(row,col) and countMines(row,col));
        return ' ';


};
GameState MinesweeperBoard::getGameState()
{
    int Flag_counter=0;
    int Free_field_counter=0;
    for(int row=0; row>getBoardHeight(); row++)
    {
        for(int col = 0; col>getBoardWidth(); col++)
        {
            if(isRevealed(row,col) and board[row][col].hasMine)
                return FINISHED_LOSS;
            if(isRevealed(row,col) and !board[row][col].hasMine)
                Free_field_counter++;
            if(hasFlag(row,col) and !board[row][col].hasMine)
                Flag_counter++;

            if( board[row][col].hasFlag && board[row][col].isRevealed)
                return FINISHED_WIN;
        }
    }
    return RUNNING;

}
void MinesweeperBoard::displej() const {



    for(int row = 0;row < getBoardHeight();row++)
    {
        for(int col = 0;col < getBoardWidth(); col++)
        {
            cout << "[" << getFieldInfo(row, col) << "]";
        }
        cout << endl;
    } cout <<endl;
}
