#Find Packages
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Widgets REQUIRED )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(RESOURCE_FILES resource.qrc)

#Combine everything
add_library(UI main.cpp MainWindow.cpp MainWindow.h toolbox/OperationsToolWidget.cpp toolbox/OperationsToolWidget.h toolbox/OperationNameWidget.cpp toolbox/OperationNameWidget.h execution/OperationsListWidget.cpp execution/OperationsListWidget.h execution/BlockListStyle.cpp execution/BlockListStyle.h execution/blocks/BlockWidget.cpp execution/blocks/BlockWidget.h execution/blocks/SettingsDialog.cpp execution/blocks/SettingsDialog.h ${RESOURCE_FILES} ../Logic/OperationFactory.h execution/blocks/settings/FileGetterWidget.cpp execution/blocks/settings/FileGetterWidget.h execution/blocks/settings/ParameterChanger.h execution/blocks/BlockWidget.h
        execution/blocks/BlockWidget.cpp ../Logic/OperationFactory.h)

#Link Libraries
target_link_libraries(UI Qt5::Widgets)
target_link_libraries(UI Qt5::Core)
target_link_libraries(UI Qt5::Gui)


include_directories(../Logic)

target_include_directories(UI PUBLIC execution "${CMAKE_CURRENT_BINARY_DIR}/UI_autogen/include")
target_include_directories(UI PUBLIC toolbox "${CMAKE_CURRENT_BINARY_DIR}/UI_autogen/include")
target_include_directories(UI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_BINARY_DIR}/UI_autogen/include")


