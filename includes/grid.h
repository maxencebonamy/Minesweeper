#ifndef MINESWEEPER_GRID_H
#define MINESWEEPER_GRID_H

#include "config.h"
#include "cell.h"
#include "image.h"

class Grid {

public:
    Grid();

    void display(sf::RenderWindow& window);

    void updateEvents(const sf::Mouse& mouse, sf::RenderWindow& window);

private:
    Cell& _getCellFocused(const sf::Mouse& mouse, const sf::RenderWindow& window);
    int _getNeighborMines(const Vector2& position);
    bool _isInBounds(const Vector2& position);

    void _revealCell(const Vector2& position);

    const Vector2& _size { GRID_SIZE };
    std::vector<std::vector<Cell>> _cells;

    Image IMAGE_DEFAULT { "default" };
    Image IMAGE_FLAG { "flag" };
    Image IMAGE_MINE { "mine" };
    Image IMAGE_ZERO { "0" };

    std::array<Image, 9> IMAGE_NUMBERS;
    bool _hasDefeated { false };

};

#endif
