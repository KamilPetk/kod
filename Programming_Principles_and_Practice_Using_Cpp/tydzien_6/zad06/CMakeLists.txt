cmake_minimum_required(VERSION 2.6)
project(zad06)

add_executable(zad06 zad06.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

target_link_libraries(zad06 -lfltk -lfltk_images)

install(TARGETS zad06 RUNTIME DESTINATION bin)
