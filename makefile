all: testEvent

testEvent: event.o testEvent.o
	gcc -o ./outputs/testEvent ./outputs/testEvent.o ./outputs/event.o

testEvent.o: event.o
	gcc -I headers -o ./outputs/testEvent.o -c ./test/testEvent.c -Wall

event.o:
	gcc -I headers -o ./outputs/event.o -c ./src/event.c -Wall

clean:
	rm -rf ./outputs/*.o

mrproper: clean
	rm -rf ./outputs/testEvent
