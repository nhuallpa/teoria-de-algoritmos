cmake_minimum_required(VERSION 3.15)
project(MaximaGanancia)
set(CMAKE_CXX_STANDARD 11)

include_directories(src)

set(SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_subdirectory("${PROJECT_SOURCE_DIR}/src/Utils")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/Producto")

add_executable(MaximaGanancia ${SOURCE} ${HEADERS})

target_link_libraries(MaximaGanancia Producto_lib)


add_subdirectory(tests)