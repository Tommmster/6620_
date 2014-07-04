

SOURCES = $(shell find . -name \*.tex)
OBJECTS = $(patsubst %.tex, %.pdf, $(SOURCES))

all: $(OBJECTS)
        :
        
%.pdf: %.tex
	pdflatex $<
	pdflatex $<
	if [ ! -d pdfs ]; then mkdir pdfs; fi
	mv $@ pdfs/$@
	

clean:
	rm -rf *.pdf *.log *.aux
	rm -rf pdfs

