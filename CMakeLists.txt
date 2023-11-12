cmake_minimum_required(VERSION 3.14)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PATHS include/)
set(NAME_EXECUTABLE "TicTacToe")
set(NAME_TEST "TicTacToeTest")

project(${NAME_EXECUTABLE})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${NAME_EXECUTABLE} ./src/main.cpp)
add_library(controller ./src/board_console_controller.cpp)
add_library(model ./src/board_model.cpp)
add_library(view ./src/board_console_viewer.cpp)
add_executable(${NAME_TEST} ./test/test.cpp)

target_include_directories(controller
    PRIVATE "${PATHS}"
)
target_include_directories(model
    PRIVATE "${PATHS}"
)
target_include_directories(view
    PRIVATE "${PATHS}"
)
target_include_directories(${NAME_EXECUTABLE}
    PRIVATE "${PATHS}"
)

target_link_libraries(${NAME_EXECUTABLE} PRIVATE
    controller model view
)

target_include_directories(${NAME_TEST}
    PRIVATE "${PATHS}"
)

target_link_libraries(${NAME_TEST} 
    model
)

target_link_libraries(
  ${NAME_TEST}
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${NAME_TEST})

