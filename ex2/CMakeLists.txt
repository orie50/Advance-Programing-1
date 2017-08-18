cmake_minimum_required(VERSION 3.3)
project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -g")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES src/main.cpp src/Flow.cpp src/Flow.h src/Sprite.h
        src/SpriteCollection.cpp src/SpriteCollection.h src/Driver.cpp src/Driver.h
        src/DriverInfo.cpp src/DriverInfo.h src/Trip.cpp src/Trip.h
        src/Passenger.cpp src/Passenger.h src/TaxiCenter.cpp src/TaxiCenter.h
        src/LuxTaxi.cpp src/LuxTaxi.h src/Map.cpp src/Map.h src/Bfs.cpp src/Bfs.h src/Taxi.cpp src/Taxi.h)


set(TEST_FILES tests/TaxiTest.cpp tests/DriverTest.cpp tests/TripTest.cpp tests/LuxTaxiTest.cpp
        tests/DriverInfoTest.cpp tests/TaxiCenterTest.cpp tests/SpriteCollectionTest.cpp
        tests/BfsTest.cpp tests/BfsTest.h tests/MapTest.cpp
        tests/FlowTest.cpp tests/PassengerTest.cpp tests/PointTest.cpp)

add_executable(ex2 ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(ex2 gtest gtest_main pthread)
add_test(ex2 ex2)
