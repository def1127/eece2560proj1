GCC = g++
CFLAGS = -g -O3 -Wall
OBJS = main.o LockBox.o ClientFeedback.o SmartClient.o

main: $(OBJS)
	$(GCC) $(OBJS) -o main

main.o: LockBox.h LockBox.cpp ClientFeedback.h ClientFeedback.cpp
	$(GCC) $(CFLAGS) -c main.cpp

LockBox.o: LockBox.h
	$(GCC) $(CFLAGS) -c LockBox.cpp

ClientFeedback.o: ClientFeedback.h
	$(GCC) $(CFLAGS) -c ClientFeedback.cpp

SmartClient.o: SmartClient.h
	$(GCC) $(CFLAGS) -c SmartClient.cpp

clean:
	rm -f $(OBJS)