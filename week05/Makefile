PROGS = endian strlen strcpy

ENDIAN_OBJS = endian.o
STRLEN_OBJS = strlen.o strlen_c.o strlen_s.o
STRCPY_OBJS = strcpy.o strcpy_c.o strcpy_s.o

OBJS = ${ENDIAN_OBJS} ${STRLEN_OBJS} ${STRCPY_OBJS}

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all: ${PROGS}

endian: ${ENDIAN_OBJS}
	gcc -g -o $@ $^

strlen: ${STRLEN_OBJS}
	gcc -g -o $@ $^

strcpy: ${STRCPY_OBJS}
	gcc -g -o $@ $^

clean:
	rm -rf ${PROGS} ${OBJS}
