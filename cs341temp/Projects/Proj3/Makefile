CC = g++
CFLAGS = -ansi -Wall
TARGET = Driver
TARGET1 = BinarySearchTree
TARGET2 = RandomBinarySearchTree


all: Driver
Driver: Driver.cpp
	$(CC) $(CFLAGS) $(TARGET).cpp $(TARGET1).h $(TARGET2).h -o $(TARGET).out
run: 
	./Driver.out $(FILE) $(L)
clean:
	rm -rf *.o
	rm -f a.out
	rm -f Driver.out
	rm -f *~ *.h.gch *#