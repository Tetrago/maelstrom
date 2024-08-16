cmake_minimum_required(VERSION 3.20)
project(maelstrom LANGUAGES CXX)

add_library(
	${PROJECT_NAME} INTERFACE "include/maelstrom/maelstrom.hpp"
	"include/maelstrom/base.hpp" "include/maelstrom/matrix.hpp"
	"include/maelstrom/vector.hpp"
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

target_include_directories(${PROJECT_NAME} INTERFACE "include")

option(MAELSTROM_BUILD_TESTS "Build unit tests" ON)
if(MAELSTROM_BUILD_TESTS)
	include(FetchContent)
	FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
	)

	if(WIN32)
		set(gtest_force_shared_crt
			ON
			CACHE BOOL "" FORCE
		)
	endif()

	FetchContent_MakeAvailable(googletest)

	enable_testing()

	add_executable(
		${PROJECT_NAME}_test "tests/matrix.cpp" "tests/meta.cpp"
							 "tests/vector.cpp"
	)

	target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_14)

	target_link_libraries(
		${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME} GTest::gtest_main
	)

	include(GoogleTest)
	gtest_discover_tests(${PROJECT_NAME}_test)
endif()
