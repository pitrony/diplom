
#include "test_board.h"

int data1=0x00;
int data2=0xff;
int data3=0xff;
int adr1=0x20;
int adr2=0x24;
int adr3=0x22;
int main(){
struct move_t word1={0,0,0,0,0,0};
struct status_t word2={0,0,0,0,0,0,0,0};
struct status2_t word3={0,0,0,0,0,0,0,0};
 int fd1, fd2, fd3; 
    wiringPiSetup();
    fd1 = wiringPiI2CSetup(adr1);
    fd2 = wiringPiI2CSetup(adr2);
	fd3 = wiringPiI2CSetup(adr3);
	wiringPiI2CWrite(fd1,0xFF);
	wiringPiI2CWrite(fd3,0xFF);
	wiringPiI2CWrite(fd2,0xFF);
while (1)
{	
	data1=wiringPiI2CRead(fd1);
	data2=wiringPiI2CRead(fd2);
	data3=wiringPiI2CRead(fd3);
printf("\n%d", data1);
printf("\n%d", data2);
printf("\n%d", data3);
printf("\n");
char topic1[]="/orange/data1";
int send1=send_mqtt(topic1, data1);
char topic2[]="/orange/data2";
int send2=send_mqtt(topic2, data2);
//char topic3[]="/orange/data3";
//int send3=send_mqtt(topic3, data3);

if (send1==1 && send2==1)
printf("sending Ok\n");
else 
printf("sending is eror\n");
printf("\n");
decode(&word1, &word2, data1, data2);

sleep(2); 
}

return 1;	
	
}
