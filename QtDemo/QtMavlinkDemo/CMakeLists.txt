cmake_minimum_required(VERSION 3.5)

project(QtMavlinkDemo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/c_library_v1-master/common)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/WiringPi-master/wiringPi)

#LINK_LIBRARIES("/usr/local/bin/libwiringPi.so.2.70")
#link_libraries(${PROJECT_SOURCE_DIR}/lib/)
#link_libraries("/usr/local/bin/libwringPi.so")

set(PROJECT_SOURCES
        main.cpp
        myserial.cpp
        mainwindow.cpp
        mainwindow.h
        myserial.h
        mainwindow.ui
        dialog.cpp
        dialog.h
        dialog.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtMavlinkDemo
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(QtMavlinkDemo SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(QtMavlinkDemo
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QtMavlinkDemo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${PROJECT_SOURCE_DIR}/lib/libwiringPi.so)

find_package(Qt5 REQUIRED COMPONENTS Charts)
target_link_libraries(QtMavlinkDemo PRIVATE Qt5::Charts)


