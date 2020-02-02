# pshell

pshell is a simple object-oriented shell implementation.

## Prerequisites

 * C++11 capable compiler
 * [cmake](http://cmake.org/)
 * optionally [Doxygen](http://doxygen.org/) to build docs

## Build

pshell is built using CMake.

Clone source code repository:

    $ git clone https://github.com/jmprathab/pshell.git

Next

    $ mkdir build
    $ cd build

Generate project files for your favorite IDE or Makefile by running `cmake -G "{target}"` in the build directory.

For example:

    $ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release && make

or

    $ cmake .. -G "Xcode"

There are several variants of build:

`-DCMAKE_BUILD_TYPE`  must be one of the:
- `Debug` - enable debug messages, assertions and disable optimization
- `Release` - release build
- `RelWithDebInfo` - release build with debug information enabled
- `MinSizeRel` - minimal size release
- `AddressSanitizer` - special build to run under [Address Sanitizer](https://code.google.com/p/address-sanitizer/) (compiler support and libasan required)

## Run tests or benchmarks

All binaries (main executable, unit tests, etc.) will be in `bin/{build_type}`.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0)

## Credits

* Thanks to all the open source community
