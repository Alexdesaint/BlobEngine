add_library(glad glad.c)
set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)
if (UNIX)
    target_link_libraries(glad ${CMAKE_DL_LIBS})
endif ()