EXE := $(wildcard *.cpp)
EXE := $(EXE:%.cpp=%)

CXXFLAGS := -std=c++11
# CXXFLAGS += -pedantic
# CXXFLAGS += -Weverything

# -----------------------------------------------------------------------------
.PHONY: all clean

all: $(EXE)

clean:
	rm $(EXE)

