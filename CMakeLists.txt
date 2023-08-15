cmake_minimum_required(VERSION 3.22)
project(test)

set(CMAKE_CXX_STANDARD 20)

add_executable(test "projects/contact/contact.c" "projects/cricket/welcome.h" "projects/cricket/menu.h" "projects/cricket/newscoresheet.h" "projects/cricket/main.h" "projects/cricket/final.h")
