CC = g++-6
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -c
LFLAGS = -Wall $(DEBUG)
OBJS = main.o spell_checker.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

main.o: persistence_traits.h spell_checker.h main.cpp
	$(CC) $(CFLAGS) main.cpp

spell_checker.o: pset.h spell_checker.cpp spell_checker.h
	$(CC) $(CFLAGS) spell_checker.cpp

clean:
	\rm -f driver *.o
	\rm *.corrected

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~