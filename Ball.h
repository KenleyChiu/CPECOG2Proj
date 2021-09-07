#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include"Block.h"
class Ball
{
public:
	Ball(uint32_t* sprite_tracker, int width, int height, int x, int y, float speed_x, float speed_y);
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	float getSpeed_x();
	float getSpeed_y();
	uint32_t* getSpriteTracker();
	void setWidth(int width);
	void setHeight(int height);
	void setX(int x);
	void setY(int y);
	void setSpriteTracker(uint32_t* sprite_tracker);
	void setSpeed_y( float speed_y);
	void setSpeed_x(float speed_x);
	void checkBlockCollision(Block* block);
	void changeXPos();
	void changeYPos();
	void changeXDirection();
	void changeYDirection();

private:
	float speed_x;
	float speed_y;
	int x, y;
	int width, height;
	uint32_t* sprite_tracker;
};

