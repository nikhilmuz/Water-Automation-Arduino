int analog_input = A5;
int analog_temp = A0;
int val = 0;
int temp = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(analog_input);
temp = analogRead(analog_temp);
Serial.println("(" + String(val) + "," + String(temp) + ")");
delay(2000);
}
