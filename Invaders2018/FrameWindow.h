#ifndef FRAMEWINDOW_H
#define FRAMEWINDOW_H

#include <Windows.h>

class FrameWindow
{
	public:
		FrameWindow()
		{
			delta = new char[100];
			FillMemory(delta, 100, 48l);
			//ZeroMemory(delta, 100);
			len = 10;
			tot = 0;
		}

		void create()
		{
			int w = 768;
			int h = 1024;
			int x = 100;
			int y = 10;

			
			int styleEx = 0;//WS_EX_CLIENTEDGE;//WS_EX_OVERLAPPEDWINDOW;
				int style = WS_POPUP;//WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU /*| WS_THICKFRAME*/ | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

			hWnd = CreateWindowEx(styleEx, "InvadersFramedWindowClass", "Window", style, x, y, w, h, NULL, NULL, GetModuleHandle(NULL), NULL);
		}

		LRESULT sendMessage(UINT _msg, WPARAM _wParam, LPARAM _lParam)
		{
			return(SendMessage(hWnd, _msg, _wParam, _lParam));
		}

		BOOL show()
		{
			return(AnimateWindow(hWnd, 200, AW_ACTIVATE | AW_CENTER | AW_BLEND));
		}

		HDC getDC()
		{
			return(GetDC(hWnd));
		}

		int releaseDC(HDC _dc)
		{
			return(ReleaseDC(hWnd, _dc));
		}

		BOOL invalidate()
		{
			return(InvalidateRect(hWnd, NULL, FALSE));
		}

		int beginPaint()
		{
			dc = BeginPaint(hWnd, &ps);
			back = CreateCompatibleDC(dc);
			//bm = CreateCompatibleBitmap(dc, ps.rcPaint.right, ps.rcPaint.bottom);
			RECT r;
			GetClientRect(hWnd, &r);
			BITMAPINFO bmi;
			ZeroMemory(&bmi, sizeof(BITMAPINFO));
			bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
			bmi.bmiHeader.biWidth = ps.rcPaint.right;
			bmi.bmiHeader.biHeight = ps.rcPaint.bottom;
			bmi.bmiHeader.biPlanes = 1;
			bmi.bmiHeader.biBitCount = 32;
			bmi.bmiHeader.biCompression = BI_RGB;
			bm = CreateDIBSection(dc, &bmi, DIB_RGB_COLORS, (void**)&buff, NULL, 0);
			
			if (!bm)
			{
				DWORD er = GetLastError();

				MessageBox(NULL, "Error", "bmFail", MB_OK);
			}
			
			if (back)
			{
				SelectObject(back, bm);
				TextOut(back, 20, 20, delta, len);
				return(1);
			}
			return(0);
		}

		void drawDot(int _x, int _y, int _color)
		{
			int i = (ps.rcPaint.bottom*ps.rcPaint.right - 1) - ((_y)*ps.rcPaint.right + _x);
			if (i < ps.rcPaint.bottom * ps.rcPaint.right  && i > 0)
			{
				buff[i] = _color;
			}
		}

		void DrawSprite(int** _frame, int _x, int _y, int _w, int _h)
		{
			for (int y = 0; y < _h; y++)
			{
				for (int x = 0; x < _w; x++)
				{
					if (_frame[y][x] != 0)
					{
						int i = (ps.rcPaint.bottom*ps.rcPaint.right - 1) - ((_y + y)*ps.rcPaint.right + _x + x);
						if (i < ps.rcPaint.bottom * ps.rcPaint.right  && i > 0)
						{
							buff[i] = _frame[y][x];
						}
					}
				}
			}
		}

		BOOL stopPaint()
		{
			RECT r;
			GetClientRect(hWnd, &r);
			if (!BitBlt(dc, 0, 0, ps.rcPaint.right, ps.rcPaint.bottom, back, 0, 0, SRCCOPY))
			{
				DWORD er = GetLastError();

				MessageBox(NULL, "Error","BLitFail", MB_OK);
			}
			DeleteObject(bm);
			DeleteDC(back);
			return(EndPaint(hWnd, &ps));
		}

		void update(int _delta)
		{
			//len = wsprintf(delta, "Delta: %d\n\rTotal: %d", _delta, tot);
			len = wsprintf(delta, "Time: %d", tot/1000);
			tot += _delta;
		}

		~FrameWindow() { delete[](delta); }
	protected:
		HWND hWnd;
		HDC dc;
		HDC back;
		HBITMAP bm;
		PAINTSTRUCT ps;

		int tot;
		char* delta;
		int len;
		int *buff;
		
};

#endif
