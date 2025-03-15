set(APP_SOURCES
    snail.cpp
    # plant.cpp
)

set(APP_HEADERS
    snail.h
    # plant.h
)

add_library(application STATIC
    ${APP_SOURCES}
    ${APP_HEADERS}
)

target_include_directories(application PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
