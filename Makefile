CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = common_wrapper

INCLUDES = -IAssignment1/include -IAssignment2/include

SOURCES = \
	common_wrapper/common_wrapper.cpp \
	Assignment1/driver/main_driver.cpp \
	Assignment1/src/gemm_simple.cpp \
	Assignment1/src/gemm_blocking.cpp \
	Assignment1/src/csr.cpp \
	Assignment2/driver/main.cpp \
	Assignment2/src/bellman_ford.cpp \
	Assignment2/src/floyd_warshall.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	del /Q $(subst /,\,$(OBJECTS)) $(TARGET).exe 2>nul || exit 0

.PHONY: clean