int incoming = 0;
String moist = "";
String chrome = "";

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "Node";
const char *password = "password";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void moisture() {
	server.send(200, "text/html", chrome);
}

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
 server.on("/m", moisture);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
  
	server.handleClient();
   if (Serial.available() > 0){
    incoming = Serial.read();
    if (incoming>39 && incoming<58){
      moist += char(incoming);
      if (incoming==41){
        chrome = moist;
      Serial.println(chrome);
      moist = "";
        }
      }
  }
}
