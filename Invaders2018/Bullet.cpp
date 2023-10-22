#include "Bullet.h"

Bullet::Bullet()
{

}

int Bullet::initialize()
{
	frame = 0;
	minFrame = 0;
	maxFrame = 1;
	totalFrames = 2;
	fps = 21;

	width = 3;
	height = 10;
	x = 0;
	y = 0;
	scale = 1.0f;

	accel = 2;
	deccl = 1;

	char* buffer = "111111111111223323442242040005111111111111323422452242040500";

	pallet[0] = 0x00000000;
	pallet[1] = 0x00FFFFFF;
	pallet[2] = 0x00FFDDDD;
	pallet[3] = 0x00FF5555;
	pallet[4] = 0x00DD2222;
	pallet[5] = 0x00550000;

	if (totalFrames > 0)
	{
		img = new int**[totalFrames];
		for (int z = 0; z < totalFrames; z++)
		{
			img[z] = new int*[height];
			for (int y = 0; y < height; y++)
			{
				img[z][y] = new int[width];
				for (int x = 0; x < width; x++)
				{
					img[z][y][x] = pallet[buffer[x + y*width + z*height*width] - 48];
				}
			}
		}
	}
	hp = 1;
	state = 0x00000001;
	return(1);
}

int Bullet::update(int _delta)
{
	lifeTime += _delta;
	y -= _delta*1.25f;
	if (lifeTime > 1000)
	{
		frame++;
		if (frame > maxFrame)
		{
			frame = minFrame;
		}
	}
	if (y < 200)
	{
		return(1);
	}
	return(0);
}

Bullet::~Bullet()
{
}
