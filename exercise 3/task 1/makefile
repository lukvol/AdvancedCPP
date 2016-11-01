CC = g++-6
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -c
LFLAGS = -Wall $(DEBUG)
OBJS = main.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

main.o: persistence_traits.h pset.h pvector.h main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm -f driver *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~