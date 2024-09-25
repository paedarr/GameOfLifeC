# /**
#  * @file Makefile
#  * @author Paedar Rader
#  * @brief This file contains the the Makefile specifications and functionality so the
#  * user can assemble to code using make commands. Refer to README.md for more.
#  * @date 2024-09-24
#  * 
#  * @copyright Copyright (c) 2024
#  * 
#  */

CC = gcc
CFLAGS = -Wall -Wextra -g

# all c files are listed as sources
SOURCES = gol_cmd.c gol_io.c gol_sim.c gol.c

# generate object file names
OBJECTS = $(SOURCES:.c=.o)

# main target, gol
TARGET = gol

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# rule for compiling .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean