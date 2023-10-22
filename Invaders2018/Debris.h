#ifndef DEBRIS_H
#define DEBRIS_H
#include <stdlib.h>

class Debris
{
	public:
		Debris()
		{
			for (int x = 0; x < 3; x++)
			{
				color[x][0] = 0xff;
				color[x][1] = 0x00;
				color[x][2] = 5;
			}
			position[0][0] = 200.0f;
			position[1][0] = 200.0f;
			position[0][1] = -0.5f + (rand()%10)*0.1f;
			position[1][1] = -0.5f + (rand() %10)*0.1f;
			position[0][2] = 0.0075f;
			position[1][2] = 0.0075f;
		}

		int update(int _delta)
		{
			//if (_delta < 1) { _delta = 1; }
			position[0][0] += position[0][1] * _delta;
			position[1][0] += position[1][1] * _delta;
			position[0][1] += (0 - position[0][1]) * position[0][2] * _delta;
			position[1][1] += (0 - position[1][1]) * position[0][2] * _delta;
			return (1);
		}

		int getColor()
		{
			int c = 0x00000000;
			for (int x = 0; x < 3; x++)
			{
				c |= color[x][0];
				if (x < 2)
				{
					c = c << 8;
				}
			}
			return(c);
		}

		int getx() { return((int)position[0][0]); }
		int gety() { return((int)position[1][0]); }

		~Debris()
		{

		}
	protected:
		unsigned char color[3][3];
			/*
				red
					current
					final
					rate
				green
					current
					final
					rate
				blue
					current
					final
					rate
			*/
		int colorDelay;
		float position[2][3];
			/*
				x
					current
					direction
					deccel
				y
					current
					direction
					deccel
			*/
};

#endif