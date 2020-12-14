cmake_minimum_required(VERSION 2.6)
project(zad02)

add_executable(zad02 zad02.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

target_link_libraries(zad02 -lfltk -lfltk_images)


install(TARGETS zad02 RUNTIME DESTINATION bin)
