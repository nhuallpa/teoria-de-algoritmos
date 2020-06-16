set(SOURCE
        ${SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/SistemaProductos.cpp
        PARENT_SCOPE
        )
set(HEADERS
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/SistemaProductos.h
        PARENT_SCOPE
        )

add_library(SistemaProductos_lib STATIC ${SOURCE} ${HEADER})
