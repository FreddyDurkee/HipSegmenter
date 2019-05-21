add_subdirectory(parameters)

add_library(operations Operation.h Operation.cpp LoadImageBlock.cpp LoadImageBlock.h parameters/Parameter.cpp parameters/Parameter.h BlockConfig.cpp BlockConfig.h parameters/StringParameter.cpp parameters/StringParameter.h)

target_link_libraries(operations parameters)