CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
SRC = src/*.cpp main.cpp
TARGET = RideHub

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
