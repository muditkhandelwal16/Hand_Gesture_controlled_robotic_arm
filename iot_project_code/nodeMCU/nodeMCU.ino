#define BLYNK_TEMPLATE_ID "TMPLhnIos-8N"
#define BLYNK_DEVICE_NAME "IOT Project"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include <Wire.h>
int arr[5];
BLYNK_WRITE(V0)
{
  arr[0]=param.asInt();
  Serial.print(arr[0]);
  Serial.print(" "); 
}
BLYNK_WRITE(V1)
{
  arr[1]=param.asInt();
  Serial.print(arr[1]);
  Serial.print(" ");
}
BLYNK_WRITE(V2)
{
  arr[2]=param.asInt();
  Serial.print(arr[2]);
  Serial.print(" ");
}
BLYNK_WRITE(V3)
{
  arr[3]=param.asInt();
  Serial.print(arr[3]);
  Serial.print(" ");
}
BLYNK_WRITE(V4)
{
  arr[4]=param.asInt();
  Serial.println(arr[4]);
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);  
}

void setup()
{
  pinMode(2, OUTPUT); // Initialise digital pin 2 as an output pin
  Serial.begin(115200);
  
  Wire.begin(5, 4);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  Wire.beginTransmission(8); /* begin with device address 8 */
  Wire.write(arr[0]);
  Wire.write(arr[1]);
  Wire.write(arr[2]);
  Wire.write(arr[3]);
  Wire.write(arr[4]);
  Wire.endTransmission();
}
