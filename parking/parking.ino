#include <SoftwareSerial.h>
#include<Servo.h>
SoftwareSerial nodemcu(2,3);
int entry = 9;
int out_ = 11;
int parking1_slot1_ir_s = 4; // parking slot1 infrared sensor connected with pin number 4 of arduino
int parking1_slot2_ir_s = 5;
int parking1_slot3_ir_s = 6;
int parking2_slot1_ir_s = 7;
int parking2_slot2_ir_s = 8;
int cars = 0;
Servo gate;
String sensor1;
String sensor2;
String sensor3;
String sensor4;
String sensor5;
String cdata =""; // complete data, consisting of sensors values
void setup()
{
gate.attach(10);
Serial.begin(9600);
nodemcu.begin(9600);
pinMode(entry, INPUT);
pinMode(out_, INPUT);
pinMode(parking1_slot1_ir_s, INPUT);
pinMode(parking1_slot2_ir_s, INPUT);
pinMode(parking1_slot3_ir_s, INPUT);
pinMode(parking2_slot1_ir_s, INPUT);
pinMode(parking2_slot2_ir_s, INPUT);
gate.write(0);
delay(1000);
}
void loop()
{
int in = digitalRead(entry);
int out = digitalRead(entry);
int s1 = digitalRead(parking1_slot1_ir_s);
int s2 = digitalRead(parking1_slot2_ir_s);
int s3 = digitalRead(parking1_slot3_ir_s);
int s4 = digitalRead(parking2_slot1_ir_s);
int s5 = digitalRead(parking2_slot1_ir_s);
if(cars == 5){
Serial.println(“ PARKING FULL! ”);
}
else{
Serial.print(“Cars in the parking : ”);
Serial.print(cars);
Serial.print(“ Empty slots := ”);
if(s1 == 1){
Serial.print(“Slot 1 ”);
}
if(s2 == 1){
Serial.print(“Slot 2 ”);
}
if(s3 == 1){
Serial.print(“Slot 3 ”);
}
if(s4 == 1){
Serial.print(“Slot 4 ”);
}
if(s5 == 1){
Serial.print(“Slot 5 ”);
}
if(s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0){
Serial.print(“ NOT AVAILABLE! “);
}
Serial.println();
if(in == 0 && cars < 5){
cars = cars + 1;
gate.write(90);
delay(3000);
gate.write(0);
}
if(out == 0 && cars > 0){
cars = cars – 1;
delay(1000);
}
p1slot1();
p1slot2();
p1slot3();
p2slot1();
p2slot2();
cdata = cdata + sensor1 +"," + sensor2 + ","+ sensor3 +","+ sensor4 + "," + sensor5 + ",";// + sensor6 +","; comma will be used as a delimiter.
Serial.println(cdata);
nodemcu.println(cdata);
delay(6000); // 6 seconds
cdata = "";
digitalWrite(parking1_slot1_ir_s, HIGH);
digitalWrite(parking1_slot2_ir_s, HIGH);
digitalWrite(parking1_slot3_ir_s, HIGH);
digitalWrite(parking2_slot1_ir_s, HIGH);
digitalWrite(parking2_slot2_ir_s, HIGH);
}
void p1slot1() // parking 1 slot1
{
if( digitalRead(parking1_slot1_ir_s) == LOW)
{
sensor1 = "255";
delay(200);
}
if( digitalRead(parking1_slot1_ir_s) == HIGH)
{
sensor1 = "0";
delay(200);
}
}
void p1slot2() // parking 1 slot2
{
if( digitalRead(parking1_slot2_ir_s) == LOW)
{
sensor2 = "255";
delay(200);
}
if( digitalRead(parking1_slot2_ir_s) == HIGH)
{
sensor2 = "0";
delay(200);
}
}
void p1slot3() // parking 1 slot3
{
if( digitalRead(parking1_slot3_ir_s) == LOW)
{
sensor3 = "255";
delay(200);
}
if( digitalRead(parking1_slot3_ir_s) == HIGH)
{
sensor3 = "0";
delay(200);
}
}
// now for parking 2
void p2slot1() // parking 2 slot1
{
if( digitalRead(parking2_slot1_ir_s) == LOW)
{
sensor4 = "255";
delay(200);
}
if( digitalRead(parking2_slot1_ir_s) == HIGH)
{
sensor4 = "0";
delay(200);
}
}
void p2slot2() // parking 2 slot2
{
if( digitalRead(parking2_slot2_ir_s) == LOW)
{
sensor5 = "255";
delay(200);
}
if( digitalRead(parking2_slot2_ir_s) == HIGH)
{
sensor5 = "0";
delay(200);
}
}
