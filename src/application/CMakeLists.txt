set(APP_SOURCES
        model/snail.cpp
    # plant.cpp
)

set(APP_HEADERS
        model/base/Organism.cpp
        model/base/Organism.h
        model/Snail.cpp
        model/Snail.h
        simulation/input/SimulationContext.cpp
        simulation/input/SimulationContext.h
        simulation/output/IterationResult.cpp
        simulation/output/IterationResult.h
        simulation/SimulationManager.cpp
        simulation/SimulationManager.h
        model/Plant.cpp
        model/Plant.h
        model/Plant.h
        model/Aquarium.cpp
        model/Aquarium.h
        serivce/AquariumService.cpp
        serivce/AquariumService.h
        # plant.h
)

add_library(application STATIC
    ${APP_SOURCES}
    ${APP_HEADERS}
)

target_include_directories(application PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
