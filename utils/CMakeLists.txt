# utils/CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

add_library(utils
    src/common.cpp
    src/logger.cpp
)

# 设置包含目录
target_include_directories(utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接所需的系统库
target_link_libraries(utils PUBLIC
    stdc++fs
    SQLiteCpp
    sqlite3
)

# 设置 C++ 标准
target_compile_features(utils PUBLIC cxx_std_17)

# 如果在Windows上需要链接额外的库
if(WIN32)
    target_link_libraries(utils PUBLIC shell32)
endif()