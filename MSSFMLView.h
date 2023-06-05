#ifndef MINESWEEPERBOARD_MSSFMLVIEW_H
#define MINESWEEPERBOARD_MSSFMLVIEW_H


#include "MSSFMLView.h"

#include "MinesweeperBoard.h"

#include "MSBoardTextView.h"

#include "MSTextController.h"

#include <SFML/Graphics.hpp>

class MSSFMLView
{

public:

    MSSFMLView(MinesweeperBoard &b);

    MinesweeperBoard & board;

    sf::RectangleShape pole();
    sf::RectangleShape pole_odkryte();
    sf::CircleShape mina();
    sf::RectangleShape flaga();
    void draw (sf::RenderWindow & win) const;


};

#endif //MINESWEEPERBOARD_MSSFMLVIEW_H