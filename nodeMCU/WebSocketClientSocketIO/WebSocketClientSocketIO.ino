/*
 * WebSocketClientSocketIO.ino
 *
 *  Created on: 06.06.2016
 *
 */
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ArduinoJson.h>
//
//#include <WebSocketsClient.h>
//#include <SocketIOclient.h>
#include <WebSocketsClient.h>
#include <SocketIoClient.h>
#include <Hash.h>

ESP8266WiFiMulti WiFiMulti;
SocketIoClient socketIO;

#define USE_SERIAL Serial1

void messageEventHandler(const char * payload, size_t length) {
 Serial.printf("got message: %s\n", payload);
}
void setup() {
    // USE_SERIAL.begin(921600);
    USE_SERIAL.begin(115200);

    //Serial.setDebugOutput(true);
    USE_SERIAL.setDebugOutput(true);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

      for(uint8_t t = 4; t > 0; t--) {
          USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
          USE_SERIAL.flush();
          delay(1000);
      }

    // disable AP
    if(WiFi.getMode() & WIFI_AP) {
        WiFi.softAPdisconnect(true);
    }

    WiFiMulti.addAP("ahmed", "@AhmedAbbas99@");

    //WiFi.disconnect();
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    String ip = WiFi.localIP().toString();
    USE_SERIAL.printf("[SETUP] WiFi Connected %s\n", ip.c_str());

    // server address, port and URL
    socketIO.begin("192.168.1.6", 8000);
    // event handler for the event message
    socketIO.on("move_left",messageEventHandler);

    // event handler
//    socketIO.onEvent(socketIOEvent);
}

unsigned long messageTimestamp = 0;
void loop() {
    socketIO.loop();

    uint64_t now = millis();
  if(now - messageTimestamp > 6000) {
    messageTimestamp = now;
    // Send event     
  socketIO.emit("my_message", "\"this is a message from the client\"");   
  }    
//        // create JSON message for Socket.IO (event)
//        DynamicJsonDocument doc(1024);
//        JsonArray array = doc.to<JsonArray>();
//        
//        // add event name
//        // Hint: socket.on('event_name', ....
//        array.add("move_left");
//
//        // add payload (parameters) for the event
//        JsonObject param1 = array.createNestedObject();
//
//        // JSON to String (serializion)
//        String output;
//        serializeJson(doc, output);
//
//        // Send event        
//        socketIO.sendEVENT(output);
//
//        // Print JSON for debugging
//        USE_SERIAL.println(output);
    
}
