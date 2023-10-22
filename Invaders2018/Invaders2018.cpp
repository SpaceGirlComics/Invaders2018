#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windowsx.h>
#include <stdio.h>
#include <stdlib.h>


#include "FrameWindow.h"
#include "Player.h"
#include "Alien.h"
#include "Shield.h"
#include "Bullet.h"
#include "List.h"
#include "Button.h"
#include "Debris.h"

BOOL done;
bool keys[256];

FrameWindow x;
Player ship;
List alienList;
List bulletList;
List shieldList;
Button e;
//Alien badGuy;

int lifeTime;
int prevtime;
int delta;
Debris* debris[100];

LRESULT CALLBACK frameWndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)
{
	switch (_msg)
	{
		case WM_PAINT:
		{
			x.beginPaint();
			x.DrawSprite(ship.getFrameData(), ship.getX(), ship.getY(), ship.getWidth(), ship.getHeight());
			x.DrawSprite(e.getFrameData(), e.getX(), e.getY(), e.getWidth(), e.getHeight());
			
			for (int y = 0; y < alienList.getLength(); y++)
			{
				for (int a = 0; a < ((List*)alienList.get())->getLength(); a++)
				{
					Alien* temp = ((Alien*)((List*)alienList.get())->get());
					
					x.DrawSprite(temp->getFrameData(), temp->getX(), temp->getY(), temp->getWidth(), temp->getHeight());
					((List*)alienList.get())->next();
				}
				((List*)alienList.get())->reset();
				alienList.next();
			}
			alienList.reset();
			
			for (int y = 0; y < bulletList.getLength(); y++)
			{
				x.DrawSprite(((Bullet*)bulletList.get())->getFrameData(), ((Bullet*)bulletList.get())->getX(), ((Bullet*)bulletList.get())->getY(), ((Bullet*)bulletList.get())->getWidth(), ((Bullet*)bulletList.get())->getHeight());
				bulletList.next();
			}
			bulletList.reset();

			for (int y = 0; y < shieldList.getLength(); y++)
			{
				x.DrawSprite(((Bullet*)shieldList.get())->getFrameData(), ((Bullet*)shieldList.get())->getX(), ((Bullet*)shieldList.get())->getY(), ((Bullet*)shieldList.get())->getWidth(), ((Bullet*)shieldList.get())->getHeight());
				shieldList.next();
			}
			shieldList.reset();
			for (int y = 0; y < 5; y++)
			{
				x.drawDot(debris[y]->getx(), debris[y]->gety(), debris[y]->getColor());
			}
			x.stopPaint();
			return(0);
			break;
		}
		case WM_KEYDOWN:
		{
			if (_wParam == VK_SPACE && _lParam & 0x40000000)
			{
				return(0);
			}

			keys[_wParam] = true;
			return(0);
			break;
		}

		case WM_KEYUP:
		{
			keys[_wParam] = false;
			return(0);
			break;
		}

		case WM_MOUSEMOVE:
		{
			e.onMouseMove(GET_X_LPARAM(_lParam), GET_Y_LPARAM(_lParam));
			return(0);
			break;
		}

		case WM_LBUTTONDOWN:
		{	
			e.onMBDown(0x00000001);
			//return(0);
			break;
		}

		case WM_LBUTTONUP:
		{
			break;
		}

		case WM_CLOSE:
		case WM_QUIT:
		{
			done = TRUE;
			break;
		}
	}

	return(DefWindowProc(_hWnd, _msg, _wParam, _lParam));
}

bool collisionFirstPast(Alien* al, Bullet* bu)
{
	int side = 0;
	if (al->getX() - bu->getWidth() +1 < bu->getX() + bu->getWidth())
	{
		side++;
	}
	if (bu->getX() < al->getX() + al->getWidth() - 1)
	{
		side++;
	}
	if (al->getY() - bu->getWidth() + 1 < bu->getY() + bu->getHeight())
	{
		side++;
	}
	if (bu->getY() < al->getY() + al->getHeight() - 1)
	{
		side++;
	}

	return(side == 4);
}


int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE _prevInstance, LPSTR _cmdLine, int _cmdShow)
{
	MSG msg;
	done = FALSE;
	
	WNDCLASSEX frameWndClass;
	ZeroMemory(&frameWndClass, sizeof(WNDCLASSEX));
	frameWndClass.style					= CS_OWNDC | CS_DROPSHADOW | CS_VREDRAW | CS_HREDRAW;
	frameWndClass.cbSize				= sizeof(WNDCLASSEX);
	frameWndClass.lpfnWndProc			= (WNDPROC)frameWndProc;
	frameWndClass.hInstance				= _hInstance;
	frameWndClass.lpszClassName			= "InvadersFramedWindowClass";
	frameWndClass.hIcon					= LoadIcon(NULL, IDI_WINLOGO);
	frameWndClass.hCursor				= LoadCursor(NULL, IDC_ARROW);
	frameWndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	RegisterClassEx(&frameWndClass);

	x.create();
	x.show();

	bool update = true;

	srand(time(NULL));

	ship.initialize();
	e.initialize();

	for (int x = 0; x < 5; x++)
	{
		debris[x] = new Debris();
	}

	for (int x = 0; x < 10; x++)
	{
		//alienList.unshift((void*)new List());
		List* temp = new List();
		for (int y = 0; y < 6; y++)
		{
			//temp->unshift((void*)new Alien());
			Alien* al = new Alien();
			al->initialize();
			al->translate(x * 65, 70 + y * 50);
			temp->unshift(al);
		}
		alienList.unshift(temp);
	}
	

	for (int y = 0; y < 3; y++)
	{
		shieldList.push((void*)new Shield());
	}
	shieldList.reset();
	for (int y = 0; y < 3; y++)
	{
		((Shield*)shieldList.get())->initialize();
		((Shield*)shieldList.get())->translate(40 + y * 300, 800);
		shieldList.next();
	}
	shieldList.reset();
	lifeTime = GetTickCount();
	int refresh = 0;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		prevtime = lifeTime;
		lifeTime = GetTickCount();
		delta = lifeTime - prevtime;
		refresh += delta;
		
		if (keys[VK_LEFT])
		{
			ship.translate(delta/5, 0);
			update = true;
		}
		if (keys[VK_RIGHT])
		{
			ship.translate(delta/-5, 0);
			update = true;
		}
		if (keys[VK_SPACE]&& bulletList.getLength() < 3)
		{
			Bullet* temp = new Bullet();
			temp->initialize();
			temp->translate(ship.getX(), ship.getY());
			bulletList.push(temp);
			keys[VK_SPACE] = false;
		}
		
		x.update(delta);
		ship.update(delta);

		for (int x = 0; x < 5; x++)
		{
			if (debris[x]->update(delta) == 3)
			{
				delete debris[x];
				debris[x] = new Debris();
			}
		}
		int flag = 0;
		for (int y = 0; y < alienList.getLength(); y++)
		{
			for (int x = 0; x < ((List*)alienList.get())->getLength(); x++)
			{
				Alien* temp = ((Alien*)((List*)alienList.get())->get());
				temp->update(delta);
				if (((List*)alienList.get())->getSelectedIndex() == 0 && rand() % 100 == 1) 
				{
					//fire bullet
				}
				for (int z = 0; z < bulletList.getLength(); z++)
				{
					if (collisionFirstPast(temp, (Bullet*)bulletList.get()))
					{
						flag = 1;
						delete((Alien*)((List*)alienList.get())->remove());
						delete((Bullet*)bulletList.remove());
					}
					else
					{
						bulletList.next();
					}
				}
				bulletList.reset();
				if (!flag)
				{
					((List*)alienList.get())->next();
				}
					flag = 0;
			}
			((List*)alienList.get())->reset();
			alienList.next();
		}
		alienList.reset();
		
		for (int x = 0; x < bulletList.getLength(); x++)
		{
			if (((Bullet*)bulletList.get())->update(delta))
			{
				delete((Bullet*)bulletList.remove());
			}
			bulletList.next();
		}
		bulletList.reset();

		if (e.update(delta))
		{
			x.sendMessage(WM_QUIT, NULL, NULL);
		}
		
		//if (update)
		{
			x.invalidate();
		}
		update = false;
	}

alienList.reset();
	while(alienList.getLength())
	{
		List* temp = (List*)alienList.pop();
		while(temp->getLength())
		{
			delete((Alien*)temp->pop());
		}
		delete((List*)temp);
	}

	for (int x = 0; x < bulletList.getLength(); x++)
	{
		delete(bulletList.pop());
	}

	for (int x = 0; x < 10; x++)
	{
			delete debris[x];
	}

	UnregisterClass("InvadersFramedWindowClass", _hInstance);
	return(EXIT_SUCCESS);
}
