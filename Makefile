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

test1: 
	./sed_simplified input.txt -r "new" "prog"

test2:
	./sed_simplified input.txt -i -f "mega"

test3:
	./sed_simplified input.txt -i -b "lol"

test4:
	./sed_simplified input.txt -d "prog"

clean:
	rm -f *.o sed_simplified
