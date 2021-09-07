#include "Ball.h"
#include "Block.h"
#define WIDTH  1280
#define HEIGHT 720

Ball::Ball(uint32_t* sprite_tracker, int width, int height, int x, int y, float speed_x, float speed_y)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->sprite_tracker = sprite_tracker;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
}

int Ball::getWidth()
{
	return width;
}

int Ball::getHeight()
{
	return height;
}

int Ball::getX()
{
	return x;
}

int Ball::getY()
{
	return y;
}

float Ball::getSpeed_x()
{
	return speed_x;
}

float Ball::getSpeed_y()
{
	return speed_y;
}

uint32_t* Ball::getSpriteTracker()
{
	return sprite_tracker;
}

void Ball::setWidth(int width)
{
	this->width = width;
}

void Ball::setHeight(int height)
{
	this->height = height;
}

void Ball::setX(int x)
{
	this->x = x;
}

void Ball::setY(int y)
{
	this->y = y;
}

void Ball::setSpriteTracker(uint32_t* sprite_tracker)
{
	this->sprite_tracker = sprite_tracker;
}

void Ball::setSpeed_y(float speed_y)
{
	this->speed_y = speed_y;
}

void Ball::setSpeed_x(float speed_x)
{
	this->speed_x = speed_x;
}

void Ball::checkBlockCollision(Block* block)
{
	int ball_bottom = y + height;
	int ball_right = x + width;
	int block_bottom = block->getY() + block->getHeight();
	int block_right = block->getX() + block->getWidth();
	if (ball_right + speed_x > block->getX() &&     x + speed_x < block_right &&      ball_bottom > block->getY() &&     y < block_bottom)
	{
		speed_x = -speed_x * block->getFactor();
		speed_y = speed_y * block->getFactor();
	}
	else if (ball_bottom + speed_y > block->getY() &&      y + speed_y < block_bottom       && ball_right > block->getX()     && x < block_right)
	{
		speed_x = speed_x * block->getFactor();	
		speed_y = -speed_y * block->getFactor();
	}
}

void Ball::changeXPos()
{
	x = x + speed_x;
}

void Ball::changeYPos()
{
	y = y + speed_y;
}

void Ball::changeXDirection()
{
	speed_x = -speed_x;
}

void Ball::changeYDirection()
{
	speed_y = -speed_y;
}
