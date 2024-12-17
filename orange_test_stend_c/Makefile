all: test_board.exe

test_board.exe: test_board.o decode.o pub_mqtt.o
	gcc -o test_board.exe test_board.o decode.o pub_mqtt.o -L/usr/local/lib -lwiringPi -lpaho-mqtt3c

test_board.o: 
	gcc -c -g -Wall -lconio --std=c11 -lwiringPi -o test_board.o test_board.c

decode.o:
	gcc -c -g -Wall -lconio --std=c11 -o decode.o decoder_data.c

pub_mqtt.o: 
	gcc -c -g -Wall -lconio --std=c11 -o pub_mqtt.o pub_mqtt.c -L/usr/local/lib -lpaho-mqtt3c

dell:
	rm *.o 
	rm test_board.exe
