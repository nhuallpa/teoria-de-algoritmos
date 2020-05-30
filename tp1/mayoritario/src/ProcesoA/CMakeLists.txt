set(SOURCE
        ${SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/AlgoritmoA.cpp
        PARENT_SCOPE
        )
set(HEADERS
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/AlgoritmoA.h
        PARENT_SCOPE
        )

add_library(ProcesoA_lib STATIC ${SOURCE} ${HEADER})
