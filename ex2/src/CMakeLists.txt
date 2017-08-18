cmake_minimum_required(VERSION 3.6)
project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES main.cpp Flow.cpp Flow.h Sprite.h
        SpriteCollection.cpp SpriteCollection.h Driver.cpp Driver.h
        DriverInfo.cpp DriverInfo.h Trip.cpp Trip.h
        Passenger.cpp Passenger.h TaxiCenter.cpp TaxiCenter.h
        LuxTaxi.cpp LuxTaxi.h Map.cpp Map.h Bfs.cpp Bfs.h Taxi.cpp Taxi.h)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(TEST_FILES tests/TaxiTest.cpp tests/DriverTest.cpp tests/TripTest.cpp tests/LuxTaxiTest.cpp
        tests/DriverInfoTest.cpp tests/TaxiCenterTest.cpp tests/SpriteCollectionTest.cpp
        tests/BfsTest.cpp tests/BfsTest.h tests/MapTest.cpp
        tests/FlowTest.cpp tests/PassengerTest.cpp tests/PointTest.cpp)

add_executable(ex2 ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(ex2 gtest pthread)
