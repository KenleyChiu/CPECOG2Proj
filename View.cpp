#include "View.h"
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include "CImg.h"
#include "Ball.h"

#define WIDTH	1280
#define HEIGHT	720
#define COUNT   8

uint32_t  View::bg_arr[];
uint32_t  View::frame[];
uint32_t  View::sprite_mem[];
uint32_t*  View::sprite_mem_tracker;
const size_t View::sprite_mem_size;


View::View(uint8_t* bg_mem)
{
	bgbuffer = bg_arr;
	framebuffer = frame;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			uint8_t r = bg_mem[WIDTH * y + x];
			uint8_t g = bg_mem[WIDTH * y + x + WIDTH * HEIGHT];
			uint8_t b = bg_mem[WIDTH * y + x + 2 * WIDTH * HEIGHT];


			bgbuffer[WIDTH * (y)+(x)] = (r << 16) + (g << 8) + b;
			framebuffer[WIDTH * (y)+(x)] = bgbuffer[WIDTH * (y)+(x)];
		}
	}
	sprite_mem_tracker = sprite_mem;
}


uint32_t* View::getFrameBuffer()
{
	return framebuffer;
}

uint32_t* View::loadSprite(uint8_t* sprite_data, int width, int height)
{
	uint32_t* sprite_tracker = sprite_mem_tracker;

	for (int x = 0; x != width; x++)
	{
		for (int y = 0; y != height; y++)
		{
			uint32_t r = sprite_data[width * y + x];
			uint32_t g = sprite_data[width * y + x + width * height];
			uint32_t b = sprite_data[width * y + x + 2 * width * height];
			uint32_t pixels = (r << 16) + (g << 8) + b;
			sprite_tracker[width* (y)+(x)] = pixels;
		}
	}
	sprite_mem_tracker += (width * height);
	return sprite_tracker;
}

void View::displaySprite(uint32_t* sprite, int width, int height, int current_x, int current_y)
{
	for (int y = 0; y != height; y++)
	{
		for (int x = 0; x != width; x++)
		{
			if (sprite[width * y + x] != 0)
				framebuffer[WIDTH * (current_y + y) + (current_x + x)] = sprite[width * y + x];
		}
	}
}



void View::moveBall(Ball* ball)
{
	for (int x = 0; x != ball->getWidth(); x++)
	{
		for (int y = 0; y != ball->getHeight(); y++)
		{
			framebuffer[WIDTH * (ball->getY() + y) + (ball->getX() + x)] = bgbuffer[WIDTH * (ball->getY() + y) + (ball->getX() + x)];
		}
	}
	ball->changeXPos();

	ball->changeYPos();

	displaySprite(ball->getSpriteTracker(), ball->getWidth(), ball->getHeight(), ball->getX(), ball->getY());
}



