import smbus
import time
import paho.mqtt.publish as publish

bus= smbus.SMBus(3)
#bWrite=0x00
#mask=0xFF
adr_2=0x24
adr_1=0x20
i=0

bus.write_byte(adr_2, 0xFF)
bus.write_byte(adr_1, 0xFF)
while (true):
	data1=bus.read_binary(adr_1))
	data1=bus.read_binary(adr_2))	
	msgs = [{'topic': "/orange/data1", 'payload': data1}, ("/orange/data2", data2, 0, False)]
	publish.multiple(msgs, hostname="mqtt.eclipseprojects.io")
	sleep(1)

