#Add submodules
add_subdirectory(operations)

#Create library
add_library(Logic Image.cpp Image.h ImageFormat.cpp ImageFormat.h Parameter.cpp Parameter.h
        OperationConfig.cpp OperationConfig.h Operation.cpp Operation.h Validators.h OperationType.h)

#Link submodules
target_link_libraries(Logic operations)
target_include_directories(Logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})