add_subdirectory(parameters)

add_library(operations ../Operation.h ../Operation.cpp LoadImageBlock.cpp LoadImageBlock.h ../Parameter.cpp ../Parameter.h ../OperationConfig.cpp ../OperationConfig.h parameters/StringParameter.cpp parameters/StringParameter.h)

target_link_libraries(operations parameters)