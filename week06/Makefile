PROGS = decode rv_emu

DECODE_OBJS = decode.o add2_s.o
RV_EMU_OBJS = rv_emu.o add2_c.o add2_s.o

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all : ${PROGS}

decode: ${DECODE_OBJS}
	gcc -g -o $@ $^

rv_emu: ${RV_EMU_OBJS}
	gcc -g -o $@ $^

clean:
	rm -rf ${PROGS} ${OBJS}
	
