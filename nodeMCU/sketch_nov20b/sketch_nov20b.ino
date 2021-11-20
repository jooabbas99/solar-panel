

#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>
#include <SocketIoClient.h>

SocketIoClient socketIO;
void messageEventHandler(const char * payload, size_t length) {
 Serial.printf("got message: %s\n", payload);
}
void setup() {
 WiFi.begin("ahmed", "@AhmedAbbas99@");
 Serial.print("Connecting");
 while (WiFi.status() != WL_CONNECTED)
 {
  delay(500);
  Serial.print(".");
 }
 Serial.println();

 Serial.print("Connected, IP address: ");
 Serial.println(WiFi.localIP());

  // server address, port and URL
  socketIO.begin("192.168.1.6", 8000);
  // event handler for the event message
  socketIO.on("move_left",messageEventHandler);
}
uint64_t messageTimestamp;

void loop() {
  // put your main code here, to run repeatedly:
   socketIO.loop();
uint64_t now = millis();
  if(now - messageTimestamp > 6000) {
    messageTimestamp = now;
    // Send event     
  socketIO.emit("my_message", "\"this is a message from the client\"");   
  }    
}
