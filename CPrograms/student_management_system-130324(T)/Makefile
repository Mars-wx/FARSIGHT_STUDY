CC=gcc
CFLAG= -c -O2 -Wall

main:get.o sort.o show.o main.o
	$(CC) $^ -o $@
get.o:get.c head.h
	$(CC) $^ $(CFLAG)
sort.o:sort.c head.h
	$(CC) $^ $(CFLAG)
show.o:show.c head.h
	$(CC) $^ $(CFLAG)
main.o:main.c head.h
	$(CC) $^ $(CFLAG)

.PHONY: clean
clean:
	@-rm *.o main
	@-echo done !
