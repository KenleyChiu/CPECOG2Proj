#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
class Block
{
	public:
		Block(uint32_t* sprite_tracker, int width, int height, int x, int y, float factor, int type);
		int getWidth();
		int getHeight();
		int getX();
		int getY();
		float getFactor();
		int getType();
		uint32_t* getSpriteTracker();
		void setWidth(int width);
		void setHeight(int height);
		void setX(int x);
		void setY(int y);
		void setSpriteTracker(uint32_t* sprite_tracker);
		void setFactor(float factor);
		void setType(int type);
	private:
		int type;
		uint32_t* sprite_tracker;
		float factor;
		int x, y;
		int width, height;
};

