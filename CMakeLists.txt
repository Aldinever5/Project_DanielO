cmake_minimum_required(VERSION 3.5)

project(IN_cuba LANGUAGES C++)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_C++_STANDARD 11)
set(CMAKE_C++_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} "main.cpp" "DB_local.cpp" "DB_local.h"
"main_gui.cpp" "Sensor.cpp" "Sensor.h" "Incubadora.cpp" "Incubadora.h" "IN_cuba_app.h" "IN_cuba_app.cpp")

target_link_libraries (${PROJECT_NAME} sqlite3 mysqlclient Qt5::Core )

add_executable(${PROJECT_NAME}_gui "main.cpp" "DB_local.cpp" "DB_local.h" "IN_cuba_app.h" "IN_cuba_app.cpp"
"main_gui.cpp" "Sensor.cpp" "Sensor.h" "Incubadora.cpp" "Incubadora.h" "mainwindow.h" "mainwindow.cpp" "mainwindow.ui")


target_link_libraries(IN_cuba PRIVATE Qt5::Widgets)
