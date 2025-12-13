CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -O2
TARGET = main
SRCS = main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
