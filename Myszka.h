#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>


#ifndef MINESWEEPERBOARD_MYSZKA_H
#define MINESWEEPERBOARD_MYSZKA_H


class Myszka {

    MinesweeperBoard & board;

public:
    void click(sf::Event& event, sf::RenderWindow &window) ;

    MSSFMLView &view;

    Myszka(MinesweeperBoard &b ,MSSFMLView & v);
};


#endif //MINESWEEPERBOARD_MYSZKA_H
