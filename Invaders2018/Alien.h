#ifndef ALIEN_H
#define ALIEN_H
#include <stdlib.h>
#include <time.h>
#include "Character.h"

class Alien : public Character
{
	public:
		Alien();

		virtual int initialize();
		virtual int update(int delta);
		int setPaletteColor(int _i);

		~Alien();
	protected:
		//static const char* IMAGE;
		int* moves;
		int move;
		int direction;
};

#endif

