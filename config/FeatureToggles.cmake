# FILE: FeatureToggles.cmake
# Provides a list of switches for turning features on and off.

# --- Macro Toggle Setup -----------------------------------------------------------------

macro(ST_FEATURE _MACRO _TOGGLE _COMMENT)
	set(${_MACRO} ${_TOGGLE} CACHE BOOL "${_COMMENT}" FORCE)
	if(${_MACRO})
		add_compile_definitions(${_MACRO})
		message(STATUS "[Sandstone Features] -- ${_MACRO}: ${_COMMENT}")
	endif()
endmacro()

# --- Functional Toggles -----------------------------------------------------------------

ST_FEATURE(STF_NO_SINGLE_INSTANCE  ON   "Skip Single Instance Checks")


# --- Not Implemented Toggles ------------------------------------------------------------
# Some described features may not be implemented and will be in future versions.

ST_FEATURE(STF_NO_MAZE_GENERATION  ON   "Disables Procedurally Generating Mazes")
ST_FEATURE(STF_NO_INPUT_LEGACY     OFF  "Ignores Box Movement via Arrow Keys")
ST_FEATURE(STF_NO_INPUT_CONTEXTUAL OFF  "Ignores Box Movement via WASD Keys")
ST_FEATURE(STF_NO_CANVAS_LOCK      OFF  "Disables the Canvas Lock")
ST_FEATURE(STF_NO_CANVAS_BOUNDS    ON   "Disables Canvas Size Constraints for the Box")
ST_FEATURE(STF_NO_CANVAS_GRID      OFF  "Disables Canvas Grid Toggle")
ST_FEATURE(STF_NO_INPUT_DRAG_CLICK OFF  "Disables Canvas Drag Click Interaction")
ST_FEATURE(STF_NO_CANVAS_LCLICK    OFF  "Disables Wall Creation by Left Click")
ST_FEATURE(STF_NO_CANVAS_RCLICK    OFF  "Disables Wall Removal by Right Click")
ST_FEATURE(STF_NO_WALLS            OFF  "Disables the Walls")
ST_FEATURE(STF_NO_BOX              OFF  "Disables the Main Box Entity")
ST_FEATURE(STF_NO_INTERFACE        OFF  "Disables the Interface Elements")
ST_FEATURE(STF_NO_MODERN_FONT      OFF  "Disables Modern Font Rendering")
ST_FEATURE(STF_NO_CANVAS_ZOOM      ON   "Disables Canvas Zooming")
ST_FEATURE(STF_NO_ARG_PARSING      OFF  "Disables CLI Args Parsing")
ST_FEATURE(STF_NO_PATH_FINDING     ON   "Disables Path Finding")
ST_FEATURE(STF_NO_NOTIFY           ON   "Disables Notify Messages")
ST_FEATURE(STF_NO_CUSTOM_THEME     ON   "Disables Custom Theming")
ST_FEATURE(STF_NO_CONFIG_FILE      ON   "Disables Startup Configuration File")
ST_FEATURE(STF_NO_HELP             ON   "Disables Help Screen")
ST_FEATURE(STF_NO_MOVABLE_PANEL    ON   "Disables Panel Movement")
ST_FEATURE(STF_NO_THEME_CHANGE     OFF  "Disables Theme Switching")
ST_FEATURE(STF_NO_WALLS_RANDOM     OFF  "Disables Random Wall Generation")
ST_FEATURE(STF_NO_TOGGLE_INTERFACE OFF  "Disables Interface Toggle")
ST_FEATURE(STF_NO_WALL_CLEAR       OFF  "Disables Clearing Canvas")
ST_FEATURE(STF_NO_CANVAS_RESET     OFF  "Disables Canvas Reset")