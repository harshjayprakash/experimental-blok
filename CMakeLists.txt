cmake_minimum_required(VERSION 3.10)

project(blok C)

include(${CMAKE_SOURCE_DIR}/config/FeatureToggles.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCES
    # FORMAT MODULE
    "source/sandstone/fmt/convert.c" "source/sandstone/fmt/convert.h"

    # GDI MODULE
    "source/sandstone/gdi/graphics.c" "source/sandstone/gdi/graphics.h"
    "source/sandstone/gdi/rendertools.c" "source/sandstone/gdi/rendertools.h"
    "source/sandstone/gdi/theme.c" "source/sandstone/gdi/theme.h"

    # MODEL MODULE
    "source/sandstone/model/direction.c" "source/sandstone/model/direction.h"
    "source/sandstone/model/dynlist.c" "source/sandstone/model/dynlist.h"
    "source/sandstone/model/square.h"
    "source/sandstone/model/vector.c" "source/sandstone/model/vector.h"

    # STATE MODULE
    "source/sandstone/state/state.c" "source/sandstone/state/state.h"

    # UI MODULE
    "source/sandstone/ui/components/canvas.c" "source/sandstone/ui/components/canvas.h"
    "source/sandstone/ui/components/panel.c" "source/sandstone/ui/components/panel.h"
    "source/sandstone/ui/controls/button.c" "source/sandstone/ui/controls/button.h"
    "source/sandstone/ui/controls/progressbar.c" "source/sandstone/ui/controls/progressbar.h"
    "source/sandstone/ui/controls/text.c" "source/sandstone/ui/controls/text.h"
    "source/sandstone/ui/controls/toggle.c" "source/sandstone/ui/controls/toggle.h"
    "source/sandstone/ui/events/action.c" "source/sandstone/ui/events/action.h"
    "source/sandstone/ui/events/process.c" "source/sandstone/ui/events/process.h"
    "source/sandstone/ui/frame/window.c" "source/sandstone/ui/frame/window.h"
    "source/sandstone/ui/viewport.c" "source/sandstone/ui/viewport.h"

    # MAIN MODULE
    "source/sandstone/core/context.c" "source/sandstone/core/context.h"
     "source/sandstone/core/lifecycle.h" "source/sandstone/core/lifecycle.c"
    "source/sandstone/core/args.c" "source/sandstone/core/args.h"

    # MAIN ENTRYPOINT
    "source/main.c"
 )

add_definitions(/DUNICODE /D_UNICODE /DSTRICT)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})