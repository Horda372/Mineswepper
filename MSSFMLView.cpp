#include <iostream>
#include "MinesweeperBoard.h"

#include <SFML/Graphics.hpp>

#include "MSSFMLView.h"

using namespace std;

MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b)
{

}

void MSSFMLView::draw (sf::RenderWindow & win ) const
{
    sf::Font font;
   font.loadFromFile(R"(C:\Windows\Fonts\arialbd.ttf)");
    sf::Text Text;
Text.setFont(font);

int Size;

if(board.getBoardWidth()<=10 or board.getBoardHeight()<=10)
{
        Size =80;
}
if((board.getBoardWidth()>10 and board.getBoardWidth()<=40) or (board.getBoardWidth()>10 and board.getBoardHeight()<=40))
{
    Size =20;
}
if(board.getBoardWidth()>40 or board.getBoardHeight()>40)
{
    Size =8;
}



    sf::RectangleShape plansza(sf::Vector2f(Size, Size));
    plansza.setOutlineColor(sf::Color::Black);
    plansza.setOutlineThickness(1);


    for (int row = 0; row < board.getBoardHeight() ; row ++)
    {
        for (int col = 0; col < board.getBoardWidth(); col ++)
        {

            plansza.setPosition(float(col) * Size, float(row) * Size);
            Text.setPosition(float(col) * Size, float(row) * Size);
            Text.setCharacterSize(Size-1);

            if (board.getFieldInfo(row, col) == '_') {
                plansza.setFillColor(sf::Color::White);
                win.draw( plansza);
            }
            else if (board.getFieldInfo(row, col) == ' ') {
                plansza.setFillColor(sf::Color::Black);
                win.draw( plansza);
            }
            else if (board.getFieldInfo(row, col) == 'F') {
                plansza.setFillColor(sf::Color::Red);
                win.draw( plansza);
            }
            else if (board.getFieldInfo(row, col) == 'X')
            {
                plansza.setFillColor(sf::Color::Magenta);
                win.draw( plansza);
            }
            if (board.getFieldInfo(row, col) == '1') {
            Text.setString("1");
            Text.setFillColor(sf::Color::Red);
            win.draw(Text);
        }
            if (board.getFieldInfo(row, col) == '2') {
            Text.setString("2");
            Text.setFillColor(sf::Color::Red);
            win.draw(Text);
        }
            if (board.getFieldInfo(row, col) == '3') {
                Text.setString("3");
                Text.setFillColor(sf::Color::Red);
                win.draw(Text);
            }
            if (board.getFieldInfo(row, col) == '4') {
                Text.setString("4");
                Text.setFillColor(sf::Color::Red);
                win.draw(Text);
            }
            if (board.getFieldInfo(row, col) == '5') {
                Text.setString("5");
                Text.setFillColor(sf::Color::Red);
                win.draw(Text);
            }
            if (board.getFieldInfo(row, col) == '6') {
                Text.setString("6");
                Text.setFillColor(sf::Color::Red);
                win.draw(Text);
            }
            if (board.getFieldInfo(row, col) == '7') {
                Text.setString("7");
                Text.setFillColor(sf::Color::Red);
                win.draw(Text);
            }
            if (board.getFieldInfo(row, col) == '8') {
                Text.setString("8");
                Text.setFillColor(sf::Color::Red);
                win.draw(Text);
            }
        }
    }
//    if(board.getGameState()==FINISHED_WIN or board.getGameState()==FINISHED_LOSS) {
//        cout<<"Koniec"<<endl;
//        Text.setString("Koniec");
//        Text.setFillColor(sf::Color::Red);
//        // Text.setPosition(float(col) * Size, float(row) * Size);
//        Text.setCharacterSize(200);
//        win.draw(Text);
//    }
}