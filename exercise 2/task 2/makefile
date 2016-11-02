CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra -c -std=c++11
LFLAGS = -Wall $(DEBUG)
OBJS = driver.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

main.o: driver.h driver.cpp
	$(CC) $(CFLAGS) driver.cpp

clean:
	\rm -f driver *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~