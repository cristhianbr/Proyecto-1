cc = gcc
CFLAGS = -O3 -c -Wall

all:	object
	$(cc) -o main *.o
	rm *.o	

object: 
	$(cc) $(CFLAGS) *.c

clean:
	rm main
