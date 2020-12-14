cmake_minimum_required(VERSION 2.6)
project(zad01)

add_executable(zad01 zad01.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

target_link_libraries(zad01 -lfltk -lfltk_images)


install(TARGETS zad01 RUNTIME DESTINATION bin)
