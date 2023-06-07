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
    cout<<"Jan Hordyński\n";
}

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

    MinesweeperBoard board(10, 10, EASY);

  //  board.revealField(2,2);

    MSBoardTextView widok ( board );
    MSTextController ctrl(board, widok);
    MSSFMLView view (board);
    Myszka ruch (board, view);

board.debug_display();
//board.displej();

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

