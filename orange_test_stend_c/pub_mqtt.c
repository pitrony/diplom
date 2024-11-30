#include "test_board.h"
#include <MQTTClientPersistence.h>
//#include <MQTTClient.h>
// #include "D:\alexey\iot_lerning\vc_projects\orang_test_elevator_board\paho.mqtt.c-master\src\MQTTClient.h"
#include <MQTTAsync.h>
#include "paho.mqtt.c-master/src/samples/pubsub_opts.h"



#if defined(_WIN32)
#define sleep Sleep
#else
#include <sys/time.h>
#endif


// #define ADDRESS     "tcp://localhost:1883"
#define ADDRESS     "mqtt.eclipseprojects.io:1883"
//#define ADDRESS     "192.168.1.85:1883"
#define CLIENTID    "Orangepi"
//#define TOPIC "/orangepi/data1"
//~ #define PAYLOAD     "Hello World!"
// #define PAYLOAD     "32"
#define QOS         1
#define TIMEOUT     10000L
int data=33;
char* TOPIC = "/orangepi/data1";
int send_mqtt(char* TOPIC, int data)
{
//int  PAYLOAD=_data;
MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.username = "orange";
    conn_opts.password = "orange";

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    //Encoding.UTF8.GetBytes(message)
    //pubmsg.payload = atoi((char *)_data);
    pubmsg.payload = &data;
    //pubmsg.payloadlen =64;
    pubmsg.payloadlen = sizeof(data);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %d\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), data, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;

}

int main()
{
	
	int ret=send_mqtt(TOPIC, data);
	
	return ret;
	
	}
