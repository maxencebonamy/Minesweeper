#ifndef MINESWEEPER_CELL_H
#define MINESWEEPER_CELL_H

#include "config.h"


enum class State {
    HIDDEN,
    REVEALED,
    FLAG
};


class Cell {

public:
    Cell(const Vector2& position, sf::Sprite sprite);

    State getState() const;
    Vector2 getPosition() const;
    void reveal();
    void flag();

    bool isMine() const;
    bool isFlag() const;
    bool isRevealed() const;
    bool isHidden() const;

    void display(sf::RenderWindow& window);

    void setSprite(sf::Sprite sprite);

private:
    const float _size { CELL_SIZE };
    Vector2 _position;
    State _state { State::HIDDEN };
    bool _isMine { rand() % 10 == 0 };

    sf::Sprite _sprite;

};

#endif
