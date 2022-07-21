#include "cell.h"


Cell::Cell(const Vector2& position, sf::Sprite sprite) : _position(position), _sprite(sprite) {

}

State Cell::getState() const { return _state; }


Vector2 Cell::getPosition() const { return _position; }

void Cell::reveal() {
    if (_state == State::HIDDEN) _state = State::REVEALED;
}

void Cell::flag() {
    if (_state == State::HIDDEN) _state = State::FLAG;
    else if (_state == State::FLAG) _state = State::HIDDEN;
}


bool Cell::isMine() const { return _isMine; }

bool Cell::isFlag() const { return _state == State::FLAG; }

bool Cell::isRevealed() const { return _state == State::REVEALED; }

bool Cell::isHidden() const { return _state == State::HIDDEN; }


void Cell::display(sf::RenderWindow& window) {
    _sprite.setPosition((_position * CELL_SIZE).toSFML());
    window.draw(_sprite);
}


void Cell::setSprite(sf::Sprite sprite) {
    _sprite = sprite;
}
