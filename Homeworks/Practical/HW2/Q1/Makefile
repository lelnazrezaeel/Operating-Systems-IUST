CC    = gcc
CFLAGS  = -g
RM    = rm -f

default: all

all: redirect    

redirect: redirect.c
	$(CC) $(CFLAGS) -o redirect redirect.c

clean veryclean:
	$(RM) redirect