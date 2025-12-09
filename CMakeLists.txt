cmake_minimum_required(VERSION 3.16)

project(Timirbaev_Erik_AS-22-04_Lab_4 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        timirbaevmainwindow.cpp
        timirbaevmainwindow.h
        timirbaevmainwindow.ui
)

# boost
set(Boost_ROOT "C:/Users/User/Downloads/boost_1_86_0")
set(Boost_NO_WARN_NEW_VERSIONS 1)
find_package(Boost 1.86.0 REQUIRED COMPONENTS serialization)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_libraries(${Boost_LIBRARIES})
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Timirbaev_Erik_AS-22-04_Lab_4
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        timirbaevcourier.h timirbaevcourier.cpp
        timirbaevpark.h timirbaevpark.cpp
        timirbaevautocourier.h timirbaevautocourier.cpp
        timirbaevtable.h timirbaevtable.cpp
        timirbaevutilities.h
        timirbaevdialog.h timirbaevdialog.cpp timirbaevdialog.ui
        timirbaevadddialog.h timirbaevadddialog.cpp timirbaevadddialog.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Timirbaev_Erik_AS-22-04_Lab_4 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Timirbaev_Erik_AS-22-04_Lab_4 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Timirbaev_Erik_AS-22-04_Lab_4
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Timirbaev_Erik_AS-22-04_Lab_4 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Timirbaev_Erik_AS-22-04_Lab_4)
endif()
set_target_properties(Timirbaev_Erik_AS-22-04_Lab_4 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Timirbaev_Erik_AS-22-04_Lab_4
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Timirbaev_Erik_AS-22-04_Lab_4)
endif()

# Doxygen документация
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs/html)
    set(DOXYGEN_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    
    configure_file(Doxyfile.in Doxyfile @ONLY)
    
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()
