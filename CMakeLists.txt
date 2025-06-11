cmake_minimum_required(VERSION 3.19)
project(Section-6 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Sql)

qt_standard_project_setup()

qt_add_executable(Section-6
    main.cpp
    database.h
    database.cpp
)

target_link_libraries(Section-6
    PRIVATE
        Qt::Core
        Qt::Sql
)

include(GNUInstallDirs)

install(TARGETS Section-6
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Section-6
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
