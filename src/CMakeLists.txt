add_subdirectory(GL)
add_subdirectory(VK)
add_subdirectory(collision)
add_subdirectory(geometrie)
add_subdirectory(glTF2)
add_subdirectory(Reader)

add_library(Time Time.cpp)
target_include_directories(Time PUBLIC ../include)