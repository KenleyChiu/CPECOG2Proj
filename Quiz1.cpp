#include <stdio.h>
#include <stdlib.h>

#include "CImg.h"
#include "MiniFB.h"
#include <iostream>
#include "View.h"
#include "Ball.h"
#include "Block.h"

#define WIDTH  1280
#define HEIGHT 720
#define COUNT 8
using namespace cimg_library;
int main()
{
	//initialize Background Image
	CImg<unsigned char> bg("assets/background.bmp");
	uint8_t* bg_mem = bg.data();
	// Instantiate View Object
	View *graphics = new View(bg_mem);

	//Initialize Ball Image
	CImg<unsigned char> ball_sprite("assets/alongus.bmp");
	uint8_t* ball_data = ball_sprite.data();
	// Load ball to sprite memory
	uint32_t* ball_pointer = graphics->loadSprite(ball_data, ball_sprite.width(), ball_sprite.height());
	//Instantiate Ball Object
	Ball *ball = new Ball(ball_pointer, ball_sprite.width(), ball_sprite.height(), 20, 40, 5, 5	);
	//Display Ball to framebuffer
	graphics->displaySprite(ball->getSpriteTracker(), ball->getWidth(), ball->getHeight(), ball->getX(), ball->getY());

	//Set blocks info
	char file[4][100] = { "assets/block_stop.bmp", "assets/block_fast.bmp","assets/block_slow.bmp","assets/block_neutral.bmp" };
	int block_info[COUNT][3] = { {1060,300,0},{100,250,1},{800,200,1},{500,350,2},{1100,550,2},{850,600,3},{400,150,3},{200,500,3} };
	float factor[4] = {0,2,0.5,1};
	Block *block_arr[COUNT];

	
	for (int i = 0; i < COUNT; i++)
	{
		//initialize Block Image
		CImg<unsigned char> block_sprite(file[block_info[i][2]]);
		uint8_t* block_data = block_sprite.data();
		// Load block to sprite memory
		uint32_t* block_pointer = graphics->loadSprite(block_data, block_sprite.width(), block_sprite.height()); 
		//Instantiate Block Object
		block_arr[i] = new Block(block_pointer, block_sprite.width(), block_sprite.height(), block_info[i][0], block_info[i][1], factor[block_info[i][2]], block_info[i][2]);
		//Display Ball to framebuffer
		graphics->displaySprite(block_arr[i]->getSpriteTracker(), block_arr[i]->getWidth(), block_arr[i]->getHeight(), block_arr[i]->getX(), block_arr[i]->getY());
	}


	struct mfb_window* window;
	window = mfb_open("Quiz 1", WIDTH, HEIGHT);
	if (!window)
		return -1;
	while(1)
	{
		//Get the other sides of the ball
		int ball_bottom = ball->getY() + ball->getHeight();
		int ball_right = ball->getX() + ball->getWidth();
		for (int i = 0; i < COUNT; i++)
		{
			ball->checkBlockCollision(block_arr[i]);
		}
		if (ball_right >= WIDTH || ball->getX() <= 0) ball->changeXDirection();
		else if (ball_bottom >= HEIGHT || ball->getY() <= 0) ball->changeYDirection();
		// New Ball Position
		graphics->moveBall(ball);

		mfb_update(window, graphics->getFrameBuffer());
		mfb_wait_sync(window);
	} 
}