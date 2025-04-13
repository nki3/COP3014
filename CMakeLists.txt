cmake_minimum_required(VERSION 3.30)
project(COP3014)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(COP3014
    BudgetCalculator.cpp
    SimplePosSystem.cpp
    SpudMarket.cpp
    SpudBrary.cpp)
