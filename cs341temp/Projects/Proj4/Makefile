CC = g++
CFLAGS = -ansi -Wall
TARGET = Driver
TARGET1 = IntervalHeap


all: Driver
Driver: Driver.cpp
	$(CC) $(CFLAGS) $(TARGET).cpp $(TARGET1).cpp -o $(TARGET).out
run: 
	./Driver.out $(MIN) $(MAX) $(SIZE) $(SEED)
clean:
	rm -rf *.o
	rm -f a.out
	rm -f Driver.out
	rm -f *~ *.h.gch *#