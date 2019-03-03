cmake_minimum_required(VERSION 3.9.1)
project(HipSegmenter)

#Set-ups
#set(CMAKE_PREFIX_PATH "C:/Qt/5.9.1/mingw53_32")
set(CMAKE_PREFIX_PATH "C:/Qt/5.9.1/msvc2017_64")

#Static config
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#Find Packages - for auto deploy
find_package( Qt5Core REQUIRED )

#Create Executable
add_executable(${PROJECT_NAME} main.cpp)

#Add Subdirectories
include_directories( ${MY_SOURCE_DIR}/UI )

add_subdirectory(UI)

#Specify that HipSegmenter needs to be linked against one or more libraries
target_link_libraries(${PROJECT_NAME} UI)

#Deploy Application
get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
        env PATH="${_qt_bin_dir}" "${WINDEPLOYQT_EXECUTABLE}"
        --verbose 0
        --no-compiler-runtime
        \"$<TARGET_FILE:${PROJECT_NAME}>\"
        COMMENT "Deploying Qt Libraries..."
        )