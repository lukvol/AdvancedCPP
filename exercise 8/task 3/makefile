CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra -c -std=c++11 -pthread
LFLAGS = -Wall $(DEBUG)
OBJS = driver.o my_playfield.o computerplayer.o humanplayer.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

driver.o: player.hpp connect4.hpp playfield.hpp driver.cpp
	$(CC) $(CFLAGS) driver.cpp

my_playfield.o: playfield.hpp my_playfield.hpp my_playfield.cpp
	$(CC) $(CFLAGS) my_playfield.cpp

computerplayer.o: player.hpp computerplayer.hpp computerplayer.cpp
	$(CC) $(CFLAGS) computerplayer.cpp

humanplayer.o: player.hpp humanplayer.hpp humanplayer.cpp
	$(CC) $(CFLAGS) humanplayer.cpp

clean:
	\rm -f driver *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~