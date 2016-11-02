CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra -c -std=c++11
LFLAGS = -Wall $(DEBUG)
OBJS = driver.o playfield.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

driver.o: player.hpp connect4.hpp playfield.hpp driver.cpp
	$(CC) $(CFLAGS) driver.cpp

playfield.o: playfield.hpp playfield.cpp
	$(CC) $(CFLAGS) playfield.cpp

clean:
	\rd *.o
	\rd *.txt
