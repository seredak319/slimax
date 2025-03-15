cmake_minimum_required(VERSION 3.19)
project(slimaks LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

add_subdirectory(src/application)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

set(HEADERS
    src/mainwindow.h
)

qt_wrap_ui(UI_HEADERS view/mainwindow.ui)

qt_standard_project_setup()

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
    src/application/snail.h src/application/snail.cpp
)

target_link_libraries(slimaks
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        application
)

include(GNUInstallDirs)

install(TARGETS slimaks
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET slimaks
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
