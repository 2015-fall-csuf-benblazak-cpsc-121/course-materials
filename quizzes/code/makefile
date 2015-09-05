# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

CPP := $(wildcard *.cpp)

OUTPUT := $(CPP:%.cpp=%.gen.output)
SECTION := $(CPP:%=%.gen.section)  # and possible some *.section-* files too
BLANK := $(CPP:%=%.gen.blank) $(OUTPUT:%=%.gen.blank)

# -----------------------------------------------------------------------------
.PHONY: all clean cleanall

all: $(OUTPUT) $(SECTION) $(BLANK)

clean:
	-rm *.gen.exe

cleanall: clean
	-rm *.gen.*

# -----------------------------------------------------------------------------

%.gen.exe: %.cpp
	clang++ -o '$@' '$<'

%.gen.output: %.gen.exe
	./'$<' > '$@'

%.gen.section: %
	../../scripts/gen-section.py '$<' '//'

%.gen.blank: %
	sed 's/.*/ /' '$<' > '$@'

