cmake_minimum_required(VERSION 3.10)

set(AppName "cpp_loigc")

project(${AppName} CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

aux_source_directory(${CMAKE_SOURCE_DIR} SRC_FILES)
message("SRC_FILES ${SRC_FILES}")

add_compile_options(-D_EXPORTING)

add_library(${AppName} SHARED ${SRC_FILES})

set_target_properties(${AppName} PROPERTIES CMAKE_POSITION_INDEPENDENT_CODE ON)

target_include_directories(${AppName} PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/../    
)

