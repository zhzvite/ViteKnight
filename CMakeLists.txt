cmake_minimum_required(VERSION 3.15)

project(Tutorial VERSION 0.0.0)

add_subdirectory(MathFunctions)

SET(SRC_LIST tutorial.cpp)
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} PUBLIC MathFunctions)

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${PROJECT_SOURCE_DIR}/MathFunctions
                           )



