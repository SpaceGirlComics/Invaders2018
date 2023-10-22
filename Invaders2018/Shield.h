#ifndef SHIELD_H
#define SHEILD_H

#include "Character.h"

class Shield : public Character
{
	public:
		Shield();

		virtual int initialize();
		virtual int update(int delta);
		
		~Shield();
	protected:
};



#endif
