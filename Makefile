CXX = g++
CXXFLAGS = -std=c++11 -Wall -g3

# List of source files
SRCS = tree.cpp countsubstrings.cpp

# Object files derived from source files
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = countsubstrings

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJS)