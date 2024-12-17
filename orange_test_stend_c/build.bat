gcc -g -c --std=c11 -lconio -Wall -lwiringPi -o test_board.o test_board.c
gcc -g -c --std=c11 -lconio -Wall -o decoder_data.o decoder_data.c
gcc -g -c --std=c11 -lconio -Wall -o pub_mqtt.o pub_mqtt.c
gcc -o test_board.exe test_board.o decoder_data.o pub_mqtt.o -L/usr/local/lib -lwiringPi -lpaho-mqtt3c
pause
test_board.exe
pause
