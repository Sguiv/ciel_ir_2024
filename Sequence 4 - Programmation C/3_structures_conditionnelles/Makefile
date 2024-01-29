PDFLATEX=pdflatex
PDFNUP=pdfnup
FLAGS=-shell-escape
DOCUMENT=structures_conditionnelles

.PHONY: all

all: $(DOCUMENT).pdf

$(DOCUMENT).pdf: $(DOCUMENT).tex
	make pdf
	make nup

pdf: $(DOCUMENT).tex
	$(PDFLATEX) $(FLAGS) $(DOCUMENT).tex

nup: $(DOCUMENT).pdf
	$(PDFNUP) --nup 2x1 $(DOCUMENT).pdf
	mv $(DOCUMENT)-nup.pdf $(DOCUMENT)-multi.pdf

clean:
	rm -rf *.aux *.log *.out

mrproper: clean
	rm -rf $(DOCUMENT).pdf
