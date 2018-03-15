#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <TimedAction.h>

int a0 = A0,a1 = A1,a2 = A2,a3 = A3,a4 = A4,a5 = A5;
int va0,va1,va2,va3,va4,va5;
char ba1,ba2,ba3,ba4;
String actionsec,minmax;
int min,max;
char s1,s2,s3,s4;

//eeprom start
int writeaddr = 0;
int readaddr = 0;
void writeeeprom(String str){
  EEPROM.update(writeaddr,str.length());
  writeaddr++;
  for(int i=0;i<str.length();i++){
    EEPROM.update(writeaddr,str[i]);
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
//eeprom end

char preftooutput(char pref){
  if(pref=='1'){return HIGH;}
  else if(pref=='0'){return LOW;}
  return LOW;
}

int getresponse(){
  int incoming=1000;
  if(Serial.available()>0){
    incoming=Serial.read();
    }
    return incoming;
  }

void basics()
{
va0=analogRead(a0);
va1=(1024 - analogRead(a1))/10.24;
va2=(1024 - analogRead(a2))/10.24;
va3=(1024 - analogRead(a3))/10.24;
va4=(1024 - analogRead(a4))/10.24;
va5=analogRead(a5);
  
if(EEPROM.read(0)!=7){writeaddr = 0; actionsec="0,0,0,0"; minmax="000,100";  writeeeprom(actionsec); writeeeprom(minmax);}
readaddr = 0;
actionsec=readeeprom();
minmax=readeeprom();

s1=actionsec[0];
s2=actionsec[2];
s3=actionsec[4];
s4=actionsec[6];

min=(minmax.substring(0,3)).toInt();
max=(minmax.substring(4,7)).toInt();

if(s1!='2'){digitalWrite(9,preftooutput(s1));}
if(s2!='2'){digitalWrite(10,preftooutput(s2));}
if(s3!='2'){digitalWrite(12,preftooutput(s3));}
if(s4!='2'){digitalWrite(13,preftooutput(s4));}

//automation
if(s1=='2'){if(va1<min){digitalWrite(9,preftooutput('1'));}
else if(va1>max){digitalWrite(9,preftooutput('0'));}
}
if(s2=='2'){if(va2<min){digitalWrite(10,preftooutput('1'));}
else if(va2>max){digitalWrite(10,preftooutput('0'));}
}
if(s3=='2'){if(va3<min){digitalWrite(12,preftooutput('1'));}
else if(va3>max){digitalWrite(12,preftooutput('0'));}
}
if(s4=='2'){if(va4<min){digitalWrite(13,preftooutput('1'));}
else if(va4>max){digitalWrite(13,preftooutput('0'));}
}
//automation end

}

void handlecomm(){
  int updateaddr;
  int resp=getresponse();
 // Serial.println(char(resp));
  if (char(resp)=='('){
    while((resp <47) || (resp>58) ){
    resp=getresponse();}
    Serial.println("2nd");
    //Serial.println(char(resp));
    if(char(resp)=='1'){updateaddr=1;
    Serial.println("1");
    }
    else if(char(resp)=='2'){updateaddr=3;
    Serial.println("2");}
    else if(char(resp)=='3'){updateaddr=5;
    Serial.println("3");}
    else if(char(resp)=='4'){updateaddr=7;
    Serial.println("4");}
    for(int i=0;i<10;i++){
    resp=getresponse();
    if(char(resp)=='0'||char(resp)=='1'||char(resp)=='2')
    EEPROM.update(updateaddr,char(resp));
    Serial.println(char(resp));
    }
  }
  }

TimedAction ta1 = TimedAction(1000,basics);

void setup() {
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
Serial.begin(115200);
writeaddr = 0; actionsec="2,2,2,2"; minmax="050,055";  writeeeprom(actionsec); writeeeprom(minmax);
}

void loop(){
  ta1.check();
  handlecomm();
  }
