add_library(Logic ChainedOperator.cpp ChainedOperator.h Image.cpp Image.h ImageFormat.cpp ImageFormat.h)

target_include_directories(Logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})