# Lista plików źródłowych – tylko logika, bez main.cpp
set(APP_SOURCES
        model/snail.cpp
        model/base/Organism.cpp
        simulation/input/SimulationContext.cpp
        simulation/SimulationManager.cpp
        model/Plant.cpp
        model/Aquarium.cpp
        serivce/AquariumService.cpp
)

# Lista plików nagłówkowych
set(APP_HEADERS
        model/snail.h
        model/base/Organism.h
        simulation/input/SimulationContext.h
        simulation/SimulationManager.h
        model/Plant.h
        model/Aquarium.h
        serivce/AquariumService.h
        simulation/SimulationStatus.h
)

add_library(application STATIC
        ${APP_SOURCES}
        ${APP_HEADERS}
)

target_include_directories(application PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
