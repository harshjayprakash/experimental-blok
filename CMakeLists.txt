cmake_minimum_required(VERSION 3.10)

if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "")
    string(JOIN "" CMAKE_MSVC_DEBUG_INFORMATION_FORMAT 
        "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,"
        "$<CXX_COMPILER_ID:MSVC>>,"
        "$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,"
        "$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(blok C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCES
    # COMMAND LINE MODULE
    "source/blok/cmd/args.c" "source/blok/cmd/args.h"
    "source/blok/cmd/console.c" "source/blok/cmd/console.h"

    # FORMAT MODULE
    "source/blok/fmt/convert.c" "source/blok/fmt/convert.h"

    # GDI MODULE
    "source/blok/gdi/graphics.c" "source/blok/gdi/graphics.h"
    "source/blok/gdi/rendertools.c" "source/blok/gdi/rendertools.h"
    "source/blok/gdi/theme.c" "source/blok/gdi/theme.h"

    # MODEL MODULE
    "source/blok/model/direction.c" "source/blok/model/direction.h"
    "source/blok/model/dynlist.c" "source/blok/model/dynlist.h"
    "source/blok/model/square.h"
    "source/blok/model/vector.c" "source/blok/model/vector.h"

    # STATE MODULE
    "source/blok/state/state.c" "source/blok/state/state.h"

    # UI MODULE
    "source/blok/ui/components/canvas.c" "source/blok/ui/components/canvas.h"
    "source/blok/ui/components/panel.c" "source/blok/ui/components/panel.h"
    "source/blok/ui/controls/button.c" "source/blok/ui/controls/button.h"
    "source/blok/ui/controls/progressbar.c" "source/blok/ui/controls/progressbar.h"
    "source/blok/ui/controls/text.c" "source/blok/ui/controls/text.h"
    "source/blok/ui/controls/toggle.c" "source/blok/ui/controls/toggle.h"
    "source/blok/ui/events/action.c" "source/blok/ui/events/action.h"
    "source/blok/ui/events/process.c" "source/blok/ui/events/process.h"
    "source/blok/ui/frame/window.c" "source/blok/ui/frame/window.h"
    "source/blok/ui/viewport.c" "source/blok/ui/viewport.h"

    # MAIN MODULE
    "source/blok/context.c" "source/blok/context.h"
    "source/blok/lifecycle.c" "source/blok/lifecycle.h"

    # MAIN ENTRYPOINT
    "source/main.c"
)

add_definitions(/DUNICODE /D_UNICODE /DSTRICT)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})