# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -DDEBUG \
    -I./src \
    -I./src/scheduler \
    -I./src/fc \
    -I./hal

# Source and build config
SRC = \
    src/main.c \
    src/scheduler/scheduler.c \
    src/fc/tasks.c \
    src/fc/attitude.c \
    src/fc/gyro.c \
    src/fc/mixer.c \
    src/fc/pid.c \
    src/fc/ctrl.c \
    hal/sim/timing_sim.c \
	hal/sim/imu_sim.c \
    hal/sim/motor_sim.c \

OBJ = $(SRC:%.c=build/%.o)
OUT = build/flightx

# Default rule
all: clean $(OUT)

# Link all object files into final binary
$(OUT): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each source file into corresponding build/ object file
build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf build
