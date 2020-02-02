# ${CMAKE_CURRENT_LIST_DIR} allows to include this files anywhere in the project
# For instance it is included in unit tests to simplify linking

set(psh_SOURCES
        main/cpp/command.cpp
        main/cpp/interpreter.cpp
        main/cpp/psh.cpp
        main/public/command.hpp
        main/public/interpreter.hpp
        main/public/psh.hpp
        )

add_library(psh SHARED ${psh_SOURCES})
include_directories(main/headers main/public)