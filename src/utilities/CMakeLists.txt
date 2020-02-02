# *****************************************************************************
# Building utilities library
# *****************************************************************************

set(UTILITIES_SOURCES
        main/public/List.hpp
        )

add_library(utilities
        SHARED
        ${UTILITIES_SOURCES}
        )

include_directories(
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        main/headers
        main/public
)

SET_TARGET_PROPERTIES(utilities PROPERTIES LINKER_LANGUAGE CXX)

# *****************************************************************************
# Building utilities library test
# *****************************************************************************

set(UTILITIES_TEST_SOURCES
        test/ListTest.cpp
        )

add_executable(utilities_test
        ${UTILITIES_TEST_SOURCES}
        )

target_link_libraries(utilities_test
        gtest
        gtest_main
        utilities
        )

SET_TARGET_PROPERTIES(utilities_test PROPERTIES LINKER_LANGUAGE CXX)