cmake_minimum_required(VERSION 4.2)
project(TF_609307 C)

set(CMAKE_C_STANDARD 23)

add_subdirectory("C:/raylib/raylib" raylib_build)

add_executable(TF_609307
        ../src/main.c
        ../src/jogo.h
        ../mapas/mapa.c
        ../src/jogador.c
        ../src/eventos.c)

TARGET_LINK_LIBRARIES(TF_609307 PRIVATE raylib)
