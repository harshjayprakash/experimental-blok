# The Experimental Block Project

![Banner](./doc/blok-banner.png)

> [!NOTE]
> As this is an experiment without a clear roadmap, this program will likely always be in
> the developing stage. There will not be a deployed executable file. However, there will
> be tagged versions if there is a significant enough change and is stable enough (no
> guarantee). This program contains absolutely no warranty.

## Usage

![Program Light and Dark Mode](./doc/blok-dual-screenshot.png)

| Ref. | Description |
|:----------|:------------|
| A | This refers to the Canvas component, where most of the interaction will take place. |
| B | The Panel component, which shows information and additional actions. |
| C | The native window title. |
| 1 | The "Block" (the main part or component) is a coloured square (blue in light mode, aqua in dark mode) that can be moved by the arrow keys and cannot move past the "Obstructables". |
| 2 | An "Obstructable", a sort of wall for the "Block". This can be added by clicking on the canvas with the mouse. |
| 3 | Shows the coordinates of the "Block". |
| 4 | A button to clear all the "Obstructables" on the canvas. |
| 5 | A toggle button to lock the canvas from registering any clicks. This stops the generation of "Obstructables". |
| 6 | Shows the number of "Obstructables" and a progress bar relative to the vector size. |
| 7 | A button to randomly generate "Obstructables" on the canvas. The number of "Obstructables" is based on the window size. |

![Program Logging](./doc/blok-logging.png)

This program logs messages to the console as seen in the above screenshot. Any internal
errors are shown in the console.

## Compilation and Execution

This program uses the make build system. Note, this uses the clang compiler, you can
switch it to the GCC compiler, if you wish by changing the CC variable in the makefile.
You can run the following:

```pwsh
# Creating the folders for the compilation process.
mingw32-make init

# Building and linking the program.
mingw32-make build

# Running the program. 
# Optional arguments "--light-mode" or "--dark-mode" for the theming.
# Default is dark mode.
# Other arguments include "--scale <number>" where the scale is specified.
# Default scaling is 15.
.\bin\blok
```

## What's New (24Q3.01)

- Re-defined Internal Architecture
- New Console Logging
- Re-implementated Result System
- Re-implementated Clear All Button
- Visual Vector Size Indicator
- Changed Style of Movable Block
- Switched Colour Scheme
- Improved Doxygen Documentation
- New Ability to Specify Scale via CLI
- Double Buffered UI

## Limitations and Issues

- GDI32 graphics flicking.
- Scaling specified can be too small or too large.
- Block can go under the panel.
- Generating obstructables can take time.

## Find an issue

If you find an issue, feel free to report it under the issues tab of this repository.
