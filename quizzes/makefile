# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

TEX := $(wildcard *.tex)
TEX := $(filter-out %.part.tex,$(TEX))
TEX := $(filter-out %.gen.tex,$(TEX))
TEX := $(TEX:%.tex=%.questions.gen.tex) $(TEX:%.tex=%.answers.gen.tex)
PDF := $(TEX:%.tex=%.pdf)

# -----------------------------------------------------------------------------
.PHONY: all clean cleanall

all: $(PDF)

clean:
	latexmk --shell-escape -lualatex -pdf -c $(TEX)
	-rm *.out.pyg *.fls

cleanall: clean
	latexmk --shell-escape -lualatex -pdf -C $(TEX)
	-rm *.gen.tex

# -----------------------------------------------------------------------------
.PHONY: view-standards

view-standards:
	@grep --color -r ' \\standard{' *

# -----------------------------------------------------------------------------
.SECONDARY: $(TEX)

%.questions.gen.tex: %.tex makefile
	( echo '\\long\\def \\question #1{#1}'; \
	  echo '\\long\\def \\answer #1{}'; \
	  echo '\\input{$<}'; \
	  echo; \
	) > '$@'

%.answers.gen.tex: %.tex makefile
	( echo '\\long\\def \\question #1{}'; \
	  echo '\\long\\def \\answer #1{#1}'; \
	  echo '\\input{$<}'; \
	  echo; \
	) > '$@'

# -----------------------------------------------------------------------------

%.pdf: %.tex document-setup.part.tex scripts/functions.lua
	latexmk --shell-escape -lualatex -pdf '$<'

