CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra -c -std=c++11
LFLAGS = -Wall $(DEBUG)
OBJS = driver.o player.o connect4.o playfield.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

driver.o: player.hpp connect4.hpp playfield.hpp driver.cpp
	$(CC) $(CFLAGS) driver.cpp

playfield.o: playfield.hpp playfield.cpp
	$(CC) $(CFLAGS) playfield.cpp

connect4.o: connect4.hpp connect4.cpp
	$(CC) $(CFLAGS) connect4.cpp

player.o: player.hpp player.cpp
	$(CC) $(CFLAGS) player.cpp

clean:
	\del *.o
	\del *.txt
