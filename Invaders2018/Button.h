#ifndef BUTTON_H
#define BUTTON_H

#include "Character.h"

class Button : public Character
{
	public:
		Button();

		virtual int initialize();
		virtual int update(int _delta);

		void onMouseMove(int _x, int _y);
		void onMBDown(int buttons);

		~Button();
	protected:

};


#endif