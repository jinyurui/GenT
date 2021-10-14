CMake
===================================

Some keys
------------------------------------
.. code::

    CMAKE_MINIMUM_REQUIRED   << cmake version set

    PROJECT                  << app create, this will create var_BINARY_DIR and var_SOURCE_DIR
                            
    CMAKE_SOURCE_DIR         << top CMakeLists [readonly]
    PROJECT_SOURCE_DIR       << recent project cmd ref, this is diff CMAKE_SOURCE_DIR [readonly]
    PROJECT_BINARY_DIR       << run cmake path, eg ./build/

    CMAKE_CURRENT_SOURCE_DIR << recent cmakelists path, action by add_subdirectory
    CMAKE_CURRENT_BINARY_DIR << recent cmakelists binary path, action by add_subdirectory

    EXECUTABLE_OUTPUT_PATH   << exe path [read & write]
    LIBRARY_OUTPUT_PATH      << lib path [read & write]

    CMAKE_C_FLAGS            << set c build opts
    CMAKE_CXX_FLAGS          << set c++ build opts

    ADD_SUBDIRECTORY         << add sub dir

    INCLUDE_DIRECTORIES      << add include

    ADD_EXECUTABLE           << create exe

    ADD_LIBRARY              << create lib

    LINK_DIRECTORIES         << bad, If a library search path must be provided, 
       prefer to localize the effect where possible by using the target_link_directories() command 
       rather than link_directories(). 
       The target-specific command can also control how the search directories propagate to other 
       dependent targets.

    TARGET_LINK_LIBRARIES    << exe link lib

    MESSAGE                  << debug help

Demo
-----------------------

Project hello
***********************
There is a hello project, a static library will be created and used.

.. code::

    --- hello/
    |-- CMakeLists.txt         << root cmake
    |-- main.cpp
    |-- other/
    |------ CMakeLists.txt     << static lib cmake
    |------ include/
    |---------- a.h
    |------ src/
    |---------- a.cpp
    |-- build/                 << auto create
    |------ bin/
    |------ lib/

root cmake
***************
.. code::

    # cmake version
    cmake_minimum_required (VERSION 3.8)

    # hello.exe
    project (hello VERSION 0.1.0 DESCRIPTION "hello")

    # set exe path
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin/)

    # include lib header
    include_directories(${CMAKE_SOURCE_DIR}/other/include/)

    # link lib dir
    link_directories(${CMAKE_SOURCE_DIR}/build/lib/)

    # exe
    add_executable(hello main.cpp)

    # add sub dir, a will be create, then can be linked
    add_subdirectory(other)

    # link lib 
    target_link_libraries(hello a)



static lib cmake
*********************
.. code::

    # set lib src
    set(libSrc ${CMAKE_CURRENT_SOURCE_DIR}/src/a.cpp)

    # create lib
    add_library(a_static STATIC ${libSrc})

    # set lib out name
    set_target_properties(a_static PROPERTIES OUTPUT_NAME "a")

    # set lib out path
    set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib/)
