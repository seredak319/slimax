cmake_minimum_required(VERSION 3.19)
project(slimaks LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/src/view)

add_subdirectory(src/application)

set(SOURCES
        src/main.cpp
        src/controller/mainwindow.cpp
        src/view/mainwindow.ui
)

set(HEADERS
        src/controller/mainwindow.h
        src/view/model/PlantView.cpp
        src/view/model/PlantView.h
        src/view/model/AquariumView.cpp
        src/view/model/AquariumView.h
        src/view/model/SnailView.cpp
        src/view/model/SnailView.h
)

qt_standard_project_setup()

add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
        src/application/model/snail.h src/application/model/snail.cpp
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

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_1.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_2.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_3.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_4.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_5.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_6.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_7.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_8.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_9.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_10.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_11.png
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/plant/wild_plant_grow_12.png
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}/resources
)

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/snail/snail.png
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}/resources
)


file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/src/view/img/background/background.jpg
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}/resources
)
