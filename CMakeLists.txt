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
    "source/standstone/cmd/args.c" "source/standstone/cmd/args.h"
    "source/standstone/cmd/console.c" "source/standstone/cmd/console.h"

    # FORMAT MODULE
    "source/standstone/fmt/convert.c" "source/standstone/fmt/convert.h"

    # GDI MODULE
    "source/standstone/gdi/graphics.c" "source/standstone/gdi/graphics.h"
    "source/standstone/gdi/rendertools.c" "source/standstone/gdi/rendertools.h"
    "source/standstone/gdi/theme.c" "source/standstone/gdi/theme.h"

    # MODEL MODULE
    "source/standstone/model/direction.c" "source/standstone/model/direction.h"
    "source/standstone/model/dynlist.c" "source/standstone/model/dynlist.h"
    "source/standstone/model/square.h"
    "source/standstone/model/vector.c" "source/standstone/model/vector.h"

    # STATE MODULE
    "source/standstone/state/state.c" "source/standstone/state/state.h"

    # UI MODULE
    "source/standstone/ui/components/canvas.c" "source/standstone/ui/components/canvas.h"
    "source/standstone/ui/components/panel.c" "source/standstone/ui/components/panel.h"
    "source/standstone/ui/controls/button.c" "source/standstone/ui/controls/button.h"
    "source/standstone/ui/controls/progressbar.c" "source/standstone/ui/controls/progressbar.h"
    "source/standstone/ui/controls/text.c" "source/standstone/ui/controls/text.h"
    "source/standstone/ui/controls/toggle.c" "source/standstone/ui/controls/toggle.h"
    "source/standstone/ui/events/action.c" "source/standstone/ui/events/action.h"
    "source/standstone/ui/events/process.c" "source/standstone/ui/events/process.h"
    "source/standstone/ui/frame/window.c" "source/standstone/ui/frame/window.h"
    "source/standstone/ui/viewport.c" "source/standstone/ui/viewport.h"

    # MAIN MODULE
    "source/standstone/context.c" "source/standstone/context.h"
    "source/standstone/lifecycle.c" "source/standstone/lifecycle.h"

    # MAIN ENTRYPOINT
    "source/main.c"
)

add_definitions(/DUNICODE /D_UNICODE /DSTRICT)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})