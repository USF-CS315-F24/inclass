PROGS = first_c first_s add1 add3 add3arr ifelse loop
FIRSTC_OBJS = first_c.o
FIRSTS_OBJS = first_s.o
ADD1_OBJS = add1.o add1_c.o add1_s.o
ADD3_OBJS = add3.o add3_c.o add3_s.o
ADD3ARR_OBJS = add3arr.o add3arr_c.o add3arr_s.o
IFELSE_OBJS = ifelse.o ifelse_c.o ifelse_s.o
LOOP_OBJS = loop.o loop_c.o loop_s.o
CLEAN_OBJS = ${FIRSTC_OBJS} ${FIRSTS_OBJS} ${ADD1_OBJS} \
			 ${ADD3_OBJS} ${ADD3ARR_OBJS} ${IFELSE_OBJS} \
			 ${LOOP_OBJS}

%.o : %.s
	as -g -o $@ $<

%.o : %.c
	gcc -g -c -o $@ $<

all : ${PROGS}

first_c : ${FIRSTC_OBJS}
	gcc -g -o $@ $^

first_s : ${FIRSTS_OBJS}
	gcc -g -o $@ $^

add1: ${ADD1_OBJS}
	gcc -g -o $@ $^

add3: $(ADD3_OBJS)
	gcc -g -o $@ $^

add3arr: $(ADD3ARR_OBJS)
	gcc -g -o $@ $^

ifelse: $(IFELSE_OBJS)
	gcc -g -o $@ $^

loop: $(LOOP_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf ${CLEAN_OBJS} ${PROGS}
