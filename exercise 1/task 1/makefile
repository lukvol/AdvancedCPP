CC = g++-6
CFLAGS = -Wall -Wextra -Werror
OBJS = main.cpp

all: main

main: $(OBJS)
	$(CC) $(OBJS) -o main

clean:
	\rm -f main *.o

distclean:
	clean
	\rm -f .depend/*.d
	\rm -f *~