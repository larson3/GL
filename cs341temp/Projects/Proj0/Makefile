CC = g++
CFLAGS = -ansi -Wall -g
TARGET = Driver



all: Driver
Driver: Driver.cpp
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET).out
run: 
	./Driver.out $(FILE)
clean:
	rm -rf *.o
	rm -f a.out
	rm -f Driver.out
	rm -f *~ *.h.gch *#