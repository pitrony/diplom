all: test_board.exe

test_board: curs_dron.o decode.o pub_mqtt.o
	gcc -o test_board.exe test_board.o decode.o pub_mqtt.o

test_board.o: test_board.c test_board.h
	gcc -c -g -Wall -lconio --std=c17 -lwiringPi -o test_board.o test_board.c

decode.o: decode.c
	gcc -c -g -Wall -lconio --std=c17 -o decode.o decode.c

pub_mqtt.o: pub_mqtt.c
	gcc -c -g -Wall -lconio --std=c17 -o pub_mqtt.o pub_mqtt.c

dell:
	del *.o 
	del test_board.exe
