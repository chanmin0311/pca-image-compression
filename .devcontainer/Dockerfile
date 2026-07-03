FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-24.04

RUN apt-get update && apt-get install -y \
    cmake \
    clang-format \
    ninja-build \
    gdb \
    valgrind \
    pkg-config \
    git \
    libopencv-dev \
    libeigen3-dev \
    libfmt-dev \
    && apt-get clean
