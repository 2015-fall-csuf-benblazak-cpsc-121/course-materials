# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

CPP := $(wildcard *.cpp)
TXT := $(CPP:%.cpp=%.gen.txt)

# -----------------------------------------------------------------------------
.PHONY: all clean cleanall

all: $(TXT)

clean:
	-rm *.gen.exe

cleanall: clean
	-rm *.gen.*

# -----------------------------------------------------------------------------

%.gen.exe: %.cpp
	clang++ -o $@ $<

%.gen.txt: %.gen.exe
	./$< > $@

