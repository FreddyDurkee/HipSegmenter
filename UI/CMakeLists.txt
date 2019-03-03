#Find Packages
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Widgets REQUIRED )

add_library(UI MainWindow.cpp)

#Link Libraries
target_link_libraries(UI Qt5::Widgets)
target_link_libraries(UI Qt5::Core)
target_link_libraries(UI Qt5::Gui)


target_include_directories(UI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

