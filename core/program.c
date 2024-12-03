#include "program.h"

void bkInit(
	bkProgram* pProgram, HINSTANCE hInstance, HINSTANCE hPreviousInstance,
	LPWSTR pCommandLine, int showFlag
)
{
	if (!pProgram) return;
	pProgram->args.hInstance = hInstance;
	pProgram->args.hPreviousInstance = hPreviousInstance;
	pProgram->args.pCommandLine = pCommandLine;
	pProgram->args.showFlag = showFlag;
}

void bkRun(bkProgram* pProgram)
{
	if (!pProgram) return;
	(void)MessageBoxW(NULL, L"This is a test.", L"Blok", MB_OK);
}

void bkFree(bkProgram* pProgram)
{
	if (!pProgram) return;
}
