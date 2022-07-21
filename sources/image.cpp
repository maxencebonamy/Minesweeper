#include "image.h"


Image::Image(const std::string& name) {
    _texture.loadFromFile("dependencies/assets/" +  name + ".png");
    _sprite = sf::Sprite(_texture);
}

sf::Sprite& Image::getSprite() { return _sprite; }

void Image::setSprite(const std::string& name) {
    _texture.loadFromFile("dependencies/assets/" +  name + ".png");
    _sprite = sf::Sprite(_texture);
}


