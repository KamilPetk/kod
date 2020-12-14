cmake_minimum_required(VERSION 2.6)
project(zad05)

add_executable(zad05 zad05.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp zad05_Arc.cpp zad05_Box.cpp zad05_Arrow.cpp zad05_RightTriangle.cpp)

target_link_libraries(zad05 -lfltk -lfltk_images)


install(TARGETS zad05 RUNTIME DESTINATION bin)
