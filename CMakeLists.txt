cmake_minimum_required(VERSION 3.8)

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
enable_language(RC)

set(SOURCES
    "src/main.c"

    "src/base/context.c" "src/base/context.h"
    "src/base/lifecycle.c" "src/base/lifecycle.h"

    "src/cmd/args.c" "src/cmd/args.h"
    "src/cmd/console.c" "src/cmd/console.h"

    "src/gdi/drawtools.c" "src/gdi/drawtools.h"
    "src/gdi/graphics.c" "src/gdi/graphics.h"
    "src/gdi/theme.c" "src/gdi/theme.h"

    "src/model/direction.c" "src/model/direction.h"
    "src/model/dynlist.c" "src/model/dynlist.h"
    "src/model/square.h"
    "src/model/vector.c" "src/model/vector.h"

    "src/store/state.c" "src/store/state.h"

    "src/ui/controls/button.c" "src/ui/controls/button.h"
    "src/ui/controls/progressbar.c" "src/ui/controls/progressbar.h"
    "src/ui/controls/text.c" "src/ui/controls/text.h"
    "src/ui/controls/toggle.c" "src/ui/controls/toggle.h"
    "src/ui/components/canvas.c" "src/ui/components/canvas.h"
    "src/ui/components/panel.c" "src/ui/components/panel.h"
    "src/ui/events/process.c" "src/ui/events/process.h"
    "src/ui/frame/window.c" "src/ui/frame/window.h"
    "src/ui/viewport.c" "src/ui/viewport.h"

    "src/utils/convert.c" "src/utils/convert.h"

    "res/resource.rc"
)

add_definitions(/DUNICODE /D_UNICODE /DSTRICT)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})