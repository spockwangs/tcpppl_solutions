# Makefile in top directory.

SUBDIRS = $(shell find . -maxdepth 1 -type d -name '[^.]*')

all:
	for i in $(SUBDIRS); do \
	    $(MAKE) -C "$$i" all; \
	done

clean:
	for i in $(SUBDIRS); do \
	    $(MAKE) -C "$$i" clean; \
	done
	
dist-clean:
	for i in $(SUBDIRS); do \
	    $(MAKE) -C "$$i" dist-clean; \
	done
