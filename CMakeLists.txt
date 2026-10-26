cmake_minimum_required(VERSION 3.10)

project(blok C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCES
    # FORMAT MODULE
    "src/blok/fmt/convert.c" "src/blok/fmt/convert.h"

    # GDI MODULE
    "src/blok/gdi/graphics.c" "src/blok/gdi/graphics.h"
    "src/blok/gdi/rendertools.c" "src/blok/gdi/rendertools.h"
    "src/blok/gdi/theme.c" "src/blok/gdi/theme.h"

    # MODEL MODULE
    "src/blok/model/direction.c" "src/blok/model/direction.h"
    "src/blok/model/dynarr.c" "src/blok/model/dynarr.h"
    "src/blok/model/square.h"
    "src/blok/model/vector.c" "src/blok/model/vector.h"

    # STATE MODULE
    "src/blok/state/state.c" "src/blok/state/state.h"

    # UI MODULE
    "src/blok/ui/components/canvas.c" "src/blok/ui/components/canvas.h"
    "src/blok/ui/components/panel.c" "src/blok/ui/components/panel.h"
    "src/blok/ui/controls/button.c" "src/blok/ui/controls/button.h"
    "src/blok/ui/controls/progressbar.c" "src/blok/ui/controls/progressbar.h"
    "src/blok/ui/controls/text.c" "src/blok/ui/controls/text.h"
    "src/blok/ui/controls/toggle.c" "src/blok/ui/controls/toggle.h"
    "src/blok/ui/events/action.c" "src/blok/ui/events/action.h"
    "src/blok/ui/events/process.c" "src/blok/ui/events/process.h"
    "src/blok/ui/frame/window.c" "src/blok/ui/frame/window.h"
    "src/blok/ui/viewport.c" "src/blok/ui/viewport.h"

    # MAIN MODULE
    "src/blok/core/context.c" "src/blok/core/context.h"
    "src/blok/core/lifecycle.h" "src/blok/core/lifecycle.c"
    "src/blok/core/args.c" "src/blok/core/args.h"

    # INFO MODULE
    "src/blok/info/version.h"

    # MAIN ENTRYPOINT
    "src/main.c"
 )

set(BLOK_VERSION_STRING "")
set(BLOK_MILESTONE 8.0)
set(BLOK_SVN_REVISION "")

execute_process(
    COMMAND svn info --show-item revision
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE BLOK_SVN_REVISION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

if (DEFINED BLOK_MILESTONE)
    string(APPEND BLOK_VERSION_STRING "m${BLOK_MILESTONE}")
endif()

if (NOT BLOK_SVN_REVISION STREQUAL "")
    string(APPEND BLOK_VERSION_STRING " (r${BLOK_SVN_REVISION})")
endif()

add_definitions(/DUNICODE /D_UNICODE /DSTRICT /DBLOK_VERSION_STRING="${BLOK_VERSION_STRING}")
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})