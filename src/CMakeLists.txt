file(GLOB SRC_FILES *.cpp)
add_library(corelink_cpp ${SRC_FILES})
target_include_directories(corelink_cpp PUBLIC ${CMAKE_SOURCE_DIR}/include)

