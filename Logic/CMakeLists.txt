#Add submodules
add_subdirectory(operations)

#Create library
add_library(Logic ChainedOperator.cpp ChainedOperator.h Image.cpp Image.h ImageFormat.cpp ImageFormat.h)

#Link submodules
target_link_libraries(Logic operations)
target_include_directories(Logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})