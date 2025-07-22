cmake_minimum_required(VERSION 3.16)

project(QTBUG-137932 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appQTBUG-137932
    main.cpp
)

qt_add_qml_module(appQTBUG-137932
    URI QTBUG-137932
    VERSION 1.0
    QML_FILES main.qml
    QML_FILES ComboBox.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQTBUG-137932 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQTBUG-137932
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQTBUG-137932
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appQTBUG-137932
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
