# ${CMAKE_CURRENT_LIST_DIR} allows to include this files anywhere in the project
# For instance it is included in unit tests to simplify linking

set(simple_psh_SOURCES
        main/cpp/main.cpp
        main/cpp/noopinterpreter.cpp
        main/cpp/simplepsh.cpp
        main/headers/noopinterpreter.hpp
        main/headers/simplepsh.hpp
        )

add_executable(simple_psh ${simple_psh_SOURCES})
include_directories(main/headers main/public)
target_link_libraries(simple_psh psh)