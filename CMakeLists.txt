cmake_minimum_required(VERSION 3.15)

project(ViteKnight VERSION 0.0.0)

add_subdirectory(Role)

SET(SRC_LIST main.cpp)
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} PUBLIC Role)

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${PROJECT_SOURCE_DIR}/Role
                           )



