CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = assignment2

INCLUDES = -Iinclude -I../Assignment1/include

SOURCES = \
	driver/main.cpp \
	src/bellman_ford.cpp \
	src/floyd_warshall.cpp \
	../Assignment1/src/csr.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	del /Q $(subst /,\,$(OBJECTS)) $(TARGET).exe 2>nul || exit 0