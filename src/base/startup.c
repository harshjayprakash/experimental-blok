#include "startup.h"

int BlokStartUpInfoSave(
    StartUpInfo *sui, HINSTANCE instance, LPWSTR commandLine, DWORD showFlag)
{
    if (sui == 0) { return 1; }

    sui->instance = instance;
    sui->commandLine = commandLine;
    sui->showFlag = showFlag;

    return 0;
}