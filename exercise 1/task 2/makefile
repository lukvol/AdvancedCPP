CC = g++-6
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -c
LFLAGS = -Wall $(DEBUG)
OBJS_DRIVER_1 = fraction.o main1.o
OBJS_DRIVER_2 = fraction.o main2.o

all: driver1 driver2

driver2: $(OBJS_DRIVER_2)
	$(CC) $(OBJS_DRIVER_2) -o driver2

driver1: $(OBJS_DRIVER_1)
	$(CC) $(OBJS_DRIVER_1) -o driver1

main1.o: fraction.h main1.cpp
	$(CC) $(CFLAGS) main1.cpp

main2.o: fraction.h main2.cpp
	$(CC) $(CFLAGS) main2.cpp

fraction.o: fraction.h fraction.cpp
	$(CC) $(CFLAGS) fraction.cpp

clean:
	\rm -f driver1 driver2 *.o

distclean: clean
	\rm -f .depend/*.d
	\rm -f *~