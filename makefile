CC=gcc

hinfosvc: prog.c
	$(CC) prog.c -o hinfosvc

clean: 
	rm -f hinfosvc