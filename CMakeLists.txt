cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

project(BinaryFileComparer LANGUAGES CXX)

# Set the CMAKE_INSTALL_PREFIX to /usr if not specified
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "/usr" CACHE PATH "The default install prefix" FORCE)
endif()

# Set the CMAKE_INSTALL_BINDIR to /bin if not specified
if(NOT DEFINED CMAKE_INSTALL_BINDIR)
  set(CMAKE_INSTALL_BINDIR "bin" CACHE PATH "user executables (bin)")
endif()

# Set the CMAKE_INSTALL_DATAROOTDIR to /share if not specified
if(NOT DEFINED CMAKE_INSTALL_DATAROOTDIR)
  set(CMAKE_INSTALL_DATAROOTDIR "share" CACHE PATH "read-only architecture-independent data root (share)")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt5Widgets REQUIRED)

add_executable(${PROJECT_NAME}
main.cpp
mainwindow.cpp
qhexedit.cpp
commands.cpp
color_manager.cpp
dialogcompare.cpp
chunks.cpp
mainwindow.h
qhexedit.h
commands.h
color_manager.h
dialogcompare.h
chunks.h
mainwindow.ui
dialogcompare.ui
res.qrc
	)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/img/compare64.png" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/pixmaps")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/other/FileComparator.desktop" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/applications")
