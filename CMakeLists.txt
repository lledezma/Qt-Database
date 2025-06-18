cmake_minimum_required(VERSION 3.19)
project(Qt-Database LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Sql)

qt_standard_project_setup()

qt_add_executable(Qt-Database
    main.cpp
    database.h
    database.cpp
)

target_link_libraries(Qt-Database
    PRIVATE
        Qt::Core
        Qt::Sql
)

include(GNUInstallDirs)

install(TARGETS Qt-Database
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Qt-Database
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
