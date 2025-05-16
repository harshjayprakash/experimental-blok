# Experimental Blok: An exploration of the Win32 API

![Banner (Decorative)](./doc/xbk-banner-raster.png)

> [!NOTE]
> This version "5.0 --25H2A" is currently still in development, the features described may
> not work correctly, at all, or subject to change. These changes will merged to main
> in Autumn 2025.

## Overview

"Experimental Blok", or simply "Blok" is a small and minimal simulation of a user
generated maze, and a box that moves around with the WASD or Arrow Keys.

This project originated as a way to learn C and the Windows API, although it was initially
written in C++, starting in February of 2021. _It was not available on GitHub at this_
_time_. This project had no specific goals or direction. The name "Blok" resulted from an
accidental misspelling of "block" during its initial phase, when I called it the "C
Project". The program could render a square that moved within a native window but would
leave a trail due to lacking window updates.

The motivation for creating this project is not entirely clear; however, I've always had
a strong interest in the Windows Operating System.

![Light Dark Mode Screenshot](./doc/xbk-preview-light-dark.png)

### The Canvas Grid

The "Canvas Grid" is a components that provides a coordinate grid, scaled at fifteen
pixels or another specified value at startup (via CLI). This grid contains the box entity
and a surface to create walls ("obstructs") that blocks the box's movement.

* The canvas is adapts to the full window client area.
* The grid lines can be toggled with `G` key, but is drawn before the box and obstructs -
resulting in parts of lines becoming hidden.
* A left click will create an obstruct at the current position.
* A left drag click will create a series of obstructs.
* A right click will remove an obstruct at the current position.
* A right drag click will remove a series of obstructs.

### The Information and Action Panel

The "Panel" is the component that shows information and provides controls to manipulate
the canvas.

* The current coordinates of box is shown.
* The "Clear All" button removes all obstructs.
* The "Generate" button adds an obstruct at a random position.
* Shows the current number of obstructs on the canvas.
* The progress bar shows the internal dynamic array memory size storing the obstructs.
* The locked toggle, shows whether the canvas has been locked
  * Enabled - any clicks or drags on the canvas are ignored.
  * Disabled - normal operation.

### The Console

The "Console" is a separate window displaying information, warning and/or error messages
while the program is running.

* Does not accept user input.
* Must be enabled on startup by passing the `--show-console` argument.

### Keyboard Shortcuts

* `W`: Move box up by current scale.
* `A`: Move box right by current scale.
* `S`: Move box down by current scale.
* `D`: Move box left by current scale.
* `G`: Toggle grid lines visibility.
* `O`: Generate an obstructive at a random location.
* `I`: Toggle interface visibility.
* `T`: Change theme.
* `C`: Clear all obstructives.
* `L`: Toggle canvas lock.

## The Architecture

The architecture of the program is based around the `Context` structure, storing the
state of the entire program as a sort of global through a singleton helper function.

![Program Architecture (Shows Interaction Between Layers)](./doc/xbk-arch-raster.png)

| Folder | Description |
| :----- | :---------- |
| (main.c) | entrypoint. |
| base   | contains the main singleton context structure (stores all program data) and lifecycle functions |
| cmd | handles the console host allocation and argument processing. |
| gdi | handles the windows drawing and painting tools, and theme handling. |
| model | model object structures and operations. |
| store | stores the object state. |
| ui | handles the user interface (including event handling and components). |
| utils | any unclassified function such as converting from blok to win -types and vise versa. |

## Compilation and Execution

This project uses the CMake build system. I use MSVC.

The executable can be run with extra arguments

```pwsh
# Runs with the default configuration
blok.exe

# Any of the following arguments can be passed to the program:
#
#     --light-theme
#         Specifies the program to startup with the light theme.
#
#     --dark-theme
#         Specifies the program to startup with the dark theme (default).
#
#     --show-console
#         Shows the information console while the program is running.
#         The console cannot be started after the program is running due to
#             implementation.
#
#     --scale [integer]
#         Specifies the scale in both x and y direction (default: 15).
#
#     --scale-x [integer]
#         Specifies the scale in the x direction (default: 15).
#
#     --scale-y [integer]
#         Specifies the scale in the y direction (default: 15).
```

## Changelog

### Version 5.0 (Snapshot 25H2A) - September 2025

* **Overview**: This version is complete rewrite.

  * Functionality
    * Added new keyboard shortcuts.
    * Implemented drag click.
    * Disabled console by default.
    * Implemented obstruct removal.
  * Internal
    * Changed entrypoint to `wWinMain`.
    * Improved performance.
    * Changed build system to CMake.
    * Updated Architecture to a contextual system.
    * Improved win32 message handling.
    * Improved window painting operation.
    * Implemented new control and component update functions.
    * Renamed `Vector` to `DynList`.
    * Refactored `Size` and `Position` to `VectorII`
    * Implemented direction to vectorii function.
    * Update text rendering to use `DrawTextW` instead of `TextOutW`.
    * Updated function naming convention.
    * Improved doxygen documentation.
    * Improved modularity.
  * Visual
    * Implemented single instance mutex (mutant winobj).
    * Updated colour scheme.
    * Redesigned UI.
    * Implemented on hover styles.
    * Changed panel width.
    * Updated font to "Segoe UI".
    * Added executable resource file.
    * Reduced gdi32 flickering.
    * Implemented panel visibility.
    * Implemented grid visibility.



## Limitations and Known Issues

* Generating an obstructs (Button/Keyboard) may create a duplicate positioned wall.
* Box can go under the panel.
* Box can go out of bounds of the window.
* Specified scaling can be too small or too big.
* Drag click can continue if the cursor leaves the window.
* Holding down the generate button will not continue to generate obstructs.

## Potential Future Features

* Move around canvas.
* Movable panel.
* Re-sizable panel.
* Custom theming.
* Loading configuration from file.
* File-based logging.
* Small alert box system.
* Keyboard shortcut guide screen.
* Save state to file.
* Import state from file.
* Generate entire maze.
* Find path from box to point.
