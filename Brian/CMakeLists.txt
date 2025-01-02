cmake_minimum_required(VERSION 3.16)

project(Brian VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

# Buscar automáticamente los archivos fuente .cpp y .h
file(GLOB_RECURSE CPP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

# Buscar automáticamente archivos QML con rutas relativas
file(GLOB_RECURSE QML_SOURCES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/qml/*.qml"
)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appBrian
    main.cpp
)

qt_add_qml_module(appBrian
    URI Brian
    VERSION 1.0
    SOURCES
        ${CPP_SOURCES}
        ${HEADER_SOURCES}
    QML_FILES
        ${QML_SOURCES}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appBrian PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appBrian
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appBrian
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appBrian
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
