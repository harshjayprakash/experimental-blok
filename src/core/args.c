/**
 * \file args.c
 * \date 18-08-2024
 * \brief Implementation of argument processing functions.
 *
 * This file contains function implementation for processing arguments provided by the
 * user through the CLI at runtime.
 */

#include "args.h"
#include "../presentation/graphics/theme.h"
#include "log.h"
#include "program.h"
#include "result.h"
#include <wchar.h>

static int mBlockScale = 15;

BlokResult BlokProcessArguments(void)
{
    if (!BlokIsInit())
    {
        return BlokLogAndReturn(
            BlokError,
            BlokCreateResult(BlokNotInit,
                             L"Argument Processing Failed: Program Not Initialised."));
    }

    int argumentCount = 0;
    LPWSTR *arguments = CommandLineToArgvW(GetCommandLineW(), &argumentCount);

    if (!arguments)
    {
        return BlokLogAndReturn(
            BlokError,
            BlokCreateResult(BlokNotInit, L"Arguments Processing Failed: Cannot Get."));
    }

    int scaleMode = 0;

    for (int index = 0; index < argumentCount; index++)
    {

        if (wcsncmp(arguments[index], L"--dark-mode", 12 * sizeof(unsigned short)) == 0)
        {
            BlokLog(BlokInformation,
                    BlokCreateResult(BlokNone, L"Theme Changed to Dark Mode."));
            BlokSetTheme(BlokDarkTheme);
        }
        if (wcsncmp(arguments[index], L"--light-mode", 13 * sizeof(unsigned short)) == 0)
        {
            BlokLog(BlokInformation,
                    BlokCreateResult(BlokNone, L"Theme Changed to Light Mode."));
            BlokSetTheme(BlokLightTheme);
        }
        if (wcsncmp(arguments[index], L"--scale", 13 * sizeof(unsigned short)))
        {
            scaleMode = 1;
            BlokLog(BlokInformation,
                    BlokCreateResult(BlokNone, L"Updating Block Scale."));
        }
        if (scaleMode)
        {
            int value = _wtoi(arguments[index]);
            if (value == 0)
            {
                scaleMode = 0;
                continue;
            }
            mBlockScale = value;
            scaleMode = 0;
        }
    }

    BlokUpdateColours();

    (void)LocalFree(arguments);

    return BlokCreateResult(BlokSuccess, L"Arguments Processed.");
}

int BlokGetBlockScale(void)
{
    return mBlockScale;
}