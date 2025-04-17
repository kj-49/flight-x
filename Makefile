# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src -I./src/scheduler -I./src/fc

# Source and build config
SRC = src/main.c src/scheduler/scheduler.c src/fc/tasks.c
OBJ = $(SRC:src/%.c=build/%.o)
OUT = build/flightx

# Default rule
all: $(OUT)

# Link all object files into final binary
$(OUT): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each source file into corresponding build/ object file
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf build
