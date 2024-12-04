#include "program.h"

void bkInit(
	bkProgram* pProgram, HINSTANCE hInstance, HINSTANCE hPreviousInstance,
	LPWSTR pCommandLine, int showFlag)
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
	bkWindowInit(&pProgram->window, pProgram->args.hInstance, pProgram->args.showFlag);
	bkWindowFree(&pProgram->window, pProgram->args.hInstance);
}

void bkFree(bkProgram* pProgram)
{
	if (!pProgram) return;
}
