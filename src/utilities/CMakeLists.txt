# *****************************************************************************
# Building utilities library
# *****************************************************************************

set(UTILITIES_SOURCES
        main/cpp/Element.cpp
        main/cpp/Cache.cpp
        main/cpp/OrderedCache.cpp
        main/public/List.hpp
        main/public/Cache.hpp
        main/public/Element.hpp
        main/public/Iterator.hpp
        main/public/OrderedCache.hpp
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
        test/CacheTest.cpp
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