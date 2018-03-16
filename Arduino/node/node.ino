#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "ESPap";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);
void handleminmax(){
Serial.println("@"+server.arg("min")+","+server.arg("max"));
server.send(200, "text/plain", "success");
  }
void handleRoot11() {
	Serial.println("(11");
  server.send(200, "text/plain", "success");
}
void handleRoot32() {
  Serial.println("(32");
  server.send(200, "text/plain", "success");
}
void handleRoot31() {
  Serial.println("(31");
  server.send(200, "text/plain", "success");
}
void handleRoot30() {
  Serial.println("(30");
  server.send(200, "text/plain", "success");
}
void handleRoot22() {
  Serial.println("(22");
  server.send(200, "text/plain", "success");
}
void handleRoot21() {
  Serial.println("(21");
  server.send(200, "text/plain", "success");
}
void handleRoot20() {
  Serial.println("(20");
  server.send(200, "text/plain", "success");
}
void handleRoot10() {
  Serial.println("(10");
  server.send(200, "text/plain", "success");
}
void handleRoot12() {
  Serial.println("(12");
  server.send(200, "text/plain", "success");
}
void handleRoot42() {
  Serial.println("(42");
  server.send(200, "text/plain", "success");
}
void handleRoot41() {
  Serial.println("(41");
  server.send(200, "text/plain", "success");
}
void handleRoot40() {
  Serial.println("(40");
  server.send(200, "text/plain", "success");
}
void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
 server.on("/10", handleRoot10);server.on("/11", handleRoot11);server.on("/12", handleRoot12);
 server.on("/20", handleRoot20);server.on("/21", handleRoot21);server.on("/22", handleRoot22);
 server.on("/30", handleRoot30);server.on("/31", handleRoot31);server.on("/32", handleRoot32);
 server.on("/40", handleRoot40);server.on("/41", handleRoot41);server.on("/42", handleRoot42);
 server.on("/mm", handleminmax);
 server.begin();
 Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
