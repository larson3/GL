CC = g++
CFLAGS = -ansi -Wall
TARGET = Proj4
TARGET2 = Proj4Aux
TARGET3 = Document
TARGET4 = DocumentStore
TARGET5 = Memo
TARGET6 = Email
TARGET7 = Report


all: Proj4
Proj4: Proj4.cpp
	$(CC) $(CFLAGS) $(TARGET).cpp $(TARGET2).cpp $(TARGET3).cpp $(TARGET4).cpp $(TARGET5).cpp $(TARGET6).cpp $(TARGET7).cpp -o $(TARGET).out
clean:
	$(RM)$(TARGET)