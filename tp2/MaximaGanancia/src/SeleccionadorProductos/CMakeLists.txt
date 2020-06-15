set(SOURCE_FILES
        SeleccionadorProductos.cpp
        )
set(HEADER_FILES
        SeleccionadorProductos.h
        )

add_library(SeleccionadorProductos_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

