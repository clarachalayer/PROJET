cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c src/pecheAuxCanards/pecheAuxCanards.c src/pecheAuxCanards/pecheAuxCanards.h src/tirAuxBallons/tirAuxBallons.c src/tirAuxBallons/tirAuxBallons.h)

INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.8.0_2/include)
LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.8.0_2/lib)
file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")
TARGET_LINK_LIBRARIES(PROJET ${LIBRARIES})



