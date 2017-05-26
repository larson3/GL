CXX = g++
CXXFLAGS = -Wall

lab9: Book.o
	$(CXX) $(CXXFLAGS) Book.o lab9.cpp -o lab9
	
Book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -c Book.cpp