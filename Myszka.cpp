#include <iostream>
#include <ctime>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include "Myszka.h"

using namespace std;

Myszka::Myszka (MinesweeperBoard & b, MSSFMLView & v) : board(b), view(v)
{

}


void Myszka::click(sf::Event& event, sf::RenderWindow &window)
{
    int Size;
    if(board.getBoardWidth()<=10 or board.getBoardHeight()<=10)
    {
        Size =80;
    }
    if(board.getBoardWidth()>10 and board.getBoardWidth()<=40 or board.getBoardWidth()>10 and board.getBoardHeight()<=40)
    {
        Size =20;
    }
    if(board.getBoardWidth()>40 or board.getBoardHeight()>40)
    {
        Size =8;
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        int col = ((event.mouseButton.x /(Size)));
        int row = ((event.mouseButton.y /(Size)));

        if(event.mouseButton.button == sf::Mouse::Left)
        {
            cout<<"Left"<<event.mouseButton.button<<endl;
            cout<<"X:"<<event.mouseButton.x<<endl;
            cout<<"Y:"<<event.mouseButton.y<<endl;
            board.revealField(row,col);
            return;
        }
        if(event.mouseButton.button == sf::Mouse::Right)
        {
            cout<<"Right"<<event.mouseButton.button<<endl;
            cout<<"X:"<<event.mouseButton.x<<endl;
            cout<<"Y:"<<event.mouseButton.y<<endl;
            board.toggleFlag(row, col);
            return;

        }
    }

}