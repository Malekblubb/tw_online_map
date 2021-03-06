 project(twom)
cmake_minimum_required(VERSION 2.8)

# collect files
file(GLOB_RECURSE SRC_LIST "./include/*" "./src/*")
include_directories("./include" "./external/mlk/include" "./external/twl/include")

add_executable(${PROJECT_NAME} ${SRC_LIST})

# set compiler flags
set(CMAKE_CXX_FLAGS "-std=c++1y -O3")
set(CMAKE_CXX_COMPILER "clang++")


# link
# zlib
find_package(ZLIB REQUIRED)
if(ZLIB_FOUND)
    include_directories(${ZLIB_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${ZLIB_LIBRARIES})
endif()

# sfml
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

# wt
target_link_libraries(${PROJECT_NAME} wthttp wt)

# pnglite
target_link_libraries(${PROJECT_NAME} pnglite)

# qt
FIND_PACKAGE(Qt4 REQUIRED)
if(Qt4_FOUND)
    include_directories(${QT_INCLUDE_DIR})
    include(${QT_USE_FILE})
    add_definitions(${QT_DEFINITIONS})
    target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
endif()

