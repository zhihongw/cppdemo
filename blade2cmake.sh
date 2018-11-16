cmake_minimum_required(VERSION 3.7)
project(mycxx)
MESSAGE("${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 11)

#遍历所有的源文件
file(GLOB_RECURSE ALL_SOURCES "**/*.cpp")
message("${ALL_SOURCES}")

#遍历所有的头文件
file(GLOB_RECURSE ALL_HEADERS "**/*.h" "**/*.hpp")
message("${ALL_HEADERS}")
#把源文件的绝对路径，转成相当于BLADE根路径的相对路径
string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" SOURCES_LIST "${ALL_SOURCES}")
#把头文件的绝对路径，转成相当于BLADE根路径的相对路径
string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" HEADERS_LIST "${ALL_HEADERS}")

#遍历每个头文件，塞到include搜索目录里面
FOREACH(HEADER ${ALL_HEADERS})
    #截断文件名
    get_filename_component(DIR ${HEADER} DIRECTORY)
    #去掉BLADE根路径
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" HEADER_DIR "${DIR}")
    #去掉第三方库的前方路径
    string(REGEX MATCH "^[cpp3rdlib|cppcomponent][0-9_a-zA-Z\\/]+include" HEADER_DIR_2 "${HEADER_DIR}")
    #如果正则匹配上了
    if ("${HEADER_DIR_2}" STRGREATER "")
        INCLUDE_DIRECTORIES("${HEADER_DIR_2}")
    else()
        INCLUDE_DIRECTORIES("${HEADER_DIR}")
    endif()
ENDFOREACH()
include_directories(.)
add_executable(mycxx "${SOURCES_LIST}" "${HEADERS_LIST}")
