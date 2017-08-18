cmake_minimum_required(VERSION 3.3)
project(ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -g")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES src/Flow.cpp src/Flow.h src/Driver.cpp src/Driver.h
        src/Trip.cpp src/Trip.h src/Passenger.cpp src/Passenger.h
        src/TaxiCenter.cpp src/TaxiCenter.h src/LuxTaxi.cpp src/LuxTaxi.h
        src/Map.cpp src/Map.h src/Bfs.cpp src/Bfs.h src/Taxi.cpp src/Taxi.h
        src/Parser.cpp src/Parser.h src/AvaliableNotifier.h
        src/AvaliableListener.h src/TripListener.h src/TripListener.cpp)


set(TEST_FILES tests/main.cpp tests/TaxiTest.cpp tests/DriverTest.cpp
        tests/TripTest.cpp tests/LuxTaxiTest.cpp
        tests/TaxiCenterTest.cpp tests/BfsTest.cpp tests/BfsTest.h
        tests/MapTest.cpp tests/FlowTest.cpp tests/PassengerTest.cpp
        tests/PointTest.cpp tests/TripListenerTest.cpp tests/ParserTest.cpp)

add_executable(ex3 ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(ex3 gtest gtest_main pthread)
add_test(ex3 ex3)
