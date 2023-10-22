#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
	public:
		Player();

		virtual int initialize();
		virtual int update(int delta);

		~Player();
	protected:
		//static const char* IMAGE;
};


#endif