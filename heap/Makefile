CXX := clang++
CXXFLAGS := -std=c++23 -Wall -Wextra -Werror -pedantic -ferror-limit=3 -glldb
SRCS := main.cpp
TARGET := heap_example
OBJS := $(SRCS:.cpp=.o)
DEPS := heap.tpp heap.hpp

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o : %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)\
