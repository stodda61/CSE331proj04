EXE = out
SOURCES = main.cpp
OBJECTS := $(SOURCES:%.cpp=%.o)
CXXFLAGS = -Wall -std=c++11
CXX = g++

$(EXE) : $(OBJECTS)
	$(CXX) $^ -o $@

clean:
	$(RM) $(EXE) $(OBJECTS)



