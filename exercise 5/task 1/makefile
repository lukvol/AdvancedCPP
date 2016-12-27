CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -c
LFLAGS = -Wall $(DEBUG)
OBJS = testdriver.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

testdriver.o: dumb_pointer.h smart_pointer.h testdriver.cpp
	$(CC) $(CFLAGS) testdriver.cpp

clean:
	\rm -f driver *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~