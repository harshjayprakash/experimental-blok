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
    "src/blok/model/dynlist.c" "src/blok/model/dynlist.h"
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

    # MAIN ENTRYPOINT
    "src/main.c"
 )

add_definitions(/DUNICODE /D_UNICODE /DSTRICT)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})