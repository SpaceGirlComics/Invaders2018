#ifndef BULLET_H
#define BULLET_H

#include "Character.h"

class Bullet : public Character
{
	public:
		Bullet();

		virtual int initialize();
		virtual int update(int _delta);

		~Bullet();
	protected:
		
};



#endif
