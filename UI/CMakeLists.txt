#Find Packages
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Widgets REQUIRED )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(RESOURCE_FILES resource.qrc)


#Combine everything
add_library(UI MainWindow.cpp MainWindow.h OperationBlockWidget.cpp OperationBlockWidget.h OperationsToolBox.cpp OperationsToolBox.h OperationBlockLabel.cpp OperationBlockLabel.h OperationsListWidget.cpp OperationsListWidget.h BlockListStyle.cpp BlockListStyle.h OperationBlockWidget.cpp OperationBlockWidget.h SettingsDialog.cpp SettingsDialog.h ${RESOURCE_FILES})

#Link Libraries
target_link_libraries(UI Qt5::Widgets)
target_link_libraries(UI Qt5::Core)
target_link_libraries(UI Qt5::Gui)

include_directories(../Logic)


target_include_directories(UI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_BINARY_DIR}/UI_autogen/include")


