#include <EEPROM.h>

int writeaddr = 0;
int readaddr = 0;


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
  int len = EEPROM.read(readaddr-1);
  for(int i=0;i<len;i++){
    output+=(char)EEPROM.read(readaddr);
    readaddr++;
    }
  return output;
}

void cleareeprom(){
  for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);

}
void setup() {
Serial.begin(115200);
  
 EEPROM.begin(512);
 String id="Nikhil";
 String pwd="password";
  cleareeprom();
  writeeeprom(id);
  writeeeprom(pwd);
  EEPROM.commit();
  
Serial.print(readeeprom());
Serial.print(readeeprom());
}

void loop(){
  // put your main code here, to run repeatedly:

}
