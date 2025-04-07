# Find all test files
file(GLOB_RECURSE TEST_SOURCES "*.cc")

# Create test executables
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    # Only build if BUILD_ALL is ON or if this is the specified target
    if(BUILD_ALL OR "${TEST_NAME}" STREQUAL "${BUILD_TARGET}")
        add_executable(${TEST_NAME} ${TEST_SOURCE})
        target_include_directories(${TEST_NAME} PRIVATE
            ${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include
            ${CMAKE_SOURCE_DIR}/third_party/googletest/googlemock/include
        )
        target_link_libraries(${TEST_NAME} GTest::gtest_main)
    endif()
endforeach()
