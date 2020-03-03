LIBDIR = $(shell pwd)
CC = gcc
CFLAGS = -O2
LIBS = -lgslcblas -lgsl -lm

all: gplot besselJ0
clean:
	rm -f gplot.o besselJ0 libgplot.so
gplot: gplot.c gplot.h
	$(CC) $(CFLAGS) -c -o gplot.o gplot.c -I. -fPIC
	$(CC) -shared -o libgplot.so gplot.o
besselJ0: libgplot.so
	env LD_LIBRARY_PATH=$(LIBDIR):$(LD_LIBRARY_PATH) $(CC) $(CFLAGS) -o besselJ0 exJ.c $(LIBS) -L$(LIBDIR) -lgplot
