BBB=no

ifeq ($(BBB),yes)
  $(info Traîtement pour cible BBB/ARM...)
  CC=arm-linux-gnueabihf-gcc-8
  AR=arm-linux-gnueabihf-ar
  LIBS=-L/usr/arm-linux-gnueabihf/lib
else
  $(info Traîtement pour cible PC/AMD64...)
  CC=gcc
  AR=ar
  LIBS=
endif

CFLAGS=-Wall
LIB=libx440

all: $(LIB).so $(LIB).a

$(LIB).so: $(LIB).h $(LIB).c
	$(CC) $(CFLAGS) -shared -fPIC $(LIB).c -o $(LIB).so $(LIBS)
$(LIB).a: $(LIB).h $(LIB).c
	$(CC) $(CFLAGS) -c $(LIB).c $(LIBS)
	$(AR) rcs $(LIB).a libx440.o

.PHONY: clean

clean:
	$(info Suppression des précédents fichiers générés...)
	@[ -f $(LIB).o ] && rm $(LIB).o || true
	@[ -f $(LIB).so ] && rm $(LIB).so || true
	@[ -f $(LIB).a ] && rm $(LIB).a || true
