CXXFLAGS := -std=c++14 -Wall -ggdb -O0

SOURCES := $(wildcard *.cpp)
OBJS := $(SOURCES:%.cpp=%.o)


TARGET := main

.PHONY : all
all : $(TARGET)

$(TARGET) : $(OBJS)
	 $(CXX) $(CXXFLAGS) $^ -o $@ 

.PHONY : clean
clean : 
	rm -rf $(TARGET) $(OBJS)