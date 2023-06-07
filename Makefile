all: gpt

gpt: gpt.o
	g++ -o gpt gpt.o

mbr.o: mbr.c
	g++ -c -o gpt.o gpt.c

clean:
	rm -f gpt 
	rm -f *.o