#include "test_board.h"
#include <string.h>
#include <MQTTClientPersistence.h>
#include <MQTTAsync.h>

//#define ADDRESS     "tcp://localhost:1883"
#define ADDRESS     "mqtt.eclipseprojects.io:1883"
#define CLIENTID    "Orangepi"

#define QOS         1
#define TIMEOUT     10000L

int send_mqtt(char* TOPIC, int _data){
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
    printf("connect, return code %d\n", rc);
    //Encoding.UTF8.GetBytes(message)
    //pubmsg.payload = atoi((char *)_data);
    pubmsg.payload = &_data;
    //pubmsg.payloadlen =64;
    pubmsg.payloadlen = sizeof(_data);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %d\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), _data, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;

}
