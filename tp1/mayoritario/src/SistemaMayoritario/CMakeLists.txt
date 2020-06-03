set(SOURCE
        ${SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/SistemaMayoritario.cpp
        PARENT_SCOPE
        )
set(HEADERS
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/SistemaMayoritario.h
        PARENT_SCOPE
        )

add_library(SistemaMayoritario_lib STATIC ${SOURCE} ${HEADER})
