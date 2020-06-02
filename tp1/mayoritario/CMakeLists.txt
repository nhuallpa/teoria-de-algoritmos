cmake_minimum_required(VERSION 3.15)
project(mayoritario)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)


set(SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_subdirectory("${PROJECT_SOURCE_DIR}/src/Lista")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/ProcesoA")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/ProcesoB")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/ProcesoC")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/Utils")

add_executable(mayoritario ${SOURCE} ${HEADERS})

target_link_libraries(mayoritario ProcesoA_lib ProcesoB_lib ProcesoC_lib)

#add_subdirectory("${PROJECT_SOURCE_DIR}/tests")
