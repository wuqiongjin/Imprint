# core/CMakeLists.txt
add_library(core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/word_entry.cpp
)

target_include_directories(core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# deps
target_link_libraries(core
    PUBLIC
        utils
)