cmake_minimum_required(VERSION 3.15)
project(BugCodeExamples)

set(CMAKE_CXX_STANDARD 14)

include(cmake/module_define.cmake)

include_directories(${CMAKE_CURRENT_LIST_DIR})

set(targets CWE
        highIntegrityC++CodingStandard
        misc
        SEI_CERT)
foreach(item ${targets})
    add_subdirectory(${item})
endforeach()