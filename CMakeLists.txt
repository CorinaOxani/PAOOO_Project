# Versiunea minimă a CMake
cmake_minimum_required(VERSION 3.0)

# Numele proiectului
project(ParkingManager)

# Specifică standardul C++ necesar
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directorul cu header-ele
include_directories(include)

# Definirea executabilului
add_executable(${PROJECT_NAME} src/main.cpp src/ParkingSpot.cpp)
