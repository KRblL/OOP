cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME game)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Curses REQUIRED)

set(PLAYER Player/Player.cpp)
set(CONTROLLER Controller/Controller.cpp Controller/Direction.cpp)
set(FIELD Field/Cell.cpp Field/Field.cpp Field/FieldCreator.cpp)
set(EVENT Event/IEvent.cpp Event/DamageEvent.cpp Event/HealEvent.cpp Event/ScoreEvent.cpp Event/TeleportEvent.cpp)
set(GAMEMANAGER GameManager/GameManager.cpp)
set(CONFIGREADER Input/ConfigReader.cpp)
set(COMMANDREADER Input/ICommandReader.cpp Input/CommandReader.cpp)
set(VIEW View/ViewState.cpp View/IView.cpp View/IObservable.cpp View/IObserver.cpp View/GameObserver.cpp View/ConsoleView.cpp)
set(LOGGING Logging/ILogger.cpp Logging/ConsoleLogger.cpp Logging/FileLogger.cpp Logging/IMessage.cpp Logging/MessageCommandKey.cpp Logging/MessageLose.cpp Logging/MessageNewGame.cpp Logging/MessageUnknownKey.cpp Logging/MessageWin.cpp) 

add_executable(${PROJECT_NAME} main.cpp ${PLAYER} ${CONTROLLER} ${FIELD} ${EVENT} ${GAMEMANAGER} ${CONFIGREADER} ${COMMANDREADER} ${VIEW} ${LOGGING})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})