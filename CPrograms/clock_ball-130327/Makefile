CC=gcc
CFLAG= -O2 -Wall -c
OBJ=linkqueue.o main.o seqstack.o linknode.o

main:$(OBJ)
	$(CC) $^ -o $@

linkqueue.o:linkqueue.c 
	$(CC) $^ $(CFLAG) -o $@
main.o:main.c
	$(CC) $^ $(CFLAG) -o $@
seqstack.o:seqstack.c 
	$(CC) $^ $(CFLAG) -o $@
linknode.o:linknode.c 
	$(CC) $^ $(CFLAG) -o $@

.PHONY:clean

clean:
	-rm $(OBJ) main
	@-echo done !


