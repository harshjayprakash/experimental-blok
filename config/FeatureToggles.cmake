# Provides a list of switches for turning features on and off.
# Please do not touch the if statements in this file. These checks ensure that the
# features for basic functionality are still available.

macro(ST_FEATURE _MACRO _TOGGLE _COMMENT)
	set(${_MACRO} ${_TOGGLE} CACHE BOOL "${_COMMENT}" FORCE)
	if(${_MACRO})
		add_compile_definitions(${_MACRO})
		message(STATUS "[Sandstone Features] -- ${_MACRO}: ${_COMMENT}")
	endif()
endmacro()

ST_FEATURE(STF_NO_SINGLE_INSTANCE  ON   "Skip Single Instance Checks")
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