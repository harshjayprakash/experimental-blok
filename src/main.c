/**
 * \file main.c
 * \date 13-08-2024
 * \brief Implementation of the entrypoint.
 *
 * This file contains the WinMain entrypoint functions for Windows programs.
 */

#define STRICT 1
#include "core/args.h"
#include "core/log.h"
#include "core/program.h"
#include "core/result.h"
#include <Windows.h>

/**
 * \brief The entrypoint of the program.
 *
 * \param hInstance The instance handle.
 * \param hPrevInstance Previous version of the instance handle.
 * \param lpCmdLine The command line.
 * \param nShowCmd How the program will be displayed.
 * \return Exit code 0 for success.
 */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
                      int nShowCmd)
{
    (void)hPrevInstance;
    (void)lpCmdLine;

    BlokInitLogger(BlokFile);

    (void)BlokInit(hInstance, nShowCmd);
    (void)BlokProcessArguments();
    (void)BlokStart();
    (void)BlokFree();

    BlokFreeLogger(); 

    return (int)BlokSuccess;
}