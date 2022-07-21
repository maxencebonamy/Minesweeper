#ifndef MINESWEEPER_IMAGE_H
#define MINESWEEPER_IMAGE_H

#include "config.h"

class Image {

public:
    Image() = default;
    Image(const std::string& name);

    sf::Sprite& getSprite();
    void setSprite(const std::string& name);

private:
    sf::Texture _texture;
    sf::Sprite _sprite;

};

#endif
