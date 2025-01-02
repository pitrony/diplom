//#include <stdio.h>
#include "test_board.h"
// gcc -Wall pcf8574.c -o pcf8574 -lwiringPi
// sudo ./pcf8574
// wiringPiI2CWrite(fd,0xEF);  //LED ON
     //   delay(500);
       // wiringPiI2CWrite(fd,0xFF);  //LED OFF
        //delay(500);

int data1=0x00;
int data2=0xff;
int adr1=0x20;
int adr2=0x24;
int main(){
struct move_t word1={0,0,0,0,0,0};
struct status_t word2={0,0,0,0,0,0,0,0};
 int fd1, fd2; 
    wiringPiSetup();
    fd1 = wiringPiI2CSetup(adr1);
    fd2 = wiringPiI2CSetup(adr2);
	wiringPiI2CWrite(fd1,0xFF);
	wiringPiI2CWrite(fd2,0xFF);
while (1)
{	
	data1=wiringPiI2CRead(fd1);
	data2=wiringPiI2CRead(fd2);
printf("\n%d", data1);
printf("\n%d", data2);
printf("\n");
char topic1[]="/host/orangepi/data1";
int send1=send_mqtt(topic1, data1);
char topic2[]="/host/orangepi/data2";
int send2=send_mqtt(topic2, data2);
if (send1==1 && send2==1)
printf("sending Ok\n");
else 
printf("sending is eror\n");
printf("\n");
decode(&word1, &word2, data1, data2);

Sleep(2); 
}

return 1;	
	
}
