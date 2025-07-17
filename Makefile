CXX = g++
CXXFLAGS = -Wall -std=c++17 -I/opt/homebrew/include/SDL2
LDFLAGS = -L/opt/homebrew/lib -lSDL2

SRC = main.cpp particle.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = cloth_sim

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
