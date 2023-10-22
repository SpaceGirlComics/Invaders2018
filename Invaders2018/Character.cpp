#include "Character.h"

Character::Character()
{
	frame = 0;
	minFrame = 0;
	maxFrame = 0;
	totalFrames = 0;
	fps = 0;

	width = 0;
	height = 0;
	x = 0;
	y = 0;
	scale = 1.0f;

	img = (int***)0;
	
	hp = 1;
	state = 0x00000000;

	lifeTime = frameTime = 0;

	xspeed = accel = deccl = 0;
}

int Character::getX() {return(x);}
int Character::getY() {return(y); }
int Character::getWidth() { return(width); }
int Character::getHeight() {return(height);}

void Character::translate(int _x, int _y)
{
	x += _x;
	if (x < 0)
	{
		x = 0;
	}
	if (x > 700)
	{
		x = 700;
	}
	y += _y;
}

int** Character::getFrameData()
{
	return(img[frame]);
}

Character::~Character()
{
	if (totalFrames > 0)
	{
		for (int z = 0; z < totalFrames; z++)
		{
			for (int y = 0; y < height; y++)
			{
				delete(img[z][y]);
			}
			delete(img[z]);
		}
		delete(img);
	}
}