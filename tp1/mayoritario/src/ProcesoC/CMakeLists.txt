set(SOURCE
        ${SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/AlgoritmoC.cpp
        PARENT_SCOPE
        )
set(HEADERS
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/AlgoritmoC.h
        PARENT_SCOPE
        )

add_library(ProcesoC_lib STATIC ${SOURCE} ${HEADER})
