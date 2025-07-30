# Development History

> [!WARNING]
> This document is a work in progress.

While *Blok* has evolved into a modular, intentionally designed project, early versions
were built organically - with limited or no technical documentation. This history
attempts to reconstruct and narrate major shifts from memory and surviving prototypes.

## The Origins

<p align="center">
  <img src="./../docs/assets/xbk-original-recreation.gif" alt="">
  <br>
  <caption>
    A recreation of <i>Blok</i> as of September 2021.
  </caption>
</p>

*Blok* did not begin as a fully developed project idea. It started with confusion,
curiosity, and C++. In February 2021, I had Microsoft Visual Studio 2019 installed as I
was learning Visual Basic .NET for the A-Level Computer Science course at college. It
offered C++ as a project option - and that's where things started. I was interested on how
Windows applications worked under the hood.

> At the time, it was just "The C Project". No codename. No goals. Just exploration.

 
<!--
Visual Studio, generated a base application written in C++. It looked strange, from using
types such as `HINSTANCE`, `HWND`, `LPCWSTR`, `TCHAR`. Even the entrypoint of
`WinMain(HINSTANCE, HINSTANCE, LPSTR, int)` - this is not even the wide character version
(wWinMain) or the macro-based _tWinMain. I was always used to "Main", with just command
line arguments.

In the Windows API, it is not as simple as initialising the window and showing it within
two lines `Form window = new Form(); window.Show();`

Painting involved using a library called "GDI32". 

* Exploring GDI, GDI+ (Initialised, but not used).
* The difficulty of understanding Windows Types (Hungarian Notation)
* Memory Allocation
* The Failing to Update the Window.
* Using Namespaces for Organisation.
* Could not put Window Procedure in Custom Window Class.
* Concept of Header Files and Source Files.
* Unicode and ASCII, TCHAR
* Compiling and Linking
* Console App vs Desktop App, not both.

## The GitHub Emergence

| Date           | Name                            |
| :------------- | :------------------------------ |
| June 2021      | "The C Project"                 |
| September 2021 | "The Block Experiment"          |
| October 2022   | "The Blok Experiment"           |
| July 2023      | "The Experimental Blok Project" |
| February 2025  | "Experimental Blok"             |

* Introduced to the world - October 2022.
* First project on GitHub
* A switch to semi-annual changes.
* Adding custom drawn components and adapting to Window Size.
* Clickable Regions.
* Drawing Text.
* Updating Colours.
* Deleting Handles instead of 
* Messing with the message loop.

* Name
  * Changes "The Experimental Block Project" to "Blok Experiment" to "Experimental Blok"
* Introduced codename to prevent clashing with the WINAPI.
  * "XBlok" -> "blok"
* 

## The Modern Re-Design

* Update codename -> "Sandstone".
* Focus on Architecture - Not rigid.
* Focus on Scalability.
* Increased used of colours.
* Modularity.
* Redesigned UI to match modern application.
* Hover effects
* Improvement in User Experiences.
* Better Colours.
* Focus on the elimating globals and static variables.
* Contextual Structure (Like a HANDLE)
* A switch to Epoch Semantic Versioning.
* Better CLI Argument Handling
* Increased Security and Guard Clauses.
* Custom Grid Scaling.
* Drag Click
* Better Font Readability.
* Abstractions.


## The Future of Blok


## Useful Sources

* MSDN
-->
