CC = gcc
TARGET=hellomake
OBJETCS=hellomake.o hellofunc.o

$(TARGET): $(OBJETCS)
	$(CC) -o $(TARGET) $(OBJETCS)

hellomake.o: hellomake.c hellofunc.h
	$(CC) -c hellomake.c -I.

clean :
	-rm $(TARGET) $(OBJETCS)
