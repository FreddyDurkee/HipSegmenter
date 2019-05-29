set(OpenCV_DIR "C:/opencv/build")
find_package( OpenCV REQUIRED )

#Add submodules
add_subdirectory(operations)

#Create library
add_library(Logic Image.cpp Image.h ImageFormat.cpp ImageFormat.h Parameter.cpp Parameter.h
        OperationConfig.cpp OperationConfig.h Operation.cpp Operation.h Validators.h OperationType.h)

#Link submodules
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Logic operations ${OpenCV_LIBS})
target_include_directories(Logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})