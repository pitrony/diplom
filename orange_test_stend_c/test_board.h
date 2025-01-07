#include <stdio.h>
#include <time.h>
#include <string.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <MQTTClient.h>
#include <MQTTClientPersistence.h>
#include <MQTTAsync.h>
#include <stdint.h>
#include <stdlib.h>
#if defined(_WIN32)
    #define sleep Sleep
    #include <windows.h>
#else
    #include <sys/time.h>
    #include <unistd.h>
#endif
//#define ADDRESS     "tcp://localhost:1883"
#define ADDRESS     "mqtt.eclipseprojects.io:1883"
#define CLIENTID    "Orangepi"

#define QOS         1
#define TIMEOUT     10000L

typedef struct move_t{
	uint8_t speed;
	uint8_t forwrd;
	uint8_t reverse;
	uint8_t ready;
	uint8_t fren;
	uint8_t ptc;
	} move_t;
typedef struct status_t{
	uint8_t inspect;
	uint8_t up;
	uint8_t down;
	uint8_t ml1;
	uint8_t ml2;
	uint8_t comand_door;
	uint8_t top_floor;
	uint8_t down_floor;
	} status_t;

typedef struct status2_t{
	uint8_t rgk;
	uint8_t fri;
	uint8_t ppp;
	uint8_t safe;
	uint8_t dsh;
	uint8_t dcab;
	uint8_t ligth;
	uint8_t rez1;
	} status2_t;
/* calls floor
typedef struct callfl_t{
	uint8_t fl1;
	uint8_t fl2;
	uint8_t fl3;
	uint8_t fl4;
	uint8_t fl5;
	uint8_t fl6;
	uint8_t fl7;
	uint8_t fl8;
	} callfl_t;	
*/
void decode(move_t* _word1, status_t* _word2, const int _data1, const int _data2);
int send_mqtt(char* TOPIC, int data);
