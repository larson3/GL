CC = g++
CFLAGS = -ansi -Wall
TARGET = Driver
TARGET1 = SeismicEvent
TARGET2 = SeismicDataCollector
TARGET3 = AcousticNoise
TARGET4 = AnthropogenicEvent
TARGET5 = Earthquake
TARGET6 = Explosion
TARGET7 = MiningExplosion
TARGET8 = QuarryBlast


all: Driver
Driver: Driver.cpp
	$(CC) $(CFLAGS) $(TARGET).cpp $(TARGET1).cpp $(TARGET2).cpp $(TARGET3).cpp $(TARGET4).cpp $(TARGET5).cpp $(TARGET6).cpp $(TARGET7).cpp $(TARGET8).cpp -o $(TARGET).out
run: 
	./Driver.out $(FILE)
clean:
	rm -rf *.o
	rm -f a.out
	rm -f Driver.out
	rm -f *~ *.h.gch *#