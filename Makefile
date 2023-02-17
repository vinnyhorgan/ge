EXE = ge.exe
CC = g++
CFLAGS = -Ideps/include -Wall -std=c++17 -O2
LDFLAGS = -Ldeps/lib -llua -lraylib -lopengl32 -lgdi32 -lwinmm

SRCS = $(wildcard src/*.cpp) $(wildcard deps/src/*.cpp)
OBJS := $(SRCS:%=build/%.o)

all: build/$(EXE) run

build/$(EXE): $(OBJS)
	$(CC) $(OBJS) -o build/$(EXE) $(LDFLAGS)

build/%.cpp.o: %.cpp
	@if not exist build mkdir build
	@if not exist build\src mkdir build\src
	@if not exist build\deps mkdir build\deps
	@if not exist build\deps\src mkdir build\deps\src

	$(CC) $(CFLAGS) -c $< -o $@

run: build/$(EXE)
	build/$(EXE)

.PHONY: clean
clean:
	rmdir /s build
