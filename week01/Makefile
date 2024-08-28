PROGS = hello hello.cpreproc concepts

% : %.c
	gcc -g -o $@ $<

all : ${PROGS}

hello.cpreproc : hello.c
	gcc -E $< > $@
	
clean :
	rm -rf ${PROGS}
