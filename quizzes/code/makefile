# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

CPP := $(wildcard *.cpp)
CPP := $(filter-out %.part.cpp,$(CPP))

OUTPUT := $(CPP:%.cpp=.%.gen.output)
BLANK := $(CPP:%=.%.gen.blank) $(OUTPUT:%=%.gen.blank)

# possibly incomplete list of section files
SECTION := $(CPP:%=.%.gen.section.all) $(OUTPUT:%=%.gen.section.all)

# -----------------------------------------------------------------------------
.PHONY: all clean cleanall

all: $(OUTPUT) $(SECTION) $(BLANK)

clean:
	-rm -r .*.gen.* *.gen.*

cleanall: clean

# -----------------------------------------------------------------------------

.%.cpp: %.cpp
	cp '$<' '$@'

%.gen.exe: %.cpp
	clang++ -o '$@' '$<'

%.gen.output: %.gen.exe
	./'$<' > '$@'

%.gen.section.all: %
	../../scripts/gen-section.py '$<' '//'
	-for i in $*.gen.section.*--bad; do make "$${i/%--bad/--diff}"; done
	for i in $*.gen.section.*; do make "$${i/%.gen.blank/}.gen.blank"; done

%--diff: %--bad %--good
	diff -u $^ | tail -n +3 > '$@'

%.gen.blank: %
	sed 's/.*/ /' '$<' > '$@'

