cmake_minimum_required(VERSION 3.27)
project(pacman_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(pacman_cpp main.cpp
        lib/player/player.cpp
        lib/player/player.h
        lib/random_gen.cpp
        lib/random_gen.h
        lib/player/pacman.cpp
        lib/player/pacman.h
        lib/player/ghost.cpp
        lib/player/ghost.h
        lib/board/non_player.cpp
        lib/board/non_player.h
        lib/board/base_block.h
        lib/board/base_block.cpp
        lib/board/game_board.cpp
        lib/board/game_board.h
        lib/ai_play.cpp
        lib/ai_play.h
        lib/init_config.h
        lib/base4.cpp
        lib/base4.h)
