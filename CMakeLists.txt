cmake_minimum_required(VERSION 3.10)

project(Blok C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_COMPIL)

add_definitions(/DUNICODE /D_UNICODE /DSTRICT=1)

set(SOURCES
	"src/main.c"
	"src/core/args.c" "src/core/args.h"
	"src/core/log.c" "src/core/log.h"
	"src/core/program.c" "src/core/program.h"
	"src/core/result.c" "src/core/result.h"
	"src/model/object/square.c" "src/model/object/square.h"
	"src/model/utility/direction.h"
	"src/model/utility/position.c" "src/model/utility/position.h"
	"src/model/utility/size.c" "src/model/utility/size.h"
	"src/model/utility/vector.c" "src/model/utility/vector.h"
	"src/presentation/window.c" "src/presentation/window.h"
	"src/presentation/components/canvas.c" "src/presentation/components/canvas.h"
	"src/presentation/components/panel.c" "src/presentation/components/panel.h"
	"src/presentation/controls/button.h"
	"src/presentation/controls/progress-bar.h"
	"src/presentation/controls/text.h"
	"src/presentation/controls/toggle-button.h"
	"src/presentation/events/handler.c" "src/presentation/events/handler.h"
	"src/presentation/graphics/drawing.c" "src/presentation/graphics/drawing.h"
	"src/presentation/graphics/theme.c" "src/presentation/graphics/theme.h"
	"src/presentation/objects/block.c" "src/presentation/objects/block.h"
	"src/presentation/objects/obstructables.c" "src/presentation/objects/obstructables.h"
)

add_executable(${PROJECT_NAME} WIN32 ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE user32 gdi32 kernel32 shell32)