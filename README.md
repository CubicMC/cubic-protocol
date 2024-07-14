# Cubic Protocol

A complete C++ implementation of Minecraft's protocol.

## Status

This project is currently still in its infancy and still needs a lot of work to
be considered finished.

## Goals

The goal is to support all the protocols from 1.21 upwards, but older versions
might be added if people are interested enough.

## Running

Precompiled binaries are not currently available.

See **Building** section to know how to compile the library.

## Building

Currently **only Linux x86_64** is targeted, it might build on another system
but it isn't guaranted for now (Windows, FreeBSD and OpenBSD will be supported
later down the road, but not until we have a solid codebase.)

### Dependencies

Here is the list of dependencies required to build CubicProtocol:

 - gcc7\* (Any c++17 compliant compiler should work but it is not guarranted as
 we do not code strictly to the standard)
 - gnumake (Build system, other make versions might work but have not been
 tested)

\* gcc7 is the lowest version that should work with this codebase but it has
not been tested yet, a higher compiler version will always be recommended for
optimization reasons. See the gcc c++17 feature matrix
[here](https://gcc.gnu.org/projects/cxx-status.html#cxx17).

### How to build
#### Build from source on your machine
To build follow those steps :
```bash
git clone https://github.com/CubicMC/cubic-protocol
cd cubic-protocol
make -j `nproc --exclude 1` # The -j option is here to speed-up the compilation
```

## TODO for this README

- Testing
- Lib deps
- Build system explaination

## Contributing

Any contributions are welcome, if you don't know what to do you can take a look
at our issues tab and start talking in one of them to contribute :D.
