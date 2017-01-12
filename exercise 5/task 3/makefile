CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra -c -std=c++11
LFLAGS = -Wall $(DEBUG)
OBJS = driver.o playfield.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

driver.o: player_cpu.hpp player.h connect4.hpp playfield.hpp driver.cpp
	$(CC) $(CFLAGS) driver.cpp

playfield.o: playfield.hpp playfield.cpp
	$(CC) $(CFLAGS) playfield.cpp

clean:
	\rm -f driver *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~