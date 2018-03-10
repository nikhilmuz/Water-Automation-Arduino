#include<TimedAction.h>
#include <ESP8266WiFi.h>
bool runninga=true;
WiFiServer server(80);
void printaa(){
  if(runninga)
  Serial.println("printed");
  }
void handlereq(){
  WiFiClient client = server.available();
  if (client.available()){
  String req = client.readStringUntil('\r');
  client.flush();
  int val;
  if (req.indexOf("/req") != -1){
    runninga=true;
    }
    else if (req.indexOf("/unreq") != -1){
    runninga=false;
    }
    }}
TimedAction thread1=TimedAction(1000,printaa);
TimedAction thread2=TimedAction(100,handlereq);
void setup() {
Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("Nikhil", "password");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  thread1.check();
  thread2.check();
}
