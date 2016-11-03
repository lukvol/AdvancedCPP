CC = g++-6
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -c
LFLAGS = -Wall $(DEBUG)
OBJS = main.o fraction.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

main.o: RPN.h fraction.h main.cpp
	$(CC) $(CFLAGS) main.cpp

fraction.o: fraction.h mymin.h fraction.cpp
	$(CC) $(CFLAGS) fraction.cpp

clean:
	\rm -f driver *.o
	\rm *.txt
distclean: clean
	\rm -f .depend/*.d
	\rm -f *~