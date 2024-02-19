BBB=no

ifeq ($(BBB),yes)
  CC=arm-linux-gnueabihf-gcc-8
  LIBS=-L/usr/arm-linux-gnueabihf/lib
else
  CC=gcc
  LIBS=
endif

OPATH=..
LPATH=-L$(OPATH)
CFLAGS=-Wall
OBJ=libx440.o
LIB=-lx440
EXEC=test

all: $(EXEC)_o $(EXEC)_a $(EXEC)_so

$(EXEC)_o: $(EXEC).c
	$(CC) $(CFLAGS) $(EXEC).c \
	$(OPATH)/$(OBJ) -o $(EXEC)_o

$(EXEC)_a: $(EXEC).c
	$(CC) $(CFLAGS) $(EXEC).c \
	-o $(EXEC)_a -static \
	$(LIB) $(LPATH) $(LIBS)

$(EXEC)_so: $(EXEC).c
	$(CC) $(CFLAGS) $(EXEC).c \
	-o $(EXEC)_so $(LIB) \
	$(LPATH) $(LIBS)

clean:
	rm $(EXEC)_*
