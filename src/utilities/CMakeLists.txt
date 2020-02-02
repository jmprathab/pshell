# *****************************************************************************
# Building utilities library
# *****************************************************************************

set(UTILITIES_SOURCES
        main/cpp/List.cpp
        main/cpp/ListImpl.cpp
        main/cpp/String.cpp
        main/headers/ListImpl.hpp
        main/public/List.hpp
        main/public/String.hpp
        )

add_library(utilities
        SHARED
        ${UTILITIES_SOURCES}
        )

include_directories(
        main/headers
        main/public
)

# *****************************************************************************
# Building utilities library test
# *****************************************************************************

set(UTILITIES_TEST_SOURCES
        test/main.cpp
        )

add_executable(utilities_test
        ${UTILITIES_TEST_SOURCES}
        )

target_link_libraries(utilities_test
        utilities
        )
