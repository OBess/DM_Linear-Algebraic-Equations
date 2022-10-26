cmake_minimum_required(VERSION 3.5)
project(DM_Linear-Algebraic-Equations VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# - Директорія для .exe - файлів
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/deploy)

add_subdirectory(tests)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES DM_Linear-Algebraic-Equations_uk_UA.ts)

set(PROJECT_SOURCES
        main.cpp
        linearalgebraicequations.cpp
        linearalgebraicequations.h
        linearalgebraicequations.ui
        uiseidelssetup.cpp
        uiseidelssetup.h
        uiseidelssetup.ui
        uisedelsresult.cpp
        uisedelsresult.h
        uisedelsresult.ui
        SeidelsMethod.h
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DM_Linear-Algebraic-Equations
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(DM_Linear-Algebraic-Equations SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(DM_Linear-Algebraic-Equations
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(DM_Linear-Algebraic-Equations PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(DM_Linear-Algebraic-Equations PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS DM_Linear-Algebraic-Equations
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DM_Linear-Algebraic-Equations)
endif()
