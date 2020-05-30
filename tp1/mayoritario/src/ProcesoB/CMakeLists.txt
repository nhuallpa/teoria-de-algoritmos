set(SOURCE
        ${SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/AlgoritmoB.cpp
        PARENT_SCOPE
        )
set(HEADERS
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/AlgoritmoB.h
        PARENT_SCOPE
        )

add_library(ProcesoB_lib STATIC ${SOURCE} ${HEADER})
