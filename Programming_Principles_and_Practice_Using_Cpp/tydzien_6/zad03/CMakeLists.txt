cmake_minimum_required(VERSION 2.6)
project(zad03ver02)

add_executable(zad03ver02 zad03.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

target_link_libraries(zad03ver02 -lfltk -lfltk_images)

install(TARGETS zad03ver02 RUNTIME DESTINATION bin)
