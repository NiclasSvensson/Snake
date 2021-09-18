cmake_minimum_required(VERSION 3.16)

project(Snake VERSION 1.0.0.0)

# Windows specific config
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
    # Link sfml statically
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

# Find SFML shared libraries
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

FILE(
  GLOB
  SOURCES
  "src/main.cpp"
  "src/board.cpp"
  "src/snake.cpp"
  "src/resource.cpp"
)

# Compile executable
add_executable(app ${SOURCES})

# Link executable to required SFML modules
target_link_libraries(app sfml-graphics sfml-window sfml-system)
