#include <MQTT.h>

int ownnr = 1;
int previous;
bool done = false;
bool idle = true;
int neighbours[3] = { 2, 3, 4}; 
unsigned long no_touch;
unsigned long touched;
MQTTClient client;

void setup() 
{
Serial.begin(9600);
  initPressureSensor();
  initMqtt(client);
  initColour();
  no_touch = millis();
  touched = millis();
}

void loop() 
{
  //mqtt
  client.loop();
  if (!client.connected()){ connect();}

  //pressuresensor just turning on when being stepped on.
 loopPressureSensor();
  float pressureValue = getRunningAvg();
  Serial.println(pressureValue);
  if(pressureValue > 3000){
    iterateOn();
    //instead of iterate on
    //if(!done){
        //String message = 
        //client.publish("/OfficePlayground", "1");
        //bool done = true
     //}
  }
  //if(done && pressureValue < 3000){
    //client.publish("/OfficePlayground", "0"
}
