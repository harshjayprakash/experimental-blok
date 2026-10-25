# Experimental Blok

> [!NOTE]
> As of v6.0, this project no longer follows a fixed release rhythm - defined as
> regular merges from the next branch into main.

## Overview

<p align="center">
  <img src="./docs/assets/xbk-preview-raster.png" alt="Screenshot of Program Running">
</p>

**Experimental Blok**, or simply *blok*, is a lightweight simulation of a user-generated
maze. A box entity moves around the canvas using the `WASD` or Arrow Keys, with
interactive controls for wall placement, scaling, and theming.

Originally created in February 2021 as a personal experiment to learn C and the Windows
API (after an initial C++ prototype), *Blok* had no defined goals or roadmap. The project
name emerged from a simple typo - misspelling "Block" during its early phase as
"The C Project." The first implementation rendered a box that moved freely across a native
window, but left visual trails due to missing repaint logic.

There was no formal documentation or GitHub presence during those early versions. The
motivation was exploratory - rooted in a interest with Windows internals and low-level
behaviour.

### The Canvas Grid

<p align="center">
  <img src="./docs/assets/xbk-canvas-demo.gif" alt="Canvas Interaction Demo">
</p>

The "Canvas Grid" is a component that provides a coordinate grid, scaled at fifteen
pixels, or another specified value at startup via the CLI. This grid contains the box
entity and a surface to create walls ("obstructs") that block the box's movement.

* The canvas adapts to the full window client area.
* The grid lines can be toggled with the `G` key, but are drawn before the box and obstructs,
  resulting in parts of the lines becoming hidden.
* A left click will create an obstruct at the current position.
* A left drag click will create a series of obstructs.
* A right click will remove an obstruct at the current position.
* A right drag click will remove a series of obstructs.

### The Information and Action Panel

<p align="center">
  <img src="./docs/assets/xbk-info-panel.png" alt="Information Panel">
</p>

The "Panel" is the component that shows information and provides controls to manipulate
the canvas.

* The current coordinates of the box are shown.
* The "Clear All" button removes all obstructs.
* The "Generate" button adds an obstruct at a random position.
* Shows the current number of obstructs on the canvas.
* The progress bar shows the internal dynamic array memory size storing the obstructs.
* The locked toggle shows whether the canvas has been locked
  * Enabled - any clicks or drags on the canvas are ignored.
  * Disabled - normal operation.

### Keyboard Shortcuts

* `W`: Move box up by current scale.
* `A`: Move box left by current scale.
* `S`: Move box down by current scale.
* `D`: Move box right by current scale.
* `G`: Toggle grid lines visibility.
* `O`: Generate an obstructive at a random location.
* `I`: Toggle interface visibility.
* `T`: Change theme.
* `C`: Clear all obstructs.
* `L`: Toggle canvas lock.
* `M`: Generate a set of random obstructs. _experimental: to generate whole maze_.

## The Architecture

The architecture reflects a quiet intent - each module is a shaped layer in a larger
system, design not just to function, but to clarify. At its centre is the `Context`
structure, accessed via helpers.

The layout is discoverable by design:

* **main.c**: Entry point and context bootstrap.
* **core**: Defines the `Context` structure and lifecycle functions.
* **fmt**: Converts between internal *blok* types and Win32 facing values.
* **gdi**: Manages graphics tool lifetimes and theme colours.
* **model**: Shapes and organises internal data structures.
* **state**: Tracks object state.
* **ui**: Hosts components, controls, and event handling logic.

## Compilation and Execution

### Pre-requisites

> This project is tested with MSVC on Windows, using CMake as its build system. While
> MinGW may work (even on Linux under Wine), it is not officially supported, and no 
> specific steps are provided.

Required Libraries

* **GDI32**: Used for graphics.
* **SHELL32**: Command-line parsing.
* **USER32**: Window messages, controls and event handling.
* **KERNEL32**: Memory and process interaction.

### Building the Project

```sh
# 1. Cloning the Repository and Move into Directory.
git clone https://github.com/harshjayprakash/experimental-blok.git
cd experimental-blok

# 2. Generate build files with CMake.
cmake -S . -B build

# 3. Compile the project
cmake --build build --config Release

# 4. Run the project
./build/Release/blok.exe
```

### Command Line Arguments

After compilation, the program can executed with various arguments to customise behaviour.
The available arguments are shown below.

| Argument          | Description                             |
| :---------------- | :-------------------------------------- |
| `--light-theme`   | Starts with the light theme.            |
| `--dark-theme`    | Starts with the dark theme. (default).  |
| `--scale [int]`   | Sets scale for both X and Y directions. |
| `--scale-x [int]` | Sets the scale for the X direction.     |
| `--scale-y [int]` | Sets the scale for the Y direction.     |

## Changelog

* See [Changelog and Version History](./CHANGELOG)

## Limitations and Known Issues

* **Layout/Positioning**: The box may be positioned outside of the bounds.
* **Panel Overlay**: The box can be covered by the panel. *This behaviour may persist by*
*design in future revisions.*
* **Scaling Sensitivity**: Specified scaling value may produce an unusable small or
oversize grid.
* **Drag Persistence**: Drag-click interaction can persist even if the cursor leaves
the window boundary.
* **Hitbox Detection**: Buttons and toggle regions - especially `Clear All` and `Generate`
have imprecise hitboxes, which may impact usability.
