#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
RF24 radio(7,8); // CE, CSN

const byte address[6] = "00001";
int arr[5];
bool state=0;
void setup() {
  servo0.attach(2);
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);

  Wire.begin(8);
  Wire.onReceive(receiveEvent); /* register receive event */
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

}

void loop() {
  if (radio.available()&&state==0) {
    radio.read(&arr, sizeof(arr));
  }
    servo0.write(arr[0]);
    servo1.write(arr[1]);
    servo2.write(arr[2]);
    servo3.write(arr[3]);
    servo4.write(arr[4]);

}


// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
  for(int i=0;i<5;i++){
    arr[i] = Wire.read();           /* print the character */
  }
 }
}
