/*****************************************************************//**
 * \file   window.h
 * \brief  Contains window related functions and structures.
 * 
 * \author Harsh Jayprakash
 * \date   04 of December 2024
 *********************************************************************/

#ifndef __BLOK_WINDOW_H
#define __BLOK_WINDOW_H

#define STRICT 1
#include <Windows.h>

typedef struct bkWindow
{
	HWND hWindow;
	WNDCLASSEXW klass;
} bkWindow;

void bkWindowInit(bkWindow* pWindow, HINSTANCE hInstance);

WPARAM bkWindowShow(bkWindow* pWindow, const int kShowFlag);

void bkWindowFree(bkWindow* pWindow, HINSTANCE hInstance);

#endif // !__BLOK_WINDOW_H
