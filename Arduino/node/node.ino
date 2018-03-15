#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot11() {
	Serial.print("(11");
}
void handleRoot32() {
  Serial.print("(32");
}
void handleRoot31() {
  Serial.print("(31");
}
void handleRoot30() {
  Serial.print("(30");
}

void handleRoot22() {
  Serial.print("(22");
}
void handleRoot21() {
  Serial.print("(21");
}
void handleRoot20() {
  Serial.print("(20");
}
void handleRoot10() {
  Serial.print("(10");
}
void handleRoot12() {
  Serial.print("(12");
}
void handleRoot42() {
  Serial.print("(42");
}
void handleRoot41() {
  Serial.print("(41");
}
void handleRoot40() {
  Serial.print("(40");
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
 server.on("/setting", []() {
        String qsid = server.arg("ssid");
          Serial.println(qsid);
    });
 server.begin();
 Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
