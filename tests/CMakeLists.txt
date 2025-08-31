# test/CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

# 添加测试可执行文件
add_executable(logger_test logger_test.cpp)

# 链接 依赖的库
target_link_libraries(logger_test PRIVATE utils)

# 设置包含目录
target_include_directories(logger_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/utils/include
)