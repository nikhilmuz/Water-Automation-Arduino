#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>

ESP8266WebServer server(80);

int writeaddr = 0;
int readaddr = 0;

void s1on() {
	server.send(200, "text/html", "<h1>Welcome</h1>");
  digitalWrite(12, 1);
}

void s1off() {
	server.send(200, "text/html", "<h1>Welcome1</h1>");
 digitalWrite(12, 0);
}
void s2on() {
	server.send(200, "text/html", "<h1>Welcome</h1>");
  digitalWrite(13, 1);
}

void s2off() {
	server.send(200, "text/html", "<h1>Welcome1</h1>");
 digitalWrite(13, 0);
}
void s3on() {
	server.send(200, "text/html", "<h1>Welcome</h1>");
  digitalWrite(14, 1);
}

void s3off() {
	server.send(200, "text/html", "<h1>Welcome1</h1>");
 digitalWrite(14, 0);
}
void s4on() {
	server.send(200, "text/html", "<h1>Welcome</h1>");
  digitalWrite(15, 1);
}

void s4off() {
  server.send(200, "text/html", "<h1>Welcome1</h1>");
 digitalWrite(15, 0);
}

void refill() {
  server.send(200, "text/html", "<h1>Welcome</h1>");
 digitalWrite(1, 0);
}

void writeeeprom(String str){
  EEPROM.write(writeaddr,str.length());
  writeaddr++;
  for(int i=0;i<str.length();i++){
    EEPROM.write(writeaddr,str[i]);
    writeaddr++;
  }
}

String readeeprom(){
  String output="";
  readaddr++;
  for(int i=0;i<EEPROM.read(readaddr-1);i++){
    output+=(char)EEPROM.read(readaddr);
    readaddr++;
    }
  return output;
}

void cleareeprom(){
	for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);
}

//void credential() {
//	WiFiClient client = server.available();
//	String req = client.readStringUntil('\r');
//	client.flush();
//	if (req.indexOf("/GET") == 0){
//		String temp = explode(req, ' ');
//		auto cred = explode(temp[1], '/');
//		 String id = temp[0];
//		 String pwd = temp[1];
//		 writeeeprom(id);
//		 writeeeprom(pwd);
//		 
//	}
//}


void setup() {
  Serial.begin(115200);
  
  WiFi.softAP("Water", "password");
  
  server.on("/s1on", s1on);
  server.on("/s1off", s1off);
  server.on("/s2on", s2on);
  server.on("/s2off", s2off);
  server.on("/s3on", s3on);
  server.on("/s3off", s3off);
  server.on("/s4on", s4on);
  server.on("/s4off", s4off);
  server.on("/refill", refill);
  
  server.begin();

  
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(1, OUTPUT);
  
//  EEPROM.begin(512);
//  String id="Nikhil";
//  String pwd="password";
//  cleareeprom();
//  writeeeprom(id);
//  writeeeprom(pwd);
//  EEPROM.commit();
  
//Serial.print(readeeprom());
//Serial.print(readeeprom());
}

void loop() {
	server.handleClient();
}
