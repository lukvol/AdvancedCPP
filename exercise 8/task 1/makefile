CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra -c -std=c++11
LFLAGS = -Wall $(DEBUG)
OBJS = driver.o playerFactory.o my_playfield.o computerplayer.o humanplayer.o player_nico.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

driver.o: player.hpp connect4.hpp playfield.hpp driver.cpp
	$(CC) $(CFLAGS) driver.cpp

playerFactory.o: player.hpp playerFactory.cpp
	$(CC) $(CFLAGS) playerFactory.cpp

my_playfield.o: playfield.hpp my_playfield.hpp my_playfield.cpp
	$(CC) $(CFLAGS) my_playfield.cpp

computerplayer.o: player.hpp computerplayer.hpp computerplayer.cpp
	$(CC) $(CFLAGS) computerplayer.cpp

humanplayer.o: player.hpp humanplayer.hpp humanplayer.cpp
	$(CC) $(CFLAGS) humanplayer.cpp

player_nico: player.hpp player_nico.h player_nico.cc
	$(CC) $(CFLAGS) player_nico.cpp

clean:
	\rm -f driver *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~