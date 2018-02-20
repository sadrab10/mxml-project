#gcc -o helloWorld helloWorld.c -L/home/ubuntu/Downloads/projet -lmxml -lpthread

CC=gcc
CFLAGS=
LDFLAGS= -L/home/ubuntu/Downloads/projet
LIBS = -lmxml -lpthread
EXEC= helloWorld

all: $(EXEC)

helloWorld: helloWorld.o 
	$(CC) -o helloWorld helloWorld.o $(LDFLAGS) 

helloWorld.o: helloWorld.c
	$(CC) -o helloWorld.o -c helloWorld.c $(LIBS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
