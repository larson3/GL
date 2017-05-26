CC = g++
CFLAGS = -ansi -Wall
TARGET = Driver
TARGET1 = QuadraticProbing
TARGET2 = ReadData
TARGET3 = SoloHash


all: Driver
Driver: Driver.cpp
	$(CC) $(CFLAGS) $(TARGET).cpp $(TARGET1).cpp $(TARGET2).cpp $(TARGET3).cpp -o $(TARGET).out
run: 
	./Driver.out $(DIR)
clean:
	rm -rf *.o
	rm -f a.out
	rm -f Driver.out
	rm -f *~ *.h.gch *#
