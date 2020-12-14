cmake_minimum_required(VERSION 2.6)
project(zad04)

add_executable(zad04 zad04.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

target_link_libraries(zad04 -lfltk -lfltk_images)

install(TARGETS zad04 RUNTIME DESTINATION bin)
