PROGS = arr call
ARR_OBJS = arr.o arr_c.o arr_s.o
CALL_OBJS = call.o call_c.o call_s.o
OBJS = ${ARR_OBJS} ${CALL_OBJS}

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all: ${PROGS}

arr: $(ARR_OBJS)
	gcc -g -o $@ $^

call: $(CALL_OBJS)
	gcc -g -o $@ $^
	

clean:
	rm -rf ${PROGS} ${OBJS}

