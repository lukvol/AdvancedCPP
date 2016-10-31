CC = g++-6
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -c
LFLAGS = -Wall $(DEBUG)
OBJS = main.o rpn.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

main.o: RPN.h main.cpp
	$(CC) $(CFLAGS) main.cpp

rpn.o: RPN.h RPN.cpp
	$(CC) $(CFLAGS) RPN.cpp

clean:
	\rm -f driver *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~