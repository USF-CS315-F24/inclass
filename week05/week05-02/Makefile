PROGS = endian signed strlen strcpy hello_c hello_s struct countll
 
ENDIAN_OBJS = endian.o
SIGNED_OBJS = signed.o
STRLEN_OBJS = strlen.o strlen_c.o strlen_s.o
STRCPY_OBJS = strcpy.o strcpy_c.o strcpy_s.o
HELLOC_OBJS = hello_c.o
HELLOS_OBJS = hello_s.o
STRUCT_OBJS = struct.o struct_c.o struct_s.o
COUNTLL_OBJS = countll.o countll_c.o countll_s.o

OBJS = ${ENDIAN_OBJS} ${SIGNED_OBJS} \
       ${STRLEN_OBJS} ${STRCPY_OBJS} \
       ${HELLOC_OBJS} ${HELLOS_OBJS} \
	   ${STRUCT_OBJS} ${COUNTLL_OBJS}

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all: ${PROGS}

endian: ${ENDIAN_OBJS}
	gcc -g -o $@ $^

signed: ${SIGNED_OBJS}
	gcc -g -o $@ $^

strlen: ${STRLEN_OBJS}
	gcc -g -o $@ $^

strcpy: ${STRCPY_OBJS}
	gcc -g -o $@ $^

hello_c: ${HELLOC_OBJS}
	gcc -g -o $@ $^

hello_s: ${HELLOS_OBJS}
	gcc -g -o $@ $^

struct: ${STRUCT_OBJS}
	gcc -g -o $@ $^

countll: ${COUNTLL_OBJS}
	gcc -g -o $@ $^


clean:
	rm -rf ${PROGS} ${OBJS}
