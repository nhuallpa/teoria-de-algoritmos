set(SOURCE_FILES
        Producto.cpp
        )
set(HEADER_FILES
        Producto.h
        )

add_library(Producto_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

