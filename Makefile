CC = gcc

all: sed_simplified

sed_simplified: main.o functions.o checkValidate.o
	$(CC) -o sed_simplified main.o functions.o checkValidate.o

main.o: main.c header.h
	$(CC) -c main.c

functions.o: functions.c header.h
	$(CC) -c functions.c

checkValidate.o: checkValidate.c header.h
	$(CC) -c checkValidate.c

clean:
	rm -f *.o sed_simplified
