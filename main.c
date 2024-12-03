#define STRICT 1
#include <Windows.h>
#include "core/program.h"

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
	_In_ INT nCmdShow)
{
	bkProgram program;
	bkInit(&program, hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	bkRun(&program);
	bkFree(&program);
	return 0;
}
