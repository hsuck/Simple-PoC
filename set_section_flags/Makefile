SHELL = /bin/bash
CC = gcc
CFLAGS = -gdwarf
OC = objcopy
OFLAGS = --set-section-flags
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
EXE = $(patsubst %.c, %, $(SRC))
LDSCRIPT = $(wildcard *.x)

all: ${EXE}

${EXE}: ${OBJ}
	${CC} ${CFLAGS} $@.o -o $@ -T ${LDSCRIPT}

${OBJ}: ${SRC}
	${CC} -c ${CFLAGS} ${SRC} -o $@
	${OC} ${OFLAGS} '.debug_str=alloc,load' $@

clean:
	rm -rf ${EXE} ${OBJ}
