message("Blob Test are enable")

add_executable(TestAsset TestAsset.cpp)
target_link_libraries(TestAsset Blob::Includes)

add_executable(TestImGUI TestImGUI.cpp)
target_link_libraries(TestImGUI Blob)

add_executable(TestSDL TestSDL.cpp)
target_link_libraries(TestSDL SDL2::SDL2main SDL2::SDL2-static)

add_executable(TestWindowCore TestWindowCore.cpp)
target_link_libraries(TestWindowCore Blob)

add_executable(TestColor TestColor.cpp)
target_link_libraries(TestColor Blob)

add_executable(TestShapes TestShapes.cpp)
target_link_libraries(TestShapes Blob)

add_executable(TestShaders TestShaders.cpp)
target_link_libraries(TestShaders Blob)

add_subdirectory(BlenderExporter)
add_subdirectory(GL)
add_subdirectory(VK)
add_subdirectory(Maths)
add_subdirectory(Collision)
