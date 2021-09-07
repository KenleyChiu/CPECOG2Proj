#include "Block.h"

Block::Block(uint32_t* sprite_tracker, int width, int height, int x, int y, float factor, int type)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->sprite_tracker = sprite_tracker;
    this->factor = factor;
    this->type = type;
}

int Block::getWidth()
{
    return width;
}

int Block::getHeight()
{
    return height;
}

int Block::getX()
{
    return x;
}

int Block::getY()
{
    return y;
}

float Block::getFactor()
{
    return factor;
}

int Block::getType()
{
    return type;
}

uint32_t* Block::getSpriteTracker()
{
    return sprite_tracker;
}

void Block::setWidth(int width)
{
    this->width = width;
}

void Block::setHeight(int height)
{
    this->height = height;
}

void Block::setX(int x)
{
    this->x = x;
}

void Block::setY(int y)
{
    this->y = y;
}

void Block::setSpriteTracker(uint32_t* sprite_tracker)
{
    this->sprite_tracker = sprite_tracker;
}

void Block::setFactor(float factor)
{
    this->factor = factor;
}

void Block::setType(int type)
{
    this->type = type;
}
