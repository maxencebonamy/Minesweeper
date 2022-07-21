#include "grid.h"


Grid::Grid() {
    for (int i { 0 }; i < _size.getX(); ++i) {
        _cells.push_back({});
        for (int j { 0 }; j < _size.getY(); ++j) {
            _cells[i].push_back(Cell(Vector2(i, j), IMAGE_DEFAULT.getSprite()));
        }
    }

    for (int i { 0 }; i <= 8; ++i) {
        IMAGE_NUMBERS[i].setSprite(std::to_string(i));
    }
}

void Grid::display(sf::RenderWindow& window) {
    for (auto& line : _cells) {
        for (auto& cell : line) {
            cell.display(window);
        }
    }
}

void Grid::updateEvents(const sf::Mouse& mouse, sf::RenderWindow& window) {
    if (!_hasDefeated) {
        if (mouse.isButtonPressed(sf::Mouse::Left)) {
            Cell& cell { _getCellFocused(mouse, window) };
            if (cell.isHidden()) {
                if (cell.isMine()) {
                    _hasDefeated = true;
                    for (auto& line : _cells) {
                        for (auto& element : line) {
                            if (element.isMine()) element.setSprite(IMAGE_MINE.getSprite());
                        }
                    }
                }
                else _revealCell(cell.getPosition());
            }
        }
        else if (mouse.isButtonPressed(sf::Mouse::Right)) {
            Cell& cell { _getCellFocused(mouse, window) };
            cell.flag();
            if (cell.isFlag()) cell.setSprite(IMAGE_FLAG.getSprite());
            else cell.setSprite(IMAGE_DEFAULT.getSprite());
        }
    }
}

Cell& Grid::_getCellFocused(const sf::Mouse& mouse, const sf::RenderWindow& window) {
    Vector2 mousePosition { (float)mouse.getPosition(window).x, (float)mouse.getPosition(window).y };
    Vector2 cellPosition { mousePosition / CELL_SIZE };
    int x { (int)cellPosition.getX() }, y { (int)cellPosition.getY() };
    return _cells[x][y];
}

int Grid::_getNeighborMines(const Vector2& position) {
    int result { 0 };
    int x { (int)position.getX() }, y { (int)position.getY() };

    for (int i { -1 }; i <= 1; ++i) {
        for (int j { -1 }; j <= 1; ++j) {
            if (_isInBounds(position + Vector2(i, j)) && _cells[x+i][y+j].isMine()) ++result;
        }
    }

    return result;
}

bool Grid::_isInBounds(const Vector2& position) {
    return position.getX() >= 0 && position.getX() < _size.getX() && position.getY() >= 0 && position.getY() < _size.getY();
}

void Grid::_revealCell(const Vector2& position) {
    int x { (int)position.getX() }, y { (int)position.getY() };

    Cell& cell { _cells[x][y] };
    if (cell.isHidden()) {
        int neighbors { _getNeighborMines(cell.getPosition()) };

        cell.reveal();
        cell.setSprite(IMAGE_NUMBERS[neighbors].getSprite());

        if (neighbors == 0) {
            for (int i { -1 }; i <= 1; ++i) {
                for (int j { -1 }; j <= 1; ++j) {
                    if ((i != 0 || j != 0) && _isInBounds(position + Vector2(i, j))) {
                        _revealCell(position + Vector2(i, j));
                    }
                }
            }
        }
    }
}
