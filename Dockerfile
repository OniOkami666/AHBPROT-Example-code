FROM devkitpro/devkitppc:latest

WORKDIR /workspace
COPY . /workspace
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build .