CFLAGS=-W -Wall -g -I/usr/local/include
LDFLAGS=-L/usr/local/lib	
OBJECTS=exerciseStack.o balanceCheck.o
LIBRARIES=-lADTs 
all: exerciseStack balanceCheck

exerciseStack: exerciseStack.o 
	gcc $(LDFLAGS) -o  exerciseStack exerciseStack.o $(LIBRARIES)

balanceCheck: balanceCheck.o
	gcc $(LDFLAGS) -o balanceCheck balanceCheck.o $(LIBRARIES)


exerciseStack.o: exerciseStack.c
balanceCheck.o: balanceCheck.c


clean:
	rm -f $(OBJECTS) exerciseStack balanceCheck
