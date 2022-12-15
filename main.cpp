#include <iostream>
#include <ctime>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include "Myszka.h"

using namespace std;

void intro()
{
    cout<<"Jan Hordyński 36\n";
}
/*
int main() {
    srand(time(nullptr));
    intro();

    MinesweeperBoard plansza ={4 , 5, HARD};
    plansza.debug_display();
    cout<<"Wysokosc: "<< plansza.getBoardHeight()<<endl;
    cout<<"Szerokosc: "<< plansza.getBoardWidth()<<endl;
    plansza.revealField(2,2);
    cout<<"Miny dookola: " << plansza.countMines(0,0)<<endl;
    cout<<plansza.getFieldInfo(1,1)<<endl;
    plansza.debug_display();
    //UWWAGA!! wpisuje numer kolumny liczonej od 0!!

    return 0;
}
*/

/*
int main()
{
    srand(time(nullptr));
    MinesweeperBoard board (6, 7, GameMode::HARD);
    MSBoardTextView view (board);
    view.display();
    board.revealField(0,5);
    view.display();
}//Tylko wyśitle nie z get field info
*/


//int main()
//{
//    srand(time(nullptr));
//    MinesweeperBoard board (2, 5, GameMode::HARD);
//    MSBoardTextView view ( board );
//    MSTextController ctrl(board, view);
//    ctrl.play();
//}


int main()
{
    srand(time(nullptr));
    sf::RenderWindow window(sf::VideoMode(900, 802), "MinesweeperBoard");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(4, 7, EASY);

 //   board.toggleFlag(10,10);
    board.revealField(2,2);
//    board.revealField(30,30);
//    board.revealField(22,22);
//    board.revealField(31,31);

    MSBoardTextView widok ( board );
    MSTextController ctrl(board, widok);
    MSSFMLView view (board);
    Myszka ruch (board, view);

board.debug_display();
board.displej();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        switch (event.type)
        {
            case  sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                switch(event.key.code)
                {
                    case sf::Mouse::Left:
                        ruch.click(event, window);
                        break;

                    case sf::Mouse::Right:
                        ruch.click(event, window);
                        break;
                }
        }
        window.clear();
        view.draw(window);
        window.display();
    }
    return 0;
}

