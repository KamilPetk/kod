cmake_minimum_required(VERSION 2.6)
project(zad03)

add_executable(zad03 zad03.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

target_link_libraries(zad03 -lfltk -lfltk_images)


install(TARGETS zad03 RUNTIME DESTINATION bin)
