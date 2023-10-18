cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME game)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PLAYER Player/Player.cpp)
set(CONTROLLER Controller/Controller.cpp)
set(FIELD Field/Cell.cpp Field/Field.cpp)
set(EVENT Event/IEvent.cpp Event/HealthEvent.cpp)

add_executable(${PROJECT_NAME} main.cpp    ${PLAYER} ${CONTROLLER} ${FIELD} ${EVENT})