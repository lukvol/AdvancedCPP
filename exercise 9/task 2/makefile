CC = g++-6
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -c
LFLAGS = -Wall $(DEBUG)
OBJS = main.o indentation_buffer.o

all: driver

driver: $(OBJS)
	$(CC) $(OBJS) -o driver

main.o: indentation_buffer.h main.cpp
	$(CC) $(CFLAGS) main.cpp

indentation_buffer.o: indentation_buffer.cpp indentation_buffer.h
	$(CC) $(CFLAGS) indentation_buffer.cpp

clean:
	\rm -f driver *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~
