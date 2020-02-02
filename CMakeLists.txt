#Copyright (c) 2015, Iurii Krasnoshchok (cachelot [at] cachelot.io)
#All rights reserved.
#
#Redistribution and use in source and binary forms, with or without
#modification, are permitted provided that the following conditions are met:
#
#1. Redistributions of source code must retain the above copyright notice, this
#   list of conditions and the following disclaimer.
#2. Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution.
#
#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
#ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
#ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


###########################################################################
#       Cmake basic setup
###########################################################################
if (NOT CMAKE_GENERATOR STREQUAL "Unix Makefiles")
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebugInfo;MinSizeRel;AddressSanitizer" CACHE TYPE INTERNAL FORCE)
    mark_as_advanced(CMAKE_CONFIGURATION_TYPES)
else ()
    # Unix Makefiles support only single build configuration - release by default
    if (NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE RelWithDebugInfo CACHE TYPE INTERNAL FORCE)
    endif ()
endif ()

project(pshell)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

###########################################################################
#       Platform setup
###########################################################################
if (CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(PSHELL_PLATFORM_BITS 32)
    add_definitions("-DPSHELL_PLATFORM_BITS=32")
elseif (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PSHELL_PLATFORM_BITS 64)
    add_definitions("-DPSHELL_PLATFORM_BITS=64")
else ()
    message(FATAL_ERROR "CMake reports unsupported pointer size: \"${CMAKE_SIZEOF_VOID_P}\"")
endif ()
message(STATUS "Platform: ${CMAKE_SYSTEM_NAME} x${PSHELL_PLATFORM_BITS}")
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definition(-D_WIN32_WINNT=0x05010000) # set NTDDI_WINXP as a target win version
endif ()
string(REGEX MATCH "arm.*" ARM_CPU "${CMAKE_SYSTEM_PROCESSOR}")
string(REGEX MATCH "x86_64" x86_64_CPU "${CMAKE_SYSTEM_PROCESSOR}")

###########################################################################
#       Compiler setup
###########################################################################
#  TODO: Precompiled headers macro
message(STATUS "Compiler: " ${CMAKE_CXX_COMPILER_ID} " v" ${CMAKE_CXX_COMPILER_VERSION})
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    # - Visual Studio - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # warnings
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_SECURE_NO_WARNINGS)
    add_definitions("/wd4510 /wd4511 /wd4512") # default / copy constructor / assignment operator could NOT be generated
    add_definitions("/wd4996") # function call with parameters that may be unsafe
    add_definitions(-DWIN32_LEAN_AND_MEAN) # limit amount of code in Windows.h to the minimum
    add_definitions(-DNOMINMAX) # disable min / max macro from Windows.h
    set(CMAKE_C_FLAGS "/W4 /EHsc /Zi")
    set(CMAKE_C_FLAGS_RELEASE "/MD /Ot")
    set(CMAKE_C_FLAGS_DEBUG "/sdl /MDd /GS /Ob0 /Od /DEBUG /RTC1")
    set(DEBUG_LIBRARIES "Dbghelp.lib")
elseif ((${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU") OR (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"))
    # - GCC / Clang common - - - - - - - - - - - - - - - - - - - - - - - - - -
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -fstrict-overflow -fstrict-aliasing -Wshadow -Wstrict-aliasing -Wstrict-overflow=4")
    if (CMAKE_SYSTEM_PROCESSOR STREQUAL x86_64_CPU)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -msse2")
        if (PSHELL_PLATFORM_BITS EQUAL 64)
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -m64")
        endif ()
    endif ()
    set(CMAKE_C_FLAGS_DEBUG "-O0 -g -DDEBUG")
    set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
    set(CMAKE_C_FLAGS_RELWITHDEBUGINFO "-O2 -DNDEBUG -g")
    set(CMAKE_C_FLAGS_MINSIZEREL "-Os -DNDEBUG")
    set(CMAKE_C_FLAGS_ADDRESSSANITIZER "-fsanitize=address -O1 -g -DNDEBUG -DADDRESS_SANITIZER -fno-optimize-sibling-calls")

    set(DEBUG_LIBRARIES "")
    # - - Clang specific - - - - - - - - - - - - - - - - - - - - - - - -
    if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat -Wno-c++98-compat-pedantic")
        # set libc++ as a default std library (if available)
        if (NOT ${CMAKE_CXX_FLAGS} MATCHES "-stdlib=")
            include(CheckLibraryExists)
            check_library_exists(c++ throw "" HAVE_LIBCPLUSPLUS)
            if (HAVE_LIBCPLUSPLUS)
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
                set(CMAKE_EXE_LINKER_FLAGS "-stdlib=libc++ -lc++abi")
            endif ()
        endif ()
    endif ()
else ()
    message(FATAL_ERROR "unknown compiler")
endif ()
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
set(CMAKE_CXX_FLAGS_RELWITHDEBUGINFO ${CMAKE_C_FLAGS_RELWITHDEBUGINFO})
set(CMAKE_CXX_FLAGS_MINSIZEREL ${CMAKE_C_FLAGS_MINSIZEREL})
set(CMAKE_CXX_FLAGS_ADDRESSSANITIZER ${CMAKE_C_FLAGS_ADDRESSSANITIZER})

###########################################################################
#       CCache configuration
###########################################################################
find_program(CCACHE_FOUND ccache)
if (CCACHE_FOUND)
    message(STATUS "Enable ccache")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif (CCACHE_FOUND)

###########################################################################
#       Clone Google Test
###########################################################################
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/thirdpartylibs/googletest)
if (NOT EXISTS ${GOOGLETEST_DIR})
    find_package(Git REQUIRED)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${GOOGLETEST_DIR}
    )
endif ()

add_subdirectory(thirdpartylibs/googletest)

###########################################################################
#       Targets
###########################################################################
message(STATUS "pshell setup ...")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE}")
include_directories(src)

add_subdirectory(src/utilities)
add_subdirectory(src/psh)
add_subdirectory(src/simple_psh)
