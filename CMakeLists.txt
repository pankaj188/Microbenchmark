cmake_minimum_required(VERSION 3.27.6)

project(Microbenchmark)
# Set the C++ standard to C++11 or higher
set(CMAKE_CXX_STANDARD 11)
find_package(benchmark REQUIRED)
add_subdirectory(benchmark)
target_link_libraries(benchmarks.cpp benchmark::benchmark)
# Add your source files here
set(SOURCE_FILES
    main.cpp
    OrderBook.cpp
    OrderBook.h
    MarketDataGenerator.cpp
    MarketDataGenerator.h
    OrderMatchingAlgorithm.cpp
    OrderMatchingAlgorithm.h
)

# Add an executable target for your project
add_executable(benchmark ${SOURCE_FILES})

# Optionally, enable testing for  project
enable_testing()
add_subdirectory(benchmarks.cpp)
