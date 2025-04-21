#ifndef _BLOK_STARTUP_H_
#define _BLOK_STARTUP_H_

#include <Windows.h>

typedef struct _StartUpInfo {
    HINSTANCE instance;
    LPWSTR commandLine;
    DWORD showFlag;
} StartUpInfo;

int BlokStartUpInfoSave(
    StartUpInfo *sui, 
    HINSTANCE instance, 
    LPWSTR commandLine, 
    DWORD showFlag
);

#endif // _BLOK_STARTUP_H_