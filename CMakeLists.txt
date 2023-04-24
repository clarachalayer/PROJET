cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c src/pecheAuxCanards/pecheAuxCanards.c src/pecheAuxCanards/pecheAuxCanards.h src/tirAuxBallons/tirAuxBallons.c src/tirAuxBallons/tirAuxBallons.h src/snake/fonctionsnake.c src/snake/fonctionsnake.h src/constant.h)
add_executable(SNAKE src/snake/fonctionsnake.c src/snake/fonctionsnake.h src/snake/main.c )

IF(WIN32)
    target_link_libraries(PROJET -lmingw32 -lallegro-5.0.10-monolith-md-debug)
    target_link_libraries(SNAKE -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    IF(0)
        # Chemin Macpro
        INCLUDE_DIRECTORIES(/opt/homebrew/Cellar/allegro/5.2.8.0_2/include)
        LINK_DIRECTORIES(/opt/homebrew/Cellar/allegro/5.2.8.0_2/lib)
        file(GLOB LIBRARIES "/opt/homebrew/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
        message("LIBRARIES = ${LIBRARIES}")
        TARGET_LINK_LIBRARIES(PROJET ${LIBRARIES})
        TARGET_LINK_LIBRARIES(SNAKE ${LIBRARIES})
    ELSE()
        # Chemin Macair
        INCLUDE_DIRECTORIES(/opt/homebrew/Cellar/allegro/5.2.8.0_2/include)
        LINK_DIRECTORIES(/opt/homebrew/Cellar/allegro/5.2.8.0_2/lib)
        file(GLOB LIBRARIES "/opt/homebrew/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
        message("LIBRARIES = ${LIBRARIES}")
        TARGET_LINK_LIBRARIES(PROJET ${LIBRARIES})
        TARGET_LINK_LIBRARIES(SNAKE ${LIBRARIES})
    ENDIF()
ENDIF()




