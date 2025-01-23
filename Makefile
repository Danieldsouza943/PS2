
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -pedantic -O2

SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
SFML_INCLUDE = /usr/include
SFML_LIB_DIR = /usr/lib

TARGET = Penta

# Source files
SRCS = main.cpp penta.cpp
HEADERS = penta.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE) -L$(SFML_LIB_DIR) $(OBJS) -o $(TARGET) $(SFML_LIBS)

lint:
	cpplint --filter=-build/include_what_you_use,-build/c++11,-runtime/explicit $(SRCS) $(HEADERS)

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE) -c $< -o $@

